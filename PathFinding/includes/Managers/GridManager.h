//
// Created by Quentin on 11/21/2017.
//

#ifndef PATHFINDING_PFMANAGER_H
#define PATHFINDING_PFMANAGER_H

#include <list>
#include <SFML/Graphics.hpp>

#include "IManager.h"
#include "../Utils/Cell.h"

using namespace Utils;

namespace Managers
{
    class GridManager : public IManager
    {
    public:
        static const unsigned m_cols = 50;
        static const unsigned m_rows = 50;

    private:
        sf::RenderWindow *m_window;

        std::vector<Cell*> m_grid;
        std::vector<Cell*> m_openSet;
        std::vector<Cell*> m_closedSet;
        std::vector<Cell*> m_path;

        Cell *m_start;
        Cell *m_end;

        bool m_solution;
        bool m_done;
        bool m_newPath;

    public:
        explicit GridManager(sf::RenderWindow *p_window);
        ~GridManager();

        void Setup() override;
        void Update() override;

        void Display();

        void Remove(std::vector<Cell*> &p_grid, Cell* p_current);
        bool Found(std::vector<Cell*> &p_grid, Cell* p_current);

        float heuristic(Cell *p_current, Cell *p_end);

        bool getDone() const;

    };
}

#endif //PATHFINDING_PFMANAGER_H