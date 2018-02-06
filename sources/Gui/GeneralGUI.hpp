/*
** GeneralGUI.hpp for new in /home/sshsupreme/tek2/new/sources/Events
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Wed May 17 17:27:31 2017 sshSupreme
// Last update Sat Jun 17 03:48:12 2017 benamar
*/

#include <IrrlichtDevice.h>
#include <memory>
#include <vector>
#include "include.h"
#include "EventHandler.hpp"
#include "../Events/EventHandler.hpp"
#include "../Core/GUI.hpp"
#include "../Core/RessourcesManager.hpp"

#ifndef _GENERALGUI_HPP
  #define _GENERALGUI_HPP

#define WIDTH 1920
#define HEIGHT 1080

namespace NsGUI
{
  class GraphicsEngine
    {
      public:
        static GraphicsEngine &Instance(void);
        void 									Initialization();
    void 									Refresh(CGUIGame *guiGame);
    void 									Refresh();
    void									Refresh_Splash();
      void									Refresh_Defeat();
        void                  JoystickHandle();

    void Refresh_Victory();

   public:
        irr::IrrlichtDevice                *Device(void) {return device_;}
        irr::video::IVideoDriver           *Driver(void) {return driver_;}
        irr::scene::ISceneManager          *Scene(void) {return scene_;}
        irr::gui::IGUIEnvironment          *Environment(void) {return env_;}
        NsEvents::EventHandler             &InputManager(void) {return inputManager_;}
        core::array<SJoystickInfo>         &getJoystickInfo() {return JoystickInfo_;}
        std::vector<std::shared_ptr<NsEvents::KeyInput>>   &getVEvents() {return VEvents_;}

      public:
        void setDevice(irr::IrrlichtDevice *device) {device_ = device;}
        void setDriver(irr::video::IVideoDriver *driver) {driver_ = driver;}
        void setScene(irr::scene::ISceneManager *scene) {scene_ = scene;}
        void setEnvironment(irr::gui::IGUIEnvironment *env) {env_ = env;}
   private:
        GraphicsEngine(void);
        ~GraphicsEngine(void);
        GraphicsEngine(const GraphicsEngine &Instance) {}
        GraphicsEngine &operator=(const GraphicsEngine &Instance) {}

      private:
        static GraphicsEngine                              Instance_;
        core::array<SJoystickInfo>                         JoystickInfo_;
        NsEvents::EventHandler                             inputManager_;
        irr::IrrlichtDevice                                *device_;
        irr::video::IVideoDriver                           *driver_;
        irr::scene::ISceneManager                          *scene_;
      irr::gui::IGUIEnvironment                          *env_;
        std::vector<std::shared_ptr<NsEvents::KeyInput>>   VEvents_;

  };
}

  #endif
