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
    ~Rect();

    bool draw(char* buffer, Screen& display);
    int get_u();
    int get_v();
    int get_a();
    int get_b();
    void set_u(int uu);
    void set_v(int vv);
    void set_a(int aa);
    void set_b(int bb);
};


#endif //UNTITLED_RECT_H
