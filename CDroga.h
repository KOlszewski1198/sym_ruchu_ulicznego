#pragma once
#include "CObiektStatyczny.h"
#include "CParametryStatGlob.h"

class CDroga: public CObiektStatyczny
{
private:
	bool Pion; /*!< Czy droga biegnie w pionie czy w poziomie */
public:
	/**
	*Konstruktor klasy CDroga
	*
	*/
	CDroga(int x, int y, CParametryStatGlob param, bool Pion);

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

	/**
	* Funkcja wypisujaca typ drogi
	*
	* \return true jesli pionowa, false jesli pozioma
	*/
	bool czy_droga_pionowa();
};
