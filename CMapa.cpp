#pragma once
#include "CMapa.h"

CMapa::CMapa()
{
	tworz_mape();
}

void CMapa::tworz_mape()
{
	Mapa_samoch[0][0] = 0;
	Mapa_samoch[1][0] = 2;
	Mapa_samoch[2][0] = 0;
	Mapa_samoch[3][0] = 2;
	Mapa_samoch[4][0] = 0;
	Mapa_samoch[5][0] = 2;
	Mapa_samoch[6][0] = 2;
	Mapa_samoch[7][0] = 0;
	Mapa_samoch[8][0] = 2;
	Mapa_samoch[9][0] = 2;
	Mapa_samoch[10][0] = 2;
	Mapa_samoch[11][0] = 0;
	Mapa_samoch[12][0] = 0;

	Mapa_samoch[0][1] = 0;
	Mapa_samoch[1][1] = 2;
	Mapa_samoch[2][1] = 0;
	Mapa_samoch[3][1] = 2;
	Mapa_samoch[4][1] = 0;
	Mapa_samoch[5][1] = 2;
	Mapa_samoch[6][1] = 2;
	Mapa_samoch[7][1] = 0;
	Mapa_samoch[8][1] = 2;
	Mapa_samoch[9][1] = 2;
	Mapa_samoch[10][1] = 2;
	Mapa_samoch[11][1] = 0;
	Mapa_samoch[12][1] = 0;

	Mapa_samoch[0][2] = 1;
	Mapa_samoch[1][2] = 3;
	Mapa_samoch[2][2] = 1;
	Mapa_samoch[3][2] = 3;
	Mapa_samoch[4][2] = 1;
	Mapa_samoch[5][2] = 3;
	Mapa_samoch[6][2] = 3;
	Mapa_samoch[7][2] = 1;
	Mapa_samoch[8][2] = 3;
	Mapa_samoch[9][2] = 3;
	Mapa_samoch[10][2] = 3;
	Mapa_samoch[11][2] = 1;
	Mapa_samoch[12][2] = 1;

	Mapa_samoch[0][3] = 1;
	Mapa_samoch[1][3] = 3;
	Mapa_samoch[2][3] = 1;
	Mapa_samoch[3][3] = 3;
	Mapa_samoch[4][3] = 1;
	Mapa_samoch[5][3] = 3;
	Mapa_samoch[6][3] = 3;
	Mapa_samoch[7][3] = 1;
	Mapa_samoch[8][3] = 3;
	Mapa_samoch[9][3] = 3;
	Mapa_samoch[10][3] = 3;
	Mapa_samoch[11][3] = 1;
	Mapa_samoch[12][3] = 1;

	Mapa_samoch[0][4] = 0;
	Mapa_samoch[1][4] = 2;
	Mapa_samoch[2][4] = 0;
	Mapa_samoch[3][4]  = 2;
	Mapa_samoch[4][4] = 0;
	Mapa_samoch[5][4] = 2;
	Mapa_samoch[6][4] = 2;
	Mapa_samoch[7][4] = 0;
	Mapa_samoch[8][4] = 2;
	Mapa_samoch[9][4] = 2;
	Mapa_samoch[10][4] = 2;
	Mapa_samoch[11][4] = 0;
	Mapa_samoch[12][4] = 0;

	Mapa_samoch[0][5] = 1;
	Mapa_samoch[1][5] = 3;
	Mapa_samoch[2][5] = 1;
	Mapa_samoch[3][5] = 3;
	Mapa_samoch[4][5] = 1;
	Mapa_samoch[5][5] = 4;
	Mapa_samoch[6][5] = 3;
	Mapa_samoch[7][5] = 1;
	Mapa_samoch[8][5] = 4;
	Mapa_samoch[9][5] = 3;
	Mapa_samoch[10][5] = 3;
	Mapa_samoch[11][5] = 1;
	Mapa_samoch[12][5] = 1;

	Mapa_samoch[0][6] = 1;
	Mapa_samoch[1][6] = 4;
	Mapa_samoch[2][6] = 1;
	Mapa_samoch[3][6] = 3;
	Mapa_samoch[4][6] = 1;
	Mapa_samoch[5][6] = 3;
	Mapa_samoch[6][6] = 4;
	Mapa_samoch[7][6] = 1;
	Mapa_samoch[8][6] = 3;
	Mapa_samoch[9][6] = 3;
	Mapa_samoch[10][6] = 4;
	Mapa_samoch[11][6] = 1;
	Mapa_samoch[12][6] = 1;

	Mapa_samoch[0][7] = 1;
	Mapa_samoch[1][7] = 3;
	Mapa_samoch[2][7] = 1;
	Mapa_samoch[3][7] = 3;
	Mapa_samoch[4][7] = 1;
	Mapa_samoch[5][7] = 4;
	Mapa_samoch[6][7] = 3;
	Mapa_samoch[7][7] = 1;
	Mapa_samoch[8][7] = 4;
	Mapa_samoch[9][7] = 3;
	Mapa_samoch[10][7] = 3;
	Mapa_samoch[11][7] = 1;
	Mapa_samoch[12][7] = 1;

	Mapa_samoch[0][8] = 0;
	Mapa_samoch[1][8] = 2;
	Mapa_samoch[2][8] = 0;
	Mapa_samoch[3][8] = 2;
	Mapa_samoch[4][8] = 0;
	Mapa_samoch[5][8] = 2;
	Mapa_samoch[6][8] = 2;
	Mapa_samoch[7][8] = 0;
	Mapa_samoch[8][8] = 2;
	Mapa_samoch[9][8] = 2;
	Mapa_samoch[10][8] = 2;
	Mapa_samoch[11][8] = 0;
	Mapa_samoch[12][8] = 0;

	Mapa_samoch[0][9] = 1;
	Mapa_samoch[1][9] = 3;
	Mapa_samoch[2][9] = 1;
	Mapa_samoch[3][9] = 3;
	Mapa_samoch[4][9] = 1;
	Mapa_samoch[5][9] = 3;
	Mapa_samoch[6][9] = 3;
	Mapa_samoch[7][9] = 1;
	Mapa_samoch[8][9] = 3;
	Mapa_samoch[9][9] = 3;
	Mapa_samoch[10][9] = 3;
	Mapa_samoch[11][9] = 1;
	Mapa_samoch[12][9] = 1;

	Mapa_samoch[0][10] = 1;
	Mapa_samoch[1][10] = 3;
	Mapa_samoch[2][10] = 1;
	Mapa_samoch[3][10] = 3;
	Mapa_samoch[4][10] = 1;
	Mapa_samoch[5][10] = 4;
	Mapa_samoch[6][10] = 4;
	Mapa_samoch[7][10] = 1;
	Mapa_samoch[8][10] = 3;
	Mapa_samoch[9][10] = 3;
	Mapa_samoch[10][10] = 3;
	Mapa_samoch[11][10] = 1;
	Mapa_samoch[12][10] = 1;

	Mapa_samoch[0][11] = 0;
	Mapa_samoch[1][11] = 2;
	Mapa_samoch[2][11] = 0;
	Mapa_samoch[3][11] = 2;
	Mapa_samoch[4][11] = 0;
	Mapa_samoch[5][11] = 2;
	Mapa_samoch[6][11] = 2;
	Mapa_samoch[7][11] = 0;
	Mapa_samoch[8][11] = 2;
	Mapa_samoch[9][11] = 2;
	Mapa_samoch[10][11] = 2;
	Mapa_samoch[11][11] = 0;
	Mapa_samoch[12][11] = 0;

	Mapa_samoch[0][12] = 0;
	Mapa_samoch[1][12] = 2;
	Mapa_samoch[2][12] = 0;
	Mapa_samoch[3][12] = 2;
	Mapa_samoch[4][12] = 0;
	Mapa_samoch[5][12] = 2;
	Mapa_samoch[6][12] = 2;
	Mapa_samoch[7][12] = 0;
	Mapa_samoch[8][12] = 2;
	Mapa_samoch[9][12] = 2;
	Mapa_samoch[10][12] = 2;
	Mapa_samoch[11][12] = 0;
	Mapa_samoch[12][12] = 0;

	Mapa_samoch[0][13] = 1;
	Mapa_samoch[1][13] = 3;
	Mapa_samoch[2][13] = 1;
	Mapa_samoch[3][13] = 4;
	Mapa_samoch[4][13] = 1;
	Mapa_samoch[5][13] = 3;
	Mapa_samoch[6][13] = 3;
	Mapa_samoch[7][13] = 1;
	Mapa_samoch[8][13] = 3;
	Mapa_samoch[9][13] = 4;
	Mapa_samoch[10][13] = 3;
	Mapa_samoch[11][13] = 1;
	Mapa_samoch[12][13] = 1;

	Mapa_samoch[0][14] = 1;
	Mapa_samoch[1][14] = 3;
	Mapa_samoch[2][14] = 1;
	Mapa_samoch[3][14] = 3;
	Mapa_samoch[4][14] = 1;
	Mapa_samoch[5][14] = 3;
	Mapa_samoch[6][14] = 3;
	Mapa_samoch[7][14] = 1;
	Mapa_samoch[8][14] = 3;
	Mapa_samoch[9][14] = 3;
	Mapa_samoch[10][14] = 3;
	Mapa_samoch[11][14] = 1;
	Mapa_samoch[12][14] = 1;

	Mapa_samoch[0][15] = 1;
	Mapa_samoch[1][15] = 3;
	Mapa_samoch[2][15] = 1;
	Mapa_samoch[3][15] = 3;
	Mapa_samoch[4][15] = 1;
	Mapa_samoch[5][15] = 3;
	Mapa_samoch[6][15] = 3;
	Mapa_samoch[7][15] = 1;
	Mapa_samoch[8][15] = 3;
	Mapa_samoch[9][15] = 3;
	Mapa_samoch[10][15] = 3;
	Mapa_samoch[11][15] = 1;
	Mapa_samoch[12][15] = 1;

	Mapa_samoch[0][16] = 0;
	Mapa_samoch[1][16] = 2;
	Mapa_samoch[2][16] = 0;
	Mapa_samoch[3][16] = 2;
	Mapa_samoch[4][16] = 0;
	Mapa_samoch[5][16] = 2;
	Mapa_samoch[6][16] = 2;
	Mapa_samoch[7][16] = 0;
	Mapa_samoch[8][16] = 2;
	Mapa_samoch[9][16] = 2;
	Mapa_samoch[10][16] = 2;
	Mapa_samoch[11][16] = 0;
	Mapa_samoch[12][16] = 0;

	Mapa_samoch[0][17] = 0;
	Mapa_samoch[1][17] = 2;
	Mapa_samoch[2][17] = 0;
	Mapa_samoch[3][17] = 2;
	Mapa_samoch[4][17] = 0;
	Mapa_samoch[5][17] = 2;
	Mapa_samoch[6][17] = 2;
	Mapa_samoch[7][17] = 0;
	Mapa_samoch[8][17] = 2;
	Mapa_samoch[9][17] = 2;
	Mapa_samoch[10][17] = 2;
	Mapa_samoch[11][17] = 0;
	Mapa_samoch[12][17] = 0;

	Mapa_samoch[0][18] = 0;
	Mapa_samoch[1][18] = 2;
	Mapa_samoch[2][18] = 0;
	Mapa_samoch[3][18] = 2;
	Mapa_samoch[4][18] = 0;
	Mapa_samoch[5][18] = 2;
	Mapa_samoch[6][18] = 2;
	Mapa_samoch[7][18] = 0;
	Mapa_samoch[8][18] = 2;
	Mapa_samoch[9][18] = 2;
	Mapa_samoch[10][18] = 2;
	Mapa_samoch[11][18] = 0;
	Mapa_samoch[12][18] = 0;
}

int CMapa::podaj_mape(int i, int j)
{
	return  Mapa_samoch[i][j];
}