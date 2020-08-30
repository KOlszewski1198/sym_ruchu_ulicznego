#pragma once
#include "CDroga.h"
#include "CGObiekt.h"

class CGDroga: public CGObiekt
{
public:
	/**
	*Konstruktor klasy CGDroga
	*
	*/
	CGDroga(CDroga* Droga);

	CDroga* Droga;  /*!< Wskaznik do obiektu ktoremu ta grafika odpowiada */

	/**
	* Funkcja uzywana do polimorfizmu
	* Funkcja rysujaca obiekty na ekranie
	*
	* \param[RenderWindow] oknoAplikacji  okno aplikacji programu.
	*/
	virtual void rysuj(sf::RenderWindow& oknoAplikacji);

};
