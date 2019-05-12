#include "Shape.h"

char Shape::get_color() {
    return color;
}

enum shape Shape::get_type() {
    return this->type;
}

ostream &operator<<(ostream &os, Shape *obj) {      //<< operator tulterhelese, hogy kiirja a ketfele objektumot
    if(obj->get_type() == R)        //Rect objektumra vonatkozo
    {
        Rect* robj  = ((Rect*)obj);
        cout << "Szin: " << (int)obj->get_color() << " Bal felso sarok(u,v):" << robj->get_u() << "," << robj->get_v() << " a: " << robj->get_a() << " b: " << robj->get_b();
    }
    if(obj->get_type() == C)        //Circle objektumra vonatkozo
    {
        Circle* cobj = ((Circle*)obj);
        cout << "Szin: " << (int)obj->get_color() << " Kozeppont(u,v):" << cobj->get_u() << "," << cobj->get_v() << " Sugar: " << cobj->get_r();
    }
        return os;
}

void put_pixel(int x, int y, int c, char* buffer, Screen& display)      // pixel beszinezese
{
    // kiszamolja a pixel offsetjet
    unsigned int pix_offset = x + y * display.get_linelength();

    // beallitja a szint a megadott pixelre
    *((char *)(buffer + pix_offset)) = c;
}
