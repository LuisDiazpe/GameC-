#pragma once
#include "Entidad.h"

enum SpriteAliado {

	wCaminarAbajo
};

class Aliado : public Entidad {

	SpriteAliado accion; 

public:
    Aliado(Bitmap^ img) {
		x = rand() % 400;
		y = rand() % 400;
        dx = dy = 0;
        ancho = img->Width / 1;
        alto = img->Height / 1;

        accion = wCaminarAbajo;
		visibilidad = false;
    }

	void Mostrar(Graphics^ g, Bitmap^ img) {
		g->DrawImage(img, Area());
		g->DrawRectangle(Pens::Black, Area());
	}
    


};

class Aliados {
    vector<Aliado*>aliados;

public:
	Aliados(int n, Rectangle obj, Bitmap^ img) {
		for (int i = 0; i < n; i++) {
			Aliado* obs = new Aliado(img);
			if (obs->Area().IntersectsWith(obj) == false && Colision(obs->Area()) == false)
				aliados.push_back(obs);
			else { delete obs; i--; }
		}
	}
	~Aliados() {
		for (int i = 0; i < aliados.size(); i++) {
			delete aliados.at(i);
		}
	}

	bool Colision(Rectangle obj) {
		for each (Aliado * obs in aliados)
		{	
			if (obs->NextArea().IntersectsWith(obj))
				return true;
		}
		return false;
	}

	void Mover(Graphics^ g) {
		for (Aliado* obs : aliados) {
			obs->Mover(g);
		}
	}

	void Mostrar(Graphics^ g, Bitmap^ img) {
		for (Aliado* obs : aliados) {
			obs->Mostrar(g, img);
		}
	}
};
