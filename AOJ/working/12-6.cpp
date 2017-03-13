#include <stdio.h>

void divide(int a, int b, int f[]) {
	int r, rr[100], i, j, cnt = 3,N=100;
	f[2] = a / b;
	r = a%b;
	i = 3;
	j = 0;
	while (r != 0 && j == 0 && i < N) {
		rr[i] = r;
		r *= 10;
		f[i] = r / b;
		r %= b;
		j = i;
		while (j != 0 && r != rr[j]) {
			j--;
		}
		i++;
	}
	f[0] = j-2 ; //printf("\n%d", j);
	f[1] = i-2 ; //printf(" %d\n", i);
	if (f[0] == -2 && f[1] == 1) {
		f[0] = f[1] = 0;
	}
	if (f[0] == -2)f[0] = f[1];
	return;
}

void print_recurring(int f[]) {
	int i;
	printf("%d.", f[2]);
	//printf("%d", f[0]);
	for (i = 3; i < f[0] + 2; i = i + 1)
		printf("%d", f[i]);
	if (f[0] < f[1]) {
		printf("(");
		for (; i < f[1] + 2; i = i + 1)
			printf("%d", f[i]);
		printf(")");
	}
	//printf("%d %d", f[0], f[1]);
	printf("\n");
}

int main(void) {
	int f[100], i, j;

	for (i = 0; i < 100; i = i + 10)
		for (j = 2; j < 50; j++) {
			printf("%d / %d = ", i, j);
			divide(i, j, f);
			print_recurring(f);
		}
	return (0);
}
