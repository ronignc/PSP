#include "ChartView.h"
#include "ElementPlotData.h"

ChartView::ChartView(wxWindow* parent, std::vector<ElementPlotData> epdList, std::vector<double> time)
    : ChartViewBase(parent)
{
    m_epdList = epdList;
    m_time = time;
    m_xAxisValues = time;

    m_menuItemShowGrid->Check(m_hideGrid ? false : true);
    m_menuItemShowLabel->Check(m_showLeg);
    m_menuItemShowCoordinates->Check(m_showCoords);
    m_menuItemDarkTheme->Check(m_darkTheme);

    // Create color property.
    m_pgPropColor = m_pgMgr->Insert(m_pgPropLineProp, 1, new wxColourProperty(_("Color")));
    m_pgPropColor->SetEditor(wxT("ChoiceAndButton"));
    m_pgPropColor->SetValue(static_cast<wxVariant>(*wxBLACK));

    // Set margins and axis limit to composed mode.
    m_pgPropMargins->SetValue(wxT("<composed>"));
    m_pgMgr->Collapse(m_pgPropMargins);
    m_pgPropAxisLimit->SetValue(wxT("<composed>"));
    m_pgMgr->Collapse(m_pgPropAxisLimit);

    // Add line type choices
    m_pgProplineType->AddChoice(_("Solid"), wxPENSTYLE_SOLID);
    m_pgProplineType->AddChoice(_("Dot"), wxPENSTYLE_DOT);
    m_pgProplineType->AddChoice(_("Dash"), wxPENSTYLE_SHORT_DASH);
    m_pgProplineType->AddChoice(_("Dot and dash"), wxPENSTYLE_DOT_DASH);
    m_pgProplineType->AddChoice(_("Cross"), wxPENSTYLE_CROSS_HATCH);
    m_pgProplineType->AddChoice(_("Driagonal cross"), wxPENSTYLE_CROSSDIAG_HATCH);

    SetMPWindow();
    GetSizer()->Add(m_mpWindow, 1, wxEXPAND, WXC_FROM_DIP(5));
    SetTreectrl();
    Layout();
    SetInitialSize();

    BuildColourList();
}

ChartView::~ChartView() {}
void ChartView::SetMPWindow()
{
    m_mpWindow = new mpWindow(this, wxID_ANY);

    m_mpWindow->SetMargins(20, 10, 40, 60);
    m_xaxis = new mpScaleX("", mpALIGN_BOTTOM, true);
    m_yaxis = new mpScaleY("", mpALIGN_LEFT, true);
    m_xaxis->SetDrawOutsideMargins(false);
    m_yaxis->SetDrawOutsideMargins(false);
    m_xaxis->SetTicks(m_hideGrid);
    m_yaxis->SetTicks(m_hideGrid);

    m_leg = new mpInfoLegend(wxRect(200, 20, 40, 40), wxWHITE_BRUSH);
    m_coords = new mpInfoCoords(wxRect(0, 0, 0, 0), wxWHITE_BRUSH);

    m_chartTitle = new mpText("", 50, 0);
    wxFont chartTitleFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    m_chartTitle->SetFont(chartTitleFont);

    m_mpWindow->AddLayer(m_xaxis);
    m_mpWindow->AddLayer(m_yaxis);
    m_mpWindow->AddLayer(m_leg);
    m_mpWindow->AddLayer(m_coords);
    m_mpWindow->AddLayer(m_chartTitle);

    m_leg->SetVisible(m_showLeg);
    m_coords->SetVisible(m_showCoords);

    m_mpWindow->EnableDoubleBuffer(true);
    m_mpWindow->LockAspect(false);
    Fit();
}

void ChartView::SetTreectrl()
{
    wxTreeItemId rootID = m_treeCtrl->AddRoot(wxT("root"));
    m_treeTimeID = m_treeCtrl->AppendItem(rootID, _("Time"));
    m_treeCtrl->SetItemTextColour(m_treeTimeID, *wxRED);

    bool firstElement[ElementPlotData::NUM_ELEMENTS];
    for(int i = 0; i < ElementPlotData::NUM_ELEMENTS; ++i) firstElement[i] = true;

    wxString rootElementName[ElementPlotData::NUM_ELEMENTS];
    rootElementName[ElementPlotData::CT_BUS] = _("Bus");
    rootElementName[ElementPlotData::CT_IND_MOTOR] = _("Induction motor");
    rootElementName[ElementPlotData::CT_LINE] = _("Line");
    rootElementName[ElementPlotData::CT_LOAD] = _("Load");
    rootElementName[ElementPlotData::CT_SHUNT_CAPACITOR] = _("Capacitor");
    rootElementName[ElementPlotData::CT_SHUNT_INDUCTOR] = _("Inductor");
    rootElementName[ElementPlotData::CT_SYNC_COMPENSATOR] = _("Synchronous compensator");
    rootElementName[ElementPlotData::CT_SYNC_GENERATOR] = _("Synchronous generator");
    rootElementName[ElementPlotData::CT_TRANSFORMER] = _("Transformer");

    wxTreeItemId rootItemID[ElementPlotData::NUM_ELEMENTS];

    for(auto it = m_epdList.begin(), itEnd = m_epdList.end(); it != itEnd; ++it) {
        ElementPlotData data = *it;
        ElementPlotData::CurveType curveType = data.GetCurveType();

        if(firstElement[curveType]) {
            rootItemID[curveType] = m_treeCtrl->AppendItem(rootID, rootElementName[curveType]);
            firstElement[curveType] = false;
        }
        wxTreeItemId itemID = m_treeCtrl->AppendItem(rootItemID[curveType], data.GetName());
        for(int i = 0; i < data.GetElementDataNumber(); ++i) {
            m_treeCtrl->AppendItem(itemID, data.GetDataName(i), -1, -1, data.GetPlotData(i));
        }
    }
}

void ChartView::OnPropertyGridChange(wxPropertyGridEvent& event)
{
    bool fit = false;

    if(m_treeCtrl->GetSelection()) {
        if(PlotData* data = dynamic_cast<PlotData*>(m_treeCtrl->GetItemData(m_treeCtrl->GetSelection()))) {
            if(event.GetPropertyName() == _("Draw")) {
                bool isPlotting = m_pgPropDraw->GetValue();
                data->SetPlot(isPlotting);
                if(isPlotting) {
                    wxColour colour = GetNextColour();
                    data->SetColour(colour);
                    m_pgPropColor->SetValue(static_cast<wxVariant>(colour));
                }
                fit = true;
            } else if(event.GetPropertyName() == _("Color")) {
                wxColour colour;
                colour << m_pgPropColor->GetValue();
                data->SetColour(colour);
            } else if(event.GetPropertyName() == _("Thickness")) {
                data->SetThick(m_pgProplineThick->GetValue().GetInteger());
            } else if(event.GetPropertyName() == _("Type")) {
                data->SetPenType(static_cast<wxPenStyle>(m_pgProplineType->GetValue().GetInteger()));
            } else if(event.GetPropertyName() == _("Axis")) {
                int axis = m_pgProplineAxis->GetValue().GetInteger();
                if(axis == 1) {  // Y
                    // All lines to Y axis
                    AllToYAxis(m_treeCtrl->GetRootItem());
                    // curva selecionada para o eixo X
                    m_treeCtrl->SetItemTextColour(m_treeCtrl->GetSelection(), *wxRED);
                    m_xAxisValues = data->GetValues();
                }
                data->SetAxis(axis);
                fit = true;
            }
        }
    }

    if(event.GetPropertyName() == _("Margins")) {
        m_mpWindow->SetMargins(m_pgPropMarginsUp->GetValue().GetLong(), m_pgPropMarginsRight->GetValue().GetLong(),
                               m_pgPropMarginsBot->GetValue().GetLong(), m_pgPropMarginsLeft->GetValue().GetLong());
        m_mpWindow->UpdateAll();
    }
    if(event.GetPropertyName() == _("Axis limit")) {
        m_mpWindow->Fit(m_pgPropXMin->GetValue().GetDouble(), m_pgPropXMax->GetValue().GetDouble(),
                        m_pgPropYMin->GetValue().GetDouble(), m_pgPropYMax->GetValue().GetDouble());
        m_mpWindow->UpdateAll();
    }
    UpdatePlot(fit);
}

void ChartView::OnMenuDarkThemeClick(wxCommandEvent& event)
{
    m_darkTheme = event.IsChecked();
    wxColour grey(96, 96, 96);

    if(m_darkTheme) {
        m_mpWindow->SetColourTheme(*wxBLACK, *wxWHITE, grey);
        m_leg->SetBrush(*wxBLACK_BRUSH);
        m_coords->SetBrush(*wxBLACK_BRUSH);
    } else {
        m_mpWindow->SetColourTheme(*wxWHITE, *wxBLACK, grey);
        m_leg->SetBrush(*wxWHITE_BRUSH);
        m_coords->SetBrush(*wxWHITE_BRUSH);
    }

    m_mpWindow->UpdateAll();
}

void ChartView::OnMenuSaveImageClick(wxCommandEvent& event)
{
    int x = m_mpWindow->GetScreenPosition().x;
    int y = m_mpWindow->GetScreenPosition().y;
    int width = m_mpWindow->GetSize().GetWidth();
    int height = m_mpWindow->GetSize().GetHeight();

    wxScreenDC dcScreen;
    wxBitmap screenshot(width, height);

    wxMemoryDC memDC;
    memDC.SelectObject(screenshot);

    memDC.Blit(0, 0, width, height, &dcScreen, x, y);
    memDC.SelectObject(wxNullBitmap);

    wxFileDialog saveFileDialog(
        this, _("Save image"), "", "",
        "PNG image file (*.png)|*.png|Bitmap image file (*.bmp)|*.bmp|JPEG image file (*.jpg)|*.jpg",
        wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    if(saveFileDialog.ShowModal() == wxID_CANCEL) return;

    wxFileName imagePath(saveFileDialog.GetPath());
    wxBitmapType imageType = wxBITMAP_TYPE_BMP;

    if(imagePath.GetExt() == "png")
        imageType = wxBITMAP_TYPE_PNG;
    else if(imagePath.GetExt() == "jpg")
        imageType = wxBITMAP_TYPE_JPEG;

    screenshot.SaveFile(imagePath.GetFullPath(), imageType);
}

void ChartView::OnMenuSendClipClick(wxCommandEvent& event)
{
    int x = m_mpWindow->GetScreenPosition().x;
    int y = m_mpWindow->GetScreenPosition().y;
    int width = m_mpWindow->GetSize().GetWidth();
    int height = m_mpWindow->GetSize().GetHeight();

    wxScreenDC dcScreen;
    wxBitmap screenshot(width, height);

    wxMemoryDC memDC;
    memDC.SelectObject(screenshot);

    memDC.Blit(0, 0, width, height, &dcScreen, x, y);
    memDC.SelectObject(wxNullBitmap);

    if(wxTheClipboard->Open()) {
        wxTheClipboard->SetData(new wxBitmapDataObject(screenshot));
        wxTheClipboard->Close();

        wxMessageDialog msgDialog(this, _("Chart send to clipboard"), _("Info"), wxOK | wxICON_INFORMATION,
                                  wxDefaultPosition);
        msgDialog.ShowModal();
    } else {
        wxMessageDialog msgDialog(this, _("It was not possible to send to clipboard"), _("Error"), wxOK | wxICON_ERROR,
                                  wxDefaultPosition);
        msgDialog.ShowModal();
    }
}

void ChartView::OnMenuShowCoordinatesClick(wxCommandEvent& event)
{
    m_showCoords = event.IsChecked();
    m_coords->SetVisible(m_showCoords);
    m_mpWindow->UpdateAll();
}

void ChartView::OnMenuShowGridClick(wxCommandEvent& event)
{
    m_hideGrid = event.IsChecked() ? false : true;
    m_xaxis->SetTicks(m_hideGrid);
    m_yaxis->SetTicks(m_hideGrid);
    m_mpWindow->UpdateAll();
}

void ChartView::OnMenuShowLabelClick(wxCommandEvent& event)
{
    m_showLeg = event.IsChecked();
    m_leg->SetVisible(m_showLeg);
    m_mpWindow->UpdateAll();
}

void ChartView::Fit()
{
    m_mpWindow->Fit();
    double bBox[4];
    m_mpWindow->GetBoundingBox(bBox);

    m_pgPropXMin->SetValue(bBox[0]);
    m_pgPropXMax->SetValue(bBox[1]);
    m_pgPropYMin->SetValue(bBox[2]);
    m_pgPropYMax->SetValue(bBox[3]);
}

void ChartView::UpdatePlot(bool fit)
{
    wxRect legRect = m_leg->GetRectangle();
    wxRect coordsRect = m_coords->GetRectangle();
    m_mpWindow->DelAllLayers(true, false);

    // GoAllTrees(treeCtrl_ChartSelection->GetRootItem());
    UpdateAllPlots(m_treeCtrl->GetRootItem());

    m_xaxis = new mpScaleX(m_pgPropXLabel->GetValueAsString(), mpALIGN_BOTTOM, true);
    m_yaxis = new mpScaleY(m_pgPropYLabel->GetValueAsString(), mpALIGN_LEFT, true);
    m_leg = new mpInfoLegend(legRect, wxWHITE_BRUSH);
    m_coords = new mpInfoCoords(coordsRect, wxWHITE_BRUSH);

    m_xaxis->SetDrawOutsideMargins(false);
    m_yaxis->SetDrawOutsideMargins(false);
    m_xaxis->SetTicks(m_hideGrid);
    m_yaxis->SetTicks(m_hideGrid);

    mpText* chartTitle = new mpText(m_pgPropChartTitle->GetValueAsString(), 50, 0);
    wxFont chartTitleFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    chartTitle->SetFont(chartTitleFont);

    m_mpWindow->AddLayer(m_xaxis);
    m_mpWindow->AddLayer(m_yaxis);
    m_mpWindow->AddLayer(m_leg);
    m_mpWindow->AddLayer(m_coords);
    m_mpWindow->AddLayer(chartTitle);

    m_leg->SetVisible(m_showLeg);
    m_coords->SetVisible(m_showCoords);

    if(fit) Fit();

    wxColour grey(96, 96, 96);
    if(m_darkTheme) {
        m_mpWindow->SetColourTheme(*wxBLACK, *wxWHITE, grey);
        m_leg->SetBrush(*wxBLACK_BRUSH);
        m_coords->SetBrush(*wxBLACK_BRUSH);
    } else {
        m_mpWindow->SetColourTheme(*wxWHITE, *wxBLACK, grey);
        m_leg->SetBrush(*wxWHITE_BRUSH);
        m_coords->SetBrush(*wxWHITE_BRUSH);
    }
}

void ChartView::OnTreeItemActivated(wxTreeEvent& event)
{
    if(PlotData* data = dynamic_cast<PlotData*>(m_treeCtrl->GetItemData(event.GetItem()))) {
        bool isPlotting = data->IsPlot() ? false : true;
        data->SetPlot(isPlotting);
        m_pgPropDraw->SetValue(data->IsPlot());
        if(isPlotting) {
            wxColour colour = GetNextColour();
            data->SetColour(colour);
            m_pgPropColor->SetValue(static_cast<wxVariant>(colour));
        }
        UpdatePlot(true);
    }

    if(event.GetItem() == m_treeTimeID) {
        AllToYAxis(m_treeCtrl->GetRootItem());
        m_treeCtrl->SetItemTextColour(m_treeTimeID, *wxRED);
        m_xAxisValues = m_time;
        UpdatePlot(true);
    }

    event.Skip();
}

void ChartView::OnTreeItemSelectionChanged(wxTreeEvent& event)
{
    if(PlotData* data = dynamic_cast<PlotData*>(m_treeCtrl->GetItemData(event.GetItem()))) {
        m_pgPropDraw->SetValue(data->IsPlot());
        wxVariant colour;
        colour << data->GetColour();
        m_pgPropColor->SetValue(colour);
        m_pgProplineThick->SetValue(data->GetThick());
        m_pgProplineType->SetValue(data->GetPenType());
        m_pgProplineAxis->SetValue(data->GetAxis());
    }
    event.Skip();
}

void ChartView::BuildColourList()
{
    m_colourList.push_back(wxColour(255, 0, 0));
    m_colourList.push_back(wxColour(0, 0, 255));
    m_colourList.push_back(wxColour(0, 255, 0));
    m_colourList.push_back(wxColour(255, 128, 0));
    m_colourList.push_back(wxColour(128, 0, 255));
    m_colourList.push_back(wxColour(0, 255, 128));
    m_colourList.push_back(wxColour(255, 255, 0));
    m_colourList.push_back(wxColour(255, 0, 255));
    m_colourList.push_back(wxColour(0, 255, 255));
    m_colourList.push_back(wxColour(128, 255, 0));
    m_colourList.push_back(wxColour(255, 0, 128));
    m_colourList.push_back(wxColour(0, 128, 255));
    m_colourList.push_back(wxColour(128, 128, 128));
    m_colourList.push_back(*wxBLACK);
    m_itColourList = --m_colourList.end();
}

wxColour ChartView::GetNextColour()
{
    if(*m_itColourList == *wxBLACK)
        m_itColourList = m_colourList.begin();
    else
        ++m_itColourList;

    return *m_itColourList;
}

wxTreeItemId ChartView::AllToYAxis(wxTreeItemId root)
{
    wxTreeItemIdValue cookie;
    wxTreeItemId item = m_treeCtrl->GetFirstChild(root, cookie);
    wxTreeItemId child;

    while(item.IsOk()) {
        m_treeCtrl->SetItemTextColour(item, *wxBLACK);
        if(PlotData* data = dynamic_cast<PlotData*>(m_treeCtrl->GetItemData(item))) data->SetAxis(0);  // X axis.

        if(m_treeCtrl->ItemHasChildren(item)) {
            wxTreeItemId nextChild = AllToYAxis(item);
            if(nextChild.IsOk()) return nextChild;
        }
        item = m_treeCtrl->GetNextChild(root, cookie);
    }

    wxTreeItemId dummyID;
    return dummyID;
}

wxTreeItemId ChartView::UpdateAllPlots(wxTreeItemId root)
{
    wxTreeItemIdValue cookie;
    wxTreeItemId item = m_treeCtrl->GetFirstChild(root, cookie);
    wxTreeItemId child;

    while(item.IsOk()) {
        if(PlotData* data = dynamic_cast<PlotData*>(m_treeCtrl->GetItemData(item))) {
            if(data->IsPlot()) {
                wxString parentName = m_treeCtrl->GetItemText(m_treeCtrl->GetItemParent(item));
                mpFXYVector* newLayer = new mpFXYVector(data->GetName() + " (" + parentName + ")");
                newLayer->SetData(m_xAxisValues, data->GetValues());
                newLayer->SetContinuity(true);
                wxPen layerPen(data->GetColour(), data->GetThick(), data->GetPenType());
                newLayer->SetPen(layerPen);
                newLayer->SetDrawOutsideMargins(false);
                newLayer->ShowName(false);

                m_mpWindow->AddLayer(newLayer);
            }
        }

        if(m_treeCtrl->ItemHasChildren(item)) {
            wxTreeItemId nextChild = UpdateAllPlots(item);
            if(nextChild.IsOk()) return nextChild;
        }
        item = m_treeCtrl->GetNextChild(root, cookie);
    }

    wxTreeItemId dummyID;
    return dummyID;
}
