#include <iostream>
#include <vector>

#include "simple_session.h"


void testSimpleSession() {
    // building services
    SimpleNavigationSession session;
    session.runSession({9, 9}, 12);
}

// void testItemList() {
//     // preparing list
//     HexapodRobot robot1("Alice", 1);
//     HexapodRobot robot2("Bob", 2);
//     HexapodRobot robot3("Charlie", 3);
//     std::vector<HexapodRobot> robots = {robot1, robot2, robot3};

//     // building "services"
//     auto predicates = getPredicates();
//     for (auto predicate : predicates) {
//         std::cout << "Predicate: " << std::endl;
//         // injecting "service" (predicate) into "client"
//         printInventory(robots, predicate);
//     }
// }

int main(int argc, char const *argv[])
{
    using namespace std;
    testSimpleSession();
    // testSession();
    // testItemList();
}
