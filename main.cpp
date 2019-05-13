#include "Screen.h"
#include "Rect.h"
#include "Circle.h"
#include <vector>

using namespace std;

int main()
{
    Screen display;     //megnyitja a framebuffert es kiolvassa az infokat
    char buffer[display.get_screensize()];  //letrehoz egy buffert ami pont akkora mint a framebuffer
    memset(buffer, 0, display.get_screensize());  //letorli a memoriaszemetet
    std::vector<Shape *> shapes;     //vector az objektumok tarolasara
    char input = 1; //menu input tarolasara
    int selected;   //objektum valasztashoz
    enum colors c;      //a constructorba enum kell a szinhez
    int color, hcolor = 0;  //color beolvasashoz
    //szinek kiirasa
    cout
            << "0-black, 1-blue, 2-green, 3-turkisz, 4-red, 5-pink, 6-brown, 7-light_grey, 8-dark_grey, 9-light_blue, 10-light_green, 11-light_turkisz, 12-light_red, 13-light_pink, 14-yellow, 15-white"
            << endl;

    while (input != '0')    //menu kezdete
    {
        cout << "0 - kilep\n1 - hatter\n2 - negyzet\n3 - kor\n4 - objektumok listazasa\n5 - kirajzol" << endl;
        cin >> input;
        if (input == '1')
        {
            do
            {
                cout << "Milyen szinnel(0-15)?" << endl;
                cin >> hcolor;  //beallitja a hatterszin valtozot
            } while (!(hcolor >= 0 && hcolor <= 15));  //input ellenorzes
            input = 1; //input visszaallitasa
        }

        if (input == '2')
        {
            int x, y, a, b;
            cout << "Hova? Mekkorat? Milyen szinnel(x y a b color)?" << endl;
            cin >> x >> y >> a >> b >> color;
            if (color >= 0 && color <= 15)
            {                                       //a default szin a feher, ha nem megfelelo szint adunk neki
                c = (enum colors) color;
            } else
            {
                color = 15;
                c = (enum colors) color;
            }
            Shape *rectangle = new Rect(x, y, a, b, c); //negyzet objektum letrehozasa
            shapes.push_back(rectangle);    //beillesztes a vektorba
            input = 1;
        }
        if (input == '3')
        {
            int x, y, r;
            cout << "Hova? Mekkora a sugara? Milyen szinnel(x y r color)?" << endl;
            cin >> x >> y >> r >> color;
            if (color >= 0 && color <= 15)
            {                                       //a default szin a feher, ha nem megfelelo szint adunk neki
                c = (enum colors) color;
            } else
            {
                color = 15;
                c = (enum colors) color;
            }
            Shape *circle = new Circle(x, y, r, c); //kor objektum letrehozasa
            shapes.push_back(circle);       //beillesztes a vektorba
            input = 1;
        }
        if (input == '4')
        {
            if (shapes.empty())
            {
                cout << "ures" << endl;
            }
            do
            {
                for (int i = 0; i < shapes.size(); i++)
                {
                    cout << i << " - ";
                    cout << shapes[i] << endl;
                }
                cout << "valaszd ki az objektumot" << endl;
                cin >> selected;
            } while (!(selected >= 0 && selected < shapes.size()));
            do
            {
                cout << "1 - torol, 2 - modosit, 3 - felcserel, 0 - vissza" << endl;
                cin >> input;
                if (input == '1')
                {
                    delete shapes[selected]; //kitorli
                    shapes.erase(shapes.begin() + selected); //kiveszi a vektorbol a pointert
                    input = 1;
                }
                if (input == '2')
                {
                    do
                    {
                        cout << shapes[selected] << endl; //kiirja az objektum parametereit
                        cout << "mit szeretnel modositani(a,b,u,v,r)?\n0-semmit" << endl;
                        cin >> input;
                        int n;
                        switch (input)
                        {
                            case 'a':
                                cout << "a erteke?" << endl;
                                cin >> n;
                                ((Rect *) shapes[selected])->set_a(n);
                                break;
                            case 'b':
                                cout << "b erteke?" << endl;
                                cin >> n;
                                ((Rect *) shapes[selected])->set_b(n);
                                break;
                            case 'u':
                                cout << "u erteke?" << endl;
                                cin >> n;
                                shapes[selected]->set_u(n);
                                break;
                            case 'v':
                                cout << "v erteke?" << endl;
                                cin >> n;
                                shapes[selected]->set_v(n);
                                break;
                            case 'r':
                                cout << "r erteke?" << endl;
                                cin >> n;
                                ((Circle *) shapes[selected])->set_r(n);
                                break;
                            default:
                                break;

                        }
                    } while (input != '0');
                    input = 1;
                }
                if (input == '3')
                {
                    int in;
                    do
                    {
                        cout << "Melyikkel cserelne ki?" << endl;
                        cin >> in;
                    } while (!(in >= 0 && in < shapes.size()));
                    Shape *temp = shapes[selected];             //kicsereli a ket megadott pointert a vektorban
                    shapes[selected] = shapes[in];
                    shapes[in] = temp;
                    input = 1;

                }
            } while (input != '0');
            input = 1;
        }
        if (input == '5')
        {
            memset(buffer, hcolor, display.get_screensize()); //beallitja a hatterszint
            for (Shape *i : shapes)
            {
                i->draw(buffer, display);   //kirajzolja sorba az objektumokat
            }
            display.print_out(buffer);      //atmasolja a buffert
            input = 1;
        }
    }
    for (int i = 0; i < shapes.size(); i++)
    {
        delete shapes[i];           //felszabaditja a memoriat
    }
    shapes.clear();     //kiuriti a vektort
    return 0;
}
