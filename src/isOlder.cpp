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
int len(char str[])
{
	int i = 0, count = 0;
	while (str[i] != '\0')
	{
		count++;
		i++;
	}
	return(count);
}
int day(char str[])
{
	int i = 0, j = 0, a[10], x = 0;
	while (i <= 1)
	{
		a[j] = (int)str[i] - 48;
		x = x * 10 + a[j];
		i++;
		j++;
	}
	return(x);
}
int month(char str[])
{
	int i = 3, b[10], j = 0, y = 0;
	while (i <= 4)
	{
		b[j] = (int)str[i] - 48;
		y = y * 10 + b[j];
		j++;
		i++;
	}
	return(y);
}
int years(char str[])
{
	int i = 6, j = 0, c[10], z = 0;
	while (i <= 9)
	{
		c[j] = (int)str[i] - 48;
		z = z * 10 + c[j];
		j++;
		i++;
	}
	return(z);
}
int isOlder(char *dob1, char *dob2) {
	int day1, mon1, year1, day2, mon2, year2, mdays1, mdays2, length1, length2;
	length1 = len(dob1);
	length2 = len(dob2);
	day1 = day(dob1);
	mon1 = month(dob1);
	year1 = years(dob1);
	day2 = day(dob2);
	mon2 = month(dob2);
	year2 = years(dob2);
	if (length1 == 10 && length2 == 10)
	{
		if (dob1[2] == '-'&&dob1[5] == '-'&&dob2[2] == '-'&&dob2[5] == '-')
		{
			if (year1 != 0 && year2 != 0)
			{
				if (mon1 >= 1 && mon1 <= 12 && mon2 >= 1 && mon2 <= 12)
				{
					if (mon1 == 2)
					{
						if (year1 % 4 == 0 && year1 % 100 != 0 || year1 % 400 == 0)
						{
							mdays1 = 29;
						}
						else
						{
							mdays1 = 28;
						}
					}
					else	if (mon1 == 4 || mon1 == 6 || mon1 == 9 || mon1 == 11)
					{
						mdays1 = 30;
					}
					else
					{
						mdays1 = 31;
					}
					if (mon2 == 2)
					{
						if (year2 % 4 == 0 && year2 % 100 != 0||year2%400==0)
						{
							mdays2 = 29;
						}
						else
						{
							mdays2 = 28;
						}
					}
					else if (mon2 == 4 || mon2 == 6 || mon2 == 9 || mon2 == 11)
					{
						mdays2 = 30;
					}
					else
					{
						mdays2 = 31;
					}
					if (day1 >= 1 && day1 <= mdays1&&day2 >= 1 && day2 <= mdays2)
					{
						if (year1 < year2)
						{
							return(1);
						}
						else	if (year1 > year2)
						{
							return(2);
						}
						else if (year1 == year2)
						{
							if (mon1 < mon2)
							{
								return(1);
							}
							else if (mon1 > mon2)
							{
								return(2);
							}
							else	if (mon1 == mon2)
							{
								if (day1 < day2)
								{
									return(1);
								}
								else if (day1>day2)
								{
									return(2);
								}
								else
								{
									return(0);
								}
							}
						}
					}
						else
						{
							return(-1);
						}
					}
					else
					{
						return(-1);
					}
				}
				else
				{
					return(-1);
				}
			}
			else
			{
				return(-1);
			}
		}
		else
		{
			return(-1);
		}
	}

