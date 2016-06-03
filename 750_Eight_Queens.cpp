#include <iostream>
using namespace std;
const int N = 8;
int a, b, TC, soln;
int board[N];

bool canPlace(int queen, int row)
{
	for (int i = 0; i < queen; i++)
	{
		int prev = board[i];
		if (prev == row || prev == row - (queen - i) || prev == row + (queen - i)){return false;}
	}
	return true;
}

void NQueens(int queen)
{
	if (queen == N) {
    if(board[b - 1] != a - 1){
      return;
    }
    printf("%2d      ", soln++);
    for(int i=0;i<8;i++){
      if(i!=0) printf(" ");
      printf("%d",board[i]+1);
    }
		printf("\n");
	}else{
		for (int i = 0; i < N; i++) {
			if (canPlace(queen, i)){
				board[queen] = i;
				NQueens(queen + 1);
			}
		}
	}
}

int main()
{
  bool first = true;
  scanf("%d", &TC);
  while(TC--){
    scanf("%d %d", &a, &b);
    soln = 1;
    if(!first)cout << endl;
    first = false;
    cout << "SOLN       COLUMN" << endl;
    cout << " #      1 2 3 4 5 6 7 8\n" << endl;
    NQueens(0);
  }
	return 0;
}
