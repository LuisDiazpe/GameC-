#pragma once

#include "Jugador.h"
#include "Obstaculo.h"
#include "Enemigo.h"
#include "Aliado.h"
#include "Bala.h"
#include "class_bullet.h"
#include <vector>
using namespace std;
class Juego {

private: 
	Jugador* jugador;
	Obstaculos* obstaculos;
	vector<Bullet*>Bullets;
	Enemigos* enemigos;
	vector<Enemigos*> arr_enemigos;
	Aliados* aliado;

	//Bitmap^ imgObstaculo;
	//Bitmap^ imgMonachina;
	//Bitmap^ imgEnemigo;
	//Bitmap^ imgAliado;
	//Bitmap^ imgBala;
	//Bitmap^ bmpBullet;

	int cooldown_enemigo;
	int tiempo_juego;
public:
	
	Juego(int v, int e, int t, Bitmap^ bmpObstaculo, Bitmap^ bmpPersonaje, Bitmap^ bmpEnemigo, Bitmap^ bmpAliado, Bitmap^ bmpBullet) {
		jugador = new Jugador(bmpPersonaje, v);
		obstaculos = new Obstaculos(5, jugador->Area(), bmpObstaculo);

		// Aquí asigna la instancia de Enemigos a la variable miembro enemigos
		enemigos = new Enemigos(bmpEnemigo, e);

		aliado = new Aliados(1, jugador->Area(), bmpAliado);

		cooldown_enemigo = 0;
		tiempo_juego = t * 1000;

	}
	~Juego() {
		delete jugador;
		delete obstaculos;
		delete enemigos;
		delete aliado;
	}

	void addBullet(Bullet* b) {
		Bullets.push_back(b);
	}
	

	void MovimientoJugador(bool accion, Keys tecla , Bitmap^ bmpPersonaje, Bitmap^ bmpBullet) {
		int v = 3;
		if (accion == true) {
			if (tecla == Keys::Up || tecla == Keys::W) {
				jugador->SetDY(-v);
				jugador->SetAccion(CaminarArriba);
			}
			else if (tecla == Keys::Down || tecla == Keys::S)
			{
				jugador->SetDY(v);
				jugador->SetAccion(CaminarAbajo);
			}
			else if (tecla == Keys::Left || tecla == Keys::A)
			{
				jugador->SetDX(-v);
				jugador->SetAccion(CaminarIzquierda);
			}
			else if (tecla == Keys::Right || tecla == Keys::D) 
			{
				jugador->SetDX(v);
				jugador->SetAccion(CaminarDerecha);
			}
			else if (tecla == Keys::Space) {
				Bullet* b = new Bullet(jugador->GetX(), jugador->GetY(), bmpBullet->Width, bmpBullet->Height, jugador->GetAccion());
				addBullet(b);
			}
		}

		else {
			if (tecla == Keys::Up)
				jugador->SetDY(0);
			else if (tecla == Keys::Down)
				jugador->SetDY(0);
			else if (tecla == Keys::Left)
				jugador->SetDX(0);
			else if (tecla == Keys::Right)
				jugador->SetDX(0);
		}
	}

	bool Mover(Graphics^ g, Keys uwu, Bitmap^ bmpBullet) {
		// Mover todas las balas automáticamente
		for (int i = 0; i < Bullets.size(); i++) {
			Bullets[i]->move();  // Mover la bala según su dirección
			Bullets[i]->draw(g, bmpBullet);  // Asegurarse de que cada bala se dibuje después de moverse
		}

		// Mover al jugador solo si no colisiona con un obstáculo
		if (!obstaculos->Colision(jugador->NextHitBox())) {
			jugador->Mover(g);  // Mueve el jugador
		}

		// Mover los obstáculos y enemigos
		obstaculos->Mover(g);
		enemigos->Mover(g);

		// Verificar si el jugador colisiona con enemigos
		if (enemigos->Colision(jugador->Area()) && clock() - cooldown_enemigo >= 2300) {
			jugador->SetVidas(-1);
			cooldown_enemigo = clock();
			if (jugador->GetVidas() == 0) {
				return false;  // Fin del juego
			}
		}

		// Continuar el juego
		return true;
	}



	void Mostrar(Graphics^ g, Bitmap^ bmpObstaculo, Bitmap^ bmpPersonaje, Bitmap^ bmpEnemigo, Bitmap^ bmpAliado, Bitmap^ bmpBullet) {

		g->DrawString("Tiempo: " + ((tiempo_juego-clock())/1000), gcnew Font("Arial", 12), Brushes::Black, 0, 20);
		jugador->Mostrar(g, bmpPersonaje);
		obstaculos->Mostrar(g, bmpObstaculo);
		enemigos->Mostrar(g, bmpEnemigo);

		if (enemigos->Colision(jugador->NextArea()) == true) {
			aliado->Mostrar(g, bmpAliado);
		}

		for (int i = 0; i < Bullets.size(); i++) {
			Bullets[i]->draw(g, bmpBullet);
		}

	}

	void collision(Graphics^ g) {
		// Verificar colisiones con los bordes de la pantalla
		for (int i = 0; i < Bullets.size(); i++) {
			if (Bullets[i]->getX() <= 0 || Bullets[i]->getXWidth() >= g->VisibleClipBounds.Width ||
				Bullets[i]->getY() <= 0 || Bullets[i]->getYHeight() >= g->VisibleClipBounds.Height) {
				Bullets[i]->setVisibility(false);
			}
		}

		// Colisión bullet vs enemy
		for (int i = 0; i < arr_enemigos.size(); i++) {
			for (int j = 0; j < Bullets.size(); j++) {
				if (arr_enemigos[i]->getRectangle().IntersectsWith(Bullets[j]->getRectangle())) {
					arr_enemigos[i]->setVisibility(false);
					Bullets[j]->setVisibility(false);
				}
			}
		}

		// Eliminar balas fuera de los límites o invisibles, iterando al revés para evitar problemas de índices
		for (int i = Bullets.size() - 1; i >= 0; i--) {
			if (!Bullets[i]->getVisibility()) {
				Bullets.erase(Bullets.begin() + i);
			}
		}

		// Eliminar enemigos que hayan sido alcanzados, también iterando al revés
		for (int i = arr_enemigos.size() - 1; i >= 0; i--) {
			if (!arr_enemigos[i]->getVisibility()) {
				arr_enemigos.erase(arr_enemigos.begin() + i);
			}
		}
	}


};