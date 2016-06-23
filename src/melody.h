/*
 * melody.h
 * Issue
 * 1. 문자배열과, 정수배열의 선택
 * 2. 비교방법
 *  Created on: 2016. 6. 23.
 *      Author: don
 */

#ifndef MELODY_H_
#define MELODY_H_

#include <stdio.h>
#include <string.h>

#define FOR(i, n, m) for(int (i)=(n);(i)<(m);(i)++)

int input_length, target;
int input[3001];

int check(int length, int t);

void melody()
{
	setbuf(stdout, NULL);

	freopen("melody_input.txt", "r", stdin);
	freopen("melody_output.txt", "w", stdout);


	int testcase;
	scanf("%d", &testcase);
	FOR(t, 0, testcase)
	{
		//init
		input_length=0;
		FOR(i,0,3001) input[i]= -1;

		scanf("%d\r\n", &input_length);
		FOR(i, 0 ,input_length)
		{
			scanf("%d ", &input[i]);
		}
		scanf("\r\n");


		int maxMatchCnt = 0;
		int retLen=0;
		FOR(selectLen, 1,input_length+1) //선택하는 멜로디 갯수
		{
			int subject[3001];
			FOR(n, 0, 3001) subject[n]=-1;

			FOR(l, 0, selectLen) subject[l] = input[l];

			int s=0;//비교 대상의 시작 인덱스
			int matchCnt = 0;
			while(s+selectLen-1<=input_length)
			{
				int object[3001];
				FOR(n, 0, 3001) object[n]=-1;

				FOR(m, 0, selectLen) object[m] = input[s+m];

				//compare
				bool flag = true;
				FOR(k, 0, selectLen)
				{
					if(subject[k]!=object[k])
					{
						flag=false;
						break;
					}
				}
				if(flag)
					matchCnt++;

				if(maxMatchCnt<=matchCnt)
				{
					maxMatchCnt = matchCnt;
					retLen=selectLen;
				}
				++s;
			}
		}

		printf("#%d %d \r\n", t, retLen);


	}
}



#endif /* MELODY_H_ */
