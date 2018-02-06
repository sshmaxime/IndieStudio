/*
** Archer.cpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/newEntity
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Sat Jun 03 00:03:40 2017 sshSupreme
** Last update Tue Jun 06 19:43:48 2017 sshSupreme
*/

#include "../Gui/GeneralGUI.hpp"
#include "../Projectil/Projectil.hpp"

void                    NsEntity::Archer::Move()
{
  if (this->isMoving == false) this->MoveAnim();
  if (this->isMoving == false && this->isShooting == true) this->MoveShotAnim();
  this->isMoving = true;
}

void                    NsEntity::Archer::Static()
{

  if (this->isShooting == false) this->StaticAnim();
  this->isMoving = false;
}

void                    NsEntity::Archer::Spell_1()
{

}

void                    NsEntity::Archer::Spell_2()
{

}

void                    NsEntity::Archer::Spell_3()
{

}

void                    NsEntity::Archer::AutoRangeShot(std::vector<std::shared_ptr<NsProjectil::Projectil>>& v)
{
  //NsManager::NsAudioManager_.getSound("fireball")->getSound().play();
  PushProjectil(std::make_shared<NsProjectil::Fireball>(NsManager::NsTexturesManager_.getTexture("fire"), this->getNode()->getRotation()), this->getNode()->getPosition(), v);
  if (this->isShooting == false) this->ShotAnim();
  if (this->isShooting == false && this->isMoving == true) this->MoveShotAnim();
  this->isShooting = true;
}

void                    NsEntity::Archer::StopShot()
{

  if (this->isShooting == true && this->isMoving == true) this->MoveAnim();
  if (this->isShooting == true && this->isMoving == false) this->StaticAnim();
  this->isShooting = false;
}

void                    NsEntity::Archer::Death()
{
  this->DeathAnim();
}

void                    NsEntity::Archer::MoveAnim() {this->getNode()->setFrameLoop(40, 64);}
void                    NsEntity::Archer::ShotAnim() {this->getNode()->setFrameLoop(0, 11);}
void                    NsEntity::Archer::StaticAnim() {this->getNode()->setFrameLoop(38, 38);}
void                    NsEntity::Archer::MoveShotAnim() {this->getNode()->setFrameLoop(14, 38);}
void                    NsEntity::Archer::DeathAnim() {this->getNode()->setFrameLoop(66, 78);}
void                    NsEntity::Archer::HappyAnim() {this->getNode()->setFrameLoop(80, 104);}
void                    NsEntity::Archer::AngryAnim() {this->getNode()->setFrameLoop(106, 130);}

NsEntity::Archer::Archer(Model3D& model) : PlayableEntity(model)
{
  this->isMoving = false;
  this->isShooting = false;
  this->Health_ = 80;
  this->MaxHealth_ = this->Health_;
  this->Damages_ = 0;
  this->Ranger_ = true;
  this->speedAttack_ = 30;
}

NsEntity::Archer::~Archer()
{

}

void                							NsEntity::Archer::PushProjectil(std::shared_ptr<NsProjectil::Fireball> entity, const irr::core::vector3df& pos, std::vector<std::shared_ptr<NsProjectil::Projectil>>& vProjectil_)
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
