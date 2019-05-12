#ifndef UNTITLED_CIRCLE_H
#define UNTITLED_CIRCLE_H

#include "Shape.h"



class Circle:public Shape
{
private:
    int r;
public:
    Circle(int u, int v, int r, enum colors c);
    bool draw(char* buffer, Screen& display);
    ostream& operator<<(ostream &os);
    char get_color();

};


#endif //UNTITLED_CIRCLE_H
