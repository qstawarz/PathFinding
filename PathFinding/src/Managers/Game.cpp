//
// Created by Quentin on 11/14/2017.
//
#include <iostream>

#include "../../includes/Managers/Game.h"

using namespace Managers;

Game::Game() : m_displayManager {nullptr}, m_inputManager {nullptr}, m_GridManager {nullptr},
               m_clock {}, m_time {}, m_deltaTime {}
{
//    std::cout << "Game created" << std::endl;
}

Game::~Game()
{
    if (this->m_GridManager != nullptr)
        delete this->m_GridManager;

    if (this->m_inputManager != nullptr)
        delete this->m_inputManager;

    if (this->m_displayManager != nullptr)
        delete this->m_displayManager;

//    std::cout << "Game destroyed" << std::endl;
}

void Game::Setup()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    //DisplayManager
    this->m_displayManager = new DisplayManager;
    if (this->m_displayManager != nullptr)
        this->m_displayManager->Setup();
    //InputManager
    if (this->m_displayManager->IsStarted());
        this->m_inputManager = new InputManager(this->m_displayManager->getWindow());
    if (this->m_inputManager != nullptr)
        this->m_inputManager->Setup();
    //GridManager
    if (this->m_displayManager->IsStarted())
        this->m_GridManager = new GridManager(this->m_displayManager->getWindow());
    if (this->m_GridManager != nullptr)
        this->m_GridManager->Setup();
}

void Game::Update()
{
    this->m_displayManager->Update();

    this->m_inputManager->Update();

    if (!this->m_GridManager->getDone())
        this->m_GridManager->Update();
}

void Game::Display()
{
    this->m_GridManager->Display();

    this->m_displayManager->getWindow()->display();
}

void Game::Run()
{
    while (this->m_displayManager->IsRunning())
    {
        this->Update();

        this->Display();

        this->m_deltaTime = this->m_clock.restart();
        this->m_time += this->m_deltaTime;
    }
}