#pragma once
#include "CSkrzyzowanieSwietlne.h"
#include "CGObiekt.h"

class CGSkrzyzowanieSwietlne: public CGObiekt
{
public:
	/**
	*Konstruktor klasy CGSkrzyzowanieSwietlne
	*
	*/
	CGSkrzyzowanieSwietlne(CSkrzyzowanieSwietlne* Skrzyzowanie);

	CSkrzyzowanieSwietlne* Skrzyzowanie;  /*!< Wskaznik do obiektu ktoremu ta grafika odpowiada */

	/**
	* Funkcja uzywana do polimorfizmu
	* Funkcja rysujaca obiekty na ekranie
	*
	* \param[RenderWindow] oknoAplikacji  okno aplikacji programu.
	*/
	virtual void rysuj(sf::RenderWindow& oknoAplikacji);
};
