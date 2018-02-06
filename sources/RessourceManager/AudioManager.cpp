/*
** AudioManager.cpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/RessourceManager
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Fri May 26 00:16:11 2017 sshSupreme
** Last update Fri May 26 04:09:38 2017 sshSupreme
*/

#include "AudioManager.hpp"

void                      AudioManager::addMusic(const std::string& MusicName, const std::string& MusicPath)
{
  std::shared_ptr<Music>  newMusic = std::make_shared<Music>(MusicPath);

  this->m_Musics.insert( {MusicName, newMusic} );
}

std::shared_ptr<Music>    AudioManager::getMusic(const std::string& MusicName)
{
  return (this->m_Musics.at(MusicName));
}

void                      AudioManager::addSound(const std::string& SoundName, const std::string& SoundPath)
{
  std::shared_ptr<Sound>  newSound = std::make_shared<Sound>(SoundPath);

  this->m_Sounds.insert( {SoundName, newSound} );
}

std::shared_ptr<Sound>   AudioManager::getSound(const std::string& SoundName)
{
  return (this->m_Sounds.at(SoundName));
}

AudioManager::AudioManager()
{

}

AudioManager::~AudioManager()
{

}
