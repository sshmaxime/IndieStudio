/*
** include.h for cpp_indie_studio in /home/aubane_m/tek2/cpp_indie_studio/include
**
** Made by aubane_m
** Login   <aubane_m@epitech.net>
**
** Started on  Thu May 04 17:29:25 2017 aubane_m
** Last update Thu May 18 22:03:19 2017 sshSupreme
*/

#ifndef _INCLUDE_H_
# define _INCLUDE_H_

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include <chrono>
#include <unordered_map>
#include <memory>

typedef struct      s_score
{
  std::string       NamePlayer;
  std::vector<int>  Score;
}                   t_score;

#endif
