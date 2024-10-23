#ifndef __UICOMBOBOX_H__
#define __UICOMBOBOX_H__

#pragma once

namespace DuiLib
{
	/// À©Õ¹ÏÂÀ­ÁÐ±í¿ò
	/// Ôö¼ÓarrowimageÊôÐÔ,Ò»ÕÅÍ¼Æ¬Æ½¾ù·Ö³É5·Ý,Normal/Hot/Pushed/Focused/Disabled(±ØÐëÓÐsourceÊôÐÔ)
	/// <Default name="ComboBox" value="arrowimage=&quot;file='sys_combo_btn.png' source='0,0,16,16'&quot; "/>
	class UILIB_API CComboBoxUI : public CComboUI
	{
		DECLARE_DUICONTROL(CComboBoxUI)
	public:
		CComboBoxUI();
		LPCTSTR GetClass() const;

		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

		void PaintText(HDC hDC);
		void PaintStatusImage(HDC hDC);

	protected:
		CDuiString m_sArrowImage;
		int        m_nArrowWidth;
	};
}

#endif // __UICOMBOBOX_H__
