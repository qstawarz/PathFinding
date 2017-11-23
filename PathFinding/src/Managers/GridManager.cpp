//
// Created by Quentin on 11/21/2017.
//
#include <cmath>
#include <iostream>

#include "../../includes/Managers/GridManager.h"
#include "../../includes/Managers/DisplayManager.h"

using namespace Managers;

GridManager::GridManager(sf::RenderWindow *p_window) : m_window {p_window}, m_grid {},
                                                       m_openSet {}, m_closedSet {}, m_path {},
                                                       m_start {nullptr}, m_end {nullptr},
                                                       m_solution {true}, m_done {false}, m_newPath {false}
{
//    std::cout << "GridManager created" << std::endl;
}

GridManager::~GridManager()
{
    for (auto it : this->m_grid)
        delete it;

//    std::cout << "GridManager destroyed" << std::endl;
}

void GridManager::Setup()
{
    float w = DisplayManager::m_windowW / this->m_cols;
    float h = DisplayManager::m_windowH / this->m_rows;
    //Create grid
    for (int i = 0; i < this->m_cols; ++i)
        for (int j = 0; j < this->m_rows; ++j)
            this->m_grid.push_back(new Cell(i, j, w, h));
    //Add neighbors
    for (auto it : this->m_grid)
        it->addNeighbors(this->m_grid);
    //Start
    this->m_grid.front()->m_wall = false;
    this->m_grid.front()->getShape()->setFillColor(sf::Color::White);
    this->m_start = this->m_grid.front();
    //End
    this->m_grid.back()->m_wall = false;
    this->m_grid.back()->getShape()->setFillColor(sf::Color::White);
    this->m_end = this->m_grid.back();

    this->m_openSet.push_back(this->m_start);
}

void GridManager::Update()
{
    size_t openSetSize = this->m_openSet.size();
    size_t neighborsCount = 0;
    size_t winner = 0;
    Cell *current = nullptr;
    Cell *neighbor = nullptr;
    Cell *temp = nullptr;
    std::vector<Cell*> neighbors;
    float tempG = 0.0f;

    if (this->m_solution)
    {
        if (!this->m_openSet.empty())
        {
            for (size_t i = 0; i < openSetSize; ++i)
                if (this->m_openSet[i]->m_f < this->m_openSet[winner]->m_f)
                    winner = i;

            current = this->m_openSet[winner];

            //Trying to find the path
            this->m_path.clear();
            temp = current;
            this->m_path.push_back(temp);

            while (temp->m_previous)
            {
                this->m_path.push_back(temp->m_previous);
                temp = temp->m_previous;
            }

            if (current == this->m_end)
            {
                //Find the final path
                temp = current;
                this->m_path.push_back(temp);

                while (temp->m_previous)
                {
                    this->m_path.push_back(temp->m_previous);
                    temp = temp->m_previous;
                }

                std::cout << "DONE!" << std::endl;
                this->m_done = true;
                return;
            }

            this->Remove(this->m_openSet, current);
            this->m_closedSet.push_back(current);

            neighbors = current->m_neighbors;
            neighborsCount = neighbors.size();

            for (size_t i = 0; i < neighborsCount; ++i)
            {
                neighbor = neighbors[i];

                if (!this->Found(this->m_closedSet, neighbor) && !neighbor->m_wall)
                {
                    tempG = current->m_g + 1;

                    if (this->Found(this->m_openSet, neighbor))
                    {
                        if (tempG < neighbor->m_g)
                        {
                            neighbor->m_g = tempG;
                            this->m_newPath = true;
                        }
                    }
                    else
                    {
                        neighbor->m_g = tempG;
                        this->m_newPath = true;
                        this->m_openSet.push_back(neighbor);
                    }

                    if (this->m_newPath)
                    {
                        neighbor->m_h = heuristic(neighbor, this->m_end);
                        neighbor->m_f = neighbor->m_g + neighbor->m_h;
                        neighbor->m_previous = current;
                    }
                }
            }
        }
        else
        {
            std::cout << "NO SOLUTION!" << std::endl;
            this->m_solution = false;
            return;
        }
    }
}

void GridManager::Display()
{
    for (auto it : this->m_grid)
        this->m_window->draw(*it->getShape());

    for (auto it : this->m_openSet)
    {
        it->getShape()->setFillColor(sf::Color::Green);
        it->getShape()->setFillColor(sf::Color::Green);
        this->m_window->draw(*it->getShape());
    }

    for (auto it : this->m_closedSet)
    {
        it->getShape()->setFillColor(sf::Color::Red);
        this->m_window->draw(*it->getShape());
    }

    for (auto it : this->m_path)
    {
        it->getShape()->setFillColor(sf::Color::Blue);
        this->m_window->draw(*it->getShape());
    }
}

void GridManager::Remove(std::vector<Cell *> &p_grid, Cell *p_current)
{
    size_t index = 0;
    bool found = false;

    for (auto it : p_grid)
    {
        if (it == p_current)
            found = true;
        if (!found)
            ++index;
    }

    p_grid.erase(p_grid.begin() + index);
}

bool GridManager::Found(std::vector<Cell *> &p_grid, Cell *p_current)
{
    for (auto it : p_grid)
        if (it == p_current)
            return true;

    return false;
}

float GridManager::heuristic(Cell *p_current, Cell *p_end)
{   //Rectilinear distance (4-way movement)
//    float x = abs(p_current->m_i - p_end->m_i);
//    float y = abs(p_current->m_j - p_end->m_j);
//
//    return x + y;
    //Euclidean distance (any angle)
    auto x = static_cast<float>(pow(p_current->m_i - p_end->m_i, 2));
    auto y = static_cast<float>(pow(p_current->m_j - p_end->m_j, 2));

    return std::sqrt(x + y);
    //Diagonal distance (8-way movement)
//    float x = abs(p_current->m_i - p_end->m_i);
//    float y = abs(p_current->m_j - p_end->m_j);
//
//    return std::max(x, y);
}

bool GridManager::getDone() const
{
    return this->m_done;
}