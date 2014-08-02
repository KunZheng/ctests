#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define maxlen  11
#define maxnum 100000
struct dict_entry {
	char left[maxlen];
	char right[maxlen];
};

int main()
{
	char str1[maxlen];
	char str2[maxlen];
	char word[maxlen];
	int index = 0;
	char buf[30];

 	struct dict_entry * p_dict = (struct dict_entry*)malloc(maxnum * sizeof(struct dict_entry));
 	struct dict_entry * p_result = (struct dict_entry*)malloc(maxnum * sizeof(struct dict_entry));

	while(1){
		fgets(buf, 30, stdin);
		if(buf[0] == '\n'){
//			printf("this is an empty line\n");
			break;
		}

		sscanf(buf, "%s %s", str1, str2);
//		printf("str1 = %s, str2 = %s\n", str1, str2);
		strcpy(p_dict[index].left, str1);
		strcpy(p_dict[index].right, str2);
		index++;
	}

	int i = 0;
	int j = 0;
	while( scanf("%s", word) != EOF){
		strcpy(p_result[i].right, word);
		for(j=0; j< index; j++){
			if(strcmp(word, p_dict[j].right) == 0) {
				strcpy(p_result[i].left, p_dict[j].left);
				break;
			}
		}
		if (j == index)
			strcpy(p_result[i].left, "eh");

		i++;	
	}

	for (j=0; j<i; j++)
		printf("%s\n", p_result[j].left);

	return 0;
}
