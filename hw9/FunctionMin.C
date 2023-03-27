///////////////////////////
//minimum of a func////////
///Golden Section Search///
////used AI////////////////
#include<iostream>
using namespace std;


//my function 
double myFunc(double x){

	return 3*sin(x)*TMath::Power(cos(x), 3)/x;//function
}
//getting minimum using golden section rule
double getMinima_GSS(double a, double b, double minWidth){
       
	const double phi = (1 + TMath::Sqrt(5))/2; //golden ratio
        double x1 = b- (b-a)/phi;
        double x2 = a+ (b-a)/phi;
 //loop to get minima

	 while(TMath::Abs(b-a) > minWidth){
         if(myFunc(x1) < myFunc(x2)){


		 //redifining points
                 b = x2; 
                 x2 = x1;
                 x1 = b- (b-a )/phi;
         }
         else{
        //redefining points
         a = x1;
         x1=x2;
         x2 = a + (b-a)/phi;// min point

         }
  }

return (a+b)/2; //minimum
}

void FunctionMin(){


	double xa= 2.100, xb= 4.3, wd=0.000001; 

double minFn = getMinima_GSS(xa, xb, wd); 


cout<<"func min is: "<<minFn<<endl;


//creat canvas to make plot

auto *c = new TCanvas();

auto *fn = new TF1("fn", "myFunc(x)", 2.1, 4.3);
TH1 *hs = fn->GetHistogram();//switched to histogram to label the axis

hs->GetXaxis()->SetTitle("Angle(rad)");
hs->GetYaxis()->SetTitle("Func Value");
hs->SetTitle("Func: 3(Sin(x)Cos(x)^3)/x");	
fn->Draw();

c->SaveAs("miniFunc.pdf");
}//end
