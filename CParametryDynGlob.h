#pragma once
using namespace std;

class CParametryDynGlob
{
public:
	/**
	*Konstruktor klasy CParametryDynGlob
	*
	*/
	CParametryDynGlob();

	/**
	* Funkcja wypisuje wartosc okreslonego przez parametr 'i' wartosc parametru dynamicznego globalnego
	*
	* W zaleznosci od wartosci parametru i =:
	* 3. Odleglosc
	* 4. Predkosc pojazdow
	* 6. Nateznienie ruchu
	*
	* \param[int] i indeks odpowiedniego parametru globalnego.
	* \return [int] wartosc parametu globlanego
	*/
	float wypisz_wartosc_para_dyn_glob(int i);

	/**
	* Funkcja zwieksza wartosc okreslonego przez parametr 'i' wartosc parametru dynamicznego globalnego
	*
	* W zaleznosci od wartosci parametru i =:
	* 3. Odleglosc
	* 4. Predkosc pojazdow
	* 6. Nateznienie ruchu
	*
	* \param[int] i indeks odpowiedniego parametru globalnego.
	*/
	void zwieksz_wartosc_para_dyn_glob(int i);

	/**
	* Funkcja zmniejsza wartosc okreslonego przez parametr 'i' wartosc parametru dynamicznego globalnego
	*
	* W zaleznosci od wartosci parametru i =:
	* 3. Odleglosc
	* 4. Predkosc pojazdow
	* 6. Nateznienie ruchu
	*
	* \param[int] i indeks odpowiedniego parametru globalnego.
	*/
	void zmniejsz_wartosc_para_dyn_glob(int i);

private:
	float GlobUtrzyOdl;/*!< Globalne urzymywanie odleglosci miedzy pojazdami */
	float GlobSzybkosc;/*!< Globalna predkosc pojazdow*/
	float GlobNaterzenieRuchu; /*!< Globale natezenie ruchu */
};
