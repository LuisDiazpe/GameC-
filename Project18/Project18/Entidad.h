#pragma once

#include "Dependencias.h"

class Entidad
{
protected:
    int x, y;
    int dx, dy;
    int ancho, alto;
    int IDx;

    bool visibilidad;
public:
    Entidad() {
        x = y = 0;
        dx = dy = 0;
        ancho = alto = 0;
        IDx = 0;
    }


    void SetDX(int value) {
        dx = value;
    }
    void SetDY(int value) {
        dy = value;
    }
    Rectangle Area() {
        return Rectangle(x, y, ancho, alto);
    }
    Rectangle NextArea() {
        return Rectangle(x + dx, y + dy, ancho, alto);
    }

    Rectangle HitBox() {
        return Rectangle(x + ancho / 4, y+ alto/3.4, ancho/2, alto*2/3);
    }
    Rectangle NextHitBox() {
        return Rectangle(x + ancho / 4+dx, y + alto / 3.4+ dy, ancho / 2, alto * 2 / 3);
    }

    virtual void Mover(Graphics^ g) {
        x += dx;
        y += dy;
    }
    virtual void Mostrar(Graphics^ g,Bitmap^ img) {
        g->FillRectangle(Brushes::Black, Area());
    }

    int getIdx() { return IDx; }
    int getAncho1() { return ancho; }
    int getAlto1() { return alto; }
    int getX() { return x; }
    int getY() { return y; }

};