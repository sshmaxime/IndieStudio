/*
** Audio.hpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/RessourceManager
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Fri May 26 00:17:12 2017 sshSupreme
** Last update Fri Jun 16 04:41:44 2017 Antoine Deforges
*/

#ifndef _MUSIC_HPP_
# define _MUSIC_HPP_

#include "include.h"
#include <SFML/Audio.hpp>

class Music
{
private:
  sf::Music                  Music_;

public:
  sf::Music&                 getMusic() {
    Music_.setLoop(true);
    return Music_;
  }

  void                       setVolume(int volume) {
    switch (volume) {
      case 0:
      Music_.setVolume(0);
      break;
      case 1:
      Music_.setVolume(25);
      break;
      case 2:
      Music_.setVolume(50);
      break;
      case 3:
      Music_.setVolume(75);
      break;
      case 4:
      Music_.setVolume(100);
      break;
    }
  }

public:
  Music(const std::string&);
  ~Music();
};

class Sound
{
private:
  sf::Sound                  Sound_;
  sf::SoundBuffer            SoundBuffer_;

public:
  sf::Sound&                 getSound() {return Sound_;}

public:
  Sound(const std::string&);
  ~Sound();
};

#endif
