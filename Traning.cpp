//Toufiqul Islam Tanmoy
//Learning Programm
#include <bits/stdc++.h>
using namespace std;
int main(){
	int i,j,k,l,m,n; //those all are counter
	int input[8][3]; //input data set 2D array variable 
	float W[3];  //Weight value 
	float sum=0.0; // sum variable to calculate the sum of input and weight
	float thita=0.0; //this is the threshold variable 
	int output=0; //here store the ouptput after compare whith treshold
	ofstream WV,threshold;  //variable for store updated weights and current threshold for using in testing process
	i=0;

	while(i<8){  //Here we are createing Input data set
		j=0;
		k=i;
		while(j<3){
			input[i][j]=k%2;
			
			k=k/2;
			j++;
		}
		i++;
	}
	cout<<"Inputs: X2 X1 X0\n"; //here i am disiplaying the input data set
	for(int i=0;i<8;i++){
		cout<<"For X"<<i<<": ";
		for(int j=2;j>=0;j--){
			cout<<input[i][j]<<"  ";
		}
		cout<<endl;
	}
	/**********Here I  am taking the weights value form user*********/
	cout<<"Enter Weights Value..\n"; 
	for(int i=0;i<3;i++){
		cout<<"Weight["<<i<<"]: ";
		cin>>W[i];
	}
	
	cout<<"\nEnter The Threshold Value: "; //user input for Threshold
	cin>>thita;

	/**************Computing Sum and Compare with Threshold ***********/
	i=0;
	  while(i<8){
	  	sum=0;
	  	j=0;
	  	while(j<3){
	  		sum=input[i][j]*W[j]+sum; //here compute the summation after multiply with input value and weights value
	  		j++;
	  	}
	  	if(sum<thita){ //Here compare with the threshold if less then output will be 0 
	  		output=0;
	  	}
	  	else{
	  		output=1; //other wise output will be 1
	  	}
		/******Here i am chacking that our desired output are equal or not with actual output*******/
	  	if(i<4){ 
	  		if(output==0){ //if desired output equal with actual output then move on next
	  			i++;
	  		}else{
	  			int j=0;
	  			while(j<3){
	  				W[j]=W[j]-input[i][j]; // if output 1 should be 0 => w(t+1)=w(t)-x(t);
	  				j++;
	  			}
	  			i=0;//if the weight value ar update it start again in the beginning
	  		}
	  	}
	  	else{
	  		if (output==1)
	  		{
	  			i++;
	  		}else{
	  			int j=0;
	  			while(j<3){
	  				W[j]=W[j]+input[i][j]; // if output 0 should be 1 => w(t+1)=w(t)+x(t);
	  				j++;
	  			}
	  			i=0;//if the weight value ar update it start again in the beginning
	  		}
	  	}
	  }
	  /********Here I am Displaying the updated Weights**********/
	  cout<<"Updated weights are: [";
	  for (int i = 0; i < 3; ++i)
	  {
	  	cout<<W[i];
	  	if(i<2){cout<<",";}
	  	
	  }
	  cout<<"]";

	  WV.open("WV.txt"); //here i'm opening a text file to store updated weights and threshold


	  for (int i = 0; i <3; ++i)
	  {
	  	WV<<W[i]<<endl; //here i'm writing weights value in text file
	  	
	  }
	  WV<<thita; //here i'm writing threshold value in text file	
}