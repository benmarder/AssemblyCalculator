#include <iostream>
#include<stdio.h>
using namespace std;


int multiplication(int num_1, int num_2);
int addition(int num1, int num2);
int subtraction(int num1,int num2);
int division (int num1 ,int num2);

void main(){
	char cc=0;
	int num=0,num2,num1=0;
	int(*operator1_ptr)(int, int) ;
	int(*operator2_ptr)(int, int) ;
	int flag=0;
	operator1_ptr=addition;
	while(cc != 'q'){	
		cin>>cc;
		if(cc>47 && cc<58){
			num=10*num +cc-48;
			flag =0;
		}
		else if(cc>41 && cc<48){
			switch (cc) {
			case 42:
				operator2_ptr =multiplication;
				break;
			case 43:
				operator2_ptr = addition;
				break;
			case 44	:
				cout<<"invalid input";
				num=0;
				num1=0;
				operator1_ptr=addition;
				break;
			case 45:
				operator2_ptr = subtraction;
				break;
			case 46:
				cout<<"invalid input";
				num=0;
				num1=0;
				operator1_ptr=addition;
				break;
			case 47:
				operator2_ptr = division;
			}
			if(flag==1)
				operator1_ptr=operator2_ptr;
			else{
				num2=num;
				num1= operator1_ptr(num1,num2);
				operator1_ptr= operator2_ptr;
			}
			flag=1;
			num=0;
		}
		else if(cc == '='){
			num2=num;
			if(flag==1)
				cout<<operator1_ptr(num1,num1)<<"\t";
			else
				cout<<operator1_ptr(num1,num)<<"\t";
			num=0;
			num1=0;
			operator1_ptr=addition;

		}
		else {
			cout<<"invalid input";
			num=0;
			num1=0;
			operator1_ptr=addition;
		}
	}
	cout<<"byeee";
}
int multiplication(int num_1, int num_2){
	int temp=num_1;
	num_1=0;
	while(num_2 != 0){
		num_1=num_1+temp;
		num_2-- ;
	}
	return num_1;
}
int addition(int num1, int num2){
	return num1+num2;
}

int subtraction(int num1,int num2){
	return num1-num2;
}
int division (int num1 ,int num2){
	int remain;
	int counter=0;
	if(num2 == 0){
		printf("math error");
		return 0 ;// actually returning to beginning not 0.
	}

	else if(num1<0 ){
		num1=-num1;
		return -(division(num1,num2));
	}
	else {
			while (num1>0){
				num1=num1-num2;
				if (num1>=0)
					counter ++;
			}
			if(num1==0)
				remain=0;
			else 
				remain= num1+num2;
		}



		return counter;
}



