/*
** Joystick.cpp for new in /home/sshsupreme/tek2/new/sources/Events
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Wed May 17 17:03:03 2017 sshSupreme
** Last update Wed May 24 19:15:19 2017 sshSupreme
*/

#include <memory>
#include <iostream>
#include "EventHandler.hpp"

void                                NsEvents::Joystick::UpdateKey()
{
  int                               ButtonPressed;

  ButtonPressed = this->JoystickState_.ButtonStates;
  if (ButtonPressed != 0)
    {
      if (ButtonPressed == 32768 && this->JoystickState_old.ButtonStates != 32768)
	      {this->key_ = NsEvents::e_JoystickKey::KEY_SQUARE; this->KeyInput_->setSQUARE();}
      else if (ButtonPressed == 16384 && this->JoystickState_old.ButtonStates != 16384)
        {key_ = NsEvents::e_JoystickKey::KEY_CROSS; this->KeyInput_->setCROSS();}
      else if (ButtonPressed == 8192 && this->JoystickState_old.ButtonStates != 8192)
        {key_ = NsEvents::e_JoystickKey::KEY_CIRCLE; this->KeyInput_->setCIRCLE();}
      else if (ButtonPressed == 4096 && this->JoystickState_old.ButtonStates != 4096)
        {key_ = NsEvents::e_JoystickKey::KEY_TRIANGLE; this->KeyInput_->setTRIANGLE();}
      else if (ButtonPressed == 2048)
        {key_ = NsEvents::e_JoystickKey::KEY_R1; this->KeyInput_->setR1();}
      else if (ButtonPressed == 1024 && this->JoystickState_old.ButtonStates != 1024)
        key_ = NsEvents::e_JoystickKey::KEY_L1;
      else if (ButtonPressed == 512 && this->JoystickState_old.ButtonStates != 512)
        key_ = NsEvents::e_JoystickKey::KEY_R2;
      else if (ButtonPressed == 256 && this->JoystickState_old.ButtonStates != 256)
        key_ = NsEvents::e_JoystickKey::KEY_L2;
      else if (ButtonPressed == 128 && this->JoystickState_old.ButtonStates != 128)
 	{key_ = NsEvents::e_JoystickKey::KEY_LEFT; this->KeyInput_->setLEFT();}
      else if (ButtonPressed == 64 && this->JoystickState_old.ButtonStates != 64)
        {key_ = NsEvents::e_JoystickKey::KEY_DOWN; this->KeyInput_->setDOWN();}
      else if (ButtonPressed == 32 && this->JoystickState_old.ButtonStates != 32)
        {key_ = NsEvents::e_JoystickKey::KEY_RIGHT; this->KeyInput_->setRIGHT();}
      else if (ButtonPressed == 16 && this->JoystickState_old.ButtonStates != 16)
        {key_ = NsEvents::e_JoystickKey::KEY_UP; this->KeyInput_->setUP();}
    }
}

void                                NsEvents::Joystick::UpdateAxis()
{
  this->R_HorizontalMove = (f32)this->JoystickState_.Axis[SEvent::SJoystickEvent::AXIS_R];// / -32767.f;
  if(fabs(this->R_HorizontalMove) < DEAD_ZONE)
    this->R_HorizontalMove = 0.f;
  this->R_VerticalMove = (f32)this->JoystickState_.Axis[SEvent::SJoystickEvent::AXIS_Z];// / 32767.f;
  if(fabs(this->R_VerticalMove) < DEAD_ZONE)
    this->R_VerticalMove = 0.f;

  this->L_HorizontalMove = (f32)this->JoystickState_.Axis[SEvent::SJoystickEvent::AXIS_Y];// / -32767.f;
  if(fabs(this->L_HorizontalMove) < DEAD_ZONE)
    this->L_HorizontalMove = 0.f;
  this->L_VerticalMove = (f32)this->JoystickState_.Axis[SEvent::SJoystickEvent::AXIS_X];// / 32767.f;
  if(fabs(this->L_VerticalMove) < DEAD_ZONE)
    this->L_VerticalMove = 0.f;

  if (fabs(this->L_VerticalMove) > DEAD_ZONE || fabs(this->L_HorizontalMove) > DEAD_ZONE)
    {this->L_JoystickMove = true; this->KeyInput_->setJLEFT(); this->KeyInput_->setJLEFTVALUE_X(this->L_HorizontalMove);this->KeyInput_->setJLEFTVALUE_Y(this->L_VerticalMove);}
  else
    this->L_JoystickMove = false;

 /* if (fabs(this->R_VerticalMove) > DEAD_ZONE || fabs(this->R_HorizontalMove) > DEAD_ZONE)
    {this->R_JoystickMove = true; this->KeyInput_->setJRIGHT(); this->KeyInput_->setJRIGHTVALUE_X(this->R_HorizontalMove);this->KeyInput_->setJRIGHTVALUE_Y(this->R_VerticalMove);}
  else
    this->R_JoystickMove = false;*/
}

void                                NsEvents::Joystick::Update()
{
  this->UpdateKey();
  this->UpdateAxis();
}

bool                                NsEvents::Joystick::OnEvent(const SEvent& event)
{
  if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick == this->id_)
    {
      JoystickState_old = JoystickState_;
      JoystickState_ = event.JoystickEvent;
      this->Update();
    }
  return false;
}

NsEvents::e_JoystickKey                         NsEvents::Joystick::getKeyPressed()
{
  NsEvents::e_JoystickKey                       returnedKey = this->key_;

  this->key_ = NsEvents::e_JoystickKey::KEY_NONE;
  return (returnedKey);
}

NsEvents::Joystick::Joystick(int id, int playerID, std::shared_ptr<KeyInput> KeyInput) : DEAD_ZONE(0.05f), KeyInput_(KeyInput)
{
  this->key_ = NsEvents::e_JoystickKey::KEY_NONE;
  this->playerID_ = playerID;
  this->id_ = id;
  this->L_JoystickMove = false;
  this->R_JoystickMove = false;
  this->L_HorizontalMove = 0.f;
  this->L_VerticalMove = 0.f;
  this->R_HorizontalMove = 0.f;
  this->R_VerticalMove = 0.f;
}

NsEvents::Joystick::~Joystick()
{

}
