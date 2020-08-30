#pragma once
using namespace std;

class CParametryStatGlob
{
public:
	/**
	*Konstruktor klasy CParametryStatGlob
	*
	*/
	CParametryStatGlob();

	/**
	* Funkcja wypisuje wartosc okreslonego przez parametr 'i' wartosc parametru statycznego globalnego
	*
	* W zaleznosci od wartosci parametru i =:
	* 0. Predkosc symulacji
	* 1. Globalna dlugosc swiatel
	* 3. Osobowe
	* 4. Jednoslady
	* 5. Tiry
	* 6. Dostawcze
	*
	* \param[int] i indeks odpowiedniego parametru globalnego.
	* \return [int] wartosc parametu globlanego
	*/
	float wypisz_wartosc_para_stat_glob(int i);

	/**
	* Funkcja zwiekszajaca wartosc okreslonego przez parametr 'i' wartosc parametru statycznego globalnego
	*
	* W zaleznosci od wartosci parametru i =:
	* 0. Predkosc symulacji
	* 1. Globalna dlugosc swiatel
	*
	* \param[int] i indeks odpowiedniego parametru globalnego.
	*/
	void zwieksz_wartosc_para_stat_glob(int i);

	/**
	* Funkcja zmniejszajaca wartosc okreslonego przez parametr 'i' wartosc parametru statycznego globalnego
	*
	* W zaleznosci od wartosci parametru i =:
	* 0. Predkosc symulacji
	* 1. Globalna dlugosc swiatel
	*
	* \param[int] i indeks odpowiedniego parametru globalnego.
	*/
	void zmniejsz_wartosc_para_stat_glob(int i);

	/**
	* Funkcja zmieniajaca na przeciwna wartosc okreslonego przez parametr 'i' wartosc parametru statycznego globalnego
	*
	* W zaleznosci od wartosci parametru i =:
	* 0. Osobowe
	* 1. Jednoslady
	* 2. Tiry
	* 3. Dostawcze
	*
	* \param[int] i indeks odpowiedniego parametru globalnego.
	*/
	void zaprzeczenie_param(int i);

private:
	float PredkoscSymulacji; /*!< Globalna predkosc symulacji */
	float GlobDlSwiatel; /*!< Globalna dlugosc swialel */
	bool Dostawcze; /*!< Wystepowanie pojazdow dostawczych */
	bool Tiry; /*!< Wystepowanie pojazdow tirow */
	bool Osobowe; /*!< Wystepowanie pojazdow osobowych */
	bool Jednoslady; /*!< Wystepowanie pojazdow jednosladow */
};
