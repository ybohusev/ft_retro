

#ifndef FIELD_HPP
# define FIELD_HPP

#include <ncurses.h>
#include "Bullet.hpp"
#include "Ship.hpp"
#include "Collisions.hpp"
#include "ShipList.hpp"

class Field{

public:
    Field();
    Field(Field const & other);
    Field &operator = (Field const & other);
    ~Field();

    int getMaxX()const;
    int getMaxY()const;
    void setMaxX(int val);
    void setMaxY(int val);
    void bulletsDraw(BulletList &);
    void backGroundDraw(AObject * obj);
    void drawHero(Ship & we);
    void drowEnem(ShipList & shipList);
    void drawStat(Ship & we);
    WINDOW * getWindow();

private:
    WINDOW *window_;
    int maxX_;
    int maxY_;

};

#endif