#include <graphics.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>

class Point3D {
public:
    float x, y, z;
};

// Draw cube using projection (ignore z)
void drawCube(Point3D p[]) {
    // Front face
    line(p[0].x, p[0].y, p[1].x, p[1].y);
    line(p[1].x, p[1].y, p[2].x, p[2].y);
    line(p[2].x, p[2].y, p[3].x, p[3].y);
    line(p[3].x, p[3].y, p[0].x, p[0].y);

    // Back face
    line(p[4].x, p[4].y, p[5].x, p[5].y);
    line(p[5].x, p[5].y, p[6].x, p[6].y);
    line(p[6].x, p[6].y, p[7].x, p[7].y);
    line(p[7].x, p[7].y, p[4].x, p[4].y);

    // Connecting edges
    for (int i = 0; i < 4; i++) {
        line(p[i].x, p[i].y, p[i+4].x, p[i+4].y);
    }
}

// Translation
void translate(Point3D p[], int n, float tx, float ty, float tz) {
    for (int i = 0; i < n; i++) {
        p[i].x += tx;
        p[i].y += ty;
        p[i].z += tz;
    }
}

// Scaling
void scale(Point3D p[], int n, float sx, float sy, float sz) {
    for (int i = 0; i < n; i++) {
        p[i].x *= sx;
        p[i].y *= sy;
        p[i].z *= sz;
    }
}

// Rotation about X-axis
void rotateX(Point3D p[], int n, float angle) {
    float rad = angle * 3.14 / 180;
    for (int i = 0; i < n; i++) {
        float y = p[i].y;
        float z = p[i].z;
        p[i].y = y * cos(rad) - z * sin(rad);
        p[i].z = y * sin(rad) + z * cos(rad);
    }
}

// Rotation about Y-axis
void rotateY(Point3D p[], int n, float angle) {
    float rad = angle * 3.14 / 180;
    for (int i = 0; i < n; i++) {
        float x = p[i].x;
        float z = p[i].z;
        p[i].x = x * cos(rad) + z * sin(rad);
        p[i].z = -x * sin(rad) + z * cos(rad);
    }
}

// Rotation about Z-axis
void rotateZ(Point3D p[], int n, float angle) {
    float rad = angle * 3.14 / 180;
    for (int i = 0; i < n; i++) {
        float x = p[i].x;
        float y = p[i].y;
        p[i].x = x * cos(rad) - y * sin(rad);
        p[i].y = x * sin(rad) + y * cos(rad);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    Point3D cube[8] = {
        {100,100,100}, {200,100,100}, {200,200,100}, {100,200,100},
        {120,120,200}, {220,120,200}, {220,220,200}, {120,220,200}
    };

    int choice;
    float tx, ty, tz, sx, sy, sz, angle;

    // Draw original cube
    setcolor(WHITE);
    drawCube(cube);
    outtextxy(10,10,"Original Cube");

    cout << "\n1. Translation\n2. Scaling\n3. Rotation X\n4. Rotation Y\n5. Rotation Z\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            cout << "Enter tx ty tz: ";
            cin >> tx >> ty >> tz;
            translate(cube, 8, tx, ty, tz);
            break;

        case 2:
            cout << "Enter sx sy sz: ";
            cin >> sx >> sy >> sz;
            scale(cube, 8, sx, sy, sz);
            break;

        case 3:
            cout << "Enter angle: ";
            cin >> angle;
            rotateX(cube, 8, angle);
            break;

        case 4:
            cout << "Enter angle: ";
            cin >> angle;
            rotateY(cube, 8, angle);
            break;

        case 5:
            cout << "Enter angle: ";
            cin >> angle;
            rotateZ(cube, 8, angle);
            break;
    }

    setcolor(YELLOW);
    drawCube(cube);
    outtextxy(10,30,"Transformed Cube");

    getch();
    closegraph();
    return 0;
}
