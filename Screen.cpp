#include "Screen.h"

int Screen::get_x() { return hres; }

int Screen::get_y() { return vres; }

int Screen::get_depth() { return var_info.bits_per_pixel; }

int Screen::get_linelength() { return fix_info.line_length; }

long int Screen::get_screensize() { return screensize; }

char *Screen::buffer() { return fbp; }

void Screen::print_out(char *buffer)
{
    memcpy(this->fbp, buffer, get_screensize());
}

/*void Screen::clear(char c) {
    memset(this->fbp, c, var_info.xres * var_info.yres);
}*/

Screen::Screen()
{
    //framebuffer megnyitasa
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1)
    {
        printf("Error: cannot open framebuffer device.\n");
    }
    printf("The framebuffer device opened.\n");

    //atallitja a szinmelyseget
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &var_info))
    {
        printf("Error reading variable screen info.\n");
    }
    var_info.bits_per_pixel = 8;
    if (ioctl(fbfd, FBIOPUT_VSCREENINFO, &var_info))
    {
        printf("Error setting variable information.\n");
    }

    printf("Variable info:\n %dx%d, %d bpp\n",
           var_info.xres,
           var_info.yres,
           var_info.bits_per_pixel);


    //keprenyo informacio kiolvasasa
    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &fix_info))
    {
        printf("Error reading fixed screen info.\n");
    }
    printf("Fixed info:\n");
    printf(" id = %s\n type=%d\n accel=%d\n",
           fix_info.id,
           fix_info.type,
           fix_info.accel);
    printf(" smem_len=%d\n line_length=%d\n capabs=%d\n",
           fix_info.smem_len,
           fix_info.line_length,
           fix_info.capabilities);


    screensize = fix_info.smem_len;
    hres = var_info.xres;
    vres = var_info.yres;

    //buffer kimappalese a memoriaba
    fbp = (char *) mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);

    if (*(int *) fbp == -1)
    {
        printf("Failed to mmap.\n");
    }

    //cursor elrejtese
    console_fd = open("/dev/tty0", O_RDWR);
    if (!console_fd)
    {
        fprintf(stderr, "Could not open console.\n");
        exit(1);
    }
    if (ioctl(console_fd, KDSETMODE, KD_GRAPHICS))
    {
        fprintf(stderr, "Could not set console to KD_GRAPHICS mode.\n");
        exit(1);
    }
    close(console_fd);
}

Screen::~Screen()
{
    //cursor visszaallitasa
    if (kbfd >= 0)
    {
        ioctl(kbfd, KDSETMODE, KD_TEXT);
    }
    //fajl bezarasa
    close(fbfd);
    //memoria felszabaditasa
    munmap(fbp, screensize);
}


