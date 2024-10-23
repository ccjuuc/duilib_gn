#ifndef __UIBASE_H__
#define __UIBASE_H__

#pragma once
#define UILIB_STATIC
#define UILIB_API
namespace DuiLib {
	/////////////////////////////////////////////////////////////////////////////////////
	//
/////////////////////////////////////////////////////////////////////////////////////uidefine

#define MAX_FONT_ID		30000
#define CARET_TIMERID	0x1999

	// �б�����
	enum ListType
	{
		LT_LIST = 0,
		LT_COMBO,
		LT_TREE,
		LT_MENU,
	};

	// ����궨��
#define DUI_ARROW           32512
#define DUI_IBEAM           32513
#define DUI_WAIT            32514
#define DUI_CROSS           32515
#define DUI_UPARROW         32516
#define DUI_SIZE            32640
#define DUI_ICON            32641
#define DUI_SIZENWSE        32642
#define DUI_SIZENESW        32643
#define DUI_SIZEWE          32644
#define DUI_SIZENS          32645
#define DUI_SIZEALL         32646
#define DUI_NO              32648
#define DUI_HAND            32649

	// ��Ϣ����
	enum DuiSig
	{
		DuiSig_end = 0, // [marks end of message map]
		DuiSig_lwl,     // LRESULT (WPARAM, LPARAM)
		DuiSig_vn,      // void (TNotifyUI)
	};

	// ���Ŀؼ�
	class CControlUI;

		struct DUI_MSGMAP_ENTRY;
	struct DUI_MSGMAP
	{
#ifndef UILIB_STATIC
		const DUI_MSGMAP* (PASCAL* pfnGetBaseMap)();
#else
		const DUI_MSGMAP* pBaseMap;
#endif
		const DUI_MSGMAP_ENTRY* lpEntries;
	};


	#define DUI_DECLARE_MESSAGE_MAP()                                         \
private:                                                                  \
	static const DUI_MSGMAP_ENTRY _messageEntries[];                      \
protected:                                                                \
	static  const DUI_MSGMAP messageMap;				                  \
	virtual const DUI_MSGMAP* GetMessageMap() const;                      \


	// Structure for notifications to the outside world
	typedef struct tagTNotifyUI
	{
		CDuiString sType;
		CDuiString sVirtualWnd;
		CControlUI* pSender;
		DWORD dwTimestamp;
		POINT ptMouse;
		WPARAM wParam;
		LPARAM lParam;
	} TNotifyUI;
	class UILIB_API CNotifyPump
	{
	public:
		bool AddVirtualWnd(CDuiString strName,CNotifyPump* pObject);
		bool RemoveVirtualWnd(CDuiString strName);
		void NotifyPump(TNotifyUI& msg);
		bool LoopDispatch(TNotifyUI& msg);
		DUI_DECLARE_MESSAGE_MAP()
	private:
		CStdStringPtrMap m_VirtualWndMap;
	};

		typedef void (CNotifyPump::*DUI_PMSG)(TNotifyUI& msg);  

		struct DUI_MSGMAP_ENTRY //����һ���ṹ�壬�������Ϣ��Ϣ
	{
		CDuiString sMsgType;          // DUI��Ϣ����
		CDuiString sCtrlName;         // �ؼ�����
		UINT       nSig;              // ��Ǻ���ָ������
		DUI_PMSG   pfn;               // ָ������ָ��
	};


	union DuiMessageMapFunctions
	{
		DUI_PMSG pfn;   // generic member function pointer
		LRESULT(CNotifyPump::*pfn_Notify_lwl)(WPARAM, LPARAM);
		void (CNotifyPump::*pfn_Notify_vn)(TNotifyUI&);
	};

	//����������Ϣ����
	//////////////////////////////////////////////////////////////////////////

#define DUI_MSGTYPE_MENU                   (_T("menu"))
#define DUI_MSGTYPE_LINK                   (_T("link"))

#define DUI_MSGTYPE_TIMER                  (_T("timer"))
#define DUI_MSGTYPE_CLICK                  (_T("click"))
#define DUI_MSGTYPE_DBCLICK                (_T("dbclick"))

#define DUI_MSGTYPE_RETURN                 (_T("return"))
#define DUI_MSGTYPE_SCROLL                 (_T("scroll"))

#define DUI_MSGTYPE_PREDROPDOWN            (_T("predropdown"))
#define DUI_MSGTYPE_DROPDOWN               (_T("dropdown"))
#define DUI_MSGTYPE_SETFOCUS               (_T("setfocus"))

#define DUI_MSGTYPE_KILLFOCUS              (_T("killfocus"))
#define DUI_MSGTYPE_ITEMCLICK 		   	   (_T("itemclick"))
#define DUI_MSGTYPE_ITEMRCLICK 			   (_T("itemrclick"))
#define DUI_MSGTYPE_TABSELECT              (_T("tabselect"))

#define DUI_MSGTYPE_ITEMSELECT 		   	   (_T("itemselect"))
#define DUI_MSGTYPE_ITEMEXPAND             (_T("itemexpand"))
#define DUI_MSGTYPE_WINDOWINIT             (_T("windowinit"))
#define DUI_MSGTYPE_WINDOWSIZE             (_T("windowsize"))
#define DUI_MSGTYPE_BUTTONDOWN 		   	   (_T("buttondown"))
#define DUI_MSGTYPE_MOUSEENTER			   (_T("mouseenter"))
#define DUI_MSGTYPE_MOUSELEAVE			   (_T("mouseleave"))

#define DUI_MSGTYPE_TEXTCHANGED            (_T("textchanged"))
#define DUI_MSGTYPE_HEADERCLICK            (_T("headerclick"))
#define DUI_MSGTYPE_ITEMDBCLICK            (_T("itemdbclick"))
#define DUI_MSGTYPE_SHOWACTIVEX            (_T("showactivex"))

#define DUI_MSGTYPE_ITEMCOLLAPSE           (_T("itemcollapse"))
#define DUI_MSGTYPE_ITEMACTIVATE           (_T("itemactivate"))
#define DUI_MSGTYPE_VALUECHANGED           (_T("valuechanged"))
#define DUI_MSGTYPE_VALUECHANGED_MOVE      (_T("movevaluechanged"))

#define DUI_MSGTYPE_SELECTCHANGED 		   (_T("selectchanged"))
#define DUI_MSGTYPE_UNSELECTED	 		   (_T("unselected"))

#define DUI_MSGTYPE_TREEITEMDBCLICK 		(_T("treeitemdbclick"))
#define DUI_MSGTYPE_CHECKCLICK				(_T("checkclick"))
#define DUI_MSGTYPE_TEXTROLLEND 			(_T("textrollend"))
#define DUI_MSGTYPE_COLORCHANGED		    (_T("colorchanged"))

#define DUI_MSGTYPE_LISTITEMSELECT 		   	(_T("listitemselect"))
#define DUI_MSGTYPE_LISTITEMCHECKED 		(_T("listitemchecked"))
#define DUI_MSGTYPE_COMBOITEMSELECT 		(_T("comboitemselect"))
#define DUI_MSGTYPE_LISTHEADERCLICK			(_T("listheaderclick"))
#define DUI_MSGTYPE_LISTHEADITEMCHECKED		(_T("listheaditemchecked"))
#define DUI_MSGTYPE_LISTPAGECHANGED			(_T("listpagechanged"))

#define DUI_MSGTYPE_PAGECHANED				(_T("page_selected_changed"))


	//////////////////////////////////////////////////////////////////////////



#define DUI_BASE_BEGIN_MESSAGE_MAP(theClass)                              \
	const DUI_MSGMAP* theClass::GetMessageMap() const                     \
	{ return &theClass::messageMap; }                                 \
	UILIB_COMDAT const DUI_MSGMAP theClass::messageMap =                  \
	{  NULL, &theClass::_messageEntries[0] };                         \
	UILIB_COMDAT const DUI_MSGMAP_ENTRY theClass::_messageEntries[] =     \
	{                                                                     \



#define DUI_BEGIN_MESSAGE_MAP(theClass, baseClass)                        \
	const DUI_MSGMAP* theClass::GetMessageMap() const                     \
	{ return &theClass::messageMap; }                                 \
	UILIB_COMDAT const DUI_MSGMAP theClass::messageMap =                  \
	{ &baseClass::messageMap, &theClass::_messageEntries[0] };        \
	UILIB_COMDAT const DUI_MSGMAP_ENTRY theClass::_messageEntries[] =     \
	{                                                                     \


	//��������
#define DUI_END_MESSAGE_MAP()                                             \
	{ _T(""), _T(""), DuiSig_end, (DUI_PMSG)0 }                           \
	};                                                                        \


	//������Ϣ����--ִ�к�����
#define DUI_ON_MSGTYPE(msgtype, memberFxn)                                \
	{ msgtype, _T(""), DuiSig_vn, (DUI_PMSG)&memberFxn},                  \


	//������Ϣ����--�ؼ�����--ִ�к�����
#define DUI_ON_MSGTYPE_CTRNAME(msgtype,ctrname,memberFxn)                 \
	{ msgtype, ctrname, DuiSig_vn, (DUI_PMSG)&memberFxn },                \


	//����click��Ϣ�Ŀؼ�����--ִ�к�����
#define DUI_ON_CLICK_CTRNAME(ctrname,memberFxn)                           \
	{ DUI_MSGTYPE_CLICK, ctrname, DuiSig_vn, (DUI_PMSG)&memberFxn },      \


	//����selectchanged��Ϣ�Ŀؼ�����--ִ�к�����
#define DUI_ON_SELECTCHANGED_CTRNAME(ctrname,memberFxn)                   \
	{ DUI_MSGTYPE_SELECTCHANGED,ctrname,DuiSig_vn,(DUI_PMSG)&memberFxn }, \


	//����killfocus��Ϣ�Ŀؼ�����--ִ�к�����
#define DUI_ON_KILLFOCUS_CTRNAME(ctrname,memberFxn)                       \
	{ DUI_MSGTYPE_KILLFOCUS,ctrname,DuiSig_vn,(DUI_PMSG)&memberFxn },     \


	//����menu��Ϣ�Ŀؼ�����--ִ�к�����
#define DUI_ON_MENU_CTRNAME(ctrname,memberFxn)                            \
	{ DUI_MSGTYPE_MENU,ctrname,DuiSig_vn,(DUI_PMSG)&memberFxn },          \


	//������ؼ������޹ص���Ϣ��

	//����timer��Ϣ--ִ�к�����
#define DUI_ON_TIMER()                                                    \
	{ DUI_MSGTYPE_TIMER, _T(""), DuiSig_vn,(DUI_PMSG)&OnTimer },          \


	///
	//////////////END��Ϣӳ��궨��////////////////////////////////////////////////////


//////////////BEGIN�ؼ����ƺ궨��//////////////////////////////////////////////////
///
#define  DUI_CTR_BOX							 (_T("Box")) //

#define  DUI_CTR_EDIT                            (_T("Edit"))
#define  DUI_CTR_LIST                            (_T("List"))
#define  DUI_CTR_TEXT                            (_T("Text"))
#define  DUI_CTR_HBOX                            (_T("HBox"))
#define  DUI_CTR_VBOX                            (_T("VBox"))
#define  DUI_CTR_RING							 (_T("Ring"))

#define  DUI_CTR_COMBO                           (_T("Combo"))
#define  DUI_CTR_LABEL                           (_T("Label"))
#define  DUI_CTR_FLASH							 (_T("Flash"))

#define  DUI_CTR_BUTTON                          (_T("Button"))
#define  DUI_CTR_OPTION                          (_T("Option"))
#define  DUI_CTR_SLIDER                          (_T("Slider"))
#define  DUI_CTR_TAB_BOX					     (_T("TabBox")) //

#define  DUI_CTR_CONTROL                         (_T("Control"))
#define  DUI_CTR_ACTIVEX                         (_T("ActiveX"))
#define  DUI_CTR_GIFANIM                         (_T("GifAnim"))
#define	 DUI_CTR_TILE_BOX						 (_T("TileBox")) //
#define  DUI_CTR_LOADINGCIRCLE					 (_T("Loading")) //

#define  DUI_CTR_LISTITEM                        (_T("ListItem"))
#define  DUI_CTR_PROGRESS                        (_T("Progress"))
#define  DUI_CTR_RICHEDIT                        (_T("RichEdit"))
#define  DUI_CTR_CHECKBOX                        (_T("CheckBox"))
#define  DUI_CTR_COMBOBOX                        (_T("ComboBox"))
#define  DUI_CTR_DATETIME                        (_T("DateTime"))
#define  DUI_CTR_TREEVIEW                        (_T("TreeView"))
#define  DUI_CTR_TREENODE                        (_T("TreeNode"))
#define  DUI_CTR_CHILD_BOX					     (_T("ChildBox")) //

#define  DUI_CTR_CONTAINER                       (_T("Container"))
#define  DUI_CTR_TABLAYOUT                       (_T("TabLayout"))
#define  DUI_CTR_SCROLLBAR                       (_T("ScrollBar"))
#define  DUI_CTR_IPADDRESS                       (_T("IPAddress"))

#define  DUI_CTR_LISTHEADER                      (_T("ListHeader"))
#define  DUI_CTR_LISTFOOTER                      (_T("ListFooter"))
#define  DUI_CTR_TILELAYOUT                      (_T("TileLayout"))
#define  DUI_CTR_WEBBROWSER                      (_T("WebBrowser"))

#define  DUI_CTR_CHILDLAYOUT                     (_T("ChildLayout"))
#define  DUI_CTR_LISTELEMENT                     (_T("ListElement"))

#define  DUI_CTR_VERTICALLAYOUT                  (_T("VerticalLayout"))
#define  DUI_CTR_LISTHEADERITEM                  (_T("ListHeaderItem"))

#define  DUI_CTR_LISTTEXTELEMENT                 (_T("ListTextElement"))

#define  DUI_CTR_HORIZONTALLAYOUT                (_T("HorizontalLayout"))
#define  DUI_CTR_LISTLABELELEMENT                (_T("ListLabelElement"))

#define  DUI_CTR_ANIMATIONTABLAYOUT				 (_T("AnimationTabLayout"))

#define  DUI_CTR_LISTCONTAINERELEMENT            (_T("ListContainerElement"))

#define  DUI_CTR_TEXTSCROLL						 (_T("TextScroll"))

#define DUI_CTR_COLORPALETTE					  (_T("ColorPalette"))


/////////////////////////////////////////////////////////////////////////////////////uidefine


#define UI_WNDSTYLE_CONTAINER  (0)
#define UI_WNDSTYLE_FRAME      (WS_VISIBLE | WS_OVERLAPPEDWINDOW)
#define UI_WNDSTYLE_CHILD      (WS_VISIBLE | WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN)
#define UI_WNDSTYLE_DIALOG     (WS_VISIBLE | WS_POPUPWINDOW | WS_CAPTION | WS_DLGFRAME | WS_CLIPSIBLINGS | WS_CLIPCHILDREN)

#define UI_WNDSTYLE_EX_FRAME   (WS_EX_WINDOWEDGE)
#define UI_WNDSTYLE_EX_DIALOG  (WS_EX_TOOLWINDOW | WS_EX_DLGMODALFRAME)

#define UI_CLASSSTYLE_CONTAINER  (0)
#define UI_CLASSSTYLE_FRAME      (CS_VREDRAW | CS_HREDRAW)
#define UI_CLASSSTYLE_CHILD      (CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS | CS_SAVEBITS)
#define UI_CLASSSTYLE_DIALOG     (CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS | CS_SAVEBITS)


	/////////////////////////////////////////////////////////////////////////////////////
	//
#ifndef ASSERT
#define ASSERT(expr)  _ASSERTE(expr)
#endif

#ifdef _DEBUG
#ifndef DUITRACE
#define DUITRACE DUI__Trace
#endif
#define DUITRACEMSG DUI__TraceMsg
#else
#ifndef DUITRACE
#define DUITRACE
#endif
#define DUITRACEMSG _T("")
#endif

	void UILIB_API DUI__Trace(LPCTSTR pstrFormat, ...);
	LPCTSTR UILIB_API DUI__TraceMsg(UINT uMsg);

	/////////////////////////////////////////////////////////////////////////////////////
	//

	class UILIB_API CWindowWnd
	{
	public:
		CWindowWnd();

		HWND GetHWND() const;
		operator HWND() const;

		void EnableUnicode();

		bool RegisterWindowClass();
		bool RegisterSuperclass();

		HWND Create(HWND hwndParent, LPCTSTR pstrName, DWORD dwStyle, DWORD dwExStyle, const RECT rc, HMENU hMenu = NULL);
		HWND Create(HWND hwndParent, LPCTSTR pstrName, DWORD dwStyle, DWORD dwExStyle, int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, int cx = CW_USEDEFAULT, int cy = CW_USEDEFAULT, HMENU hMenu = NULL);
		HWND CreateDuiWindow(HWND hwndParent, LPCTSTR pstrWindowName,DWORD dwStyle =0, DWORD dwExStyle =0);

		HWND Subclass(HWND hWnd);
		void Unsubclass();
		void ShowWindow(bool bShow = true, bool bTakeFocus = true);
		UINT ShowModal();
    	void ShowModalFake();
		void Close(UINT nRet = IDOK);
		void CenterWindow();	// ���У�֧����չ��Ļ
		void SetIcon(UINT nRes);

		LRESULT SendMessage(UINT uMsg, WPARAM wParam = 0, LPARAM lParam = 0L);
		LRESULT PostMessage(UINT uMsg, WPARAM wParam = 0, LPARAM lParam = 0L);
		void ResizeClient(int cx = -1, int cy = -1);

	protected:
		virtual LPCTSTR GetWindowClassName() const = 0;
		virtual LPCTSTR GetSuperClassName() const;
		virtual UINT GetClassStyle() const;

		virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
		virtual void OnFinalMessage(HWND hWnd);

		static LRESULT CALLBACK __WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK __ControlProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	protected:
		HWND m_hWnd;
		WNDPROC m_OldWndProc;
		bool m_bSubclassed;
		bool m_bUnicode;
		bool m_bFakeModal;
	};

} // namespace DuiLib

#endif // __UIBASE_H__
