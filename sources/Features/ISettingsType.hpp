/*
** ISettingsType.hpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/include
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Thu May 11 16:01:21 2017 sshSupreme
** Last update Thu May 11 20:27:36 2017 sshSupreme
*/

#include "include.h"

class ISettingsType
{
public:
  virtual int                     getValue() const = 0;
  virtual const std::string&      getName() const= 0;
  virtual void                    setValue(int) = 0;
  virtual void                    incValue() = 0;
  virtual void                    decValue() = 0;

public:
  virtual ~ISettingsType() {}
};
