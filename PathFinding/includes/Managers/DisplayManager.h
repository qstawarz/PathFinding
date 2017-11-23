//
// Created by Quentin on 11/14/2017.
//

#ifndef PATHFINDING_DISPLAYMANAGER_H
#define PATHFINDING_DISPLAYMANAGER_H

#include <SFML/Graphics.hpp>

#include "IManager.h"

namespace Managers
{
    class DisplayManager : public IManager
    {
    public:
        static const unsigned m_windowW = 500;
        static const unsigned m_windowH = 500;

    private:
        sf::RenderWindow *m_window;

        bool m_isStarted;

    public:
        DisplayManager();
        ~DisplayManager();

        void Setup() override;
        void Update() override;

        sf::RenderWindow *getWindow() const;

        bool IsRunning() const;
        bool IsStarted() const;
    };
}

#endif //CATCH_ME_DISPLAYMANAGER_H