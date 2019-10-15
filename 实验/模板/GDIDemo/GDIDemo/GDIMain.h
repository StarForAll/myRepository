#pragma once
#include "T_Engine.h"
class GDIMain :public T_Engine
{
public:
	virtual~GDIMain();
	GDIMain(HINSTANCE hInstance, LPCTSTR szWindowClass, LPCTSTR szTitle,
		WORD Icon = NULL, WORD SmIcon = NULL,
		int iWidth = WIN_WIDTH, int iHeight = WIN_HEIGHT,
		COLORREF bkColor = WIN_BKCLR);

	// ���ظ����еĺ�����������Ϸ���ܴ���
	// ��Ϸ��ʼ��
	void GameInit();
	// ��Ϸ�߼�����
	void GameLogic();
	// ��Ϸ��������
	void GameEnd();
	// ����GAME_STATEֵ��ʾ��Ϸ����
	void GamePaint(HDC hdc);
	// ����KM_ACTIONֵ��������Ϊ
	void GameKeyAction(int ActionType = KEY_SYS_NONE);
	// ����KM_ACTIONֵ���������Ϊ
	void GameMouseAction(int x, int y, int ActionType);
private:
	int wnd_width, wnd_height;//��Ϸ���ڿ��
};

