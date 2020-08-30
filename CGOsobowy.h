#pragma once
#include "CGObiekt.h"
#include "COsobowy.h"
#include <iostream>
#include <fstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class CGOsobowy : public CGObiekt
{
private:
	
public:
	/**
	*Konstruktor klasy CGOsobowy
	*
	*/
	CGOsobowy(COsobowy *Osobowy);

	/**
	* Funkcja uzywana do polimorfizmu
	* Funkcja rysujaca obiekty na ekranie
	*
	* \param[RenderWindow] oknoAplikacji  okno aplikacji programu.
	*/
	virtual void rysuj(sf::RenderWindow& oknoAplikacji);

	COsobowy* Osobowy;  /*!< Wskaznik do obiektu ktoremu ta grafika odpowiada */
};