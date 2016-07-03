/*
 * moon_base.h
 *
 *  Created on: 2016. 7. 3.
 *      Author: don
 */

#ifndef MOON_BASE_H_
#define MOON_BASE_H_

#include <cstdlib>

#define FOR(index, init, max) for(int (index)=(init);(index)<(max);(index)++)
#define MIN_INIT 100000

int N;
char map[300][300];
int flag[300][300];//2번째 Testcase, 무한루프에 빠지는 경우가 있다. 무한루프 방지를 위해 추가함.

int g_Min;
enum dire{L, R ,U, D};
int dire[4][2]={{0,-1},{0,1},{-1,0},{1,0}};



void check(int y, int x, int d, int cnt);
int convertDire(char mirror, int d);

void moon_base()
{
	freopen("moon_base_input.txt", "r", stdin);

	int testcase;
	scanf("%d\r\n", &testcase);
	FOR(t, 0 , testcase)
	{
		//init
		N=0;
		g_Min=MIN_INIT;
		FOR(y, 0, 300)
		{
			FOR(x, 0 , 300)
			{
				map[y][x] = '\0';
				flag[y][x] = 0;
			}
		}

		scanf("%d\r\n", &N);
		FOR(y, 0, N)
		{
			FOR(x, 0 , N)
			{
				scanf("%c", &map[y][x]);
			}
			scanf("\r\n");
		}

		FOR(y, 0, N)
		{
			FOR(x, 0 , N)
			{
				if(map[y][x]=='T')
				{
					check(y,x,R,0);
					printf("#%d %d\r\n", t, g_Min==MIN_INIT?-1:g_Min);
				}
			}
		}



	}

	printf("end \r\n");
}



void check(int y, int x, int d, int cnt)
{
	y = y+dire[d][0];
	x = x+dire[d][1];

	if(y<0 || y>=N || x<0 || x>=N || map[y][x]=='0' || map[y][x]=='T')
		return;
	if(cnt>=g_Min)
		return;
	if(map[y][x]=='S')
	{
		if(g_Min>cnt)
			g_Min=cnt;
		return;
	}



	if(map[y][x]=='R' && flag[y][x]==0)
	{
		flag[y][x]=1;
		check(y, x, convertDire('R',d), cnt);
		check(y, x, convertDire('L',d), ++cnt);
	}

	else if( map[y][x]=='L' && flag[y][x]==0)
	{
		flag[y][x]=1;
		check(y, x, convertDire('L',d), cnt);
		check(y, x, convertDire('R',d), ++cnt);
	}
	else
	{
		check(y, x, d, cnt);
	}

	return;

}

int convertDire(char mirror, int d)
{
	switch(d)
	{
		case L:
			if(mirror=='L') return D;
			if(mirror=='R') return U;
			break;
		case R:
			if(mirror=='L') return U;
			if(mirror=='R') return D;
			break;
		case U:
			if(mirror=='L') return R;
			if(mirror=='R') return L;
			break;
		case D:
			if(mirror=='L') return L;
			if(mirror=='R') return R;
			break;
	}
	return d;
}





#endif /* MOON_BASE_H_ */
