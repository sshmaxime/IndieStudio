/*
** Texture.hpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/RessourceManager
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Mon Jun 05 22:35:56 2017 sshSupreme
** Last update Mon Jun 05 22:38:48 2017 sshSupreme
*/

#ifndef _TEXTURE_HPP_
# define _TEXTURE_HPP_

#include "../include.h"
#include <irrlicht.h>

class Texture
{
private:
  irr::video::ITexture      *Texture_;

public:
  irr::video::ITexture*      getTexture() const {return Texture_;}

public:
  Texture(const std::string&);
  ~Texture();
};

#endif
