/*
** Score.hpp for cpp_indie_studio in /home/aubane_m/tek2/cpp_indie_studio/include
**
** Made by aubane_m
** Login   <aubane_m@epitech.net>
**
** Started on  Thu May 04 17:15:27 2017 aubane_m
** Last update Wed May 17 21:13:59 2017 sshSupreme
*/

#ifndef _SCORE_HPP_
# define _SCORE_HPP_

#include "include.h"

class Score
{
private:
  std::vector<struct s_score>           V_Score;
  std::string                           PathDirectory;

public:
  void                                  add(const std::string&, int); //add a score
  void                                  load();//update Score with file
  void                                  save();//updata ScoreFile with class
  void                                  reset();//delete all score
  void                                  Initialization();
public:
  std::vector<struct s_score>           getScore();

public:
  Score(const std::string&); //path to directory of score files
  ~Score();
};

#endif
