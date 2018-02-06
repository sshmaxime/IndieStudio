/*
** Texture.cpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/RessourceManager
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Mon Jun 05 22:35:57 2017 sshSupreme
** Last update Mon Jun 05 22:37:08 2017 sshSupreme
*/

#include "Texture.hpp"
#include "../Gui/GeneralGUI.hpp"

Texture::Texture(const std::string& TexturePath)
{
  Texture_ = NsGUI::GraphicsEngine::Instance().Driver()->getTexture(TexturePath.c_str());
}

Texture::~Texture()
{

}
