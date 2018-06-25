

#include <curses.h>
#include "Bullet.hpp"

int Bullet::bulletsOn_ = 0;

Bullet::Bullet() {
    bulletsOn_++;
}

Bullet::Bullet(Bullet const &other) {
    *this = other;
}

Bullet::Bullet(int x, int y, int rch)  {

    bulletsOn_++;

    this->x_ = x;
    this->y_ = y;
    this->represChar_ = rch;
}

Bullet& Bullet::operator=(Bullet const &other) {
    this->x_ = other.getX();
    this->y_ = other.getY();
    this->represChar_ = other.getRChar();
    return *this;
}

Bullet::~Bullet(){
    bulletsOn_--;
}
