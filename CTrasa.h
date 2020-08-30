#pragma once
//#include "CObiektDynamiczny.h"
#include "CMapa.h"
//#include "COsobowy.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class CTrasa
{
public:
	/**
	*Konstruktor klasy CTrasa
	*
	*/
	CTrasa();

	/**
	* Funkcja tworzaca trase dla pokazdu
	*
	* \param[int] X poczatkowa wspolrzedna trasy.
	* \param[int] Y poczatkowa wspolrzedna trasy.
	* \param[int] XX koncowa wspolrzedna trasy.
	* \param[int] YY koncowa wspolrzedna trasy.
	* \param[CMapa] xMapa mapa programu.
	*/
	void tworz_trase(int X, int Y, int XX, int YY, CMapa xMapa);

	/**
	* Funkcja aktulazujaca pozycje pojazdu na mapie
	*
	*/
	void odswierz_pozycje();

	/**
	* Funkcja podajaca nastepny skret pojazdu
	*
	* \return [int] wartosc nastepnego skretu
	*/
	int podaj_nastepny_skret();

	/**
	* Funkcja podajaca wartosc konkretnego skret pojazdu na trasie
	*
	* \param[int] nr numer skretu.
	* \return [int] wartosc skretu
	*/
	int podaj_skret_nr(int nr);

	/**
	* Funkcja podajaca aktualna pozycje pojazdu
	*
	* \return [int] aktualna pozycja
	*/
	int podaj_aktualna_pozycje();

	/**
	* Funkcja ile skretow pojazd musi wykonac na trasie
	*
	* \return [int] ilosc kretow na trasie
	*/
	int podaj_ilosc_skretow();

private:
	int AktualnaPozycja; /*!< Wartosc aktualnej pozycji pojazdu */
	vector <int> Lista_Skretow; /*!< Lista skretow pojazdu na trasie */

};
