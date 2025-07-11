#pragma once

// 키보드 입력
void HandleKeyInput();

extern int PlayerState;

enum Color
{
	Red = 12,
	Black = 0,
	Yellow = 14,
	White = 15,
	Blue = 3,
};

enum PlayerMove {
	STAY = 0,
	UP = 1,
	DOWN = 2,
	RIGHT = 3,
	LEFT = 4
};

void SetCursorPosition(int x, int y);
void SetCursorOnOff(bool visible);
void SetCursorColor(Color color, Color bg = Color::Black);

//SetCursorColor(Color::Yellow, Color::Red);
//SetCursorColor(Color::Yellow);