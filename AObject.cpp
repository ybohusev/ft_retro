

#include "AObject.hpp"

AObject::AObject() {

}

AObject::AObject(AObject const &other) {
    *this = other;
}

AObject& AObject::operator=(AObject const &other) {
    this->x_ = other.getX();
    this->y_ = other.getY();
    this->represChar_ = other.getRChar();
    return *this;
}

void AObject::moveUp() {
    if (this->y_ > 0)
        this->y_--;
}

void AObject::moveDown(int maxY) {
    if(maxY - 1 > this->y_)
        this->y_++;
}

void AObject::moveLeft(){
    if (this->x_ > 0)
        this->x_--;
}

void AObject::moveRight(int maxX) {
    if (this->x_ < maxX - 1)
        this->x_++;
}

int AObject::getX() const {
    return this->x_;
}

int AObject::getY() const {
    return this->y_;
}

int AObject::getRChar() const {
    return this->represChar_;
}


void AObject::setY(int v) {
    this->y_ = v;
}

void AObject::setX(int v) {
    this->x_ = v;
}

void AObject::setChar(int v) {
    this->represChar_ = v;
}

void AObject::setStr(std::string str) {
    this->represStr_ = str;
}

std::string AObject::getStr() const {
    return this->represStr_;
}

AObject::~AObject(){

}