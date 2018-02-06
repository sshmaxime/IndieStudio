/*
** Projectil.hpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/Projectil
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Mon Jun 05 21:38:22 2017 sshSupreme
** Last update Wed Jun 07 21:10:56 2017 sshSupreme
*/

#ifndef _PROJECTIL_HPP_
# define _PROJECTIL_HPP_

#include <irrlicht.h>
#include "include.h"
#include "Texture.hpp"
#include "EnnemyEntity.hpp"

using namespace irr;

namespace NsProjectil
{
class Projectil
{
protected:
  bool                                    isAlive_ = true;

public:
  bool                                    isAlive() const {return (isAlive_);};

public:
  virtual void                            Move() = 0;
  virtual void                            setNode(irr::scene::IParticleSystemSceneNode*) = 0;
  virtual irr::scene::ISceneNode*         getNode() = 0;
  virtual Texture&                        getTexture() = 0;
  virtual void                            Initialization() = 0;
  virtual bool                            CheckCollision(std::vector<std::shared_ptr<NsEntity::EnnemyEntity>>&) = 0;
};

class Fireball : public Projectil
{
protected:
  Texture                                 &Texture_;
  const irr::core::vector3df              &Dir_;
  irr::scene::IParticleSystemSceneNode*   node_;

protected:
  size_t                                  Damages_;
  irr::core::vector3df                    Speed_;

public:
  void                                    setNode(irr::scene::IParticleSystemSceneNode*);
  irr::scene::IParticleSystemSceneNode*   getNode();
  Texture&                                getTexture();
  void                                    Initialization();
  bool                                    CheckCollision(std::vector<std::shared_ptr<NsEntity::EnnemyEntity>>&);

public:
  void                                    Move();

public:
  Fireball(Texture&, const irr::core::vector3df&);
  ~Fireball();
};
}

#endif
