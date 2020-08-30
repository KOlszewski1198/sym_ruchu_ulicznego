#pragma once
#include "CGSkrzyzowanieswietlne.h"

CGSkrzyzowanieSwietlne::CGSkrzyzowanieSwietlne(CSkrzyzowanieSwietlne* Skrzyzowanie)
{
    this->Skrzyzowanie = Skrzyzowanie;
}

void CGSkrzyzowanieSwietlne::rysuj(sf::RenderWindow& oknoAplikacji)
{
    sf::Texture tek;

    if(Skrzyzowanie->podaj_swiatla()==0)
        tek.loadFromFile("zasoby/Swietlne0.png");

    if(Skrzyzowanie->podaj_swiatla() == 1)
        tek.loadFromFile("zasoby/Swietlne1.png");

    sf::Sprite obrazek;
    obrazek.setTexture(tek);
    obrazek.scale(0.8, 0.8);

    obrazek.setPosition(sf::Vector2f(Skrzyzowanie->podaj_x()*80 + 250, Skrzyzowanie->podaj_y()*80 + 000));
    oknoAplikacji.draw(obrazek);
}