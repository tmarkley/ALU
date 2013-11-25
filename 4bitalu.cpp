#include <iostream>
#include "blogic.H"
using namespace std;

int output(int f0, int f1, int inva, int ena, int enb, int c_i, int a, int b){
  // this function returns the output of a 1-bit ALU using the parameters
  //   as the control lines and input lines
  return (bor(
	      band(
		   band(
			bxor(inva, band(a,ena)),
			band(b,enb)),
		   band(
			bnot(f0),
			bnot(f1))),
	      band(
		   bor(
		       bxor(inva, band(a,ena)),
		       band(b,enb)),
		   band(bnot(f0),f1)),
	      band(
		   bnot(band(b,enb)),
		   band(f0,bnot(f1))),
	      band(
		   bxor(
			c_i,
			bxor(
			     band(b,enb),
			     bxor(inva,band(a,ena)))),
		   band(f0,f1))));
}

int carry_out(int f0, int f1, int inva, int ena, int enb, int c_i, int a, int b){
  // this function returns the carry_out of a 1-bit ALU using the parameters
  //   as the control lines and input lines
  return (bor(
	      band(
		   c_i,
		   bxor(
			band(b,enb),
			bxor(inva,band(a,ena))),
		   band(f0,f1)),
	      band(
		   band(b,enb),
		   bxor(inva,band(a,ena)),
		   band(f0,f1))));
}

void fourbitalu(int f0, int f1, int inva, int ena, int enb, int c_i, int a0, int b0, int a1, int b1, int a2, int b2, int a3, int b3) {
  // this function prints out the result of each ALU in a 4-bit ALU based 
  //   on the values of the parameters for the control lines and input
  
  cout << "(";
  //carry out value for the most significant bit
  cout << carry_out(f0,f1,inva,ena,enb,
		    carry_out(f0,f1,inva,ena,enb,
			      carry_out(f0,f1,inva,ena,enb,
					carry_out(f0,f1,inva,ena,enb,c_i,a0,b0),
					a1,b1),
			      a2,b2),
		    a3,b3) << ",";
  //output from alu3 (farthest to the right in the diagram)
  cout << output(f0,f1,inva,ena,enb,
		 carry_out(f0,f1,inva,ena,enb,
			   carry_out(f0,f1,inva,ena,enb,
				     carry_out(f0,f1,inva,ena,enb,c_i,a0,b0),
				     a1,b1),
			   a2,b2),
		 a3,b3) << ",";
  //output from alu2
  cout << output(f0,f1,inva,ena,enb,
		 carry_out(f0,f1,inva,ena,enb,
			   carry_out(f0,f1,inva,ena,enb,c_i,a0,b0),
			   a1,b1),
		 a2,b2) << ",";
  //output from alu1
  cout << output(f0,f1,inva,ena,enb,
		 carry_out(f0,f1,inva,ena,enb,c_i,a0,b0),
		 a1,b1) << ",";
  //output from alu0
  cout << output(f0,f1,inva,ena,enb,c_i,a0,b0) << ")"<< endl;
}

int main() {
  
  //since there are way too many combinations of a 4-bit ALU, I do a user
  //  input so that you can choose what to use
  int f0,f1,inva,ena,enb,inc,a0,a1,a2,a3,b0,b1,b2,b3;
  cout << "F0="; cin >> f0;
  cout << "F1="; cin >> f1;
  cout << "INVA="; cin >> inva;
  cout << "ENA="; cin >> ena;
  cout << "ENB="; cin >> enb;
  cout << "INC="; cin >> inc;
  cout << "A0="; cin >> a0;
  cout << "B0="; cin >> b0;
  cout << "A1="; cin >> a1;
  cout << "B1="; cin >> b1;
  cout << "A2="; cin >> a2;
  cout << "B2="; cin >> b2;
  cout << "A3="; cin >> a3;
  cout << "B3="; cin >> b3;
  cout << endl << "Output is in the form (Carry Out,Out3,Out2,Out1,Out0):";
  cout << endl << endl;
  cout << "4-bitalu("<<f0<< ","<<f1<<","<<inva<<","<<ena<<","<<enb<<",";
  cout << inc<<","<<a0<<","<<b0<<","<<a1<<","<<b1<<","<<a2<<","<<b2<<",";
  cout << a3<<","<<b3<<") --> ";
  fourbitalu(f0,f1,inva,ena,enb,inc,a0,b0,a1,b1,a2,b2,a3,b3);
  cout << endl;

}
