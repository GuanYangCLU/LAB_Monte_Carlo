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

void lsdou()
{ 
   gROOT->Reset();

   int rin_num=10,t_num=1,i=0,j_num=0;//rin_num:remain_number
   const Int_t tt_num=t_num*10+1;
   float m[10]={0},n[10]={0},m_num[tt_num]={0},n_num[tt_num]={0},tmp[2]={0},pede[1]={0},*x,*y,*xer,*yer; 
   float ner[10]={0},nern[tt_num]={0}; 
   ifstream fin;        
   fin.open("/home/tgs416/programfiles/geant4/g4work/myN06/20/m.txt");
   for(int loop=0;loop<10;loop++)
    {
          for(int l=0;l<2;l++)
          {
                fin >> tmp[l];
                m_num[loop]=tmp[0];
                n_num[loop]=tmp[1];
           }
     }
     fin.close();
/////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
   gROOT->Reset();
   c3 = new TCanvas("c3","A Simple Graph with error bars",200,10,700,500);
   c3->SetGrid();


   gr3 = new TGraph(10,m_num,n_num);
   gr3->SetMarkerColor(4);
   gr3->SetMarkerStyle(20);
   gr3->SetMarkerSize(0.65);
   
   TF1 *eyfitf = new TF1("eyfitf","expo",m_num[0],n_num[9]);
   eyfitf->SetLineColor(3);
   gr3->Fit("eyfitf"); 
   double el1=eyfitf->GetParError(1);
 
  
   Double_t length=-1/eyfitf->GetParameter(1);
   el1=sqrt(length)*el1;
 
  // gPad->SetLogy(); //Change Y axis to log scale.
    gr3->GetXaxis()->SetTitle("length(m)");
    gr3->GetYaxis()->SetTitle("ADC Channels");
    gr3->Draw("AP");

   TPaveStats *ptstats = new TPaveStats(0.6,0.8,0.9,0.9,"brNDC");
   ptstats->SetName("Fit Results");
   TText *text = ptstats->AddText("Attenuation Length");
   text->SetTextSize(0.034);
   text = ptstats->AddText(Form("%.2f (+/-) %.2f (m)",length,el1));
   ptstats->Draw();
   c3->SaveAs("/home/tgs416/programfiles/geant4/g4work/myN06/20/fit_20.png");
   ofstream out1("/home/tgs416/programfiles/geant4/g4work/myN06/20/m.txt",ios::out&&ios::app);
   out1<<"Attenuation Length"<<"\t"<<length<<"\t"<<el1<<endl;
   out1.close();


   c3->Update();
}
