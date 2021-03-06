#ifndef SWITCHINGFORM_H
#define SWITCHINGFORM_H

#include "ElementForm.h"

class PowerElement;

class SwitchingForm : public SwitchingFormBase
{
public:
    SwitchingForm(wxWindow* parent);
    SwitchingForm(wxWindow* parent, PowerElement* element);
    virtual ~SwitchingForm();
protected:
    virtual void OnDownButtonClick(wxCommandEvent& event);
    virtual void OnUpButtonClick(wxCommandEvent& event);
    virtual void OnChangeProperties(wxPropertyGridEvent& event);
    virtual void OnSelectItem(wxListEvent& event);
    virtual void OnCancelButtonClick(wxCommandEvent& event);
    virtual void OnInsertButtonClick(wxCommandEvent& event);
    virtual void OnOKButtonClick(wxCommandEvent& event);
    virtual void OnRemoveButtonClick(wxCommandEvent& event);
    
    int m_maxID = 0;
    
    PowerElement* m_element = NULL;
};
#endif // SWITCHINGFORM_H
