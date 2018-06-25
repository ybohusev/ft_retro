


#ifndef COLLISIONS_HPP
# define COLLISIONS_HPP

#include "BulletList.hpp"
#include "ShipList.hpp"

class Collisions{

public:
    Collisions();
    Collisions(Collisions const & other);
    Collisions &operator = (Collisions const & other);
    Collisions(int x);
    ~Collisions();

    void collisionWallBullet(BulletList & bl);
    void wallShipsCollitsion(ShipList & sl);
    void bulletShip(BulletList & our, ShipList  & enem, Ship & we);
    void heroEnemCollis(Ship & ship, ShipList & enemShips, WINDOW * window);
private:
    int maxX_;
};

#endif