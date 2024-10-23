#ifndef __UISHADOW_H__
#define __UISHADOW_H__

#pragma once
#include <map>

namespace DuiLib
{

class UILIB_API CShadowUI
{
public:
	friend class CPaintManagerUI;

	CShadowUI(void);
	virtual ~CShadowUI(void);

public:
	// bShowÎªÕæÊ±²Å»á´´½¨ÒõÓ°
	void ShowShadow(bool bShow);	
	bool IsShowShadow() const;

	void DisableShadow(bool bDisable);
	bool IsDisableShadow() const;

	// Ëã·¨ÒõÓ°µÄº¯Êý
	bool SetSize(int NewSize = 0);
	bool SetSharpness(unsigned int NewSharpness = 5);
	bool SetDarkness(unsigned int NewDarkness = 200);
	bool SetPosition(int NewXOffset = 5, int NewYOffset = 5);
	bool SetColor(COLORREF NewColor = 0);

	// Í¼Æ¬ÒõÓ°µÄº¯Êý
	bool SetImage(LPCTSTR szImage);
	bool SetShadowCorner(RECT rcCorner);	// ¾Å¹¬¸ñ·½Ê½ÃèÊöÒõÓ°
	
	// °Ñ×Ô¼ºµÄÒõÓ°ÑùÊ½¸´ÖÆµ½´«Èë²ÎÊý
	bool CopyShadow(CShadowUI* pShadow);

	//	´´½¨ÒõÓ°´°Ìå£¬ÓÉCPaintManagerUI×Ô¶¯µ÷ÓÃ,³ý·Ç×Ô¼ºÒªµ¥¶À´´½¨ÒõÓ°
	void Create(CPaintManagerUI* pPaintManager);
protected:

	//	³õÊ¼»¯²¢×¢²áÒõÓ°Àà
	static bool Initialize(HINSTANCE hInstance);

	// ±£´æÒÑ¾­¸½¼ÓµÄ´°Ìå¾ä±úºÍÓëÆä¹ØÁªµÄÒõÓ°Àà,·½±ãÔÚParentProc()º¯ÊýÖÐÍ¨¹ý¾ä±úµÃµ½ÒõÓ°Àà
	static std::map<HWND, CShadowUI *>& GetShadowMap();

	//	×ÓÀà»¯¸¸´°Ìå
	static LRESULT CALLBACK ParentProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	// ¸¸´°Ìå¸Ä±ä´óÐ¡£¬ÒÆ¶¯£¬»òÕßÖ÷¶¯ÖØ»æÒõÓ°Ê±µ÷ÓÃ
	void Update(HWND hParent);

	// Í¨¹ýËã·¨¼ÆËãÒõÓ°
	void MakeShadow(UINT32 *pShadBits, HWND hParent, RECT *rcParent);

	// ¼ÆËãalphaÔ¤³ËÖµ
	inline DWORD PreMultiply(COLORREF cl, unsigned char nAlpha)
	{
		return (GetRValue(cl) * (DWORD)nAlpha / 255) |
			(GetGValue(cl) * (DWORD)nAlpha / 255) << 8 |
			(GetBValue(cl) * (DWORD)nAlpha / 255) << 16 ;
	}

protected:
	enum ShadowStatus
	{
		SS_ENABLED = 1,				// Shadow is enabled, if not, the following one is always false
		SS_VISABLE = 1 << 1,		// Shadow window is visible
		SS_PARENTVISIBLE = 1<< 2	// Parent window is visible, if not, the above one is always false
	};

	
	static bool s_bHasInit;

	CPaintManagerUI	*m_pManager;		// ¸¸´°ÌåµÄCPaintManagerUI£¬ÓÃÀ´»ñÈ¡ËØ²Ä×ÊÔ´ºÍ¸¸´°Ìå¾ä±ú
	HWND			 m_hWnd;			// ÒõÓ°´°ÌåµÄ¾ä±ú
	LONG_PTR		 m_OriParentProc;	// ×ÓÀà»¯¸¸´°Ìå
	BYTE			 m_Status;
	bool			 m_bIsImageMode;	// ÊÇ·ñÎªÍ¼Æ¬ÒõÓ°Ä£Ê½
	bool			 m_bIsShowShadow;	// ÊÇ·ñÒªÏÔÊ¾ÒõÓ°
	bool			m_bIsDisableShadow;
	// Ëã·¨ÒõÓ°³ÉÔ±±äÁ¿
	unsigned char m_nDarkness;	// Darkness, transparency of blurred area
	unsigned char m_nSharpness;	// Sharpness, width of blurred border of shadow window
	signed char m_nSize;	// Shadow window size, relative to parent window size

	// The X and Y offsets of shadow window,
	// relative to the parent window, at center of both windows (not top-left corner), signed
	signed char m_nxOffset;
	signed char m_nyOffset;

	// Restore last parent window size, used to determine the update strategy when parent window is resized
	LPARAM m_WndSize;

	// Set this to true if the shadow should not be update until next WM_PAINT is received
	bool m_bUpdate;

	COLORREF m_Color;	// Color of shadow

	// Í¼Æ¬ÒõÓ°³ÉÔ±±äÁ¿
	CDuiString	m_sShadowImage;
	RECT		m_rcShadowCorner;
};

}

#endif //__UISHADOW_H__