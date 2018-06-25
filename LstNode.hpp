

#ifndef LSTNODE_HPP
# define LSTNODE_HPP

#include "Bullet.hpp"

class LstNode{

public:
    LstNode();
    LstNode(LstNode const & other);
    LstNode &operator = (LstNode const & other);
    LstNode(Bullet * tbullet);
    ~LstNode();

    LstNode *getNext() const;
    LstNode *getPrev() const;
    void setNext(LstNode * node);
    void setPrev(LstNode * node);
    Bullet *getBullet() const ;
    static int  NodeCount;
private:
    Bullet * bullet;
    LstNode * next;
    LstNode * prev;

};

#endif
