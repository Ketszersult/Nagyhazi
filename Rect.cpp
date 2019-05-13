#include "Rect.h"


Rect::Rect(int x, int y, int a, int b, enum colors c) : a(a), b(b)
{
    color = c;
    u = x;
    v = y;

}

bool Rect::draw(char *buffer, Screen &display)
{
    if (u < 0 || v < 0 || u + a > display.get_x() || v + b > display.get_y())    //pozicio ellenorzese
    {
        cout << "kifut a kepernyorol" << endl;
        return false;
    }
    for (int i = u; i <= (u + a); i++)      //x iranyban rajzol
    {
        for (int j = v; j <= (v + b); j++)      //y iranyban rajzol
        {
            put_pixel(i, j, color, buffer, display);        //kirajzolja a negyzetet
        }
    }
    cout << "kesz" << endl;
    return true;
}

void Rect::print()
{
    cout << "Szin: " << (int)get_color() << " Bal felso sarok(u,v):" << get_u() << "," << get_v()
         << " a: " << get_a() << " b: " << get_b();
}

//getter, setter fuggvenyek

int Rect::get_a() { return this->a; }

int Rect::get_b() { return this->b; }

int Rect::get_u() { return this->u; }

int Rect::get_v() { return this->v; }

void Rect::set_a(int aa) { this->a = aa; }

void Rect::set_b(int bb) { this->b = bb; }

void Rect::set_u(int uu) { this->u = uu; }

void Rect::set_v(int vv) { this->v = vv; }

Rect::~Rect() {}


