/*
** Font.cpp for new in /home/sshsupreme/tek2/new/sources/RessourceManager
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Thu May 18 00:01:19 2017 sshSupreme
** Last update Fri May 26 04:15:26 2017 sshSupreme
*/

#include "Font.hpp"
#include "GeneralGUI.hpp"

Font::Font(const std::string& FontPath)
{
  Font_ = NsGUI::GraphicsEngine::Instance().Environment()->getFont(FontPath.c_str());
}

Font::~Font()
{

}
