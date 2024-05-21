#ifndef __SESSION_H__
#define __SESSION_H__


#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Item 9: use alias declarations over typedefs
using Map = vector<vector<bool>>;
using Coords = pair<int, int>;

class SimpleNavigationSession {
    public:
        SimpleNavigationSession(){
            map = Map(10, std::vector<bool>(10, true));
            current = {0, 0};
        };

        void runSession(Coords end, int maxIterations){
            /* TODO: Initialize the robot */
            initializeRobot(current);
            for (size_t i = 0; i < maxIterations; i++)
                {
                    // Getting the next intended position
                    Coords nextCoord = planNextCoordinate(current, end);
                    // Physically drive the robot to the next position
                    current = driveRobot(nextCoord);
                    // Check if the robot has reached the destination
                    if (current == end)
                    {
                        std::cout << "Reached destination" << std::endl;
                        break;
                    }
                }
            shutDownRobot();
        }
        
        private:
            Coords current;
            Map map;
            // Robot functionality
            void initializeRobot(Coords start) {
                current = start;
                cout << "Initialization ... " << endl;
            };
            void shutDownRobot() {
                cout << "Shutting down ..." << endl;
            };
            Coords driveRobot(Coords target) {
                cout << "Driving to " << target.first << ", " << target.second << endl;
                current = target;
                return current;
            };
            //
            Coords planNextCoordinate(Coords current, Coords end) {
                int diffX = end.first - current.first;
                int diffY = end.second - current.second;
                float nrmX = diffX == 0 ? 0 : diffX / abs(diffX);
                float nrmY = diffX == 0 ? 0 : diffY / abs(diffY);
                return {current.first + nrmX, current.second + nrmY};
            };
            // void updateMap(const Map& map) {};
};

#endif