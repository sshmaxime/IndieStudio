/*
** SettingsType.hpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/include
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Thu May 11 19:18:39 2017 sshSupreme
** Last update Thu May 11 20:28:50 2017 sshSupreme
*/

#include "ISettingsType.hpp"

class Brightness : public ISettingsType
{
private:
  int                   value_;
  const std::string&    name_;

public:
  void                    setValue(int value) {value_ = value;}
  int                     getValue() const {return value_;}
  const std::string&      getName() const {return name_;}
  void                    incValue();
  void                    decValue();

public:
  Brightness(int);
  virtual ~Brightness();
};

class GeneralVolume : public ISettingsType
{
private:
  int                   value_;
  const std::string&    name_;

public:
  void                    setValue(int value) {value_ = value;}
  int                     getValue() const {return value_;}
  const std::string&      getName() const {return name_;}
  void                    incValue();
  void                    decValue();

public:
  GeneralVolume(int);
  virtual ~GeneralVolume();
};
