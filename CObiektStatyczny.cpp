#pragma once
#include "CObiektStatyczny.h"

CObiektStatyczny::CObiektStatyczny()
{
}

int CObiektStatyczny::podaj_x()
{
	return X;
}

int CObiektStatyczny::podaj_y()
{
	return Y;
}

bool CObiektStatyczny::podaj_swiatla()
{
	return Swiatla;
}

