

#ifndef SHIPLIST_HPP
# define SHIPLIST_HPP

#include "Node.hpp"

class ShipList{

public:
    ShipList();
    ShipList(ShipList const & other);
    ShipList &operator = (ShipList const & other);
    ~ShipList();

    Node * getHead() const ;
    void pushBack(Node * newOne);
    void removeNode(Node * node );

    int isEmptyList() const ;
    int getElemIn() const ;

private:
    Node * head_;
    int elementsIn_;

};

#endif