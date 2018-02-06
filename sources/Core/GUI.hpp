//
// Created by chauvin on 27/05/17.
//

#ifndef CPP_INDIE_STUDIO_GUI_HPP
#define CPP_INDIE_STUDIO_GUI_HPP

#include "../../irrlicht/include/irrlicht.h"
#include "../Entity/PlayableEntity.hpp"

using namespace irr;

class CGUIGame {

 private:
  video::IVideoDriver* driver;
  int x1Bar, y1Bar, x2Bar, y2Bar;

  int   maxHealthBarValue; //bar size
  double deltaHealthBar;      //interpolation
  double healthBarValue;  //current bar value
  std::vector<std::shared_ptr<NsEntity::PlayableEntity>> _vPlayer;
  std::vector<int> 	_state;

  int maxManaBarValue;
  double deltaManaBar;
  double manaBarValue;

  video::ITexture* GUITextures[10];

 public:

  CGUIGame(video::IVideoDriver* videoDriver, std::vector<int> _state, std::vector<std::shared_ptr<NsEntity::PlayableEntity>> vPlayer, int maxHealthValue, int maxManaValue); //constructor
  ~CGUIGame(); //destructor :O
  void renderGUIGame(); //render the GUI, must be called AFTER the 3D draw, or it  wont show
  void setHealthBarValue(int healthValue); //change bar values
  void setManaBarValue(int manaValue);

};



#endif //CPP_INDIE_STUDIO_GUI_HPP
