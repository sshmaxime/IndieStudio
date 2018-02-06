/*
** Fireball.cpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/Projectil
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Mon Jun 05 22:18:21 2017 sshSupreme
** Last update Wed Jun 07 21:12:21 2017 sshSupreme
*/

#include "Projectil.hpp"

void                            NsProjectil::Fireball::setNode(irr::scene::IParticleSystemSceneNode* node) {node_ = node;}
Texture&                        NsProjectil::Fireball::getTexture() {return (Texture_);}

void                            NsProjectil::Fireball::Initialization()
{
  this->node_->setRotation(this->Dir_);
}

irr::scene::IParticleSystemSceneNode*   NsProjectil::Fireball::getNode()
{
  return (this->node_);
}

bool                            NsProjectil::Fireball::CheckCollision(std::vector<std::shared_ptr<NsEntity::EnnemyEntity>>& v)
{
  for (auto i = v.begin(); i < v.end(); i++)
    {
      if (this->node_->getTransformedBoundingBox().intersectsWithBox((*i)->getNode()->getTransformedBoundingBox()))
        {
          (*i)->takeDamage(this->Damages_);
          this->isAlive_ = false;
          return (true);
        }
    }
  return (false);
}

void                            NsProjectil::Fireball::Move()
{
  irr::core::matrix4 m;
  irr::core::vector3df vel = this->Speed_;

  m.setRotationDegrees(this->node_->getRotation());
  m.transformVect(vel);
  this->node_->setPosition(this->node_->getPosition() - vel);
}

NsProjectil::Fireball::Fireball(Texture& texture, const irr::core::vector3df& vector) : Texture_(texture), Dir_(vector)
{
  this->Speed_ = irr::core::vector3df(0, 0, 6.0f);
  this->Damages_ = 50;
}

NsProjectil::Fireball::~Fireball()
{
}
