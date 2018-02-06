/*
** PlayableEntity.cpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/newEntity
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Sat Jun 03 00:00:41 2017 sshSupreme
** Last update Sun Jun 18 17:32:59 2017 Florent Sebag
*/

#include <iostream>
#include "PlayableEntity.hpp"
#include "../Gui/GeneralGUI.hpp"

size_t                           NsEntity::PlayableEntity::getGold() const {return (this->Gold_);}
size_t                           NsEntity::PlayableEntity::getKeys() const {return (this->Keys_);}
void                             NsEntity::PlayableEntity::setGold(size_t value) {this->Gold_ = value;}
void                             NsEntity::PlayableEntity::setKeys(size_t value) {this->Keys_ = value;}
bool				 NsEntity::PlayableEntity::getIsDying() const {return this->_isDying;}
void 				 NsEntity::PlayableEntity::setIsDying(bool isDying) {this->_isDying = isDying;}

void                             NsEntity::PlayableEntity::Move(f32 Horizontal, f32 Vertical)
{
  NsGUI::GraphicsEngine &engine = NsGUI::GraphicsEngine::Instance();

  Horizontal = -(Horizontal);
  irr::core::matrix4 m;
  irr::core::vector3df vel = irr::core::vector3df(0,0,4.0f);
  core::vector3df direction = core::vector3df(Horizontal, 0, Vertical);
  core::vector3df pos;
  m.transformVect(direction);
  this->getNode()->setRotation(faceTarget(direction, this->getNode()->getPosition()));
  m.setRotationDegrees(this->getNode()->getRotation());
  m.transformVect(vel);
  pos = this->getNode()->getPosition();
  this->getNode()->setPosition(this->getNode()->getPosition() - vel);
  this->Move();
 // std::cout << this->getNode()->getPosition().X << "," << this->getNode()->getPosition().Y << "," << this->getNode()->getPosition().Z << std::endl;
}

void                            NsEntity::PlayableEntity::Jump()
{
  /* irr::core::matrix4 m;
   irr::core::vector3df vel = irr::core::vector3df(0,15,0);

   m.setRotationDegrees(this->getNode()->getRotation());
   m.transformVect(vel);
   this->getNode()->setPosition(this->getNode()->getPosition() + vel);*/
}

void                            NsEntity::PlayableEntity::Moveback()
{
  NsGUI::GraphicsEngine &engine = NsGUI::GraphicsEngine::Instance();
  irr::core::matrix4 m;
  irr::core::vector3df vel = irr::core::vector3df(0,0,4.0f);
  core::vector3df pos;
  m.setRotationDegrees(this->getNode()->getRotation());
  m.transformVect(vel);
  pos = this->getNode()->getPosition();
  this->getNode()->setPosition(this->getNode()->getPosition() + vel);
}

// void                            NsEntity::PlayableEntity::UpdateCoolDown()
// {
//   static size_t                 speedAttack = 0;
//
//   if (this->ableAttack_ == false && speedAttack < this->speedAttack_)
//     speedAttack = speedAttack + 1;
//   if (this->ableAttack_ == false && speedAttack == this->speedAttack_) {this->ableAttack_ = true; speedAttack = 0;}
// }

void                            NsEntity::PlayableEntity::AutoShot(std::vector<std::shared_ptr<NsEntity::EnnemyEntity>> ennemy, std::vector<std::shared_ptr<NsProjectil::Projectil>>& projectil)
{
  if (this->ableAttack_ == false)
    return ;
  if (this->Ranger_ == false)
    {
      for (auto i = ennemy.begin(); i < ennemy.end(); i++)
        {
          if (this->getNode()->getTransformedBoundingBox().intersectsWithBox((*i)->getNode()->getTransformedBoundingBox()))
            (*i)->takeDamage(this->Damages_);
        }
    }
  else
    this->AutoRangeShot(projectil);
  this->AutoShot();
  this->ableAttack_ = false;
}

void                      NsEntity::PlayableEntity::takeDamage(size_t value)
{
  std::cout << "coucou takedmg" << std::endl;
  if (value > this->Health_)
    this->Health_ = 0;
  else
    this->Health_ = this->Health_ - value;
  std::cout << "Health : " << this->Health_ << std::endl;
}

NsEntity::PlayableEntity::PlayableEntity(Model3D& model) : Entity(model)
{
  this->Keys_ = 0;
  this->Gold_ = 0;
  this->_isDying = true;
}

NsEntity::PlayableEntity::~PlayableEntity()
{

}
