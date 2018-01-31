//This program is used to fit the LS attenuation length.
//--------How to use----
//1.input"  root -l ls.c" under the dos window;
//
//2.make sure the time "t_num"of the measure at every height of liquid;
//
//3.When you do not need the data of a height,you can add a "9" in the first data of this height.
//
#include "TGraph.h"
#include "TFile.h"
#include "TBrowser.h"
#include "TH1.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TF1.h"
#include "TROOT.h"
#include <time.h> 
#include <stdio.h> 

void lsdou_yyzh()
{ 
   gROOT->Reset();
   

   Int_t xnum[3000]={0},t=0,ynum[3000]={0}; 
   Double_t mean=0; 
   ifstream fin;    
   fin.open("/home/tgs416/programfiles/geant4/g4work/myN06/470/10.txt");
   //char path_str[64],lab_str[64];
   std::string path_str;

   //  TH1F  *hist = new TH1F("Charge Counting","Charge Counting",100,0,1000);                
     TH1F *hist=new TH1F("","",100,900,1100);
                  hist->GetXaxis()->SetTitle("channel");
	 	  hist->GetYaxis()->SetTitle("counts");
                  hist->SetLineWidth(2);
                  hist->SetMarkerSize(2);
                  hist->GetXaxis()->SetRangeUser(900,1100); 

     TCanvas *c = new TCanvas("cav","Hist Draw Canvas",1000,600);         


   while(fin)
   {
      fin>>path_str;
      if(path_str=="start.")
        {
            for(int loop=0;loop<3000;loop++)
                {
                   fin>>ynum[loop];
                  //  xnum[loop]=loop+1;
                   hist->Fill(ynum[loop]); 

                }
        }
    }
   fin.close();
 
                 c->cd();
                 hist->Draw();
    TF1 *fit=new TF1("LAB","gaus",900,1100);
         fit->SetLineColor(kRed);
                 hist->Fit(fit,"R");
                 mean=fit->GetParameter(1);
                 c->SaveAs("/home/tgs416/programfiles/geant4/g4work/myN06/470/fit_10.png");
	         //sigma=fit->GetParameter(2);

  ofstream out1("/home/tgs416/programfiles/geant4/g4work/myN06/470/m.txt",ios::out&&ios::app);

 //ofstream out1;
  // out1.open("/home/tgs416/programfiles/geant4/g4work/myN06/40/m.txt");
   
   out1<<"1.0"<<"\t"<<mean<<endl;
   
   out1.close();
   
// cout<<mean<<endl;





  /* ofstream out;
   out.open("/home/tgs416/programfiles/geant4/g4work/myN06/40/09out.txt");
   for(int l=0;l<3000;l++)
   {
    out<<xnum[l]<<"\t"<<ynum[l]<<endl;
   }
   out.close();*/
}
