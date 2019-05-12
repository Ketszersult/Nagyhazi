#include "Rect.h"

enum shape tr = R;

Rect::Rect(int x, int y, int a, int b, enum colors c) : a(a), b(b)
{
    color = c;
    type=tr;
    u=x;
    v=y;

}

bool Rect::draw(char *buffer, Screen& display) {
    if(u<0 || v<0 || u+a>display.get_x() || v+b>display.get_y())
    {
        return false;
    }
    for (int i = u; i <= (u + a); i++)
    {
        for (int j = v; j <= (v + b); j++)
        {
            put_pixel(i, j, color, buffer, display);
        }
    }
    cout << "kesz" << endl;
    return true;
}


ostream & operator<<(ostream &os, Rect* obj) {
    cout << "Szin: " << obj->get_color() << "Bal felso sarok:" << obj->get_u() << "," << obj->get_v() << "a: " << obj->get_a() << "b: " << obj->get_b() << endl;
    return os;
}

int Rect::get_a() {return this->a;}
int Rect::get_b() {return this->b;}
int Rect::get_u() {return this->u;}
int Rect::get_v() {return this->v;}

