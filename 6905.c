#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void add(char *in1, char * in2, char *out);

int main()
{
	int i, j, k;
	char in1[201] = {0};
	char in2[201] = {0};
	char out[201] = {0};
	scanf("%s", in1);
	scanf("%s", in2);

	for(i=200,j=strlen(in1), k=strlen(in2); 
			i>=0; 
			j--, k--,i--){
		if(j<0) 
			in1[i] = '0';
		else 
			in1[i] = in1[j];

		if(k<0)
			in2[i] = '0';
		else
			in2[i] = in2[k];
	}

	add(in1, in2, out);

	i = 0;
	while(out[i] == 48 && i<(strlen(out)-1))
		i++;
	printf("%s\n", &out[i]);

	return 0;
}


void add(char* in1, char* in2, char* out)
{
	int tmp = 0;
	int i = 200;
	int up = 0;
	out[i--] = '\0';
	
	while(i>=0){
		tmp = (in1[i]-48) + (in2[i]-48) + up;
		out[i] = (tmp %10) + 48;
		up =(tmp >= 10)? 1:0;
		i--;
	}	
}
