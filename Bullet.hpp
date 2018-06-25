



#ifndef BULLET_HPP
# define BULLET_HPP

#include "AObject.hpp"

class Bullet : public AObject
{
public:
    Bullet();
    Bullet(Bullet const & other);
    Bullet(int x, int y, int rch);
    Bullet &operator = (Bullet const & other);
    ~Bullet();

   // int getBulletsOn() const ;
    //void setBulletsOn(int val);
    static int bulletsOn_;

};

#endif
