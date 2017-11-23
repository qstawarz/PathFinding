//
// Created by Quentin on 11/21/2017.
//
#include <iostream>

#include "../../includes/Utils/Cell.h"
#include "../../includes/Managers/GridManager.h"

using namespace Utils;
using namespace Managers;

Cell::Cell() : m_shape {nullptr}, m_i {0}, m_j {0}, m_f {0.0f}, m_g {0.0f}, m_h {0.0f}, m_wall {false},
               m_previous {nullptr}, m_neighbors {}
{
//    std::cout << "Cell created" << std::endl;
}

Cell::Cell(int p_i, int p_j, float p_w, float p_h) : m_shape {nullptr}, m_i {p_i}, m_j {p_j},
                                                     m_f {0.0f}, m_g {0.0f}, m_h {0.0f}, m_previous{nullptr},
                                                     m_neighbors {}
{
    this->setShape(p_i, p_j, p_w, p_h);

//    std::cout << "Cell created" << std::endl;
}

Cell::Cell(const Cell &p_other)
{
    *this = p_other;
}

Cell &Cell::operator=(const Cell &p_other)
{
    this->m_shape = p_other.m_shape;
    this->m_i = p_other.m_i;
    this->m_j = p_other.m_j;
    this->m_f = p_other.m_f;
    this->m_g = p_other.m_g;
    this->m_h = p_other.m_h;

    this->m_previous = p_other.m_previous;
    this->m_neighbors = p_other.m_neighbors;

    return *this;
}

Cell::~Cell()
{
    if (this->m_shape != nullptr)
        delete this->m_shape;

//    std::cout << "Cell destroyed" << std::endl;
}

sf::RectangleShape *Cell::getShape() const
{
    return this->m_shape;
}

void Cell::setShape(int p_i, int p_j, float p_w, float p_h)
{
    if (rand()%100 < 30)
        this->m_wall = true;

    this->m_shape = new sf::RectangleShape(sf::Vector2f(p_w, p_h));

    this->m_shape->setPosition(p_i * p_w, p_j * p_h);
    this->m_shape->setFillColor(sf::Color::White);
    this->m_shape->setOutlineThickness(1.0f);
    this->m_shape->setOutlineColor(sf::Color::Black);

    if (this->m_wall)
        this->m_shape->setFillColor(sf::Color::Black);
}

void Cell::addNeighbors(std::vector<Cell*> p_grid)
{
    int cols = GridManager::m_cols;
    int rows = GridManager::m_rows;
    int i = this->m_i;
    int j = this->m_j;

    if (i < cols - 1)
        this->m_neighbors.push_back(p_grid[(i + 1) * cols + j]);
    if (i > 0)
        this->m_neighbors.push_back(p_grid[(i - 1) * cols + j]);
    if (j < rows - 1)
        this->m_neighbors.push_back(p_grid[i * cols + (j + 1)]);
    if (j > 0)
        this->m_neighbors.push_back(p_grid[i * cols + (j - 1)]);
    if (i > 0 && j > 0)
        this->m_neighbors.push_back(p_grid[(i - 1) * cols + (j - 1)]);
    if (i > 0 && j < rows - 1)
        this->m_neighbors.push_back(p_grid[(i - 1) * cols + (j + 1)]);
    if (i < cols - 1 && j > 0)
        this->m_neighbors.push_back(p_grid[(i + 1) * cols + (j - 1)]);
    if (i < cols - 1 && j < rows - 1)
        this->m_neighbors.push_back(p_grid[(i + 1) * cols + (j + 1)]);
}