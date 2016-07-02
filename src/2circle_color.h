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

bool color[1000];
bool flag[1000];

int check();
void circle_color()
{

	FILE* fp1 = freopen("circle_color_input.txt", "r", stdin);
//	FILE* fp2 = freopen("circle_color_output.txt", "w", stdout);

	int testcase;
	scanf("%d", &testcase);
	FOR(t, 0, testcase)
	{
		//init
		FOR(i,0,1000)
			FOR(j,0,1000) array[i][j]=0;
		FOR(i,0,1000)
		{
			color[i]=false;
			flag[i]=false;
		}

		scanf("%d %d", &V, &G );
		FOR(i,0,G)
		{
			int v1, v2;
			scanf("%d %d", &v1, &v2 );
			array[v1][v2] = 1;
			array[v2][v1] = 1;
		}
		int ret = check();
		if(ret>0)
		{
			printf("%d ", ret);
			FOR(i,0,V)
			{
				if(color[i]==true)
					printf("%d ", i);
			}
			printf("\r\n");

		}
		else
		{
			printf("-1\n");
		}

	}

	printf("end\n");
}


int check()
{

	color[1]=true;//white
	flag[1]=true;

	int cnt=1;

	FOR(s,1,V+1)
	{
		if (flag[s] == true) {
			FOR(t, 1, V+1)//모든 정점을 순회하자...
			{
				if (array[s][t] == 1) {
					if (flag[t] == true && color[t] == color[s])
						return -1;
					if (flag[t] != true) {
						flag[t] = true;
						color[t] = !color[s];
						if(color[t]==true)
							cnt++;
					}
				}
			}
		}
	}
	return cnt;
}

/*
bool flags[1000];
int color[1000];

void bfs(int start)
{
	bool curColor = 1;//0:none, 1:w , 2:b
	std::queue<int> Q;
	Q.push(start);
	flags[start] = true;
	color[start] = curColor;
	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		printf("%d ", v);

		if(color[v]==1) curColor=2;
		if(color[v]==2) curColor=1;


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
	FOR(i,0,V) printf("%s ", color[i]?"white":"black");
	printf("\r\n");
	printf("\r\n");
}
*/

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
