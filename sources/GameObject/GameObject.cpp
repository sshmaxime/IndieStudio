//
// Created by chauvin on 31/05/17.
//

#include "GameObject.hpp"
#include "../Entity/PlayableEntity.hpp"
#include "../Core/RessourcesManager.hpp"

//! add a key to the player inventory and sets invisible the model
void NsGameObject::Key::Take(std::shared_ptr<NsEntity::PlayableEntity> & entity)
{
  if (this->getNode()->isVisible())
    {
      entity->setKeys(entity->getKeys() + 1);
      this->getNode()->setVisible(false);
      // NsManager::NsAudioManager_.getSound("takekey")->getSound().play();
      std::cout << "INVISIBLE KEY" << std::endl;
    }
}

//! add a gold to the player inventory and sets invisible the model
void NsGameObject::Gold::Take(std::shared_ptr<NsEntity::PlayableEntity> & entity)
{
  if (this->getNode()->isVisible())
    {
      entity->setGold(entity->getGold() + 1);
      this->getNode()->setVisible(false);
      std::cout << "INVISIBLE COIN" << std::endl;
      NsManager::NsAudioManager_.getSound("takecoin")->getSound().play();
    }
}

void NsGameObject::Door::Take(std::shared_ptr<NsEntity::PlayableEntity> &entity)
{
  if (entity->getKeys() > 0 && open == 0 && this->getNode()->isVisible())
    {
      entity->setKeys(entity->getKeys() - 1);
      open = 2;
      if (type == 1)
	this->getNode()->setFrameLoop(0, 38);
      else
	this->getNode()->setFrameLoop(0, 24);
      //this->getNode()->setLoopMode(false);
      this->getNode()->setAnimationSpeed(10);
      //this->getNode()->setVisible(false);
      std::cout << "INVISIBLE DOOR" << std::endl;
    }
}

int NsGameObject::Door::isOpen() const
{
  return open;
}

void NsGameObject::Door::setOpen(int open)
{
  Door::open = open;
}

void NsGameObject::Door::checkFrame()
{
  if (this->getNode()->getFrameNr() >=  35 && this->type == 1)
    {
      this->open = 1;
      this->getNode()->setVisible(false);
    }
  else if (this->getNode()->getFrameNr() >=  20 && (this->type == 2 || this->type == 3))
      {
	this->open = 1;
	this->getNode()->setVisible(false);
      }
}

std::vector<scene::ISceneNodeAnimator *> &NsGameObject::Door::getPAnimator()
{
  return pAnimator;
}

void NsGameObject::Door::setPAnimator(const std::vector<scene::ISceneNodeAnimator *> &pAnimator)
{
  Door::pAnimator = pAnimator;
}

int NsGameObject::Door::getType() const
{
  return type;
}

void NsGameObject::Door::setType(int type)
{
  Door::type = type;
}
