/*
** KeyInput.cpp for new in /home/sshsupreme/tek2/new/sources/Events
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Wed May 17 17:12:02 2017 sshSupreme
** Last update Tue May 23 16:34:18 2017 sshSupreme
*/

#include "EventHandler.hpp"

NsEvents::KeyInput::KeyInput(int id)
{
  playerID_ = id;
  UP_ = false;
  DOWN_ = false;
  LEFT_ = false;
  RIGHT_ = false;
  SQUARE_ = false;
  CIRCLE_ = false;
  CROSS_ = false;
  TRIANGLE_ = false;
  JLEFT_ = false;
  JRIGHT_ = false;
  JLEFTVALUE_X_ = 0.f;
  JLEFTVALUE_Y_ = 0.f;
  JRIGHTVALUE_X_ = 0.f;
  JRIGHTVALUE_Y_ = 0.f;
  R1_ = false;
}

NsEvents::KeyInput::~KeyInput()
{

}
