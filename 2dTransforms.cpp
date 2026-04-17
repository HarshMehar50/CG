#include <graphics.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>

class Point {
public:
    float x, y;
};

void drawPolygon(Point p[], int n) {
    for (int i = 0; i < n; i++) {
        line(p[i].x, p[i].y, p[(i+1)%n].x, p[(i+1)%n].y);
    }
}

// Translation
void translate(Point p[], int n, int tx, int ty) {
    for (int i = 0; i < n; i++) {
        p[i].x += tx;
        p[i].y += ty;
    }
}

// Scaling
void scale(Point p[], int n, float sx, float sy) {
    for (int i = 0; i < n; i++) {
        p[i].x *= sx;
        p[i].y *= sy;
    }
}

// Rotation (about origin)
void rotate(Point p[], int n, float angle) {
    float rad = angle * 3.14 / 180;
    for (int i = 0; i < n; i++) {
        float x = p[i].x;
        float y = p[i].y;
        p[i].x = x * cos(rad) - y * sin(rad);
        p[i].y = x * sin(rad) + y * cos(rad);
    }
}

// Shearing
void shear(Point p[], int n, float shx, float shy) {
    for (int i = 0; i < n; i++) {
        float x = p[i].x;
        float y = p[i].y;
        p[i].x = x + shx * y;
        p[i].y = y + shy * x;
    }
}

// Reflection
void reflect(Point p[], int n, int choice) {
    for (int i = 0; i < n; i++) {
        if (choice == 1)       // X-axis
            p[i].y = -p[i].y;
        else if (choice == 2)  // Y-axis
            p[i].x = -p[i].x;
        else if (choice == 3) { // Origin
            p[i].x = -p[i].x;
            p[i].y = -p[i].y;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int n, choice;
    Point p[10];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter coordinates:\n";
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    cleardevice();
    setcolor(WHITE);
    drawPolygon(p, n);
    outtextxy(10, 10, "Original Shape");

    cout << "\n1. Translation\n2. Scaling\n3. Rotation\n4. Shearing\n5. Reflection\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int tx, ty;
            cout << "Enter tx and ty: ";
            cin >> tx >> ty;
            translate(p, n, tx, ty);
            break;
        }
        case 2: {
            float sx, sy;
            cout << "Enter sx and sy: ";
            cin >> sx >> sy;
            scale(p, n, sx, sy);
            break;
        }
        case 3: {
            float angle;
            cout << "Enter angle: ";
            cin >> angle;
            rotate(p, n, angle);
            break;
        }
        case 4: {
            float shx, shy;
            cout << "Enter shx and shy: ";
            cin >> shx >> shy;
            shear(p, n, shx, shy);
            break;
        }
        case 5: {
            int ch;
            cout << "1.X-axis 2.Y-axis 3.Origin\nEnter: ";
            cin >> ch;
            reflect(p, n, ch);
            break;
        }
    }

    setcolor(YELLOW);
    drawPolygon(p, n);
    outtextxy(10, 30, "Transformed Shape");

    getch();
    closegraph();
    return 0;
}
