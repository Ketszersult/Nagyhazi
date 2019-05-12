#ifndef UNTITLED_RECT_H
#define UNTITLED_RECT_H

#include "Shape.h"

class Rect:public Shape
{
private:
    int a;
    int b;
public:
    Rect(int x, int y, int a, int b, char color);
    bool draw(char* buffer, Screen& display);

};


#endif //UNTITLED_RECT_H
