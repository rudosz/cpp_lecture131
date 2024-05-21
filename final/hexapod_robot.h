#ifndef __HEXAPOD_ROBOT_H__
#define __HEXAPOD_ROBOT_H__

#include "session.h"
#include "inventory_item.h"
#include <string>
using namespace std;

class HexapodRobot : public IRobot, public InventoryItem{

    public:
        HexapodRobot(std::string name, int id) : InventoryItem(name, id){
            map = Map(10, std::vector<bool>(10, true));
            current = {0, 0};
        }

        void initialize(Coords start) override {
            current = start;
            cout << "Initialization ... " << endl;
        };
        void shutDown() override {
            cout << "Shutting down ..." << endl;
        };
        Coords drive(Coords target) override {
            cout << "Driving to " << target.first << ", " << target.second << endl;
            current = target;
            return current;
        };
        Map getMap() const override{return map;};

    private:
        Coords current;
        Map map;
};


#endif
