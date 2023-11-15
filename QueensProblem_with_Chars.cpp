#include <iostream>
using namespace std;

int main(){
  int b[8][8] = {0}, c = 0, r;

  b[0][0] = 1;
  int numSolutions = 0;

  newColumn:
    c++;
    if(c == 8) goto print;

    r = -1;

  newRow:
    r++;
    if(r == 8) goto backtrack;

  //row test
  for(int i = 0; i < c; i++){
    if(b[r][i] == 1) goto newRow;
  }

  //up diagonal test
  for(int i = 1; (r - i) >= 0 && (c - i) >= 0; i++){
    if(b[r-i][c-i] == 1) goto newRow;
  }

  //down diagonal test
  for(int i = 1; (r + i) < 8 && (c - i) >= 0; i++){
    if(b[r+i][c-i] == 1) goto newRow;
  }

  b[r][c] = 1;
  goto newColumn;

  backtrack:
    c--;
    if(c == -1) return 0;
    r = 0;
    while(b[r][c] != 1){
      r++;
    }
    b[r][c] = 0;
    goto newRow;

  print:
  	cout << "\nSolution #" << ++numSolutions << ":\n";
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        if(b[i][j] == 0){
            cout << "X ";
        }
        else{
            cout << "Q ";
        }
      }
      cout << endl;
    }
    goto backtrack;

  return 0;


}

