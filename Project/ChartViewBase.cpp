//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: ChartView.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "ChartViewBase.h"


// Declare the bitmap loading function
extern void wxCE3EBInitBitmapResources();

static bool bBitmapLoaded = false;


ChartViewBase::ChartViewBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxFrame(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCE3EBInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    m_menuBar = new wxMenuBar(0);
    this->SetMenuBar(m_menuBar);
    
    m_menuFile = new wxMenu();
    m_menuBar->Append(m_menuFile, _("File"));
    
    m_menuItemSaveImage = new wxMenuItem(m_menuFile, wxID_ANY, _("Save chart as image"), wxT(""), wxITEM_NORMAL);
    m_menuFile->Append(m_menuItemSaveImage);
    
    m_menuItemSendToClipboard = new wxMenuItem(m_menuFile, wxID_ANY, _("Send to clipboard"), wxT(""), wxITEM_NORMAL);
    m_menuFile->Append(m_menuItemSendToClipboard);
    
    m_menuFile->AppendSeparator();
    
    m_menuItemExit = new wxMenuItem(m_menuFile, wxID_ANY, _("Exit"), wxT(""), wxITEM_NORMAL);
    m_menuFile->Append(m_menuItemExit);
    
    m_menuView = new wxMenu();
    m_menuBar->Append(m_menuView, _("View"));
    
    m_menuItemFit = new wxMenuItem(m_menuView, wxID_ANY, _("Fit"), wxT(""), wxITEM_NORMAL);
    m_menuView->Append(m_menuItemFit);
    
    m_menuView->AppendSeparator();
    
    m_menuItemShowGrid = new wxMenuItem(m_menuView, wxID_ANY, _("Show grid"), wxT(""), wxITEM_CHECK);
    m_menuView->Append(m_menuItemShowGrid);
    
    m_menuItemShowLabel = new wxMenuItem(m_menuView, wxID_ANY, _("Show label"), wxT(""), wxITEM_CHECK);
    m_menuView->Append(m_menuItemShowLabel);
    
    m_menuItemShowCoordinates = new wxMenuItem(m_menuView, wxID_ANY, _("Show coordinates"), wxT(""), wxITEM_CHECK);
    m_menuView->Append(m_menuItemShowCoordinates);
    
    m_menuItemDarkTheme = new wxMenuItem(m_menuView, wxID_ANY, _("Dark theme"), wxT(""), wxITEM_CHECK);
    m_menuView->Append(m_menuItemDarkTheme);
    
    wxBoxSizer* boxSizer_lvl1_1 = new wxBoxSizer(wxHORIZONTAL);
    this->SetSizer(boxSizer_lvl1_1);
    
    wxBoxSizer* boxSizer_lvl2_1 = new wxBoxSizer(wxVERTICAL);
    
    boxSizer_lvl1_1->Add(boxSizer_lvl2_1, 0, wxEXPAND, WXC_FROM_DIP(5));
    
    m_treeCtrl = new wxTreeCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxTR_DEFAULT_STYLE|wxTR_HIDE_ROOT);
    
    boxSizer_lvl2_1->Add(m_treeCtrl, 1, 0, WXC_FROM_DIP(5));
    m_treeCtrl->SetMinSize(wxSize(250,-1));
    
    wxArrayString m_pgMgrArr;
    wxUnusedVar(m_pgMgrArr);
    wxArrayInt m_pgMgrIntArr;
    wxUnusedVar(m_pgMgrIntArr);
    m_pgMgr = new wxPropertyGridManager(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxPG_SPLITTER_AUTO_CENTER|wxPG_BOLD_MODIFIED);
    
    boxSizer_lvl2_1->Add(m_pgMgr, 0, 0, WXC_FROM_DIP(5));
    
    m_pgPropLineProp = m_pgMgr->Append(  new wxPropertyCategory( _("Line properties") ) );
    m_pgPropLineProp->SetHelpString(wxT(""));
    
    m_pgPropDraw = m_pgMgr->AppendIn( m_pgPropLineProp,  new wxBoolProperty( _("Draw"), wxPG_LABEL, 1) );
    m_pgPropDraw->SetHelpString(wxT(""));
    m_pgPropDraw->SetEditor( wxT("CheckBox") );
    
    m_pgProplineThick = m_pgMgr->AppendIn( m_pgPropLineProp,  new wxIntProperty( _("Thickness"), wxPG_LABEL, 1) );
    m_pgProplineThick->SetHelpString(wxT(""));
    m_pgProplineThick->SetEditor( wxT("TextCtrl") );
    
    m_pgMgrArr.Clear();
    m_pgMgrIntArr.Clear();
    m_pgMgrArr.Add(_("Solid"));
    m_pgMgrArr.Add(_("Dot"));
    m_pgMgrArr.Add(_("Dash"));
    m_pgMgrArr.Add(_("Dot and dash"));
    m_pgMgrArr.Add(_("Cross"));
    m_pgMgrArr.Add(_("Diagonal cross"));
    m_pgProplineType = m_pgMgr->AppendIn( m_pgPropLineProp,  new wxEnumProperty( _("Type"), wxPG_LABEL, m_pgMgrArr, m_pgMgrIntArr, 0) );
    m_pgProplineType->SetHelpString(wxT(""));
    m_pgProplineType->SetEditor( wxT("Choice") );
    
    m_pgMgrArr.Clear();
    m_pgMgrIntArr.Clear();
    m_pgMgrArr.Add(_("Y"));
    m_pgMgrArr.Add(_("X"));
    m_pgProplineAxis = m_pgMgr->AppendIn( m_pgPropLineProp,  new wxEnumProperty( _("Axis"), wxPG_LABEL, m_pgMgrArr, m_pgMgrIntArr, 0) );
    m_pgProplineAxis->SetHelpString(wxT(""));
    m_pgProplineAxis->SetEditor( wxT("Choice") );
    
    m_pgPropChartProp = m_pgMgr->Append(  new wxPropertyCategory( _("Chart properties") ) );
    m_pgPropChartProp->SetHelpString(wxT(""));
    
    m_pgPropChartTitle = m_pgMgr->AppendIn( m_pgPropChartProp,  new wxStringProperty( _("Chart title"), wxPG_LABEL, wxT("")) );
    m_pgPropChartTitle->SetHelpString(wxT(""));
    m_pgPropChartTitle->SetEditor( wxT("TextCtrl") );
    
    m_pgPropXLabel = m_pgMgr->AppendIn( m_pgPropChartProp,  new wxStringProperty( _("X axis label"), wxPG_LABEL, wxT("")) );
    m_pgPropXLabel->SetHelpString(wxT(""));
    m_pgPropXLabel->SetEditor( wxT("TextCtrl") );
    
    m_pgPropYLabel = m_pgMgr->AppendIn( m_pgPropChartProp,  new wxStringProperty( _("Y axis label"), wxPG_LABEL, wxT("")) );
    m_pgPropYLabel->SetHelpString(wxT(""));
    m_pgPropYLabel->SetEditor( wxT("TextCtrl") );
    
    m_pgPropMargins = m_pgMgr->AppendIn( m_pgPropChartProp,  new wxStringProperty( _("Margins"), wxPG_LABEL, wxT("")) );
    m_pgPropMargins->SetHelpString(wxT(""));
    
    m_pgPropMarginsUp = m_pgMgr->AppendIn( m_pgPropMargins,  new wxIntProperty( _("Up"), wxPG_LABEL, 20) );
    m_pgPropMarginsUp->SetHelpString(wxT(""));
    
    m_pgPropMarginsBot = m_pgMgr->AppendIn( m_pgPropMargins,  new wxIntProperty( _("Botton"), wxPG_LABEL, 40) );
    m_pgPropMarginsBot->SetHelpString(wxT(""));
    
    m_pgPropMarginsLeft = m_pgMgr->AppendIn( m_pgPropMargins,  new wxIntProperty( _("Left"), wxPG_LABEL, 60) );
    m_pgPropMarginsLeft->SetHelpString(wxT(""));
    
    m_pgPropMarginsRight = m_pgMgr->AppendIn( m_pgPropMargins,  new wxIntProperty( _("Right"), wxPG_LABEL, 10) );
    m_pgPropMarginsRight->SetHelpString(wxT(""));
    
    m_pgPropAxisLimit = m_pgMgr->AppendIn( m_pgPropChartProp,  new wxStringProperty( _("Axis limit"), wxPG_LABEL, wxT("")) );
    m_pgPropAxisLimit->SetHelpString(wxT(""));
    
    m_pgPropXMin = m_pgMgr->AppendIn( m_pgPropAxisLimit,  new wxFloatProperty( _("X min"), wxPG_LABEL, 0) );
    m_pgPropXMin->SetHelpString(wxT(""));
    
    m_pgPropXMax = m_pgMgr->AppendIn( m_pgPropAxisLimit,  new wxFloatProperty( _("X max"), wxPG_LABEL, 1) );
    m_pgPropXMax->SetHelpString(wxT(""));
    
    m_pgPropYMin = m_pgMgr->AppendIn( m_pgPropAxisLimit,  new wxFloatProperty( _("Y min"), wxPG_LABEL, 0) );
    m_pgPropYMin->SetHelpString(wxT(""));
    
    m_pgPropYMax = m_pgMgr->AppendIn( m_pgPropAxisLimit,  new wxFloatProperty( _("Y max"), wxPG_LABEL, 1) );
    m_pgPropYMax->SetHelpString(wxT(""));
    m_pgMgr->SetMinSize(wxSize(250,250));
    
    SetName(wxT("ChartViewBase"));
    SetSize(-1,-1);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    this->Connect(m_menuItemSaveImage->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ChartViewBase::OnMenuSaveImageClick), NULL, this);
    this->Connect(m_menuItemSendToClipboard->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ChartViewBase::OnMenuSendClipClick), NULL, this);
    this->Connect(m_menuItemExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ChartViewBase::OnMenuExitClick), NULL, this);
    this->Connect(m_menuItemFit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ChartViewBase::OnMenuFitClick), NULL, this);
    this->Connect(m_menuItemShowGrid->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ChartViewBase::OnMenuShowGridClick), NULL, this);
    this->Connect(m_menuItemShowLabel->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ChartViewBase::OnMenuShowLabelClick), NULL, this);
    this->Connect(m_menuItemShowCoordinates->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ChartViewBase::OnMenuShowCoordinatesClick), NULL, this);
    this->Connect(m_menuItemDarkTheme->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ChartViewBase::OnMenuDarkThemeClick), NULL, this);
    m_treeCtrl->Connect(wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler(ChartViewBase::OnTreeItemActivated), NULL, this);
    m_treeCtrl->Connect(wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler(ChartViewBase::OnTreeItemSelectionChanged), NULL, this);
    m_pgMgr->Connect(wxEVT_PG_CHANGED, wxPropertyGridEventHandler(ChartViewBase::OnPropertyGridChange), NULL, this);
    
}

ChartViewBase::~ChartViewBase()
{
    this->Disconnect(m_menuItemSaveImage->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ChartViewBase::OnMenuSaveImageClick), NULL, this);
    this->Disconnect(m_menuItemSendToClipboard->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ChartViewBase::OnMenuSendClipClick), NULL, this);
    this->Disconnect(m_menuItemExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ChartViewBase::OnMenuExitClick), NULL, this);
    this->Disconnect(m_menuItemFit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ChartViewBase::OnMenuFitClick), NULL, this);
    this->Disconnect(m_menuItemShowGrid->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ChartViewBase::OnMenuShowGridClick), NULL, this);
    this->Disconnect(m_menuItemShowLabel->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ChartViewBase::OnMenuShowLabelClick), NULL, this);
    this->Disconnect(m_menuItemShowCoordinates->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ChartViewBase::OnMenuShowCoordinatesClick), NULL, this);
    this->Disconnect(m_menuItemDarkTheme->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ChartViewBase::OnMenuDarkThemeClick), NULL, this);
    m_treeCtrl->Disconnect(wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler(ChartViewBase::OnTreeItemActivated), NULL, this);
    m_treeCtrl->Disconnect(wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler(ChartViewBase::OnTreeItemSelectionChanged), NULL, this);
    m_pgMgr->Disconnect(wxEVT_PG_CHANGED, wxPropertyGridEventHandler(ChartViewBase::OnPropertyGridChange), NULL, this);
    
}
