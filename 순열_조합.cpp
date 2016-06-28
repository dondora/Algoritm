#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
#define FOR(i,n,m) for(int (i)=(n);(i)<(m);(i)++)

void P(vector<int>& v, int r);
void P(int n, vector<int>& v, int r);
void C(int n, vector<int>& v, int r);

int main(int argc, char** argv)
{
	printf("순열 \r\n");
	vector<int> v;
	v.clear();
	P(5, v, 4);

	printf("조합 \r\n");
	v.clear();
	C(5, v, 4);

	printf("next_permutation \r\n");
	int a[] = {1,2,3,4,5};
	v.assign(a,a+5);
	P(v, 4);

}

bool flag[50];
void P(int n, vector<int>& v, int r)
{
	if(r==0)
	{
		FOR(i,0,v.size()) 
			printf("%d ", v[i]);
		printf("\r\n");
		return;
	}

	FOR(i, 1, n+1)
	{		
		if(flag[i]!=true)
		{
			flag[i]=true;
			v.push_back(i);
			P(n, v, r-1);
			flag[i]=false;
			v.pop_back();
		}
		
	}
}


void C(int n, vector<int>& v, int r)
{
	if(r==0)
	{
		FOR(i,0,v.size()) 
			printf("%d ", v[i]);
		printf("\r\n");
		return;
	}

	int small = (v.size()==0)? 1 : v.back()+1;
	FOR(i, small, n+1)
	{
		v.push_back(i);
		C(n, v, r-1);
		v.pop_back();
	}
}

void P(vector<int>& v, int r)
{
	do 
	{
		FOR(i, 0, r)
			printf("%d ", v[i]);
		printf("\r\n");
	} while (std::next_permutation(v.begin(),v.end()));	
}


