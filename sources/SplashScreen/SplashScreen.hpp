/*
** SplashScreen.hpp for cpp_indie_studio in /home/chenne_a/delivery/cpp_indie_studio/SplashScreen.hpp
**
** Made by Prenom Nom
** Login   <arthur.chennetier@epitech.eu>
**
** Started on  mer. juin 07 16:51:35 2017 Prenom Nom
** Last update mer. juin 07 16:51:35 2017 Prenom Nom
*/

#ifndef CPP_INDIE_STUDIO_SPLASHSCREEN_HPP
#define CPP_INDIE_STUDIO_SPLASHSCREEN_HPP

#include <chrono>
#include <iostream>
#include "../Gui/GeneralGUI.hpp"
#include "../Entity/PlayableEntity.hpp"
#include "../Core/RessourcesManager.hpp"

class			SplashScreen {

 public:
  SplashScreen();
  ~SplashScreen();
  void 		move(irr::core::vector3df rot);
  int		rotate_right(irr::core::vector3df rot, int speed);
  int		rotate_left(irr::core::vector3df rot, int speed);
  int		move_rotateX(irr::core::vector3df mov, irr::core::vector3df rot, int stop, int frame);
  int		move_rotateZ(irr::core::vector3df mov, irr::core::vector3df rot, int stop, int frame);
  int 		wait_n_seconds(double seconds);



  void 		Initialisation();
  void		LaunchSplashScreen();

 private:
};

#endif //CPP_INDIE_STUDIO_SPLASHSCREEN_HPP
