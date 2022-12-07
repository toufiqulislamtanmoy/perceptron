//Toufiqul Islam Tanmoy
//Testing Programm
#include <bits/stdc++.h>
using namespace std;
int main(){
	int i=0;
	float sum=0.0;
	float w[3];//Weights Variable
	int input[3];
	int output;

	/***************************************
				  Traning Data set
					x2	x1	x0
					0 	0 	0
					0 	0 	1
					0 	1 	0
					0 	1   1
					1 	0 	0
					1 	0 	1
					1 	1 	0
					1 	1 	1
	***************************************/
	cout<<"Enter three Digit input only '0' & '1': ";
	for(int i=2;i>=0;i--){
		cin>>input[i]; //Here I am taking Input form user
		
	}
	cout<<"Given Input: ["<<input[2]<<input[1]<<input[0]<<"]\n"; //Displaying User input
	cout<<endl;
	ifstream WVV("WV.txt");//Read data form txt file
	if(!WVV) {
    cout << "Cannot open test.txt file.\n";
    return 1;
  	}else{
	  	for(int i=0;i<3;i++)
	  	{
		  	WVV>>w[i]; //Here Read weights value form txt file
	  	}
	  	WVV>>w[3];//Here Read threshod value form txt file
	  	cout<<"Traning Threshold Is: "<<w[3];

	  	
	  	for (int i = 0; i < 3; ++i)
	  	{
	  		sum=sum+input[i]*w[i];//Calculate Total sum
	  	}	
	  	if(sum<w[3]){ //compare sum is less than threshold value or not
	  		output=0;
	  		cout<<"\nIt is a Member of Class A\n";
	  	}else{
	  		output=1;
	  		cout<<"\nIt is a Member of Class B\n";
	  	}
  	}
}
