#pragma once
#include "CParametryDynGlob.h"

using namespace std;

CParametryDynGlob::CParametryDynGlob()
{
	 GlobUtrzyOdl = 1;
	 GlobSzybkosc = 1;
	 GlobNaterzenieRuchu = 1;
}

void CParametryDynGlob::zwieksz_wartosc_para_dyn_glob(int i)
{
	switch (i)
	{	
	case 3:
		 GlobUtrzyOdl =  GlobUtrzyOdl + 0.1;
		if ( GlobUtrzyOdl > 9.9)  GlobUtrzyOdl = 9.9;
		break;
	case 4:
		 GlobSzybkosc =  GlobSzybkosc + 0.1;
		if ( GlobSzybkosc > 9.9)  GlobSzybkosc = 9.9;
		break;
	case 6:
		 GlobNaterzenieRuchu =  GlobNaterzenieRuchu + 0.1;
		if ( GlobNaterzenieRuchu > 9.9)  GlobNaterzenieRuchu = 9.9;
		break;
	}
}

void CParametryDynGlob::zmniejsz_wartosc_para_dyn_glob(int i)
{
	switch (i)
	{
	case 3:
		 GlobUtrzyOdl=  GlobUtrzyOdl-0.1;
		if ( GlobUtrzyOdl < 0.1)  GlobUtrzyOdl = 0.1;
		break;
	case 4:
		 GlobSzybkosc=  GlobSzybkosc-0.1;
		if ( GlobSzybkosc < 0.1)  GlobSzybkosc = 0.1;
		break;
	case 6:
		 GlobNaterzenieRuchu=  GlobNaterzenieRuchu-0.1;
		if ( GlobNaterzenieRuchu < 0.1)  GlobNaterzenieRuchu = 0.1;
		break;
	}
}

float CParametryDynGlob::wypisz_wartosc_para_dyn_glob(int i)
{
	switch (i)
	{
	case 3:
		return  GlobUtrzyOdl;
	case 4:
		return  GlobSzybkosc;
	case 6:
		return  GlobNaterzenieRuchu;
	}
}