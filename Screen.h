#ifndef UNTITLED_SCREEN_H
#define UNTITLED_SCREEN_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <linux/kd.h>
#include <sys/ioctl.h>
#include <math.h>
#include <iostream>
#include <vector>

class Screen {
private:
    int fbfd; // framebuffer filedescriptor
    struct fb_var_screeninfo var_info;
    struct fb_fix_screeninfo fix_info;
    //struct fb_var_screeninfo orig_vinfo;
    int kbfd;
    long int screensize = 0;
    char *fbp = nullptr;
    int hres, vres;
    int console_fd;
public:
    Screen();
    ~Screen();
    int get_x();
    int get_y();
    int get_depth();
    int get_linelength();
    char *buffer();
    void print_out(char *buffer);
    void clear(char c);
    long int get_screensize();



};


#endif //UNTITLED_SCREEN_H
