#include "Shape.h"
Shape::Shape() = default;

Shape::~Shape() = default;

void put_pixel(int x, int y, int c, char* buffer, Screen& display)
{
    // calculate the pixel's byte offset inside the buffer
    unsigned int pix_offset = x + y * display.get_linelength();

    // now this is about the same as 'fbp[pix_offset] = value'
    *((char *)(buffer + pix_offset)) = c;
}


