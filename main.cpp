#include "Screen.h"
#include "Rect.h"
#include "Circle.h"
#include <vector>

using namespace std;
std::vector<Shape*> shapes;


int main()
{

    Screen display;
    char buffer[display.get_screensize()];
    memset(buffer,0,display.get_screensize());

    char input = 1;
    enum colors c;
    int color;
    cout << "0-black, 1-blue, 2-green, 3-turkisz, 4-red, 5-pink, 6-brown, 7-light_grey, 8-dark_grey, 9-light_blue, 10-light_green, 11-light_turkisz, 12-light_red, 13-light_pink, 14-yellow, 15-white" << endl;

    while (input != '0')
    {
        cout << "0 - kilep\n1 - kepernyo torlese\n2 - negyzet\n3 - kor\n4 - objektumok listazasa\n5 - kirajzol" << endl;
        cin >> input;
        if (input == '1')
        {
            cout << "Milyen szinnel?" << endl;
            cin >> color;
            memset(buffer,color,display.get_screensize());
            input = 1;
        }

        if (input == '2')
        {
            int x, y, a, b;
            cout << "Hova? Mekkorat? Milyen szinnel(x y a b color)?" << endl;
            cin >> x >> y >> a >> b >> color;
            c = (enum colors)color;
            Shape* rectangle = new Rect(x, y, a, b, c);
            shapes.push_back(rectangle);
            input = 1;
        }
        if (input == '3')
        {
            int x, y, r;
            cout << "Hova? Mekkora a sugara? Milyen szinnel(x y r color)?" << endl;
            cin >> x >> y >> r >> color;
            c = (enum colors)color;
            Shape* circle = new Circle(x, y, r, c);
            shapes.push_back(circle);
            input = 1;
        }
        if (input == '4')
        {
            for(Shape* i : shapes)
            {
                cout<<i;
            }
        }
        if (input == '5')
        {
            for(Shape* i : shapes)
            {
                i->draw(buffer, display);
            }
            display.print_out(buffer);
            input = 1;
        }

    }
    return 0;
}
