//*************************************************************************************************************
//
// マウス処理 [mouse.h]
// Author:IKUTO SEKINE
//
//*************************************************************************************************************
#ifndef _MOUSE_H_
#define _MOUSE_H_

#define _CRT_SECURE_NO_WARNINGS

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "input.h"

//-------------------------------------------------------------------------------------------------------------
// マクロ定義
//-------------------------------------------------------------------------------------------------------------
#define	NUM_BUTTON_MAX			(8)		// ボタン(マウス)の最大数

//-------------------------------------------------------------------------------------------------------------
// クラスの定義
//-------------------------------------------------------------------------------------------------------------
class CMouse :public CInput
{
public:
	typedef struct
	{
		DIMOUSESTATE2	mouseState;	// 状態
		POINT			point;		// 位置
	} MOUSE;

	/* --- メンバ関数 --- */
	CMouse();
	~CMouse();
	HRESULT      Init(HINSTANCE hInstance, HWND hWnd);														// 初期化
	void         Update(void);																				// 更新
	void         Uninit(void);																				// 終了
	/* インライン関数 */
	inline bool  GetPress(int nButton)   { return (m_aButtonState[nButton] & 0x80) ? true : false; }		// 押しているとき
	inline bool  GetTrigger(int nButton) { return (m_aButtonStateTrigger[nButton] & 0x80) ? true : false; }	// 押した時
	inline bool  GetRelease(int nButton) { return (m_aButtonStateRelease[nButton] & 0x80) ? true : false; }	// 離した時
	inline LONG  GetMouseX(void)         { return m_mouse.point.x; }										// マウスX軸
	inline LONG  GetMouseY(void)         { return m_mouse.point.y; }										// マウスY軸
	inline POINT GetMousePoint(void)     { return m_mouse.point; }											// マウスの位置
private:
	MOUSE	m_mouse;									// マウスの情報
	BYTE	m_aButtonState[NUM_BUTTON_MAX];				// マウスの入力情報ワーク
	BYTE	m_aButtonStateTrigger[NUM_BUTTON_MAX];		// マウスのトリガー
	BYTE	m_aButtonStateRelease[NUM_BUTTON_MAX];		// 離した時
	HWND	m_hWnd;										// ウィンドウハンドル
};

#endif
