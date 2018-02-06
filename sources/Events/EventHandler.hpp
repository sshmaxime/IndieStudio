/*
** EventHandler.hpp for new in /home/sshsupreme/tek2/new
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Wed May 17 16:32:30 2017 sshSupreme
** Last update Tue May 23 16:32:32 2017 sshSupreme
*/

#ifndef _EVENTHANDLER_HPP_
# define _EVENTHANDLER_HPP_

#include <irrlicht.h>
#include <memory>
#include <vector>
#include "include.h"

using namespace irr;

namespace NsEvents
{
  enum class e_JoystickKey
    {
	    KEY_CROSS,
      KEY_SQUARE,
      KEY_CIRCLE,
      KEY_TRIANGLE,
      KEY_UP,
      KEY_DOWN,
    	KEY_RIGHT,
    	KEY_LEFT,
      KEY_R1,
      KEY_R2,
      KEY_L1,
      KEY_L2,
      KEY_NONE
    };
  class KeyInput
    {
      private:
        int     playerID_;
        bool    UP_;
        bool    DOWN_;
        bool    LEFT_;
        bool    RIGHT_;
        bool    SQUARE_;
        bool    CIRCLE_;
        bool    CROSS_;
        bool    TRIANGLE_;
        bool    JLEFT_;
        bool    JRIGHT_;
        f32     JLEFTVALUE_X_;
        f32     JLEFTVALUE_Y_;
        f32     JRIGHTVALUE_X_;
        f32     JRIGHTVALUE_Y_;
        bool    R1_;

      public:
        void setUP() {UP_ = true;}
        void setDOWN() {DOWN_ = true;}
        void setLEFT() {LEFT_ = true;}
        void setRIGHT() {RIGHT_ = true;}
        void setSQUARE() {SQUARE_ = true;}
        void setCIRCLE() {CIRCLE_ = true;}
        void setCROSS() {CROSS_ = true;}
        void setTRIANGLE() {TRIANGLE_ = true;}
        void setJLEFT() {JLEFT_ = true;}
        void setJRIGHT() {JRIGHT_ = true;}
        void setJLEFTVALUE_X(f32 a) {JLEFTVALUE_X_ = a;}
        void setJLEFTVALUE_Y(f32 a) {JLEFTVALUE_Y_ = a;}
        void setJRIGHTVALUE_X(f32 a) {JRIGHTVALUE_X_ = a;}
        void setJRIGHTVALUE_Y(f32 a) {JRIGHTVALUE_Y_ = a;}
        void setR1() {R1_ = true;}

      public:
        int  getPlayerID() {return playerID_;}
        bool getUP() {bool a = UP_;this->UP_ = false;return a;}
        bool getDOWN() {bool a = DOWN_;this->DOWN_ = false;return a;}
        bool getLEFT() {bool a = LEFT_;this->LEFT_ = false;return a;}
        bool getRIGHT() {bool a = RIGHT_;this->RIGHT_ = false;return a;}
        bool getSQUARE() {bool a = SQUARE_;this->SQUARE_ = false;return a;}
        bool getCIRCLE() {bool a = CIRCLE_;this->CIRCLE_ = false;return a;}
        bool getCROSS() {bool a = CROSS_;this->CROSS_ = false;return a;}
        bool getTRIANGLE() {bool a = TRIANGLE_;this->TRIANGLE_ = false;return a;}
        bool getJLEFT() {bool a = JLEFT_;this->JLEFT_ = false;return a;}
        bool getJRIGHT() {bool a = JRIGHT_;this->JRIGHT_ = false;return a;}
        f32  getJLEFTVALUE_X() {f32 a = JLEFTVALUE_X_;this->JLEFTVALUE_X_ = 0.f;return a;}
        f32  getJLEFTVALUE_Y() {f32 a = JLEFTVALUE_Y_;this->JLEFTVALUE_Y_ = 0.f;return a;}
        f32  getJRIGHTVALUE_X() {f32 a = JRIGHTVALUE_X_;this->JRIGHTVALUE_X_ = 0.f;return a;}
        f32  getJRIGHTVALUE_Y() {f32 a = JRIGHTVALUE_Y_;this->JRIGHTVALUE_Y_ = 0.f;return a;}
        bool getR1() {bool a = R1_;this->R1_ = false;return a;}

      public:
      	KeyInput(int);
        KeyInput& operator=(const KeyInput& obj) {return *this;}
      	~KeyInput();
    };
  class EventHandler : public IEventReceiver
    {
      public:
       std::vector<std::shared_ptr<irr::IEventReceiver>>   mEventReceivers;

      public:
        virtual bool     OnEvent(const irr::SEvent& event);
        void             AddEventReceiver(std::shared_ptr<irr::IEventReceiver> receiver_);
        bool             RemoveEventReceiver(std::shared_ptr<irr::IEventReceiver> receiver_);

      public:
        EventHandler();
        virtual ~EventHandler();
    };
  class	KeyMouse : public IEventReceiver
  {
   private:
    std::shared_ptr<KeyInput> KeyInput_;
   public:
    KeyMouse(std::shared_ptr<KeyInput>);
    ~KeyMouse();
    virtual bool    OnEvent(const SEvent& event);
  };

  class Joystick : public IEventReceiver
    {
      private:
        int                       id_;
        int                       playerID_;
        SEvent::SJoystickEvent    JoystickState_;
        SEvent::SJoystickEvent    JoystickState_old;
        f32                       DEAD_ZONE;
        f32                       L_HorizontalMove;
        f32                       L_VerticalMove;
        f32                       R_HorizontalMove;
        f32                       R_VerticalMove;
        bool                      L_JoystickMove;
        bool                      R_JoystickMove;
      	e_JoystickKey             key_;
    std::shared_ptr<KeyInput> KeyInput_;

      public:
        f32 			getL_HorizontalMove() const {return L_HorizontalMove;}
        f32 			getL_VerticalMove() const {return L_VerticalMove;}
        f32 			getR_HorizontalMove() const {return R_HorizontalMove;}
        f32 			getR_VerticalMove() const {return R_VerticalMove;}

      public:
        bool            isConnected() const;
    	virtual bool    OnEvent(const SEvent& event);
        e_JoystickKey   getKeyPressed();
        void            Update();

      private:
        void            UpdateKey();
        void            UpdateAxis();

      public:
      	Joystick(int, int, std::shared_ptr<KeyInput>);
      	~Joystick();
    };
}

#endif
