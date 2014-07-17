#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void plusone(int *imask)
{
	int i = 0;
	while((imask[i] ^ 0xFFFFFFFF) == 0){
		imask[i] = 0x0;
		i++;
	}
	
	imask[i] += 1;
}

int get_i(int *imask, int index)
{
	int tmp = 0;
	tmp = imask[index/32];
	tmp = (tmp >> (index%32));
	if(tmp&1) // index points to 1
		return 1;
	else 
		return 0;
		
}

//if position n-1 == 1, then finished, return 1;
int finished(int *imask, int n)
{
	return get_i(imask, n-1);
}


int compute(int num[], int* mask, int N)
{
	int i = 0;
	int sum = 0;
	int tmp = 0;
	for(i=0; i<N; i++){
		if(get_i(mask, i) ==1)
			sum = sum + (-1)*num[i];
		else
			sum = sum + num[i];
	}

	return sum;
}

int main()
{

	int N = 0;
	int K = 0;
	int i;
	int ret = 0;
	int sum=0;

	int S[10000] = {0};
	
	scanf("%d %d", &N, &K);

	for(i=0; i<N; i++){
		scanf("%d", &S[i]);
	}

	int lmask = N/32 +1;
    int *imask = (int *) malloc(sizeof(int) * lmask);

	memset(imask, 0, sizeof(int)*lmask);

	i=0;
	while(!finished(imask, N)){
		sum = compute(S, imask, N);
		if(sum%K == 0){
			ret = 1;
			break;
		}
		printf("ret=%d ", ret);	
//		for(i = 0; i< lmask; i++)
//			printf("%x ", imask[i]);
		plusone(imask);
	}

	ret ? printf("YES"):printf("NO");

	free(imask);
	return 0;
}
