#pragma once
#include "CParametryStatGlob.h"

using namespace std;

CParametryStatGlob::CParametryStatGlob()
{
	this ->PredkoscSymulacji=1;
	  GlobDlSwiatel = 1;
	 Tiry = 1;
	 Dostawcze = 1;
	 Osobowe = 1;
	 Jednoslady = 1;
}

void CParametryStatGlob::zwieksz_wartosc_para_stat_glob(int i)
{
	switch (i)
	{
	case 0:
		 PredkoscSymulacji=  PredkoscSymulacji+0.1;
		if ( PredkoscSymulacji > 9.9)  PredkoscSymulacji = 9.9;
		break;
	case 1:
		 GlobDlSwiatel=  GlobDlSwiatel+0.1;
		if ( GlobDlSwiatel > 9.9)  GlobDlSwiatel = 9.9;
		break;
	}
}

void CParametryStatGlob::zmniejsz_wartosc_para_stat_glob(int i)
{
	switch (i)
	{
	case 0:
		 PredkoscSymulacji=  PredkoscSymulacji-0.1;
		if ( PredkoscSymulacji < 0.1)  PredkoscSymulacji = 0.1;
		break;
	case 1:
		 GlobDlSwiatel=  GlobDlSwiatel-0.1;
		if ( GlobDlSwiatel < 0.1)  GlobDlSwiatel = 0.1;
		break;
	}
}

void CParametryStatGlob::zaprzeczenie_param(int i)
{
	switch (i)
	{
	case 0:
		if ( Tiry == 0)
			 Tiry = 1;
		else
			 Tiry = 0;
		break;
	case 1:
		if ( Dostawcze == 0)
			 Dostawcze = 1;
		else
			 Dostawcze = 0;
		break;
	case 2:
		if ( Osobowe == 0)
			 Osobowe = 1;
		else
			 Osobowe = 0;
		break;
	case 3:
		if ( Jednoslady == 0)
			 Jednoslady = 1;
		else
			 Jednoslady = 0;
		break;
	}
}

float CParametryStatGlob::wypisz_wartosc_para_stat_glob(int i)
{
	switch (i)
	{
	case 0:
		return  PredkoscSymulacji;
	case 1:
		return  GlobDlSwiatel;
	case 3:
		return  Tiry;
	case 4:
		return  Dostawcze;
	case 5:
		return  Osobowe;
	case 6:
		return  Jednoslady;
	}
}
