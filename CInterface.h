#pragma once
#include <vector>
#include "CParametryStatGlob.h"
#include "CParametryDynGlob.h"
#include "CGObiekt.h"
#include "CObiektStatyczny.h"
#include "CObiektDynamiczny.h"
#include "COsobowy.h"
#include "CGOsobowy.h"
#include "CJednoslad.h"
#include "CGJednoslad.h"
#include "CCiezarowka.h"
#include "CGCiezarowka.h"
#include "CTir.h"
#include "CGTir.h"
#include "CDroga.h"
#include "CSkrzyzowanieRownorzedne.h"
#include "CSkrzyzowanieSwietlne.h"
#include "CGDroga.h"
#include "CGSkrzyzowanieRownorzedne.h"
#include "CGSkrzyzowanieSwietlne.h"
#include "CSkrzyzowanieRownorzedne.h"
#include "CSkrzyzowanieSwietlne.h"
#include "CDroga.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;


class CInterface
{
public:
	/**
	*Konstruktor klasy CInterface
	*
	*/
	CInterface();

	/**
	*Dekonstruktor klasy CInterface
	*
	*/
	~CInterface();

	/**
	* Funkcja rysujaca interface uzytkownia.
	* Pobiera obiekt typu sf::RenderWindow reprezentujacy wyswitlane okno aplikacji, 
	*
	* \param[RenderWindow] okno aplikacji.
	*/
	void rysuj_interface(sf::RenderWindow& oknoAplikacji);
	
	/**
	* Funkcja rysujaca wszystkie istniejace obiekty dynamiczne.
	* Pobiera obiekt typu sf::RenderWindow reprezentujacy wyswitlane okno aplikacji,
	*
	* \param[RenderWindow] okno aplikacji.
	*/
	void rysyj_obiekty_dynamiczne(sf::RenderWindow& oknoAplikacji);

	/**
	* Funkcja rysujaca wszystkie istniejace obiekty statyczne.
	* Pobiera obiekt typu sf::RenderWindow reprezentujacy wyswitlane okno aplikacji,
	*
	* \param[RenderWindow] okno aplikacji.
	*/
	void rysuj_obiekty_statyczne(sf::RenderWindow& oknoAplikacji);

	/**
	* Funkcja odpowiedzialna za ciagla prace gry.
	*
	*/
	void loop();

	/**
	* Funkcja informujaca o czy rozgrywka trwa, czy jest zatrzymana.
	*
	* \return true jesli gra dziala, false w przeciwnym wypadku
	*/
	bool czy_uruchomiona();

	/**
	* Funkcja po wywolaniu zatrzymuje i rozpoczyna gre.
	*
	*/
	void start();

	/**
	* Funkcja zwraca czesc calkowita odpowiedniego parametru globalnego w zaleznaosci od wartosci parmetru wejsciowego.
	*
	* W zaleznosci od wartosci parametru i =:
	* 0. Predkosc symulacji
	* 1. Globalna dlugosc swiatel
	* 3. Osobowy
	* 4. Jednoslad
	* 5. Tir
	* 6. Dostawczy
	* 10. Globalne utrzymanie odleglosci
	* 11. Globalna predkosc
	* 13. Globalne natezenie ruchu
	*
	* \param[int] i indeks odpowiedniego parametru globalnego.
	* \return [int] czesc calkowita parametu globlanego
	*/
	int podaj_czesc_calkowita_param(int i);

	/**
	* Funkcja zwraca czesc ulamkowa odpowiedniego parametru globalnego w zaleznaosci od wartosci parmetru wejsciowego.
	*
	* W zaleznosci od wartosci parametru i =:
	* 0. Predkosc symulacji
	* 1. Globalna dlugosc swiatel
	* 3. Osobowy
	* 4. Jednoslad
	* 5. Tir
	* 6. Dostawczy
	* 10. Globalne utrzymanie odleglosci
	* 11. Globalna predkosc
	* 13. Globalne natezenie ruchu
	*
	* \param[int] i indeks odpowiedniego parametru globalnego.
	* \return [int] czesc ulamkowa parametu globlanego
	*/
	int podaj_czesc_ulamkowa_param(int i);

	/**
	* Funkcja inicjuje tworzenie nowego obiektu dynamicznego. W zaleznosci od wartsci parametru "Licznik" moga byc tworzone rozne rodzaje obiektow dynamiczny lub tworzenie obiektu moze zostac zaniechane
	*
	* \param[int] Licznik decyduje o rodzaju tworzonego obiektu
	*/
	void tworz_obiekt_dyn(int Licznik);

	/**
	* Funkcja tworzy wszystkie wykorzystywane w programie obiekty statyczne.
	*/
	void tworz_obiekty_stat();

	/**
	* Funkcja realizuje ruch wszystkich istniejacych obiektow dynamicznych.
	*/
	void ruch_obie_dyn();

	/**
	* Funkcja usuwa obiekty dynamiczne, ktore dotarly do stwojego pierwotnego celu.
	*/
	void usun_obiekty_dynamiczne();

	/**
	* Funkcja inicjujaca zmiane swiatel obiektow statycznych utworzonych w programie.
	*/
	void zmiana_swiatel();

	/**
	* Funkcja rozpatrujaca mozliwosc przepisowego ruchu pojazdu
	*
	* \param[int] n indeks aktualnie rozpatrywanego obiektu dynamicznego.
	* \return true jesli dozwolony, false w przeciwnym wypadku
	*/
	bool czy_ruch_dozwolony(int n);

	/**
	* Funkcja realizujaca procedure konczenia pracy programu. Usuwa wszystkie obiekty statyczne oraz dynamiczne. 
	*
	*/
	void zakonczenie_programu();


private:
	bool Start; /*!< czy gra dziala (1), czy pauza(0) */
	int Wskaznik; /*!<aktualna pozycja kursora interfejsu*/
	int Licznik; /*!<licznik ilosci wywolan glownej petli programu*/
	CMapa Mapa; /*!<mapa symulacji*/
	CParametryStatGlob ParStat; /*!<paramet globalne statyczne symulacji*/
	CParametryDynGlob ParDyn; /*!<paramet globalne dynamiczne symulacji*/
	CGObiekt* GraphOStat[247]; /*!<tablica grafik obiektow statycznych*/
	vector <CGObiekt*> GraphODyn; /*!<lista grafik obiektow dynamicznych*/
	CObiektStatyczny* OStat[247]; /*!<tablica obiektow statycznych*/
	vector <CObiektDynamiczny*> ODyn; /*!<lista obiektow dynamicznych*/
};
