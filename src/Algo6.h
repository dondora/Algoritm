/*
 * Algo6.h
 * 정수 그룹의 합
 *  Created on: 2016. 6. 21.
 *      Author: don
 */

#ifndef ALGO6_H_
#define ALGO6_H_

#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

#define FOR(index, startValue, M) for(int index=(startValue);index<(M);(++index))

int testcase;
int su[6], sum[21];

void check(int& a, int& b);
void algo6() {

	FILE* fp1 = freopen("algo6_input.txt", "r", stdin);
	FILE* fp2 = freopen("algo6_output.txt", "w", stdout);

	scanf("%d", &testcase);
	FOR(t, 0, testcase)
	{
		FOR(i,0,6)
		{
			scanf("%d ", &su[i]);
		}

		int a, b;
		check(a, b);
		printf("#%d %d %d \n", t, a, b);
	}

	fclose(fp2);
	fclose(fp1);
}

void check(int& a, int& b) {
	int total = 0;
	FOR(l,0,6)
	{
		total+=su[l];
	}

	int retA, retB;
	int min = (1<<31)-1;

	FOR(i,0,6)
	{
		FOR(j,i+1,6)
		{
			FOR(k, j+1, 6)
			{
				int aa = su[i]+su[j]+su[k];
				int bb = total-aa;
				int minV = abs(bb-aa);
				if(min>minV)
				{
					min = minV;
					a=aa;
					b=bb;
				}
			}
		}
	}
}

#endif /* ALGO6_H_ */
