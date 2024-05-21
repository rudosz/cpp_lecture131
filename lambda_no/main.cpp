#include <iostream>
#include <vector>

#include "simple_inventory_item.h"
using namespace std;

void testItemList() {
    HexapodRobot robot1("Alice", 1);
    HexapodRobot robot2("Bob", 2);
    HexapodRobot robot3("Charlie", 3);
    vector<InventoryItem> robots = {robot1, robot2, robot3};

    cout << "items starting with A: " << endl;
    printNameStartsWith(robots, 'A');
    cout << "items with ID bigger than 1: " << endl;
    printIdBiggerThan(robots, 1);

}

int main(int argc, char const *argv[])
{
    testItemList();
}
