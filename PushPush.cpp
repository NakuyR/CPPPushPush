#include <iostream>
#include <Windows.h>
#include "Helper.h"
#include "Player.h"
#include "Map.h"

int main()
{
	int count = 0;
	SetCursorOnOff(false);

	SetMap(Boxes);
	SetMap(Goals);


	while (true)
	{
		SetCursorPosition(0, 0);

		// 입력
		HandleKeyInput();
		

		// 로직 (Update)
		HandleMove();


		// 출력 (렌더링)
		PrintMap();

		for (int i = 0; i < Box; i++) {
			for (int j = 0; j < Box; j++) {
				if (Boxes[i].x == Goals[j].x && Boxes[i].y == Goals[j].y){
					count++;
				}
			}
		}
		if (count == Box) {
			break;
		}
		else {
			count = 0;
		}
	}

	std::cout << "클리어";
}

