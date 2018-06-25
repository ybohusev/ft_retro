

#include <curses.h>
#include <zconf.h>
#include "Collisions.hpp"
#include "LstNode.hpp"
#include "Node.hpp"
#include "iostream"

Collisions::Collisions() {

}
Collisions::Collisions(int x):maxX_(x) {

}

Collisions::Collisions(Collisions const &other) {
    *this = other;
}

Collisions& Collisions::operator=(Collisions const &other) {
    this->maxX_ = other.maxX_;
    return *this;
}
void Collisions::collisionWallBullet(BulletList &bl) {
   LstNode *tmp = bl.getHead();
   LstNode * tmp2 = NULL;

    while(tmp)
    {
        if (tmp->getBullet()->getX() == this->maxX_ - 1)
        {
            tmp2 = tmp->getNext();
            bl.removeNode(tmp);
            tmp = tmp2;
        } else
        {
            tmp = tmp->getNext();
        }
    }
}

void Collisions::wallShipsCollitsion(ShipList &sl) {
    Node * tmp = sl.getHead();
    Node * tmp2 = NULL;

    while (tmp)
    {
        if (tmp->getShip()->getX() <= 0)
        {
            tmp2 = tmp->getNext();
            sl.removeNode(tmp);
            tmp = tmp2;
        } else
        {
            tmp = tmp->getNext();
        }

    }
}

void Collisions::bulletShip(BulletList &our, ShipList &enem, Ship & we) {

    Node * shipTmp;
    LstNode * ourBulletsTmp = our.getHead();

    while (ourBulletsTmp)
    {
        shipTmp = enem.getHead();
        while (shipTmp)
        {
            if (ourBulletsTmp->getBullet()->getX() == shipTmp->getShip()->getX() &&
                    ourBulletsTmp->getBullet()->getY() == shipTmp->getShip()->getY())
            {
                enem.removeNode(shipTmp);
                we.setScore(we.getScore() + 1);
                break ;
            }
            shipTmp = shipTmp->getNext();
        }
        ourBulletsTmp = ourBulletsTmp->getNext();
    }
}

void Collisions::heroEnemCollis(Ship & ship, ShipList & enemShips, WINDOW * window){

    Node * tmp = enemShips.getHead();
    int x = 0, y = 0;
    getmaxyx(window, y, x);
    while (tmp)
    {
        if (tmp->getShip()->getX() == ship.getX() && tmp->getShip()->getY() == ship.getY())
        {
            if (ship.getHP() <= 1) {
                nocbreak();
                erase();
                mvprintw(y / 2, x / 2 - 5, "GAME OVER");
                refresh();
                getch();
                erase();
                endwin();
                exit(0);
            } else{
                erase();
                refresh();
                getch();
                erase();
                endwin();
                ship.setHP(ship.getHP() - 1);
                enemShips.removeNode(tmp);
                break;
            }
        }
        tmp = tmp->getNext();
    }
}
Collisions::~Collisions() {

}