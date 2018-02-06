/*
** EnnemyEntity.cpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/newEntity
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Fri Jun 02 23:18:09 2017 sshSupreme
** Last update Sun Jun 18 22:07:24 2017 Florent Sebag
*/

#include <iostream>
#include "../SpawnManager/SpawnManager.hpp"

irr::scene::HealthSceneNode*          NsEntity::EnnemyEntity::getHealthbar() const {return (this->Healthbar_);}
void                                  NsEntity::EnnemyEntity::setHealthbar(irr::scene::HealthSceneNode *Healthbar) {this->Healthbar_ = Healthbar;}

void                                  NsEntity::EnnemyEntity::takeDamage(size_t value)
{
  if (value > this->Health_)
    this->Health_ = 0;
  else
    this->Health_ = this->Health_ - value;
  std::cout << "Health : " << this->Health_ << std::endl;
  this->getHealthbar()->setProgress((irr::s32) (100 * this->Health_ / this->MaxHealth_));
}

void                                  NsEntity::EnnemyEntity::CheckWall(irr::core::vector3df PrevPos, irr::core::vector3df focus, int indic, std::vector<std::shared_ptr<NsEntity::EnnemyEntity>> &vEnnemy_)
{
  irr::core::vector3df tmp_pos;

  if (indic == 1)
    return ;
  if (this->getNode()->getPosition() != PrevPos)
    return ;
  tmp_pos.X = this->getNode()->getPosition().X;
  if (focus.Z - this->getNode()->getPosition().Z < 0)
    tmp_pos.Z = this->getNode()->getPosition().Z - 100;
  else
    tmp_pos.Z = this->getNode()->getPosition().Z + 100;
  tmp_pos.Y = focus.Y;
  Move(tmp_pos, 1, vEnnemy_);
  if (this->getNode()->getPosition() != PrevPos)
    return ;
  tmp_pos.Z = this->getNode()->getPosition().Z;
  if (focus.X - this->getNode()->getPosition().X < 0)
    tmp_pos.X = this->getNode()->getPosition().X - 100;
  else
    tmp_pos.X = this->getNode()->getPosition().X + 100;
  tmp_pos.Y = focus.Y;
  Move(tmp_pos, 1, vEnnemy_);
}

int                                  NsEntity::EnnemyEntity::Move(irr::core::vector3df focus, int indic, std::vector<std::shared_ptr<NsEntity::EnnemyEntity>> &vEnnemy_)
{
  irr::core::matrix4 m;
  irr::core::vector3df vel = this->Speed_;
  irr::core::vector3df new_pos;
  irr::core::vector3df tmp;

  // if (this->isMoving == false)
  //   this->getNode()->setFrameLoop(0, 24);
  // this->isShooting = false;
  // this->isMoving = true;
  tmp = this->getNode()->getPosition();
  this->getNode()->setRotation(faceTarget(focus, this->getNode()->getPosition()));
  m.setRotationDegrees(this->getNode()->getRotation());
  m.transformVect(vel);
  new_pos = this->getNode()->getPosition() - vel;
  this->getNode()->setPosition(new_pos);
  this->CheckWall(tmp, focus, indic, vEnnemy_);
  return (0);
}

void                                 NsEntity::EnnemyEntity::AutoShot(std::shared_ptr<NsEntity::PlayableEntity> &focus)
{
  // if (this->isShooting == false)
  //   this->getNode()->setFrameLoop(26, 38);
  // this->isShooting = true;
  // this->isMoving = false;
  focus->takeDamage(this->Damages_);
  this->ableAttack_ = false;
}

NsEntity::EnnemyEntity::EnnemyEntity(Model3D& model) : Entity(model)
{
  nb_loop = 0;
}

NsEntity::EnnemyEntity::~EnnemyEntity()
{

}

int NsEntity::EnnemyEntity::getRoom_id_() const
{
  return Room_id_;
}

void NsEntity::EnnemyEntity::setRoom_id_(int Room_id_)
{
  EnnemyEntity::Room_id_ = Room_id_;
}
