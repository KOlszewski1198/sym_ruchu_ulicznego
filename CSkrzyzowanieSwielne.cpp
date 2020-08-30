#pragma once
#include "CSkrzyzowanieSwietlne.h"
#include <iostream>

CSkrzyzowanieSwietlne::CSkrzyzowanieSwietlne(int x, int y, CParametryStatGlob param)
{
	X = x;
	Y = y;
	Swiatla = 0;

	DlugoscSwiatel = param.wypisz_wartosc_para_stat_glob(1);
}

void CSkrzyzowanieSwietlne::zmien_swiatla(int licz)
{
	if (licz % int (10 * DlugoscSwiatel) == 0)
	{
		if (Swiatla == 0)
		{
			Swiatla = 1;
		}
		else
		{
			Swiatla = 0;
		}
	}
}

void CSkrzyzowanieSwietlne::odswiez_param(CParametryStatGlob param)
{
	DlugoscSwiatel = param.wypisz_wartosc_para_stat_glob(1);
}

