#include <iostream>

using std::cout;
using std::endl;

int main(){
  int maxlen, maxn;
  maxlen = 0;
  for(int n = 2; n <= 1000; ++n){

    int rest = 1;
    int r0;
    for(int i = 0; i < n; ++i) 
      rest = (rest*10)%n;
    r0 = rest;

    int len = 0;
    do {
      rest = (rest*10)%n;
      len++;
    } while( rest!=r0 );

    if( len > maxlen ){
      maxn = n;
      maxlen = len;
    }

  }
  cout << maxn << endl;
  return 0;
}
