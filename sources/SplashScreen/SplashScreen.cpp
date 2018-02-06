/*
** SplashScreen.cpp for cpp_indie_studio in /home/chenne_a/delivery/cpp_indie_studio/SplashScreen.cpp
**
** Made by Prenom Nom
** Login   <arthur.chennetier@epitech.eu>
**
** Started on  mer. juin 07 16:51:23 2017 Prenom Nom
** Last update mer. juin 07 16:51:23 2017 Prenom Nom
*/

#include <math.h>
#include "../../irrlicht/include/irrlicht.h"
#include "SplashScreen.hpp"

using namespace irr;
using namespace core;
using namespace video;

SplashScreen::SplashScreen()
{
  std::cout << "Launching SplashScreen" << std::endl;
}

void 		SplashScreen::Initialisation()
{
  NsGUI::GraphicsEngine &engine = NsGUI::GraphicsEngine::Instance();

  irr::core::vector3df pos(-11, 1028, 1320);
  irr::core::vector3df rot(0, 179, 0);
  engine.Scene()->getActiveCamera()->setPosition(pos);
  engine.Scene()->getActiveCamera()->setRotation(rot);
}

void 		SplashScreen::move(irr::core::vector3df rot)
{
  NsGUI::GraphicsEngine &engine = NsGUI::GraphicsEngine::Instance();
  irr::core::matrix4 m;
  irr::core::vector3df vel = irr::core::vector3df(0,0,4.0f);

  m.setRotationDegrees(rot);
  m.transformVect(vel);
  engine.Scene()->getActiveCamera()->setPosition(engine.Scene()->getActiveCamera()->getPosition() + vel);
}

int		SplashScreen::rotate_right(irr::core::vector3df rot, int speed)
{
  NsGUI::GraphicsEngine &engine = NsGUI::GraphicsEngine::Instance();
  std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
  std::chrono::high_resolution_clock::time_point t2;
  float 		decX;
  float 		decY;
  float 		decZ;
  int 			i = 0;

  decX = (rot.X - engine.Scene()->getActiveCamera()->getTarget().X) / 250;
  decY = (rot.Y - engine.Scene()->getActiveCamera()->getTarget().Y) / 250;
  decZ = (rot.Z - engine.Scene()->getActiveCamera()->getTarget().Z) / 250;
  while (engine.Scene()->getActiveCamera()->getTarget().X > rot.X && engine.Device()->run())
    {
      t2 = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(
       t2 - t1);
      if ((*engine.getVEvents().begin())->getCROSS())
	return (-1);
      if (time_span > (std::chrono::duration<double>)0.007)
	{
	  if (i > speed)
	    {
	      decX = decX * 2;
	      decY = decY * 2;
	      decZ = decZ * 2;
	    }
	  irr::core::vector3df incr(engine.Scene()->getActiveCamera()->getTarget().X + decX,
				    engine.Scene()->getActiveCamera()->getTarget().Y + decY,
				    engine.Scene()->getActiveCamera()->getTarget().Z + decZ);
	  engine.Scene()->getActiveCamera()->setTarget(incr);
	  engine.Refresh();
	  t1 = std::chrono::high_resolution_clock::now();
	  i++;
	}
    }
  return (0);
}

int		SplashScreen::rotate_left(irr::core::vector3df rot, int speed)
{
  NsGUI::GraphicsEngine &engine = NsGUI::GraphicsEngine::Instance();
  std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
  std::chrono::high_resolution_clock::time_point t2;
  float 		decX;
  float 		decY;
  float 		decZ;
  int 			i = 0;

  decX = (rot.X - engine.Scene()->getActiveCamera()->getTarget().X) / 250;
  decY = (rot.Y - engine.Scene()->getActiveCamera()->getTarget().Y) / 250;
  decZ = (rot.Z - engine.Scene()->getActiveCamera()->getTarget().Z) / 250;
  while (engine.Scene()->getActiveCamera()->getTarget().X < rot.X && engine.Device()->run())
    {
      t2 = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(
       t2 - t1);
      if ((*engine.getVEvents().begin())->getCROSS())
	return (-1);
      if (time_span > (std::chrono::duration<double>)0.007)
	{
	  if (i > speed)
	    {
	      decX = decX * 2;
	      decY = decY * 2;
	      decZ = decZ * 2;
	    }
	  irr::core::vector3df incr(engine.Scene()->getActiveCamera()->getTarget().X + decX,
				    engine.Scene()->getActiveCamera()->getTarget().Y + decY,
				    engine.Scene()->getActiveCamera()->getTarget().Z + decZ);
	  engine.Scene()->getActiveCamera()->setTarget(incr);
	  engine.Refresh();
	  t1 = std::chrono::high_resolution_clock::now();
	  i++;
	}
    }
  return (0);
}


int		SplashScreen::move_rotateX(irr::core::vector3df mov, irr::core::vector3df rot, int stop, int frame)
{
  NsGUI::GraphicsEngine &engine = NsGUI::GraphicsEngine::Instance();
  std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
  std::chrono::high_resolution_clock::time_point t2;
  float 		decX;
  float 		decY;
  float 		decZ;
  float			decMov;

  decX = (rot.X - engine.Scene()->getActiveCamera()->getTarget().X) / frame;
  decY = (rot.Y - engine.Scene()->getActiveCamera()->getTarget().Y) / frame;
  decZ = (rot.Z - engine.Scene()->getActiveCamera()->getTarget().Z) / frame;
  decMov = abs((abs(stop) - abs(static_cast<int>(engine.Scene()->getActiveCamera()->getPosition().X)))) / frame;
  while (engine.Scene()->getActiveCamera()->getTarget().X > rot.X && engine.Device()->run())
    {
      t2 = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(
       t2 - t1);
      if ((*engine.getVEvents().begin())->getCROSS())
	return (-1);
      if (time_span > (std::chrono::duration<double>)0.01)
	{
	  irr::core::vector3df incr(engine.Scene()->getActiveCamera()->getTarget().X + decX,
				    engine.Scene()->getActiveCamera()->getTarget().Y + decY,
				    engine.Scene()->getActiveCamera()->getTarget().Z + decZ);
	  engine.Scene()->getActiveCamera()->setTarget(incr);
	  int tmp = abs(static_cast<int>(engine.Scene()->getActiveCamera()->getPosition().X));
	  while (abs(static_cast<int>(engine.Scene()->getActiveCamera()->getPosition().X)) - tmp < static_cast<int>(decMov))
	    move(mov);
	  engine.Refresh();
	  t1 = std::chrono::high_resolution_clock::now();
	}
    }
  return (0);
}

int		SplashScreen::move_rotateZ(irr::core::vector3df mov, irr::core::vector3df rot, int stop, int frame)
{
  NsGUI::GraphicsEngine &engine = NsGUI::GraphicsEngine::Instance();
  std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
  std::chrono::high_resolution_clock::time_point t2;
  float 		decX;
  float 		decY;
  float 		decZ;
  float			decMov;

  decX = (rot.X - engine.Scene()->getActiveCamera()->getTarget().X) / frame;
  decY = (rot.Y - engine.Scene()->getActiveCamera()->getTarget().Y) / frame;
  decZ = (rot.Z - engine.Scene()->getActiveCamera()->getTarget().Z) / frame;
  decMov = abs((abs(stop) - abs(static_cast<int>(engine.Scene()->getActiveCamera()->getPosition().Z)))) / frame;
  while (engine.Scene()->getActiveCamera()->getTarget().X > rot.X && engine.Device()->run())
    {
      t2 = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(
       t2 - t1);
      if ((*engine.getVEvents().begin())->getCROSS())
	return (-1);
      if (time_span > (std::chrono::duration<double>)0.01)
	{
	  irr::core::vector3df incr(engine.Scene()->getActiveCamera()->getTarget().X + decX,
				    engine.Scene()->getActiveCamera()->getTarget().Y + decY,
				    engine.Scene()->getActiveCamera()->getTarget().Z + decZ);
	  engine.Scene()->getActiveCamera()->setTarget(incr);
	  int tmp = abs(static_cast<int>(engine.Scene()->getActiveCamera()->getPosition().Z));
	  if (abs(static_cast<int>(engine.Scene()->getActiveCamera()->getPosition().Z)) < abs(stop))
	    {
	      while (abs(static_cast<int>(engine.Scene()->getActiveCamera()->getPosition().Z)) -
		     tmp < static_cast<int>(decMov))
		move(mov);
	    }
	  engine.Refresh();
	  t1 = std::chrono::high_resolution_clock::now();
	}
    }
  return (0);
}

int 		SplashScreen::wait_n_seconds(double seconds)
{
  NsGUI::GraphicsEngine &engine = NsGUI::GraphicsEngine::Instance();
  std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
  std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(
   t2 - t1);
  while (time_span < (std::chrono::duration<double>)seconds && engine.Device()->run())
    {
      if ((*engine.getVEvents().begin())->getCROSS())
	return (-1);
      engine.Refresh();
      t2 = std::chrono::high_resolution_clock::now();
      time_span = std::chrono::duration_cast<std::chrono::duration<double>>(
       t2 - t1);
    }
  return (0);
}

void		SplashScreen::LaunchSplashScreen()
{
  NsGUI::GraphicsEngine &engine = NsGUI::GraphicsEngine::Instance();

  while (engine.Scene()->getActiveCamera()->getPosition().Y > 87 && engine.Device()->run())
    {
      if ((*engine.getVEvents().begin())->getCROSS())
	return ;
      move(irr::core::vector3df(38, 179, 0));
      engine.Refresh();
    }
  if (rotate_right(irr::core::vector3df(-100 , 85, -710), 125) == -1)
    return;
  while (engine.Scene()->getActiveCamera()->getPosition().Z > - 704 && engine.Device()->run())
    {
      if ((*engine.getVEvents().begin())->getCROSS())
	return ;
      move(irr::core::vector3df(0, 179, 0));
      engine.Refresh();
    }
  if (move_rotateX(irr::core::vector3df(0, 258, 0), irr::core::vector3df(-1093 , 100, -1345), -1052, 325) == -1)
    return ;
  if (move_rotateZ(irr::core::vector3df(0, 179, 0), irr::core::vector3df(-1122 , 50, -4406), -3500, 500) == - 1)
    return ;
  while (engine.Scene()->getActiveCamera()->getPosition().Y < 650 && engine.Device()->run())
    {
      if ((*engine.getVEvents().begin())->getCROSS())
	return ;
      move(irr::core::vector3df(272, 180, 0));
      engine.Refresh();
    }
  if (rotate_right(irr::core::vector3df(-1600 , 650, -4366), 250) == -1)
    return ;
  while (engine.Scene()->getActiveCamera()->getPosition().Z > -4000 && engine.Device()->run())
    {
      if ((*engine.getVEvents().begin())->getCROSS())
	return ;
      move(irr::core::vector3df(346, 197, 0));
      engine.Refresh();
    }
  if (wait_n_seconds(1.0) == -1)
    return ;
  if (rotate_right(irr::core::vector3df(-1622 , 730, -5404), 250) == -1)
    return;
  while (engine.Scene()->getActiveCamera()->getPosition().Z > -4500 && engine.Device()->run())
    {
      if ((*engine.getVEvents().begin())->getCROSS())
	return ;
      move(irr::core::vector3df(346, 197, 0));
      engine.Refresh();
    }
  if (wait_n_seconds(1.0) == -1)
    return ;
  if (rotate_left(irr::core::vector3df(-551 , 641, -5100), 250) == -1)
    return;
  while (engine.Scene()->getActiveCamera()->getPosition().X < -1150 && engine.Device()->run())
    {
      if ((*engine.getVEvents().begin())->getCROSS())
	return ;
      move(irr::core::vector3df(12.5, 120, 0));
      engine.Refresh();
    }
  if (wait_n_seconds(1.0) == -1)
    return ;
  if (rotate_right(irr::core::vector3df(-702 , 646, -3954), 250) == -1)
    return;
  while (engine.Scene()->getActiveCamera()->getPosition().Z < -4488 && engine.Device()->run())
    {
      if ((*engine.getVEvents().begin())->getCROSS())
	return ;
      move(irr::core::vector3df(0, 27, 0));
      engine.Refresh();
    }
  if (rotate_right(irr::core::vector3df(-1148 , 625, -4001), 250) == -1)
    return;
  while (engine.Scene()->getActiveCamera()->getPosition().Z < -3000 && engine.Device()->run())
    {
      if ((*engine.getVEvents().begin())->getCROSS())
	return ;
      move(irr::core::vector3df(21, 2, 0));
      engine.Refresh();
    }
  while (engine.Device()->run()){
      if ((*engine.getVEvents().begin())->getCROSS())
	break ;
      engine.Refresh_Splash();
    }
}


SplashScreen::~SplashScreen()
{
  std::cout << "End of SplashScreen" << std::endl;
}