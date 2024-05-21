#include <iostream>
#include <vector>

#include "session.h"
#include "dummy_navigator.h"
#include "hexapod_robot.h"


void testSession() {
    // building services
    HexapodRobot robot("Alice", 1);
    DummyNavigator nav;
    // injection into client
    NavigationSession session(robot, nav);
    // use client
    session.runSession({9, 9}, 12);
}

int main(int argc, char const *argv[])
{
    using namespace std;
    testSession();
}
