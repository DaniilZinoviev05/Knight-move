#include <iostream>
#include <vector>
#include <iomanip>

using std::cout;
using std::cin;
using std::vector;
using std::endl;

void printBoard(vector<vector<int>> &board){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            printf(" %2d", board[i][j]);
        }
        printf("\n");
    }
}

bool visited(vector<vector<int>> &board){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if (board[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}

bool traversingFunction(int x, int y, int c, vector<vector<int>> &board, int (*Moves)[2], char t){
    board[x][y]++;
    c++;
    int xMove, yMove;

    if (t == 'y'){
        cout << "step: " << c << " points: " << "(x:" << x << "; y:" << y << ")"<< endl;
    }

    cout << endl;
    printBoard(board);
    cout << endl;

    for(int i = 0; i < 8; i++){
        xMove = x + Moves[i][0];
        yMove = y + Moves[i][1];

        if(xMove < 8 && yMove < 8 && yMove >= 0 && xMove >= 0 && board[xMove][yMove] == 0){
            traversingFunction(xMove, yMove, c, board, Moves, t);
            if(visited(board)){
                return true;
            }
            else {
                traversingFunction(x, y, c, board, Moves, t);
            }
        }
    }
    return false;
}

int main(void) {
    int x, y;
    char t;
    cout << "Enter x value: ";
    cin >> x;
    cout << "Enter y value: ";
    cin >> y;
    cout << "display moves?(y/n)";
    cin >> t;
    cout << endl;
    if (t != 'y' && t != 'n') return 0;
    else {
        vector<vector<int>> board(8, vector<int>(8, 0));
        int Moves[8][2] {
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
            {1, 2}, {-1, 2}, {1, -2}, {-1, -2}
        };

        if(traversingFunction(x, y, 1, board, Moves, t)){
            cout << "Traversing is ended with success." << endl;
        }
        else {
            cout << "Traversing is ended with failure." << endl;
        }
        cout << "BOARD:" << endl;
        printBoard(board);
    }
}
