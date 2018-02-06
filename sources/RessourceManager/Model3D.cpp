/*
** Model3D.cpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/src
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Fri May 12 22:38:41 2017 sshSupreme
** Last update Mon Jun 05 22:36:11 2017 sshSupreme
*/

#include "Model3D.hpp"
#include "GeneralGUI.hpp"

Model3D::Model3D(const std::string& MeshPath, const std::string& TexturePath)
{
  Mesh_ = NsGUI::GraphicsEngine::Instance().Scene()->getMesh(MeshPath.c_str());
  Texture_ = NsGUI::GraphicsEngine::Instance().Driver()->getTexture(TexturePath.c_str());
}

Model3D::Model3D(const std::string& MeshPath)
{
  Mesh_ = NsGUI::GraphicsEngine::Instance().Scene()->getMesh(MeshPath.c_str());
  Texture_ = NULL;
}

Model3D::~Model3D()
{

}
