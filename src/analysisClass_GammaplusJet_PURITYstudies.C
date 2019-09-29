#define analysisClass_cxx
#include "analysisClass.h"
#include <TH2.h>
#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TParameter.h>
#include <TLorentzVector.h>
#include <TVector2.h>
#include <TVector3.h>
#define RESET_COLOR "\033[m"
#define MAKE_RED "\033[31m"
#define MAKE_BLUE "\033[34m"

enum class IsolationType {
    CHARGED_HADRONS,
    NEUTRAL_HADRONS,
    PHOTONS
    };
    
float getEffectiveArea(float eta, IsolationType type) {
  eta = fabs(eta);
  switch (type) {
  case IsolationType::CHARGED_HADRONS:
    if (eta < 1.0)
      return 0.0360;
    else if (eta < 1.479)
      return 0.0377;
    else if (eta < 2.0)
      return 0.0306;
    else if (eta < 2.2)
      return 0.0283;
    else if (eta < 2.3)
      return 0.0254;
    else if (eta < 2.4)
      return 0.0217;
    else
      return 0.0167;
    break;
    
  case IsolationType::NEUTRAL_HADRONS:
    if (eta < 1.0)
      return 0.0597;
    else if (eta < 1.479)
      return 0.0807;
    else if (eta < 2.0)
      return 0.0629;
    else if (eta < 2.2)
      return 0.0197;
    else if (eta < 2.3)
      return 0.0184;
    else if (eta < 2.4)
      return 0.0284;
    else
      return 0.0591;
    break;

    //Official  
  case IsolationType::PHOTONS:
    if (eta < 1.0)
      return 0.1210;
    else if (eta < 1.479)
      return 0.1107;
    else if (eta < 2.0)
      return 0.0699;
    else if (eta < 2.2)
      return 0.1056;
    else if (eta < 2.3)
      return 0.1457;
    else if (eta < 2.4)
      return 0.1719;
    else
      return 0.1998;
    break;
  }
  
  return -1;
}

double getCorrectedPFIsolation(float isolation, float rho, float eta, IsolationType type) 
{
  float effectiveArea = getEffectiveArea(eta, type); 
  return isolation - rho*effectiveArea;
}

bool isValidPhotonTight(const float& SigmaIEtaIEta, const float& hadTowOverEm, const float&  rhos, const float& ChargedIsolation, const float& NeutralHadronIsolation,const float& PhotonIsolation, const float& eta_photon, const float& pt_photon)
{
    bool isValid = true;
    
   // #1: H/E
    isValid &= hadTowOverEm < 0.0269;
    if (! isValid)
    return false;
    //#2: sigma ietaieta
    isValid &= SigmaIEtaIEta < 0.00994; //Official    
    if (! isValid)
    return false;
    
    isValid &= getCorrectedPFIsolation(ChargedIsolation, rhos, eta_photon, IsolationType::CHARGED_HADRONS) < 0.202;
    isValid &= getCorrectedPFIsolation(NeutralHadronIsolation, rhos, eta_photon, IsolationType::NEUTRAL_HADRONS) < (0.264 + 0.0148*pt_photon+0.000017*(pt_photon*pt_photon ) );
    isValid &= getCorrectedPFIsolation(PhotonIsolation, rhos, pt_photon, IsolationType::PHOTONS) < (2.362+0.0047*pt_photon);
    if (! isValid)
    return false;
    
    return isValid;
    
    
}

bool isNewonOldValidJetTight(const float& Eta_ak4, const float& nhf, const float& neMult, const float& nemf, const bool& isoldvalid, const bool& isDATA, const bool& hasgenjet)
{
   
    int idL = -999 ;
    if(isoldvalid) {
    return true ;  
    }else{return false;}   
    if(!isDATA && !hasgenjet) return false;
    
    if(fabs(Eta_ak4) > 2.7  && fabs(Eta_ak4) <= 3.0)
    {
       idL = ( nemf>0.01 && nhf<0.98 && neMult>2)  ;
       
       
    }else{
       if(isoldvalid){
       idL =1;
       }else{idL =0;}
       
    } 
    
 return idL;

    
    
}


analysisClass::analysisClass(string * inputList, string * cutFile, string * treeName, string * outputFileName, string * cutEfficFile)
  :baseClass(inputList, cutFile, treeName, outputFileName, cutEfficFile)
{
  std::cout << "analysisClass::analysisClass(): begins " << std::endl;

  // For JECs
  if( int(getPreCutValue1("useJECs"))==1 )
  {
    std::cout << "Reapplying JECs on the fly" << std::endl;

    std::string L1Path =  getPreCutString1("L1MC");//"data/Spring16_25nsV8BCD_MC/Spring16_25nsV8BCD_MC_L1FastJet_AK4PFchs.txt";
    std::string L2Path = getPreCutString1("L2MC");//"data/Spring16_25nsV8BCD_MC/Spring16_25nsV8BCD_MC_L2Relative_AK4PFchs.txt";
    std::string L3Path = getPreCutString1("L3MC");//"data/Spring16_25nsV8BCD_MC/Spring16_25nsV8BCD_MC_L3Absolute_AK4PFchs.txt";
    std::string L1DATAPath = getPreCutString1("L1Dat");//"data/Spring16_25nsV8BCD_DATA/Spring16_25nsV8BCD_DATA_L1FastJet_AK4PFchs.txt";
    std::string L2DATAPath = getPreCutString1("L2Dat");//"data/Spring16_25nsV8BCD_DATA/Spring16_25nsV8BCD_DATA_L2Relative_AK4PFchs.txt"; 
    std::string L3DATAPath = getPreCutString1("L3Dat");//"data/Spring16_25nsV8BCD_DATA/Spring16_25nsV8BCD_DATA_L3Absolute_AK4PFchs.txt";
    std::string L2L3ResidualPath = getPreCutString1("L2L3Dat");//"data/Spring16_25nsV8BCD_DATA/Spring16_25nsV8BCD_DATA_L2Residual_AK4PFchs.txt"; 
    
    
    std::string L1RCcorrDATAPath = getPreCutString1("L1RCMC");//"data/Spring16_25nsV8BCD_DATA/Spring16_25nsV8BCD_DATA_L1RC_AK4PFchs.txt";
    std::string L1RCcorrMCPath = getPreCutString1("L1RCDat");//"data/Spring16_25nsV8BCD_MC/Spring16_25nsV8BCD_MC_L1RC_AK4PFchs.txt";

    //uncertainty
    unc = new JetCorrectionUncertainty(getPreCutString1("JECuncDat")/*"data/Spring16_25nsV8BCD_DATA/Spring16_25nsV8BCD_DATA_Uncertainty_AK4PFchs.txt"*/);
        
    L1Par = new JetCorrectorParameters(L1Path);
    L2Par = new JetCorrectorParameters(L2Path);
    L3Par = new JetCorrectorParameters(L3Path);
    L1DATAPar = new JetCorrectorParameters(L1DATAPath);
    L2DATAPar = new JetCorrectorParameters(L2DATAPath);
    L3DATAPar = new JetCorrectorParameters(L3DATAPath);
    L2L3Residual = new JetCorrectorParameters(L2L3ResidualPath);
    
    L1JetParForTypeI =new JetCorrectorParameters(L1RCcorrDATAPath);
    L1JetParForTypeIMC =new JetCorrectorParameters(L1RCcorrMCPath);


    std::vector<JetCorrectorParameters> vPar;
    std::vector<JetCorrectorParameters> vPar_data;
    vPar.push_back(*L1Par);
    vPar.push_back(*L2Par);
    vPar.push_back(*L3Par);
    
     std::vector<JetCorrectorParameters> vParTypeI;
    vParTypeI.push_back(*L1JetParForTypeI);
    std::vector<JetCorrectorParameters> vParTypeIL123;
    vParTypeIL123.push_back(*L1DATAPar);
    vParTypeIL123.push_back(*L2DATAPar);
    vParTypeIL123.push_back(*L3DATAPar);
    vParTypeIL123.push_back(*L2L3Residual);
    
    std::vector<JetCorrectorParameters> vParTypeIMC;
    vParTypeIMC.push_back(*L1JetParForTypeIMC);
    std::vector<JetCorrectorParameters> vParTypeIL123MC;
    vParTypeIL123MC.push_back(*L1Par);
    vParTypeIL123MC.push_back(*L2Par);
    vParTypeIL123MC.push_back(*L3Par);
    
   
    //residuals are applied only to data
    vPar_data.push_back(*L1DATAPar);
    vPar_data.push_back(*L2DATAPar);
    vPar_data.push_back(*L3DATAPar);
    vPar_data.push_back(*L2L3Residual);

    JetCorrector = new FactorizedJetCorrector(vPar); assert(JetCorrector);
    JetCorrector_data = new FactorizedJetCorrector(vPar_data); assert(JetCorrector_data);
    
    JetCorrectortypI      = new FactorizedJetCorrector(vParTypeI); assert(JetCorrectortypI);
    JetCorrectortypIL123  = new FactorizedJetCorrector(vParTypeIL123); assert(JetCorrectortypIL123);
    JetCorrectortypIMC      = new FactorizedJetCorrector(vParTypeIMC); assert(JetCorrectortypIMC);
    JetCorrectortypIL123MC  = new FactorizedJetCorrector(vParTypeIL123MC); assert(JetCorrectortypIL123MC);
    
  }
  
  std::cout << "analysisClass::analysisClass(): ends " << std::endl;
}

analysisClass::~analysisClass()
{
  std::cout << "analysisClass::~analysisClass(): begins " << std::endl;

  std::cout << "analysisClass::~analysisClass(): ends " << std::endl;
}

void analysisClass::Loop()
{
   std::cout << "analysisClass::Loop() begins" <<std::endl;   
    
   if (fChain == 0) return;
   
   
    Double_t genweight = 0.;
    Float_t trueInteractionall =0;
    
    TTree *PUvariable = new TTree("puvariable","puvariable");
    PUvariable->Branch("Generatorweight", &genweight, "genweight/D");
    PUvariable->Branch("TrueInteractionall", &trueInteractionall, "trueInteractionall/F");    
     
     
    TH2F *DeltaPhiAlpha = new TH2F("DeltaPhi_vs_alpha", "DeltaPhi_vs_alpha", 50, 0, 1. ,50, 0, 5  ) ;
      
    TH1F *SumWeight  = new TH1F("h_sumW", "h_sumW", 1, -0.5, 5.5) ;    
    SumWeight->Sumw2();
    TParameter<float> *totalluminosityP = new  TParameter<float>("totallumi", 0.);
    float storelumi = -15;
    float totalluminosity = 0.; 
    int nselectedevent = 0;
    int ncut_photon = 0;
    int ncut_photonpt = 0;
    int ncut_nophoton = 0;
    int ncut_deltaphi = 0;
    int ncut_alpha = 0;
    int ncut_pixelseed = 0;
    int ncut_muons = 0;
    int ncut_electron = 0;
    int ncut_jet = 0 ;
    int ncut_ptjet = 0;
    int Vtxcut = 0 ;
    int testcount = 0 ;
   /////////initialize variables

   Long64_t nentries = fChain->GetEntriesFast();
   
   std::cout << "analysisClass::Loop(): nentries = " << nentries << std::endl;      
   ////// The following ~7 lines have been taken from rootNtupleClass->Loop() /////
   ////// If the root version is updated and rootNtupleClass regenerated,     /////
   ////// these lines may need to be updated.                                 /////    
  Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   //for (Long64_t jentry=0; jentry<2000;jentry++) {
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     
     nb = fChain->GetEntry(jentry);   nbytes += nb;
    if(jentry < 10 || jentry%1000 == 0) std::cout << "analysisClass::Loop(): jentry = " << jentry << std::endl;   
     // if (Cut(ientry) < 0) continue;
    
  // if(jentry - Vtxcut -   ncut_nophoton -  ncut_photon >= 300) break ;
   
     ////////////////////// User's code starts here ///////////////////////

     ///Stuff to be done for every event
     int idx_InTimeBX=-1;
     for(size_t j=0; j<PileupOriginBX->size(); ++j)
       {
	// cout << PileupOriginBX->at(j) << endl;	 
	 if(PileupOriginBX->at(j)==0)
	   {
	     idx_InTimeBX = j;
	     //cout << "idx_InTimeBX: " << idx_InTimeBX << endl; 
	   }
       }
       bool isData = 0;
     if(idx_InTimeBX > -1 ) isData = 0;
     else isData = 1;
     
     
     if(!isData)
     {
         SumWeight->Fill(0.,weight);
         genweight = weight;
         trueInteractionall = npu->at(1)/*PileupInteractions->at(idx_InTimeBX)*/;
         PUvariable->Fill();
         
     }else
     {
          SumWeight->Fill(0.,1);
          weight = 1 ;  
          trueInteractionall = -999;   
          PUvariable->Fill();
     }
  //  cout<<"good vtx "<<goodPVtx<<endl;
    if(!goodPVtx){
       
       Vtxcut++;
       continue;
    } 
     if(nPhoton > 0){
          if(nPhotonTight == 1 ){
        //  if(jentry - Vtxcut -   ncut_nophoton -  ncut_photon < 200) continue;
          testcount ++;
             size_t nb_photon =  PhotonLoosePt->size();
             int indexgoodpho = 0  ; 
             for(size_t pho = 0 ; pho <  nb_photon ; pho ++)
          {
              if(isPhotonTight->at(pho)){
               indexgoodpho = pho ;
               break ; 
              }
          }
       //   cout<<"idx photon "<<indexgoodpho<<endl;
          
               if(!HaspixelSeed->at(indexgoodpho)){
                     if(/*PhotonLoosePt->at(indexgoodpho)*/PhotonsmearPt->at(indexgoodpho)>= 40.){
                        bool keepmuon = true ;
                        if(nMuonsLoose != 0){ 
                        size_t nb_muons = muonPt->size();
                       
                        for(size_t mu = 0 ; mu < nb_muons ; mu++)
                        {
                          if(muonPt->at(mu) > 5.){
                           keepmuon = false ;
                           break;
                          }
                        }
                        }
                        
                          if(nMuonsLoose == 0 || keepmuon ){


     size_t no_jets_ak4=jetPtAK4->size();
    
     
     TLorentzVector gamma1      ;
    // TLorentzVector gamma1smear ;
      // gamma1.SetPtEtaPhiE(PhotonLoosePt->at(indexgoodpho),PhotonLooseEta->at(indexgoodpho),PhotonLoosePhi->at(indexgoodpho),PhotonLooseEnergy->at(indexgoodpho));
       gamma1.SetPtEtaPhiE(PhotonsmearPt->at(indexgoodpho),PhotonsmearEta->at(indexgoodpho),PhotonsmearPhi->at(indexgoodpho),PhotonsmearEnergy->at(indexgoodpho)); 
       
       
       
     size_t neletron =  electronPt->size();
     bool keepEvent = true;
    for (size_t j = 0; j < neletron; j++) {
      double deltaR = std::hypot((electronEta->at(j)-gamma1.Eta()),(electronPhi->at(j)-gamma1.Phi()));
      if (deltaR < 0.13) {
        keepEvent = false;
        break;
      }
    }
    
     if(!keepEvent){
      ncut_electron++;
      continue;
      
      }
     vector<TLorentzVector> AK4jets;
     TLorentzVector ak4j1, ak4j2;
     
     TLorentzVector rawMet;
     rawMet.SetPtEtaPhiE(metPt,metEta,metPhi,metEnergy);
     TLorentzVector MetTypeI;      

     resetCuts();

     //find intime BX
    

     std::vector<double> jecFactors;
     std::vector<double> jecUncertainty;
     // new JECs could change the jet pT ordering. the vector below
     // holds sorted jet indices after the new JECs had been applied
     std::vector<unsigned> sortedJetIdx;
     
     
     int nfakejet = 0;
     int fakejetIdx = -999;
     double fakecorrection = 0. ;
     bool isthirdjet = false ;
     

     TLorentzVector Tmpjet;
     
     if( int(getPreCutValue1("useJECs"))==1 )
       {
	 // sort jets by increasing pT

	 std::multimap<double, unsigned> sortedJets;
	 for(size_t j=0; j<no_jets_ak4; ++j)
	   {
	     
	     
	     JetCorrector->setJetEta(jetEtaAK4->at(j));
	     JetCorrector->setJetPt(jetPtAK4->at(j)/jetJecAK4->at(j)); //pTraw
	     JetCorrector->setJetA(jetAreaAK4->at(j));
	     JetCorrector->setRho(rho);

  	     JetCorrector_data->setJetEta(jetEtaAK4->at(j));
	     JetCorrector_data->setJetPt(jetPtAK4->at(j)/jetJecAK4->at(j)); //pTraw
	     JetCorrector_data->setJetA(jetAreaAK4->at(j));
	     JetCorrector_data->setRho(rho);


  	     //nominal value of JECs
	     double correction;//, old_correction, nominal_correction;
	     
	     if (isData == 1) correction = JetCorrector_data->getCorrection();
	     else correction = JetCorrector->getCorrection();
	     
	     //JEC uncertainties
	     unc->setJetEta(jetEtaAK4->at(j));
	     unc->setJetPt(jetPtAK4->at(j)/jetJecAK4->at(j)*correction);
	     double uncertainty = unc->getUncertainty(true);
	     jecUncertainty.push_back(uncertainty); 

	     
	     //use "shifted" JECs for study of systematic uncertainties 
	     if( int(getPreCutValue1("shiftJECs"))==1 ){
	       
	       
	       //shift of the corresponding unc
	       correction = correction + getPreCutValue2("shiftJECs")*uncertainty*correction;
	       
	       
	   }
         //if(std::hypot((jetEtaAK4->at(j)-gamma1.Eta()),(jetPhiAK4->at(j)-gamma1.Phi()))>=0.4)
	 //     {
	         jecFactors.push_back(correction);
	  //    }
	  
	  Tmpjet.SetPtEtaPhiM(jetPtAK4->at(j)/jetJecAK4->at(j)*correction, jetEtaAK4->at(j), jetPhiAK4->at(j), jetMassAK4->at(j)/jetJecAK4->at(j)*correction);
	  
	 sortedJets.insert(std::make_pair((jetPtAK4->at(j)/jetJecAK4->at(j))*correction, j));
	 if(/*std::hypot((jetEtaAK4->at(j)-gamma1.Eta()),(jetPhiAK4->at(j)-gamma1.Phi()))*/ gamma1.DeltaR(Tmpjet) < 0.4)
	      { 
	         nfakejet++ ;
	         fakejetIdx = j;
	         fakecorrection = correction;
	        
	      }

       }
       int size_all = sortedJets.size();
       if(nfakejet !=0)
       {

          sortedJets.erase((jetPtAK4->at(fakejetIdx)/jetJecAK4->at(fakejetIdx))*fakecorrection);


        }
        int size_true = sortedJets.size();
       // int size_Jec = jecFactors.size();
     //   std::cout<<"size jet vector "<< size_true << "size JEC vector "<< size_Jec << std::endl;
        
       if(size_all - size_true > 1) std::cout<<"Warning : more than two jet removed because of photon misidentification"<<std::endl;
     // get jet indices in decreasing pT order
     for(std::multimap<double, unsigned>::const_reverse_iterator it = sortedJets.rbegin(); it != sortedJets.rend(); ++it)
	 sortedJetIdx.push_back(it->second);

     }
     else if( int(getPreCutValue1("noJECs"))==1  )
       {
	 // sort jets by increasing pT
	 std::multimap<double, unsigned> sortedJets;
	 for(size_t j=0; j<no_jets_ak4; ++j) //same ordering of original root trees
	   {
	     jecUncertainty.push_back(0.); 
	     jecFactors.push_back(1.);
	     sortedJets.insert(std::make_pair((jetPtAK4->at(j)/jetJecAK4->at(j)), j)); //raw
	   }       
	 // get jet indices in decreasing pT order
	 for(std::multimap<double, unsigned>::const_reverse_iterator it = sortedJets.rbegin(); it != sortedJets.rend(); ++it)
	   sortedJetIdx.push_back(it->second);
       }
     else
       {
	 for(size_t j=0; j<no_jets_ak4; ++j) //same ordering of original root trees
	   {
	     jecFactors.push_back(jetJecAK4->at(j));
	     jecUncertainty.push_back(0.); 
	     sortedJetIdx.push_back(j);
	   }
       }


     //#############################################################
     //########## NOTE: from now on sortedJetIdx[ijet] should be used
     //#############################################################

    
     //count ak4 jets passing pt threshold and id criteria
     int Nak4 = 0;
     double HTak4 = 0;
     for(size_t ijet=0; ijet<no_jets_ak4-nfakejet; ++ijet)
       {	 
	  
	 if(fabs(jetEtaAK4->at(sortedJetIdx[ijet])) < getPreCutValue1("jetFidRegion")
	    && idLAK4->at(sortedJetIdx[ijet]) == getPreCutValue1("tightJetID")
	    && (jecFactors[sortedJetIdx[ijet]]/jetJecAK4->at(sortedJetIdx[ijet]))*jetPtAK4->at(sortedJetIdx[ijet]) >= getPreCutValue1("ptCut"))
	   {
	     Nak4 += 1;
	     HTak4 += (jecFactors[sortedJetIdx[ijet]]/jetJecAK4->at(sortedJetIdx[ijet]))*jetPtAK4->at(sortedJetIdx[ijet]);
	   }
       }



    int sndjetidx = -10 ;


     //AK4 jets
    if(no_jets_ak4-nfakejet>=1  ) 
      { 
     
      bool hasgen = false;
      if(!isData && jetPtGenAK4->at(sortedJetIdx[0])){ hasgen = 1;}
     
         
	 if((jecFactors[sortedJetIdx[0]]/jetJecAK4->at(sortedJetIdx[0]))*jetPtAK4->at(sortedJetIdx[0]) >=  15 /*getPreCutValue1("pt0Cut")*/ && isNewonOldValidJetTight(jetEtaAK4->at(sortedJetIdx[0]), jetNhfAK4->at(sortedJetIdx[0]), neMultAK4->at(sortedJetIdx[0]), jetNemfAK4->at(sortedJetIdx[0]),idLAK4->at(sortedJetIdx[0]), isData, hasgen)/*  && (jecFactors[sortedJetIdx[0]]/jetJecAK4->at(sortedJetIdx[0]))*jetPtAK4->at(sortedJetIdx[0]) >= gamma1.Pt()*getPreCutValue1("firstJetThreshold")*/)
	   {
		 ak4j1.SetPtEtaPhiM( (jecFactors[sortedJetIdx[0]]/jetJecAK4->at(sortedJetIdx[0])) *jetPtAK4->at(sortedJetIdx[0]) ,jetEtaAK4->at(sortedJetIdx[0])
				     ,jetPhiAK4->at(sortedJetIdx[0])
				     , (jecFactors[sortedJetIdx[0]]/jetJecAK4->at(sortedJetIdx[0])) *jetMassAK4->at(sortedJetIdx[0]));
		
		
		for(size_t secjet = 1 ; secjet < no_jets_ak4-nfakejet ; secjet++ ){	
		bool hasgen2 = false;
                if(!isData && jetPtGenAK4->at(sortedJetIdx[secjet])){ hasgen2 = 1;}	     
		if(no_jets_ak4-nfakejet >= secjet + 1 && (jecFactors[sortedJetIdx[secjet]]/jetJecAK4->at(sortedJetIdx[secjet]))*jetPtAK4->at(sortedJetIdx[secjet]) >= 10 && isNewonOldValidJetTight(jetEtaAK4->at(sortedJetIdx[secjet]), jetNhfAK4->at(sortedJetIdx[secjet]), neMultAK4->at(sortedJetIdx[secjet]), jetNemfAK4->at(sortedJetIdx[secjet]),idLAK4->at(sortedJetIdx[0]), isData,hasgen2))
	       {
		      ak4j2.SetPtEtaPhiM( (jecFactors[sortedJetIdx[secjet]]/jetJecAK4->at(sortedJetIdx[secjet])) *jetPtAK4->at(sortedJetIdx[secjet])
				     ,jetEtaAK4->at(sortedJetIdx[secjet])
				     ,jetPhiAK4->at(sortedJetIdx[secjet])
				     , (jecFactors[sortedJetIdx[secjet]]/jetJecAK4->at(sortedJetIdx[secjet])) *jetMassAK4->at(sortedJetIdx[secjet]));
				     sndjetidx = secjet;
				     break;
				     
	       }ak4j2.SetPtEtaPhiM(0.,0.,0.,0.);}
	   }else{
	   ncut_ptjet++;
	   continue;
	   }
   
     }else{ncut_jet++;
     continue;}




 //----------------------TYPE I MET computation------------------
 // std::cout<<"rawMet: "<< rawMet.Pt() << " "<< rawMet.Eta() << " " << rawMet.Phi() << " " << rawMet.Et() <<std::endl; 
  
               

  
  double deltaPx = 0., deltaPy = 0.;
  TLorentzVector  jetRC,corrJet; 
  
  
  for (Long64_t it=0; it< no_jets_ak4/*-nfakejet*/ ; it++) {
  //  if(fakejetIdx==it)continue;
    
    
    double corrs = 1.;
    double corrsForTypeI = 1.;
    
    
      if(isData)
      {
      JetCorrectortypI->setJetEta(jetEtaAK4->at(it));
      JetCorrectortypI->setJetPt(jetPtAK4->at(it)/jetJecAK4->at(it));
      JetCorrectortypI->setJetA(jetAreaAK4->at(it));
      JetCorrectortypI->setRho(rho);
      corrsForTypeI = JetCorrectortypI->getCorrection(); //only RC

      JetCorrectortypIL123 ->setJetEta(jetEtaAK4->at(it));
      JetCorrectortypIL123 ->setJetPt(jetPtAK4->at(it)/jetJecAK4->at(it));
      JetCorrectortypIL123 ->setJetA(jetAreaAK4->at(it));
      JetCorrectortypIL123 ->setRho(rho);
      corrs = JetCorrectortypIL123->getCorrection(); // L1L2L3
      
      }else{

      JetCorrectortypIMC->setJetEta(jetEtaAK4->at(it));
      JetCorrectortypIMC->setJetPt(jetPtAK4->at(it)/jetJecAK4->at(it));
      JetCorrectortypIMC->setJetA(jetAreaAK4->at(it));
      JetCorrectortypIMC->setRho(rho);
      corrsForTypeI = JetCorrectortypIMC->getCorrection(); //only RC
      JetCorrectortypIL123MC ->setJetEta(jetEtaAK4->at(it));
      JetCorrectortypIL123MC ->setJetPt(jetPtAK4->at(it)/jetJecAK4->at(it));
      JetCorrectortypIL123MC ->setJetA(jetAreaAK4->at(it));
      JetCorrectortypIL123MC ->setRho(rho);
      corrs = JetCorrectortypIL123MC->getCorrection(); // L1L2L3

      }

    jetRC.SetPtEtaPhiE((jetPtAK4->at(it)/jetJecAK4->at(it))*corrsForTypeI,jetEtaAK4->at(it),jetPhiAK4->at(it),(jetEnergyAK4->at(it)/jetJecAK4->at(it))*corrsForTypeI);
     // only RC
      
    corrJet.SetPtEtaPhiE((jetPtAK4->at(it)/jetJecAK4->at(it))*corrs,jetEtaAK4->at(it),jetPhiAK4->at(it),(jetEnergyAK4->at(it)/jetJecAK4->at(it))*corrs);
      
    double dR = gamma1.DeltaR(corrJet);
   
  //    std::cout<<"pt of ak4jets "<<jetRC.Pt()<<" dr "<<dR<<std::endl;}
    if(corrJet.Pt() > 15 && dR > 0.25) {
	
      double emEnergyFraction = jetNemfAK4->at(it) + jetCemfAK4->at(it);
      if (emEnergyFraction > 0.90)
	continue;
	
      deltaPx += (corrJet.Px() - jetRC.Px());
      deltaPy += (corrJet.Py() - jetRC.Py());
    } // jet.pt() && dR
  }//loop over jets
    
  double correctedMetPx = rawMet.Px() - deltaPx;
  double correctedMetPy = rawMet.Py() - deltaPy;
  double correctedMetPt = sqrt(correctedMetPx * correctedMetPx + correctedMetPy * correctedMetPy);
  
  MetTypeI.SetPxPyPzE(correctedMetPx,correctedMetPy, rawMet.Pz(), std::hypot(correctedMetPx,correctedMetPy));  
 // MetTypeI.SetPxPyPzE(rawMet.Px(),rawMet.Py(),rawMet.Pz(),rawMet.E());
 // if(evtNo == 231020624  ){
  // std::cout<<"MET type I: "<< MetTypeI.Pt() << " "<< MetTypeI.Eta() << " " << MetTypeI.Phi() << " " << MetTypeI.Et() <<std::endl; }

//------------------------END met calculation------------------


  double Rbal = -999. ;
  double Rmpf = -999. ;
  double Rmpfraw = -999. ;

  Rbal = (ak4j1.Pt()/gamma1.Pt());
  double deltPHIgj = fabs(gamma1.DeltaPhi(ak4j1));
  double deltaphiPhomet = (gamma1.Phi()- metPhi);

  Rmpf = 1. + (MetTypeI.Px()*gamma1.Px()+MetTypeI.Py()*gamma1.Py())/std::pow(gamma1.Pt(),2);
  Rmpfraw = 1. + metPt*gamma1.Pt()*cos(deltaphiPhomet)/std::pow(gamma1.Pt(),2);
  double alpha = -999. ;
  
  alpha = (ak4j2.Pt()/gamma1.Pt());

 DeltaPhiAlpha->Fill(alpha,deltPHIgj);
 //std::cout<<gamma1.DeltaPhi(ak4j1)<<std::endl;
 /* if(evtNo == 231020624  ){
 for(int i = 0 ; i < 5; i++)
     {
        std::cout<<" run "<<runNo <<" pt["<<i<<"] : "<< (jecFactors[i]/jetJecAK4->at(i))*jetPtAK4->at(i)<<" ID["<<i<<"] "<<idLAK4->at(i)<<" DR["<<i<<"]"<<std::hypot((jetEtaAK4->at(i)-gamma1.Eta()),(jetPhiAK4->at(i)-gamma1.Phi()))<<" delta phi jet"<< jetPhiAK4->at(i)<<" "<<gamma1.Phi()<<" nemf : " << jetNemfAK4->at(i)<<" cemf "<< jetCemfAK4->at(i)<< " N hadron em f " << jetNhfAK4->at(i)<< " C hadron em f " << jetChfAK4->at(i)<<std::endl;
     } 
     std::cout <<  std::endl;
     std::cout<<" event : "<<evtNo<<" jet Pt : "<< (jecFactors[sortedJetIdx[0]]/jetJecAK4->at(sortedJetIdx[0]))*jetPtAK4->at(sortedJetIdx[0]) << " Eta : "<<jetEtaAK4->at(sortedJetIdx[0])<<" ID "<< idLAK4->at(sortedJetIdx[0])<< " veto photon "<< gamma1.Pt()*getPreCutValue1("firstJetThreshold")<< " pt photon "<<gamma1.Pt()<< " njet - n fake "<< no_jets_ak4-nfakejet<< " n fake "<< nfakejet   <<std::endl;
     std::cout<<" event : "<<evtNo<<" second jet Pt : "<< (jecFactors[sortedJetIdx[1]]/jetJecAK4->at(sortedJetIdx[1]))*jetPtAK4->at(sortedJetIdx[1]) << " Eta : "<<jetEtaAK4->at(sortedJetIdx[1])<<" ID "<< idLAK4->at(sortedJetIdx[1])<< std::endl;
     std::cout <<  std::endl;
         /*if (no_jets_ak4-nfakejet >=2 && idLAK4->at(sortedJetIdx[1])) std::cout<<" event : "<<evtNo<<" second jet Pt : "<< (jecFactors[sortedJetIdx[2]]/jetJecAK4->at(sortedJetIdx[2]))*jetPtAK4->at(sortedJetIdx[2]) << " Eta : "<<jetEtaAK4->at(sortedJetIdx[2])<<" ID "<< idLAK4->at(sortedJetIdx[2])<< std::endl;
     std::cout <<  std::endl;*/
 
 
     if(deltPHIgj>=2.8 )
     {
     
      
      
     if( ak4j2.Pt() == 0 ||(ak4j2.Pt() < 10. || alpha < 0.3 ) ){
     
     if( ak4j1.Pt()>0   )
     {
       
       AK4jets.push_back( ak4j1 );
       if(ak4j2.Pt()>0)
       {
          AK4jets.push_back( ak4j2 );
       }
     }
     
     
      //== Fill Variables ==
      bool hasgen = false;
      if(!isData && jetPtGenAK4->at(sortedJetIdx[0])){ hasgen = 1;}
     if(ak4j1.Pt()>0 && isNewonOldValidJetTight(jetEtaAK4->at(sortedJetIdx[0]), jetChfAK4->at(sortedJetIdx[0]), neMultAK4->at(sortedJetIdx[0]), jetNemfAK4->at(sortedJetIdx[0]),idLAK4->at(sortedJetIdx[0]), isData, hasgen)) 
    {
     nselectedevent++;
     
     if(lumi != storelumi)
      {
        totalluminosity += lumi ;
      }
      storelumi = lumi;

     
     
     
     fillVariableWithValue("N_photon", nPhoton);
     fillVariableWithValue("run",runNo);     
     fillVariableWithValue("event",evtNo);     
     fillVariableWithValue("lumi",lumi);     
     fillVariableWithValue("nVtx",nvtx);     
     fillVariableWithValue("nJet",no_jets_ak4-nfakejet);
     fillVariableWithValue("metSig",metSig);
     fillVariableWithValue("Nak4",Nak4);
     fillVariableWithValue( "PassJSON", passJSON (runNo, lumi, isData));
     fillVariableWithValue("rho",rho);
     
     fillVariableWithValue("Pt_photon", gamma1.Pt());
     fillVariableWithValue("Eta_photon", gamma1.Eta());
     fillVariableWithValue("Phi_photon", gamma1.Phi());
     fillVariableWithValue("Energy_photon", gamma1.Energy());
     fillVariableWithValue("Rbalancing", Rbal);
     fillVariableWithValue("RMPF", Rmpf);
     fillVariableWithValue("RMPFRAW", Rmpfraw);
     fillVariableWithValue("alpha", alpha);
     fillVariableWithValue("deltaPHIgj", deltPHIgj);
     fillVariableWithValue("sigmaietaieta_photon", Photonfull5x5SigmaIEtaIEtaMapToken->at(indexgoodpho));
     fillVariableWithValue("CHiso_photon", PhotonphoChargedIsolationToken->at(indexgoodpho));
     fillVariableWithValue("NHiso_photon", PhotonphoNeutralHadronIsolationToken->at(indexgoodpho));
     fillVariableWithValue("Photoniso_photon", PhotonphoPhotonIsolationToken->at(indexgoodpho));
     fillVariableWithValue("Pt_photonSC",PhotonSCPt->at(indexgoodpho));
     fillVariableWithValue("Eta_photonSC",PhotonSCEta->at(indexgoodpho));
     fillVariableWithValue("Phi_photonSC",PhotonSCPhi->at(indexgoodpho));
     fillVariableWithValue("Energy_photonSC",PhotonSCEnergy->at(indexgoodpho));
     fillVariableWithValue("hadTowOverEm",hadTowOverEm->at(indexgoodpho));
     if(isData)
       {
          fillVariableWithValue("weight", 1);
          
         //  SumWeight->Fill(0.,weight);
        }
       if(!isData)
       {
         fillVariableWithValue("Pt_photonGEN",photonPtGen->at(indexgoodpho));
	 fillVariableWithValue("Eta_photonGEN",photonEtaGen->at(indexgoodpho));
	 fillVariableWithValue("Phi_photonGEN",photonPhiGen->at(indexgoodpho));
	 fillVariableWithValue("Energy_photonGEN",photonEnergyGen->at(indexgoodpho));
	 
	 fillVariableWithValue("weight",weight);
	// SumWeight->Fill(0.,weight);
	 
       }//MC
     

     if( AK4jets.size() >=1 )
     {
       //cout << "AK4jets.size() " <<  AK4jets.size() << endl;
       //cout << "IdTight_j1 : " << idTAK4->at(sortedJetIdx[0]) << endl;
       fillVariableWithValue( "IdTight_j1",idLAK4->at(sortedJetIdx[0]));
       fillVariableWithValue( "pTAK4_j1", AK4jets[0].Pt());
       fillVariableWithValue( "etaAK4_j1", AK4jets[0].Eta());
       fillVariableWithValue( "phiAK4_j1", AK4jets[0].Phi());
       
       //fillVariableWithValue( "jetPtAK4matchCaloJet_j1", jetPtAK4matchCaloJet->at(sortedJetIdx[0]));
       
       fillVariableWithValue( "jetJecAK4_j1", jecFactors[sortedJetIdx[0]] );
       fillVariableWithValue( "jetJecUncAK4_j1", jecUncertainty[sortedJetIdx[0]] );
       fillVariableWithValue( "jetCSVAK4_j1", jetCSVAK4->at(sortedJetIdx[0]) );
       //jetID
       fillVariableWithValue( "neutrHadEnFrac_j1", jetNhfAK4->at(sortedJetIdx[0]));
       fillVariableWithValue( "chargedHadEnFrac_j1", jetChfAK4->at(sortedJetIdx[0]));
       fillVariableWithValue( "photonEnFrac_j1", jetPhfAK4->at(sortedJetIdx[0]));
       fillVariableWithValue( "eleEnFract_j1", jetElfAK4->at(sortedJetIdx[0]));
       fillVariableWithValue( "muEnFract_j1", jetMufAK4->at(sortedJetIdx[0]));
       fillVariableWithValue( "neutrElectromFrac_j1", jetNemfAK4->at(sortedJetIdx[0]));
       fillVariableWithValue( "chargedElectromFrac_j1", jetCemfAK4->at(sortedJetIdx[0]));
       fillVariableWithValue( "chargedMult_j1", chMultAK4->at(sortedJetIdx[0]));
       fillVariableWithValue( "neutrMult_j1", neMultAK4->at(sortedJetIdx[0]));
       fillVariableWithValue( "photonMult_j1", phoMultAK4->at(sortedJetIdx[0]));
       if(!isData )
       {
         fillVariableWithValue( "pTAK4_j1GEN", jetPtGenAK4->at(sortedJetIdx[0]));
	 fillVariableWithValue( "etaAK4_j1GEN", jetEtaGenAK4->at(sortedJetIdx[0]));	       
	 fillVariableWithValue("PDGIDAK4_j1",jetpdgIDGenAK4->at(sortedJetIdx[0]));
       }
     }
     
     if( AK4jets.size() >=2){

       fillVariableWithValue( "IdTight_j2",idLAK4->at(sortedJetIdx[sndjetidx]));
       fillVariableWithValue( "pTAK4_j2", AK4jets[1].Pt() );
       fillVariableWithValue( "etaAK4_j2", AK4jets[1].Eta());
       fillVariableWithValue( "phiAK4_j2", AK4jets[1].Phi());
       //fillVariableWithValue( "jetPtAK4matchCaloJet_j2", jetPtAK4matchCaloJet->at(sortedJetIdx[1]));
       fillVariableWithValue( "jetJecAK4_j2", jecFactors[sortedJetIdx[sndjetidx]]); 
       fillVariableWithValue( "jetJecUncAK4_j2", jecUncertainty[sortedJetIdx[sndjetidx]] );
       fillVariableWithValue( "jetCSVAK4_j2", jetCSVAK4->at(sortedJetIdx[sndjetidx]) );
       //jetID
       fillVariableWithValue( "neutrHadEnFrac_j2", jetNhfAK4->at(sortedJetIdx[sndjetidx]));
       fillVariableWithValue( "chargedHadEnFrac_j2", jetChfAK4->at(sortedJetIdx[sndjetidx]));
       fillVariableWithValue( "photonEnFrac_j2", jetPhfAK4->at(sortedJetIdx[sndjetidx]));
       fillVariableWithValue( "eleEnFract_j2", jetElfAK4->at(sortedJetIdx[sndjetidx]));
       fillVariableWithValue( "muEnFract_j2", jetMufAK4->at(sortedJetIdx[sndjetidx]));
       fillVariableWithValue( "neutrElectromFrac_j2", jetNemfAK4->at(sortedJetIdx[sndjetidx]));
       fillVariableWithValue( "chargedElectromFrac_j2", jetCemfAK4->at(sortedJetIdx[sndjetidx]));
       fillVariableWithValue( "chargedMult_j2", chMultAK4->at(sortedJetIdx[sndjetidx]));
       fillVariableWithValue( "neutrMult_j2", neMultAK4->at(sortedJetIdx[sndjetidx]));
       fillVariableWithValue( "photonMult_j2", phoMultAK4->at(sortedJetIdx[sndjetidx]));
       //dijet
       fillVariableWithValue( "CosThetaStarAK4", TMath::TanH( (AK4jets[0].Eta()-AK4jets[1].Eta())/2 ));
       if(!isData )
       {
          

         fillVariableWithValue( "pTAK4_j2GEN", jetPtGenAK4->at(sortedJetIdx[sndjetidx]));
	 fillVariableWithValue( "etaAK4_j2GEN", jetEtaGenAK4->at(sortedJetIdx[sndjetidx]));
 	 fillVariableWithValue("PDGIDAK4_j2",jetpdgIDGenAK4->at(sortedJetIdx[sndjetidx]));
	 

       } 
     }
     //no cuts on these variables, just to store in output
     if(!isData)
       fillVariableWithValue("trueInteraction",npu->at(1)/*PileupInteractions->at(idx_InTimeBX)*/);
     else if(isData)
       fillVariableWithValue("trueInteraction",999);     

     fillVariableWithValue("MET",MetTypeI.Et());
     fillVariableWithValue("MET_Pt",MetTypeI.Pt());
     fillVariableWithValue("MET_Eta",MetTypeI.Eta());
     fillVariableWithValue("MET_Phi",MetTypeI.Phi());
     fillVariableWithValue("METRAW",metEnergy);
     if(!isData && metEnergyGen)
     {
       fillVariableWithValue("METGEN",metEnergyPUPPIGen);
       fillVariableWithValue("METGEN_Pt",metPtPUPPIGen);
       fillVariableWithValue("METGEN_Eta",metEtaPUPPIGen);
       fillVariableWithValue("METGEN_Phi",metPhiPUPPIGen);
     }
     
     //double METoverHTAK4=double(met/htAK4);
     double METoverHTAK4=double(MetTypeI.Et()/HTak4);
     fillVariableWithValue("METoverHTAK4",METoverHTAK4);
     //fillVariableWithValue("HTAK4",htAK4);
     fillVariableWithValue("HTAK4",HTak4);
     fillVariableWithValue("ptHat",ptHat);

     // Trigger
     int NtriggerBits = triggerResult->size();
     if( NtriggerBits > 0 && isData)
     {
       fillVariableWithValue("passHLT_Photon30",triggerResult->at(0));// 
     //  fillVariableWithValue("prescaletrigger_Photon30",triggerPrescale->at(0));// 

     }
    if( NtriggerBits > 1 && isData)
    {
       fillVariableWithValue("passHLT_Photon50",triggerResult->at(1));//

     }
     if( NtriggerBits > 2 && isData)
     {
       fillVariableWithValue("passHLT_Photon75",triggerResult->at(2));// 

     }
     if( NtriggerBits > 3 && isData)
     {
       fillVariableWithValue("passHLT_Photon90",triggerResult->at(3));//

     }
     if( NtriggerBits > 4 && isData)
     {
       fillVariableWithValue("passHLT_Photon120",triggerResult->at(4));//

     }
     if( NtriggerBits > 5 && isData)
     {
       fillVariableWithValue("passHLT_Photon165",triggerResult->at(5));//

     }
     
     

     // Evaluate cuts (but do not apply them)
     evaluateCuts();
     
     

     // optional call to fill a skim with a subset of the variables defined in the cutFile (use flag SAVE)
     if( passedCut("Pt_photon") ) 
       {
	 fillReducedSkimTree();

       }
}
}else{ncut_alpha++;
continue;}
}else{ncut_deltaphi++;
continue;}//end dphi cut
//end of pt j1 cut
     ////////////////////// User's code ends here ///////////////////////
     
     
}else{ncut_muons++;
continue;}
}else{ncut_photonpt++;
continue;}
}else{ncut_pixelseed++;
continue;}
}else{ncut_photon++;
 continue;}
//end photon condition
}else{
   ncut_nophoton++;
   continue;
}//no photon 
   } // End loop over events
   
   
   totalluminosityP->SetVal(totalluminosity);
  
   SumWeight->Write();
   totalluminosityP->Write();
   PUvariable->Write();
   DeltaPhiAlpha->Write();
   /*
    std::cout << std::endl;
  std::cout << "Absolute efficiency : related to initial number of event =  " << nentries<< std::endl;
  std::cout << "Efficiency for photon presence cut: " << MAKE_RED << (double) ncut_nophoton  / nentries * 100 << "%" << RESET_COLOR << std::endl;
  std::cout << "Efficiency for photon cut: " << MAKE_RED << (double) ncut_photon  / nentries * 100 << "%" << RESET_COLOR << std::endl;
  std::cout << "Efficiency for pixel seed veto cut: " << MAKE_RED << (double) ncut_pixelseed / nentries * 100 << "%" << RESET_COLOR << std::endl;    
  std::cout << "Efficiency for  pt photon cut: " << MAKE_RED << (double) ncut_photonpt  / nentries * 100 << "%" << RESET_COLOR << std::endl;
  std::cout << "Efficiency for muons cut: " << MAKE_RED << (double) ncut_muons / nentries * 100 << "%" << RESET_COLOR << std::endl; 
  std::cout << "Efficiency for electrons cut: " << MAKE_RED << (double) ncut_electron / nentries * 100 << "%" << RESET_COLOR << std::endl; 
  std::cout << "Efficiency for n jet cut: " << MAKE_RED << (double) ncut_jet / nentries * 100 << "%" << RESET_COLOR << std::endl;  
  std::cout << "Efficiency for Pt(j1) cut: " << MAKE_RED << (double)  ncut_ptjet / nentries * 100 << "%" << RESET_COLOR << std::endl;   
  std::cout << "Efficiency for Δφ cut: " << MAKE_RED << (double) ncut_deltaphi / nentries * 100 << "%" << RESET_COLOR << std::endl;
  std::cout << "Efficiency for α cut: " << MAKE_RED << (double) ncut_alpha / nentries * 100 << "%" << RESET_COLOR << std::endl;  
  std::cout << "Selection efficiency: " << MAKE_RED << (double) nselectedevent / nentries * 100 << "%" << RESET_COLOR << std::endl;
  std::cout << std::endl;
  
     std::cout << std::endl;
  std::cout << "Absolute efficiency : related to initial number of event =  " << nentries<< std::endl;
  std::cout << "Nevent after photon presence cut: " << MAKE_RED << nentries - (double) Vtxcut -  (double)  ncut_nophoton    << RESET_COLOR << std::endl;
  std::cout << "Nevent after photon cut: " << MAKE_RED <<  nentries - (double) Vtxcut - (double)  ncut_nophoton - (double) ncut_photon  << RESET_COLOR << std::endl;
  std::cout << "Nevent after pixel seed veto cut: " << MAKE_RED <<  nentries - (double) Vtxcut - (double)  ncut_nophoton - (double) ncut_photon -(double) ncut_pixelseed  << RESET_COLOR << std::endl;    
  std::cout << "Nevent after  pt photon cut: " << MAKE_RED <<   nentries - (double) Vtxcut - (double)  ncut_nophoton - (double) ncut_photon -(double) ncut_pixelseed  - (double) ncut_photonpt  << RESET_COLOR << std::endl;
  std::cout << "Nevent after muons cut: " << MAKE_RED << nentries - (double) Vtxcut - (double)  ncut_nophoton - (double) ncut_photon -(double) ncut_pixelseed  - (double) ncut_photonpt - (double) ncut_muons  << RESET_COLOR << std::endl; 
  std::cout << "Nevent after electrons cut: " << MAKE_RED << nentries - (double) Vtxcut - (double)  ncut_nophoton - (double) ncut_photon -(double) ncut_pixelseed  - (double) ncut_photonpt - (double) ncut_muons - (double) ncut_electron << RESET_COLOR << std::endl; 
  std::cout << "Nevent after n jet cut: " << MAKE_RED <<nentries - (double) Vtxcut - (double)  ncut_nophoton - (double) ncut_photon -(double) ncut_pixelseed  - (double) ncut_photonpt - (double) ncut_muons - (double) ncut_electron - (double) ncut_jet << RESET_COLOR << std::endl;  
  std::cout << "Nevent after Pt(j1) cut: " << MAKE_RED << nentries - (double) Vtxcut - (double)  ncut_nophoton - (double) ncut_photon -(double) ncut_pixelseed  - (double) ncut_photonpt - (double) ncut_muons - (double) ncut_electron - (double) ncut_jet - (double)  ncut_ptjet<< RESET_COLOR << std::endl;   
  std::cout << "Nevent after Δφ cut: " << MAKE_RED << nentries - (double) Vtxcut - (double)  ncut_nophoton - (double) ncut_photon -(double) ncut_pixelseed  - (double) ncut_photonpt - (double) ncut_muons - (double) ncut_electron - (double) ncut_jet - (double)  ncut_ptjet - (double) ncut_deltaphi  << RESET_COLOR << std::endl;
  std::cout << "Nevent after α cut: " << MAKE_RED << nentries - (double) Vtxcut - (double)  ncut_nophoton - (double) ncut_photon -(double) ncut_pixelseed  - (double) ncut_photonpt - (double) ncut_muons - (double) ncut_electron - (double) ncut_jet - (double)  ncut_ptjet - (double) ncut_deltaphi - (double) ncut_alpha  << RESET_COLOR << std::endl;  
  std::cout << "Selection efficiency: " << MAKE_RED << (double) nselectedevent  << RESET_COLOR << std::endl;
  std::cout << std::endl;
   
   std::cout<<" nb of selected event " << nselectedevent<<std::endl;
   
   */
   
    std::cout << std::endl;
  std::cout << "Absolute efficiency : related to initial number of event =  " << testcount<< std::endl;
  std::cout << "Nevent after photon presence cut: " << MAKE_RED << testcount - (double) Vtxcut -  (double)  ncut_nophoton    << RESET_COLOR << std::endl;
  std::cout << "Nevent after photon cut: " << MAKE_RED <<  testcount - (double) Vtxcut - (double)  ncut_nophoton - (double) ncut_photon  << RESET_COLOR << std::endl;
  std::cout << "Nevent after pixel seed veto cut: " << MAKE_RED <<  testcount /*- (double) Vtxcut - (double)  ncut_nophoton - (double) ncut_photon */-(double) ncut_pixelseed  << RESET_COLOR << std::endl;    
  std::cout << "Nevent after  pt photon cut: " << MAKE_RED <<   testcount /*- (double) Vtxcut - (double)  ncut_nophoton - (double) ncut_photon */-(double) ncut_pixelseed  - (double) ncut_photonpt  << RESET_COLOR << std::endl;
  std::cout << "Nevent after muons cut: " << MAKE_RED << testcount /*- (double) Vtxcut - (double)  ncut_nophoton - (double) ncut_photon */-(double) ncut_pixelseed  - (double) ncut_photonpt - (double) ncut_muons  << RESET_COLOR << std::endl; 
  std::cout << "Nevent after electrons cut: " << MAKE_RED << testcount  /*- (double) Vtxcut - (double)  ncut_nophoton - (double) ncut_photon */-(double) ncut_pixelseed  - (double) ncut_photonpt - (double) ncut_muons - (double) ncut_electron << RESET_COLOR << std::endl; 
  std::cout << "Nevent after n jet cut: " << MAKE_RED <<testcount  /*- (double) Vtxcut - (double)  ncut_nophoton - (double) ncut_photon */-(double) ncut_pixelseed  - (double) ncut_photonpt - (double) ncut_muons - (double) ncut_electron - (double) ncut_jet << RESET_COLOR << std::endl;  
  std::cout << "Nevent after Pt(j1) cut: " << MAKE_RED << testcount /*- (double) Vtxcut - (double)  ncut_nophoton - (double) ncut_photon */ -(double) ncut_pixelseed  - (double) ncut_photonpt - (double) ncut_muons - (double) ncut_electron - (double) ncut_jet - (double)  ncut_ptjet<< RESET_COLOR << std::endl;   
  std::cout << "Nevent after Δφ cut: " << MAKE_RED << testcount /*- (double) Vtxcut - (double)  ncut_nophoton - (double) ncut_photon */-(double) ncut_pixelseed  - (double) ncut_photonpt - (double) ncut_muons - (double) ncut_electron - (double) ncut_jet - (double)  ncut_ptjet - (double) ncut_deltaphi  << RESET_COLOR << std::endl;
  std::cout << "Nevent after α cut: " << MAKE_RED << testcount /*- (double) Vtxcut - (double)  ncut_nophoton - (double) ncut_photon */ -(double) ncut_pixelseed  - (double) ncut_photonpt - (double) ncut_muons - (double) ncut_electron - (double) ncut_jet - (double)  ncut_ptjet - (double) ncut_deltaphi - (double) ncut_alpha  << RESET_COLOR << std::endl;  
  std::cout << "Selection efficiency: " << MAKE_RED << (double) nselectedevent  << RESET_COLOR << std::endl;
  std::cout << std::endl;
   
   std::cout<<" nb of selected event " << nselectedevent<<std::endl;
   
   
   
   
   
   
   
   
   
   std::cout << "analysisClass::Loop() ends" <<std::endl; 
   
    delete  PUvariable;

   }
