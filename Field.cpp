

#include "Field.hpp"
#include "Ship.hpp"
#include <unistd.h>
#include <iostream>
#include "Collisions.hpp"

Field::Field() {

    this->window_ = initscr();
    getmaxyx(window_, maxY_, maxX_);
    raw();
    noecho();
    keypad(this->window_, true);
    start_color();
    curs_set(0);
}

Field::Field(Field const &other) {
    *this = other;
}

Field& Field::operator=(Field const &other) {
    this->maxY_ = other.maxY_;
    this->maxX_ = other.maxX_;
    this->window_ = other.window_;
    return *this;
}

void    Field::bulletsDraw(BulletList &bl)
{

    LstNode * tmp = bl.getHead();
    while (tmp)
    {
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        attron(COLOR_PAIR(3));
        mvaddch(tmp->getBullet()->getY(), tmp->getBullet()->getX(), tmp->getBullet()->getRChar());
        attroff(COLOR_PAIR(3));
        tmp = tmp->getNext();
    }

}

void    Field::drawHero(Ship & we){
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    we.setStr(">");
    mvprintw(we.getY(), we.getX(), we.getStr().c_str());
    attroff(COLOR_PAIR(1));
}

void    Field::drowEnem(ShipList & shipList)
{
    Node *tmp = shipList.getHead();
    while (tmp)
    {
        init_pair(2, COLOR_MAGENTA,COLOR_BLACK);
        attron(COLOR_PAIR(2));
        // mvaddch(tmp->getShip()->getY(), tmp->getShip()->getX(), tmp->getShip()->getRChar());
        mvprintw(tmp->getShip()->getY(), tmp->getShip()->getX(), "<_<_<///0_/");
        attroff(COLOR_PAIR(2));
        tmp = tmp->getNext();
    }
}

void Field::backGroundDraw(AObject * obj) {

    for (int i = 0; i < 100; ++i)
    {
        mvaddch(obj[i].getY(), obj[i].getX(), '.');
    }
}

void Field::drawStat(Ship &we) {

    mvprintw(0, maxX_ - 30, "HP: %d, SCORE: %d", we.getHP(), we.getScore() );
}
int Field::getMaxX() const {
    return this->maxX_;
}
int Field::getMaxY() const {
    return this->maxY_;
}

void Field::setMaxX(int val) {
    this->maxX_ = val;
}
void Field::setMaxY(int val) {
     this->maxY_ = val;
}

WINDOW* Field::getWindow() {
    return this->window_;
}
Field::~Field() {
    nodelay(stdscr, false);
}
