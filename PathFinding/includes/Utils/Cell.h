//
// Created by Quentin on 11/21/2017.
//

#ifndef PATHFINDING_CELL_H
#define PATHFINDING_CELL_H

#include <SFML/Graphics.hpp>

namespace Utils
{
    class Cell
    {
    public:
        int m_i;
        int m_j;
        float m_f;
        float m_g;
        float m_h;

        bool m_wall;

        Cell* m_previous;

        std::vector<Cell*> m_neighbors;

    private:
        sf::RectangleShape *m_shape;

    public:
        Cell();
        explicit Cell(int p_i, int p_j, float p_w, float p_h);
        Cell(const Cell& p_other);
        Cell &operator=(const Cell& p_other);
        ~Cell();

        sf::RectangleShape *getShape() const;

        void setShape(int p_i, int p_j, float p_w, float p_h);
        void addNeighbors(std::vector<Cell*> p_grid);

    };
}

#endif //PATHFINDING_CELL_H