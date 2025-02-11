#ifndef __UILoadingCircle_H
#define __UILoadingCircle_H

namespace DuiLib
{

enum StylePresets
{
	Custom,
	MacOSX,
	Firefox,
	IE7
};

class UILIB_API CLoadingUI : public CControlUI
{
    DECLARE_DUICONTROL(CControlUI)

	enum TIMEID
	{
		kTimerLoadingId = 100,
	};
public:
	CLoadingUI();
	virtual ~CLoadingUI();

	LPCTSTR GetClass() const;
	LPVOID GetInterface(LPCTSTR pstrName);

	virtual void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
	void Start();
	void Stop();
protected:
    virtual void PaintBkImage(HDC hDC);
    virtual void DoEvent(TEventUI& event);
	virtual void Init();
	Gdiplus::Color* GenerateColorsPallet(Gdiplus::Color _objColor, bool _blnShadeColor, int _intNbSpoke);

protected:
	int                 m_nNumber;
	int                 m_nTime;
	bool				m_bStop;

	int m_NumberOfSpoke;//·øÌõÊýÁ¿
	int m_SpokeThickness;//·øÌõ´ÖÏ¸
	int m_ProgressValue;//------------------------
	int m_OuterCircleRadius;//ÍâÈ¦
	int m_InnerCircleRadius;//ÄÚÈ¦
	Gdiplus::PointF m_CenterPoint;//¶þÎ¬Æ½ÃæµÄµã
	Gdiplus::Color m_Color;
	Gdiplus::Color* m_Colors;
	double* m_Angles;
};

CControlUI* CreateLoadingControl(LPCTSTR pstrType);

}


#endif //__UILoadingCircle_H
