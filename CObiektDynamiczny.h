#pragma once
#include "CTrasa.h"
#include "CParametryDynGlob.h"

using namespace std;

class CObiektDynamiczny
{
protected:
	double X; /*!< Aktulana pozycja obiektu */
	double Y; /*!< Aktulana pozycja obiektu */
	float UtrzyOdle; /*!< Wartosc utrzymywanej przez obiekt obleglosci od innych obiektow */
	float Szybkosc; /*!< Wartosc predkosci poruszanie sie obiektu */
	double poczX; /*!< Poczatkowa pozycja obiektu */
	double poczY; /*!< Poczatkowa pozycja obiektu */
	double celX; /*!< Koncowa pozycja obiektu */
	double celY; /*!< Koncowa pozycja obiektu */
	
public:
	CTrasa Trasa; /*!< Trasa obiektu */
	int NaZakrecie; /*!< W jakiej fazie skretu jest obiekt */
	bool WTrakcieManewru; /*!< Czy obiekt jest w tracjie manewru drogowego */
	int CzasZ; /*!< Jak dlugo pojazd wykonuje manewr */

	/**
	*Konstruktor klasy CObiektDynamiczny
	*
	*/
	CObiektDynamiczny();

	/**
	* Funkcja podajaca aktualna pozycje obiektu
	*
	* \return [double] wartosc pozycji 'x'
	*/
	double podaj_x();

	/**
	* Funkcja podajaca aktualna pozycje obiektu
	*
	* \return [double] wartosc pozycji 'y'
	*/
	double podaj_y();

	/**
	* Funkcja podajaca wartosc utrzymywanej oleglosci
	*
	* \return [double] wartosc utrzymywanej oleglosci
	*/
	float podaj_preferowana_odleglosc();

	/**
	* Funkcja inicjujaca ruch obiektu
	*
	*/
	void ruch();

	/**
	* Funkcja uzywana do polimorfizmu
	* Nadawanie o odswiezanie warosci parametra obiektow dynamicznych
	*
	*/
	virtual void nadaj_wartosc_param(CParametryDynGlob ObDyn) = 0;
};
