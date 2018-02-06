/*
** Audio.cpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/RessourceManager
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Fri May 26 00:17:10 2017 sshSupreme
** Last update Fri May 26 04:05:27 2017 sshSupreme
*/

#include "Audio.hpp"

Music::Music(const std::string& MusicPath)
{
  this->Music_.openFromFile(MusicPath);
}

Music::~Music()
{

}

Sound::Sound(const std::string& SoundPath)
{
  this->SoundBuffer_.loadFromFile(SoundPath);
  this->Sound_.setBuffer(this->SoundBuffer_);
}

Sound::~Sound()
{

}
