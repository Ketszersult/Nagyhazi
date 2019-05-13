#ifndef UNTITLED_CIRCLE_H
#define UNTITLED_CIRCLE_H

#include "Shape.h"


class Circle : public Shape {
private:
    int r;
public:
    Circle(int u, int v, int r, enum colors c);

    ~Circle();

    bool draw(char *buffer, Screen &display);

    int get_u();

    int get_v();

    int get_r();

    void set_u(int uu);

    void set_v(int vv);

    void set_r(int rr);

};


#endif //UNTITLED_CIRCLE_H
