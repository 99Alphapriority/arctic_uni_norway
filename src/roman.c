#include<stdlib.h>
#include<stdio.h>
#include"roman.h"

char *int_to_roman(int val)
{
	char *ans = (char*)calloc(20,sizeof(char));		//allocate memory to store the final roman string and initialise it with 0 value
	int idx = 0;
	/*
	 * This loop will convert the provided integer value to roman numeral.
	 * It starts by converting the largest integer value to roman numeral and then subtrating that largest
	 * value from the original value.
	 * Added checks for when the value encounters subtractive notation condition like 900,400,90,40,9 and 4.
	 */ 
	while(val != 0)
	{
		if(val>=1000)
		{
			ans[idx++] = 'M';
			val -= 1000;
		}
		else if(val>=900)
		{
			ans[idx++] = 'C';
			ans[idx++] = 'M';
			val -=900;
		}
		else if(val>=500)
		{
			ans[idx++] = 'D';
			val -= 500;
		}
		else if(val>=400)
		{
			ans[idx++] = 'C';
			ans[idx++] = 'D';
			val -=400;
		}
		else if(val >=100)
		{
			ans[idx++] = 'C';
			val -=100;
		}
		else if(val >=90)
		{
			ans[idx++] = 'X';
			ans[idx++] = 'C';
			val -=90;
		}
		else if(val>=50)
		{
			ans[idx++] = 'L';
			val -=50;
		}
		else if(val>=40)
		{
			ans[idx++] = 'X';
			ans[idx++] = 'L';
			val -=40;
		}
		else if(val>=10)
		{
			ans[idx++] = 'X';
			val -=10;
		}
		else if(val==9)
		{
			ans[idx++] = 'I';
			ans[idx++] = 'X';
			val -=9;
		}
		else if(val>=5)
		{
			ans[idx++] = 'V';
			val -=5;
		}
		else if(val==4)
		{
			ans[idx++] = 'I';
			ans[idx++] = 'V';
			val -=4;
		}
		else if(val>=1)
		{
			ans[idx++] = 'I';
			val -=1;
		}
	}

	return ans;
}

int roman_to_int(char *numeral)
{
	int num = 0;
	for(int idx = 0; numeral[idx] != '\0'; idx++)
	{
		/*
		 * This condition checks for subtractive notation.
		 * for instance the given string contains IV(4), the code will
		 * identify that I(1) is less than V(5) so it will subtract 1 from the
		 * resultant number.
		 * Otherwise it will just convert the character to appropriate integer value
		 * and add it to the reultant number.
		 */ 
		if(romanVal(numeral[idx])<romanVal(numeral[idx+1]))
			num -= romanVal(numeral[idx]);
		else
			num += romanVal(numeral[idx]);
	}
	return num;
}

int romanVal(char roman)
{
	switch(roman)
	{
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
	}
	return 0;
}

