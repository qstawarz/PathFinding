//
// Created by Quentin on 11/14/2017.
//
#include <iostream>

#include "../../includes/Managers/Game.h"

using namespace Managers;

Game::Game() : m_displayManager {nullptr}, m_inputManager {nullptr}, m_uiManager {nullptr},
               m_player {nullptr}, m_enemy {nullptr}, m_GridManager {nullptr},
               m_clock {}, m_time {}, m_deltaTime {}
{
//    std::cout << "Game created" << std::endl;
}

Game::~Game()
{
    if (this->m_GridManager != nullptr)
        delete this->m_GridManager;

    if (this->m_enemy != nullptr)
        delete this->m_enemy;

    if (this->m_player != nullptr)
        delete this->m_player;

    if (this->m_uiManager != nullptr)
        delete this->m_uiManager;

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
//    //UIManager
//    if (this->m_displayManager->IsStarted());
//    this->m_uiManager = new UIManager(this->m_displayManager->getWindow());
//    if (this->m_uiManager != nullptr)
//        this->m_uiManager->Setup();
//    //Player
//    if (this->m_displayManager->IsStarted())
//        this->m_player = new Player(this->m_displayManager->getWindow());
//    if (this->m_player != nullptr)
//        this->m_player->Setup();
//    //Enemy
//    if (this->m_displayManager->IsStarted())
//        this->m_enemy = new Enemy(this->m_displayManager->getWindow());
//    if (this->m_enemy != nullptr)
//        this->m_enemy->Setup();
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

//    this->m_uiManager->Update();
//
//    this->m_player->Update();
//
//    this->m_enemy->Update();
}

void Game::Display()
{
//    this->m_enemy->Display();
//
//    this->m_player->Display();
//
//    this->m_uiManager->Display();
//    this->m_uiManager->Score();

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