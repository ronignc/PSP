#ifndef SYNCGENERATOR_H
#define SYNCGENERATOR_H

#include "Machines.h"

class SyncMachineForm;

struct SyncGeneratorElectricalData {
    // General
    wxString name = "";
    double nominalPower = 100.0;
    ElectricalUnit nominalPowerUnit = UNIT_MVA;
    double nominalVoltage = 13.8;
    ElectricalUnit nominalVoltageUnit = UNIT_kV;
    double activePower = 100.0;
    ElectricalUnit activePowerUnit = UNIT_MW;
    double reactivePower = 0.0;
    ElectricalUnit reactivePowerUnit = UNIT_MVAr;
    bool haveMaxReactive = false;
    double maxReactive = 9999.0;
    ElectricalUnit maxReactiveUnit = UNIT_MVAr;
    bool haveMinReactive = false;
    double minReactive = -9999.0;
    ElectricalUnit minReactiveUnit = UNIT_MVAr;
    bool useMachineBase = false;

    // Fault
    double positiveResistance = 0.0;
    double positiveReactance = 1.0;
    double negativeResistance = 0.0;
    double negativeReactance = 1.0;
    double zeroResistance = 0.0;
    double zeroReactance = 1.0;
    double groundResistance = 0.0;
    double groundReactance = 0.0;
    bool groundNeutral = true;
    // p.u. fault data
    std::complex<double> faultCurrent[3] = { std::complex<double>(0.0, 0.0), std::complex<double>(0.0, 0.0),
        std::complex<double>(0.0, 0.0) };

    // Stability
    bool plotSyncMachine = false;
    double inertia = 0.0;
    double damping = 0.0;
    bool useAVR = false;
    bool useSpeedGovernor = false;

    double armResistance = 0.0;
    double potierReactance = 0.0;
    double satFactor = 0.0;

    double syncXd = 0.0;
    double syncXq = 0.0;
    double transXd = 1.0;
    double transXq = 0.0;
    double transTd0 = 0.0;
    double transTq0 = 0.0;
    double subXd = 0.0;
    double subXq = 0.0;
    double subTd0 = 0.0;
    double subTq0 = 0.0;
};

class SyncGenerator : public Machines
{
public:
    SyncGenerator();
    SyncGenerator(wxString name);
    ~SyncGenerator();
	
	virtual Element* GetCopy();
    virtual void Init();
    virtual void DrawSymbol() const;
    virtual bool GetContextMenu(wxMenu& menu);
    virtual bool ShowForm(wxWindow* parent, Element* element);
    virtual wxString GetTipText() const;
    virtual SyncGeneratorElectricalData GetElectricalData() { return m_electricalData; }
    virtual SyncGeneratorElectricalData GetPUElectricalData(double systemPowerBase);
    virtual void SetElectricalData(SyncGeneratorElectricalData electricalData) { m_electricalData = electricalData; }
    virtual void SetNominalVoltage(std::vector<double> nominalVoltage, std::vector<ElectricalUnit> nominalVoltageUnit);
protected:
    std::vector<wxPoint2DDouble> m_sinePts;

    SyncGeneratorElectricalData m_electricalData;
};

#endif // SYNCGENERATOR_H
