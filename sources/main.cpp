/*
** main.cpp for new in /home/sshsupreme/tek2/new
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Wed May 17 16:31:43 2017 sshSupreme
** Last update Sun Jun 18 03:10:41 2017 Florent Sebag
*/

#include <SFML/Audio.hpp>
#include "GeneralGUI.hpp"
#include "Core.hpp"
#include "Models3DManager.hpp"
#include "Gui/GeneralGUI.hpp"
#include "Core/Core.hpp"


int         main()
{
  NsGUI::GraphicsEngine &engine = NsGUI::GraphicsEngine::Instance();
  engine.Initialization(); // first init for graphic engine

  NsCore::Core        GAUNTLET;

  GAUNTLET.StartGame();
  return (0);
}
/*
 *
 * x = -1534
 * y = 583
 * z = - 4207
 *
 * Rot y = 1.6
 * rot x = 353 (ou 0)
 */
