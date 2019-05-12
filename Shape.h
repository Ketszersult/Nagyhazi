#ifndef UNTITLED_SHAPE_H
#define UNTITLED_SHAPE_H
#include "Screen.h"

using namespace std;

enum shape { R, C };
enum colors {
    black,
    blue,
    green,
    turkisz,
    red,
    pink,
    brown,
    light_grey,
    dark_grey,
    light_blue,
    light_green,
    light_turkisz,
    light_red,
    light_pink,
    yellow,
    white
};
class Shape{
protected:
    enum colors color;
    int u;
    int v;
    enum shape type;
public:
    Shape();
    ~Shape();
    virtual bool draw(char* buffer, Screen& display) = 0;
    virtual ostream& operator<<(ostream& os) = 0;
    char get_color();
    virtual int get_u() = 0;
    virtual int get_v() = 0;
    virtual int get_r() = 0;
    virtual int get_a() = 0;
    virtual int get_b() = 0;
};

void put_pixel(int x, int y, int c, char* buffer, Screen& display);

#endif //UNTITLED_SHAPE_H
