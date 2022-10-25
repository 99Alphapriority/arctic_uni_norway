#include<stdio.h>
#include"roman.h"

int main()
{
	FILE *fp;
	fp = fopen("output.txt","w+");
	fprintf(fp,"Assignment: Integer to roman numeral, and back again\n");
	
	char inputString[20], opt;
	int inputVal;
	
	printf("(a)\tImplement a C or Python function int_to_roman() that converts an integer to a roman numeral.\n");
	printf("   \tThe input is guaranteed to be within the range of 1 to 3999 (inclusive).\n");
	printf("Enter an integer value to convert to roman numeral: \t");
	scanf("%d",&inputVal);
	fflush(stdin);
	fprintf(fp,"(a)\t%d in roman numerals is: \t%s\n\n",inputVal,int_to_roman(inputVal));
	
	printf("(b)\tImplement a C or Python function roman_to_int() that takes the Roman numerals produced by the\n");
	printf("   \tfunction int_to_roman() in assignment (a) and convert them back to integers. The input is guaranteed\n");
	printf("   \tto be within the same range as in (a).\n");
	printf("Enter a roman numeral string to convert to an integer value: \t");
	scanf("%s",inputString);
	fflush(stdin);
	fprintf(fp,"(b)\t%s in integer is: \t%d\n\n",inputString,roman_to_int(inputString));
	
	printf("(c)\tOptional: Create a program that uses the functions from (a) and (b) to write out all the\n");
        printf("   \tnumbers from 1 to 3999 as Roman numerals, and then convert them back to, and print them out, as integers.\n");
	
	fprintf(fp,"(c)\n");
	for(int idx = 1; idx<4000; idx++)
	{
		char *str;
		int val;
		str = int_to_roman(idx);
		val = roman_to_int(str);
		fprintf(fp,"roman numeral: %s,\tinteger value: %d\n",str,val);
	}
	fclose(fp);
	printf("\nPlease view output.txt\n");
	return 0;
}
