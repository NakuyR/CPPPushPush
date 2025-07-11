#include "Player.h"
#include "Helper.h"

Locate Player;
bool CanMove(int x, int y)
{
	for (int i = 0; i < Box; i++) {
		//이동 방향에 박스가 있는 경우
		if (Boxes[i].y == Player.y - 1 && Player.x == Boxes[i].x) {
			for (int k = 0; k < Box; k++) {
				//이동방향에 있는 박스가 연속으로 있을 경우
				if (Boxes[i].y - 1 == Boxes[k].y && Boxes[i].x == Boxes[k].x) {
					return false;
				}
			}
			//박스가 하나일 경우
			if (Boxes[i].y >= 2) {
				Boxes[i].y = Boxes[i].y - 1;
				Player.y = Player.y - 1;
				return false;
			}
			else 
			{
				return false;
			}
		}
	}
	
	return true;
}

void HandleMove()
{
	switch (PlayerState)
	{
	//STAY
	case 0: 
		break;

	//UP
	case 1:
		if (Player.y >= 2) {
			bool IsMove = true;
			for (int i = 0; i < Box; i++) {
				//이동 방향에 박스가 있는 경우
				if (Boxes[i].y == Player.y - 1 && Player.x == Boxes[i].x) {
					for (int k = 0; k < Box; k++) {
						//이동방향에 있는 박스가 연속으로 있을 경우
						if (Boxes[i].y - 1 == Boxes[k].y && Boxes[i].x == Boxes[k].x) {
							IsMove = false;
						}
					}
					//박스가 하나일 경우
					if (Boxes[i].y >= 2 && IsMove == true) {
						Boxes[i].y = Boxes[i].y - 1;
						Player.y = Player.y - 1;
						IsMove = false;
					}
					else {
						IsMove = false;
					}
				}
			}
			if (IsMove == true) {
				Player.y = Player.y - 1;
			}
			
		}
		break;

	//DOWN
	case 2:
		if (Player.y < Mapsize-2) {
			bool IsMove = true;
			for (int i = 0; i < Box; i++) {
				if (Boxes[i].y == Player.y + 1 && Player.x == Boxes[i].x) {
					for (int k = 0; k < Box; k++) {
						if (Boxes[i].y + 1 == Boxes[k].y && Boxes[i].x == Boxes[k].x) {
							IsMove = false;
						}
					}

					if (Boxes[i].y < Mapsize - 2 && IsMove == true) {
						Boxes[i].y = Boxes[i].y + 1;
						Player.y = Player.y + 1;
						IsMove = false;
					}
					else {
						IsMove = false;
					}
				}
			}
			if (IsMove == true) {
				Player.y = Player.y + 1;
			}
		}
		break;

	//RIGHT
	case 3:

		if (Player.x < Mapsize - 2) {
			bool IsMove = true;
			for (int i = 0; i < Box; i++) {
				if (Boxes[i].x == Player.x + 1 && Player.y == Boxes[i].y) {
					for (int k = 0; k < Box; k++) {
						if (Boxes[i].x + 1 == Boxes[k].x && Boxes[i].y == Boxes[k].y) {
							IsMove = false;
						}
					}

					if (Boxes[i].x < Mapsize - 2 && IsMove == true) {
						Boxes[i].x = Boxes[i].x + 1;
						Player.x = Player.x + 1;
						IsMove = false;
					}
					else {
						IsMove = false;
					}
				}
				
			}
			if (IsMove == true) {
				Player.x = Player.x + 1;
			}
		}
		break;

	//LEFT
	case 4:
		if (Player.x >=2) {
			bool IsMove = true;
			for (int i = 0; i < Box; i++) {
				if (Boxes[i].x == Player.x - 1 && Player.y == Boxes[i].y) {
					for (int k = 0; k < Box; k++) {
						if (Boxes[i].x - 1 == Boxes[k].x &&Boxes[i].y == Boxes[k].y) {
							IsMove = false;
						}
					}

					if (Boxes[i].x >= 2 && IsMove ==  true) {
						Boxes[i].x = Boxes[i].x - 1;
						Player.x = Player.x - 1;
						IsMove = false;
					}
					else {
						IsMove = false;
					}
				}
				
			}
			if (IsMove == true) {
				Player.x = Player.x - 1;
			}
		}
		break;

	default:
		break;
	}
	PlayerState = PlayerMove::STAY;
	// 키 입력에 따라 플레이어를 이동할 것이다.
}
