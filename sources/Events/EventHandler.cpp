/*
** EventHandler.cpp for new in /home/sshsupreme/tek2/new
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Wed May 17 16:32:32 2017 sshSupreme
** Last update Mon May 22 23:27:50 2017 sshSupreme
*/

#include "EventHandler.hpp"

void                     NsEvents::EventHandler::AddEventReceiver(std::shared_ptr<irr::IEventReceiver> receiver)
{
  mEventReceivers.push_back(receiver);
}

bool                     NsEvents::EventHandler::OnEvent(const irr::SEvent& event)
{
  for (auto i = mEventReceivers.begin(); i < mEventReceivers.end(); ++i)
    {
      if ((*i)->OnEvent(event))
	return true;
    }
  return false;
}

bool                     NsEvents::EventHandler::RemoveEventReceiver(std::shared_ptr<irr::IEventReceiver> receiver)
{
  for (unsigned int i = 0; i < mEventReceivers.size(); ++i)
    {
      if (mEventReceivers[i] == receiver)
	{
	  mEventReceivers.erase(mEventReceivers.begin() + i);
	  return true;
	}
    }
  return false;
}

NsEvents::EventHandler::EventHandler()
{

}

NsEvents::EventHandler::~EventHandler()
{

}

NsEvents::KeyMouse::KeyMouse(std::shared_ptr<NsEvents::KeyInput> KeyInput) : KeyInput_(KeyInput)
{}

NsEvents::KeyMouse::~KeyMouse()
{

}

bool NsEvents::KeyMouse::OnEvent(const SEvent &event)
{
  if (event.EventType == EET_KEY_INPUT_EVENT)
    {
      switch (event.KeyInput.Key)
	{
	  case KEY_KEY_H:
	    {
	      this->KeyInput_->setCROSS();
	      break;
	    }
	  case KEY_KEY_J:
	    {
	      this->KeyInput_->setSQUARE();
	      break;
	    }
	  case KEY_KEY_K:
	    {
	      this->KeyInput_->setCIRCLE();
	      break;
	    }
	  case KEY_KEY_L:
	    {
	      this->KeyInput_->setTRIANGLE();
	      break;
	    }
	  case KEY_KEY_Z:
	    {
	      this->KeyInput_->setJLEFT();
	      break;
	    }
	  default:
	    break;
	}
    }
  if (event.EventType == EET_MOUSE_INPUT_EVENT)
    this->KeyInput_->setJRIGHT();
  return false;
}
