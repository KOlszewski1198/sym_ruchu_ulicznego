#pragma once
#include "CInterface.h"

CInterface::CInterface()
{
     Wskaznik = 0;
     Start = 0;
     Licznik = 0;
    tworz_obiekty_stat();
}

CInterface::~CInterface()
{
    zakonczenie_programu();
}

void CInterface::loop()
{
    srand(time(0));
    sf::RenderWindow oknoAplikacji(sf::VideoMode(), "PJC - Ruch uliczny", sf::Style::Fullscreen);
    
    while (oknoAplikacji.isOpen())
    {
        Licznik++;
        if (Licznik == 2000000000) Licznik = 0;

        sf::Event zdarzenie;

        //Obs³uga Przerwan
        while (oknoAplikacji.pollEvent(zdarzenie))
        {
            if (zdarzenie.type == sf::Event::KeyPressed)
            {
                if (zdarzenie.key.code == sf::Keyboard::Escape)
                {
                    oknoAplikacji.close();
                }

                if (zdarzenie.key.code == sf::Keyboard::Up)
                {
                    CInterface::Wskaznik++;
                    if (CInterface::Wskaznik == 15)
                    {
                        CInterface::Wskaznik = 0;
                    }
                }

                if (zdarzenie.key.code == sf::Keyboard::Down)
                {
                    CInterface::Wskaznik--;
                    if (CInterface::Wskaznik == -1)
                    {
                        CInterface::Wskaznik = 14;
                    }
                }

                if (zdarzenie.key.code == sf::Keyboard::Enter)
                {
                    switch (Wskaznik)
                    {
                    case 0:
                        CInterface::start();
                        break;
                    case 1:
                        ParStat.zwieksz_wartosc_para_stat_glob(0);
                        break;
                    case 2:
                        ParStat.zmniejsz_wartosc_para_stat_glob(0);
                        break;
                    case 3:
                        ParDyn.zwieksz_wartosc_para_dyn_glob(6);
                        break;
                    case 4:
                        ParDyn.zmniejsz_wartosc_para_dyn_glob(6);
                        break;
                    case 5:
                        ParDyn.zwieksz_wartosc_para_dyn_glob(4);
                        break;
                    case 6:
                        ParDyn.zmniejsz_wartosc_para_dyn_glob(4);
                        break;
                    case 9:
                        ParDyn.zwieksz_wartosc_para_dyn_glob(3);
                        break;
                    case 10:
                        ParDyn.zmniejsz_wartosc_para_dyn_glob(3);
                        break;
                    case 11:
                        ParStat.zaprzeczenie_param(2);
                        break;
                    case 12:
                        ParStat.zaprzeczenie_param(3);
                        break;
                    case 13:
                        ParStat.zaprzeczenie_param(0);
                        break;
                    case 14:
                        ParStat.zaprzeczenie_param(1);
                        break;
                    case 7:
                        ParStat.zwieksz_wartosc_para_stat_glob(1);
                        break;
                    case 8:
                        ParStat.zmniejsz_wartosc_para_stat_glob(1);
                        break;
                    }

                    for (int i = 0; i < 247;i++)
                    {
                        if (OStat[i] != 0)
                        OStat[i]->odswiez_param(ParStat);
                    }
                    for (int i = 0; i <  ODyn.size();i++)
                    {
                        ODyn[i]->nadaj_wartosc_param(ParDyn);
                    }
                }
            }
        }

        //Akcje dynamiczne obiektów 
        if ( czy_uruchomiona() == 1) 
        {
            if (ParStat.wypisz_wartosc_para_stat_glob(0) >= 0.9)//zmiana szybkosci symulacji
            {
                for (int i = 10; i <= ParStat.wypisz_wartosc_para_stat_glob(0) * 10; i ++)
                {
					 tworz_obiekt_dyn(Licznik);
					 ruch_obie_dyn();
					 zmiana_swiatel();
                    if(i>10) Licznik++;
                }
            }
            else 
                if(Licznik % int(11- ParStat.wypisz_wartosc_para_stat_glob(0) *10))
				{
					 tworz_obiekt_dyn(Licznik);
					 ruch_obie_dyn();
					 zmiana_swiatel();
				}
        }

        usun_obiekty_dynamiczne();

        rysuj_interface(oknoAplikacji); 
        rysuj_obiekty_statyczne(oknoAplikacji);
        rysyj_obiekty_dynamiczne(oknoAplikacji);
     
        oknoAplikacji.display();
    }
}

void CInterface::rysuj_interface(sf::RenderWindow &oknoAplikacji)
{

    sf::Texture tekstura;
    tekstura.loadFromFile("zasoby/D³ugoœæ Swiate³.jpg");
    sf::Sprite obrazek;
    obrazek.setTexture(tekstura);
    obrazek.scale(1, 1);
    obrazek.setPosition(sf::Vector2f(-48.f, 740.f));

    sf::Texture tekstura3;
    tekstura3.loadFromFile("zasoby/Tiry.jpg");
    sf::Sprite obrazek3;
    obrazek3.setTexture(tekstura3);
    obrazek3.scale(0.7, 0.7);
    obrazek3.setPosition(sf::Vector2f(0.f, 500.f));

    sf::Texture tekstura4;
    tekstura4.loadFromFile("zasoby/Dostawcze.jpg");
    sf::Sprite obrazek4;
    obrazek4.setTexture(tekstura4);
    obrazek4.scale(0.7, 0.7);
    obrazek4.setPosition(sf::Vector2f(100.f, 500.f));

    sf::Texture tekstura5;
    tekstura5.loadFromFile("zasoby/Osobowe.jpg");
    sf::Sprite obrazek5;
    obrazek5.setTexture(tekstura5);
    obrazek5.scale(0.7, 0.7);
    obrazek5.setPosition(sf::Vector2f(0.f, 580.f));

    sf::Texture tekstura6;
    tekstura6.loadFromFile("zasoby/Jednoslady.jpg");
    sf::Sprite obrazek6;
    obrazek6.setTexture(tekstura6);
    obrazek6.scale(0.7, 0.7);
    obrazek6.setPosition(sf::Vector2f(100.f, 580.f));

    sf::Texture tekstura10;
    tekstura10.loadFromFile("zasoby/Utrzymanie odleg³oœci.jpg");
    sf::Sprite obrazek10;
    obrazek10.setTexture(tekstura10);
    obrazek10.scale(1, 1);
    obrazek10.setPosition(sf::Vector2f(0.f, 660.f));

    sf::Texture tekstura11;
    tekstura11.loadFromFile("zasoby/Szybkoœæ.jpg");
    sf::Sprite obrazek11;
    obrazek11.setTexture(tekstura11);
    obrazek11.scale(1, 1);
    obrazek11.setPosition(sf::Vector2f(0.f, 820.f));

    sf::Texture tekstura13;
    tekstura13.loadFromFile("zasoby/Natê¿enie Ruchu.jpg");
    sf::Sprite obrazek13;
    obrazek13.setTexture(tekstura13);
    obrazek13.scale(1, 1);
    obrazek13.setPosition(sf::Vector2f(0.f, 900.f));

    sf::Texture tekstura15;
    tekstura15.loadFromFile("zasoby/Pozioma.png");
    sf::Sprite obrazek15;
    obrazek15.setTexture(tekstura15);
    obrazek15.scale(1, 1);
    obrazek15.setPosition(sf::Vector2f(0.f, 650.f));

    sf::Texture tekstura150;
    tekstura150.loadFromFile("zasoby/Pozioma.png");
    sf::Sprite obrazek150;
    obrazek150.setTexture(tekstura15);
    obrazek150.scale(1, 1);
    obrazek150.setPosition(sf::Vector2f(0.f, 490.f));

    sf::Texture tekstura16;
    tekstura16.loadFromFile("zasoby/Pionowa.png");
    sf::Sprite obrazek16;
    obrazek16.setTexture(tekstura16);
    obrazek16.scale(1, 1);
    obrazek16.setPosition(sf::Vector2f(230.f, 0.f));

    sf::Texture tekstura17;
    tekstura17.loadFromFile("zasoby/Start_Stop.jpg");
    sf::Sprite obrazek17;
    obrazek17.setTexture(tekstura17);
    obrazek17.scale(1, 1);
    obrazek17.setPosition(sf::Vector2f(0.f, 1050.f));

    sf::Texture tekstura18;
    tekstura18.loadFromFile("zasoby/Prêdkoœæ Symulacji.jpg");
    sf::Sprite obrazek18;
    obrazek18.setTexture(tekstura18);
    obrazek18.scale(1, 1);
    obrazek18.setPosition(sf::Vector2f(0.f, 980.f));

    sf::Texture tekstura19;
    tekstura19.loadFromFile("zasoby/Pozioma.png");
    sf::Sprite obrazek19;
    obrazek19.setTexture(tekstura19);
    obrazek19.scale(1, 1);
    obrazek19.setPosition(sf::Vector2f(0.f, 970.f));

    sf::Texture tekstura20;
    tekstura20.loadFromFile("zasoby/Plus0.png");
    sf::Sprite obrazek20;
    obrazek20.setTexture(tekstura20);
    obrazek20.scale(0.2, 0.2);
    obrazek20.setPosition(sf::Vector2f(3.f,780.f));
    sf::Sprite obrazek22;
    obrazek22.setTexture(tekstura20);
    obrazek22.scale(0.2, 0.2);
    obrazek22.setPosition(sf::Vector2f(3.f, 540.f));
    sf::Sprite obrazek23;
    obrazek23.setTexture(tekstura20);
    obrazek23.scale(0.2, 0.2);
    obrazek23.setPosition(sf::Vector2f(103.f, 540.f));
    sf::Sprite obrazek24;
    obrazek24.setTexture(tekstura20);
    obrazek24.scale(0.2, 0.2);
    obrazek24.setPosition(sf::Vector2f(3.f, 620.f));
    sf::Sprite obrazek25;
    obrazek25.setTexture(tekstura20);
    obrazek25.scale(0.2, 0.2);
    obrazek25.setPosition(sf::Vector2f(103.f, 620.f));
    sf::Sprite obrazek29;
    obrazek29.setTexture(tekstura20);
    obrazek29.scale(0.2, 0.2);
    obrazek29.setPosition(sf::Vector2f(3.f, 700.f));
    sf::Sprite obrazek30;
    obrazek30.setTexture(tekstura20);
    obrazek30.scale(0.2, 0.2);
    obrazek30.setPosition(sf::Vector2f(3.f, 860.f));
    sf::Sprite obrazek32;
    obrazek32.setTexture(tekstura20);
    obrazek32.scale(0.2, 0.2);
    obrazek32.setPosition(sf::Vector2f(3.f, 940.f));
    sf::Sprite obrazek34;
    obrazek34.setTexture(tekstura20);
    obrazek34.scale(0.2, 0.2);
    obrazek34.setPosition(sf::Vector2f(3.f, 1015.f));
    sf::Sprite obrazek35;
    obrazek35.setTexture(tekstura20);
    obrazek35.scale(0.2, 0.2);
    obrazek35.setPosition(sf::Vector2f(110.f, 1052.f));

    sf::Texture tekstura21;
    tekstura21.loadFromFile("zasoby/Minus0.png");
    sf::Sprite obrazek36;
    obrazek36.setTexture(tekstura21);
    obrazek36.scale(0.2, 0.2);
    obrazek36.setPosition(sf::Vector2f(25.f,780.f));
    sf::Sprite obrazek38;
    obrazek38.setTexture(tekstura21);
    obrazek38.scale(0.2, 0.2);
    obrazek38.setPosition(sf::Vector2f(25.f, 540.f));
    sf::Sprite obrazek39;
    obrazek39.setTexture(tekstura21);
    obrazek39.scale(0.2, 0.2);
    obrazek39.setPosition(sf::Vector2f(125.f, 540.f));
    sf::Sprite obrazek40;
    obrazek40.setTexture(tekstura21);
    obrazek40.scale(0.2, 0.2);
    obrazek40.setPosition(sf::Vector2f(25.f, 620.f));
    sf::Sprite obrazek41;
    obrazek41.setTexture(tekstura21);
    obrazek41.scale(0.2, 0.2);
    obrazek41.setPosition(sf::Vector2f(125.f, 620.f));
    sf::Sprite obrazek45;
    obrazek45.setTexture(tekstura21);
    obrazek45.scale(0.2, 0.2);
    obrazek45.setPosition(sf::Vector2f(25.f, 700.f));
    sf::Sprite obrazek46;
    obrazek46.setTexture(tekstura21);
    obrazek46.scale(0.2, 0.2);
    obrazek46.setPosition(sf::Vector2f(25.f, 860.f));
    sf::Sprite obrazek48;
    obrazek48.setTexture(tekstura21);
    obrazek48.scale(0.2, 0.2);
    obrazek48.setPosition(sf::Vector2f(25.f, 940.f));
    sf::Sprite obrazek50;
    obrazek50.setTexture(tekstura21);
    obrazek50.scale(0.2, 0.2);
    obrazek50.setPosition(sf::Vector2f(25.f, 1015.f));
    sf::Sprite obrazek51;
    obrazek51.setTexture(tekstura21);
    obrazek51.scale(0.2, 0.2);
    obrazek51.setPosition(sf::Vector2f(132.f, 1052.f));

    sf::Texture tekstura22;
    tekstura22.loadFromFile("zasoby/Czerwony.png");
    sf::Texture tekstura25;
    tekstura25.loadFromFile("zasoby/Zielony.png");
    sf::Sprite obrazek52;
    if (ParStat.wypisz_wartosc_para_stat_glob(3)==0)
    {
        obrazek52.setTexture(tekstura22);
    }
    else
    {
        obrazek52.setTexture(tekstura25);
    }
    obrazek52.scale(0.7, 0.7);
    obrazek52.setPosition(sf::Vector2f(32.f, 540.f));

    sf::Sprite obrazek53;
    if (ParStat.wypisz_wartosc_para_stat_glob(4) == 0)
    {
        obrazek53.setTexture(tekstura22);
    }
    else
    {
        obrazek53.setTexture(tekstura25);
    }
    obrazek53.scale(0.7, 0.7);
    obrazek53.setPosition(sf::Vector2f(132.f, 540.f));

    sf::Sprite obrazek54;
    if (ParStat.wypisz_wartosc_para_stat_glob(5) == 0)
    {
        obrazek54.setTexture(tekstura22);
    }
    else 
    {
        obrazek54.setTexture(tekstura25);
    }
    obrazek54.scale(0.7, 0.7);
    obrazek54.setPosition(sf::Vector2f(32.f, 620.f));

    sf::Sprite obrazek55;
    if (ParStat.wypisz_wartosc_para_stat_glob(6) == 0)
    {
        obrazek55.setTexture(tekstura22);
    }
    else
    {
        obrazek55.setTexture(tekstura25);
    }
    obrazek55.scale(0.7, 0.7);
    obrazek55.setPosition(sf::Vector2f(132.f, 620.f));

    sf::Sprite obrazek56;
    if (Start==false)
    {
        obrazek56.setTexture(tekstura22);
    }
    else 
    {
        obrazek56.setTexture(tekstura25);
    }
    obrazek56.scale(0.7, 0.7);
    obrazek56.setPosition(sf::Vector2f(139.f, 1052.f));


    oknoAplikacji.clear(sf::Color(255, 255, 255));

    oknoAplikacji.draw(obrazek);
    oknoAplikacji.draw(obrazek3);
    oknoAplikacji.draw(obrazek4);
    oknoAplikacji.draw(obrazek5);
    oknoAplikacji.draw(obrazek6);
    oknoAplikacji.draw(obrazek10);
    oknoAplikacji.draw(obrazek11);
    oknoAplikacji.draw(obrazek13);
    oknoAplikacji.draw(obrazek15);
    oknoAplikacji.draw(obrazek16);
    oknoAplikacji.draw(obrazek17);
    oknoAplikacji.draw(obrazek18);
    oknoAplikacji.draw(obrazek19);
    oknoAplikacji.draw(obrazek20);
    oknoAplikacji.draw(obrazek22);
    oknoAplikacji.draw(obrazek23);
    oknoAplikacji.draw(obrazek24);
    oknoAplikacji.draw(obrazek25);
    oknoAplikacji.draw(obrazek29);
    oknoAplikacji.draw(obrazek30);
    oknoAplikacji.draw(obrazek32);
    oknoAplikacji.draw(obrazek34);
    oknoAplikacji.draw(obrazek35);
    oknoAplikacji.draw(obrazek36);
    oknoAplikacji.draw(obrazek45);
    oknoAplikacji.draw(obrazek46);
    oknoAplikacji.draw(obrazek48);
    oknoAplikacji.draw(obrazek50);
    oknoAplikacji.draw(obrazek52);
    oknoAplikacji.draw(obrazek53);
    oknoAplikacji.draw(obrazek54);
    oknoAplikacji.draw(obrazek55);
    oknoAplikacji.draw(obrazek56);
    oknoAplikacji.draw(obrazek150);

    sf::Texture tekstura23;
    tekstura23.loadFromFile("zasoby/Plus1.png");
    sf::Texture tekstura24;
    tekstura24.loadFromFile("zasoby/Minus1.png");
    sf::Sprite obrazek57;

    switch (Wskaznik)
    {
    case 0:
        obrazek57.setTexture(tekstura23);
        obrazek57.scale(0.2, 0.2);
        obrazek57.setPosition(sf::Vector2f(110.f, 1052.f));
        break;
    case 1:
        obrazek57.setTexture(tekstura23);
        obrazek57.scale(0.2, 0.2);
        obrazek57.setPosition(sf::Vector2f(3.f, 1015.f));
        break;
    case 2:
        obrazek57.setTexture(tekstura24);
        obrazek57.scale(0.2, 0.2);
        obrazek57.setPosition(sf::Vector2f(25.f, 1015.f));
        break;
    case 3:
        obrazek57.setTexture(tekstura23);
        obrazek57.scale(0.2, 0.2);
        obrazek57.setPosition(sf::Vector2f(3.f, 940.f));
        break;
    case 4:
        obrazek57.setTexture(tekstura24);
        obrazek57.scale(0.2, 0.2);
        obrazek57.setPosition(sf::Vector2f(25.f, 940.f));
        break;
    case 5:
        obrazek57.setTexture(tekstura23);
        obrazek57.scale(0.2, 0.2);
        obrazek57.setPosition(sf::Vector2f(3.f, 860.f));
        break;
    case 6:
        obrazek57.setTexture(tekstura24);
        obrazek57.scale(0.2, 0.2);
        obrazek57.setPosition(sf::Vector2f(25.f, 860.f));
        break;
    case 9:
        obrazek57.setTexture(tekstura23);
        obrazek57.scale(0.2, 0.2);
        obrazek57.setPosition(sf::Vector2f(3.f, 700.f));
        break;
    case 10:
        obrazek57.setTexture(tekstura24);
        obrazek57.scale(0.2, 0.2);
        obrazek57.setPosition(sf::Vector2f(25.f, 700.f));
        break;
    case 11:
        obrazek57.setTexture(tekstura23);
        obrazek57.scale(0.2, 0.2);
        obrazek57.setPosition(sf::Vector2f(3.f, 620.f));
        break;
    case 12:
        obrazek57.setTexture(tekstura23);
        obrazek57.scale(0.2, 0.2);
        obrazek57.setPosition(sf::Vector2f(103.f, 620.f));
        break;
    case 13:
        obrazek57.setTexture(tekstura23);
        obrazek57.scale(0.2, 0.2);
        obrazek57.setPosition(sf::Vector2f(3.f, 540.f));
        break;
    case 14:
        obrazek57.setTexture(tekstura23);
        obrazek57.scale(0.2, 0.2);
        obrazek57.setPosition(sf::Vector2f(103.f, 540.f));
        break;
    case 7:
        obrazek57.setTexture(tekstura23);
        obrazek57.scale(0.2, 0.2);
        obrazek57.setPosition(sf::Vector2f(3.f,780.f));
        break;
    case 8:
        obrazek57.setTexture(tekstura24);
        obrazek57.scale(0.2, 0.2);
        obrazek57.setPosition(sf::Vector2f(25.f,780.f));
        break;
    }

    oknoAplikacji.draw(obrazek57); 

    sf::Texture tekstura30;
    tekstura30.loadFromFile("zasoby/0.jpg");
    sf::Texture tekstura31;
    tekstura31.loadFromFile("zasoby/1.jpg");
    sf::Texture tekstura32;
    tekstura32.loadFromFile("zasoby/2.jpg");
    sf::Texture tekstura33;
    tekstura33.loadFromFile("zasoby/3.jpg");
    sf::Texture tekstura34;
    tekstura34.loadFromFile("zasoby/4.jpg");
    sf::Texture tekstura35;
    tekstura35.loadFromFile("zasoby/5.jpg");
    sf::Texture tekstura36;
    tekstura36.loadFromFile("zasoby/6.jpg");
    sf::Texture tekstura37;
    tekstura37.loadFromFile("zasoby/7.jpg");
    sf::Texture tekstura38;
    tekstura38.loadFromFile("zasoby/8.jpg");
    sf::Texture tekstura39;
    tekstura39.loadFromFile("zasoby/9.jpg");
    sf::Texture tekstura40;
    tekstura40.loadFromFile("zasoby/Kropka.jpg");

    sf::Sprite obrazek58;
    sf::Sprite obrazek59;
    sf::Sprite obrazek60;
    sf::Sprite obrazek61;
    sf::Sprite obrazek62;
    sf::Sprite obrazek63;
    sf::Sprite obrazek64;
    sf::Sprite obrazek65;
    sf::Sprite obrazek66;
    sf::Sprite obrazek67;
    sf::Sprite obrazek68;
    sf::Sprite pom1;

    sf::Sprite obrazek72;
    sf::Sprite obrazek73;
    sf::Sprite obrazek74;
    sf::Sprite obrazek75;
    sf::Sprite obrazek76;
    sf::Sprite obrazek77;
    sf::Sprite obrazek78;
    sf::Sprite obrazek79;
    sf::Sprite obrazek80;
    sf::Sprite obrazek81;
    sf::Sprite obrazek82;
    sf::Sprite pom2;

    sf::Sprite obrazek86;
    sf::Sprite obrazek87;
    sf::Sprite obrazek88;
    sf::Sprite obrazek89;
    sf::Sprite obrazek90;
    sf::Sprite obrazek91;
    sf::Sprite obrazek92;
    sf::Sprite obrazek93;
    sf::Sprite obrazek94;
    sf::Sprite obrazek95;
    sf::Sprite obrazek96;


    for (int i = 0; i <= 14; i++)
    {
        switch ( podaj_czesc_calkowita_param(i))
        {
        case 0:
            pom1.setTexture(tekstura30);
            break;
        case 1:
            pom1.setTexture(tekstura31);
            break;
        case 2:
            pom1.setTexture(tekstura32);
            break;
        case 3:
            pom1.setTexture(tekstura33);
            break;
        case 4:
            pom1.setTexture(tekstura34);
            break;
        case 5:
            pom1.setTexture(tekstura35);
            break;
        case 6:
            pom1.setTexture(tekstura36);
            break;
        case 7:
            pom1.setTexture(tekstura37);
            break;
        case 8:
            pom1.setTexture(tekstura38);
            break;
        case 9:
            pom1.setTexture(tekstura39);
            break;
        }

        switch ( podaj_czesc_ulamkowa_param(i))
        {
        case 0:
            pom2.setTexture(tekstura30);
            break;
        case 1:
            pom2.setTexture(tekstura31);
            break;
        case 2:
            pom2.setTexture(tekstura32);
            break;
        case 3:
            pom2.setTexture(tekstura33);
            break;
        case 4:
            pom2.setTexture(tekstura34);
            break;
        case 5:
            pom2.setTexture(tekstura35);
            break;
        case 6:
            pom2.setTexture(tekstura36);
            break;
        case 7:
            pom2.setTexture(tekstura37);
            break;
        case 8:
            pom2.setTexture(tekstura38);
            break;
        case 9:
            pom2.setTexture(tekstura39);
            break;
        }

        switch (i)
        {
        case 0:
            obrazek58 = pom1;
            obrazek72 = pom2;
            break;
        case 1:
            obrazek59 = pom1;
            obrazek73 = pom2;
            break;
        case 2:
            obrazek60 = pom1;
            obrazek74 = pom2;
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            obrazek64 = pom1;
            obrazek78 = pom2;
            break;
        case 11:
            obrazek65 = pom1;
            obrazek79 = pom2;
            break;
        case 12:
            break;
        case 13:
            obrazek67 = pom1;
            obrazek81 = pom2;
            break;
        case 14:
            break;
        }
    }

    obrazek58.setPosition(sf::Vector2f(70.f, 1015.f));
    obrazek86.setTexture(tekstura40);
    obrazek86.setPosition(sf::Vector2f(85.f, 1015.f));
    obrazek72.setPosition(sf::Vector2f(95.f, 1015.f));

    obrazek59.setPosition(sf::Vector2f(70.f,780.f));
    obrazek87.setTexture(tekstura40);
    obrazek87.setPosition(sf::Vector2f(85.f,780.f));
    obrazek73.setPosition(sf::Vector2f(95.f,780.f));

    obrazek64.setPosition(sf::Vector2f(70.f, 700.f));
    obrazek92.setTexture(tekstura40);
    obrazek92.setPosition(sf::Vector2f(85.f, 700.f));
    obrazek78.setPosition(sf::Vector2f(95.f, 700.f));

    obrazek65.setPosition(sf::Vector2f(70.f, 860.f));
    obrazek93.setTexture(tekstura40);
    obrazek93.setPosition(sf::Vector2f(85.f, 860.f));
    obrazek79.setPosition(sf::Vector2f(95.f, 860.f));

    obrazek67.setPosition(sf::Vector2f(70.f, 940.f));
    obrazek95.setTexture(tekstura40);
    obrazek95.setPosition(sf::Vector2f(85.f, 940.f));
    obrazek81.setPosition(sf::Vector2f(95.f, 940.f));

    oknoAplikacji.draw(obrazek58);//-
    oknoAplikacji.draw(obrazek86);//-
    oknoAplikacji.draw(obrazek72);//-
    oknoAplikacji.draw(obrazek59);//-
    oknoAplikacji.draw(obrazek87);//-
    oknoAplikacji.draw(obrazek73);//-
    oknoAplikacji.draw(obrazek64);//-
    oknoAplikacji.draw(obrazek92);//-
    oknoAplikacji.draw(obrazek78);//-
    oknoAplikacji.draw(obrazek65);//-
    oknoAplikacji.draw(obrazek93);//-
    oknoAplikacji.draw(obrazek79);//-
    oknoAplikacji.draw(obrazek67);//-
    oknoAplikacji.draw(obrazek95);//-
    oknoAplikacji.draw(obrazek81);//-
}

void CInterface::rysyj_obiekty_dynamiczne(sf::RenderWindow& oknoAplikacji)
{
    for (int i = 0; i <  GraphODyn.size();i++)
    {
        GraphODyn[i]->rysuj(oknoAplikacji);
    }
}

void CInterface::rysuj_obiekty_statyczne(sf::RenderWindow& oknoAplikacji)
{
    for (int i = 0; i < 247 ;i++)
    {
        if(OStat[i]!=0)
        GraphOStat[i]->rysuj(oknoAplikacji);
    }
}

void CInterface::start()
{
    if ( Start == 0)
         Start = 1;
    else
         Start = 0;
}

int CInterface::podaj_czesc_calkowita_param(int i)
{
    int pom1;
    switch (i)
    {
        case 0:
            pom1 =  ParStat.wypisz_wartosc_para_stat_glob(0);
            pom1 = floor(pom1);
            return pom1;
            break;
        case 1:
            pom1 =  ParStat.wypisz_wartosc_para_stat_glob(1);
            pom1 = floor(pom1);
            return pom1;
            break;
        case 2:
            pom1 =  ParStat.wypisz_wartosc_para_stat_glob(2);
            pom1 = floor(pom1);
            return pom1;
            break;
        case 3:
            pom1 =  ParStat.wypisz_wartosc_para_stat_glob(3);
            pom1 = floor(pom1);
            return pom1;
            break;
        case 4:
            pom1 =  ParStat.wypisz_wartosc_para_stat_glob(4);
            pom1 = floor(pom1);
            return pom1;
            break;
        case 5:
            pom1 =  ParStat.wypisz_wartosc_para_stat_glob(5);
            pom1 = floor(pom1);
            return pom1;
            break;
        case 6:
            pom1 =  ParStat.wypisz_wartosc_para_stat_glob(6);
            pom1 = floor(pom1);
            return pom1;
            break;
        case 7:
            pom1 =  ParDyn.wypisz_wartosc_para_dyn_glob(0);
            pom1 = floor(pom1);
            return pom1;
            break;
        case 8:
            pom1 =  ParDyn.wypisz_wartosc_para_dyn_glob(1);
            pom1 = floor(pom1);
            return pom1;
            break;
        case 9:
            pom1 =  ParDyn.wypisz_wartosc_para_dyn_glob(2);
            pom1 = floor(pom1);
            return pom1;
            break;
        case 10:
            pom1 =  ParDyn.wypisz_wartosc_para_dyn_glob(3);
            pom1 = floor(pom1);
            return pom1;
            break;
        case 11:
            pom1 =  ParDyn.wypisz_wartosc_para_dyn_glob(4);
            pom1 = floor(pom1);
            return pom1;
            break;
        case 12:
            pom1 =  ParDyn.wypisz_wartosc_para_dyn_glob(5);
            pom1 = floor(pom1);
            return pom1;
            break;
        case 13:
            pom1 =  ParDyn.wypisz_wartosc_para_dyn_glob(6);
            pom1 = floor(pom1);
            return pom1;
            break;
        case 14:
            pom1 =  ParDyn.wypisz_wartosc_para_dyn_glob(7);
            pom1 = floor(pom1);
            return pom1;
            break;
    }
}

int CInterface::podaj_czesc_ulamkowa_param(int i)
{
    float pom1;
    int pom2;

    switch (i)
    {
    case 0:
        pom1 =  ParStat.wypisz_wartosc_para_stat_glob(0);
        pom1 = pom1 * 10;
        pom2 = pom1;
        pom1 = pom2% 10;
        return pom1;
        break;
    case 1:
        pom1 =  ParStat.wypisz_wartosc_para_stat_glob(1);
        pom1 = pom1 * 10;
        pom2 = pom1;
        pom1 = pom2 % 10;
        return pom1;
        break;
    case 2:
        pom1 =  ParStat.wypisz_wartosc_para_stat_glob(2);
        pom1 = pom1 * 10;
        pom2 = pom1;
        pom1 = pom2 % 10;
        return pom1;
        break;
    case 3:
        pom1 =  ParStat.wypisz_wartosc_para_stat_glob(3);
        pom1 = pom1 * 10;
        pom2 = pom1;
        pom1 = pom2 % 10;
        return pom1;
        break;
    case 4:
        pom1 =  ParStat.wypisz_wartosc_para_stat_glob(4);
        pom1 = pom1 * 10;
        pom2 = pom1;
        pom1 = pom2 % 10;
        return pom1;
        break;
    case 5:
        pom1 =  ParStat.wypisz_wartosc_para_stat_glob(5);
        pom1 = pom1 * 10;
        pom2 = pom1;
        pom1 = pom2 % 10;
        return pom1;
        break;
    case 6:
        pom1 =  ParStat.wypisz_wartosc_para_stat_glob(6);
        pom1 = pom1 * 10;
        pom2 = pom1;
        pom1 = pom2 % 10;
        return pom1;
        break;
    case 7:
        pom1 =  ParDyn.wypisz_wartosc_para_dyn_glob(0);
        pom1 = pom1 * 10;
        pom2 = pom1;
        pom1 = pom2 % 10;
        return pom1;
        break;
    case 8:
        pom1 =  ParDyn.wypisz_wartosc_para_dyn_glob(1);
        pom1 = pom1 * 10;
        pom2 = pom1;
        pom1 = pom2 % 10;
        return pom1;
        break;
    case 9:
        pom1 =  ParDyn.wypisz_wartosc_para_dyn_glob(2);
        pom1 = pom1 * 10;
        pom2 = pom1;
        pom1 = pom2 % 10;
        return pom1;
        break;
    case 10:
        pom1 =  ParDyn.wypisz_wartosc_para_dyn_glob(3);
        pom1 = pom1 * 10;
        pom2 = pom1;
        pom1 = pom2 % 10;
        return pom1;
        break;
    case 11:
        pom1 =  ParDyn.wypisz_wartosc_para_dyn_glob(4);
        pom1 = pom1 * 10;
        pom2 = pom1;
        pom1 = pom2 % 10;
        return pom1;
        break;
    case 12:
        pom1 =  ParDyn.wypisz_wartosc_para_dyn_glob(5);
        pom1 = pom1 * 10;
        pom2 = pom1;
        pom1 = pom2 % 10;
        return pom1;
        break;
    case 13:
        pom1 =  ParDyn.wypisz_wartosc_para_dyn_glob(6);
        pom1 = pom1 * 10;
        pom2 = pom1;
        pom1 = pom2 % 10;
        return pom1;
        break;
    case 14:
        pom1 =  ParDyn.wypisz_wartosc_para_dyn_glob(7);
        pom1 = pom1 * 10;
        pom2 = pom1;
        pom1 = pom2 % 10;
        return pom1;
        break;
    }
}

void CInterface::tworz_obiekt_dyn(int Licznik)
{
    int pom;
    double pomY = 0;
    double pomX = 0;
    double pomYY = 0;
    double pomXX = 0;

    pom = rand() % 34;

    if (ParDyn.wypisz_wartosc_para_dyn_glob(6) >= 1)
    {

        while (pomY == pomYY && pomX == pomXX)
        {
            switch (pom)
            {
            case 0:
                pomX = 2;
                pomY = 0;
                break;
            case 1:
                pomX = 3;
                pomY = 0;
                break;
            case 2:
                pomX = 5;
                pomY = 0;
                break;
            case 3:
                pomX = 6;
                pomY = 0;
                break;
            case 4:
                pomX = 7;
                pomY = 0;
                break;
            case 5:
                pomX = 9;
                pomY = 0;
                break;
            case 6:
                pomX = 10;
                pomY = 0;
                break;
            case 7:
                pomX = 13;
                pomY = 0;
                break;
            case 8:
                pomX = 14;
                pomY = 0;
                break;
            case 9:
                pomX = 15;
                pomY = 0;
                break;
            case 10:
                pomX = 2;
                pomY = 12.99;
                break;
            case 11:
                pomX = 3;
                pomY = 12.99;
                break;
            case 12:
                pomX = 5;
                pomY = 12.99;
                break;
            case 13:
                pomX = 6;
                pomY = 12.99;
                break;
            case 14:
                pomX = 7;
                pomY = 12.99;
                break;
            case 15:
                pomX = 9;
                pomY = 12.99;
                break;
            case 16:
                pomX = 10;
                pomY = 12.99;
                break;
            case 17:
                pomX = 13;
                pomY = 12.99;
                break;
            case 18:
                pomX = 14;
                pomY = 12.99;
                break;
            case 19:
                pomX = 15;
                pomY = 12.99;
                break;
            case 20:
                pomX = 18.99;
                pomY = 1;
                break;
            case 21:
                pomX = 18.99;
                pomY = 3;
                break;
            case 22:
                pomX = 18.99;
                pomY = 5;
                break;
            case 23:
                pomX = 18.99;
                pomY = 6;
                break;
            case 24:
                pomX = 18.99;
                pomY = 8;
                break;
            case 25:
                pomX = 18.99;
                pomY = 9;
                break;
            case 26:
                pomX = 18.99;
                pomY = 10;
                break;
            case 27:
                pomX = 0;
                pomY = 1;
                break;
            case 28:
                pomX = 0;
                pomY = 3;
                break;
            case 29:
                pomX = 0;
                pomY = 5;
                break;
            case 30:
                pomX = 0;
                pomY = 6;
                break;
            case 31:
                pomX = 0;
                pomY = 8;
                break;
            case 32:
                pomX = 0;
                pomY = 9;
                break;
            case 33:
                pomX = 0;
                pomY = 10;
                break;
            }

            pom = rand() % 34;
            switch (pom)
            {
            case 0:
                pomXX = 2;
                pomYY = 0;
                break;
            case 1:
                pomXX = 3;
                pomYY = 0;
                break;
            case 2:
                pomXX = 5;
                pomYY = 0;
                break;
            case 3:
                pomXX = 6;
                pomYY = 0;
                break;
            case 4:
                pomXX = 7;
                pomYY = 0;
                break;
            case 5:
                pomXX = 9;
                pomYY = 0;
                break;
            case 6:
                pomXX = 10;
                pomYY = 0;
                break;
            case 7:
                pomXX = 13;
                pomYY = 0;
                break;
            case 8:
                pomXX = 14;
                pomYY = 0;
                break;
            case 9:
                pomXX = 15;
                pomYY = 0;
                break;
            case 10:
                pomXX = 2;
                pomYY = 12.99;
                break;
            case 11:
                pomXX = 3;
                pomYY = 12.99;
                break;
            case 12:
                pomXX = 5;
                pomYY = 12.99;
                break;
            case 13:
                pomXX = 6;
                pomYY = 12.99;
                break;
            case 14:
                pomXX = 7;
                pomYY = 12.99;
                break;
            case 15:
                pomXX = 9;
                pomYY = 12.99;
                break;
            case 16:
                pomXX = 10;
                pomYY = 12.99;
                break;
            case 17:
                pomXX = 13;
                pomYY = 12.99;
                break;
            case 18:
                pomXX = 14;
                pomYY = 12.99;
                break;
            case 19:
                pomXX = 15;
                pomYY = 12.99;
                break;
            case 20:
                pomXX = 18.99;
                pomYY = 1;
                break;
            case 21:
                pomXX = 18.99;
                pomYY = 3;
                break;
            case 22:
                pomXX = 18.99;
                pomYY = 5;
                break;
            case 23:
                pomXX = 18.99;
                pomYY = 6;
                break;
            case 24:
                pomXX = 18.99;
                pomYY = 8;
                break;
            case 25:
                pomXX = 18.99;
                pomYY = 9;
                break;
            case 26:
                pomXX = 18.99;
                pomYY = 10;
                break;
            case 27:
                pomXX = 0;
                pomYY = 1;
                break;
            case 28:
                pomXX = 0;
                pomYY = 3;
                break;
            case 29:
                pomXX = 0;
                pomYY = 5;
                break;
            case 30:
                pomXX = 0;
                pomYY = 6;
                break;
            case 31:
                pomXX = 0;
                pomYY = 8;
                break;
            case 32:
                pomXX = 0;
                pomYY = 9;
                break;
            case 33:
                pomXX = 0;
                pomYY = 10;
                break;
            }

            for (int i = 0; i <  ODyn.size();i++)
            {
                if (floor(ODyn[i]->podaj_x()) == floor(pomX) && floor(ODyn[i]->podaj_y()) == floor(pomY))
                {
                    pomY = 0;
                    pomX = 0;
                    pomXX = 0;
                    pomYY = 0;
                }
            }
        }

        int pom1, pom2, pom3, pom4;


        for (int i = 0; i < int(ParDyn.wypisz_wartosc_para_dyn_glob(6)); i++)
        {
            pom1 = Licznik % 3;
            pom2 = Licznik % 7;
            pom3 = Licznik % 13;
            pom4 = Licznik % 23;

            if (pom1 == 0 && ParStat.wypisz_wartosc_para_stat_glob(5) == 1)
            {
                COsobowy* pom = new COsobowy( ParDyn, pomX, pomY, pomXX, pomYY,  Mapa);
                 ODyn.push_back(pom);

                CGOsobowy* pom2 = new CGOsobowy(pom);
                 GraphODyn.push_back(pom2);

            }
            else if (pom2 == 0 && ParStat.wypisz_wartosc_para_stat_glob(6) == 1)
            {
                CJednoslad* pom = new CJednoslad( ParDyn, pomX, pomY, pomXX, pomYY,  Mapa);
                 ODyn.push_back(pom);

                CGJednoslad* pom2 = new CGJednoslad(pom);
                 GraphODyn.push_back(pom2);

            }
            else if (pom3 == 0 && ParStat.wypisz_wartosc_para_stat_glob(4) == 1)
            {
                CCiezarowka* pom = new CCiezarowka( ParDyn, pomX, pomY, pomXX, pomYY,  Mapa);
                 ODyn.push_back(pom);

                CGCiezarowka* pom2 = new CGCiezarowka(pom);
                 GraphODyn.push_back(pom2);

            }
            else if (pom4 == 0 && ParStat.wypisz_wartosc_para_stat_glob(3) == 1)
            {
                CTir* pom = new CTir( ParDyn, pomX, pomY, pomXX, pomYY,  Mapa);
                 ODyn.push_back(pom);

                CGTir* pom2 = new CGTir(pom);
                 GraphODyn.push_back(pom2);

            }
            Licznik++;
        }
    }
    else
    {
        while (pomY == pomYY && pomX == pomXX)
        {
            switch (pom)
            {
            case 0:
                pomX = 2;
                pomY = 0;
                break;
            case 1:
                pomX = 3;
                pomY = 0;
                break;
            case 2:
                pomX = 5;
                pomY = 0;
                break;
            case 3:
                pomX = 6;
                pomY = 0;
                break;
            case 4:
                pomX = 7;
                pomY = 0;
                break;
            case 5:
                pomX = 9;
                pomY = 0;
                break;
            case 6:
                pomX = 10;
                pomY = 0;
                break;
            case 7:
                pomX = 13;
                pomY = 0;
                break;
            case 8:
                pomX = 14;
                pomY = 0;
                break;
            case 9:
                pomX = 15;
                pomY = 0;
                break;
            case 10:
                pomX = 2;
                pomY = 12.99;
                break;
            case 11:
                pomX = 3;
                pomY = 12.99;
                break;
            case 12:
                pomX = 5;
                pomY = 12.99;
                break;
            case 13:
                pomX = 6;
                pomY = 12.99;
                break;
            case 14:
                pomX = 7;
                pomY = 12.99;
                break;
            case 15:
                pomX = 9;
                pomY = 12.99;
                break;
            case 16:
                pomX = 10;
                pomY = 12.99;
                break;
            case 17:
                pomX = 13;
                pomY = 12.99;
                break;
            case 18:
                pomX = 14;
                pomY = 12.99;
                break;
            case 19:
                pomX = 15;
                pomY = 12.99;
                break;
            case 20:
                pomX = 18.99;
                pomY = 1;
                break;
            case 21:
                pomX = 18.99;
                pomY = 3;
                break;
            case 22:
                pomX = 18.99;
                pomY = 5;
                break;
            case 23:
                pomX = 18.99;
                pomY = 6;
                break;
            case 24:
                pomX = 18.99;
                pomY = 8;
                break;
            case 25:
                pomX = 18.99;
                pomY = 9;
                break;
            case 26:
                pomX = 18.99;
                pomY = 10;
                break;
            case 27:
                pomX = 0;
                pomY = 1;
                break;
            case 28:
                pomX = 0;
                pomY = 3;
                break;
            case 29:
                pomX = 0;
                pomY = 5;
                break;
            case 30:
                pomX = 0;
                pomY = 6;
                break;
            case 31:
                pomX = 0;
                pomY = 8;
                break;
            case 32:
                pomX = 0;
                pomY = 9;
                break;
            case 33:
                pomX = 0;
                pomY = 10;
                break;
            }

            pom = rand() % 34;
            switch (pom)
            {
            case 0:
                pomXX = 2;
                pomYY = 0;
                break;
            case 1:
                pomXX = 3;
                pomYY = 0;
                break;
            case 2:
                pomXX = 5;
                pomYY = 0;
                break;
            case 3:
                pomXX = 6;
                pomYY = 0;
                break;
            case 4:
                pomXX = 7;
                pomYY = 0;
                break;
            case 5:
                pomXX = 9;
                pomYY = 0;
                break;
            case 6:
                pomXX = 10;
                pomYY = 0;
                break;
            case 7:
                pomXX = 13;
                pomYY = 0;
                break;
            case 8:
                pomXX = 14;
                pomYY = 0;
                break;
            case 9:
                pomXX = 15;
                pomYY = 0;
                break;
            case 10:
                pomXX = 2;
                pomYY = 12.99;
                break;
            case 11:
                pomXX = 3;
                pomYY = 12.99;
                break;
            case 12:
                pomXX = 5;
                pomYY = 12.99;
                break;
            case 13:
                pomXX = 6;
                pomYY = 12.99;
                break;
            case 14:
                pomXX = 7;
                pomYY = 12.99;
                break;
            case 15:
                pomXX = 9;
                pomYY = 12.99;
                break;
            case 16:
                pomXX = 10;
                pomYY = 12.99;
                break;
            case 17:
                pomXX = 13;
                pomYY = 12.99;
                break;
            case 18:
                pomXX = 14;
                pomYY = 12.99;
                break;
            case 19:
                pomXX = 15;
                pomYY = 12.99;
                break;
            case 20:
                pomXX = 18.99;
                pomYY = 1;
                break;
            case 21:
                pomXX = 18.99;
                pomYY = 3;
                break;
            case 22:
                pomXX = 18.99;
                pomYY = 5;
                break;
            case 23:
                pomXX = 18.99;
                pomYY = 6;
                break;
            case 24:
                pomXX = 18.99;
                pomYY = 8;
                break;
            case 25:
                pomXX = 18.99;
                pomYY = 9;
                break;
            case 26:
                pomXX = 18.99;
                pomYY = 10;
                break;
            case 27:
                pomXX = 0;
                pomYY = 1;
                break;
            case 28:
                pomXX = 0;
                pomYY = 3;
                break;
            case 29:
                pomXX = 0;
                pomYY = 5;
                break;
            case 30:
                pomXX = 0;
                pomYY = 6;
                break;
            case 31:
                pomXX = 0;
                pomYY = 8;
                break;
            case 32:
                pomXX = 0;
                pomYY = 9;
                break;
            case 33:
                pomXX = 0;
                pomYY = 10;
                break;
            }

            for (int i = 0; i <  ODyn.size();i++)
            {
                if (floor(ODyn[i]->podaj_x()) == floor(pomX) && floor(ODyn[i]->podaj_y()) == floor(pomY))
                {
                    pomY = 0;
                    pomX = 0;
                    pomXX = 0;
                    pomYY = 0;
                }
            }
        }

        int pom1, pom2, pom3, pom4;
        pom1 = Licznik % (3 * (11 - int(ParDyn.wypisz_wartosc_para_dyn_glob(6))));
        pom2 = Licznik % (7 * (11 - int(ParDyn.wypisz_wartosc_para_dyn_glob(6))));
        pom3 = Licznik % (13 * (11 - int(ParDyn.wypisz_wartosc_para_dyn_glob(6))));
        pom4 = Licznik % (23 * (11 - int(ParDyn.wypisz_wartosc_para_dyn_glob(6))));

        if (pom1 == 0 && ParStat.wypisz_wartosc_para_stat_glob(5) == 1)
        {
            COsobowy* pom = new COsobowy( ParDyn, pomX, pomY, pomXX, pomYY,  Mapa);
             ODyn.push_back(pom);

            CGOsobowy* pom2 = new CGOsobowy(pom);
             GraphODyn.push_back(pom2);

        }
        else if (pom2 == 0 && ParStat.wypisz_wartosc_para_stat_glob(6) == 1)
        {
            CJednoslad* pom = new CJednoslad( ParDyn, pomX, pomY, pomXX, pomYY,  Mapa);
             ODyn.push_back(pom);

            CGJednoslad* pom2 = new CGJednoslad(pom);
             GraphODyn.push_back(pom2);

        }
        else if (pom3 == 0 && ParStat.wypisz_wartosc_para_stat_glob(4) == 1)
        {
            CCiezarowka* pom = new CCiezarowka( ParDyn, pomX, pomY, pomXX, pomYY,  Mapa);
             ODyn.push_back(pom);

            CGCiezarowka* pom2 = new CGCiezarowka(pom);
             GraphODyn.push_back(pom2);

        }
        else if (pom4 == 0 && ParStat.wypisz_wartosc_para_stat_glob(3) == 1)
        {
            CTir* pom = new CTir( ParDyn, pomX, pomY, pomXX, pomYY,  Mapa);
             ODyn.push_back(pom);

            CGTir* pom2 = new CGTir(pom);
             GraphODyn.push_back(pom2);

        }
    }
}

void CInterface::tworz_obiekty_stat()
{
    int pom_licznik=0;

    for (int j = 0; j < 19; j++)
    {
        for (int i = 0; i < 13; i++)
        {
            if ( Mapa.podaj_mape(i, j) == 0)
            {
                 OStat[pom_licznik] = NULL;
            }
            if ( Mapa.podaj_mape(i, j) == 1)
            {
                CDroga* pom = new CDroga(j, i, ParStat, 1);
                 OStat[pom_licznik] = pom;

                CGDroga* pom2 = new CGDroga(pom);
                 GraphOStat[pom_licznik] = pom2;
            }
            if ( Mapa.podaj_mape(i, j) == 2)
            {
                CDroga* pom = new CDroga(j, i, ParStat, 0);
                 OStat[pom_licznik] = pom;

                CGDroga* pom2 = new CGDroga(pom);
                 GraphOStat[pom_licznik] = pom2;
            }
            if ( Mapa.podaj_mape(i, j) == 3)
            {
                CSkrzyzowanieRownorzedne* pom = new CSkrzyzowanieRownorzedne(j, i, ParStat);
                 OStat[pom_licznik] = pom;

                CGSkrzyzowanieRownorzedne* pom2 = new CGSkrzyzowanieRownorzedne(pom);
                 GraphOStat[pom_licznik] = pom2;
            }
            if ( Mapa.podaj_mape(i, j) == 4)
            {
                CSkrzyzowanieSwietlne* pom = new CSkrzyzowanieSwietlne(j, i, ParStat);
                 OStat[pom_licznik] = pom;

                CGSkrzyzowanieSwietlne* pom2 = new CGSkrzyzowanieSwietlne(pom);
                 GraphOStat[pom_licznik] = pom2;
            }
            pom_licznik++;
        }
    }
}

bool CInterface::czy_uruchomiona()
{
    if ( Start == 0) return 0;
    else return 1;
}

void CInterface::ruch_obie_dyn()
{
    for (int i = 0; i <  ODyn.size();i++)
    {
        if(czy_ruch_dozwolony(i)==1)
        ODyn[i]->ruch();
    }
}

void CInterface::usun_obiekty_dynamiczne()
{
    for (int i = 0; i <  ODyn.size();i++)
    {
        if (ODyn[i]->podaj_x() > 19 || ODyn[i]->podaj_x() < 0 || ODyn[i]->podaj_y() > 13 || ODyn[i]->podaj_y() < 0 || ODyn[i]->Trasa.podaj_aktualna_pozycje() >= ODyn[i]->Trasa.podaj_ilosc_skretow()  || (Mapa.podaj_mape(ODyn[i]->podaj_y(), ODyn[i]->podaj_x()) == 1 &&  (ODyn[i]->Trasa.podaj_nastepny_skret()==2 || ODyn[i]->Trasa.podaj_nastepny_skret() == 4)) || (Mapa.podaj_mape(ODyn[i]->podaj_y(), ODyn[i]->podaj_x()) == 2 && (ODyn[i]->Trasa.podaj_nastepny_skret() == 1 || ODyn[i]->Trasa.podaj_nastepny_skret() == 3)))
        {
            delete ODyn[i];
            delete GraphODyn[i];

            ODyn.erase(ODyn.begin()+i);
            GraphODyn.erase(GraphODyn.begin() + i);
        }
    }
}

bool CInterface::czy_ruch_dozwolony(int n)
{  
    if (ODyn[n]->CzasZ >= 10)
    {
        ODyn[n]->WTrakcieManewru = 1;
        return 1;
    }

   
    if (ODyn[n]->Trasa.podaj_nastepny_skret() == 1 && (ODyn[n]->podaj_y() - floor(ODyn[n]->podaj_y())) < 0.11
        || ODyn[n]->Trasa.podaj_nastepny_skret() == 3 && (ODyn[n]->podaj_y() - floor(ODyn[n]->podaj_y())) > 0.89
        || ODyn[n]->Trasa.podaj_nastepny_skret() == 2 && (ODyn[n]->podaj_x() - floor(ODyn[n]->podaj_x())) > 0.89
        || ODyn[n]->Trasa.podaj_nastepny_skret() == 4 && (ODyn[n]->podaj_x() - floor(ODyn[n]->podaj_x())) < 0.11)
    {
        ODyn[n]->WTrakcieManewru = 1;
        return 1;
    }


 
    for (int i = 0; i < ODyn.size();i++)
    {
        if (i != n)
        {    
            if (ODyn[i]->Trasa.podaj_nastepny_skret() == ODyn[n]->Trasa.podaj_nastepny_skret()) 
            {
                if (ODyn[i]->podaj_x() == ODyn[n]->podaj_x() && abs(ODyn[i]->podaj_y() - ODyn[n]->podaj_y()) <= (0.5*ODyn[n]->podaj_preferowana_odleglosc()))
                {
                    if (ODyn[i]->Trasa.podaj_nastepny_skret() == 1 && ODyn[n]->podaj_y() > ODyn[i]->podaj_y())
                    {
                        return 0;
                    }
                    if (ODyn[i]->Trasa.podaj_nastepny_skret() == 3 && ODyn[n]->podaj_y() < ODyn[i]->podaj_y()) 
                    {
                        return 0;
                    }
                }

                if (ODyn[i]->podaj_y() == ODyn[n]->podaj_y() && abs(ODyn[i]->podaj_x() - ODyn[n]->podaj_x()) <= (0.5 * ODyn[n]->podaj_preferowana_odleglosc()))
                {
                    if (ODyn[i]->Trasa.podaj_nastepny_skret() == 2 && ODyn[n]->podaj_x() < ODyn[i]->podaj_x())  
                    {
                        return 0;
                    }
                    if (ODyn[i]->Trasa.podaj_nastepny_skret() == 4 && ODyn[n]->podaj_x() > ODyn[i]->podaj_x()) 
                    {
                        return 0;
                    }
                }

            }
        }
    }

    for (int i = 0; i < ODyn.size();i++)
    {
        if (i != n)
        {
         
            if (ODyn[n]->WTrakcieManewru == 1)
                {
                    return 1;
                }

   
            if (Mapa.podaj_mape(floor(ODyn[n]->podaj_y()), floor(ODyn[n]->podaj_x())) == 1 
                || Mapa.podaj_mape(floor(ODyn[n]->podaj_y()), floor(ODyn[n]->podaj_x())) == 2)
            {
                ODyn[n]->WTrakcieManewru = 1;
                return 1;
            }

        
            if(Mapa.podaj_mape(floor(ODyn[n]->podaj_y()), floor(ODyn[n]->podaj_x())) == 3)
            {
                if    (floor(ODyn[n]->podaj_y()) == floor(ODyn[i]->podaj_y()) 
                    && floor(ODyn[n]->podaj_x()) == floor(ODyn[i]->podaj_x()))
                {
                    if (ODyn[i]->WTrakcieManewru == 1 && ODyn[n]->Trasa.podaj_nastepny_skret() != ODyn[i]->Trasa.podaj_nastepny_skret())
                       
                    {
                        return 0;
                    }

                    if (ODyn[n]->Trasa.podaj_nastepny_skret() - ODyn[n]->Trasa.podaj_skret_nr(ODyn[n]->Trasa.podaj_aktualna_pozycje() + 1) == 1
                        || ODyn[n]->Trasa.podaj_nastepny_skret() - ODyn[n]->Trasa.podaj_skret_nr(ODyn[n]->Trasa.podaj_aktualna_pozycje() + 1) == -3)
                       
                    {
                        ODyn[n]->WTrakcieManewru = 1;
                        return 1;
                    }

                   
                    bool pom2=0, pom3=0, pom4=0;
                    for(int i = 0; i < ODyn.size();i++)
                    {
                        if (ODyn[i]->Trasa.podaj_nastepny_skret() == 2) pom2 = 1;
                        if (ODyn[i]->Trasa.podaj_nastepny_skret() == 3) pom3 = 1;
                        if (ODyn[i]->Trasa.podaj_nastepny_skret() == 4) pom4 = 1;
                    }

                    if(pom2 == 1 && pom3 == 1 && pom4==1 && ODyn[n]->Trasa.podaj_nastepny_skret() == 1)
                    {
                        ODyn[n]->WTrakcieManewru = 1;
                        return 1;
                    }

                    
                    int pomPoz = ODyn[n]->Trasa.podaj_nastepny_skret() - ODyn[i]->Trasa.podaj_nastepny_skret();
                    if (pomPoz == -3) pomPoz = 1;
                    if(pomPoz==1)
                    {
                        return 0;
                    }
                }
            }

          
            if (Mapa.podaj_mape(floor(ODyn[n]->podaj_y()), floor(ODyn[n]->podaj_x())) == 4)
            {
               
                if   ((OStat[int (13 * (floor(ODyn[n]->podaj_x()) + 1) + (floor(ODyn[n]->podaj_y() - 13)))]->podaj_swiatla() == 0 && ODyn[n]->Trasa.podaj_nastepny_skret() % 2 == 0
                    || OStat[int (13 * (floor(ODyn[n]->podaj_x()) + 1) + (floor(ODyn[n]->podaj_y() - 13)))]->podaj_swiatla() == 1 && ODyn[n]->Trasa.podaj_nastepny_skret() % 2 == 1)
                    /* && ODyn[n]->WTrakcieManewru==0 || (ODyn[n]->podaj_y() -floor(ODyn[n]->podaj_y())>0.2 && ODyn[n]->podaj_x() - floor(ODyn[n]->podaj_x())) */ )
                {
                    return 0;
                }

                if (ODyn[i]->WTrakcieManewru == 1 && (ODyn[n]->Trasa.podaj_nastepny_skret() + ODyn[i]->Trasa.podaj_nastepny_skret())%2==1
                    && (ODyn[n]->Trasa.podaj_nastepny_skret() != ODyn[i]->Trasa.podaj_nastepny_skret())
                    && floor(ODyn[n]->podaj_y()) == floor(ODyn[i]->podaj_y()) && floor(ODyn[n]->podaj_x()) == floor(ODyn[i]->podaj_x()))
                    //Jeœli ktoœ zosta³ na skrzyzowaniu w trakcie manewru
                {
                    return 0;
                }

                if (floor(ODyn[n]->podaj_y()) == floor(ODyn[i]->podaj_y())
                    && floor(ODyn[n]->podaj_x()) == floor(ODyn[i]->podaj_x()))
                {
                    if (ODyn[n]->Trasa.podaj_nastepny_skret() - ODyn[n]->Trasa.podaj_skret_nr(ODyn[n]->Trasa.podaj_aktualna_pozycje() + 1) == -1
                        || ODyn[n]->Trasa.podaj_nastepny_skret() - ODyn[n]->Trasa.podaj_skret_nr(ODyn[n]->Trasa.podaj_aktualna_pozycje() + 1) == 3)
                       
                    {
                        //Jeœli ktoœ jedzie z naprzeciwka
                        if (abs(ODyn[n]->Trasa.podaj_nastepny_skret() - ODyn[i]->Trasa.podaj_nastepny_skret()) == 2)
                        {
                            return 0;
                        }
                    }
                }
            }
        }
    }
    ODyn[n]->WTrakcieManewru = 1;
    return 1;
}

void CInterface::zmiana_swiatel()
{
	for (int i = 0; i < 247;i++)
	{
		if (OStat[i] != 0)
			OStat[i]->zmien_swiatla(Licznik);
	}  
}

void CInterface::zakonczenie_programu()
{
    for (int i = 0; i <  ODyn.size();i++)
    {
        delete ODyn[i];
        delete GraphODyn[i];
    }

    for (int i = 0; i < 247;i++)
    {
        delete OStat[i];
        delete GraphOStat[i];
    }
}