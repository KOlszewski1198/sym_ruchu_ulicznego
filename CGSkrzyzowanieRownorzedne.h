#pragma once
#include "CSkrzyzowanieRownorzedne.h"
#include "CGObiekt.h"

class CGSkrzyzowanieRownorzedne: public CGObiekt
{
public:
	/**
	*Konstruktor klasy CGSkrzyzowanieRownorzedne
	*
	*/
	CGSkrzyzowanieRownorzedne(CSkrzyzowanieRownorzedne* Skrzyzowanie);

	CSkrzyzowanieRownorzedne *Skrzyzowanie;  /*!< Wskaznik do obiektu ktoremu ta grafika odpowiada */

	/**
	* Funkcja uzywana do polimorfizmu
	* Funkcja rysujaca obiekty na ekranie
	*
	* \param[RenderWindow] oknoAplikacji  okno aplikacji programu.
	*/
	virtual void rysuj(sf::RenderWindow& oknoAplikacji);

};
