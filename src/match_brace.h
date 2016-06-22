/*
 * match_brace.h
 *
 *  Created on: 2016. 6. 22.
 *      Author: don
 */

#ifndef MATCH_BRACE_H_
#define MATCH_BRACE_H_

#include <stdio.h>

#define FOR(i, n, m) for(int (i)=(n);(i)<(m);(i)++)

int testcase, input_length, target;
char input[10000];

int check(int length, int t);

void match_brace()
{
	setbuf(stdout, NULL);

	freopen("match_brace_input.txt", "r", stdin);
	freopen("match_brace_output.txt", "w", stdout);



	scanf("%d", &testcase);
	FOR(t, 0, testcase)
	{
		//init
		input_length=target=0;
		FOR(i, 0 , 10000) input[i] = '0';

		scanf("%d %d ", &input_length, &target);
		FOR(i,0,input_length)
		{
			scanf("%c", &input[i] );
		}
		scanf("\r\n");

		int ret= check(input_length, target);
		printf("#%d %d\r\n", t, ret);
	}



}

int check(int length, int t)
{
	int sum=0;
	FOR(i, 0, length)
	{
		if('('==input[i]) ++sum;
		else if(')'==input[i]) --sum;
		if(sum<0)
			return 0;
	}
	if(sum!=0)
		return 0;

	sum = 0;
	FOR(i,0,t)
	{
		if('('==input[i]) ++sum;
		else if(')'==input[i]) --sum;
	}
	FOR(i, t, length)
	{
		if('('==input[i]) ++sum;
		else if(')'==input[i]) --sum;

		if(sum==0)
			return i+1;// 순서 도메인으로 변환 (1부터 시작)
	}
	return 0;

}



#endif /* MATCH_BRACE_H_ */
