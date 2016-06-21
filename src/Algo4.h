/*
 * Algo4.h
 *  난수 패턴
 *  Created on: 2016. 6. 21.
 *      Author: don
 */

#ifndef ALGO4_H_
#define ALGO4_H_

#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

#define FOR(index, startValue, M) for(int index=(startValue);index<(M);(++index))

int testcase, N, g_Min, g_Max;
int bang[50][50];

void check(int y, int x);

void algo4() {

	FILE* fp1 = freopen("algo4_input.txt", "r", stdin);
	FILE* fp2 = freopen("algo4_output.txt", "w", stdout);

	scanf("%d", &testcase);
	FOR(t, 0, testcase)
	{
		FOR(y,0,N)
		{
			FOR(x,0,N)
			{
				bang[y][x] = -1;
			}
		}

		g_Max = g_Min = 0;

		scanf("%d\n", &N);
		FOR(y,0,N)
		{
			FOR(x,0,N)
			{
				scanf("%d ", &bang[y][x]);
			}
			scanf("\r\n");
		}

		FOR(y,1,N-1)
		{
			FOR(x,1,N-1)
			{
				check(y, x);
			}
		}
		printf("#%d %d %d \n", t, g_Max, g_Min);
	}

	fclose(fp2);
	fclose(fp1);
}

void check(int y, int x) {
	int dire[8][2] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };

	int target = bang[y][x];
	bool bMax = true;
	bool bMin = true;
	FOR(d,0,8)
	{
		int modY = y + dire[d][0];
		int modX = x + dire[d][1];
		int compare = bang[modY][modX];
		if (target <= compare) {
			bMax = false;
		}
		if (target >= compare) {
			bMin = false;
		}
	}
	if (bMax)
		g_Max++;
	if (bMin)
		g_Min++;
}

#endif /* ALGO4_H_ */
