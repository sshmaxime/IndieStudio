//
// Created by chauvin on 08/06/17.
//

#include "SpawnManager.hpp"
#include "../Core/Core.hpp"

void SpawnManager::GetNextLine(std::string& line, std::ifstream &s)
{
  for (;;) // until break
    {
      getline(s, line);
      if(s.good()) //If read sucess
	{
	  // If valid line
	  if(line.length() > 0 && line[0] != '#')
	    break; // Done
	}
      else // Wrong line
	{
	  line.clear(); // empty the buffer
	  break; // Abort
	}
    }
}

//! Constructor
SpawnManager::SpawnManager() {}


//! read .map file and create rooms
void SpawnManager::Initialization(int difficulty, unsigned long nbPlayers, const std::string &map)
{
  int 		nbRooms;
  std::ifstream s; // Open file stream
  std::string	line; // buff

  this->difficulty_ = difficulty;
  this->nbPlayers_ = nbPlayers;
  s.open(map);
  if (!s.is_open()) // If open failed
    return;
  else
    {
      // Read nbRooms
      GetNextLine(line, s);
      if (line.empty())
	return;
      nbRooms = atoi(line.c_str());
      for (int i = 0; i < nbRooms; i++)
	this->fillRoom(s);
    }
  s.close();
}

void Room::setposDoor_(std::string line, std::ifstream &s)
{
  irr::core::vector3df	vec;
  irr::f32		nb;
  int 			i = 0;
  int 			j = 0;
  int 			type = 0;
  std::string		buf;
  irr::core::vector3df  rot(0,0,0);

  while (line[i] != ',' && line[i])
    {
      buf[j] = line[i];
      i++;
      j++;
    }
  buf[j] = 0;
  nb = std::stof(buf);
  vec.X = nb;
  i++;
  j = 0;
  buf.clear();
  while (line[i] != ',' && line[i])
    {
      buf[j] = line[i];
      i++;
      j++;
    }
  buf[j] = 0;
  nb = std::stof(buf);
  vec.Y = nb;
  i++;
  j = 0;
  buf.clear();
  while (line[i] != ',' && line[i])
    {
      buf[j] = line[i];
      i++;
      j++;
    }
  buf[j] = 0;
  nb = std::stof(buf);
  vec.Z = nb;
  i++;
  j = 0;
  buf.clear();
  while (line[i] != ',' && line[i])
    {
      buf[j] = line[i];
      i++;
      j++;
    }
  buf[j] = 0;
  type_ = std::stoi(buf);
  i++;
  j = 0;
  buf.clear();
  while (line[i])
    {
      buf[j] = line[i];
      i++;
      j++;
    }
  buf[j] = 0;
  rot.Y = std::stof(buf);
  rotation_ = rot;
  this->doorPos = vec;
}

void		SpawnManager::fillRoom(std::ifstream &s)
{
  std::string	line;
  int 		level;
  irr::f32 	maxXG;
  irr::f32 	minXG;
  irr::f32 	maxZG;
  irr::f32 	minZG;
  irr::f32 	YG;
  irr::f32 	maxXM;
  irr::f32 	minXM;
  irr::f32 	maxZM;
  irr::f32 	minZM;
  irr::f32 	YM;
  int 		type;
  float 	rotation;

  //While we can't find a map's declaration
  while (line[0] != '{')
    this->GetNextLine(line, s);
  line.clear();
  //While we can't find the level of the room
  while (line.empty())
    this->GetNextLine(line, s);
  level = std::stoi(line);
  line.clear();
  while(line.empty())
    this->GetNextLine(line, s);
  this->getMaxMinPos(&maxXG, &minXG, &maxZG, &minZG, &YG, line);
  line.clear();
  while(line.empty())
    this->GetNextLine(line, s);
  this->getMaxMinPos(&maxXM, &minXM, &maxZM, &minZM, &YM, line);
  line.clear();
  Room r(level, maxXG, minXG, maxZG, minZG, YG, maxXM, minXM, maxZM, minZM, YM,this->nbPlayers_, this->rooms_.size());
  while (line.empty())
    this->GetNextLine(line, s);
  r.setposDoor_(line, s);
  //While end of declaration
  while (line[0] != '[')
    this->GetNextLine(line, s);
  line.clear();
  while (line[0] != ']')
    {
      this->GetNextLine(line, s);
      if (line[0] != ']')
	this->addVectorPoly(r.getPolygonG_(), line);
    }
  while (line[0] != '[')
    this->GetNextLine(line, s);
  line.clear();
  while (line[0] != ']')
    {
      this->GetNextLine(line, s);
      if (line[0] != ']')
	this->addVectorPoly(r.getPolygonM_(), line);
    }
  while (line[0] != '}')
    this->GetNextLine(line, s);
  this->rooms_.push_back(r);
}

void 			SpawnManager::addVectorPoly(std::vector<irr::core::vector3df> &poly, std::string line)
{
  irr::core::vector3df	vec;
  irr::f32		nb;
  int 			i = 0;
  int 			j = 0;
  std::string		buf;

  while (line[i] != ',' && line[i])
    {
      buf[j] = line[i];
      i++;
      j++;
    }
  buf[j] = 0;
  nb = std::stof(buf);
  vec.X = nb;
  i++;
  j = 0;
  buf.clear();
  while (line[i] != ',' && line[i])
    {
      buf[j] = line[i];
      i++;
      j++;
    }
  buf[j] = 0;
  nb = std::stof(buf);
  vec.Y = nb;
  i++;
  j = 0;
  buf.clear();
  while (line[i])
    {
      buf[j] = line[i];
      i++;
      j++;
    }
  buf[j] = 0;
  nb = std::stof(buf);
  vec.Z = nb;
  poly.push_back(vec);
}

std::vector<Room> &SpawnManager::getRooms_()
{
  return rooms_;
}

void SpawnManager::getMaxMinPos(f32 *maxX, f32 *minX, f32 *maxZ, f32 *minZ, f32 *Y,
				const std::string &line)
{
  irr::f32		nb;
  int 			i = 0;
  int 			j = 0;
  std::string		buf;

  while (line[i] != ',' && line[i])
    {
      buf[j] = line[i];
      i++;
      j++;
    }
  buf[j] = 0;
  (*maxX) = std::stof(buf);
  i++;
  j = 0;
  buf.clear();
  while (line[i] != ',' && line[i])
    {
      buf[j] = line[i];
      i++;
      j++;
    }
  buf[j] = 0;
  (*minX) = std::stof(buf);
  i++;
  j = 0;
  buf.clear();
  while (line[i] != ',' && line[i])
    {
      buf[j] = line[i];
      i++;
      j++;
    }
  buf[j] = 0;
  (*maxZ) = std::stof(buf);
  i++;
  j = 0;
  buf.clear();
  while (line[i] != ',' && line[i])
    {
      buf[j] = line[i];
      i++;
      j++;
    }
  buf[j] = 0;
  (*minZ) = std::stof(buf);
  i++;
  j = 0;
  buf.clear();
  while (line[i] != ',' && line[i])
    {
      buf[j] = line[i];
      i++;
      j++;
    }
  buf[j] = 0;
  (*Y) = std::stof(buf);
}

Room::Room(int level, irr::f32 maxX, irr::f32 minX, irr::f32 maxZ, irr::f32 minZ, irr::f32 Y,irr::f32 maxXM, irr::f32 minXM, irr::f32 maxZM, irr::f32 minZM, irr::f32 YM, int diff, int roomId)
{
  this->level_ = level;
  this->nbMaxGold_ = diff * level;
  this->nbGold_ = 0;
  this->nbmaxMonster_ = diff * level + 2;
  this->nbMonster_ = 0;
  this->maxXG_ = maxX;
  this->minXG_ = minX;
  this->maxZG_ = maxZ;
  this->minZG_ = minZ;
  this->YG_ = Y;
  this->maxXM_ = maxXM;
  this->minXM_ = minXM;
  this->maxZM_ = maxZM;
  this->minZM_ = minZM;
  this->YM_ = YM;
  this->roomId_ = roomId;
  this->active = false;
  this->door_ = NULL;
}

float Room::randomGenerator(float min, float max)
{
  return ((max - min) * ((float)rand() / RAND_MAX)) + min;
}

bool Room::PointIsInGeometry(irr::core::vector3df vec, std::vector<irr::core::vector3df> polygon){
  std::vector<irr::core::vector3d<float>>::iterator j = std::prev(polygon.end());
  bool output = false;

  for (auto i = polygon.begin(); i < polygon.end(); i++)
    {
      if ((*i).X < vec.X && (*j).X >= vec.X || (*j).X < vec.X && (*i).X >= vec.X)
	{
	  if ((*i).Z + (vec.X - (*i).X) / ((*j).X - (*i).X) * ((*j).Z - (*i).Z) < vec.Z)
	    {
	      output = !output;
	    }
	}
      j = i;
    }
  return output;
}

core::vector3df Room::GenerateMonster()
{
  irr::core::vector3df v = irr::core::vector3df(0, 0, 0);
  while (!this->PointIsInGeometry(v, this->polygonM_))
    {
      v.X = this->randomGenerator(this->minXM_, this->maxXM_);
      v.Z = this->randomGenerator(this->minZM_, this->maxZM_);
      v.Y = this->YM_;
    }
  this->nbMonster_++;
  return (v);
}

core::vector3df Room::GenerateGold()
{
  irr::core::vector3df v = irr::core::vector3df(0, 0, 0);
  while (!this->PointIsInGeometry(v, this->polygonG_))
    {
      v.X = this->randomGenerator(this->minXG_, this->maxXG_);
      v.Z = this->randomGenerator(this->minZG_, this->maxZG_);
      v.Y = this->YG_;
    }
  this->nbGold_++;
  return (v);
}

core::vector3df Room::GenerateKey()
{
  irr::core::vector3df v = irr::core::vector3df(0, 0, 0);
  while (!this->PointIsInGeometry(v, this->polygonG_))
    {
      v.X = this->randomGenerator(this->minXG_, this->maxXG_);
      v.Z = this->randomGenerator(this->minZG_, this->maxZG_);
      v.Y = this->YG_;
    }
  return (v);
}

int Room::getNbmaxMonster_() const
{
  return nbmaxMonster_;
}

int Room::getNbMonster_() const
{
  return nbMonster_;
}

int Room::getRoomId_() const
{
  return roomId_;
}

void Room::setRoomId_(int roomId_)
{
  Room::roomId_ = roomId_;
}

bool Room::isActive() const
{
  return active;
}

void Room::setActive(bool active)
{
  Room::active = active;
}

int Room::getNbGold_() const
{
  return nbGold_;
}

void Room::setNbGold_(int nbGold_)
{
  Room::nbGold_ = nbGold_;
}

int Room::getNbMaxGold_() const
{
  return nbMaxGold_;
}

void Room::setNbMaxGold_(int nbMaxGold_)
{
  Room::nbMaxGold_ = nbMaxGold_;
}

void Room::setNbMonster_(int nbMonster_)
{
  Room::nbMonster_ = nbMonster_;
}

NsGameObject::Door * Room::getDoor_() const
{
  return door_;
}

void Room::setDoor_(NsGameObject::Door *door_)
{
  Room::door_ = door_;
}

const core::vector3df &Room::getDoorPos() const
{
  return doorPos;
}

std::vector<core::vector3df> & Room::getPolygonM_()
{
  return polygonM_;
}

void Room::setPolygonM_(const std::vector<core::vector3df> &polygonM_)
{
  Room::polygonM_ = polygonM_;
}

std::vector<core::vector3df> & Room::getPolygonG_()
{
  return polygonG_;
}

void Room::setPolygonG_(const std::vector<core::vector3df> &polygonG_)
{
  Room::polygonG_ = polygonG_;
}

int Room::getLevel_() const
{
  return level_;
}

void Room::setLevel_(int level_)
{
  Room::level_ = level_;
}

int Room::getType_() const
{
  return type_;
}

void Room::setType_(int type_)
{
  Room::type_ = type_;
}

const core::vector3df &Room::getRotation_() const
{
  return rotation_;
}

void Room::setRotation_(const core::vector3df &rotation_)
{
  Room::rotation_ = rotation_;
}
