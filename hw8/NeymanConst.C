//////////////////////////////
//source code: Prof. Rogan////
//Neyman Construction/////////
//shoukat/////////////////////
//////////////////////////////
#include<iostream>
#include"TRandom3.h"
using namespace std;

int NeymanConst(int num_Exp){

 //declare a histograms 
auto *hs = new TH2D("hs","True verses measured value of alpha", 1000, -10, 10, 1000, -10, 10);
	int num_measure= 1;
        double alpha_exp=0, alpha_true, alpha_fit;
        double sigma=1;//it can be changed	

//loop around true alpha

for(int i=-200; i<200; i++){

	alpha_true = i/20.0;//range is -10to10

	//looping over number of experiments
	for(int exp=0; exp<num_Exp; exp++){
	
		alpha_fit = 0.;

	       //loop over the measurements 
	       for(int ms=0; ms<num_measure; ms++){
	       
                double num =  gRandom->Gaus(alpha_true , sigma );	
	       alpha_fit += num; 
	       }
	//take the average for best fit
	alpha_fit = alpha_fit/double(num_measure);
	
	hs->Fill(alpha_true, alpha_fit);
	
	}

  }
	//creat canvas
	auto *c = new TCanvas();
        c->SetGridx();
        c->SetGridy();	

	hs->GetXaxis()->SetTitle("True Alpha");
	hs->GetYaxis()->SetTitle("Measured Alpha");
        hs->SetMarkerStyle(20);
	hs->SetStats(0);
	hs->Draw("colz");



c->SaveAs("NeymanCon.pdf");

return 0;
}
