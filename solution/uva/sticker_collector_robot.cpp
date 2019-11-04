#include<bits/stdc++.h>
using namespace std;

#define MAX 102
#define N 1 // north
#define S 2 // south
#define L 3 // east
#define O 4 // west
#define D 5 // turn 90 deg right
#define E 6 // turn 90 deg left
#define F 7 // forward 1 cell
#define piller 12
#define sticker 11
#define normal 10



int adj[MAX][MAX];
string inst;


void reset(int r, int c) {
  inst = "";
	for(int i = 0; i<r; i++){
		for(int j = 0; j<c; j++){
			adj[i][j] = 0;
		}
	}
}

void print_graph(int r, int c){
  //i = row, j = col
	for(int i = 0; i<r; i++){
		for(int j = 0; j<c; j++){
			cout << "(" << j << ", " << i << ")-> " << adj[i][j] << " ";
		}
		puts("");
	}
	puts("");

}

// x = cols, y = rows
int robot_motion(int rows, int cols, int *x, int *y, int dir) {

	int hasSticker = 0;
	int tx = *x;
	int ty = *y;
	//updating temp coordinates (system is |-->)
	//                                     V
	if(dir == N) 			ty--;
  else if(dir == S) ty++;
	else if(dir == L) tx++;
	else if(dir == O) tx--;

	//after updating temp coordinates
	if(tx < 0 || ty < 0 || tx >= cols || ty >= rows) { }
	else{
		//updating real coordinates
		if(adj[ty][tx] == normal) {
			*x = tx;
			*y = ty;
		}
		else if(adj[ty][tx] == piller){
			// don't move , stay where you are
		}
		else if(adj[ty][tx] == sticker){
			adj[ty][tx] = normal;
			*x = tx;
			*y = ty;
			hasSticker = 1;
		}
	}
	return hasSticker;
}
int collect_sticker(int rows, int cols, int sx, int sy, int dir){
	int sticker_count = 0;
	int inst_length = inst.length();

	for(int i = 0; i<inst_length; i++){
		char c = inst[i];

		if(c == 'D') {
			if(dir == O)      dir = N;
			else if(dir == L) dir = S;
			else if(dir == S) dir = O;
			else if(dir == N) dir = L;
		}

		else if(c == 'E') {
			if(dir == O)      dir = S;
			else if(dir == L) dir = N;
			else if(dir == S) dir = L;
			else if(dir == N) dir = O;
		}

		else if(c == 'F') {
			// robot_motion(...) returns the number of stickers in the selected coordinate,
			// for this problem it will always be 1 for each coordinate if sticker exists.
			sticker_count += robot_motion(rows, cols, &sx, &sy, dir); 
		}
	}

	return sticker_count;
}


int main(){
	while(true){
		int rows, cols, queries;
		scanf("%d %d %d", &rows, &cols, &queries); // s = source

		if(rows == 0 && cols == 0 && queries == 0) break;

		reset(rows, cols);
		int sx = -1, sy = -1;
		int dir;

    for(int i = 0; i<rows; i++){
			string str;
			cin >> str;
			int length = str.length();

			for(int j = 0; j<length; j++){

				if(str[j] == '.')      { adj[i][j] = normal;}
				else if(str[j] == '*') { adj[i][j] = sticker;}
				else if(str[j] == '#') { adj[i][j] = piller;}

				else if(str[j] == 'S') { adj[i][j] = normal; sx = j; sy = i; dir = S;}
				else if(str[j] == 'L') { adj[i][j] = normal; sx = j; sy = i; dir = L;}
				else if(str[j] == 'O') { adj[i][j] = normal; sx = j; sy = i; dir = O;}
				else if(str[j] == 'N') { adj[i][j] = normal; sx = j; sy = i; dir = N;}
				
			}
		}

		cin >> inst;

		int stickers = collect_sticker(rows, cols, sx, sy, dir);
		cout << stickers << endl;
  }
	return 0;
}
