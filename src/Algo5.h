/*
 * Algo5.h
 * 반사경
 *  Created on: 2016. 6. 21.
 *      Author: don
 */

#ifndef ALGO5_H_
#define ALGO5_H_

#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

#define FOR(index, startValue, M) for(int index=(startValue);index<(M);(++index))

int testcase, N;
int bang[100][100];

//왼쪽: 0
//위쪽 : 1
//오른쪽: 2
//아래쪽 : 3

int check(int y, int x, int direction);
int convertDire(int inputDire, int mirror);
void algo5() {

	FILE* fp1 = freopen("algo5_input.txt", "r", stdin);
	FILE* fp2 = freopen("algo5_output.txt", "w", stdout);

	scanf("%d", &testcase);
	FOR(t, 0, testcase)
	{
		scanf("%d\n", &N);

		FOR(y,0,N)
		{
			FOR(x,0,N)
			{
				bang[y][x] = -1;
			}
		}

		FOR(y,0,N)
		{
			FOR(x,0,N)
			{
				scanf("%d ", &bang[y][x]);
			}
			scanf("\r\n");
		}

		int sum = check(0, 0, 2);
		printf("#%d %d \n", t, sum);
	}

	fclose(fp2);
	fclose(fp1);
}

//왼쪽: 0
//위쪽 : 1
//오른쪽: 2
//아래쪽 : 3

int check(int y, int x, int d)
{

	int dire[4][2] = { { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 } };
	if (y < 0 || x < 0 || y >= N || x >= N)
		return 0;
	else
	{
		FOR(i, 0, N)
		{
			int modY = y+dire[d][0]*(i+1);
			int modX = x+dire[d][1]*(i+1);

			if (modY < 0 || modX < 0 || modY >= N || modX >= N)
				return 0;

			if(bang[modY][modX]==1)
			{
				return check(modY, modX, convertDire(d, 1))+1;
			}
			else if(bang[modY][modX]==2)
			{
				return check(modY, modX, convertDire(d, 2))+1;
			}
		}
	}
	return 0;
}

//왼쪽: 0
//위쪽 : 1
//오른쪽: 2
//아래쪽 : 3
int convertDire(int inputDire, int mirror)
{
	switch(mirror)
	{
		case 1:
		{
			switch(inputDire)
			{
				case 0:	return 3;
				case 1: return 2;
				case 2: return 1;
				case 3: return 0;
			}
			break;
		}
		case 2:
		{
			switch(inputDire)
			{
				case 0:	return 1;
				case 1: return 0;
				case 2: return 3;
				case 3: return 2;
			}
			break;
		}
	}
	return -1;
}

#endif /* ALGO5_H_ */
