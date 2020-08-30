#pragma once
#include "CGTir.h"

CGTir::CGTir(CTir* Tir)
{
    this->Tir = Tir;
}

void CGTir::rysuj(sf::RenderWindow& oknoAplikacji)
{
    sf::Texture tek;
    tek.loadFromFile("zasoby/Tir.png");
    sf::Sprite obrazek;
    obrazek.setTexture(tek);
    obrazek.scale(0.04, 0.04);


    if (Tir->Trasa.podaj_nastepny_skret() == 4)
    {
        obrazek.setRotation(90);
        obrazek.setPosition(sf::Vector2f(Tir->podaj_x() * 80 + 265, Tir->podaj_y() * 80 + 17));
    }
    if (Tir->Trasa.podaj_nastepny_skret() == 1)
    {
        obrazek.setRotation(180);
        obrazek.setPosition(sf::Vector2f(Tir->podaj_x() * 80 + 313, Tir->podaj_y() * 80 + 12));
    }
    if (Tir->Trasa.podaj_nastepny_skret() == 2)
    {
        obrazek.setRotation(270);
        obrazek.setPosition(sf::Vector2f(Tir->podaj_x() * 80 + 237, Tir->podaj_y() * 80 + 59));
    }
    if (Tir->Trasa.podaj_nastepny_skret() == 3)
    {
        obrazek.setPosition(sf::Vector2f(Tir->podaj_x() * 80 + 267, Tir->podaj_y() * 80 - 10));
    }


    oknoAplikacji.draw(obrazek);
}