#include <stdio.h>
#include <string.h>

#define MAX_NUM_FILE 100
#define MAX_STR_LENG 31

typedef struct Directory{
	char name[MAX_STR_LENG];
	int size;
}_Dir;

_Dir dir[MAX_NUM_FILE] = {{0,0},{"Document",0},{"Music",50},{"Picture",100},{"K-pop",200},{"Pop",300},{"Photo",200},{"Movie",500},[12] = {"2020",1000},[13] = {"2021",50}};
int SearchName(char*);
int DirSize(int);

int main(){
	char st[MAX_STR_LENG] = {0};
	int i = 0, size = 0;
	scanf("%s", st);
	if(i = SearchName(st)){
		size = DirSize(i);
		printf("출력 : %d\n", size);
	}
	else
		printf("출력 : 없는 디렉토리명입니다.\n");
	return 0;
}

int SearchName(char st[]){
	for(int i=1; i<MAX_NUM_FILE; i++){
		if(strcmp(st,dir[i].name) == 0){
			return i;
		}
	}
	return 0;
}

//전위 순회
int DirSize(int pos){
	if(*dir[pos].name != '\0'){
		int SIZE = dir[pos].size;
		SIZE += DirSize(pos*2);		//left
		SIZE += DirSize(pos*2+1);	//right
		return SIZE;
	}
	else return 0;
}
