#ifndef GifAnimUI_h__
#define GifAnimUI_h__

#pragma once

namespace DuiLib
{
	class UILIB_API CGifAnimUI : public CControlUI
	{
		enum
		{ 
			EVENT_TIEM_ID = 100,
		};
		DECLARE_DUICONTROL(CGifAnimUI)
	public:
		CGifAnimUI(void);
		~CGifAnimUI(void);

		LPCTSTR	GetClass() const;
		LPVOID	GetInterface(LPCTSTR pstrName);
		void	DoInit();
		bool	DoPaint(HDC hDC, const RECT& rcPaint, CControlUI* pStopControl);
		void	DoEvent(TEventUI& event);
		void	SetVisible(bool bVisible = true );
		void	SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
		void	SetBkImage(LPCTSTR pStrImage);
		LPCTSTR GetBkImage();

		void	SetAutoPlay(bool bIsAuto = true );
		bool	IsAutoPlay() const;
		void	SetAutoSize(bool bIsAuto = true );
		bool	IsAutoSize() const;
		void	PlayGif();
		void	PauseGif();
		void	StopGif();

	private:
		void	InitGifImage();
		void	DeleteGif();
		void    OnTimer( UINT_PTR idEvent );
		void	DrawFrame( HDC hDC );		// »æÖÆGIFÃ¿Ö¡

	private:
		Gdiplus::Image	*m_pGifImage;
		UINT			m_nFrameCount;				// gifÍ¼Æ¬×ÜÖ¡Êý
		UINT			m_nFramePosition;			// µ±Ç°·Åµ½µÚ¼¸Ö¡
		Gdiplus::PropertyItem*	m_pPropertyItem;	// Ö¡ÓëÖ¡Ö®¼ä¼ä¸ôÊ±¼ä

		CDuiString		m_sBkImage;
		bool			m_bIsAutoPlay;				// ÊÇ·ñ×Ô¶¯²¥·Ågif
		bool			m_bIsAutoSize;				// ÊÇ·ñ×Ô¶¯¸ù¾ÝÍ¼Æ¬ÉèÖÃ´óÐ¡
		bool			m_bIsPlaying;
	};
}

#endif // GifAnimUI_h__
