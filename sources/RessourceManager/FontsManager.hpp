/*
** FontsManager.hpp for new in /home/sshsupreme/tek2/new/sources/RessourceManager
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Wed May 17 23:55:09 2017 sshSupreme
** Last update Fri May 26 00:18:50 2017 sshSupreme
*/

#ifndef _FONTSMANAGER_HPP_
# define _FONTSMANAGER_HPP_

#include "include.h"
#include "Font.hpp"

class FontsManager
{
private:
  std::unordered_map<std::string, Font>      m_Fonts;

public:
  void        addFont(const std::string&, const std::string&);
  Font       &getFont(const std::string&);

public:
  FontsManager();
  ~FontsManager();
};

#endif
