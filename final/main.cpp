#include <iostream>
#include <vector>

#include "inventory_item.h"
#include "session.h"
#include "dummy_navigator.h"
#include "hexapod_robot.h"

using namespace std;
// Helpers
vector<InventoryItem> getRobots() {
    HexapodRobot robot1("Alice", 1);
    HexapodRobot robot2("Bob", 2);
    HexapodRobot robot3("Charlie", 3);
    return {robot1, robot2, robot3};
}

// "service" definition
vector<ItemFilter> getPredicates() {
    vector<char> chars = {'A', 'B', 'C'};
    vector<ItemFilter> predicates;
    for (auto c : chars) {
        // CAPTURE BY VALUE 
        predicates.push_back([=](InventoryItem item) -> bool {
            return item.getName().front() == c;
        });

        // CAPTURE BY REFERENCE (references will dangle)
        // predicates.push_back([&](InventoryItem item) -> bool {
        //     return item.getName().front() == c;
        // });

        // NO CAPTURE, the "c" is not available.
        // predicates.push_back([](InventoryItem item) -> bool {
        //     return item.getName().front() == c;
        // });
    }
    return predicates;
}

// Tests
void testSession() {
    // building services
    HexapodRobot robot("Alice", 1);
    DummyNavigator nav;
    // injection into client
    NavigationSession session(robot, nav);
    // use client
    session.runSession({9, 9}, 12);
}

void testFilterWith() {
    vector<InventoryItem> robots = getRobots();
    // "service" definition
    ItemFilter biggerThanOne = [](InventoryItem item) -> bool {
        return item.getId() > 1;
    };
    ItemFilter startsWithA = [](InventoryItem item) -> bool {
        return item.getName().front() == 'A';
    };
    // injecting into "client" code
    cout << "items starting with A: " << endl;
    printFilterWith(robots, startsWithA);
    cout << "items with ID bigger than 1: " << endl;
    printFilterWith(robots, biggerThanOne);
}

void testLambdaCaptures() {
    vector<InventoryItem> robots = getRobots();
    // "service" definition
    vector<ItemFilter> predicates = getPredicates();
    for (auto predicate : predicates) {
        cout << "Predicate: " << endl;
        // injecting into "client" code
        printFilterWith(robots, predicate);
    }
}

int main(int argc, char const *argv[])
{
    testSession();
    testFilterWith();
}
