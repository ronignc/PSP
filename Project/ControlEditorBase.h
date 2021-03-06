//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: ControlEditor.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef _PSP_PROJECT_CONTROLEDITOR_BASE_CLASSES_H
#define _PSP_PROJECT_CONTROLEDITOR_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/frame.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/toolbar.h>
#include <wx/aui/framemanager.h>
#include <wx/aui/dockart.h>
#include <wx/panel.h>
#include <wx/glcanvas.h>
#include <wx/statusbr.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif


class ControlEditorBase : public wxFrame
{
public:
    enum {
        ID_RIBBON_EXPORT = 10001,
        ID_RIBBON_IMPORT = 10002,
    };
protected:
    wxToolBar* m_toolbarMain;
    wxAuiManager* m_auimgr;
    wxPanel* m_panelControlElements;
    wxPanel* m_panelWorkspace;
    wxGLCanvas* m_glCanvas;
    wxStatusBar* m_statusBarMain;

protected:
    virtual void OnKeyDown(wxKeyEvent& event) { event.Skip(); }
    virtual void OnImportClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnExportClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnPaint(wxPaintEvent& event) { event.Skip(); }
    virtual void OnLeftClickDown(wxMouseEvent& event) { event.Skip(); }
    virtual void OnLeftClickUp(wxMouseEvent& event) { event.Skip(); }
    virtual void OnDoubleClick(wxMouseEvent& event) { event.Skip(); }
    virtual void OnMiddleDown(wxMouseEvent& event) { event.Skip(); }
    virtual void OnMiddleUp(wxMouseEvent& event) { event.Skip(); }
    virtual void OnMouseMotion(wxMouseEvent& event) { event.Skip(); }
    virtual void OnScroll(wxMouseEvent& event) { event.Skip(); }
    virtual void OnIdle(wxIdleEvent& event) { event.Skip(); }

public:
    wxToolBar* GetToolbarMain() { return m_toolbarMain; }
    wxPanel* GetPanelControlElements() { return m_panelControlElements; }
    wxGLCanvas* GetGlCanvas() { return m_glCanvas; }
    wxPanel* GetPanelWorkspace() { return m_panelWorkspace; }
    wxAuiManager* GetAuimgr() { return m_auimgr; }
    wxStatusBar* GetStatusBarMain() { return m_statusBarMain; }
    ControlEditorBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Control editor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(800,600), long style = wxDEFAULT_FRAME_STYLE);
    virtual ~ControlEditorBase();
};

#endif
