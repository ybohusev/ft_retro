

#include "BulletList.hpp"
#include <iostream>

BulletList::BulletList() {
    this->head_ = NULL;
    this->elementsIn_ = 0;
}

BulletList::BulletList(BulletList const &other) {
    *this = other;
}

BulletList& BulletList::operator=(BulletList const &other) {
    this->head_ = other.head_;
    this->elementsIn_ = other.elementsIn_;
    return *this;
}
LstNode* BulletList::getHead() const {
    return this->head_;
}

int BulletList::getElemIn() const {
    return  this->elementsIn_;
}
int BulletList::isEmptyList() const {
    LstNode * tmp = this->getHead();
    int i = 0;
    while (tmp)
    {
        tmp = tmp->getNext();
        i++;
    }
    return i;
}
void BulletList::pushBack(LstNode *newOne) {
    this->elementsIn_++;
    LstNode * tmp = this->head_;
    LstNode * prev;

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
    }

}

void BulletList::removeNode(LstNode *node) {

    if (node->getPrev() == NULL && node->getNext() == NULL)
    {
       delete node;
       this->elementsIn_--;
    }
    else if (node->getPrev() == NULL)
    {
        this->head_ = node->getNext();
        this->head_->setPrev(NULL);
        //delete node->getBullet();
        delete node;
        this->elementsIn_--;
    }
    else if (node->getPrev() != NULL && node->getNext() == NULL)
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

BulletList::~BulletList() {

}