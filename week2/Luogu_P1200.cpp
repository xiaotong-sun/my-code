#include <stdio.h>

#define A 64

int main() {
	char ufo[7], team[7];
	int i = 0, total1 = 1, total2 = 1;
	scanf("%s", ufo);
	getchar();
	scanf("%s", team);
	while(ufo[i] != '\0') {
		total1 = total1 * (ufo[i] - A);
		i ++;
	}
	i = 0;
	while(team[i] != '\0') {
		total2 *= team[i] - A;
		i ++;
	}
	if(total1 % 47 == total2 % 47) {
		printf("GO");
	} else {
		printf("STAY");
	}
	return 0; 
}
