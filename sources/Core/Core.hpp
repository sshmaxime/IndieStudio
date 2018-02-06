/*
** Core.hpp for new in /home/sshsupreme/tek2/new/sources/Core
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Wed May 17 16:52:12 2017 sshSupreme
** Last update Sun Jun 18 18:31:50 2017 Florent Sebag
*/

#ifndef _CORE_HPP_
# define _CORE_HPP_

#include <vector>
#include "../Features/Score.hpp"
#include "../Features/Settings.hpp"
#include "RessourcesManager.hpp"
#include "../Menu/Menu.hpp"
#include "../Entity/Healthbar.hpp"
#include "../IA/IA.hpp"
#include "GUI.hpp"
#include "../GameObject/GameObject.hpp"
#include "../Entity/Entity.hpp"
#include "../Entity/EnnemyEntity.hpp"
#include "../Entity/PlayableEntity.hpp"
#include "../Projectil/Projectil.hpp"
#include "../SpawnManager/SpawnManager.hpp"
#include "../SplashScreen/SplashScreen.hpp"

#define _TICK_ 0.01

namespace NsCore
{
  enum class GAMESTATE {
    MENU,
    GAMELOOP,
    EXIT
  };
  class Core
  {
    Score                                                     	Score_;
    Settings                                                  	Settings_;
    GAMESTATE                                                 	GAMESTATE_;
    SplashScreen						Splash;

    std::vector<std::shared_ptr<NsEntity::EnnemyEntity>> 	vEnnemy_;
    std::vector<std::shared_ptr<NsEntity::PlayableEntity>>    	vPlayer_;
    std::vector<std::shared_ptr<NsGameObject::GameObject>>    	vObject_;
    std::vector<std::shared_ptr<NsProjectil::Projectil>>      	vProjectil_;
    std::vector<int>						_state;
    IA                                                        	IA_;
    Menu                                                      	Menu_;
    SpawnManager						Spawn_;
    CGUIGame						      	*GameGUI;
    //! Between players
    core::vector3df	                                     	midpoint;
    f64								distance;
    //! Manage Collision
    scene::ITriangleSelector* 					selector;
    irr::scene::ISceneNode*					map_;
    int                                                         actual_room;
    int 							end;

   public:
    void                Initialization();
    void                StartGame();

    void                PushEnnemyEntity(std::shared_ptr<NsEntity::EnnemyEntity>, const irr::core::vector3df&, irr::scene::ITriangleSelector *, int);

   private:
    void                InitializationModels();
    void                InitializationTextures();
    void                InitializationFonts();
    void                InitializationCamera();
    void                InitializationAudio();

   private:
    void                MenuHandler();
    int                	check_end();
    void 		AddModelsSplash();
    void 		DelModelsSplash();

   private:
    void                EngineTick();

    void 		PushGameObject(std::shared_ptr<NsGameObject::GameObject> entity, const core::vector3df &Pos, scene::ITriangleSelector *selector);
    void                PushPlayableEntity(std::shared_ptr<NsEntity::PlayableEntity>, const irr::core::vector3df&, irr::scene::ITriangleSelector *);
    void                EntitySelected(int player);

  public:
    template <typename T>void                DeleteEntityScreen(T&);

   private:
    void                GameTick();
    void                PlayerTick();
    void                EnnemyTick();
    void                CameraTick();
    void		GameObjectTick();
    void                ProjectilTick();
    void		RoomsTick();

    //! Look distance between players and check if the player can move
    void                CheckDist(std::vector<std::shared_ptr<NsEvents::KeyInput>>::iterator iterator);

   public:
    Core();
    ~Core();

    irr::scene::ITriangleSelector * createMap();
    void AddSky();

    void generateMonsters(std::vector<Room>::iterator iterator);

    scene::ITriangleSelector *getSelector() const;
    void generateGoldKey(std::vector<Room>::iterator iterator);
    void generateDoors();
    void setStartCamera();
    void setCameraStart();
    scene::ISceneNode *getMap_() const {return map_;}
    void setMap_(scene::ISceneNode *map_) {Core::map_ = map_;}

    void end_or_not();

    void CameraPodium();

    void free_world();
  };
}

#endif
