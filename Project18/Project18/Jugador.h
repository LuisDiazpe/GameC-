#pragma once

#include "Entidad.h"
#include "class_bullet.h"

enum SpriteMonachina
{
    CaminarAbajo, 
    CaminarIzquierda, 
    CaminarDerecha,
    CaminarArriba
};

class Jugador : public Entidad {

private:
    int vidas; 
    SpriteMonachina accion;
public:
    Jugador(Bitmap^ img, int v) {
        x = 120; y = 120;
        dx = dy = 0;
        ancho = img->Width /4 ;
        alto = img->Height /4;

        accion = CaminarAbajo;


        vidas= v ;
    }

    void SetVidas(int value) {
        vidas += value;
    }

    int GetVidas() {
        return vidas; 
    }

    void SetAccion(SpriteMonachina value) {
        accion = value;
    }

    SpriteMonachina GetAccion() { return accion; }
    
    void Mover(Graphics^ g) {
        if (x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width)
            x += dx;

        if (y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height)
            y += dy;

    }

    void Mostrar(Graphics^ g, Bitmap^ img) {

        g->DrawString("Vidas: "+vidas, gcnew Font("Arial",12),Brushes::Black, 0,0);

        Rectangle corte = Rectangle(IDx*ancho, accion*alto ,ancho,alto);
        g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
        g->DrawRectangle(Pens::Blue, HitBox());
        if (dx != 0 or dy != 0) {
            IDx = (IDx + 1) % 3;
        }
    }

    int GetX() { return x; }
    int GetY() { return y; }

};