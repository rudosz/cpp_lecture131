#ifndef __INVENTORY_ITEM_H__
#define __INVENTORY_ITEM_H__

#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <utility>

using namespace std;

// Item 9: use alias declarations over typedefs
using Map = vector<vector<bool>>;
using Coords = pair<int, int>;


class InventoryItem {
    public:
        InventoryItem(std::string name, int quantity) : name(name), id(quantity) {}
        std::string getName() const { return name; }
        int getId() const { return id; }
    private:
        std::string name;
        int id;
};

class HexapodRobot : public InventoryItem {
    public:
        HexapodRobot(std::string name, int id) : InventoryItem(name, id){
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



void printSwitch(const std::vector<InventoryItem>& inventory, int sw)
{
    auto predicate1 = [](InventoryItem item) -> bool {
        return item.getId() > 1;
    };

    auto predicate2 = [](InventoryItem item) -> bool{
        return item.getName().front() == 'A';
    };
    
    for (const auto& item : inventory) {
        bool result = false;
        if (sw == 1) {
            result = predicate1(item);
        } else {
            result = predicate2(item);
        }
        if (result) {
            std::cout << item.getName() << " " << item.getId() << std::endl;
        }
    }
}


using ItemFilter = std::function<bool(InventoryItem)>;

void printFilterWith(const std::vector<InventoryItem>& inventory, ItemFilter filter)
{
    for (const auto& item : inventory) {
        if (filter(item)) {
            std::cout << item.getName() << " " << item.getId() << std::endl;
        }
    }
}

#endif
