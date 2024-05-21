#include <iostream>
#include <vector>

#include "composite_session.h"


void testCompositeSession() {
    // building services
    HexapodRobot robot;
    DummyNavigator navigator;
    // injecting services into client
    CompositeNavigationSession session(robot, navigator);
    session.runSession({9, 9}, 12);
}

int main(int argc, char const *argv[])
{
    using namespace std;
    testCompositeSession();
}
