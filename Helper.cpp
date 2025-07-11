#include "Helper.h"
#include <Windows.h>

int PlayerState=0;

void HandleKeyInput()
{
	// 왼쪽 키가 눌렸는냐
	if (GetAsyncKeyState(VK_LEFT) & 0x01)
	{
		PlayerState = PlayerMove::LEFT;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x01)
	{
		PlayerState = PlayerMove::RIGHT;
	}
	else if (GetAsyncKeyState(VK_UP) & 0x01)
	{
		PlayerState = PlayerMove::UP;
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x01)
	{
		PlayerState = PlayerMove::DOWN;
	}
}


// 프레임마다 커서 옮겨서 덮어쓰기함
void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { (SHORT)x, (SHORT)y };
	::SetConsoleCursorPosition(output, pos);
}

//터미널 커서 삭제
void SetCursorOnOff(bool visible)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	::GetConsoleCursorInfo(output, &cursorInfo);
	cursorInfo.bVisible = visible;
	::SetConsoleCursorInfo(output, &cursorInfo);
}

//색상관련
void SetCursorColor(Color color, Color bg)
{
	int code = (bg << 4) | color;
	//int code = color;
	// 색상코드: 배경색(4bit) + 글자색(4bit) 조합
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, code);
}