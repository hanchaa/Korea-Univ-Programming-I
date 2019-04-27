#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 100

void display_plan(int plan[2][7]);
void two_month(int current, int usage[3][3]);
int input(int usage[3][3], int chk);
void three_month(int current, int usage[3][3], int plan[2][7]);
void recommend(int current, int usage[3][3], int plan[2][7]);

int main(void) {

	int current, chk = 0;

	int usage[3][3] = { 0 };
	int plan[2][7] = { {500, 100, 200, 50, 10, 1000, 20000}, {300, 100, 3000, 10, 30, 500, 45000} };

	char menu;
	
	srand(time(NULL));
	
	//current = 0;

	// usage[0][0] = 258; usage[1][0] = 310;
	// usage[0][1] = 85; usage[1][1] = 195;
	// usage[0][2] = 2189; usage[1][2] = 155;
	
	current = rand() % 2;

	usage[0][0] = rand() % 700 + 1;
	usage[1][0] = rand() % 700 + 1;

	usage[0][1] = rand() % 300;
	usage[1][1] = rand() % 300;

	usage[0][2] = rand() % 14501 + 500;
	usage[1][2] = rand() % 14501 + 500;


	while (1) {
		system("cls");
		printf("┌──────────────────────────────────────────────┐ \n");
		printf("│      KU Mobile Phone Bill Calculator         │ \n");
		printf("├──────────────────────────────────────────────┤ \n");
		printf("│    1 : Display plans                         │ \n");
		printf("│    2 : Usage information for past two months │ \n");
		printf("│    3 : Input this month usage                │ \n");
		printf("│    4 : Total fee for past 3 months           │ \n");
		printf("│    5 : Best plan recommendation              │ \n");
		printf("│    6 : Exit                                  │ \n");
		printf("└──────────────────────────────────────────────┘ \n");
		
		while(1){
			scanf(" %c", &menu);
			
			if(menu >= '1' && menu <= '6')
				break;
			else
				printf("Wrong Input!\n");
		}

		switch (menu) {
		case '1':
			display_plan(plan);
			break;

		case '2':
			two_month(current, usage);
			break;

		case '3':
			chk = input(usage, chk);
			break;

		case '4':
			three_month(current, usage, plan);
			break;

		case '5':
			recommend(current, usage, plan);
			break;

		case '6':
			return 0;
		}
	}
	return 0;
}

void display_plan(int plan[2][7]) {
	char a;

	system("cls");
	printf("┌───────────────────────────────────────────┐ \n");
	printf("│                Basic Plan                 │ \n");
	printf("├───────────────────────────────────────────┤ \n");
	printf("│  Included in Plan  │   Additional usages  │ \n");
	printf("├───────────────────────────────────────────┤ \n");
	printf("│ Voice     │  %dm free   │  \\ %d / 1m     │ \n", plan[0][0], plan[0][3]);
	printf("│ Text      │  %dt free   │  \\ %d / 1m     │ \n", plan[0][1], plan[0][4]);
	printf("│ Data      │  %.2fGB free │  \\ %d / 0.1GB│ \n", (float)plan[0][2] / M, plan[0][5]);
	printf("├───────────────────────────────────────────┤ \n");
	printf("│ Basic fee │  \\ %d                      │ \n", plan[0][6]);
	printf("└───────────────────────────────────────────┘ \n\n");

	printf("┌───────────────────────────────────────────┐ \n");
	printf("│             More Data Plan                │ \n");
	printf("├───────────────────────────────────────────┤ \n");
	printf("│  Included in Plan  │   Additional usages  │ \n");
	printf("├───────────────────────────────────────────┤ \n");
	printf("│ Voice     │  %dm free   │  \\ %d / 1m     │ \n", plan[1][0], plan[1][3]);
	printf("│ Text      │  %dt fre    │  \\ %d / 1m     │ \n", plan[1][1], plan[1][4]);
	printf("│ Data      │  %.2fGB free│  \\ %d / 0.1GB │ \n", (float)plan[1][2] / M, plan[1][5]);
	printf("├───────────────────────────────────────────┤ \n");
	printf("│ Basic fee │ \\ %d                       │ \n", plan[1][6]);
	printf("└───────────────────────────────────────────┘ \n");

	while (1) {
		printf("  Back to main menu Y/N : ");
		scanf(" %c", &a);

		if (a == 'Y')
			break;
		else if(a != 'N')
			printf("  Wrong Input!\n");
	}
}

void two_month(int current, int usage[3][3]) {
	char a;
	
	system("cls");
	printf("┌───────────────────────────────────────────┐ \n");
	printf("│           Last two months usage           │ \n");
	printf("├───────────────────────────────────────────┤ \n");
	printf("│  My Plan : %-14s                 │ \n", current == 0 ? "Basic Plan" : "More Data Plan");
	printf("├───────────────────────────────────────────┤ \n");
	printf("│           │   Feburary   │     March      │ \n");
	printf("├───────────────────────────────────────────┤ \n");
	printf("│  Voice    │  %6d min  │  %6d min    │ \n", usage[0][0], usage[1][0]);
	printf("│  Text     │  %6d text │  %6d text   │ \n", usage[0][1], usage[1][1]);
	printf("│  Data     │  %6.2f GB   │  %6.2f GB     │ \n", (float)usage[0][2] / M, (float)usage[1][2] / 100);
	printf("└───────────────────────────────────────────┘ \n");

	while (1) {
		printf("  Back to main menu Y/N : ");
		scanf(" %c", &a);

		if (a == 'Y')
			break;
		else if(a != 'N')
			printf("  Wrong Input!\n");
	}
}

int input(int usage[3][3], int chk) {

	float tmp;
	char a;
	
	system("cls");
	
	printf("=================================\n");
	
	if(chk == 0){
		printf("Input your usages of voice : ");
		scanf("%d", &usage[2][0]);

		printf("Input your usages of text : ");
		scanf("%d", &usage[2][1]);

		printf("Input your usages of data : ");
		scanf("%f", &tmp);

		usage[2][2] = (tmp + 0.005) * M;
		
		chk++;
	}
	
	else{
		printf("Input your usages of voice : %d\n", usage[2][0]);
		printf("Input your usages of text : %d\n", usage[2][1]);
		printf("Input your usages of data : %d\n", usage[2][2]);
	}
	
	while (1) {
		printf("Back to main menu Y/N : ");
		scanf(" %c", &a);

		if (a == 'Y')
			break;
		else if(a != 'N')
			printf("Wrong Input!\n");
	}
	
	return chk;
}

void three_month(int current, int usage[3][3], int plan[2][7]) {
	int extra[5] = { 0 }, sum[5] = { 0 };
	char a;

	for (int i = 0; i < 3; i++) {
		if (usage[i][2] < plan[current][2]) {
			extra[i + 1] = plan[current][2] - usage[i][2];

			if (extra[i + 1] > plan[current][2] / 10)
				extra[i + 1] = plan[current][2] / 10;
		}

		sum[i] = plan[current][6];
		for (int j = 0; j < 2; j++) {
			if (usage[i][j] > plan[current][j])
				sum[i] += (usage[i][j] - plan[current][j]) * plan[current][j + 3];
		}
		if (usage[i][2] > plan[current][2] + extra[i])
			sum[i] += (usage[i][2] - plan[current][2] - extra[i]) / 10 * plan[current][5];
	}

	system("cls");

	printf("┌────────────────────────────────────────────────────────────┐ \n");
	printf("│                     My three months usage                  │ \n");
	printf("├────────────────────────────────────────────────────────────┤ \n");
	printf("│ My Plan : %-14s                                   │ \n", current == 0 ? "Basic Plan" : "More Data Plan");
	printf("├────────────────────────────────────────────────────────────┤ \n");
	printf("│           │   Feburary   │     March      │     April      │ \n");
	printf("├────────────────────────────────────────────────────────────┤ \n");
	printf("│ Voice     │  %6d min  │  %6d min    │  %6d min    │ \n", usage[0][0], usage[1][0], usage[2][0]);
	printf("│ Text      │  %6d text │  %6d text   │  %6d text   │ \n", usage[0][1], usage[1][1], usage[2][1]);
	printf("│ Data      │  %6.2f GB   │  %6.2f GB     │  %6.2f GB     │ \n", (float)usage[0][2] / M, (float)usage[1][2] / M, (float)usage[2][2] / M);
	printf("├────────────────────────────────────────────────────────────┤ \n");
	printf("│ Extra Data│  %6.2f GB   │  %6.2f GB     │  %6.2f GB     │ \n", (float)extra[1] / M, (float)extra[2] / M, (float)extra[3] / M);
	printf("├────────────────────────────────────────────────────────────┤ \n");
	printf("│ Total Fee │  \\ %7d   │  \\ %7d     │  \\ %7d     │ \n", sum[0], sum[1], sum[2]);
	printf("└────────────────────────────────────────────────────────────┘ \n");

	while (1) {
		printf("  Back to main menu Y/N : ");
		scanf(" %c", &a);

		if (a == 'Y')
			break;
		else if(a != 'N')
			printf("  Wrong Input!\n");
	}
}

void recommend(int current, int usage[3][3], int plan[2][7]) {
	char a;
	int sum1 = plan[0][6], sum2 = plan[1][6];

	int avg[3] = { 0 };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			avg[i] += usage[j][i];
		}
		avg[i] = (int)((float)avg[i] / 3 + 0.5);
	}

	for (int i = 0; i < 2; i++) {
		if (avg[i] > plan[0][i])
			sum1 += (avg[i] - plan[0][i]) * plan[0][i + 3];
		if (avg[i] > plan[1][i])
			sum2 += (avg[i] - plan[1][i]) * plan[1][i + 3];
	}
	
	if (avg[2] > plan[0][2])
		sum1 += (avg[2] - plan[0][2]) / 10 * plan[0][5];
	
	if (avg[2] > plan[1][2])
		sum2 += (avg[2] - plan[1][2]) / 10 * plan[1][5];
	
	system("cls");
	printf("┌───────────────────────────────────────────┐ \n");
	printf("│         Average usage of 3-month          │ \n");
	printf("├───────────────────────────────────────────┤ \n");
	printf("│  My Plan : %-14s                 │ \n", current == 0 ? "Basic Plan" : "More Data Plan");
	printf("├───────────────────────────────────────────┤ \n");
	printf("│  Average usage of voice : %5d           │ \n", avg[0]);
	printf("│  Average usage of text : %6d           │ \n", avg[1]);
	printf("│  Average usage of data : %6.2f           │ \n", (float)avg[2] / M);
	printf("├───────────────────────────────────────────┤ \n");
	printf("│  Basic Plan Fee :      \\%7d           │ \n", sum1);
	printf("│  More Data Plan Fee  : \\%7d           │ \n", sum2);
	printf("├───────────────────────────────────────────┤ \n");
	printf("│  We recommend to use %-14s       │ \n", sum1 < sum2 ? "Basic Plan" : "More Data Plan");
	printf("└───────────────────────────────────────────┘ \n");

	while (1) {
		printf("  Back to main menu Y/N : ");
		scanf(" %c", &a);

		if (a == 'Y')
			break;
		else if(a != 'N')
			printf("  Wrong Input!\n");
	}
}