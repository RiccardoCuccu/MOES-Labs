void mult_acc(int a[4], int b[4], int &dout);
#include <iostream>
using namespace std;
#include "mc_scverify.h"
CCS_MAIN(int argv, char *argc){
int a[4] = {1,2,3,4}; 
int b[4] = {1,1,1,1};
int dout;

	for(int i=0;i<10;i++){//run multiply-accumulate 10 times
		CCS_DESIGN(mult_acc(a,b,dout));
		cout << "Result = " << dout << endl;
		for(int j=0;j<4;j++){//change mac data each call
			a[j] = a[j]*2;
			b[j] = b[j]*(j+1);
		}
	}
    CCS_RETURN(0);
}
 