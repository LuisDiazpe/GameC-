#pragma once
#include <iostream>
using namespace System::Drawing;

class Bullet {
private:
    int x, y;
    int dx, dy;
    int width, height;
    char direction;  // 'W' (arriba), 'S' (abajo), 'A' (izquierda), 'D' (derecha)
    bool visibility;

public:
    Bullet(int x, int y, int w, int h, char d) {
        width = w;
        height = h;
        direction = d;

        // Velocidad de las balas
        int speed = 10;

        // Establecer la velocidad según la dirección
        switch (direction) {
        case 'W':  // Arriba
            dx = 0;
            dy = -speed;  // Mover hacia arriba
            break;
        case 'S':  // Abajo
            dx = 0;
            dy = speed;  // Mover hacia abajo
            break;
        case 'A':  // Izquierda
            dx = -speed;
            dy = 0;
            break;
        case 'D':  // Derecha
            dx = speed;
            dy = 0;
            break;
        default:
            dx = dy = 0;
            break;
        }

        this->x = x;
        this->y = y;
        visibility = true;
    }

    ~Bullet() {}

    void draw(Graphics^ g, Bitmap^ bmp) {
        g->DrawImage(bmp, x, y, width * 0.03, height * 0.03);
    }

    void move() {
        // Mover la bala usando dx y dy directamente
        x += dx;
        y += dy;

    }

    Rectangle getRectangle() {
        return Rectangle(x, y, (int)(width * 0.03), (int)(height * 0.03));
    }

    int getX() { return x; }
    int getXWidth() { return x + (int)(width * 0.03); }
    int getY() { return y; }
    int getYHeight() { return y + (int)(height * 0.03); }

    void setVisibility(bool v) { visibility = v; }
    bool getVisibility() { return visibility; }

    // Verificar colisión con un rectángulo (enemigo)
    bool checkCollision(Rectangle enemy) {
        return getRectangle().IntersectsWith(enemy);
    }
};
