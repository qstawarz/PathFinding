//
// Created by Quentin on 11/14/2017.
//

#ifndef CATCH_ME_INPUTMANAGER_H
#define CATCH_ME_INPUTMANAGER_H

#include <SFML/Graphics.hpp>

#include "IManager.h"

namespace Managers
{
    class InputManager : public IManager
    {
    private:
        sf::RenderWindow *m_window;
        sf::Event *m_event;

    public:
        explicit InputManager(sf::RenderWindow *p_window);
        ~InputManager();

        void Setup() override;
        void Update() override;

        sf::Event *getEvent() const;

        void checkInput();

    };
}

#endif //CATCH_ME_EVENTMANAGER_H