#include "Shape.h"

char Shape::get_color()
{
    return color;
}


ostream &operator<<(ostream &os, Shape *obj)
{      //<< operator tulterhelese, hogy kiirja a ketfele objektumot
    obj->print();
    return os;
}

void put_pixel(int x, int y, int c, char *buffer, Screen &display)      // pixel beszinezese
{
    // kiszamolja a pixel offsetjet
    unsigned int pix_offset = x + y * display.get_linelength();

    // beallitja a szint a megadott pixelre
    *((char *) (buffer + pix_offset)) = c;
}
