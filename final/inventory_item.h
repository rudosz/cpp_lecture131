#ifndef __INVENTORY_ITEM_H__
#define __INVENTORY_ITEM_H__

#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <utility>

using namespace std;

class InventoryItem {
    public:
        InventoryItem(std::string name, int quantity) : name(name), id(quantity) {}
        std::string getName() const { return name; }
        int getId() const { return id; }
    private:
        std::string name;
        int id;
};

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
