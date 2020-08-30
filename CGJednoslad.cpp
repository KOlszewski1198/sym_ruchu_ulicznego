#pragma once
#include "CGJednoslad.h"

CGJednoslad::CGJednoslad(CJednoslad* Jednoslad)
{
    this->Jednoslad = Jednoslad;
}

void CGJednoslad::rysuj(sf::RenderWindow& oknoAplikacji)
{
    sf::Texture tek;
    tek.loadFromFile("zasoby/Jednoslad.png");
    sf::Sprite obrazek;
    obrazek.setTexture(tek);
    obrazek.scale(0.03, 0.03);


    if (Jednoslad->Trasa.podaj_nastepny_skret() == 4)
    {
        obrazek.setRotation(90);
        obrazek.setPosition(sf::Vector2f(Jednoslad->podaj_x() * 80 + 265, Jednoslad->podaj_y() * 80 + 17));
    }
    if (Jednoslad->Trasa.podaj_nastepny_skret() == 1)
    {
        obrazek.setRotation(180);
        obrazek.setPosition(sf::Vector2f(Jednoslad->podaj_x() * 80 + 313, Jednoslad->podaj_y() * 80 + 12));
    }
    if (Jednoslad->Trasa.podaj_nastepny_skret() == 2)
    {
        obrazek.setRotation(270);
        obrazek.setPosition(sf::Vector2f(Jednoslad->podaj_x() * 80 + 237, Jednoslad->podaj_y() * 80 + 59));
    }
    if (Jednoslad->Trasa.podaj_nastepny_skret() == 3)
    {
        obrazek.setPosition(sf::Vector2f(Jednoslad->podaj_x() * 80 + 267, Jednoslad->podaj_y() * 80 - 10));
    }


    oknoAplikacji.draw(obrazek);
}