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
	FOR(size, 3, length+1)//���ڿ� ���� 100���ΰ� ���� ����.
	{
		FOR(i, 0, length-size+1)//10������ 10���� ȸ������ �˻��Ҷ��� �����غ��� +1 �ϴ� ������ �˼� ����.
		{
			char test[101]={'\0',};
			char test2[101]={'\0',};

			//�κ� ���ڿ�.
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
