//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jan 18 10:47:52 2019 by ROOT version 5.34/38
// from TChain dijets/events/
//////////////////////////////////////////////////////////

#ifndef rootNtupleClass_h
#define rootNtupleClass_h

//// Lines added by make_rootNtupleClass.sh - BEGIN 
#include <vector> 
using namespace std; 
//// Lines added by make_rootNtupleClass.sh - END 

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>
#include <vector>
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxrun = 1;
   const Int_t kMaxevt = 1;
   const Int_t kMaxlumi = 1;
   const Int_t kMaxnVtx = 1;
   const Int_t kMaxBXnumber = 1;
   const Int_t kMaxrho = 1;
   const Int_t kMaxmetEnergy = 1;
   const Int_t kMaxmetPt = 1;
   const Int_t kMaxmetEta = 1;
   const Int_t kMaxmetPhi = 1;
   const Int_t kMaxmetEnergypuppi = 1;
   const Int_t kMaxmetPtpuppi = 1;
   const Int_t kMaxmetEtapuppi = 1;
   const Int_t kMaxmetPhipuppi = 1;
   const Int_t kMaxmetSig = 1;
   const Int_t kMaxmetcorrected = 1;
   const Int_t kMaxgoodPVtx = 1;
   const Int_t kMaxdeltaNHfootprintX = 1;
   const Int_t kMaxdeltaNHfootprintY = 1;
   const Int_t kMaxmetEnergyGen = 1;
   const Int_t kMaxmetPtGen = 1;
   const Int_t kMaxmetEtaGen = 1;
   const Int_t kMaxmetPhiGen = 1;
   const Int_t kMaxmetEnergypuppiGen = 1;
   const Int_t kMaxmetPtpuppiGen = 1;
   const Int_t kMaxmetEtapuppiGen = 1;
   const Int_t kMaxmetPhipuppiGen = 1;
   const Int_t kMaxnJetsAK4 = 1;
   const Int_t kMaxnJetsPUPPI = 1;
   const Int_t kMaxhtAK4 = 1;
   const Int_t kMaxnJetsAK8 = 1;
   const Int_t kMaxhtAK8 = 1;
   const Int_t kMaxnPhotons = 1;
   const Int_t kMaxnPhotonsLoose = 1;
   const Int_t kMaxnPhotonsMedium = 1;
   const Int_t kMaxnPhotonsTight = 1;
   const Int_t kMaxnMuonsLoose = 1;
   const Int_t kMaxptHat = 1;
   const Int_t kMaxprocessID = 1;
   const Int_t kMaxweight = 1;
   const Int_t kMaxnGenJetsAK4 = 1;
   const Int_t kMaxnGenJetsAK8 = 1;
   const Int_t kMaxnGenPhotons = 1;

class rootNtupleClass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           runNo;
   Int_t           evtNo;
   Int_t           lumi;
   Int_t           nvtx;
   Int_t           BXnumber;
   Float_t         rho;
   Float_t         metEnergy;
   Float_t         metPt;
   Float_t         metEta;
   Float_t         metPhi;
   Float_t         metEnergyPUPPI;
   Float_t         metPtPUPPI;
   Float_t         metEtaPUPPI;
   Float_t         metPhiPUPPI;
   Float_t         metSig;
   Float_t         metTypeI;
   Char_t          goodPVtx;
   Float_t         deltaNHfootprintX;
   Float_t         deltaNHfootprintY;
   Float_t         metEnergyGen;
   Float_t         metPtGen;
   Float_t         metEtaGen;
   Float_t         metPhiGen;
   Float_t         metEnergyPUPPIGen;
   Float_t         metPtPUPPIGen;
   Float_t         metEtaPUPPIGen;
   Float_t         metPhiPUPPIGen;
   vector<float>   *gen_eta;
   vector<float>   *gen_phi;
   vector<float>   *gen_p;
   vector<float>   *gen_px;
   vector<float>   *gen_py;
   vector<float>   *gen_pz;
   vector<float>   *gen_pt;
   vector<float>   *gen_energy;
   vector<int>     *gen_pdgId;
   vector<float>   *gen_vx;
   vector<float>   *gen_vy;
   vector<float>   *gen_vz;
   vector<int>     *gen_numDaught;
   vector<int>     *gen_status;
   vector<int>     *gen_index;
   vector<int>     *gen_motherIndex;
   Int_t           nJetsAK4;
   Int_t           nJetsPUPPI;
   Float_t         htAK4;
   Int_t           nJetsAK8;
   Float_t         htAK8;
   Int_t           nPhoton;
   Int_t           nPhotonLoose;
   Int_t           nPhotonMedium;
   Int_t           nPhotonTight;
   vector<bool>    *isMatch30;
   vector<bool>    *isMatch50;
   vector<bool>    *isMatch75;
   vector<bool>    *isMatch90;
   vector<bool>    *isMatch120;
   vector<bool>    *isMatch165;
   vector<bool>    *isGenMatch;
   vector<bool>    *isPhotonMedium_EG_MVA;
   vector<float>   *PhotonLoosePt;
   vector<float>   *PhotonsmearPt;
   vector<float>   *PhotonSCPt;
   vector<float>   *PhotonLooseEta;
   vector<float>   *PhotonsmearEta;
   vector<float>   *PhotonSCEta;
   vector<float>   *PhotonLoosePhi;
   vector<float>   *PhotonsmearPhi;
   vector<float>   *PhotonSCPhi;
   vector<float>   *PhotonLooseEnergy;
   vector<float>   *PhotonsmearEnergy;
   vector<float>   *PhotonSCEnergy;
   vector<double>  *PhotonEcorrBump;
   vector<float>   *Photonfull5x5SigmaIEtaIEtaMapToken;
   vector<float>   *PhotonphoChargedIsolationToken;
   vector<float>   *PhotonphoNeutralHadronIsolationToken;
   vector<float>   *PhotonphoPhotonIsolationToken;
   vector<bool>    *HaspixelSeed;
   vector<bool>    *ElectronVeto;
   vector<float>   *hadTowOverEm;
   vector<bool>    *isPhotonLoose;
   vector<bool>    *isPhotonMedium;
   vector<bool>    *isPhotonTight;
   vector<bool>    *isfakephoton;
   vector<float>   *Photonfull5x5SigmaIEtaIPhiMapToken;
   vector<float>   *Photonfull5x5E5x5MapToken;
   vector<float>   *Photonfull5x5E2x2MapToken;
   vector<float>   *PhotonESEffSigmaRRMapToken;
   vector<float>   *PhotonR9;
   vector<float>   *Photon_etawidth;
   vector<float>   *Photon_phiwidth;
   vector<float>   *Photon_ES_energy;
   vector<float>   *Photonfull5x5E2x5;
   vector<float>   *Photonfull5x5E1x3;
   vector<float>   *PhotonWorstChargedIsolation;
   vector<float>   *Photon_scaleUNC_gainup;
   vector<float>   *Photon_scaleUNC_gaindown;
   vector<float>   *Photon_scaleUNC_systup;
   vector<float>   *Photon_scaleUNC_systdown;
   vector<float>   *Photon_scaleUNC_statup;
   vector<float>   *Photon_scaleUNC_statdown;
   vector<float>   *Photon_scaleUNC_ETup;
   vector<float>   *Photon_scaleUNC_ETdown;
   vector<float>   *Photon_smearUNC_phiup;
   vector<float>   *Photon_smearUNC_rhodown;
   vector<float>   *Photon_smearUNC_rhoup;
   vector<float>   *photon_scale_central;
   vector<float>   *photon_smear_central;
   vector<float>   *electronPt;
   vector<float>   *electronEta;
   vector<float>   *electronPhi;
   vector<float>   *electronEnergy;
   vector<float>   *electronID;
   vector<float>   *electronISO;
   vector<float>   *electronPtsmeared;
   vector<float>   *electronEtasmeared;
   vector<float>   *electronPhismeared;
   vector<float>   *electronEnergysmeared;
   vector<float>   *electronIDsmeared;
   vector<float>   *electronISOsmeared;
   vector<float>   *muonPt;
   vector<float>   *muonEta;
   vector<float>   *muonPhi;
   vector<float>   *muonEnergy;
   Int_t           nMuonsLoose;
   vector<float>   *jetPtAK4;
   vector<float>   *jetJecAK4;
   vector<float>   *jetEtaAK4;
   vector<float>   *jetPhiAK4;
   vector<float>   *jetMassAK4;
   vector<float>   *jetEnergyAK4;
   vector<float>   *jetPtAK4RC;
   vector<float>   *jetEtaAK4RC;
   vector<float>   *jetPhiAK4RC;
   vector<float>   *jetMassAK4RC;
   vector<float>   *jetEnergyAK4RC;
   vector<float>   *jetAreaAK4;
   vector<float>   *jetCSVAK4;
   vector<float>   *jetQGDAK4;
   vector<float>   *jetChfAK4;
   vector<float>   *jetNhfAK4;
   vector<float>   *jetPhfAK4;
   vector<float>   *jetMufAK4;
   vector<float>   *jetElfAK4;
   vector<float>   *jetNemfAK4;
   vector<float>   *jetCemfAK4;
   vector<float>   *jetHf_hfAK4;
   vector<float>   *jetHf_emfAK4;
   vector<float>   *jetHofAK4;
   vector<int>     *idLAK4;
   vector<int>     *idTAK4;
   vector<int>     *chHadMultAK4;
   vector<int>     *chMultAK4;
   vector<int>     *neHadMultAK4;
   vector<int>     *neMultAK4;
   vector<int>     *phoMultAK4;
   vector<int>     *hadronflavour;
   vector<float>   *deepcsv_probb_AK4;
   vector<float>   *deepcsv_probbb_AK4;
   vector<float>   *deepcsv_probc_AK4;
   vector<float>   *deepcsv_probcc_AK4;
   vector<float>   *CvsB_taggerAK4;
   vector<float>   *CvsL_taggerAK4;
   vector<bool>    *triggerResult;
   vector<int>     *triggerPrescale;
   vector<string>  *triggerName;
   vector<float>   *npu;
   vector<int>     *PileupInteractions;
   vector<int>     *PileupOriginBX;
   Float_t         ptHat;
   Int_t           processID;
   Float_t         weight;
   Int_t           nGenJetsAK4;
   Int_t           nGenJetsAK8;
   Int_t           nGenPhoton;
   vector<float>   *photonPtGen;
   vector<float>   *photonEtaGen;
   vector<float>   *photonPhiGen;
   vector<float>   *photonEnergyGen;
   vector<float>   *jetPtGenAK4;
   vector<float>   *jetEtaGenAK4;
   vector<float>   *jetPhiGenAK4;
   vector<float>   *jetMassGenAK4;
   vector<float>   *jetEnergyGenAK4;
   vector<int>     *jetpdgIDGenAK4;

   // List of branches
   TBranch        *b_run_;   //!
   TBranch        *b_evt_;   //!
   TBranch        *b_lumi_;   //!
   TBranch        *b_nVtx_;   //!
   TBranch        *b_BXnumber_;   //!
   TBranch        *b_rho_;   //!
   TBranch        *b_metEnergy_;   //!
   TBranch        *b_metPt_;   //!
   TBranch        *b_metEta_;   //!
   TBranch        *b_metPhi_;   //!
   TBranch        *b_metEnergypuppi_;   //!
   TBranch        *b_metPtpuppi_;   //!
   TBranch        *b_metEtapuppi_;   //!
   TBranch        *b_metPhipuppi_;   //!
   TBranch        *b_metSig_;   //!
   TBranch        *b_metcorrected_;   //!
   TBranch        *b_goodPVtx_;   //!
   TBranch        *b_deltaNHfootprintX_;   //!
   TBranch        *b_deltaNHfootprintY_;   //!
   TBranch        *b_metEnergyGen_;   //!
   TBranch        *b_metPtGen_;   //!
   TBranch        *b_metEtaGen_;   //!
   TBranch        *b_metPhiGen_;   //!
   TBranch        *b_metEnergypuppiGen_;   //!
   TBranch        *b_metPtpuppiGen_;   //!
   TBranch        *b_metEtapuppiGen_;   //!
   TBranch        *b_metPhipuppiGen_;   //!
   TBranch        *b_gen_eta;   //!
   TBranch        *b_gen_phi;   //!
   TBranch        *b_gen_p;   //!
   TBranch        *b_gen_px;   //!
   TBranch        *b_gen_py;   //!
   TBranch        *b_gen_pz;   //!
   TBranch        *b_gen_pt;   //!
   TBranch        *b_gen_energy;   //!
   TBranch        *b_gen_pdgId;   //!
   TBranch        *b_gen_vx;   //!
   TBranch        *b_gen_vy;   //!
   TBranch        *b_gen_vz;   //!
   TBranch        *b_gen_numDaught;   //!
   TBranch        *b_gen_status;   //!
   TBranch        *b_gen_index;   //!
   TBranch        *b_gen_motherIndex;   //!
   TBranch        *b_nJetsAK4_;   //!
   TBranch        *b_nJetsPUPPI_;   //!
   TBranch        *b_htAK4_;   //!
   TBranch        *b_nJetsAK8_;   //!
   TBranch        *b_htAK8_;   //!
   TBranch        *b_nPhotons_;   //!
   TBranch        *b_nPhotonsLoose_;   //!
   TBranch        *b_nPhotonsMedium_;   //!
   TBranch        *b_nPhotonsTight_;   //!
   TBranch        *b_isMatch30;   //!
   TBranch        *b_isMatch50;   //!
   TBranch        *b_isMatch75;   //!
   TBranch        *b_isMatch90;   //!
   TBranch        *b_isMatch120;   //!
   TBranch        *b_isMatch165;   //!
   TBranch        *b_isGenMatch;   //!
   TBranch        *b_isPhotonMedium_EG_MVA;   //!
   TBranch        *b_PhotonLoosePt;   //!
   TBranch        *b_PhotonsmearPt;   //!
   TBranch        *b_PhotonSCPt;   //!
   TBranch        *b_PhotonLooseEta;   //!
   TBranch        *b_PhotonsmearEta;   //!
   TBranch        *b_PhotonSCEta;   //!
   TBranch        *b_PhotonLoosePhi;   //!
   TBranch        *b_PhotonsmearPhi;   //!
   TBranch        *b_PhotonSCPhi;   //!
   TBranch        *b_PhotonLooseEnergy;   //!
   TBranch        *b_PhotonsmearEnergy;   //!
   TBranch        *b_PhotonSCEnergy;   //!
   TBranch        *b_PhotonEcorrBump;   //!
   TBranch        *b_Photonfull5x5SigmaIEtaIEtaMapToken;   //!
   TBranch        *b_PhotonphoChargedIsolationToken;   //!
   TBranch        *b_PhotonphoNeutralHadronIsolationToken;   //!
   TBranch        *b_PhotonphoPhotonIsolationToken;   //!
   TBranch        *b_HaspixelSeed;   //!
   TBranch        *b_ElectronVeto;   //!
   TBranch        *b_hadTowOverEm;   //!
   TBranch        *b_isPhotonLoose;   //!
   TBranch        *b_isPhotonMedium;   //!
   TBranch        *b_isPhotonTight;   //!
   TBranch        *b_isfakephoton;   //!
   TBranch        *b_Photonfull5x5SigmaIEtaIPhiMapToken;   //!
   TBranch        *b_Photonfull5x5E5x5MapToken;   //!
   TBranch        *b_Photonfull5x5E2x2MapToken;   //!
   TBranch        *b_PhotonESEffSigmaRRMapToken;   //!
   TBranch        *b_PhotonR9;   //!
   TBranch        *b_Photon_etawidth;   //!
   TBranch        *b_Photon_phiwidth;   //!
   TBranch        *b_Photon_ES_energy;   //!
   TBranch        *b_Photonfull5x5E2x5;   //!
   TBranch        *b_Photonfull5x5E1x3;   //!
   TBranch        *b_PhotonWorstChargedIsolation;   //!
   TBranch        *b_Photon_scaleUNC_gainup;   //!
   TBranch        *b_Photon_scaleUNC_gaindown;   //!
   TBranch        *b_Photon_scaleUNC_systup;   //!
   TBranch        *b_Photon_scaleUNC_systdown;   //!
   TBranch        *b_Photon_scaleUNC_statup;   //!
   TBranch        *b_Photon_scaleUNC_statdown;   //!
   TBranch        *b_Photon_scaleUNC_ETup;   //!
   TBranch        *b_Photon_scaleUNC_ETdown;   //!
   TBranch        *b_Photon_smearUNC_phiup;   //!
   TBranch        *b_Photon_smearUNC_rhodown;   //!
   TBranch        *b_Photon_smearUNC_rhoup;   //!
   TBranch        *b_photon_scale_central;   //!
   TBranch        *b_photon_smear_central;   //!
   TBranch        *b_electronPt;   //!
   TBranch        *b_electronEta;   //!
   TBranch        *b_electronPhi;   //!
   TBranch        *b_electronEnergy;   //!
   TBranch        *b_electronID;   //!
   TBranch        *b_electronISO;   //!
   TBranch        *b_electronPtsmeared;   //!
   TBranch        *b_electronEtasmeared;   //!
   TBranch        *b_electronPhismeared;   //!
   TBranch        *b_electronEnergysmeared;   //!
   TBranch        *b_electronIDsmeared;   //!
   TBranch        *b_electronISOsmeared;   //!
   TBranch        *b_muonPt;   //!
   TBranch        *b_muonEta;   //!
   TBranch        *b_muonPhi;   //!
   TBranch        *b_muonEnergy;   //!
   TBranch        *b_nMuonsLoose_;   //!
   TBranch        *b_jetPtAK4;   //!
   TBranch        *b_jetJecAK4;   //!
   TBranch        *b_jetEtaAK4;   //!
   TBranch        *b_jetPhiAK4;   //!
   TBranch        *b_jetMassAK4;   //!
   TBranch        *b_jetEnergyAK4;   //!
   TBranch        *b_jetPtAK4RC;   //!
   TBranch        *b_jetEtaAK4RC;   //!
   TBranch        *b_jetPhiAK4RC;   //!
   TBranch        *b_jetMassAK4RC;   //!
   TBranch        *b_jetEnergyAK4RC;   //!
   TBranch        *b_jetAreaAK4;   //!
   TBranch        *b_jetCSVAK4;   //!
   TBranch        *b_jetQGDAK4;   //!
   TBranch        *b_jetChfAK4;   //!
   TBranch        *b_jetNhfAK4;   //!
   TBranch        *b_jetPhfAK4;   //!
   TBranch        *b_jetMufAK4;   //!
   TBranch        *b_jetElfAK4;   //!
   TBranch        *b_jetNemfAK4;   //!
   TBranch        *b_jetCemfAK4;   //!
   TBranch        *b_jetHf_hfAK4;   //!
   TBranch        *b_jetHf_emfAK4;   //!
   TBranch        *b_jetHofAK4;   //!
   TBranch        *b_idLAK4;   //!
   TBranch        *b_idTAK4;   //!
   TBranch        *b_chHadMultAK4;   //!
   TBranch        *b_chMultAK4;   //!
   TBranch        *b_neHadMultAK4;   //!
   TBranch        *b_neMultAK4;   //!
   TBranch        *b_phoMultAK4;   //!
   TBranch        *b_hadronflavour;   //!
   TBranch        *b_deepcsv_probb_AK4;   //!
   TBranch        *b_deepcsv_probbb_AK4;   //!
   TBranch        *b_deepcsv_probc_AK4;   //!
   TBranch        *b_deepcsv_probcc_AK4;   //!
   TBranch        *b_CvsB_taggerAK4;   //!
   TBranch        *b_CvsL_taggerAK4;   //!
   TBranch        *b_triggerResult;   //!
   TBranch        *b_triggerPrescale;   //!
   TBranch        *b_triggerName;   //!
   TBranch        *b_npu;   //!
   TBranch        *b_PileupInteractions;   //!
   TBranch        *b_PileupOriginBX;   //!
   TBranch        *b_ptHat_;   //!
   TBranch        *b_processID_;   //!
   TBranch        *b_weight_;   //!
   TBranch        *b_nGenJetsAK4_;   //!
   TBranch        *b_nGenJetsAK8_;   //!
   TBranch        *b_nGenPhotons_;   //!
   TBranch        *b_photonPtGen;   //!
   TBranch        *b_photonEtaGen;   //!
   TBranch        *b_photonPhiGen;   //!
   TBranch        *b_photonEnergyGen;   //!
   TBranch        *b_jetPtGenAK4;   //!
   TBranch        *b_jetEtaGenAK4;   //!
   TBranch        *b_jetPhiGenAK4;   //!
   TBranch        *b_jetMassGenAK4;   //!
   TBranch        *b_jetEnergyGenAK4;   //!
   TBranch        *b_jetpdgIDGenAK4;   //!

   rootNtupleClass(TTree *tree=0);
   virtual ~rootNtupleClass();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef rootNtupleClass_cxx
rootNtupleClass::rootNtupleClass(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {

#ifdef SINGLE_TREE
      // The following code should be used if you want this class to access
      // a single tree instead of a chain
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Memory Directory");
      if (!f || !f->IsOpen()) {
         f = new TFile("Memory Directory");
      }
      f->GetObject("dijets/events",tree);

#else // SINGLE_TREE

      // The following code should be used if you want this class to access a chain
      // of trees.
      TChain * chain = new TChain("dijets/events","");
      chain->Add("/eos/cms/store/group/phys_smp/hlattaud/Gjets_HF/GJet_Pt-15To6000_signalsample_NewEGSF_V1_G_B/GJet_Pt-15To6000_TuneCUETP8M1-Flat_13TeV_pythia8_20M/crab_GJet_Pt-15To6000_signalsample_NewEGSF_V1_G_B/190104_151405/0000/mylocaltest_Run2016B_10_21.root/dijets/events");
      tree = chain;
#endif // SINGLE_TREE

   }
   Init(tree);
}

rootNtupleClass::~rootNtupleClass()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t rootNtupleClass::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t rootNtupleClass::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void rootNtupleClass::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   gen_eta = 0;
   gen_phi = 0;
   gen_p = 0;
   gen_px = 0;
   gen_py = 0;
   gen_pz = 0;
   gen_pt = 0;
   gen_energy = 0;
   gen_pdgId = 0;
   gen_vx = 0;
   gen_vy = 0;
   gen_vz = 0;
   gen_numDaught = 0;
   gen_status = 0;
   gen_index = 0;
   gen_motherIndex = 0;
   isMatch30 = 0;
   isMatch50 = 0;
   isMatch75 = 0;
   isMatch90 = 0;
   isMatch120 = 0;
   isMatch165 = 0;
   isGenMatch = 0;
   isPhotonMedium_EG_MVA = 0;
   PhotonLoosePt = 0;
   PhotonsmearPt = 0;
   PhotonSCPt = 0;
   PhotonLooseEta = 0;
   PhotonsmearEta = 0;
   PhotonSCEta = 0;
   PhotonLoosePhi = 0;
   PhotonsmearPhi = 0;
   PhotonSCPhi = 0;
   PhotonLooseEnergy = 0;
   PhotonsmearEnergy = 0;
   PhotonSCEnergy = 0;
   PhotonEcorrBump = 0;
   Photonfull5x5SigmaIEtaIEtaMapToken = 0;
   PhotonphoChargedIsolationToken = 0;
   PhotonphoNeutralHadronIsolationToken = 0;
   PhotonphoPhotonIsolationToken = 0;
   HaspixelSeed = 0;
   ElectronVeto = 0;
   hadTowOverEm = 0;
   isPhotonLoose = 0;
   isPhotonMedium = 0;
   isPhotonTight = 0;
   isfakephoton = 0;
   Photonfull5x5SigmaIEtaIPhiMapToken = 0;
   Photonfull5x5E5x5MapToken = 0;
   Photonfull5x5E2x2MapToken = 0;
   PhotonESEffSigmaRRMapToken = 0;
   PhotonR9 = 0;
   Photon_etawidth = 0;
   Photon_phiwidth = 0;
   Photon_ES_energy = 0;
   Photonfull5x5E2x5 = 0;
   Photonfull5x5E1x3 = 0;
   PhotonWorstChargedIsolation = 0;
   Photon_scaleUNC_gainup = 0;
   Photon_scaleUNC_gaindown = 0;
   Photon_scaleUNC_systup = 0;
   Photon_scaleUNC_systdown = 0;
   Photon_scaleUNC_statup = 0;
   Photon_scaleUNC_statdown = 0;
   Photon_scaleUNC_ETup = 0;
   Photon_scaleUNC_ETdown = 0;
   Photon_smearUNC_phiup = 0;
   Photon_smearUNC_rhodown = 0;
   Photon_smearUNC_rhoup = 0;
   photon_scale_central = 0;
   photon_smear_central = 0;
   electronPt = 0;
   electronEta = 0;
   electronPhi = 0;
   electronEnergy = 0;
   electronID = 0;
   electronISO = 0;
   electronPtsmeared = 0;
   electronEtasmeared = 0;
   electronPhismeared = 0;
   electronEnergysmeared = 0;
   electronIDsmeared = 0;
   electronISOsmeared = 0;
   muonPt = 0;
   muonEta = 0;
   muonPhi = 0;
   muonEnergy = 0;
   jetPtAK4 = 0;
   jetJecAK4 = 0;
   jetEtaAK4 = 0;
   jetPhiAK4 = 0;
   jetMassAK4 = 0;
   jetEnergyAK4 = 0;
   jetPtAK4RC = 0;
   jetEtaAK4RC = 0;
   jetPhiAK4RC = 0;
   jetMassAK4RC = 0;
   jetEnergyAK4RC = 0;
   jetAreaAK4 = 0;
   jetCSVAK4 = 0;
   jetQGDAK4 = 0;
   jetChfAK4 = 0;
   jetNhfAK4 = 0;
   jetPhfAK4 = 0;
   jetMufAK4 = 0;
   jetElfAK4 = 0;
   jetNemfAK4 = 0;
   jetCemfAK4 = 0;
   jetHf_hfAK4 = 0;
   jetHf_emfAK4 = 0;
   jetHofAK4 = 0;
   idLAK4 = 0;
   idTAK4 = 0;
   chHadMultAK4 = 0;
   chMultAK4 = 0;
   neHadMultAK4 = 0;
   neMultAK4 = 0;
   phoMultAK4 = 0;
   hadronflavour = 0;
   deepcsv_probb_AK4 = 0;
   deepcsv_probbb_AK4 = 0;
   deepcsv_probc_AK4 = 0;
   deepcsv_probcc_AK4 = 0;
   CvsB_taggerAK4 = 0;
   CvsL_taggerAK4 = 0;
   triggerResult = 0;
   triggerPrescale = 0;
   triggerName = 0;
   npu = 0;
   PileupInteractions = 0;
   PileupOriginBX = 0;
   photonPtGen = 0;
   photonEtaGen = 0;
   photonPhiGen = 0;
   photonEnergyGen = 0;
   jetPtGenAK4 = 0;
   jetEtaGenAK4 = 0;
   jetPhiGenAK4 = 0;
   jetMassGenAK4 = 0;
   jetEnergyGenAK4 = 0;
   jetpdgIDGenAK4 = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("runNo", &runNo, &b_run_);
   fChain->SetBranchAddress("evtNo", &evtNo, &b_evt_);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi_);
   fChain->SetBranchAddress("nvtx", &nvtx, &b_nVtx_);
   fChain->SetBranchAddress("BXnumber", &BXnumber, &b_BXnumber_);
   fChain->SetBranchAddress("rho", &rho, &b_rho_);
   fChain->SetBranchAddress("metEnergy", &metEnergy, &b_metEnergy_);
   fChain->SetBranchAddress("metPt", &metPt, &b_metPt_);
   fChain->SetBranchAddress("metEta", &metEta, &b_metEta_);
   fChain->SetBranchAddress("metPhi", &metPhi, &b_metPhi_);
   fChain->SetBranchAddress("metEnergyPUPPI", &metEnergyPUPPI, &b_metEnergypuppi_);
   fChain->SetBranchAddress("metPtPUPPI", &metPtPUPPI, &b_metPtpuppi_);
   fChain->SetBranchAddress("metEtaPUPPI", &metEtaPUPPI, &b_metEtapuppi_);
   fChain->SetBranchAddress("metPhiPUPPI", &metPhiPUPPI, &b_metPhipuppi_);
   fChain->SetBranchAddress("metSig", &metSig, &b_metSig_);
   fChain->SetBranchAddress("metTypeI", &metTypeI, &b_metcorrected_);
   fChain->SetBranchAddress("goodPVtx", &goodPVtx, &b_goodPVtx_);
   fChain->SetBranchAddress("deltaNHfootprintX", &deltaNHfootprintX, &b_deltaNHfootprintX_);
   fChain->SetBranchAddress("deltaNHfootprintY", &deltaNHfootprintY, &b_deltaNHfootprintY_);
   fChain->SetBranchAddress("metEnergyGen", &metEnergyGen, &b_metEnergyGen_);
   fChain->SetBranchAddress("metPtGen", &metPtGen, &b_metPtGen_);
   fChain->SetBranchAddress("metEtaGen", &metEtaGen, &b_metEtaGen_);
   fChain->SetBranchAddress("metPhiGen", &metPhiGen, &b_metPhiGen_);
   fChain->SetBranchAddress("metEnergyPUPPIGen", &metEnergyPUPPIGen, &b_metEnergypuppiGen_);
   fChain->SetBranchAddress("metPtPUPPIGen", &metPtPUPPIGen, &b_metPtpuppiGen_);
   fChain->SetBranchAddress("metEtaPUPPIGen", &metEtaPUPPIGen, &b_metEtapuppiGen_);
   fChain->SetBranchAddress("metPhiPUPPIGen", &metPhiPUPPIGen, &b_metPhipuppiGen_);
   fChain->SetBranchAddress("gen_eta", &gen_eta, &b_gen_eta);
   fChain->SetBranchAddress("gen_phi", &gen_phi, &b_gen_phi);
   fChain->SetBranchAddress("gen_p", &gen_p, &b_gen_p);
   fChain->SetBranchAddress("gen_px", &gen_px, &b_gen_px);
   fChain->SetBranchAddress("gen_py", &gen_py, &b_gen_py);
   fChain->SetBranchAddress("gen_pz", &gen_pz, &b_gen_pz);
   fChain->SetBranchAddress("gen_pt", &gen_pt, &b_gen_pt);
   fChain->SetBranchAddress("gen_energy", &gen_energy, &b_gen_energy);
   fChain->SetBranchAddress("gen_pdgId", &gen_pdgId, &b_gen_pdgId);
   fChain->SetBranchAddress("gen_vx", &gen_vx, &b_gen_vx);
   fChain->SetBranchAddress("gen_vy", &gen_vy, &b_gen_vy);
   fChain->SetBranchAddress("gen_vz", &gen_vz, &b_gen_vz);
   fChain->SetBranchAddress("gen_numDaught", &gen_numDaught, &b_gen_numDaught);
   fChain->SetBranchAddress("gen_status", &gen_status, &b_gen_status);
   fChain->SetBranchAddress("gen_index", &gen_index, &b_gen_index);
   fChain->SetBranchAddress("gen_motherIndex", &gen_motherIndex, &b_gen_motherIndex);
   fChain->SetBranchAddress("nJetsAK4", &nJetsAK4, &b_nJetsAK4_);
   fChain->SetBranchAddress("nJetsPUPPI", &nJetsPUPPI, &b_nJetsPUPPI_);
   fChain->SetBranchAddress("htAK4", &htAK4, &b_htAK4_);
   fChain->SetBranchAddress("nJetsAK8", &nJetsAK8, &b_nJetsAK8_);
   fChain->SetBranchAddress("htAK8", &htAK8, &b_htAK8_);
   fChain->SetBranchAddress("nPhoton", &nPhoton, &b_nPhotons_);
   fChain->SetBranchAddress("nPhotonLoose", &nPhotonLoose, &b_nPhotonsLoose_);
   fChain->SetBranchAddress("nPhotonMedium", &nPhotonMedium, &b_nPhotonsMedium_);
   fChain->SetBranchAddress("nPhotonTight", &nPhotonTight, &b_nPhotonsTight_);
   fChain->SetBranchAddress("isMatch30", &isMatch30, &b_isMatch30);
   fChain->SetBranchAddress("isMatch50", &isMatch50, &b_isMatch50);
   fChain->SetBranchAddress("isMatch75", &isMatch75, &b_isMatch75);
   fChain->SetBranchAddress("isMatch90", &isMatch90, &b_isMatch90);
   fChain->SetBranchAddress("isMatch120", &isMatch120, &b_isMatch120);
   fChain->SetBranchAddress("isMatch165", &isMatch165, &b_isMatch165);
   fChain->SetBranchAddress("isGenMatch", &isGenMatch, &b_isGenMatch);
   fChain->SetBranchAddress("isPhotonMedium_EG_MVA", &isPhotonMedium_EG_MVA, &b_isPhotonMedium_EG_MVA);
   fChain->SetBranchAddress("PhotonLoosePt", &PhotonLoosePt, &b_PhotonLoosePt);
   fChain->SetBranchAddress("PhotonsmearPt", &PhotonsmearPt, &b_PhotonsmearPt);
   fChain->SetBranchAddress("PhotonSCPt", &PhotonSCPt, &b_PhotonSCPt);
   fChain->SetBranchAddress("PhotonLooseEta", &PhotonLooseEta, &b_PhotonLooseEta);
   fChain->SetBranchAddress("PhotonsmearEta", &PhotonsmearEta, &b_PhotonsmearEta);
   fChain->SetBranchAddress("PhotonSCEta", &PhotonSCEta, &b_PhotonSCEta);
   fChain->SetBranchAddress("PhotonLoosePhi", &PhotonLoosePhi, &b_PhotonLoosePhi);
   fChain->SetBranchAddress("PhotonsmearPhi", &PhotonsmearPhi, &b_PhotonsmearPhi);
   fChain->SetBranchAddress("PhotonSCPhi", &PhotonSCPhi, &b_PhotonSCPhi);
   fChain->SetBranchAddress("PhotonLooseEnergy", &PhotonLooseEnergy, &b_PhotonLooseEnergy);
   fChain->SetBranchAddress("PhotonsmearEnergy", &PhotonsmearEnergy, &b_PhotonsmearEnergy);
   fChain->SetBranchAddress("PhotonSCEnergy", &PhotonSCEnergy, &b_PhotonSCEnergy);
   fChain->SetBranchAddress("PhotonEcorrBump", &PhotonEcorrBump, &b_PhotonEcorrBump);
   fChain->SetBranchAddress("Photonfull5x5SigmaIEtaIEtaMapToken", &Photonfull5x5SigmaIEtaIEtaMapToken, &b_Photonfull5x5SigmaIEtaIEtaMapToken);
   fChain->SetBranchAddress("PhotonphoChargedIsolationToken", &PhotonphoChargedIsolationToken, &b_PhotonphoChargedIsolationToken);
   fChain->SetBranchAddress("PhotonphoNeutralHadronIsolationToken", &PhotonphoNeutralHadronIsolationToken, &b_PhotonphoNeutralHadronIsolationToken);
   fChain->SetBranchAddress("PhotonphoPhotonIsolationToken", &PhotonphoPhotonIsolationToken, &b_PhotonphoPhotonIsolationToken);
   fChain->SetBranchAddress("HaspixelSeed", &HaspixelSeed, &b_HaspixelSeed);
   fChain->SetBranchAddress("ElectronVeto", &ElectronVeto, &b_ElectronVeto);
   fChain->SetBranchAddress("hadTowOverEm", &hadTowOverEm, &b_hadTowOverEm);
   fChain->SetBranchAddress("isPhotonLoose", &isPhotonLoose, &b_isPhotonLoose);
   fChain->SetBranchAddress("isPhotonMedium", &isPhotonMedium, &b_isPhotonMedium);
   fChain->SetBranchAddress("isPhotonTight", &isPhotonTight, &b_isPhotonTight);
   fChain->SetBranchAddress("isfakephoton", &isfakephoton, &b_isfakephoton);
   fChain->SetBranchAddress("Photonfull5x5SigmaIEtaIPhiMapToken", &Photonfull5x5SigmaIEtaIPhiMapToken, &b_Photonfull5x5SigmaIEtaIPhiMapToken);
   fChain->SetBranchAddress("Photonfull5x5E5x5MapToken", &Photonfull5x5E5x5MapToken, &b_Photonfull5x5E5x5MapToken);
   fChain->SetBranchAddress("Photonfull5x5E2x2MapToken", &Photonfull5x5E2x2MapToken, &b_Photonfull5x5E2x2MapToken);
   fChain->SetBranchAddress("PhotonESEffSigmaRRMapToken", &PhotonESEffSigmaRRMapToken, &b_PhotonESEffSigmaRRMapToken);
   fChain->SetBranchAddress("PhotonR9", &PhotonR9, &b_PhotonR9);
   fChain->SetBranchAddress("Photon_etawidth", &Photon_etawidth, &b_Photon_etawidth);
   fChain->SetBranchAddress("Photon_phiwidth", &Photon_phiwidth, &b_Photon_phiwidth);
   fChain->SetBranchAddress("Photon_ES_energy", &Photon_ES_energy, &b_Photon_ES_energy);
   fChain->SetBranchAddress("Photonfull5x5E2x5", &Photonfull5x5E2x5, &b_Photonfull5x5E2x5);
   fChain->SetBranchAddress("Photonfull5x5E1x3", &Photonfull5x5E1x3, &b_Photonfull5x5E1x3);
   fChain->SetBranchAddress("PhotonWorstChargedIsolation", &PhotonWorstChargedIsolation, &b_PhotonWorstChargedIsolation);
   fChain->SetBranchAddress("Photon_scaleUNC_gainup", &Photon_scaleUNC_gainup, &b_Photon_scaleUNC_gainup);
   fChain->SetBranchAddress("Photon_scaleUNC_gaindown", &Photon_scaleUNC_gaindown, &b_Photon_scaleUNC_gaindown);
   fChain->SetBranchAddress("Photon_scaleUNC_systup", &Photon_scaleUNC_systup, &b_Photon_scaleUNC_systup);
   fChain->SetBranchAddress("Photon_scaleUNC_systdown", &Photon_scaleUNC_systdown, &b_Photon_scaleUNC_systdown);
   fChain->SetBranchAddress("Photon_scaleUNC_statup", &Photon_scaleUNC_statup, &b_Photon_scaleUNC_statup);
   fChain->SetBranchAddress("Photon_scaleUNC_statdown", &Photon_scaleUNC_statdown, &b_Photon_scaleUNC_statdown);
   fChain->SetBranchAddress("Photon_scaleUNC_ETup", &Photon_scaleUNC_ETup, &b_Photon_scaleUNC_ETup);
   fChain->SetBranchAddress("Photon_scaleUNC_ETdown", &Photon_scaleUNC_ETdown, &b_Photon_scaleUNC_ETdown);
   fChain->SetBranchAddress("Photon_smearUNC_phiup", &Photon_smearUNC_phiup, &b_Photon_smearUNC_phiup);
   fChain->SetBranchAddress("Photon_smearUNC_rhodown", &Photon_smearUNC_rhodown, &b_Photon_smearUNC_rhodown);
   fChain->SetBranchAddress("Photon_smearUNC_rhoup", &Photon_smearUNC_rhoup, &b_Photon_smearUNC_rhoup);
   fChain->SetBranchAddress("photon_scale_central", &photon_scale_central, &b_photon_scale_central);
   fChain->SetBranchAddress("photon_smear_central", &photon_smear_central, &b_photon_smear_central);
   fChain->SetBranchAddress("electronPt", &electronPt, &b_electronPt);
   fChain->SetBranchAddress("electronEta", &electronEta, &b_electronEta);
   fChain->SetBranchAddress("electronPhi", &electronPhi, &b_electronPhi);
   fChain->SetBranchAddress("electronEnergy", &electronEnergy, &b_electronEnergy);
   fChain->SetBranchAddress("electronID", &electronID, &b_electronID);
   fChain->SetBranchAddress("electronISO", &electronISO, &b_electronISO);
   fChain->SetBranchAddress("electronPtsmeared", &electronPtsmeared, &b_electronPtsmeared);
   fChain->SetBranchAddress("electronEtasmeared", &electronEtasmeared, &b_electronEtasmeared);
   fChain->SetBranchAddress("electronPhismeared", &electronPhismeared, &b_electronPhismeared);
   fChain->SetBranchAddress("electronEnergysmeared", &electronEnergysmeared, &b_electronEnergysmeared);
   fChain->SetBranchAddress("electronIDsmeared", &electronIDsmeared, &b_electronIDsmeared);
   fChain->SetBranchAddress("electronISOsmeared", &electronISOsmeared, &b_electronISOsmeared);
   fChain->SetBranchAddress("muonPt", &muonPt, &b_muonPt);
   fChain->SetBranchAddress("muonEta", &muonEta, &b_muonEta);
   fChain->SetBranchAddress("muonPhi", &muonPhi, &b_muonPhi);
   fChain->SetBranchAddress("muonEnergy", &muonEnergy, &b_muonEnergy);
   fChain->SetBranchAddress("nMuonsLoose", &nMuonsLoose, &b_nMuonsLoose_);
   fChain->SetBranchAddress("jetPtAK4", &jetPtAK4, &b_jetPtAK4);
   fChain->SetBranchAddress("jetJecAK4", &jetJecAK4, &b_jetJecAK4);
   fChain->SetBranchAddress("jetEtaAK4", &jetEtaAK4, &b_jetEtaAK4);
   fChain->SetBranchAddress("jetPhiAK4", &jetPhiAK4, &b_jetPhiAK4);
   fChain->SetBranchAddress("jetMassAK4", &jetMassAK4, &b_jetMassAK4);
   fChain->SetBranchAddress("jetEnergyAK4", &jetEnergyAK4, &b_jetEnergyAK4);
   fChain->SetBranchAddress("jetPtAK4RC", &jetPtAK4RC, &b_jetPtAK4RC);
   fChain->SetBranchAddress("jetEtaAK4RC", &jetEtaAK4RC, &b_jetEtaAK4RC);
   fChain->SetBranchAddress("jetPhiAK4RC", &jetPhiAK4RC, &b_jetPhiAK4RC);
   fChain->SetBranchAddress("jetMassAK4RC", &jetMassAK4RC, &b_jetMassAK4RC);
   fChain->SetBranchAddress("jetEnergyAK4RC", &jetEnergyAK4RC, &b_jetEnergyAK4RC);
   fChain->SetBranchAddress("jetAreaAK4", &jetAreaAK4, &b_jetAreaAK4);
   fChain->SetBranchAddress("jetCSVAK4", &jetCSVAK4, &b_jetCSVAK4);
   fChain->SetBranchAddress("jetQGDAK4", &jetQGDAK4, &b_jetQGDAK4);
   fChain->SetBranchAddress("jetChfAK4", &jetChfAK4, &b_jetChfAK4);
   fChain->SetBranchAddress("jetNhfAK4", &jetNhfAK4, &b_jetNhfAK4);
   fChain->SetBranchAddress("jetPhfAK4", &jetPhfAK4, &b_jetPhfAK4);
   fChain->SetBranchAddress("jetMufAK4", &jetMufAK4, &b_jetMufAK4);
   fChain->SetBranchAddress("jetElfAK4", &jetElfAK4, &b_jetElfAK4);
   fChain->SetBranchAddress("jetNemfAK4", &jetNemfAK4, &b_jetNemfAK4);
   fChain->SetBranchAddress("jetCemfAK4", &jetCemfAK4, &b_jetCemfAK4);
   fChain->SetBranchAddress("jetHf_hfAK4", &jetHf_hfAK4, &b_jetHf_hfAK4);
   fChain->SetBranchAddress("jetHf_emfAK4", &jetHf_emfAK4, &b_jetHf_emfAK4);
   fChain->SetBranchAddress("jetHofAK4", &jetHofAK4, &b_jetHofAK4);
   fChain->SetBranchAddress("idLAK4", &idLAK4, &b_idLAK4);
   fChain->SetBranchAddress("idTAK4", &idTAK4, &b_idTAK4);
   fChain->SetBranchAddress("chHadMultAK4", &chHadMultAK4, &b_chHadMultAK4);
   fChain->SetBranchAddress("chMultAK4", &chMultAK4, &b_chMultAK4);
   fChain->SetBranchAddress("neHadMultAK4", &neHadMultAK4, &b_neHadMultAK4);
   fChain->SetBranchAddress("neMultAK4", &neMultAK4, &b_neMultAK4);
   fChain->SetBranchAddress("phoMultAK4", &phoMultAK4, &b_phoMultAK4);
   fChain->SetBranchAddress("hadronflavour", &hadronflavour, &b_hadronflavour);
   fChain->SetBranchAddress("deepcsv_probb_AK4", &deepcsv_probb_AK4, &b_deepcsv_probb_AK4);
   fChain->SetBranchAddress("deepcsv_probbb_AK4", &deepcsv_probbb_AK4, &b_deepcsv_probbb_AK4);
   fChain->SetBranchAddress("deepcsv_probc_AK4", &deepcsv_probc_AK4, &b_deepcsv_probc_AK4);
   fChain->SetBranchAddress("deepcsv_probcc_AK4", &deepcsv_probcc_AK4, &b_deepcsv_probcc_AK4);
   fChain->SetBranchAddress("CvsB_taggerAK4", &CvsB_taggerAK4, &b_CvsB_taggerAK4);
   fChain->SetBranchAddress("CvsL_taggerAK4", &CvsL_taggerAK4, &b_CvsL_taggerAK4);
   fChain->SetBranchAddress("triggerResult", &triggerResult, &b_triggerResult);
   fChain->SetBranchAddress("triggerPrescale", &triggerPrescale, &b_triggerPrescale);
   fChain->SetBranchAddress("triggerName", &triggerName, &b_triggerName);
   fChain->SetBranchAddress("npu", &npu, &b_npu);
   fChain->SetBranchAddress("PileupInteractions", &PileupInteractions, &b_PileupInteractions);
   fChain->SetBranchAddress("PileupOriginBX", &PileupOriginBX, &b_PileupOriginBX);
   fChain->SetBranchAddress("ptHat", &ptHat, &b_ptHat_);
   fChain->SetBranchAddress("processID", &processID, &b_processID_);
   fChain->SetBranchAddress("weight", &weight, &b_weight_);
   fChain->SetBranchAddress("nGenJetsAK4", &nGenJetsAK4, &b_nGenJetsAK4_);
   fChain->SetBranchAddress("nGenJetsAK8", &nGenJetsAK8, &b_nGenJetsAK8_);
   fChain->SetBranchAddress("nGenPhoton", &nGenPhoton, &b_nGenPhotons_);
   fChain->SetBranchAddress("photonPtGen", &photonPtGen, &b_photonPtGen);
   fChain->SetBranchAddress("photonEtaGen", &photonEtaGen, &b_photonEtaGen);
   fChain->SetBranchAddress("photonPhiGen", &photonPhiGen, &b_photonPhiGen);
   fChain->SetBranchAddress("photonEnergyGen", &photonEnergyGen, &b_photonEnergyGen);
   fChain->SetBranchAddress("jetPtGenAK4", &jetPtGenAK4, &b_jetPtGenAK4);
   fChain->SetBranchAddress("jetEtaGenAK4", &jetEtaGenAK4, &b_jetEtaGenAK4);
   fChain->SetBranchAddress("jetPhiGenAK4", &jetPhiGenAK4, &b_jetPhiGenAK4);
   fChain->SetBranchAddress("jetMassGenAK4", &jetMassGenAK4, &b_jetMassGenAK4);
   fChain->SetBranchAddress("jetEnergyGenAK4", &jetEnergyGenAK4, &b_jetEnergyGenAK4);
   fChain->SetBranchAddress("jetpdgIDGenAK4", &jetpdgIDGenAK4, &b_jetpdgIDGenAK4);
   Notify();
}

Bool_t rootNtupleClass::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void rootNtupleClass::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t rootNtupleClass::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef rootNtupleClass_cxx
