/*
 * Algo2.h
 * 문제4 총잡이
 *  Created on: 2016. 6. 18.
 *      Author: don
 */

#ifndef ALGO2_H_
#define ALGO2_H_

#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
//W : 벽
//

#define FOR(index, startValue, M) for(int index=(startValue);index<(M);(++index))


int testcase, Y, X;
char bang[20][20] = { { 0, }, };
int G, T; //총잡이, 목표물

int check(int y, int x);

void algo2() {

	FILE* fp1 = freopen("algo2_input.txt", "r", stdin);
	FILE* fp2 = freopen("algo2_output.txt", "w", stdout);

	int t, y, x, k;

	scanf("%d", &testcase);
	FOR(t, 0, testcase)
	{
		scanf("%d %d\n", &Y, &X);

		FOR(y,0,Y)
		{
			gets(bang[y]);
		}

		int sum = 0;
		FOR(y,0,Y)
		{
			FOR(x,0,X)
			{
				if (bang[y][x] == 'T' && check(y, x) >= 1)
					++sum;
			}
		}
		printf("#%d: %d \n", t, sum);
	}

	fclose(fp2);
	fclose(fp1);


}

int check(int y, int x) {
	int direction[4][2] = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } }; //아래, 위, 왼쪽, 오른쪽
	int k, l;

	int count = 0;

	FOR(k,0,4)
	{
		FOR(l,0,std::max(Y,X))
		{
			int modY = y + direction[k][0] * (l + 1);
			int modX = x + direction[k][1] * (l + 1);

			if (modY < 0 || modX < 0 || modX >= X || modY >= Y)
				break;
			if (bang[modY][modX] == 'W' || bang[modY][modX] == 'T')
				break;
			else if (bang[modY][modX] == 'G') {
				count++;
				break;
			}
		}
	}
	return count;
}

#endif /* ALGO2_H_ */
