#pragma once
#include "CGObiekt.h"
#include "CTir.h"
#include <iostream>
#include <fstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class CGTir : public CGObiekt
{
private:

public:
	/**
	*Konstruktor klasy CGTir
	*
	*/
	CGTir(CTir* Tir);

	/**
	* Funkcja uzywana do polimorfizmu
	* Funkcja rysujaca obiekty na ekranie
	*
	* \param[RenderWindow] oknoAplikacji  okno aplikacji programu.
	*/
	virtual void rysuj(sf::RenderWindow& oknoAplikacji);

	CTir* Tir;  /*!< Wskaznik do obiektu ktoremu ta grafika odpowiada */
};