#ifndef UNTITLED_SHAPE_H
#define UNTITLED_SHAPE_H
#include "Screen.h"

using namespace std;

enum shape { R, C };
class Shape{
protected:
    char color;
    int u;
    int v;
    enum shape type;
public:
    Shape();
    ~Shape();
    virtual bool draw(char* buffer, Screen& display) = 0;
};

void put_pixel(int x, int y, int c, char* buffer, Screen& display);

#endif //UNTITLED_SHAPE_H
