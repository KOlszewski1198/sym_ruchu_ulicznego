#pragma once
#include "CJednoslad.h"
#include "CGObiekt.h"
#include <iostream>
#include <fstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class CGJednoslad : public CGObiekt
{
private:

public:
	/**
	*Konstruktor klasy CGJednoslad
	*
	*/
	CGJednoslad(CJednoslad* Jednoslad);

	/**
	* Funkcja uzywana do polimorfizmu
	* Funkcja rysujaca obiekty na ekranie
	*
	* \param[RenderWindow] oknoAplikacji  okno aplikacji programu.
	*/
	virtual void rysuj(sf::RenderWindow& oknoAplikacji);

	CJednoslad* Jednoslad;  /*!< Wskaznik do obiektu ktoremu ta grafika odpowiada */
};