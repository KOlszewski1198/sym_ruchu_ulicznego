#pragma once
#include "CGSkrzyzowanieRownorzedne.h"

CGSkrzyzowanieRownorzedne::CGSkrzyzowanieRownorzedne(CSkrzyzowanieRownorzedne* Skrzyzowanie)
{
    this->Skrzyzowanie = Skrzyzowanie;
}

void CGSkrzyzowanieRownorzedne::rysuj(sf::RenderWindow& oknoAplikacji)
{
    sf::Texture tek;
    tek.loadFromFile("zasoby/Rownorzedne.png");
    sf::Sprite obrazek;
    obrazek.setTexture(tek);
    obrazek.scale(0.8, 0.8);

    obrazek.setPosition(sf::Vector2f(Skrzyzowanie->podaj_x()*80 + 250, Skrzyzowanie->podaj_y()*80 + 000));
    oknoAplikacji.draw(obrazek);
}