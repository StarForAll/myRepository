#include "GDIMain.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	/*LPCTSTR winTitle = L"T_Engine���Գ���";
	EngineTest*test = new EngineTest(hInstance, WIN_CLASS, winTitle, NULL, NULL, 800, 600, WIN_BKCLR);
	T_Engine::pEngine = test;
	test->SetFrame(5);  //������Ϸ����֡ˢ��Ƶ��(ÿ��5֡)
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
���ظ�������ĺ���ʵ�ֵ��ǿ�ʵ��;
*/
// ��Ϸ��ʼ��
void GDIMain::GameInit() {}
// ��Ϸ�߼�����
void GDIMain::GameLogic() {}
// ��Ϸ��������
void GDIMain::GameEnd() {}
// ����GAME_STATEֵ��ʾ��Ϸ����
void GDIMain::GamePaint(HDC hdc) {
	
}

// ����KM_ACTIONֵ��������Ϊ
void GDIMain::GameKeyAction(int ActionType) {}
// ����KM_ACTIONֵ���������Ϊ
void GDIMain::GameMouseAction(int x, int y, int ActionType) {}