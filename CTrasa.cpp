#pragma once
#include "CTrasa.h"

CTrasa::CTrasa()
{
	 AktualnaPozycja = 0;
}

void CTrasa::tworz_trase(int X, int Y, int XX, int YY, CMapa xMapa)
{
	int aktX=X;
	int aktY=Y;

	while (aktX != XX || aktY != YY)
	{
		if (XX==18 && X!=XX )
		{
			if (aktY<YY)
			{
				if (xMapa.podaj_mape(aktY, aktX) == 3 || xMapa.podaj_mape(aktY, aktX) == 4)
				{
					 Lista_Skretow.push_back(3);
					aktY++;
				}
				if(xMapa.podaj_mape(aktY, aktX) == 1)
				{
					 Lista_Skretow.push_back(3);
					aktY++;
				}
				if (xMapa.podaj_mape(aktY, aktX) == 2)
				{
					 Lista_Skretow.push_back(2);
					aktX++;
				}
			}
			if (aktY > YY)
			{
				if (xMapa.podaj_mape(aktY, aktX) == 3 || xMapa.podaj_mape(aktY, aktX) == 4)
				{
					 Lista_Skretow.push_back(1);
					aktY--;
				}
				if (xMapa.podaj_mape(aktY, aktX) == 1)
				{
					 Lista_Skretow.push_back(1);
					aktY--;
				}
				if (xMapa.podaj_mape(aktY, aktX) == 2)
				{
					 Lista_Skretow.push_back(2);
					aktX++;
				}
			}
			if (aktY == YY)
			{
				 Lista_Skretow.push_back(2);
				aktX++;
			}
		}
		
		if (XX == 0 && X != XX)
		{
			if (aktY < YY)
			{
				if (xMapa.podaj_mape(aktY, aktX) == 3 || xMapa.podaj_mape(aktY, aktX) == 4)
				{
					 Lista_Skretow.push_back(3);
					aktY++;
				}
				if (xMapa.podaj_mape(aktY, aktX) == 1)
				{
					 Lista_Skretow.push_back(3);
					aktY++;
				}
				if (xMapa.podaj_mape(aktY, aktX) == 2)
				{
					 Lista_Skretow.push_back(4);
					aktX--;
				}
			}
			if (aktY > YY)
			{
				if (xMapa.podaj_mape(aktY, aktX) == 3 || xMapa.podaj_mape(aktY, aktX) == 4)
				{
					 Lista_Skretow.push_back(1);
					aktY--;
				}
				if (xMapa.podaj_mape(aktY, aktX) == 1)
				{
					 Lista_Skretow.push_back(1);
					aktY--;
				}
				if (xMapa.podaj_mape(aktY, aktX) == 2)
				{
					 Lista_Skretow.push_back(4);
					aktX--;
				}
			}
			if (aktY == YY)
			{
				 Lista_Skretow.push_back(4);
				aktX--;
			}
		}
		
		if (YY == 12 && Y != YY)
		{
			if (aktX < XX)
			{
				if (xMapa.podaj_mape(aktY, aktX) == 3 || xMapa.podaj_mape(aktY, aktX) == 4)
				{
					 Lista_Skretow.push_back(2);
					aktX++;
				}
				if (xMapa.podaj_mape(aktY, aktX) == 1)
				{
					 Lista_Skretow.push_back(3);
					aktY++;
				}
				if (xMapa.podaj_mape(aktY, aktX) == 2)
				{
					 Lista_Skretow.push_back(2);
					aktX++;
				}
			}
			if (aktX > XX)
			{
				if (xMapa.podaj_mape(aktY, aktX) == 3 || xMapa.podaj_mape(aktY, aktX) == 4)
				{
					 Lista_Skretow.push_back(4);
					aktX--;
				}
				if (xMapa.podaj_mape(aktY, aktX) == 1)
				{
					 Lista_Skretow.push_back(3);
					aktY++;
				}
				if (xMapa.podaj_mape(aktY, aktX) == 2)
				{
					 Lista_Skretow.push_back(4);
					aktX--;
				}
			}
			if (aktX == XX)
			{
				 Lista_Skretow.push_back(3);
				aktY++;
			}
		}
		
		if (YY == 0 && Y != YY)
		{
			if (aktX < XX)
			{
				if (xMapa.podaj_mape(aktY, aktX) == 3 || xMapa.podaj_mape(aktY, aktX) == 4)
				{
					 Lista_Skretow.push_back(2);
					aktX++;
				}
				if (xMapa.podaj_mape(aktY, aktX) == 1)
				{
					 Lista_Skretow.push_back(1);
					aktY--;
				}
				if (xMapa.podaj_mape(aktY, aktX) == 2)
				{
					 Lista_Skretow.push_back(2);
					aktX++;
				}
			}
			if (aktX > XX)
			{
				if (xMapa.podaj_mape(aktY, aktX) == 3 || xMapa.podaj_mape(aktY, aktX) == 4)
				{
					 Lista_Skretow.push_back(4);
					aktX--;
				}
				if (xMapa.podaj_mape(aktY, aktX) == 1)
				{
					 Lista_Skretow.push_back(1);
					aktY--;
				}
				if (xMapa.podaj_mape(aktY, aktX) == 2)
				{
					 Lista_Skretow.push_back(4);
					aktX--;
				}
			}
			if (aktX == XX)
			{
				 Lista_Skretow.push_back(1);
				aktY--;
			}
		}
		
		if (XX == X)
		{
			if (X == 18)
			{
				if(aktY<YY)
				{
					if (xMapa.podaj_mape(aktY, aktX) == 3 || xMapa.podaj_mape(aktY, aktX) == 4)
					{
						 Lista_Skretow.push_back(3);
						aktY++;
					}
					if (xMapa.podaj_mape(aktY, aktX) == 1)
					{
						 Lista_Skretow.push_back(3);
						aktY++;
					}
					if (xMapa.podaj_mape(aktY, aktX) == 2)
					{
						 Lista_Skretow.push_back(4);
						aktX--;
					}
				}
				if (aktY > YY)
				{
					if (xMapa.podaj_mape(aktY, aktX) == 3 || xMapa.podaj_mape(aktY, aktX) == 4)
					{
						 Lista_Skretow.push_back(1);
						aktY--;
					}
					if (xMapa.podaj_mape(aktY, aktX) == 1)
					{
						 Lista_Skretow.push_back(1);
						aktY--;
					}
					if (xMapa.podaj_mape(aktY, aktX) == 2)
					{
						 Lista_Skretow.push_back(4);
						aktX--;
					}
				}
				if (aktY == YY)
				{
					 Lista_Skretow.push_back(2);
					aktX++;
				}
			}

			if (X == 0)
			{
				if (aktY < YY)
				{
					if (xMapa.podaj_mape(aktY, aktX) == 3 || xMapa.podaj_mape(aktY, aktX) == 4)
					{
						 Lista_Skretow.push_back(3);
						aktY++;
					}
					if (xMapa.podaj_mape(aktY, aktX) == 1)
					{
						 Lista_Skretow.push_back(3);
						aktY++;
					}
					if (xMapa.podaj_mape(aktY, aktX) == 2)
					{
						 Lista_Skretow.push_back(2);
						aktX++;
					}
				}
				if (aktY > YY)
				{
					if (xMapa.podaj_mape(aktY, aktX) == 3 || xMapa.podaj_mape(aktY, aktX) == 4)
					{
						 Lista_Skretow.push_back(1);
						aktY--;
					}
					if (xMapa.podaj_mape(aktY, aktX) == 1)
					{
						 Lista_Skretow.push_back(1);
						aktY--;
					}
					if (xMapa.podaj_mape(aktY, aktX) == 2)
					{
						 Lista_Skretow.push_back(2);
						aktX++;
					}
				}
				if (aktY == YY)
				{
					 Lista_Skretow.push_back(4);
					aktX--;
				}
			}
		}

		if (YY == Y)
		{
			if (Y == 12)
			{
				if (aktX < XX)
				{
					if (xMapa.podaj_mape(aktY, aktX) == 3 || xMapa.podaj_mape(aktY, aktX) == 4)
					{
						 Lista_Skretow.push_back(2);
						aktX++;
					}
					if (xMapa.podaj_mape(aktY, aktX) == 1)
					{
						 Lista_Skretow.push_back(1);
						aktY--;
					}
					if (xMapa.podaj_mape(aktY, aktX) == 2)
					{
						 Lista_Skretow.push_back(2);
						aktX++;
					}
				}
				if (aktX > XX)
				{
					if (xMapa.podaj_mape(aktY, aktX) == 3 || xMapa.podaj_mape(aktY, aktX) == 4)
					{
						 Lista_Skretow.push_back(4);
						aktX--;
					}
					if (xMapa.podaj_mape(aktY, aktX) == 1)
					{
						 Lista_Skretow.push_back(1);
						aktY--;
					}
					if (xMapa.podaj_mape(aktY, aktX) == 2)
					{
						 Lista_Skretow.push_back(4);
						aktX--;
					}
				}
				if (aktX == XX)
				{
					 Lista_Skretow.push_back(3);
					aktY++;
				}
			}

			if (Y == 0)
			{
				if (aktX < XX)
				{
					if (xMapa.podaj_mape(aktY, aktX) == 3 || xMapa.podaj_mape(aktY, aktX) == 4)
					{
						 Lista_Skretow.push_back(2);
						aktX++;
					}
					if (xMapa.podaj_mape(aktY, aktX) == 1)
					{
						 Lista_Skretow.push_back(3);
						aktY++;
					}
					if (xMapa.podaj_mape(aktY, aktX) == 2)
					{
						 Lista_Skretow.push_back(2);
						aktX++;
					}
				}
				if (aktX > XX)
				{
					if (xMapa.podaj_mape(aktY, aktX) == 3 || xMapa.podaj_mape(aktY, aktX) == 4)
					{
						 Lista_Skretow.push_back(4);
						aktX--;
					}
					if (xMapa.podaj_mape(aktY, aktX) == 1)
					{
						 Lista_Skretow.push_back(3);
						aktY++;
					}
					if (xMapa.podaj_mape(aktY, aktX) == 2)
					{
						 Lista_Skretow.push_back(4);
						aktX--;
					}
				}
				if (aktX == XX)
				{
					 Lista_Skretow.push_back(1);
					aktY--;
				}
			}
		}
	}
}

void CTrasa::odswierz_pozycje()
{
		 AktualnaPozycja++;
}

int CTrasa::podaj_aktualna_pozycje()
{
	return  AktualnaPozycja;
}

int CTrasa::podaj_nastepny_skret()
{
	if (AktualnaPozycja < 0)
	{
		return  Lista_Skretow[0];
	}
	if ((AktualnaPozycja >= 0 && AktualnaPozycja <  Lista_Skretow.size()))
	{
		return  Lista_Skretow[AktualnaPozycja];
	}
}

int CTrasa::podaj_skret_nr(int nr)
{
	if (nr < 0)
	{
		return  Lista_Skretow[0];
	}
	if (nr >=  Lista_Skretow.size())
	{
		return  Lista_Skretow[Lista_Skretow.size()-1];
	}
	if((nr >= 0 && nr <  Lista_Skretow.size()))
	{
		return  Lista_Skretow[nr];
	}
}

int CTrasa::podaj_ilosc_skretow()
{
	return  Lista_Skretow.size();
}