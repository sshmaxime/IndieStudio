/*
** Settings.hpp for cpp_indie_studio in /home/aubane_m/tek2/cpp_indie_studio/include
**
** Made by aubane_m
** Login   <aubane_m@epitech.net>
**
** Started on  Fri May 05 11:16:13 2017 aubane_m
** Last update Sun May 14 19:37:40 2017 sshSupreme
*/

#include "include.h"
#include "SettingsType.hpp"

class Settings
{
private:
  std::string                           PathDirectory;

private:
  ISettingsType                         *Brightness_;
  ISettingsType                         *GeneralVolume_;

public:
  void                    Initialization();
  void                    reset(); // reset settings to usine version
  void                    load();
  void                    save();  // save settings in file

public:
  ISettingsType&          getBrightness() {return *Brightness_;}
  ISettingsType&          getGeneralVolume() {return *GeneralVolume_;}

public:
  Settings(const std::string&); // path to directory of settings file
  ~Settings();
};

typedef struct s_arrayFunction
{
  std::string     SettingsType;
  ISettingsType&  (Settings::*getter)();
}                 t_arrayFunction;
