

#include "LstNode.hpp"
#include <iostream>
int LstNode::NodeCount = 0;

LstNode::LstNode() {
    NodeCount++;
    this->next = NULL;
    this->prev = NULL;
    this->bullet = NULL;
}
LstNode::LstNode(Bullet *tbullet):bullet(tbullet) {
    this->next = NULL;
    this->prev = NULL;
    NodeCount++;
}

LstNode::LstNode(LstNode const &other) {
    *this = other;
}

LstNode& LstNode::operator=(LstNode const &other) {
    this->bullet = other.bullet;
    this->next = other.next;
    this->prev = other.prev;
    this->NodeCount = other.NodeCount;
    return *this;
}
LstNode *LstNode::getNext() const {
    return this->next;
}

LstNode *LstNode::getPrev() const {
    return this->prev;
}

void LstNode::setNext(LstNode *node) {
    this->next = node;
}

Bullet* LstNode::getBullet() const {
    return this->bullet;
}

void LstNode::setPrev(LstNode *node) {
    this->prev = node;
}

LstNode::~LstNode() {
    NodeCount--;
    if (this->bullet != NULL)
    {
        delete this->bullet;
        this->bullet = NULL;
        this->next = NULL;
        this->prev = NULL;
    }
}
