/*
** Font.hpp for new in /home/sshsupreme/tek2/new/sources/RessourceManager
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Thu May 18 00:01:18 2017 sshSupreme
** Last update Fri May 26 04:15:28 2017 sshSupreme
*/

#ifndef _FONT_HPP_
# define _FONT_HPP_

#include "include.h"
#include <irrlicht.h>

class Font
{
private:
  irr::gui::IGUIFont         *Font_;

public:
  irr::gui::IGUIFont*        getFont() const {return Font_;}

public:
  Font(const std::string&);
  ~Font();
};

#endif
