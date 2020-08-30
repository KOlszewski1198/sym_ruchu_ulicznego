#pragma once
#include "CGCiezarowka.h"

CGCiezarowka::CGCiezarowka(CCiezarowka* Ciezarowka)
{
    this->Ciezarowka = Ciezarowka;
}

void CGCiezarowka::rysuj(sf::RenderWindow& oknoAplikacji)
{
    sf::Texture tek;
    tek.loadFromFile("zasoby/Dostawczy.png");
    sf::Sprite obrazek;
    obrazek.setTexture(tek);
    obrazek.scale(0.04, 0.04);


    if (Ciezarowka->Trasa.podaj_nastepny_skret() == 4)
    {
        obrazek.setRotation(90);
        obrazek.setPosition(sf::Vector2f(Ciezarowka->podaj_x() * 80 + 265, Ciezarowka->podaj_y() * 80 + 17));
    }
    if (Ciezarowka->Trasa.podaj_nastepny_skret() == 1)
    {
        obrazek.setRotation(180);
        obrazek.setPosition(sf::Vector2f(Ciezarowka->podaj_x() * 80 + 313, Ciezarowka->podaj_y() * 80 + 12));
    }
    if (Ciezarowka->Trasa.podaj_nastepny_skret() == 2)
    {
        obrazek.setRotation(270);
        obrazek.setPosition(sf::Vector2f(Ciezarowka->podaj_x() * 80 + 237, Ciezarowka->podaj_y() * 80 + 59));
    }
    if (Ciezarowka->Trasa.podaj_nastepny_skret() == 3)
    {
        obrazek.setPosition(sf::Vector2f(Ciezarowka->podaj_x() * 80 + 267, Ciezarowka->podaj_y() * 80 - 10));
    }

    oknoAplikacji.draw(obrazek);
}