//
// Created by chauvin on 08/06/17.
//

#ifndef CPP_INDIE_STUDIO_SPAWNMANAGER_HPP
#define CPP_INDIE_STUDIO_SPAWNMANAGER_HPP


#include <vector>
#include <memory>
#include "../Entity/EnnemyEntity.hpp"
#include "../Entity/PlayableEntity.hpp"
#include "../GameObject/GameObject.hpp"

class 					Room
{
 private:
  NsGameObject::Door 			*door_;
  irr::core::vector3df			doorPos;

  //!Spawn of Monsters
  std::vector<irr::core::vector3df>	polygonM_;
  irr::f32 				maxXM_;
  irr::f32 				minXM_;
  irr::f32 				maxZM_;
  irr::f32 				minZM_;
  irr::f32 				YM_;

  //!Spawn of Gold and Key
  std::vector<irr::core::vector3df>	polygonG_;
  irr::f32 				maxXG_;
  irr::f32 				minXG_;
  irr::f32 				maxZG_;
  irr::f32 				minZG_;
  irr::f32 				YG_;

  int 					level_;
  int					nbmaxMonster_;
  int 					nbMonster_;
  int 					nbGold_;
  int 					nbMaxGold_;
  int 					type_;
  irr::core::vector3df 			rotation_;
  bool 					active;

  int 					roomId_;
 private:
  float 				randomGenerator(float min, float max);

 public:
  Room(int level, irr::f32 maxXG, irr::f32 minXG, irr::f32 maxZG, irr::f32 minZG, irr::f32 YG, irr::f32 maxXM, irr::f32 minXM, irr::f32 maxZM, irr::f32 minZM, irr::f32 YM, int i, int roomId);
  ~Room(){};
  void 					printpoly();
  irr::core::vector3df			GenerateMonster();
  irr::core::vector3df			GenerateGold();
  std::vector<core::vector3df> &	getPolygonM_();
  void					setPolygonM_(const std::vector<core::vector3df> &polygonM_);
  std::vector<core::vector3df> & 	getPolygonG_();
  void 					setPolygonG_(const std::vector<core::vector3df> &polygonG_);
  int 					getRoomId_() const;
  void 					setRoomId_(int roomId_);
  int 					getNbmaxMonster_() const;
  int 					getNbMonster_() const;
  bool					isActive() const;
  void					setActive(bool active);
  int					getNbGold_() const;
  void					setNbGold_(int nbGold_);
  int					getNbMaxGold_() const;
  void					setNbMaxGold_(int nbMaxGold_);
  void 					setNbMonster_(int nbMonster_);
  NsGameObject::Door * 			getDoor_() const;
  void 					setDoor_(NsGameObject::Door *door_);
  void 					setposDoor_(std::string basic_string, std::ifstream &ifstream);
  const irr::core::vector3df 		&getDoorPos() const;
  irr::core::vector3df 			GenerateKey();
  bool 					PointIsInGeometry(core::vector3df vec, std::vector<core::vector3df> polygon);
  int					getLevel_() const;
  void					setLevel_(int level_);
  int					getType_() const;
  void					setType_(int type_);
  const core::vector3df 		&getRotation_() const;
  void 					setRotation_(const core::vector3df &rotation_);
};

class			SpawnManager
{
  int			difficulty_;
  int 			nbPlayers_;
  std::vector<Room>	rooms_;

  void 			fillRoom(std::ifstream &s);
  void 			GetNextLine(std::string &line, std::ifstream &s);
  void 			addVectorPoly(std::vector<irr::core::vector3df> &vector, std::string basic_string);
 public:
  SpawnManager();
  ~SpawnManager(){};
  void			Initialization(int difficulty, unsigned long nbPlayers, const std::string &map);
  std::vector<Room> 	&getRooms_();
  void			getMaxMinPos(f32 *pDouble, f32 *pDouble1, f32 *pDouble2, f32 *pDouble3, f32 *pDouble4, const std::string &line);
};

#endif //CPP_INDIE_STUDIO_SPAWNMANAGER_HPP
