#pragma once
#include "CObiektStatyczny.h"
#include "CParametryStatGlob.h"

class CSkrzyzowanieSwietlne: public CObiektStatyczny
{
public:
	/**
	*Konstruktor klasy CSkrzyzowanieSwietlne
	*
	*/
	CSkrzyzowanieSwietlne(int x, int y, CParametryStatGlob param);

	/**
	* Funkcja uzywana do polimorfizmu
	* Funkcja zmieniajaca pozycje swiatel
	*
	* \param[CParametryStatGlob] param licznik.
	*/
	virtual void zmien_swiatla(int licz);

	/**
	* Funkcja uzywana do polimorfizmu
	* Funkcja odswierzajaca wartosci parametrow po ich zmianie
	*
	* \param[CParametryStatGlob] param  parametry globalne statyczne.
	*/
	virtual void odswiez_param(CParametryStatGlob param);
};
