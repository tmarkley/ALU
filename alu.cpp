// Program that simulates a 1-bit ALU and gives the output for all 
//   combinations.  T. Markley, 3/2012

#include <iostream>
#include "blogic.H"
using namespace std;

int alu(int f0, int f1, int inva, int ena, int enb, int c_i, int a, int b){
  // return the output bit-shifted one place plus the carry out to simulate
  //   the output from the ALU using the parameters of the function as
  //   input values
  return (((bor(
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
		      band(f0,f1))) << 1))
	  + (bor(
		 band(
		      c_i,
		      bxor(
			   band(b,enb),
			   bxor(inva,band(a,ena))),
		      band(f0,f1)),
		 band(
		      band(b,enb),
		      bxor(inva,band(a,ena)),
		      band(f0,f1)))));
}

void print_call(int f0, int f1, int inva, int ena, int enb, int c_i, int a, int b) {
  // again, the parameters are the input values, and this function prints
  //   out the values of the apu function call for each combination
  
  cout << "alu(" << f0 << ", " << f1 << ", " << inva << ", " << ena << ", " << enb << ", ";
  cout << c_i << ", " << a << ", " << b << ") --> " << alu(f0,f1,inva,ena,enb,c_i,a,b);
  cout << endl;

}

void print_section(int f0, int f1, int inva, int ena, int enb) {
  // this function prints 8 lines of output for the different combinations
  //   of A, B, and the carry in value

  // this loop uses bit shifts to send every combination of A, B, and c_i
  for(int n=0; n < 8; n++) {
    print_call(f0,f1,inva,ena,enb,(n >> 2),((n >> 1) & 1), n & 1);
  }

}

int main() {
 
  // this loop uses bit shifts to produce every combination of the ALU output
  //   for the control lines
  for (int n=0; n < 32; n++) {
    cout << endl;
    cout << "F0=" << (n>>4) << ", F1=" << ((n>>3) & 1) << ", ";
    cout << "INVA=" << ((n>>2) & 1) << ", ";
    cout << "ENA=" << ((n>>1) & 1) << ", ";
    cout << "ENB=" << (n & 1) << endl;
    print_section((n>>4),((n>>3) & 1),((n>>2) & 1),((n>>1) & 1),(n & 1));
  }

}
