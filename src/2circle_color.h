/*
 * 2circle_color.h
 *
 *  Created on: 2016. 6. 28.
 *      Author: don
 */

#ifndef CIRCLE_COLOR_H_
#define CIRCLE_COLOR_H_


#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

#define FOR(index, startValue, M) for(int index=(startValue);index<(M);(++index))

int V,G;
int array[1000][1000]={{0,}};

void bfs(int start);

void circle_color()
{

	FILE* fp1 = freopen("circle_color_input.txt", "r", stdin);
//	FILE* fp2 = freopen("circle_color_output.txt", "w", stdout);

	int testcase;
	scanf("%d", &testcase);
	FOR(t, 0, testcase)
	{
		scanf("%d %d", &V, &G );
		FOR(i,0,G)
		{
			int v1, v2;
			scanf("%d %d", &v1, &v2 );
			array[v1][v2] = 1;
			array[v2][v1] = 1;
		}
	}
	bfs(1);
	printf("end\n");
}

bool flags[1000];
void bfs(int start)
{
	std::queue<int> Q;
	Q.push(start);
	flags[start] = true;
	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		printf("%d ", v);

			FOR(i,1,V+1)
			{
				if(array[v][i]==1)
				{
					if(flags[i] != true)
					{
						Q.push(i);
						flags[i] = true;
					}
				}
			}


	}
	printf("\r\n");
}

//int compare(const void *a , const void *b){
//        return strcmp( (char*)a , (char*)b );
//}
//void test_qsort(int start)
//{
//	int i[]={1, 3, 5, 12, 3, 1};
//
//	std::qsort(i, sizeof(i)/sizeof(int), 4,compare);
//	FOR(j,0,6) printf("%d ", i[j]);
//	printf("\r\n");
//
//}


#endif /* 2CIRCLE_COLOR_H_ */
