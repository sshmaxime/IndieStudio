/*
** TextureManager.cpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/RessourceManager
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Mon Jun 05 22:32:14 2017 sshSupreme
** Last update Mon Jun 05 22:40:13 2017 sshSupreme
*/

#include "TextureManager.hpp"

void    TextureManager::addTexture(const std::string& TextureName, const std::string& TexturePath)
{
  Texture        newModel(TexturePath);

  this->m_Textures.insert( {TextureName, newModel} );
}

Texture &TextureManager::getTexture(const std::string& TextureName)
{
  return (this->m_Textures.at(TextureName));
}

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{

}
