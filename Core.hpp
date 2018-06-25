


#ifndef CORE_HPP
# define CORE_HPP

#include "Field.hpp"
#include "Collisions.hpp"
#include "Ship.hpp"

class Core{
public:
    Core();
    Core( Core const & other);
    Core &operator = (Core const & other);
    ~Core();

    void start();

    void randomizeStars();
    void spawnEnemies();
    void enemMove();
    void backGroundMove();
    void bulletMove(BulletList & bl);
private:
    Field field_;
    ShipList shipList_;
    AObject *obj;
    int enemRand_;
    Collisions  collisions_;
};

#endif