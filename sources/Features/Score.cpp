/*
** Score.cpp for cpp_indie_studio in /home/aubane_m/tek2/cpp_indie_studio/src
**
** Made by aubane_m
** Login   <aubane_m@epitech.net>
**
** Started on  Thu May 04 17:15:31 2017 aubane_m
** Last update Wed May 17 20:11:48 2017 sshSupreme
*/

#include "Score.hpp"

void                                    Score::load()
{
  std::string                           line;
  std::ifstream                         myfile(this->PathDirectory);
  t_score                               score;

  if (myfile.is_open())
    {
      while (getline (myfile, line))
        {
          if (line.size() == 0)
            V_Score.push_back(score);
          else if (line[0] == '[' && line[line.size() - 1] == ']')
            {
              line[0] = '\0';
              line.pop_back();
              line.erase(std::remove(line.begin(), line.end(), '\0'), line.end());
              score.NamePlayer = line;
              score.Score.clear();
            }
          else if (line[0] >= 48 && line[0] <= 57)
            score.Score.push_back(std::stoi(line));
        }
      myfile.close();
    }
}

void                                    Score::add(const std::string& namePlayer, int score)
{
  t_score                               newScore;

  for (auto it = V_Score.begin(); it != V_Score.end();++it)
    {
      if (it->NamePlayer.compare(namePlayer) == 0)
        {
          for (auto i = it->Score.begin(); i != it->Score.end(); ++i)
            {
              if (*i == score)
                return ;
            }
          it->Score.push_back(score);
          return ;
        }
    }
  newScore.NamePlayer = namePlayer;
  newScore.Score.push_back(score);
  V_Score.push_back(newScore);
}

void                                    Score::save()
{
  std::ofstream                         myFile(this->PathDirectory);

  for (auto it = V_Score.begin(); it != V_Score.end();++it)
    {
      myFile << "[" << it->NamePlayer << "]" << std::endl;
      for (auto i = it->Score.begin(); i != it->Score.end(); ++i)
        {
          myFile << *i << std::endl;
        }
      myFile << std::endl;
    }
  myFile << "--end--";
  myFile.close();
}

void                                    Score::reset()
{
  this->V_Score.clear();
  this->save();
}

std::vector<struct s_score>             Score::getScore()
{
  return (V_Score);
}

void                                    Score::Initialization()
{
  this->load();
}

Score::Score(const std::string& path)
{
  this->PathDirectory = path;
}

Score::~Score()
{
  this->save();
}
