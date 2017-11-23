//
// Created by Quentin on 11/20/2017.
//

#ifndef SFMLQUICKSTART_PLAYER_H
#define SFMLQUICKSTART_PLAYER_H

#include <SFML/Graphics.hpp>

#include "IActor.h"
#include "../Utils/Sprite.h"

using namespace Utils;

namespace Actors
{
    class Player : public IActor
    {
    private:
        sf::RenderWindow *m_window;

        Sprite *m_sprite;

        sf::Vector2f m_pos;

        float m_scale;

    public:
        explicit Player(sf::RenderWindow *p_window);
        ~Player();

        void Setup() override;
        void Update() override;
        void Display() override;
        void Move() override;

    };
}

#endif //SFMLQUICKSTART_PLAYER_H