#pragma once
#include "CGObiekt.h"
#include "CCiezarowka.h"
#include <iostream>
#include <fstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class CGCiezarowka : public CGObiekt
{
private:

public:
	/**
	*Konstruktor klasy CGCiezarowka
	*
	*/
	CGCiezarowka(CCiezarowka* Ciezarowka);

	/**
	* Funkcja uzywana do polimorfizmu
	* Funkcja rysujaca obiekty na ekranie
	*
	* \param[RenderWindow] oknoAplikacji  okno aplikacji programu.
	*/
	virtual void rysuj(sf::RenderWindow& oknoAplikacji);

	CCiezarowka* Ciezarowka; /*!< Wskaznik do obiektu ktoremu ta grafika odpowiada */
};