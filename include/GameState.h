/**
 * \brief Saves Game state
 */

#ifndef FIRENICE_GAMESTATE_H
#define FIRENICE_GAMESTATE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class GameState{
public:
    //! \brief Horizontal Resolution
    static const unsigned short _resX {1600};
    //! \brief Vertical Resolution
    static const unsigned short _resY {900};
    //! \brief Start Playing the game!
    static void play();

    enum state {Not_init, AtSplash, AtMenu, Playing, Exiting}; // More maybe added later.
    static state _state;

private:

    //! \brief The set of possible states of the game
    //! \brief Check if the game is in Exiting state.
    static bool isExiting();
    static void gameLoop();
    //! \brief Init and show a splash screen.
    static void showSplashScreen();
    static void showMainMenu();
    //! \brief The current state of the game
    static sf::RenderWindow _mainWindow;
};

#endif //FIRENICE_GAMESTATE_H