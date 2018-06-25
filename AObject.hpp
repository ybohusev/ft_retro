



#ifndef AOBJECT_HPP
# define AOBJECT_HPP

#include "string"

class AObject{
public:
    AObject();
    AObject(AObject const & other);
    AObject &operator = (AObject const & other);
    ~AObject();

    int getX()const;
    int getY()const;
    int getRChar() const;
    std::string getStr() const;

    void setX(int v);
    void setY(int v);
    void setChar(int v);
    void setStr(std::string str);

    void moveUp();
    void moveDown(int maxY);
    void moveLeft();
    void moveRight(int maxX);


protected:
    int x_;
    int y_;
    int represChar_;
    std::string represStr_;
};

#endif