

#ifndef BULLETLIST_HPP
# define BULLETLIST_HPP

#include "LstNode.hpp"

class BulletList{

public:
    BulletList();
    BulletList(BulletList const & other);
    BulletList &operator = (BulletList const & other);
    ~BulletList();

    LstNode * getHead() const ;
    void pushBack(LstNode * newOne);
    void removeNode(LstNode * node );
    int  getElemIn() const;
    int isEmptyList() const ;

private:
    LstNode * head_;
    int elementsIn_;

};

#endif