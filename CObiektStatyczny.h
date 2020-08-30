#pragma once
#include "CParametryStatGlob.h"

using namespace std;

class CObiektStatyczny
{
protected:
	int X; /*!<Pozycja pozycja obiektu */
	int Y; /*!<Pozycja pozycja obiektu */
	float DlugoscSwiatel; /*!<Warosc dlugosci swiatel obiektu */
	bool Swiatla; /*!<Pozycja swiatel */

public:

	/**
	*Konstruktor klasy CObiektStatyczny
	*
	*/
	CObiektStatyczny();

	/**
	* Funkcja uzywana do polimorfizmu
	* Funkcja odswierzajaca wartosci parametrow po ich zmianie
	*
	* \param[CParametryStatGlob] param  parametry globalne statyczne.
	*/
	virtual void odswiez_param(CParametryStatGlob param) = 0;

	/**
	* Funkcja uzywana do polimorfizmu
	* Funkcja zmieniajaca pozycje swiatel 
	*
	* \param[CParametryStatGlob] param licznik.
	*/
	virtual void zmien_swiatla(int licz) = 0 ;

	/**
	* Funkcja podajaca pozycje obiektu
	*
	* \return [double] wartosc pozycji 'x'
	*/
	int podaj_x();

	/**
	* Funkcja podajaca pozycje obiektu
	*
	* \return [double] wartosc pozycji 'y'
	*/
	int podaj_y();

	/**
	* Funkcja podajaca pozycje swialel
	*
	* \return true jesli pionowe-zielone, false jeslo pionowe-czerwone
	*/
	bool podaj_swiatla();
};


