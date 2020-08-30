#pragma once
#include "CObiektDynamiczny.h"


CObiektDynamiczny::CObiektDynamiczny()
{

}

double CObiektDynamiczny::podaj_x()
{
	return  X;
}

double CObiektDynamiczny::podaj_y()
{
	return  Y;
}

float CObiektDynamiczny::podaj_preferowana_odleglosc()
{
	return UtrzyOdle;
}

void CObiektDynamiczny::ruch()
{
	if (Y >= 18.98) Y = 19;

	switch (Trasa.podaj_nastepny_skret())
	{
	case 1:
		 Y =  Y -  0.1*Szybkosc;
		break;
	case 2:
		 X =  X + 0.1 * Szybkosc;
		break;
	case 3:
		 Y =  Y + 0.1 * Szybkosc;
		break;
	case 4:
		 X =  X - 0.1 * Szybkosc;
		break;
	}

	if (NaZakrecie == 0 || NaZakrecie == 1)
	{
		if (Trasa.podaj_nastepny_skret() == Trasa.podaj_skret_nr(Trasa.podaj_aktualna_pozycje() + 1))//dla ruchu po prostej
		{
			if (Trasa.podaj_nastepny_skret() == 1 && ((Y - floor(Y)) >= 0.08 && (Y - floor(Y) <= 0.11)))
			{
				Trasa.odswierz_pozycje();
				WTrakcieManewru = 0;
				Y = floor(Y);
			}
			else
			{
				if (Trasa.podaj_nastepny_skret() == 3 && ((Y - floor(Y)) >= 0.89 && (Y - floor(Y) <= 0.91)))
				{
					Trasa.odswierz_pozycje();
					WTrakcieManewru = 0;
					Y = ceil(Y);
				}
				else
				{
					if (Trasa.podaj_nastepny_skret() == 2 && ((X - floor(X)) >= 0.88 && (X - floor(X) <= 0.91)))
					{
						Trasa.odswierz_pozycje();
						WTrakcieManewru = 0;
						X = ceil(X);
					}
					else
					{
						if (Trasa.podaj_nastepny_skret() == 4 && ((X - floor(X)) >= 0.08 && (X - floor(X) <= 0.11)))
						{
							Trasa.odswierz_pozycje();
							WTrakcieManewru = 0;
							X = floor(X);
						}
					}
				}
			}
		}
		else
		{
			if (Trasa.podaj_nastepny_skret() != Trasa.podaj_skret_nr(Trasa.podaj_aktualna_pozycje() + 1))//dla skrêtu
			{
				if ((Y - floor(Y) >= 0.89 && Y - floor(Y) <= 0.91) && Trasa.podaj_skret_nr(Trasa.podaj_aktualna_pozycje() + 1) == 2
					&& Trasa.podaj_nastepny_skret() == 1)
				{
					if (celX == poczX || celY == poczY)
					{
						NaZakrecie = 1;
					}
					if (NaZakrecie == 0)
					{
						NaZakrecie = 1;
					}
					else
					{
						Y = floor(Y);
						X = X + 0.9;
						Trasa.odswierz_pozycje();
						NaZakrecie = 2;
					}
				}
				else
				{
					if ((Y - floor(Y) >= 0.39 && Y - floor(Y) <= 0.41) && Trasa.podaj_skret_nr(Trasa.podaj_aktualna_pozycje() + 1) == 4
						&& Trasa.podaj_nastepny_skret() == 1)
					{
						if (celX == poczX || celY == poczY)
						{
							NaZakrecie = 1;
						}
						if (NaZakrecie == 0)
						{
							NaZakrecie = 1;
						}
						else
						{
							Y = floor(Y);
							X = X + 0.7;
							Trasa.odswierz_pozycje();
							NaZakrecie = 2;
						}
					}
					else
					{
						if ((Y - floor(Y) >= 0.59 && Y - floor(Y) <= 0.61) && Trasa.podaj_nastepny_skret() == 3
							&& Trasa.podaj_skret_nr(Trasa.podaj_aktualna_pozycje() + 1) == 2)
						{
							if (celX == poczX || celY == poczY)
							{
								NaZakrecie == 1;
							}
							if (NaZakrecie == 0)
							{
								NaZakrecie = 1;
							}
							else
							{
								Y = floor(Y);
								X = X + 0.6;
								Trasa.odswierz_pozycje();
								NaZakrecie = 2;
							}
						}
						else
						{
							if ((Y - floor(Y) >= 0.29 && Y - floor(Y) <= 0.31) && Trasa.podaj_nastepny_skret() == 3
								&& Trasa.podaj_skret_nr(Trasa.podaj_aktualna_pozycje() + 1) == 4)
							{
								if (celX == poczX || celY == poczY)
								{
									NaZakrecie = 1;
								}
								if (NaZakrecie == 0)
								{
									NaZakrecie = 1;
								}
								else
								{
									Y = floor(Y);
									X = X + 0.3;
									Trasa.odswierz_pozycje();
									NaZakrecie = 2;
								}
							}
							else
							{
								if ((X - floor(X) >= 0.59 && X - floor(X) <= 0.61) && Trasa.podaj_nastepny_skret() == 2
									&& Trasa.podaj_skret_nr(Trasa.podaj_aktualna_pozycje() + 1) == 1)
								{
									if (celX == poczX || celY == poczY)
									{
										NaZakrecie = 1;
									}
									if (NaZakrecie == 0)
									{
										NaZakrecie = 1;
									}
									else
									{
										X = floor(X);
										Y = Y + 0.8;
										Trasa.odswierz_pozycje();
										NaZakrecie = 2;
									}
								}
								else
								{
									if ((X - floor(X) >= 0.19 && X - floor(X) <= 0.21) && Trasa.podaj_nastepny_skret() == 2
										&& Trasa.podaj_skret_nr(Trasa.podaj_aktualna_pozycje() + 1) == 3)
									{

										if (celX == poczX || celY == poczY)
										{
											NaZakrecie = 1;
										}
										if (NaZakrecie == 0)
										{
											NaZakrecie = 1;
										}
										else
										{
											X = floor(X);
											Y = Y + 0.5;
											Trasa.odswierz_pozycje();
											NaZakrecie = 2;
										}
									}
									else
									{
										if ((X - floor(X) >= 0.79 && X - floor(X) <= 0.81) && Trasa.podaj_nastepny_skret() == 4
											&& Trasa.podaj_skret_nr(Trasa.podaj_aktualna_pozycje() + 1) == 1)
										{
											if (celX == poczX || celY == poczY)
											{
												NaZakrecie = 1;
											}
											if (NaZakrecie == 0)
											{
												NaZakrecie = 1;
											}
											else
											{
												X = floor(X);
												Y = Y + 0.4;
												Trasa.odswierz_pozycje();
												NaZakrecie = 2;
											}
										}
										else
										{
											if ((X - floor(X) >= 0.39 && X - floor(X) <= 0.41) && Trasa.podaj_nastepny_skret() == 4
												&& Trasa.podaj_skret_nr(Trasa.podaj_aktualna_pozycje() + 1) == 3)
											{
												if (celX == poczX || celY == poczY) {
													NaZakrecie = 1;
												}
												if (NaZakrecie == 0)
												{
													NaZakrecie = 1;
												}
												else
												{
													X = floor(X);
													Y = Y + 0.3;
													Trasa.odswierz_pozycje();
													NaZakrecie = 2;
												}

											}
										}
									}
								}
							}
						}
					}
				}
			}
		}

	}

	if ((NaZakrecie == 2 || NaZakrecie == 3) && (X - floor(X) >= -0.01 && X - floor(X) <= 0.01) && (Y - floor(Y) >= -0.01 && Y - floor(Y) <= 0.01))
	{
		//	if (NaZakrecie == 2)
			//{
		//		NaZakrecie = 3;
		//	}
		//	else
		//	{
		NaZakrecie = 0;
		WTrakcieManewru = 0;
		//	}
	}

	if ((Trasa.podaj_nastepny_skret() == 3 && Trasa.podaj_skret_nr(Trasa.podaj_aktualna_pozycje() - 1) == 4)
		|| (Trasa.podaj_nastepny_skret() == 3 && Trasa.podaj_skret_nr(Trasa.podaj_aktualna_pozycje() - 1) == 2)
		|| (Trasa.podaj_nastepny_skret() == 2 && Trasa.podaj_skret_nr(Trasa.podaj_aktualna_pozycje() - 1) == 1)
		|| (Trasa.podaj_nastepny_skret() == 2 && Trasa.podaj_skret_nr(Trasa.podaj_aktualna_pozycje() - 1) == 3))
	{
		NaZakrecie = 0;
		WTrakcieManewru = 0;
	}

}