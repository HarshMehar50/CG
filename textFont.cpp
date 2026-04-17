#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(50, 50, "Default Font");
    
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
    outtextxy(50, 100, "Triplex Font");

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(50, 150, "Sans Serif Font");

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    outtextxy(50, 200, "Gothic Font");

    getch();
    closegraph();
    return 0;
}
