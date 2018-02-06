/*
** Boss.cpp for cpp_indie_studio in /home/chenne_a/delivery/cpp_indie_studio/Boss.cpp
**
** Made by Prenom Nom
** Login   <arthur.chennetier@epitech.eu>
**
** Started on  mer. juin 14 13:59:23 2017 Prenom Nom
** Last update Sun Jun 18 21:44:46 2017 Florent Sebag
*/

#include "EnnemyEntity.hpp"

void                          NsEntity::Boss::Death()
{

}

void                          NsEntity::Boss::Static()
{

}

void                          NsEntity::Boss::AutoShot()
{

}

void                          NsEntity::Boss::MoveBoss()
{
  irr::core::matrix4 m;
  irr::core::vector3df vel = this->Speed_;
  irr::core::vector3df new_pos;

  this->getNode()->setRotation(faceTarget(this->ToGo, this->getNode()->getPosition()));
  m.setRotationDegrees(this->getNode()->getRotation());
  m.transformVect(vel);
  new_pos = this->getNode()->getPosition() - vel;
  this->getNode()->setPosition(new_pos);
}

void NsEntity::Boss::BossBegin()
{
  this->ToGo.X = -1116.83;
  this->ToGo.Z = -4562.27;
  this->isGoing = true;
  this->strat = GOFIRST;
}

int NsEntity::Boss::CheckPos()
{
  if (this->getNode()->getPosition() == this->ToGo)
    return (1);
  return (0);
}

void NsEntity::Boss::setPosBacking()
{
  switch (this->strat)
  {
    case GOFIRST:
      this->newStrat();
    case GOSECOND:
      this->ToGo.X = -1116.83;
      this->ToGo.Z = -4562.27;
    case RIGHTLEFT:
      this->ToGo.X = -1116.83;
    default:
      return ;
  }
}

void NsEntity::Boss::newStrat()
{
  int rightleft;

  this->strat = NsEntity::Boss::BossStrat(rand() % 3);
  this->isGoing = true;
  this->isBacking = false;
  switch (this->strat)
  {
    case GOFIRST:
      BossBegin();
    case GOSECOND:
      this->ToGo.X = -1116.83;
      this->ToGo.Z = -4316.55;
    case RIGHTLEFT:
      rightleft = rand() % 1;
      if (rightleft == 0)
        this->ToGo.X = -895.222;
      else
        this->ToGo.X = -1389.15;
    default:
      return ;
  }
}

void NsEntity::Boss::BossHandler(irr::core::vector3df &focus)
{
  if (this->isGoing == true && this->CheckPos() == 1)
    {
      this->isBacking = true;
      this->isGoing = false;
      this->setPosBacking();
    }
  else if ((this->isBacking == true && this->CheckPos() == 1) || loop_follow == 120)
    {
      this->loop_follow = 0;
      this->newStrat();
    }
  else if (this->strat == FOLLOW)
    this->loop_follow += 1;
  this->MoveBoss();
}

NsEntity::Boss::Boss(Model3D& model) : EnnemyEntity(model)
{
  this->isMoving = true;
  this->isShooting = false;
  this->Health_ = 1000;
  this->MaxHealth_ = this->Health_;
  this->Damages_ = 30;
  this->Speed_ = irr::core::vector3df(0,0,1.5f);
  this->isBacking = false;
  this->loop_follow = 0;
  BossBegin();
}

NsEntity::Boss::~Boss()
{

}
