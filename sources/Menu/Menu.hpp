//
// Menu.hpp for indie_studio in /Users/antoinedeforges/Desktop/ubuntu-shared/cpp_indie_studio/include/
//
// Made by Antoine Deforges
// Login   <deforg_a@epitech.eu>
//
// Started on  Tue May 16 14:00:26 2017 Antoine Deforges
// Last update Fri Jun 16 04:14:04 2017 Antoine Deforges
//
#ifndef Menu_hpp_
#define Menu_hpp_

#include <irrlicht.h>
#include "../Gui/GeneralGUI.hpp"
#include "RessourcesManager.hpp"

#define CURSOR_HOME 0
#define PLAYER1 1
#define PLAYER2 2
#define PLAYER3 3
#define PLAYER4 4

class Menu {
	enum class STATE {RUN, START, EXIT};
	enum class PAGE {HOME, PLAY, SETTINGS, CREDITS, CONTROLS};
	enum class HOME {PLAY = 0, SETTINGS = 1, CREDITS = 2, EXIT = 3};

private:
	int																	_home;
	int                                	_settings;
	int 																_audio;
	std::vector<int>										_cursor_player;
	int																	_player;
	PAGE																_page;
	STATE																_state;
	int																	_nb_player;

public:
	Menu(void);
	~Menu(void);
	void 																Initialization(void);
	std::vector<int>										launcher(void);
	void 																page_manager(void);
	void 																home(void);
	bool 																check_selection(void);
	void 																player_selection(void);
	void 																credits(void);
	void 																controls(void);
	void 																audio(void);
	void 																settings(void);
};

#endif // !Menu_hpp_
