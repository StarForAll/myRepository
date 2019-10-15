#include "GDIMain.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	/*LPCTSTR winTitle = L"T_Engine测试程序";
	EngineTest*test = new EngineTest(hInstance, WIN_CLASS, winTitle, NULL, NULL, 800, 600, WIN_BKCLR);
	T_Engine::pEngine = test;
	test->SetFrame(5);  //设置游戏画面帧刷新频率(每秒5帧)
	test->StartEngine();*/
	return TRUE;
}

GDIMain::GDIMain(HINSTANCE hInstance, LPCTSTR szWindowClass, LPCTSTR szTitle, WORD Icon, WORD SmIcon, int iWidth,
	int iHeight, COLORREF bkColor) :T_Engine(hInstance, szWindowClass, szTitle, Icon, SmIcon, iWidth, iHeight, bkColor) {
	wnd_height = iHeight;
	wnd_width = iWidth;
}


GDIMain::~GDIMain()
{
}
/*
重载父类而来的函数实现的是空实现;
*/
// 游戏初始化
void GDIMain::GameInit() {}
// 游戏逻辑处理
void GDIMain::GameLogic() {}
// 游戏结束处理
void GDIMain::GameEnd() {}
// 根据GAME_STATE值显示游戏界面
void GDIMain::GamePaint(HDC hdc) {
	
}

// 根据KM_ACTION值处理按键行为
void GDIMain::GameKeyAction(int ActionType) {}
// 根据KM_ACTION值处理鼠标行为
void GDIMain::GameMouseAction(int x, int y, int ActionType) {}