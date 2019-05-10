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
    while (input != '0')
    {

        cout << "0 - kilep\n1 - kepernyo torlese\n2 - negyzet\n3 - kor" << endl;
        cin >> input;
        if (input == '1')
        {
            int color;
            cout << "Milyen szinnel?\n1-tol 15-ig" << endl;
            cin >> color;
            memset(buffer,color,display.get_screensize());
            input = 1;
        }

        if (input == '2')
        {
            int x, y, a, b;
            int color;
            cout << "Hova? Mekkorat? Milyen szinnel?" << endl;
            cin >> x;
            cin >> y;
            cin >> a;
            cin >> b;
            cin >> color;
            Shape* rectangle = new Rect(x, y, a, b, color);
            shapes.push_back(rectangle);
            input = 1;
        }
        if (input == '3')
        {
            int x, y, r;
            int color;
            cout << "Hova? Mekkora a sugara? Milyen szinnel?" << endl;
            cin >> x;
            cin >> y;
            cin >> r;
            cin >> color;
            Shape* circle = new Circle(x, y, r, color);
            shapes.push_back(circle);
            input = 1;
        }
        if (input == '4')
        {
            for(Shape* i : shapes)
            {
                i->draw(buffer, display);
            }
            input = 1;
        }
        if (input == '5')
        {
            display.print_out(buffer);
            input = 1;
        }

    }
    return 0;
}
