#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int N;
char map[300][300];
bool visited[300][300];
enum dire{L,R,U,D};
typedef struct _Mirror
{
	int y;
	int x;
	char type;
	int d;
	int cnt;

}Mirror;

dire changeDirection(char type, int d)
{
	switch (d)
	{
	case L:
		if (type == 'L')
			return D;
		if (type == 'R')
			return U;
	case R:
		if (type == 'L')
			return U;
		if (type == 'R')
			return D;
	case U:
		if (type == 'L')
			return R;
		if (type == 'R')
			return L;
	case D:
		if (type == 'L')
			return L;
		if (type == 'R')
			return R;
	}
}

//y,x 는 첫 mirror의 위치.
int direction[4][2] = { { 0,-1 },{ 0,1 },{ -1,0 },{ 1,0 } };
int check(int y, int x, char type)
{
	int minRotate = 99999;

	stack<Mirror> s;
	Mirror m1, m2;
	if (type == 'L')
	{
		m1 = { y,x,'L',changeDirection('L',R),0};
		m2 = { y,x,'R',changeDirection('R',R),1};
	}
	else
	{
		m1 = { y,x,'L',changeDirection('L',R), 1 };
		m2 = { y,x,'R',changeDirection('R',R) , 0 };
	}	
	s.push(m1);
	s.push(m2);

	while (!s.empty())
	{
		Mirror m = s.top();
		s.pop();		

		if (m.cnt > minRotate)//prunning
			break;		

		int modY = m.y;
		int modX = m.x;
		while (true)
		{
			modY += direction[m.d][0];
			modX += direction[m.d][1];			

			if (map[modY][modX] == 'S')
			{
				if (minRotate > m.cnt)
				{
					minRotate = m.cnt;
				}				
			}			

			if (modY < 0 || modX < 0 || modY>N || modX>N || map[modY][modX] == '0')
			{
				break;
			}
			if (map[modY][modX] == 'L' && visited[modY][modX]==false)
			{
				visited[modY][modX] = true;
				Mirror m1 = { modY,modX,'L',changeDirection('L',m.d), m.cnt};
				Mirror m2 = { modY,modX,'R',changeDirection('R',m.d), m.cnt+1};
				s.push(m1);
				s.push(m2);
				break;
			}
			if (map[modY][modX] == 'R' && visited[modY][modX] == false)
			{
				visited[modY][modX] = true;
				Mirror m1 = { modY,modX,'L',changeDirection('L',m.d), m.cnt+1 };
				Mirror m2 = { modY,modX,'R',changeDirection('R',m.d), m.cnt};
				s.push(m1);
				s.push(m2);
				break;
			}
		}
	}
	if (minRotate == 99999)
		return -1;
	return minRotate;
}

int main()
{
	freopen("Text.txt", "r", stdin);

	int testcase;
	scanf("%d\n", &testcase);
	for (int t = 0; t < testcase; t++)
	{
		//init
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				map[y][x] = '\0';
				visited[y][x] = false;
			}
		}

		int tY, tX, sY,sX;
		scanf("%d\n", &N);
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				scanf("%c", &map[y][x]);
				if (map[y][x] == 'T')
				{
					tY = y;
					tX = x;
				}
			}
			scanf("\n");
		}

		int mY = tY;
		int mX = tX;
		char type;
		while (true)
		{
			if (map[mY][mX] == 'L' || map[mY][mX] == 'R')
			{
				type = map[mY][mX];
				break;
			}
			mX++;
		}
		int ret = check(mY, mX, type);
		printf("#%d : %d\n", t, ret);		
	}

	return 0;
}
