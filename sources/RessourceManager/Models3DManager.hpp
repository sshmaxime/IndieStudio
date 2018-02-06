/*
** Models3DManager.hpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/include
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Fri May 12 23:27:15 2017 sshSupreme
** Last update Fri May 19 03:54:39 2017 sshSupreme
*/

#ifndef _MODELS3DMANAGER_HPP_
# define _MODELS3DMANAGER_HPP_

#include "include.h"
#include "Model3D.hpp"

class Models3DManager
{
private:
  std::unordered_map<std::string, Model3D>      m_Models;

public:
  void        addModel(const std::string&, const std::string&);
  void        addModel(const std::string&, const std::string&, const std::string&);
  Model3D     &getModel(const std::string&);

public:
  Models3DManager();
  ~Models3DManager();
};

#endif
