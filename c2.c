#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
typedef char Map[8][22];
Map map;
int place = 10, length = 0;
_Bool isStart = 1;
void *playerLoop(void* nothing)
{
	char action;
	scanf("%s",&action);
	if(isStart)
	switch(action){
		case 'd':
			if(place != 6){
				map[6][place] = '_';
				map[6][++place] = '^';
			}
			break;
		case 'a':
			if(place != 0){
				map[6][place] = '_';
				map[6][--place] = '^';
			}
	}
	return playerLoop(nothing);
}

void updateScene()
{
	
}

int main()
{
	pthread_t thread;
	{
		Map dmap = {
			{"#_________#_________#"},
			{"#___________________#"},
			{"#___________________#"},
			{"#___________________#"},
			{"#___________________#"},
			{"#___________________#"},
			{"#_________*_________#"},
			{"#_________#_________#"}
		};
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 21; j++){
				map[i][j] = dmap[i][j];
			}
		}
	}
	updateScene();
	pthread_create(&thread,NULL,playerLoop,NULL);
	pthread_exit(NULL);
	return 0;
}
