/*
** FontsManager.cpp for new in /home/sshsupreme/tek2/new/sources/RessourceManager
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Wed May 17 23:55:07 2017 sshSupreme
** Last update Fri May 26 04:15:34 2017 sshSupreme
*/

#include "FontsManager.hpp"

void    FontsManager::addFont(const std::string& FontName, const std::string& FontPath)
{
  Font        newFont(FontPath);

  this->m_Fonts.insert( {FontName, newFont} );
}

Font &FontsManager::getFont(const std::string& FontName)
{
  return (this->m_Fonts.at(FontName));
}

FontsManager::FontsManager()
{

}

FontsManager::~FontsManager()
{

}
