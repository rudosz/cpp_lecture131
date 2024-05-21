#ifndef __SESSION_H__
#define __SESSION_H__


#include <iostream>
#include <vector>
#include <utility>

// Item 9: use alias declarations over typedefs
using Map = std::vector<std::vector<bool>>;
using Coords = std::pair<int, int>;

class INavigation {
    public:
        virtual Coords next(Coords current, Coords goal) = 0;
        virtual void updateMap(const Map&) = 0;
        virtual ~INavigation() {};
};

class IRobot {
    public:
        virtual ~IRobot() {};
        virtual void initialize(Coords start) = 0;
        virtual void shutDown() = 0;
        virtual Coords drive(Coords) = 0;
        virtual Map getMap() const = 0;
};

class NavigationSession {
    public:
        IRobot& robot;
        INavigation& navigation;

        NavigationSession(IRobot& robot, INavigation& navigation) : robot(robot), navigation(navigation) {};

        void runSession(Coords end, int maxIterations){
            robot.initialize({0, 0});
            Coords current = {0, 0};
            for (size_t i = 0; i < maxIterations; i++)
                {
                    current = robot.drive(navigation.next(current, end));
                    navigation.updateMap(robot.getMap());
                    if (current == end)
                    {
                        std::cout << "Reached destination" << std::endl;
                        break;
                    }
                }
            robot.shutDown();
        }
};

#endif