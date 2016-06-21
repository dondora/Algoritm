/*
 * Algo1.cpp
 * 짝맞추기 게임?
 *  Created on: 2016. 5. 25.
 *      Author: don
 */

#include "Algo1.h"
#include <stdio.h>
#include "Common.h"


int g_count = 0;

int SelectPair(int pair[][10], int nMatchedFrieds, int nHaksangSu, bool bSelected[]);

void algo1() {

	FILE* fp1=freopen("algo1_input.txt", "r", stdin);
	FILE* fp2=freopen("algo1_output.txt", "w", stdout);

	printf("Case start \n");

	int T, i, j;
	int test_case, nHaksangSu, nMatchedFrieds;
	int pair[10][10]={{0,},};
	bool bSelected[10] = { false, };
	bool bSelectedPair[45] = {false,};

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case) {

		/**initialize*/
		/*initialize end */
		printf("Case #%d start\n", test_case);

		scanf("%d %d", &nHaksangSu, &nMatchedFrieds);

		FOR(i, 0, nMatchedFrieds)
		{
			int l, r;
			scanf("%d %d", &l, &r);
			pair[l][r] = true;
		}

		//algorithm.
		SelectPair(pair, nMatchedFrieds, nHaksangSu, bSelected);
		printf("%d\n", g_count);

		printf("Case #%d end\n", test_case);
	}
}

int SelectPair(int pair[][10], int nMatchedFrieds, int nHaksangSu,
		bool bSelected[]) {
	int i, j, count;
	bool bAllSearched = false;
	i = j = 0;

	FOR(i,0,nHaksangSu)
	{
		if (!bSelected[i]) {
			break;
		}

		if (i == nHaksangSu - 1)
			bAllSearched = true;
	}
	if (bAllSearched)
		return g_count++;

	FOR(i, 0, nHaksangSu)
	{
		FOR(j, 0, nHaksangSu)
		{
			if (!bSelected[i] && !bSelected[j] && pair[i][j]) {

				bSelected[i] = bSelected[j] = true;
				SelectPair(pair, nMatchedFrieds, nHaksangSu, bSelected);
				bSelected[i] = bSelected[j] = false;
			}
		}
	}
	return 0;
}

