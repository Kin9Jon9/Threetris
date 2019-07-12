#include "Core.h"
#include "Game.h"
#include "BlockManage.h"
#include "Rank.h"

Core* Core::Inst = NULL;

Core::Core():loop(true),score(0){
	srand((unsigned int)time(0));
}

Core::~Core() {
	BlockManage::DestroyInst();
	Game::DestroyInst();
}

bool Core::init() {
	
	//콘솔 핸들 생성
	Console = GetStdHandle(STD_OUTPUT_HANDLE);
	
	if (Console == INVALID_HANDLE_VALUE)
		return false;

	if (!Game::GetInst()->init()) {
		return false;
	}
	return true;
}

void Core::gameLogo() {

	cout << "\n\n         '########:'##::::'##:'########::'########:'########:'########:'########::'####::'######::" << endl;
	cout << "         :.. ##..:: ##:::: ##: ##.... ##: ##.....:: ##.....::... ##..:: ##.... ##:. ##::'##... ##:" << endl;
	cout << "         ::: ##:::: ##:::: ##: ##:::: ##: ##::::::: ##:::::::::: ##:::: ##:::: ##:: ##:: ##:::..::" << endl;
	cout << "         ::: ##:::: #########: ########:: ######::: ######:::::: ##:::: ########::: ##::. ######::" << endl;
	cout << "         ::: ##:::: ##.... ##: ##.. ##::: ##...:::: ##...::::::: ##:::: ##.. ##:::: ##:::..... ##:" << endl;
	cout << "         ::: ##:::: ##:::: ##: ##::. ##:: ##::::::: ##:::::::::: ##:::: ##::. ##::: ##::'##::: ##:" << endl;
	cout << "         ::: ##:::: ##:::: ##: ##:::. ##: ########: ########:::: ##:::: ##:::. ##:'####:. ######::" << endl;
	cout << "         :::..:::::..:::::..::..:::::..::........::........:::::..:::::..:::::..::....:::......:::\n\n" << endl;
	cout << "                                             \n";
	cout << "                                             ";

}

void Core::run() {
	//커서 감추기
	CursorView(0);

	gameLogo();

	cout << " Press Space Bar";

	while (1) {
		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
			system("cls");
			gameLogo();
			selected(true);
		}
		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			if (selectNum == 1) {
				system("cls");
				break;
			}
			else if (selectNum == 0) {
				exit(0);
			}
		}
		if (GetAsyncKeyState('W') & 0x8000) {
			system("cls");
			gameLogo();
			selected(true);
		}
		if (GetAsyncKeyState('S') & 0x8000) {
			system("cls");
			gameLogo();
			selected(false);
		}

	}

	
	system("mode con cols=50 lines=20 | title Threetris");
	while (loop) {
		system("cls");
		BlockManage::GetInst()->update();

		Game::GetInst()->run();
		BlockManage::GetInst()->draw();
		Sleep(10);
	}

	setConsolePoint(1, 6);  cout << "┌----------------------┐";
	setConsolePoint(1, 7);	cout << "┃      GAME  OVER      ┃";
	setConsolePoint(1, 8);	cout << "└----------------------┘";
	Sleep(1300);
	finish();
}

void Core::setConsolePoint(int x, int y)
{
	COORD pos = { (SHORT)((x+1) * 2),(SHORT) y };
	SetConsoleCursorPosition(Console, pos);
}

void Core::menu()
{

}

void Core::end()
{
	loop = false;
}

void Core::selected(bool type)
{
	if (type) {
		textcolor(0, 15);
		cout << "Start Game";
		textcolor(15, 0);
		cout << "  (Enter)\n\n" << endl;
		cout << "                                             ";
		cout << "E  X  I  T" << endl;
		selectNum = 1;
	}
	else {
		textcolor(15, 0);
		cout << "Start Game\n\n" << endl;
		cout << "                                             ";
		textcolor(0, 15);
		cout << "E  X  I  T";
		textcolor(15, 0);
		cout<<"  (Enter)" << endl;
		selectNum = 0;
	}
}


//글자색 바꾸기
void Core::textcolor(int foreground, int background)
{
		int color = foreground + background * 16;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//커서숨기기
void Core::CursorView(char show)

{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void Core::finish()
{

	string name;
	//커서 보이기
	CursorView(1);

	system("cls");
	setConsolePoint(1, 5);
	cout << "Press Enter Key \n\n";
	cin >> name;
	cin.clear();
	system("cls");

	setConsolePoint(1, 5);
	cout << "이름을 입력해주세요." << endl;
	cin >> name;
	system("cls");

	//파일 입출력 함수 호출
	Rank rank;
	rank.enterScore(name, score);
	rank.getFileData();
	rank.PrintFileRank();
	Sleep(5000);
}
