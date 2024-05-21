#ifndef __DUMMY_NAVIGATOR_H__
#define __DUMMY_NAVIGATOR_H__

#include "session.h"

class DummyNavigator : public INavigation {
    public:
        Coords next(Coords current, Coords end) override {
            int diffX = end.first - current.first;
            int diffY = end.second - current.second;
            float nrmX = diffX == 0 ? 0 : diffX / abs(diffX);
            float nrmY = diffX == 0 ? 0 : diffY / abs(diffY);
            return {current.first + nrmX, current.second + nrmY};
        };
        void updateMap(const Map& map) override {};
};

#endif
