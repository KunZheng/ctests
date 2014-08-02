#include <stdio.h>

int monkeys[300];

int main()
{
	int m, n;
	int i;

	scanf("%d %d", &n, &m);
	for(i = 0; i<n; i++)
		monkeys[i] = i;
	
	printf("%d\n", compute(n, m));
	
	return 0;
}

int compute(int n, int m)
{
	int counter = 0;
	int pos = 0;
	int j = 0;
	
	while(counter < n) {
		j=0;
		while(1) {
			if(monkeys[pos] != -1)
				j++;
			if(j==m)
				break;
			pos++;
			if(pos == n)
				pos = 0;			
		}
		monkeys[pos] = -1;
		counter++;
	}
	return (pos+1)%n;
}

