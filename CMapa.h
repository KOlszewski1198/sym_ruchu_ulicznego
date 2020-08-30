#pragma once
//#include "CTrasa.h"
//#include "CKolizja.h"

using namespace std;

class CMapa
{
private:
	int Mapa_samoch[13][19]; /*!< Przechowuje informacje o mapie */

public:
	/**
	*Konstruktor klasy CMapa
	*
	*/
	CMapa();

	/**
	* Funkcja tworzaca mape zapisywana w polu Mapa_samoch
	*
	*/
	void tworz_mape();

	/**
	* Funkcja podajaca wartosc odpowiedniej wspolrzednej mapy
	*
	*
	* \param[int] i wspolrzedna x mapy.
	* \param[int] j wspolrzedna y mapy.
	* \return [int] wartosc mapy dla wspolrzednych
	*/
	int podaj_mape(int i, int j);
};
