#ifndef UNTITLED_RECT_H
#define UNTITLED_RECT_H

#include "Shape.h"

class Rect:public Shape
{
private:
    int a;
    int b;
public:
    Rect(int x, int y, int a, int b, enum colors color);
    bool draw(char* buffer, Screen& display);
    ostream& operator<<(ostream &os);
    int get_u();
    int get_v();
    int get_a();
    int get_b();
};


#endif //UNTITLED_RECT_H
