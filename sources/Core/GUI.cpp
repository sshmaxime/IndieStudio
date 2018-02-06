//
// Created by chauvin on 27/05/17.
//

#include "GUI.hpp"
#include "../Gui/GeneralGUI.hpp"

using namespace irr;
using namespace core;
using namespace video;

CGUIGame::CGUIGame(video::IVideoDriver* videoDriver,
		   std::vector<int> state,
		   std::vector<std::shared_ptr<NsEntity::PlayableEntity>> vPlayer,
		   int maxHealthValue, int maxManaValue){

  if (videoDriver != nullptr)
    {
      this->maxHealthBarValue = maxHealthValue;
      this->maxManaBarValue = maxManaValue;
      driver = videoDriver;
      _vPlayer = vPlayer;
      _state = state;
    }
}

void CGUIGame::renderGUIGame(){

  const core::dimension2d<u32> &screenSize = driver->getScreenSize();
  int 	i = 0;
  int   pos = 0;

  NsGUI::GraphicsEngine &engine = NsGUI::GraphicsEngine::Instance();
  std::vector<std::shared_ptr<NsEntity::PlayableEntity>>::iterator j;
  std::vector<int>::iterator	k = _state.begin();

  for (j = _vPlayer.begin(); j < _vPlayer.end(); j++)
    {
      std::string gold;
      std::string key;
      std::string type;
      double 	current_health = 1.5 * (((float)(*j)->getHealth() /(float)(*j)->getMaxHealth()) * 100);

      gold = std::to_string((*j)->getGold());
      key = std::to_string((*j)->getKeys());
      pos = 450 + i * 250;
      if ((*k) == 0)
	type = "ATH_warrior";
      else if ((*k) == 1)
	type = "ATH_archer";
      else if ((*k) == 2)
	type = "ATH_wizard";
      else
	type = "ATH_guardian";

      engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture(type.c_str()).getTexture(),
				   position2d<s32>(pos, 910),
				   rect<s32>(0, 0, 200, 141), 0, SColor(255, 255, 255, 255), true);
      NsManager::NsFontsManager_.getFont("ath").getFont()
       ->draw(irr::core::stringw(key.c_str()), core::rect<s32>(pos + 50, 915, pos + 90, 930),
	      video::SColor(255, 255, 255, 255));
      NsManager::NsFontsManager_.getFont("ath").getFont()
       ->draw(irr::core::stringw(gold.c_str()), core::rect<s32>(pos + 130, 915, pos + 170, 930),
	      video::SColor(255, 255, 255, 255));

      engine.Driver()->draw2DRectangle(video::SColor(200, 232, 1, 1),
				       core::rect<s32>(pos + 25, 960, pos + 175, 965));
      engine.Driver()->draw2DRectangle(video::SColor(200, 99, 254, 52),
				       core::rect<s32>(pos + 25, 960,
						       pos + 25 + static_cast<int>(current_health), 965));
      i++;
      k++;
    }
}

void CGUIGame::setHealthBarValue(int healthValue){
  deltaHealthBar = healthValue;
}

void CGUIGame::setManaBarValue(int manaValue){
  deltaManaBar = manaValue;
}