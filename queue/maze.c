#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef struct _coor {
	int x;
	int y;
	int n;
}_Coor;

_Coor data[MAX_SIZE];

int front;
int rear;
int N = 0, M = 0;

int isGoal(_Coor);
_Coor dequeue();
void enqueue(_Coor);
int isEmpty();
int isFull();
int size();

int isRange(int a, int b){
	return (a < N) && (b < M) && (a >= 0) && (b >= 0);
}

void makeMaze(int** maze_p) {
	if (maze_p == NULL) return;
	for (int i = 0; i < N; i++) {
		getchar();
		for (int j = 0; j < M; j++) {
			int px = getchar();
			if (px == '0') {
				*(*(maze_p+i)+j) = FALSE;
			}
			else if (px == '1') {
				*(*(maze_p+i)+j) = TRUE;
			}
			else
				return;
		}
	}
}


int searchMaze(int** maze_p) {
	_Coor in = { 1,1,1}, out;
	if (maze_p == NULL) {
		printf("error: maze\n");
		return EOF;
	}
	//시작 : 큐에 (1,1) 삽입
	enqueue(in);

	while (!isGoal(out = dequeue())) {
		if (out.n == EOF) {
			printf("error: queue over\n");
			return EOF;
		}
		if (isRange(out.x,out.y-1) && (maze_p[out.x][out.y - 1] == TRUE)) {
			//아래방향
			in = out;
			in.x++;		in.n++;
			enqueue(in);
		}
		if (isRange(out.x-1,out.y) && (maze_p[out.x - 1][out.y] == TRUE)) {
			//오른방향
			in = out;
			in.y++;		in.n++;
			enqueue(in);
		}
		if (isRange(out.x-2,out.y-1) && (maze_p[out.x - 2][out.y - 1] == TRUE)) {
			//윗방향
			in = out;
			in.x--;		in.n++;
			enqueue(in);
		}
		if (isRange(out.x-1,out.y-2) && (maze_p[out.x - 1][out.y - 2] == TRUE)) {
			//왼방향
			in = out;
			in.y--;		in.n++;
			enqueue(in);
		}
		if (isEmpty() == TRUE) {
			printf("error: lost\n");
			return EOF;
		}
		maze_p[out.x-1][out.y-1] = FALSE;
	}
	return out.n;
}

int isGoal(_Coor tmp) {
	return (tmp.x == N) && (tmp.y == M);
}

void initQueue() {
	front = rear = 1;
}

int isEmpty() {
	return front == rear;
}

int isFull() {
	return front == (rear + 1) % MAX_SIZE;
}

_Coor dequeue() {
	if (isEmpty()) {
		_Coor err = { 0,0,EOF };
		return err;
	}
	else {
		front = (front + 1) % MAX_SIZE;
		return data[front];
	}
}

int size() {
	return (rear - front + MAX_SIZE) % MAX_SIZE;
}

void enqueue(_Coor tmp) {
	if (!isFull()) {
		rear = (rear + 1) % MAX_SIZE;
		data[rear] = tmp;
	}
}

int main() {
	initQueue();
	int n, m;
	int** maze = NULL;
	scanf("%d %d", &n, &m);
	
	N = n; M = m;
	maze = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		*(maze+i)= (int*)malloc(sizeof(int) * M);
	}

	makeMaze(maze);

	int num = searchMaze(maze);
	if (num == EOF){
		printf("error");
	}
	else
		printf("%d\n", num);

	return 0;
}
