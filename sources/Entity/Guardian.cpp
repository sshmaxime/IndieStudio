/*
** Guardian.cpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/Entity
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Mon Jun 05 16:42:56 2017 sshSupreme
** Last update Tue Jun 06 19:43:48 2017 sshSupreme
*/


#include "PlayableEntity.hpp"

void                    NsEntity::Guardian::Move()
{
  if (this->isMoving == false) this->MoveAnim();
  if (this->isMoving == false && this->isShooting == true) this->MoveShotAnim();
  this->isMoving = true;
}

void                    NsEntity::Guardian::Static()
{

  if (this->isShooting == false) this->StaticAnim();
  this->isMoving = false;
}

void                    NsEntity::Guardian::Spell_1()
{

}

void                    NsEntity::Guardian::Spell_2()
{

}

void                    NsEntity::Guardian::Spell_3()
{

}

void                    NsEntity::Guardian::AutoShot()
{

  if (this->isShooting == false) this->ShotAnim();
  if (this->isShooting == false && this->isMoving == true) this->MoveShotAnim();
  this->isShooting = true;
}

void                    NsEntity::Guardian::StopShot()
{

  if (this->isShooting == true && this->isMoving == true) this->MoveAnim();
  if (this->isShooting == true && this->isMoving == false) this->StaticAnim();
  this->isShooting = false;
}

void                    NsEntity::Guardian::Death()
{
  this->DeathAnim();
}

void                    NsEntity::Guardian::MoveAnim() {this->getNode()->setFrameLoop(0, 24);}
void                    NsEntity::Guardian::ShotAnim()
{
  this->getNode()->setFrameLoop(26, 46);
  this->getNode()->setLoopMode(false);
}
void                    NsEntity::Guardian::StaticAnim() {this->getNode()->setFrameLoop(26, 26);}
void                    NsEntity::Guardian::MoveShotAnim() {this->getNode()->setFrameLoop(26, 46);}
void                    NsEntity::Guardian::DeathAnim() {this->getNode()->setFrameLoop(48, 60);}
void                    NsEntity::Guardian::HappyAnim() {this->getNode()->setFrameLoop(62, 74);}
void                    NsEntity::Guardian::AngryAnim() {this->getNode()->setFrameLoop(76, 88);}

NsEntity::Guardian::Guardian(Model3D& model) : PlayableEntity(model)
{
  this->isMoving = false;
  this->isShooting = false;
  this->Health_ = 200;
  this->MaxHealth_ = this->Health_;
  this->Damages_ = 60;
  this->Ranger_ = false;
  this->speedAttack_ = 50;
}

NsEntity::Guardian::~Guardian()
{

}
