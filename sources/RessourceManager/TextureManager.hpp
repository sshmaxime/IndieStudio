/*
** TextureManager.hpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/RessourceManager
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Mon Jun 05 22:33:25 2017 sshSupreme
** Last update Mon Jun 05 22:36:01 2017 sshSupreme
*/

#include "include.h"

#ifndef _TEXTUREMANAGER_HPP_
# define _TEXTUREMANAGER_HPP_

#include "include.h"
#include "Texture.hpp"

class TextureManager
{
private:
  std::unordered_map<std::string, Texture>      m_Textures;

public:
  void        addTexture(const std::string&, const std::string&);
  Texture     &getTexture(const std::string&);

public:
  TextureManager();
  ~TextureManager();
};

#endif
