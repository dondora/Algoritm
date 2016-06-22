/*
 * circular_string.h
 *
 *  Created on: 2016. 6. 22.
 *      Author: don
 */

#ifndef CIRCULAR_STRING_H_
#define CIRCULAR_STRING_H_

#include <cstdio>
#include <string.h>

#define FOR(i, n, m) for(int (i)=(n);(i)<(m);(i)++)

int length;
char str[101];

int check();

void circular_string()
{
	setbuf(stdout, NULL);

	freopen("circular_string_input.txt", "r", stdin);
	freopen("circular_string_output.txt", "w", stdout);

	int testcase;
	scanf("%d", &testcase);
	FOR(t, 0, testcase)
	{
		//init
		length=0;
		FOR(i,0,100) str[i]='\0';

		scanf("%d %s", &length, str);
		int ret = check();
		printf("#%d %d \r\n", t, ret);
	}
}

int check()
{
	int max=0;
	FOR(size, 3, length+1)//문자열 길이 100자인것 까지 포함.
	{
		FOR(i, 0, length-size+1)//10글자중 10개가 회문임을 검사할때를 생각해보면 +1 하는 이유를 알수 있음.
		{
			char test[101]={'\0',};
			char test2[101]={'\0',};

			//부분 문자열.
			strncpy(test, str+i, size);

			//reverse string
			FOR(k,0,size)
			{
				test2[k]=test[size-1-k];
			}

			if(strcmp(test, test2)==0)
			{
				if(max<size)
					max=size;
			}
		}
	}
	return max;
}


#endif /* CIRCULAR_STRING_H_ */
