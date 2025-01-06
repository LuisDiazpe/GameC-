#pragma once
#include "Entidad.h"

class Bala :public Entidad {

	Bala(int x, int y, int dx, int dy) {
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;

		ancho = alto = 7;
	}

};


class Balas {
	vector<Bala*> balas;
public:


	~Balas() {
		for (int i = 0; i < balas.size(); i++) {
			delete balas.at(i);
		}
	};

	void Agregar(Bala* bala) {
		balas.push_back(bala);
	}

	void Eliminar(int pos) {
		balas.erase(balas.begin() + pos);
	}

	int Size() {
		return balas.size();
	}
	Bala* Get(int pos) {
		return balas[pos];
	}
	bool Colision(Rectangle obj) {
		for each (Bala * b in balas)
		{
			if (b->NextArea().IntersectsWith(obj))
				return true;
		}
		return false;
	}

	void Mover(Graphics^ g) {
		for each (Bala* b in balas) {
			b->Mover(g);
		}
	}

	void Mostrar(Graphics^ g, Bitmap^ img) {
		for each (Bala* b in balas) {
			b->Mostrar(g, img);
		}
	}

};