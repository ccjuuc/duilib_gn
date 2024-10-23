#ifndef UI_PALLET_H
#define UI_PALLET_H
#pragma once

namespace DuiLib {
	/////////////////////////////////////////////////////////////////////////////////////
	//
	class UILIB_API CColorPaletteUI : public CControlUI
	{
		DECLARE_DUICONTROL(CColorPaletteUI)
	public:
		CColorPaletteUI();
		virtual ~CColorPaletteUI();

		//»ñÈ¡×îÖÕ±»Ñ¡ÔñµÄÑÕÉ«£¬¿ÉÒÔÖ±½ÓÓÃÓÚÉèÖÃduilib±³¾°É«
		DWORD GetSelectColor();
		void SetSelectColor(DWORD dwColor);

		virtual LPCTSTR GetClass() const;
		virtual LPVOID GetInterface(LPCTSTR pstrName);
		virtual void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

		//ÉèÖÃ/»ñÈ¡ Pallet£¨µ÷É«°åÖ÷½çÃæ£©µÄ¸ß¶È
		void SetPalletHeight(int nHeight);
		int	GetPalletHeight() const;

		//ÉèÖÃ/»ñÈ¡ ÏÂ·½Bar£¨ÁÁ¶ÈÑ¡ÔñÀ¸£©µÄ¸ß¶È
		void SetBarHeight(int nHeight);
		int GetBarHeight() const;
		//ÉèÖÃ/»ñÈ¡ Ñ¡ÔñÍ¼±êµÄÂ·¾¶
		void SetThumbImage(LPCTSTR pszImage);
		LPCTSTR GetThumbImage() const;

		virtual void SetPos(RECT rc, bool bNeedInvalidate = true);
		virtual void DoInit();
		virtual void DoEvent(TEventUI& event);
		virtual void PaintBkColor(HDC hDC);
		virtual void PaintPallet(HDC hDC);

	protected:
		//¸üÐÂÊý¾Ý
		void UpdatePalletData();
		void UpdateBarData();

	private:
		HDC			m_MemDc;
		HBITMAP		m_hMemBitmap;
		BITMAP		m_bmInfo;
		BYTE		*m_pBits;
		UINT		m_uButtonState;
		bool		m_bIsInBar;
		bool		m_bIsInPallet;
		int			m_nCurH;
		int			m_nCurS;
		int			m_nCurB;

		int			m_nPalletHeight;
		int			m_nBarHeight;
		CDuiPoint		m_ptLastPalletMouse;
		CDuiPoint		m_ptLastBarMouse;
		CDuiString  m_strThumbImage;
	};
}

#endif // UI_PALLET_H