#pragma once
//#include "CInterface.h"
#include "CObiektDynamiczny.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <SFML/Window.hpp>


class CGObiekt
{
private:

public:
	/**
	*Konstruktor klasy CGObiekt
	*
	*/
	CGObiekt();

	/**
	* Funkcja uzywana do polimorfizmu
	* Funkcja rysujaca obiekty na ekranie
	*
	* \param[RenderWindow] oknoAplikacji  okno aplikacji programu.
	*/
	virtual void rysuj(sf::RenderWindow& oknoAplikacji) = 0;
};
