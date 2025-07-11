#include "Map.h"
#include "Player.h"
#include "Helper.h"

int MapSize[Mapsize][Mapsize];
Locate Boxes[Box];  //박스
Locate Goals[Box]; //도착점


random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dist(3, Mapsize - 3);

using namespace std;


void SetMap(Locate locate[Box]) {
	for (int i = 0; i < Box; i++) {
		int x = dist(gen);
		int y = dist(gen);
		if (x == Boxes[i].x && y == Boxes[i].y) {
			SetMap(locate);
		}
		else if (x == Goals[i].x && y == Goals[i].y) {
			SetMap(locate);
		}
		else {
			locate[i].x = x;
			locate[i].y = y;
		}
	}
}

void PrintMap()
{
	for (int i = 0; i < Mapsize; i++) {
		for (int j = 0; j < Mapsize; j++) {

			//맵 안쪽
			MapSize[i][j] = 3; 
			//캐릭터
			if (i == Player.y && j == Player.x) {
				MapSize[i][j] = 1;
			}
			//테두리
			if (i == 0 || j == 0 || i == Mapsize-1 || j == Mapsize-1) {
				MapSize[i][j] = 2;
			}
			//박스
			for (int k = 0; k < Box; k++) {
				if (i == Boxes[k].y && j == Boxes[k].x) {
					MapSize[i][j] = 4;
				}
			}
			
			//도착점
			for (int k = 0; k < Box; k++) {
				if (i == Goals[k].y && j == Goals[k].x) {
					MapSize[i][j] = 5;
				}
			}

			switch (MapSize[i][j])
			{
			case 1:
				SetCursorColor(Color::Red);
				cout << "♥";
				break;
			case 2:
				SetCursorColor(Color::White);
				cout << "■";
				break;
			case 3:
				SetCursorColor(Color::White);
				cout << "□";
				break;
			case 4:
				SetCursorColor(Color::Yellow);
				cout << "▩";
				break;
			case 5:
				SetCursorColor(Color::Blue);
				cout << "▣";
				break;
			default:
				break;
			}
		}
		cout << endl;
	}

}
