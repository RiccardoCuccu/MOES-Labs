#pragma design top
void mult_acc(int a[4], int b[4], int &dout){
  int acc=0;
  MAC:for(int i=0;i<4;i++){
    acc += a[i]*b[i];
  }
  dout = acc;
}	
