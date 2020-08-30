#pragma once
#include "CGOsobowy.h"

CGOsobowy::CGOsobowy(COsobowy* Osobowy)
{
    this->Osobowy = Osobowy;
}

void CGOsobowy::rysuj(sf::RenderWindow& oknoAplikacji)
{
    sf::Texture tek;
    tek.loadFromFile("zasoby/Osobowy.png");
    sf::Sprite obrazek;
    obrazek.setTexture(tek);
    obrazek.scale(0.04, 0.04);

    
        if (Osobowy->Trasa.podaj_nastepny_skret() == 4)
        {
            obrazek.setRotation(90);
            obrazek.setPosition(sf::Vector2f(Osobowy->podaj_x() * 80 + 265, Osobowy->podaj_y() * 80 + 17));
        }
        if (Osobowy->Trasa.podaj_nastepny_skret() == 1)
        {
            obrazek.setRotation(180);
            obrazek.setPosition(sf::Vector2f(Osobowy->podaj_x() * 80 + 313, Osobowy->podaj_y() * 80+12));
        }
        if (Osobowy->Trasa.podaj_nastepny_skret() == 2)
        {
            obrazek.setRotation(270);
            obrazek.setPosition(sf::Vector2f(Osobowy->podaj_x() * 80 + 237, Osobowy->podaj_y() * 80 + 59));
        }
        if (Osobowy->Trasa.podaj_nastepny_skret() == 3)
        {
            obrazek.setPosition(sf::Vector2f(Osobowy->podaj_x() * 80 + 267, Osobowy->podaj_y() * 80-10));
        }
    

    oknoAplikacji.draw(obrazek);
}