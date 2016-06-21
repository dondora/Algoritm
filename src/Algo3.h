/*

 * algo3.h
 * 둬 원 사이의 사각형 문제
 *  Created on: 2016. 6. 18.
 *      Author: don
 *
 *      원과 1x1의 접점을 이용
 */

#ifndef ALGO3_H_
#define ALGO3_H_

#include "math.h"
#include "Common.h"
#include <stdio.h>


int g_R, g_r;
int graph[100][100];

bool isAvailRect(int in_R, int in_r, int y, int x);

void algo3() {

	FILE* fp1 = freopen("algo3_input.txt", "r", stdin);
	FILE* fp2 = freopen("algo3_output.txt", "w", stdout);

	int testcase;
	scanf("%d", &testcase);
	int i, x, y, k ;
	FOR(i,0,testcase)
	{
		scanf("%d %d", &g_r, &g_R);
		{
			int sum=0;
			FOR(y, 1, g_R)
			{
				FOR(x, 1, g_R)
				{
					if(isAvailRect(g_R, g_r, y, x))
						++sum;
				}
			}
			printf("#%d : %d\n", i, sum*4);
		}
	}
}


bool isAvailRect(int in_R, int in_r, int y, int x) {
	if ((y * y) + (x * x) <= in_R * in_R) {
		if ((y - 1) * (y - 1) + (x - 1) * (x - 1) >= in_r * in_r) {
			return true;
		}
	}
	return false;
}



#endif /* ALGO3_H_ */
