


#ifndef NODE_HPP
# define NODE_HPP

#include "Ship.hpp"
#include "BulletList.hpp"

class Node{

public:
    Node();
    Node(Node const & other);
    Node &operator = (Node const & other);
    ~Node();
    Node(Ship * ship);
    Node *getNext() const;
    Node *getPrev() const;
    void setNext(Node * node);
    void setPrev(Node * node);
    Ship *getShip() const ;
private:
    Ship * ship;
    Node * next;
    Node * prev;

};

#endif