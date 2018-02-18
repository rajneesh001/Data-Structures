#include <iostream> 
#include <cstdlib> 
#include <cctype>
#include<cmath>
using namespace std; 

const int SIZE = 8; 
const string EMPTY = "_"; 

void display_game (string board[SIZE][SIZE])
{
cout<<endl;
cout << "Current board:" << endl;
for (int row = 0; row < SIZE; row++) {
for (int col = 0; col < SIZE; col++){
cout << board[row][col];

} cout << endl;
}cout << endl;
}

bool valid_move (string board[SIZE][SIZE], int from_row, int from_col, int to_row, int to_col)
{
   string element =  board[from_row][from_col];
   element = element[2];
   int move_x = to_row - from_row;
   int move_y = to_col - from_col;

  if((to_row > 0 || to_row < (SIZE -1)) || (to_col > 0 || to_col < (SIZE -1)))
{
  	 if(element == "K") 							// king validation done
   {
   		
   		if (abs(move_x) <= 1 && abs(move_y) <= 1)
            return true;

        if (abs(move_x) == 0 && abs(move_y) == 2)              // Castling - AND has higher priority than OR
        {
        	if((from_row == 0 && from_col == 4) ||(from_row == 7 && from_col == 4))
                return true;
        }
        return false;
   }
   else if(element == "Q")  		// Queen validation done
   {
   	
   		if ((abs(move_x) == abs(move_y)) || (move_x == 0 ) || (move_y == 0))  		// # Diagonal and straight moves
            return true;

        return false;
   }
   else if(element == "R")  		// Rook(Elephant) validationn done
   {
   			
        if (move_x == 0 || move_y == 0)
            return true;

        return false;

   }
   else if(element == "H")  		// Horse validation done
   {
   		
   		if ((abs(move_x) == 1 && abs(move_y) == 2) || (abs(move_x) == 2 && abs(move_y) == 1))    // L shaped movement
            return true;

        return false;
   }
   else if(element == "B")  		// Bishop(Camel) validation done
   {
   			
   		if (abs(move_x) == abs(move_y))    // only diagonal movement
            return true;

        return false;
   }
   else if(element == "P") 		// Pawn validation
   {
   	
   		if ((abs(move_y) == 1)  && (move_x == 1))    // player 1
            return true;

        															// # Player(2) capture
        if (abs(move_y) == 1 && move_x == -1)   
            return true;

      																//  # Player(1) first move
        if ((from_row == 1) && (move_y == 0) && (move_x == 2))
            return true;

       																	// # Player(2) first move
        if (from_row == 6 && move_y == 0 && move_x == -2)
            return true;

       																		// # Player(1) move
        if (move_y == 0 && move_x == 1)
            return true;

     																		//   # Player(2) move
        if  (move_y == 0 && move_x == -1)
            return true;

        return false;
   }
}
else
{
return false;
}

if(board[to_row][to_col] != "_")
{
// if the color of the occupying piece matches the color of the piece
// that's trying to move
	string s1 = board[from_row][from_col];
	string s2 = board[to_row][to_col];
if(s1.compare(s2) ==0)
{
return false;
} 
}
return (true);
}
void update_board (string board[SIZE][SIZE], int from_row, int from_col, int to_row, int to_col)
{
board[to_row][to_col] = board[from_row][from_col];
board[from_row][from_col] = " _ ";
}

void moderate_game (string board[SIZE][SIZE])
{
// Read while more good input 
while (cin.good()) {
char move_type;
cout << "Enter next move: "<<endl;

int from_row, from_col, to_row, to_col;
cin >> from_row >> from_col >> to_row >> to_col;

if (! valid_move(board, from_row, from_col, to_row, to_col)) {
cerr << "Invalid move" << endl;
}
else {
update_board(board, from_row, from_col, to_row, to_col);
display_game(board);
}
}
}

int main ()
{
string board[SIZE][SIZE] = // Check board with White on top (uppercase)
{
{" WR ", " WH ", " WB ", " WQ ", " WK ", " WB ", " WH ", " WR "},
{" WP ", " WP ", " WP ", " WP ", " WP ", " WP ", " WP ", " WP "},
{" _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ "},
{" _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ "},
{" _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ "},
{" _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ ", " _ "},
{" BP ", " BP ", " BP ", " BP ", " BP ", " BP ", " BP ", " BP "},
{" BR ", " BH ", " BB ", " BQ ", " BK ", " BB ", " BH ", " BR "},


};

display_game(board);
moderate_game(board);
#if defined(WIN32)
system("PAUSE"); 
#endif
return (0);
}
