#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	float hrly,yrly,qrtly,hafly;
	float dly, mnth, week, bweek;
	
	float hrs_per_week;
	
	printf("Enter your hourly rate below:\n");
	scanf("%f", &hrly);
	printf("\n");
	
	printf("Enter your hours per week:\n");
	scanf("%f", &hrs_per_week);
	printf("\n");
	
	mnth = hrs_per_week * hrly * 4.34524;
	yrly = hrly * hrs_per_week * 52;
	qrtly = yrly * 0.25;
	week = hrly * 8 * 5;
	dly = week / 5;
	bweek = week * 2;
	hafly = yrly * 0.5;
	
	printf("Monthly: %f\n",mnth);
	printf("Yearly: %f\n",yrly);
	printf("Quarterly: %f\n",qrtly);
	printf("Weekly: %f\n",week);
	printf("Daily: %f\n",dly);
	printf("Bi-Weekly: %f\n",bweek);
	printf("6-Month Time: %f\n\n",hafly);
	
	return 0;
}