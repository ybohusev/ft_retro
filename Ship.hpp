

#ifndef SHIP_HPP
# define SHIP_HPP

#include "AObject.hpp"
#include "Bullet.hpp"
#include "BulletList.hpp"

class Ship : public AObject{
public:
    Ship();
    Ship(int x, int y, int rch);
    Ship(Ship const & other);
    Ship &operator = (Ship const & other);
    ~Ship();

    int getHP() const;
    int getScore() const;
    int getCurrentBullets() const ;
    BulletList & getBulletsList()  ;

    void setX(int x);
    void setY(int y);
    void setHP(int hp);
    void setScore(int sc);
    void setRChar(int c);

    void makeShoot();


protected:
    int hitPoints_;
    int score;
    BulletList  bl;
    int curentBullets_;

};

#endif