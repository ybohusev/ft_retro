

#include "ShipList.hpp"
#include "Node.hpp"
#include <iostream>
#include "BulletList.hpp"

ShipList::ShipList() {
    this->head_ = NULL;
    this->elementsIn_ = 0;
}

ShipList::ShipList(ShipList const &other) {
    *this = other;
}

ShipList& ShipList::operator=(ShipList const &other) {

    this->elementsIn_ = other.elementsIn_;
    this->head_ = other.head_;
    return *this;
}
Node* ShipList::getHead() const {
    return this->head_;
}
int ShipList::getElemIn() const {
    return  this->elementsIn_;
}
int ShipList::isEmptyList() const {
    Node * tmp = this->head_;
    int i = 0;
    while (tmp)
    {
        tmp = tmp->getNext();
        i++;
    }
    return i;
}
void ShipList::pushBack(Node *newOne) {
    Node * tmp = this->head_;
    Node * prev = NULL;
    this->elementsIn_++;
    if (this->head_ == NULL)
    {
        this->head_ = newOne;
        this->head_->setPrev(NULL);
        this->head_->setNext(NULL);
    } else{
        while (tmp->getNext() != NULL)
        {
            prev = tmp;
            tmp = tmp->getNext();
            tmp->setPrev(prev);
        }
        tmp->setNext(newOne);
        newOne->setPrev(tmp);
    }

}

void ShipList::removeNode(Node *node) {

    if (node->getPrev() == NULL && node->getNext() == NULL)
    {
        delete node;
        this->elementsIn_--;
    }
    else if (node->getPrev() == NULL)
    {
        this->head_ = node->getNext();
        this->head_->setPrev(NULL);
        delete node;
        this->elementsIn_--;

    } else if (node->getPrev() != NULL && node->getNext() == NULL)
    {
            node->getPrev()->setNext(NULL);
        delete node;
        this->elementsIn_--;
    }
    else
    {
        node->getPrev()->setNext(node->getNext());
        node->getNext()->setPrev(node->getPrev());
        delete node;
        this->elementsIn_--;
    }
    node = NULL;
    if (this->elementsIn_ <= 0)
        this->head_ = NULL;
}

ShipList::~ShipList() {

}