

#include <cstdlib>
#include "Core.hpp"
#include <iostream>

Core::Core() {
    this->enemRand_ = 5;
    this->collisions_ = Collisions(field_.getMaxX());
    this->obj = new AObject[100];
    randomizeStars();
}

Core::Core(Core const &other) {
    *this = other;
}

Core& Core::operator=(Core const & other) {
    this->field_ = other.field_;
    return *this;
}

void Core::start() {
    Ship we(0, field_.getMaxY()/2, '>');
    int ch = 0;

    //field_.bulletsDraw(we.getBulletsList());

    halfdelay(1);
    while (true)
    {
        ch = getch();

        if (ch == KEY_UP)
        {
            we.moveUp();
        } else if (ch == KEY_DOWN){
            we.moveDown(field_.getMaxY());
        } else if (ch == KEY_LEFT){
            we.moveLeft();
        } else if (ch == KEY_RIGHT) {
            we.moveRight(field_.getMaxX());
        } else if (ch == ' ')
        {
            we.makeShoot();
            std::cout << "\a";
        } else if (ch == 27)
        {
            endwin();
            break;
        } else{

        }
        this->spawnEnemies();
        collisions_.heroEnemCollis(we, this->shipList_, field_.getWindow());
        this->backGroundMove();
        this->enemMove();
        collisions_.heroEnemCollis(we, this->shipList_, field_.getWindow());
        collisions_.bulletShip(we.getBulletsList(), this->shipList_, we);
        collisions_.wallShipsCollitsion(this->shipList_);
        this->bulletMove(we.getBulletsList());
        collisions_.bulletShip(we.getBulletsList(), this->shipList_, we);
        collisions_.collisionWallBullet(we.getBulletsList());

        erase();
        this->field_.backGroundDraw(this->obj);
        this->field_.bulletsDraw(we.getBulletsList());
        this->field_.drowEnem(this->shipList_);
        this->field_.drawHero(we);
        this->field_.drawStat(we);
        refresh();
    }
}

void Core::randomizeStars() {

    for(int i = 0; i < 100; i++)
    {
        this->obj[i].setX(rand() % this->field_.getMaxX());
        this->obj[i].setY(rand() % this->field_.getMaxY());
        this->obj[i].setChar('.');
    }
}

void Core::spawnEnemies() {


    this->enemRand_ = enemRand_ + 0;
    if (this->shipList_.getElemIn() < 29 && rand() % 10 == this->enemRand_)
        this->shipList_.pushBack(new Node(new Ship(field_.getMaxX() - 1, rand() % field_.getMaxY(), '<')));

}

void Core::backGroundMove() {

    int x = -1, y = -1;

    getmaxyx(this->field_.getWindow(), y, x);
    if (this->field_.getMaxX() != x || this->field_.getMaxY() != y)
    {
        this->field_.setMaxX(x);
        this->field_.setMaxY(y);
        randomizeStars();
    }

    for (int i = 0; i < 100; ++i)
    {
        if (this->obj[i].getX() != 0)
            this->obj[i].moveLeft();
        else
            this->obj[i].setX(this->field_.getMaxX());

        mvaddch(this->obj[i].getY(), this->obj[i].getX(), '.');
    }
}

void Core::enemMove() {
    Node *tmp = this->shipList_.getHead();
    while (tmp)
    {
        tmp->getShip()->moveLeft();
        tmp = tmp->getNext();
    }

}

void Core::bulletMove(BulletList & bl) {

    LstNode * tmp = bl.getHead();
    while (tmp)
    {
        tmp->getBullet()->moveRight(this->field_.getMaxX());
        tmp = tmp->getNext();
    }
}

Core::~Core() {
    delete [] this->obj;
}