#pragma once
#include"Entidad.h"

enum SpriteEnemigo {

	eCaminarAbajo
};

class Enemigo : public Entidad {

public:
	SpriteEnemigo accion;
	Enemigo(Bitmap^img) {
		x = rand() % 100;
		y = rand()% 200;

		if (rand() % 2 == 0) {
			//DX
			dx = rand() % 10 - 5;
			if (dx == 0)
				dx = 5;
		}
		else {
			//DY
			dy = rand() % 10 - 5;
			if (dy == 0)
				dy = 5;
		}

		ancho = img->Width/1;
		alto = img->Height/1;
	
		accion = eCaminarAbajo;
	}

	void Mover(Graphics^g) {
		if (!(x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width))
			dx *= -1;

		if (!(y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height))	

			dy *= -1;
			
		if (dx < 0)
			accion = eCaminarAbajo;
		else if (dx > 0)
			accion = eCaminarAbajo;
		else if (dy < 0)
			accion = eCaminarAbajo;
		else if (dy > 0)
			accion = eCaminarAbajo;

		x += dx;
		
		y += dy;
	}

	void Mostrar(Graphics^ g, Bitmap^ img) {
		Rectangle corte = Rectangle(IDx * ancho, accion * alto, ancho, alto);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
		g->DrawRectangle(Pens::Black, Area());

		
	}

	SpriteEnemigo getAccion() { return accion; }
};

class Enemigos {
	Enemigo* enemigo;
	Entidad* entidad;
	vector<Enemigo*>enemigos;

private: 

	bool visibility;

public:
	Enemigos(Bitmap^img, int cant) {
		for (int i = 0; i < cant; i++)
			enemigos.push_back(new Enemigo(img));

		visibility = true;
	}
	~Enemigos() {
		for each (Enemigo * E in enemigos)
			delete E; 
	}
	bool Colision(Rectangle obj) {
		for each (Enemigo * E in enemigos)
			if (E->Area().IntersectsWith(obj))
				return true;

		return false;
	}
	void Mover(Graphics^ g) {
		for each (Enemigo * E in enemigos)
			E->Mover(g);
	}
	void Mostrar(Graphics^ g, Bitmap^ img) {
		for each (Enemigo * E in enemigos)
			E->Mostrar(g, img);
	}
	Rectangle getRectangle() {
		return Rectangle(entidad->getAncho1()*1.0, entidad->getAlto1()*1.0, entidad->getX(), entidad->getY());
	}

	void setVisibility(bool v) { visibility = v; }
	bool getVisibility() { return visibility; }
};