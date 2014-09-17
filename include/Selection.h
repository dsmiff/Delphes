#ifndef SELECTION_h
#define SELECTION_h

#include <iostream>

Float_t xsec = 1.578;
Float_t IntLumiData = 19494;
Float_t pi = 3.14159265;

class Selection{

 public:
  
  // Cut declarations 

  // Parton Level Cuts

  static bool PLCuts(float mcq1pt, float mcq2pt, float mcvbfm)
  {
    return (mcq1pt > 30 && mcq2pt > 30 && mcvbfm > 600);
  }

  // Represents Trigger implementation of AN
  static bool TriggerCuts(float jetpt1_trig, float jetpt2_trig, float eta_trig, float dEtajj_trig, float mjj_trig, float met_trig)
  {
    return (jetpt1_trig > 40 && jetpt2_trig > 40 && eta_trig < 0 && dEtajj_trig > 3.5 && mjj_trig > 800 && met_trig > 65);
  }

  // Offline cuts, dijet pt
  static bool JetCut(float jet1pt, float jet1eta, float jet2pt, float jet2eta)
  {
    return (jet1pt > 50.0 && abs(jet1eta) < 4.7 && jet2pt > 50.0 && abs(jet2eta) < 4.7);
  }
  
  // Eta cut
  static bool EtaCut(float eta){ return (eta) < 4.7; }

  // Phi cut
  static bool PhiCut(float phi){ return phi < 1; }

  // MET cut
  static bool METcut(float met){ return met > 130; }

  // Dijet invariant mass cut
  static bool MassCut(float m_jj){ return m_jj > 1100; }

  // Delta Eta cut
  static bool DEtaCut(float dEtajj){ return dEtajj > 4.2; }

  // Eta scalar product cut
  static bool DPEta(float etaDP){ return etaDP < 0; }

  // Central Jet Veto cut
  static bool CJVCut(float eta1, float eta2, float eta3, float pt3){ return ((eta1 < eta3 && eta3 < eta2 && pt3 > 30) || (eta2 < eta3 && eta3 < eta1 && pt3 > 30)); }

  // Central Jet Eta
  static bool CJEta(float eta_jet_1, float eta_jet_2, float eta_jet_3)
  {    
    return( (eta_jet_1 < eta_jet_3 && eta_jet_3 < eta_jet_2) || (eta_jet_2 < eta_jet_3 && eta_jet_3 < eta_jet_1 ) );  
      }
  
  // Central Jet Pt
  static bool CJPt(float pt_jet_3){ return pt_jet_3 > 30; }



  // Cut quantities 

  static float Weight(Int_t Evts) { return (IntLumiData)/(Evts/xsec); }

  static float NJets() { return 2; } 
  
  static float JetPTCut() { return 50; }
  
  static float JetEtaCut() { return 4.7; } 
  
  static float JetEtaDPCut() { return 0; } 
  
  static float InvJetMassCut() { return 1100; }
  
  static float DeltaPhiJJCut() { return 1; } 
  
  static float DeltaEtaJJCut() { return 4.2; } 
  
  static float METCut() { return 150; }
  

};

#endif
