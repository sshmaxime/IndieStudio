/*
** Wizard.cpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/newEntity
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Sat Jun 03 00:03:40 2017 sshSupreme
** Last update Sat Jun 17 20:12:50 2017 Florent Sebag
*/

#include "PlayableEntity.hpp"
#include "../Core/RessourcesManager.hpp"
#include "../Gui/GeneralGUI.hpp"
#include "../Projectil/Projectil.hpp"

void                							NsEntity::Wizard::PushProjectil(std::shared_ptr<NsProjectil::Fireball> entity, const irr::core::vector3df& pos, std::vector<std::shared_ptr<NsProjectil::Projectil>>& vProjectil_)
{
  NsGUI::GraphicsEngine &engine = NsGUI::GraphicsEngine::Instance();

	irr::scene::IParticleSystemSceneNode *node = engine.Scene()->addParticleSystemSceneNode(false);
	scene::IParticleEmitter* em = node->createBoxEmitter(
	core::aabbox3d<f32>(-7,0,-7,7,1,7), // emitter size
	core::vector3df(0.0f,0.0f,0.0f),   // initial direction
	50, 50,                             // emit rate
	video::SColor(0,255,255,255),       // darkest color
	video::SColor(0,255,255,255),       // brightest color
	10,10,0,                         // min and max age, angle
  core::dimension2df(40.f,40.f),        // max size
  core::dimension2df(40.f,40.f));        // max size

	node->setEmitter(em); // this grabs the emitter
	em->drop(); // so we can drop it here without deleting it

  node->setPosition(pos);
	node->setScale(core::vector3df(1,1,1));
	node->setMaterialFlag(video::EMF_LIGHTING, false);
	node->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
	node->setMaterialTexture(0, entity->getTexture().getTexture());
	node->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
	entity->setNode(node);
	entity->Initialization();
	vProjectil_.push_back(entity);
}

void                    NsEntity::Wizard::Move()
{
  if (this->isMoving == false) this->MoveAnim();
  if (this->isMoving == false && this->isShooting == true) this->MoveShotAnim();
  this->isMoving = true;
}

void                    NsEntity::Wizard::Static()
{
  if (this->isShooting == false) this->StaticAnim();
  this->isMoving = false;
}

void                    NsEntity::Wizard::Spell_1()
{

}

void                    NsEntity::Wizard::Spell_2()
{

}

void                    NsEntity::Wizard::Spell_3()
{

}

void                    NsEntity::Wizard::AutoRangeShot(std::vector<std::shared_ptr<NsProjectil::Projectil>>& v)
{
  NsManager::NsAudioManager_.getSound("fireball")->getSound().play();
  PushProjectil(std::make_shared<NsProjectil::Fireball>(NsManager::NsTexturesManager_.getTexture("fire"), this->getNode()->getRotation()), this->getNode()->getPosition(), v);
  if (this->isShooting == false) this->ShotAnim();
  if (this->isShooting == false && this->isMoving == true) this->MoveShotAnim();
  this->isShooting = true;

}

void                    NsEntity::Wizard::StopShot()
{
  if (this->isShooting == true && this->isMoving == true) this->MoveAnim();
  if (this->isShooting == true && this->isMoving == false) this->StaticAnim();
  this->isShooting = false;
}

void                    NsEntity::Wizard::Death()
{
  this->DeathAnim();
}

void                    NsEntity::Wizard::MoveAnim() {this->getNode()->setFrameLoop(2, 26);}
void                    NsEntity::Wizard::ShotAnim() {this->getNode()->setFrameLoop(28, 40);}
void                    NsEntity::Wizard::StaticAnim() {this->getNode()->setFrameLoop(0, 0);}
void                    NsEntity::Wizard::MoveShotAnim() {this->getNode()->setFrameLoop(28, 40);}
void                    NsEntity::Wizard::DeathAnim() {this->getNode()->setFrameLoop(42, 60);}
void                    NsEntity::Wizard::HappyAnim() {this->getNode()->setFrameLoop(62, 80);}
void                    NsEntity::Wizard::AngryAnim() {this->getNode()->setFrameLoop(82, 100);}

NsEntity::Wizard::Wizard(Model3D& model) : PlayableEntity(model)
{
  this->isMoving = false;
  this->isShooting = false;
  this->Health_ = 80;
  this->MaxHealth_ = this->Health_;
  this->Damages_ = 0;
  this->Ranger_ = true;
  this->speedAttack_ = 30;
}

NsEntity::Wizard::~Wizard()
{

}
