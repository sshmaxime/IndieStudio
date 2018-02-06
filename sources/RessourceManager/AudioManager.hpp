/*
** AudioManager.hpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/RessourceManager
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Fri May 26 00:17:14 2017 sshSupreme
** Last update Fri May 26 04:07:19 2017 sshSupreme
*/

#ifndef _AUDIOMANAGER_HPP_
# define _AUDIOMANAGER_HPP_

#include "include.h"
#include "Audio.hpp"

class AudioManager
{
private:
  std::unordered_map<std::string, std::shared_ptr<Music>>      m_Musics;
  std::unordered_map<std::string, std::shared_ptr<Sound>>      m_Sounds;

public:
  void                         addMusic(const std::string&, const std::string&);
  void                         addSound(const std::string&, const std::string&);
  std::shared_ptr<Music>       getMusic(const std::string&);
  std::shared_ptr<Sound>       getSound(const std::string&);

public:
  AudioManager();
  ~AudioManager();
};

#endif
