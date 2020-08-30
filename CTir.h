#pragma once
#include "CObiektDynamiczny.h"
#include "CParametryDynGlob.h"
#include <CMath>


using namespace std;

class CTir : public CObiektDynamiczny
{
private:

public:
	/**
	*Konstruktor klasy CTir
	*
	*/
	CTir(CParametryDynGlob ObDyn, double x, double y, double XX, double YY, CMapa Mapa);

	/**
	* Funkcja uzywana do polimorfizmu
	* Nadawanie o odswiezanie warosci parametra obiektow dynamicznych
	*
	*/
	virtual void nadaj_wartosc_param(CParametryDynGlob ObDyn);
};