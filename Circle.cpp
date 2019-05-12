#include "Circle.h"

enum shape tc = C;

Circle::Circle(int u, int v, int r, enum colors c) : r(r)
{
    color = c;
    type=tc;
    Shape::u=u;
    Shape::v=v;

}
bool Circle::draw(char *buffer, Screen &display) {
    if(u-r<0 || v-r<0 || u+r>display.get_x() || v+r>display.get_y())
    {
       return false;
    }
    for (int x = u - r - 1; x < u + r + 1; x++)
    {
        for (int y = v - r - 1; y < v + r + 1; y++)
        {
            if (pow((x - u), 2) + pow((y - v), 2) <= r * r)
            {
                put_pixel(x, y, color, buffer, display);
            }
        }
    }
    cout << "kesz" << endl;
    return true;
}

ostream &Circle::operator<<(Shape* circle) {
    cout << "Szin: " << this->color << "Kozeppont: " << this->u << "," << this->v << "Sugar: " << this->r << endl;
    return os;
}



