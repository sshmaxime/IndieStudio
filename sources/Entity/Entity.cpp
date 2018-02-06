/*
** Entity.cpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/newEntity
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Fri Jun 02 22:57:11 2017 sshSupreme
** Last update Sat Jun 17 23:44:10 2017 Florent Sebag
*/

#include "Entity.hpp"

Model3D&                              NsEntity::Entity::getModel() const {return (this->Model3D_);}
irr::scene::IAnimatedMeshSceneNode*   NsEntity::Entity::getNode() const {return (this->node_);}
void                                  NsEntity::Entity::setNode(irr::scene::IAnimatedMeshSceneNode* node) {node_ = node;}



bool                                  NsEntity::Entity::isAlive() const
{
  if (this->Health_ <= 0)
    return (false);
  return (true);
}

void                            NsEntity::Entity::UpdateCoolDown()
{
  static size_t                 speedAttack = 0;

  if (this->ableAttack_ == false && speedAttack < this->speedAttack_)
    speedAttack = speedAttack + 1;
  if (this->ableAttack_ == false && speedAttack == this->speedAttack_) {this->ableAttack_ = true; speedAttack = 0;}
}

void                                  NsEntity::Entity::Initialization()
{

}

size_t                                NsEntity::Entity::getHealth() const {return (this->Health_);}
size_t                                NsEntity::Entity::getMaxHealth() const {return (this->MaxHealth_);}
size_t                                NsEntity::Entity::getDamage() const {return (this->Damages_);}
bool                                  NsEntity::Entity::getableAttack_() const {return (this->ableAttack_);}
void                                  NsEntity::Entity::setHealth(size_t value) {this->Health_ = value;}
void                                  NsEntity::Entity::setMaxHealth(size_t value) {this->MaxHealth_ = value;}
void                                  NsEntity::Entity::setDamages(size_t value) {this->Damages_ = value;}

irr::core::vector3d<irr::f32>         NsEntity::Entity::faceTarget(irr::core::vector3d<irr::f32> targetpos, const irr::core::vector3df &nodepos)
{
  irr::core::vector3df posDiff = targetpos - nodepos;
  irr::f32 degree = nodepos.Y; //keep current rotation if nothing to do
  posDiff.normalize();
  if (posDiff.X != 0.0f || posDiff.Z != 0.0f)
    degree = (irr::f32) (atan2(posDiff.X, posDiff.Z) * irr::core::RADTODEG);
  return irr::core::vector3df(0,degree - 180,0);
}

NsEntity::Entity::Entity(Model3D& model) : Model3D_(model)
{
  this->node_ = NULL;
}

NsEntity::Entity::~Entity()
{

}
