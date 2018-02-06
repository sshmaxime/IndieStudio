/*
** Settings.cpp for cpp_indie_studio in /home/aubane_m/tek2/cpp_indie_studio/src
**
** Made by aubane_m
** Login   <aubane_m@epitech.net>
**
** Started on  Fri May 05 11:17:18 2017 aubane_m
** Last update Thu May 11 20:43:06 2017 sshSupreme
*/

#include "Settings.hpp"

t_arrayFunction tab[] = {
  {"BRIGHTNESS", &Settings::getBrightness},
  {"GENERALVOLUME", &Settings::getGeneralVolume},
  {"END", &Settings::getBrightness}
};

void                                      Settings::reset()
{
  this->getBrightness().setValue(50);
  // this->getGeneralVolume().setValue(50);
}

void                                      Settings::load()
{
  std::ifstream                           myfile(this->PathDirectory);
  int                                     pos;
  std::string                             line;
  std::string                             type;
  std::string                             value;
  int                                     x;

  this->reset();
  if (myfile.is_open())
    {
      while (getline (myfile, line))
        {
          x = 0;
          pos = line.find("=");
          value = line.substr(pos + 1);
          type = line.substr(0, pos);
          while (tab[x].SettingsType.compare("END") != 0)
            {
              if (tab[x].SettingsType.compare(type) == 0)
                (this->*tab[x].getter)().setValue(std::stoi(value));
              x = x + 1;
            }
        }
      myfile.close();
    }
}

void                                      Settings::save()
{
  std::ofstream                           myFile(this->PathDirectory);
  int                                     x = 0;

  while (tab[x].SettingsType.compare("END") != 0)
    {
      myFile << tab[x].SettingsType << "=" << (this->*tab[x].getter)().getValue() << std::endl;
      x = x + 1;
    }
  myFile << "\n--end--";
  myFile.close();
}

void                                    Settings::Initialization()
{
  this->reset();
  this->load();
}

Settings::Settings(const std::string& path)
{
  Brightness_ = new Brightness(50);
  GeneralVolume_ = new GeneralVolume(50);
  this->PathDirectory = path;
}

Settings::~Settings()
{
  // this->save();
}
