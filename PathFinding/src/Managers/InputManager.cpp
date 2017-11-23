//
// Created by Quentin on 11/14/2017.
//
#include <iostream>

#include "../../includes/Managers/InputManager.h"

using namespace Managers;

InputManager::InputManager(sf::RenderWindow *p_window) : m_window {p_window}, m_event {nullptr}
{
//    std::cout << "InputManager created" << std::endl;
}

InputManager::~InputManager()
{
    if (this->m_event != nullptr)
        delete this->m_event;

//    std::cout << "InputManager destroyed" << std::endl;
}

void InputManager::Setup()
{
    this->m_event = new sf::Event;
}

void InputManager::Update()
{
    this->checkInput();
}

sf::Event *InputManager::getEvent() const
{
    return this->m_event;
}

void InputManager::checkInput()
{
    while (this->m_window->pollEvent(*this->m_event))
    {
        if (this->m_event->type == sf::Event::Closed)
            this->m_window->close();

        if (this->m_event->key.code == sf::Keyboard::Escape)
            this->m_window->close();
    }
}