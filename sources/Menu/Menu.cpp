//
// Menu.cpp for indie_studio in /Users/antoinedeforges/Desktop/ubuntu-shared/cpp_indie_studio/src/
//
// Made by Antoine Deforges
// Login   <deforg_a@epitech.eu>
//
// Started on  Tue May 16 13:58:01 2017 Antoine Deforges
// Last update Fri Jun 16 04:50:44 2017 Antoine Deforges
//

#include "Menu.hpp"

using namespace irr;
using namespace core;
using namespace video;

Menu::Menu(void) {}

Menu::~Menu(void) {}

void Menu::Initialization(void) {
  _home = 0;
  _settings = 0;
  _audio = 4;
  _page = PAGE::HOME;
  _state = STATE::RUN;
  _player = 0;
}

std::vector<int> Menu::launcher(void) {
  NsGUI::GraphicsEngine &engine = NsGUI::GraphicsEngine::Instance();
  _home = 0;
  _settings = 0;
  _page = PAGE::HOME;
  _state = STATE::RUN;
  _player = 0;
  _cursor_player.clear();
  _nb_player = engine.getVEvents().size();
  for (int i = 0 ; i < _nb_player ; ++i) _cursor_player.push_back(0);
  while (engine.Device()->run()) {
    if (_state != STATE::RUN) break;
    engine.Driver()->beginScene(true, true, SColor(0, 0, 0, 0));
    page_manager();
    engine.Driver()->endScene();
  }
  if (_state == STATE::EXIT) _cursor_player.at(0) = -1;
  return _cursor_player;
}

void Menu::page_manager(void) {
  if (_page == PAGE::HOME) home();
  else if (_page == PAGE::PLAY) player_selection();
  else if (_page == PAGE::CREDITS) credits();
  else if (_page == PAGE::SETTINGS) settings();
  else if (_page == PAGE::CONTROLS) controls();
}

void Menu::home(void) {
  NsGUI::GraphicsEngine &engine = NsGUI::GraphicsEngine::Instance();

  switch (_home) {
    case 0:
      engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("home_play").getTexture(), position2d<s32>(0, 0));
      if ((engine.getVEvents().at(0))->getDOWN()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _home += 1;
      } else if ((engine.getVEvents().at(0))->getCROSS()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _page = PAGE::PLAY;
      }
      break;
    case 1:
      engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("home_settings").getTexture(), position2d<s32>(0, 0));
      if ((engine.getVEvents().at(0))->getDOWN()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _home += 1;
      } else if ((engine.getVEvents().at(0))->getUP()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _home -= 1;
      } else if ((engine.getVEvents().at(0))->getCROSS()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _page = PAGE::SETTINGS;
      }
      break;
    case 2:
      engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("home_credits").getTexture(), position2d<s32>(0, 0));
      if ((engine.getVEvents().at(0))->getDOWN()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _home += 1;
      } else if ((engine.getVEvents().at(0))->getUP()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _home -= 1;
      } else if ((engine.getVEvents().at(0))->getCROSS()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _page = PAGE::CREDITS;
      }
      break;
    case 3:
      engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("home_exit").getTexture(), position2d<s32>(0, 0));
      if ((engine.getVEvents().at(0))->getUP()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _home -= 1;
      } else if ((engine.getVEvents().at(0))->getCROSS()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _state = STATE::EXIT;
      }
      break;
    default:
      break;
  }
}

void Menu::credits(void) {
  NsGUI::GraphicsEngine &engine = NsGUI::GraphicsEngine::Instance();
  engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("credits").getTexture(), position2d<s32>(0, 0));
  if ((engine.getVEvents().at(0))->getCROSS()) _page = PAGE::HOME;
}

bool Menu::check_selection(void) {
  bool validated = false;
  switch (_player) {
    case 0:
      validated = true;
      break;
    case 1:
      if (_cursor_player[_player] != _cursor_player[0]) {
        validated = true;
      }
      break;
    case 2:
      if (_cursor_player[_player] != _cursor_player[0] &&
        _cursor_player[_player] != _cursor_player[1]) {
        validated = true;
      }
      break;
    case 3:
      if (_cursor_player[_player] != _cursor_player[0] &&
        _cursor_player[_player] != _cursor_player[1] &&
        _cursor_player[_player] != _cursor_player[2]) {
        validated = true;
      }
      break;
    default:
      break;
  }
  return validated;
}

void Menu::audio(void) {
  NsGUI::GraphicsEngine &engine = NsGUI::GraphicsEngine::Instance();
  switch (_audio) {
    case 0:
      engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("audio0").getTexture(), position2d<s32>(0, 0));
      NsManager::NsAudioManager_.getMusic("menu")->setVolume(_audio);
      if (engine.getVEvents().at(0)->getRIGHT()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _audio += 1;
      }
      break;
    case 1:
      engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("audio1").getTexture(), position2d<s32>(0, 0));
      NsManager::NsAudioManager_.getMusic("menu")->setVolume(_audio);
      if (engine.getVEvents().at(0)->getRIGHT()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _audio += 1;
      } else if (engine.getVEvents().at(0)->getLEFT()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _audio -= 1;
      }
      break;
    case 2:
      engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("audio2").getTexture(), position2d<s32>(0, 0));
      NsManager::NsAudioManager_.getMusic("menu")->setVolume(_audio);
      if (engine.getVEvents().at(0)->getRIGHT()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _audio += 1;
      } else if (engine.getVEvents().at(0)->getLEFT()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _audio -= 1;
      }
      break;
    case 3:
      engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("audio3").getTexture(), position2d<s32>(0, 0));
      NsManager::NsAudioManager_.getMusic("menu")->setVolume(_audio);
      if (engine.getVEvents().at(0)->getRIGHT()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _audio += 1;
      } else if (engine.getVEvents().at(0)->getLEFT()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _audio -= 1;
      }
      break;
    case 4:
      engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("audio4").getTexture(), position2d<s32>(0, 0));
      NsManager::NsAudioManager_.getMusic("menu")->setVolume(_audio);
      if (engine.getVEvents().at(0)->getLEFT()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _audio -= 1;
      }
      break;
    default:
      break;
  }
}

void Menu::settings(void) {
  NsGUI::GraphicsEngine &engine = NsGUI::GraphicsEngine::Instance();
  switch (_settings) {
    case 0:
      audio();
      if (engine.getVEvents().at(0)->getDOWN()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _settings += 1;
      }
      break;
    case 1:
      engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("settings_controls").getTexture(), position2d<s32>(0, 0));
      if (engine.getVEvents().at(0)->getDOWN()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _settings += 1;
      } else if (engine.getVEvents().at(0)->getUP()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _settings -= 1;
      } else if (engine.getVEvents().at(0)->getCROSS()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _page = PAGE::CONTROLS;
      }
      break;
    case 2:
      engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("settings_back").getTexture(), position2d<s32>(0, 0));
      if (engine.getVEvents().at(0)->getUP()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _settings -= 1;
      } else if (engine.getVEvents().at(0)->getCROSS()) {
        NsManager::NsAudioManager_.getSound("sword")->getSound().play();
        _settings = 0;
        _page = PAGE::HOME;
      }
      break;
    default:
      break;
  }
}

void Menu::controls(void) {
  NsGUI::GraphicsEngine &engine = NsGUI::GraphicsEngine::Instance();
  engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("controls").getTexture(), position2d<s32>(0, 0));
  if ((engine.getVEvents().at(0))->getCROSS()) _page = PAGE::SETTINGS;
}

void Menu::player_selection(void) {
  NsGUI::GraphicsEngine &engine = NsGUI::GraphicsEngine::Instance();
  if (_player < _cursor_player.size()) {
    switch (_cursor_player[_player]) {
      case 0:
        if (_player == 0)
          engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("warriorP1").getTexture(), position2d<s32>(0, 0));
        else if (_player == 1)
          engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("warriorP2").getTexture(), position2d<s32>(0, 0));
        else if (_player == 2)
          engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("warriorP3").getTexture(), position2d<s32>(0, 0));
        else
          engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("warriorP4").getTexture(), position2d<s32>(0, 0));
        if (_player < engine.getVEvents().size() && (engine.getVEvents().at(_player))->getDOWN()) {
          NsManager::NsAudioManager_.getSound("sword")->getSound().play();
          _cursor_player[_player] += 1;
        } else if (_player < engine.getVEvents().size() && (engine.getVEvents().at(_player))->getUP()) {
          NsManager::NsAudioManager_.getSound("sword")->getSound().play();
          _cursor_player[_player] = 3;
        } else if (_player < engine.getVEvents().size() && (engine.getVEvents().at(_player))->getCROSS()) {
          NsManager::NsAudioManager_.getSound("sword")->getSound().play();
          if (check_selection()) {
            if (_player + 1 < _nb_player) {
              _player += 1;
            } else _state = STATE::START;
          }
        }
        break;
      case 1:
        if (_player == 0)
          engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("archerP1").getTexture(), position2d<s32>(0, 0));
        else if (_player == 1)
          engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("archerP2").getTexture(), position2d<s32>(0, 0));
        else if (_player == 2)
          engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("archerP3").getTexture(), position2d<s32>(0, 0));
        else
          engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("archerP4").getTexture(), position2d<s32>(0, 0));
        if (_player < engine.getVEvents().size() && (engine.getVEvents().at(_player))->getDOWN()) {
          NsManager::NsAudioManager_.getSound("sword")->getSound().play();
          _cursor_player[_player] += 1;
        } else if (_player < engine.getVEvents().size() && (engine.getVEvents().at(_player))->getUP()) {
          NsManager::NsAudioManager_.getSound("sword")->getSound().play();
          _cursor_player[_player] -= 1;
        } else if (_player < engine.getVEvents().size() && (engine.getVEvents().at(_player))->getCROSS()) {
          NsManager::NsAudioManager_.getSound("sword")->getSound().play();
          if (check_selection()) {
            if (_player + 1 < _nb_player) {
              _player += 1;
            } else _state = STATE::START;
          }
        }
        break;
      case 2:
        if (_player == 0)
          engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("wizardP1").getTexture(), position2d<s32>(0, 0));
        else if (_player == 1)
          engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("wizardP2").getTexture(), position2d<s32>(0, 0));
        else if (_player == 2)
          engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("wizardP3").getTexture(), position2d<s32>(0, 0));
        else
          engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("wizardP4").getTexture(), position2d<s32>(0, 0));
        if (_player < engine.getVEvents().size() && (engine.getVEvents().at(_player))->getDOWN()) {
          NsManager::NsAudioManager_.getSound("sword")->getSound().play();
          _cursor_player[_player] += 1;
        } else if (_player < engine.getVEvents().size() && (engine.getVEvents().at(_player))->getUP()) {
          NsManager::NsAudioManager_.getSound("sword")->getSound().play();
          _cursor_player[_player] -= 1;
        } else if (_player < engine.getVEvents().size() && (engine.getVEvents().at(_player))->getCROSS()) {
          NsManager::NsAudioManager_.getSound("sword")->getSound().play();
          if (check_selection()) {
            if (_player + 1 < _nb_player) {
              _player += 1;
            } else _state = STATE::START;
          }
        }
        break;
      case 3:
        if (_player == 0)
          engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("guardianP1").getTexture(), position2d<s32>(0, 0));
        else if (_player == 1)
          engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("guardianP2").getTexture(), position2d<s32>(0, 0));
        else if (_player == 2)
          engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("guardianP3").getTexture(), position2d<s32>(0, 0));
        else
          engine.Driver()->draw2DImage(NsManager::NsTexturesManager_.getTexture("guardianP4").getTexture(), position2d<s32>(0, 0));
        if (_player < engine.getVEvents().size() && (engine.getVEvents().at(_player))->getUP()) {
          NsManager::NsAudioManager_.getSound("sword")->getSound().play();
          _cursor_player[_player] -= 1;
        } else if (_player < engine.getVEvents().size() && (engine.getVEvents().at(_player))->getDOWN()) {
          NsManager::NsAudioManager_.getSound("sword")->getSound().play();
          _cursor_player[_player] = 0;
        } else if (_player < engine.getVEvents().size() && (engine.getVEvents().at(_player))->getCROSS()) {
          NsManager::NsAudioManager_.getSound("sword")->getSound().play();
          if (check_selection()) {
            if (_player + 1 < _nb_player) {
              _player += 1;
            } else _state = STATE::START;
          }
        }
        break;
      default:
        break;
    }
  }
}
