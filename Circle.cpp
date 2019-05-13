#include "Circle.h"

enum shape tc = C;

Circle::Circle(int u, int v, int r, enum colors c) : r(r)
{
    color = c;
    type = tc;
    Shape::u = u;
    Shape::v = v;

}

bool Circle::draw(char *buffer, Screen &display)
{
    if (u - r < 0 || v - r < 0 || u + r > display.get_x() ||
        v + r > display.get_y())    //a kor poziciojanak ellenorzese
    {
        cout << "kifut a kepernyorol" << endl;
        return false;
    }
    for (int x = u - r - 1; x < u + r + 1; x++)     //kozepponttol jobbra es balra
    {                                                                                             //negyzeten belul rajzol
        for (int y = v - r - 1; y < v + r + 1; y++)     //kozepponttol le es fel
        {
            if (pow((x - u), 2) + pow((y - v), 2) <= r * r)
            {
                put_pixel(x, y, color, buffer, display);        //kirajzolja a kort a kor egyenlet alapjan
            }
        }
    }
    cout << "kesz" << endl;
    return true;
}

//getter, setter fuggvenyek

int Circle::get_r() { return this->r; }

int Circle::get_u() { return this->u; }

int Circle::get_v() { return this->v; }

void Circle::set_v(int vv) { this->v = vv; }

void Circle::set_u(int uu) { this->u = uu; }

void Circle::set_r(int rr) { this->r = rr; }

Circle::~Circle() {}

