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

char Rect::get_color() {
    return color;
}

ostream & operator<<(ostream &os, Shape* obj) {
    cout << "Szin: " << obj->get_color() << "Bal felso sarok:" << this->u << "," << this->v << "a: " << this->a << "b: " << this->b << endl;
    return os;
}


