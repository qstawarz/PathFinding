//
// Created by Quentin on 11/20/2017.
//

#ifndef SFMLQUICKSTART_IMANAGER_H
#define SFMLQUICKSTART_IMANAGER_H

namespace Managers
{
    class IManager
    {
    public:
        virtual ~IManager() = default;

        virtual void Setup() = 0;
        virtual void Update() = 0;

    };
}

#endif //SFMLQUICKSTART_IMANAGER_H