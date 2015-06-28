#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::string;
using std::endl;

template<class B>
int myswap(B& i, B& j) {
  B temp = i;
  i = j;
  j = temp;
  return 0;
}

template<class B>
int myreverse(B begin, B end) {
  while ((begin != end) && (begin != --end)) {
    myswap(*begin++, *end);
  }
  return 0;
}

/* returns true if next lex permuation can be found and tranforms it
otherwise transform into original sorted range and return false */ 
template<class B>
bool next_perm(B begin, B end) {
  if (begin == end) { // []
    return false; 
  } 
  B i = end;
  if (begin == --i) { //[i]
    return false;
  }

  while (true) {
    B j = i--; // [...,i,j,...]

    if (*i < *j) {
      B k = end;
      while (!(*i < *--k))
        ;
      myswap(*i, *k);
      myreverse(j, end);
      return true;
    }
    
    if (i == begin) { // [i,j,...]
      myreverse(begin, end);
      return false;
    }
  }
}


int main() {
  string s = "654321";
  string si = s;
  do {
    cout << s << endl;
    //std::next_permutation(s.begin(), s.end());
    next_perm(s.begin(), s.end());
  } while (s != si);

  //reverse(s.begin(), s.end());
  //cout << s << endl;
  return 0;
}
