/*
** Warrior.cpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/Entity
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Mon Jun 05 16:47:53 2017 sshSupreme
** Last update Tue Jun 06 19:43:48 2017 sshSupreme
*/


#include "PlayableEntity.hpp"

void                    NsEntity::Warrior::Move()
{
  if (this->isMoving == false) this->MoveAnim();
  if (this->isMoving == false && this->isShooting == true) this->MoveShotAnim();
  this->isMoving = true;
}

void                    NsEntity::Warrior::Static()
{

  if (this->isShooting == false) this->StaticAnim();
  this->isMoving = false;
}

void                    NsEntity::Warrior::Spell_1()
{

}

void                    NsEntity::Warrior::Spell_2()
{

}

void                    NsEntity::Warrior::Spell_3()
{

}

void                    NsEntity::Warrior::AutoShot()
{

  if (this->isShooting == false) this->ShotAnim();
  if (this->isShooting == false && this->isMoving == true) this->MoveShotAnim();
  this->isShooting = true;
}

void                    NsEntity::Warrior::StopShot()
{

  if (this->isShooting == true && this->isMoving == true) this->MoveAnim();
  if (this->isShooting == true && this->isMoving == false) this->StaticAnim();
  this->isShooting = false;
}

void                    NsEntity::Warrior::Death()
{
  this->DeathAnim();
}

void                    NsEntity::Warrior::MoveAnim() {this->getNode()->setFrameLoop(0, 24);}
void                    NsEntity::Warrior::ShotAnim() {this->getNode()->setFrameLoop(26, 38);}
void                    NsEntity::Warrior::StaticAnim() {this->getNode()->setFrameLoop(26, 26);}
void                    NsEntity::Warrior::MoveShotAnim() {this->getNode()->setFrameLoop(26, 38);}
void                    NsEntity::Warrior::DeathAnim() {this->getNode()->setFrameLoop(38, 50);}
void                    NsEntity::Warrior::HappyAnim() {this->getNode()->setFrameLoop(52, 76);}
void                    NsEntity::Warrior::AngryAnim() {this->getNode()->setFrameLoop(78, 102);}

NsEntity::Warrior::Warrior(Model3D& model) : PlayableEntity(model)
{
  this->isMoving = false;
  this->isShooting = false;
  this->Health_ = 150;
  this->MaxHealth_ = this->Health_;
  this->Damages_ = 40;
  this->Ranger_ = false;
  this->speedAttack_ = 20;
}

NsEntity::Warrior::~Warrior()
{

}
