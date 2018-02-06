/*
** SettingsType.cpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/src
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Thu May 11 16:03:03 2017 sshSupreme
** Last update Thu May 11 19:28:36 2017 sshSupreme
*/

#include "SettingsType.hpp"

void Brightness::incValue() {if (value_ == 100) return; else value_++;}
void Brightness::decValue() {if (value_ == 0) return; else value_--;}
Brightness::Brightness(int value) : value_(value), name_("Brightness") {}
Brightness::~Brightness() {}

void GeneralVolume::incValue() {if (value_ == 100) return; else value_++;}
void GeneralVolume::decValue() {if (value_ == 0) return; else value_--;}
GeneralVolume::GeneralVolume(int value) : value_(value), name_("GeneralVolume") {}
GeneralVolume::~GeneralVolume() {}
