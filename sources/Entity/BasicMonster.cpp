/*
** BasicMonster.cpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/newEntity
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Fri Jun 02 23:36:41 2017 sshSupreme
** Last update Sun Jun 18 21:52:48 2017 Florent Sebag
*/

#include "EnnemyEntity.hpp"

void                          NsEntity::BasicMonster::Death()
{
}

void                          NsEntity::BasicMonster::Static()
{
}

void                          NsEntity::BasicMonster::AutoShot()
{
  
}

NsEntity::BasicMonster::BasicMonster(Model3D& model) : EnnemyEntity(model)
{
  this->isMoving = true;
  this->isShooting = false;
  this->Health_ = 200;
  this->MaxHealth_ = this->Health_;
  this->Damages_ = 10;
  this->Speed_ = irr::core::vector3df(0,0,1.5f);
  this->speedAttack_ = 100;
}

NsEntity::BasicMonster::~BasicMonster()
{

}
