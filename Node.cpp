


#include <iostream>
#include "Node.hpp"


Node::Node() {

    this->next = NULL;
    this->prev = NULL;
    this->ship = NULL;
}

Node::Node(Node const &other) {
    *this = other;
}
Node& Node::operator=(Node const &other) {
    this->prev = other.prev;
    this->next = other.next;
    this->ship = other.ship;
    return  * this;
}
Node::Node(Ship *tShip):ship(tShip) {
    this->next = NULL;
    this->prev = NULL;
}
Node *Node::getNext() const {
    return this->next;
}

Node *Node::getPrev() const {
    return this->prev;
}

void Node::setNext(Node *node) {
    this->next = node;
}

Ship* Node::getShip() const {
    return this->ship;
}

void Node::setPrev(Node *node) {
    this->prev = node;
}

Node::~Node() {

    if (this->ship != NULL)
    {
        this->prev = NULL;
        this->next = NULL;
        delete this->ship;
        this->ship = NULL;

    }
}