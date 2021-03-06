#ifndef MACHINES_H
#define MACHINES_H

#include "PowerElement.h"

class Machines : public PowerElement
{
public:
	Machines();
	~Machines();
	
    virtual bool AddParent(Element* parent, wxPoint2DDouble position);
    virtual bool Contains(wxPoint2DDouble position) const { return m_rect.Contains(position); }
    virtual void Draw(wxPoint2DDouble translation, double scale) const;
    virtual bool Intersects(wxRect2DDouble rect) const { return m_rect.Intersects(rect); }
    virtual void Move(wxPoint2DDouble position);
    virtual void MoveNode(Element* element, wxPoint2DDouble position);
    virtual void StartMove(wxPoint2DDouble position);
    virtual void RotateNode(Element* parent, bool clockwise = true);
    virtual void RemoveParent(Element* parent);
    virtual bool NodeContains(wxPoint2DDouble position);
    virtual bool SetNodeParent(Element* parent);
    virtual void UpdateNodes();
    virtual void Rotate(bool clockwise = true);
	virtual void DrawSymbol() const {}
    virtual void SetPowerFlowDirection(PowerFlowDirection pfDirection);

   protected:
    void UpdateSwitchesPosition();
    void UpdatePowerFlowArrowsPosition();
    bool m_inserted = false;

};

#endif // MACHINES_H
