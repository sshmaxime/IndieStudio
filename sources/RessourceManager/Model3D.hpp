/*
** Model3D.hpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/include
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Fri May 12 22:38:44 2017 sshSupreme
** Last update Thu May 18 00:11:19 2017 sshSupreme
*/

#ifndef _MODEL_3D_HPP_
# define _MODEL_3D_HPP_

#include "include.h"
#include <irrlicht.h>

class Model3D
{
private:
  irr::scene::IAnimatedMesh *Mesh_;
  irr::video::ITexture      *Texture_;

public:
  irr::scene::IAnimatedMesh* getMesh() const {return Mesh_;}
  irr::video::ITexture*      getTexture() const {return Texture_;}

public:
  Model3D(const std::string&, const std::string&);
  Model3D(const std::string&);
  ~Model3D();
};

#endif
