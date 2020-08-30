#pragma once
#include "CGDroga.h"

CGDroga::CGDroga(CDroga* Droga)
{
    this->Droga = Droga;
}

void CGDroga::rysuj(sf::RenderWindow& oknoAplikacji)
{
    sf::Texture tek;
    tek.loadFromFile("zasoby/Droga.png");
    sf::Sprite obrazek;
    obrazek.setTexture(tek);
    obrazek.scale(0.8, 0.8);
    obrazek.setPosition(sf::Vector2f(Droga->podaj_x()*80+250, Droga->podaj_y()*80 + 000));

    if (Droga->czy_droga_pionowa() == 0)
    {
      obrazek.setRotation(90);
      obrazek.setPosition(sf::Vector2f(Droga->podaj_x() * 80+80 + 250, Droga->podaj_y() * 80 + 000));
    }

    oknoAplikacji.draw(obrazek);
}