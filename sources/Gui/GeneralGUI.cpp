/*
** GeneralGUI.cpp for new in /home/sshsupreme/tek2/new/sources/Gui
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Wed May 17 17:31:13 2017 sshSupreme
// Last update Sat Jun 17 04:09:30 2017 benamar
*/

#include <iostream>
#include "GeneralGUI.hpp"
#include "../Entity/Entity.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

NsGUI::GraphicsEngine NsGUI::GraphicsEngine::Instance_ = NsGUI::GraphicsEngine();

void NsGUI::GraphicsEngine::JoystickHandle() // check if there is joystick and associate each event class present to his own key setter/getter class
{
  /*this->VEvents_.push_back(std::make_shared<NsEvents::KeyInput>(0)); // add a key setter/getter with his id
  this->inputManager_.AddEventReceiver(std::make_shared<NsEvents::KeyMouse>(VEvents_[0])); // add an event receiver and associate it with the id of the player, the joystick id and the setter/getter class*/
  int Player = 0;
  if (this->Device()->activateJoysticks(JoystickInfo_))
    {
      std::cout << "Joystick support is enabled and " << JoystickInfo_.size() << " joystick(s) are present." << std::endl;
      for(u32 joystick = 0; joystick < JoystickInfo_.size(); ++joystick)
        {
          if (JoystickInfo_[joystick].Axes == 27 && JoystickInfo_[joystick].Buttons == 19)
            {
              this->VEvents_.push_back(std::make_shared<NsEvents::KeyInput>(Player)); // add a key setter/getter with his id
              this->inputManager_.AddEventReceiver(std::make_shared<NsEvents::Joystick>(joystick, Player, VEvents_[Player])); // add an event receiver and associate it with the id of the player, the joystick id and the setter/getter class
              std::cout << "Joystick ADDED" << '\n';
              Player = Player + 1;
            }
      	  else if (JoystickInfo_[joystick].Axes == 8 && JoystickInfo_[joystick].Buttons == 14)
      	    {
      	      this->VEvents_.push_back(std::make_shared<NsEvents::KeyInput>(Player)); // add a key setter/getter with his id
      	      this->inputManager_.AddEventReceiver(std::make_shared<NsEvents::Joystick>(joystick, Player, VEvents_[Player])); // add an event receiver and associate it with the id of the player, the joystick id and the setter/getter class
      	      std::cout << "Joystick ADDED" << '\n';
      	      Player = Player + 1;
      	    }
        }
    }
    else
      std::cout << "Joystick support is not enabled." << std::endl;
  if (Player == 0)
    {
      std::cerr << "No Joystick detected\n";
      std::terminate();
    }
}

void NsGUI::GraphicsEngine::Initialization()
{
  ITexture* loader;
  this->setDevice(createDevice(video::EDT_OPENGL, dimension2d<u32>(WIDTH, HEIGHT), 64, false, false, false, &this->inputManager_));
  this->JoystickHandle();
  this->setDriver(this->Device()->getVideoDriver());
  this->setScene(this->Device()->getSceneManager());
  this->setEnvironment(this->Device()->getGUIEnvironment());
  loader = driver_->getTexture("./ressources/Menu/loading.png");
  driver_->beginScene(true, true, SColor(0, 0, 0, 0));
  driver_->draw2DImage(loader, position2d<s32>(0, 0));
  driver_->endScene();
}

void NsGUI::GraphicsEngine::Refresh(CGUIGame *gameGUI)
{
  static int lastFPS = -1;

  driver_->beginScene(true, true, SColor(255,255,255,255));
  scene_->drawAll();
  env_->drawAll();
  gameGUI->renderGUIGame();
  driver_->endScene();
  int fps = this->driver_->getFPS();

  if (lastFPS != fps)
    {
      core::stringw tmp(L"Gonetlet - Irrlicht Engine [");
      tmp += this->driver_->getName();
      tmp += L"] fps: ";
      tmp += fps;

      this->device_->setWindowCaption(tmp.c_str());
      lastFPS = fps;
    }
}

void	NsGUI::GraphicsEngine::Refresh_Splash()
{
  driver_->beginScene(true, true, SColor(255,255,255,255));
  scene_->drawAll();
  env_->drawAll();
  Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("titre").getTexture(),
			position2d<s32>(550, 180),
			rect<s32>(0, 0, 728, 236), 0, SColor(255, 255, 255, 255), true);
  Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("start").getTexture(),
			position2d<s32>(750, 500),
			rect<s32>(0, 0, 304, 90), 0, SColor(255, 255, 255, 255), true);
  driver_->endScene();
}

void	NsGUI::GraphicsEngine::Refresh_Defeat()
{
  driver_->beginScene(true, true, SColor(255,255,255,255));
  scene_->drawAll();
  env_->drawAll();
  Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("defeat").getTexture(),
			position2d<s32>(250, 70),
			rect<s32>(0, 0, 1365, 768), 0, SColor(255, 255, 255, 255), true);
  // Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("press").getTexture(),
  // 			position2d<s32>(645, 830),
  // 			rect<s32>(0, 0, 300, 300), 0, SColor(255, 255, 255, 255), true);
  driver_->endScene();
  
}

void	NsGUI::GraphicsEngine::Refresh_Victory()
{
  driver_->beginScene(true, true, SColor(255,255,255,255));
  scene_->drawAll();
  env_->drawAll();
  Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("youwin").getTexture(),
			position2d<s32>(400, 130),
			rect<s32>(0, 0, 1024, 633), 0, SColor(255, 255, 255, 255), true);
  // Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("press").getTexture(),
  // 			position2d<s32>(645, 830),
  // 			rect<s32>(0, 0, 300, 300), 0, SColor(255, 255, 255, 255), true);
  driver_->endScene();

}

void NsGUI::GraphicsEngine::Refresh()
{
  driver_->beginScene(true, true, SColor(255,255,255,255));
  scene_->drawAll();
  env_->drawAll();
  driver_->endScene();
}

NsGUI::GraphicsEngine::GraphicsEngine(void)
{
  std::cout << "Singleton GraphicsEngine created" << std::endl;
}

NsGUI::GraphicsEngine::~GraphicsEngine(void)
{
  std::cout << "Singleton GraphicsEngine deleted" << std::endl;
  device_->drop();
}

NsGUI::GraphicsEngine &NsGUI::GraphicsEngine::Instance(void) {return Instance_;}
