/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int convert(int, char*, int*);
int check(int*);
int isOlder(char *dob1, char *dob2)
{
	int len1 = 0, len2 = 0, index1 = 0, index2 = 0, index3 = 0, intDate1[3] = { 0 }, intDate2[3] = { 0 }, var1 = 0, var2 = 0;
	while (dob1[len1] != '\0')
	{
		len1++;
		if (dob1[len1] == '-')
			index1++;
	}
	while (dob2[len2] != '\0')
	{
		len2++;
		if (dob2[len2] == '-')
			index2++;
		if (dob2[len2] == dob2[len1])
			index3++;
	}
	if (index3 == len1)
		return 0;
	else if (index1 == index2)
	{
		var1 = convert(len1, dob1, intDate1);
		var2 = convert(len2, dob2, intDate2);
		if (var1 != 0 || var2 != 0)
			return -1;
		var1 = check(intDate1);
		var2 = check(intDate2);
		if (var1 != 0 || var2 != 0)
			return -1;
		if (intDate1[2] > intDate2[2])
			return 2;
		else if (intDate1[2] < intDate2[2])
			return 1;
		else
		{
			if (intDate1[1] > intDate2[1])
				return 2;
			else if (intDate1[1] < intDate2[1])
				return 1;
			else
			{
				if (intDate1[0] > intDate2[0])
					return 2;
				else if (intDate1[0] < intDate2[0])
					return 1;
				else
					return 0;
			}
		}
	}
	else
		return -1;
}

int convert(int len, char *charDate, int *intDate)
{
	int index1, index2 = 0, flag = 0, position = 0;
	for (index1 = 0; index1<len; index1++)
	{
		if (charDate[index1] > 47 && charDate[index1] < 58)
		{
			for (index2 = 0; index2 < 10; index2++)
			{
				if (charDate[index1] == (index2 + 48))
				{
					intDate[position] = intDate[position] + index2;
					if (charDate[index1 + 1] == '-' || charDate[index1 + 1] == '\0')
						break;
					else
						intDate[position] = intDate[position] * 10;
					break;
				}
			}
		}
		else if (charDate[index1] == '-')
			position++;
		else
			flag++;
	}
	if (flag > 0)
		return 1;
	return 0;
}
int check(int arr[])
{
	int leap = 0, flag = 0;
	if (arr[2] % 400 == 0 || (arr[2] % 100 != 0 && arr[2] % 4 == 0))
		leap = 1;
	if (arr[1]<13)
	{
		if (arr[1] == 1 || arr[1] == 3 || arr[1] == 5 || arr[1] == 7 || arr[1] == 8 || arr[1] == 10 || arr[1] == 12)
		{
			if (arr[0] > 1 || arr[0] < 32)
				flag = 1;
		}
		else if (arr[1] == 4 || arr[1] == 6 || arr[1] == 9 || arr[1] == 11)
		{
			if (arr[0] < 31)
				flag = 1;
		}
		else
		{
			if (leap == 1)
				if (arr[0] <= 29)
					flag = 1;
			if (leap == 0)
				if (arr[0] <= 28)
					flag = 1;
		}
	}
	if (flag == 1)
		return 0;
	else
		return 1;
}