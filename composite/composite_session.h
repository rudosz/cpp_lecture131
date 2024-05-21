#ifndef __SESSION_H__
#define __SESSION_H__


#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Item 9: use alias declarations over typedefs
using Map = vector<vector<bool>>;
using Coords = pair<int, int>;


class DummyNavigator {
    public:
        Coords next(Coords current, Coords end) {
            int diffX = end.first - current.first;
            int diffY = end.second - current.second;
            float nrmX = diffX == 0 ? 0 : diffX / abs(diffX);
            float nrmY = diffX == 0 ? 0 : diffY / abs(diffY);
            return {current.first + nrmX, current.second + nrmY};
        };
        void updateMap(const Map& map) {};
};

class HexapodRobot {

    public:
        HexapodRobot() {
            map = Map(10, std::vector<bool>(10, true));
            current = {0, 0};
        }

        void initialize(Coords start) {
            current = start;
            cout << "Initialization ... " << endl;
        };
        void shutDown() {
            cout << "Shutting down ..." << endl;
        };
        Coords drive(Coords target)  {
            cout << "Driving to " << target.first << ", " << target.second << endl;
            current = target;
            return current;
        };
        Map getMap() const {return map;};

    private:
        Coords current;
        Map map;
};

class CompositeNavigationSession {
    public:
        CompositeNavigationSession(HexapodRobot& robot, DummyNavigator& navigator) : robot(robot), navigator(navigator) {};

        void runSession(Coords end, int maxIterations){
            /* Initialize the robot */
            Coords current = {0, 0};
            robot.initialize(current);
            for (size_t i = 0; i < maxIterations; i++)
                {
                    // Getting the next intended position
                    Coords nextCoord = navigator.next(current, end);
                    // Physically drive the robot to the next position
                    current = robot.drive(nextCoord);
                    // Check if the robot has reached the destination
                    if (current == end)
                    {
                        std::cout << "Reached destination" << std::endl;
                        break;
                    }
                }
            robot.shutDown();
        }
        
        private:
            HexapodRobot robot;
            DummyNavigator navigator;

};

#endif