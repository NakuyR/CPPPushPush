#pragma once
#include <iostream>
#include <random>
#define Mapsize 10
#define Box 4

using namespace std;
//박스
struct Locate {
	int x=1;
	int y=1;
};


extern Locate Boxes[Box]; //박스들
extern Locate Goals[Box]; //도착점




extern int MapSize[Mapsize][Mapsize];

void SetMap(Locate locate[Box]);
void PrintMap();