/*
 * 5bit_su.h
 *
 *  Created on: 2016. 7. 3.
 *      Author: don
 */

#ifndef BIT_SU_H_
#define BIT_SU_H_

#include <cstdlib>
#include <algorithm>

#define FOR(index, init, max) for(int (index)=(init);(index)<(max);(index)++)

void check(unsigned long num1, unsigned long num2, unsigned long& firstNum, unsigned long& totalNum);

int num1, num2;
void five_bit()
{
	freopen("five_bit_input.txt","r", stdin);

	int testcase;
	scanf("%d", &testcase);
	FOR(t, 0 , testcase)
	{
		scanf("%d %d", &num1, &num2);

		unsigned long first, total;
		first=total=0;
		check(num1, num2, first, total);
		//printf("\r\n");
		printf("%lu %lu \r\n", total, first);
	}


}

//포함되어 있는 1의 비트수를 세어서, 5개이면 더한다.
void check(unsigned long num1, unsigned long num2, unsigned long& firstNum, unsigned long& totalNum)
{

	bool bFirst = false;

	for(unsigned long i=num1; i<=num2;i++)
	{
		int cnt = 0;
		int idx=0;
		unsigned long tmp = 0;
		do
		{
			tmp = 1<< idx;
			if(i & (tmp))
			{
				cnt++;
			}
			idx++;
		}
		while( tmp < num2);

		if(cnt==5)
		{
			if(bFirst == false)
			{
				firstNum = i;
				bFirst = true;
			}
			totalNum += i;
			//printf("%lu ", i);
		}
	}

}

#endif /* 5BIT_SU_H_ */
