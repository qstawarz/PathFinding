//
// Created by Quentin on 11/14/2017.
//

#ifndef PATHFINDING_GAME_H
#define PATHFINDING_GAME_H

#include "IManager.h"
#include "DisplayManager.h"
#include "InputManager.h"
#include "GridManager.h"

namespace Managers
{
    class Game : public IManager
    {
    private:
        DisplayManager *m_displayManager;
        InputManager *m_inputManager;
        GridManager *m_GridManager;

        sf::Clock m_clock;
        sf::Time m_deltaTime;
        sf::Time m_time;

    public:
        Game();
        ~Game();

        void Setup() override;
        void Update() override;

        void Display();
        void Run();

    };
}

#endif //CATCH_ME_GAME_H