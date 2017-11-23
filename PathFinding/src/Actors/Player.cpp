//
// Created by Quentin on 11/20/2017.
//
#include <iostream>

#include "../../includes/Actors/Player.h"
#include "../../includes/Managers/DisplayManager.h"

using namespace Actors;
using namespace Managers;

Player::Player(sf::RenderWindow *p_window) : m_window {p_window}, m_sprite {nullptr},
                                             m_pos {0.0f, 0.0f}, m_scale {1.0f}
{
    std::cout << "Player created" << std::endl;
}

Player::~Player()
{
    std::cout << "Player destroyed" << std::endl;
}

void Player::Setup()
{
    this->m_sprite = new Sprite("../res/Assets/Player.png");

    float xBound = this->m_sprite->getSprite()->getTextureRect().width / 2.0f;
    float yBound = this->m_sprite->getSprite()->getTextureRect().height / 2.0f;

    this->m_sprite->getSprite()->setOrigin(xBound, yBound);
    this->m_sprite->getSprite()->setPosition(this->m_pos);
    this->m_sprite->getSprite()->scale(sf::Vector2f(this->m_scale, this->m_scale));
}

void Player::Update()
{
    this->m_pos = this->m_sprite->getSprite()->getPosition();

    this->Move();
}

void Player::Display()
{
    this->m_window->draw(*this->m_sprite->getSprite());
}

void Player::Move()
{

}