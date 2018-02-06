/*
** Models3DManager.cpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/src
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Fri May 12 23:27:37 2017 sshSupreme
** Last update Mon Jun 05 22:30:57 2017 sshSupreme
*/

#include "Models3DManager.hpp"

void    Models3DManager::addModel(const std::string& ModelName, const std::string& MeshPath, const std::string& TexturePath)
{
  Model3D        newModel(MeshPath, TexturePath);

  this->m_Models.insert( {ModelName, newModel} );
}

void    Models3DManager::addModel(const std::string& ModelName, const std::string& MeshPath)
{
  Model3D        newModel(MeshPath);

  this->m_Models.insert( {ModelName, newModel} );
}

Model3D &Models3DManager::getModel(const std::string& ModelName)
{
  return (this->m_Models.at(ModelName));
}

Models3DManager::Models3DManager()
{

}

Models3DManager::~Models3DManager()
{

}
