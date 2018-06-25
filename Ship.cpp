

#include "Ship.hpp"
#include "iostream"

Ship::Ship() {
    this->curentBullets_ = 0;
    this->hitPoints_ = 3;
    this->score = 0;
}

Ship::Ship(Ship const &other) {
    *this = other;
}

Ship::Ship(int x, int y, int rch)  {

    this->curentBullets_ = 0;
    this->x_ = x;
    this->y_ = y;
    this->represChar_ = rch;
    this->hitPoints_ = 3;
    this->score = 0;
}
Ship& Ship::operator=(Ship const &other) {
    this->x_ = other.getX();
    this->y_ = other.getY();
    this->represChar_ = other.getRChar();
    this->represStr_ = other.represStr_;
    this->hitPoints_ = other.hitPoints_;
    return *this;
}

void Ship::makeShoot() {

    Bullet * bullet = new Bullet(this->x_ + 1, this->y_, '*');
    LstNode * nn = new LstNode(bullet);
    this->bl.pushBack((nn));
    this->curentBullets_++;

}
BulletList& Ship::getBulletsList()  {
    return this->bl;
}


int Ship::getCurrentBullets() const {
    return this->curentBullets_;
}

int Ship::getHP() const {
    return this->hitPoints_;
}

void Ship::setX(int x) {
    this->x_ = x;
}

void Ship::setY(int y) {
    this->y_ = y;
}

void Ship::setRChar(int c) {
    this->represChar_ = c;
}

void Ship::setScore(int sc) {
    this->score = sc;
}
int Ship::getScore() const {
    return this->score;
}
void Ship::setHP(int hp) {
    this->hitPoints_ = hp;
}
Ship::~Ship() {

}