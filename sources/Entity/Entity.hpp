/*
** Entity.hpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/newEntity
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Fri Jun 02 22:56:53 2017 sshSupreme
** Last update Sat Jun 17 23:43:22 2017 Florent Sebag
*/

#ifndef _ENTITY_HPP_
# define _ENTITY_HPP_

#include <memory>
#include <vector>
#include "../include.h"
#include "Model3D.hpp"
#include "Healthbar.hpp"
#include "../RessourceManager/Model3D.hpp"
#include "../../irrlicht/include/IAnimatedMeshSceneNode.h"

namespace NsEntity
{
  class Entity
    {
    protected:
      std::string                           EntityName;
      irr::scene::IAnimatedMeshSceneNode    *node_;
      Model3D                               &Model3D_;

    protected:
      size_t                                 Health_;
      size_t                                 MaxHealth_;

    protected:
      size_t                                 Damages_;

    protected:
    size_t                            	     speedAttack_ = 0;
    bool                              	     ableAttack_ = true;

    protected:
      bool                                   isMoving;
      bool                                   isShooting;

    public:
      bool                                   isAlive() const;

    public:
      virtual void                           Death() = 0;
      virtual void                           takeDamage(size_t) = 0;
      virtual void                           Jump() = 0;
      virtual void                           Static() = 0;
      virtual void                           Move(irr::f32, irr::f32) = 0;
      void                                   UpdateCoolDown();

    public:
      void                                   Initialization();
      Model3D&                               getModel() const;
      irr::scene::IAnimatedMeshSceneNode*    getNode() const;
      void                                   setNode(irr::scene::IAnimatedMeshSceneNode*);

    public:
      size_t                                 getHealth() const;
      size_t                                 getMaxHealth() const;
      size_t                                 getDamage() const;
      bool                                   getableAttack_() const;

    public:
      void                                   setHealth(size_t);
      void                                   setMaxHealth(size_t);
      void                                   setDamages(size_t);

    public:
      irr::core::vector3d<irr::f32>          faceTarget(irr::core::vector3d<irr::f32> vector3d, const irr::core::vector3df &vector3d1);

    public:
      Entity(Model3D &);
      virtual ~Entity();
    };
}

#endif
