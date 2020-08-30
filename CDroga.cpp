#pragma once
#include "CDroga.h"

CDroga::CDroga(int x, int y, CParametryStatGlob param, bool Pion)
{
	X = x;
	Y = y;
	this->Pion = Pion;
}

bool CDroga::czy_droga_pionowa()
{
	return Pion;
}

void CDroga::zmien_swiatla(int licz)
{
	return;
}

void CDroga::odswiez_param(CParametryStatGlob param)
{
	return;
}