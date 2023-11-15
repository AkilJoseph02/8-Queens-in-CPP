#include <iostream>
#include <cmath>
using namespace std;

int solutions = 1;

bool queenOk(int queenArray[], int col){
  for(int i = 0; i < col; i++){
    if( (queenArray[i] == queenArray[col]) || ((col - i) == abs(queenArray[col] - queenArray[i])) ) {
      return false;
    }
   }

	return true;
}

void printArray(int queenArray[]){

    cout << "Solutions #" << solutions++ << ":\n" ;
  for(int i = 0; i < 8; i++){
    cout << queenArray[i] << " ";
  }
  cout << endl;
}



int main(){
  int q[8] = {0};
  int c = 0;
  q[0] = 0;

	while(c>=0){
	    c++;
	    if(c==8){
	    	printArray(q);
	    	c--;
	    	if(c == -1){
	    		return -1;
	    		q[c]++;
			}
		}
	    else{
	        q[c]=-1;
	    }
	   while(c>=0){
	       q[c]++;
           if (q[c] == 8){
           	c--;
           	if(c == -1){
	    		return -1;
	    		q[c]++;
			}
	       }
	       else if(queenOk(q,c) == true){
	       	break;

		   }

	    }
	}
}
