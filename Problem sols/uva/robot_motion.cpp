#include<bits/stdc++.h>
using namespace std;

#define MAX 1003
#define N 1
#define S 2
#define E 3
#define W 4

int adj[MAX][MAX];
int vis[MAX][MAX];
bool hasCycle = false;
int steps_before_loop = 0;
int steps_of_loop = 0;
int steps = 0;

void reset(int r, int c) {
	for(int i = 0; i<r; i++){
		for(int j = 0; j<c; j++){
			adj[i][j] = 0;
			vis[i][j] = 0;
			hasCycle = false;
			steps = 0;
			steps_before_loop = 0;
			steps_of_loop = 0;
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

void print_visited(int r, int c){
  // i = row, j = col
  for(int i = 0; i<r; i++){
		for(int j = 0; j<c; j++){
			cout << "(" << j << ", " << i << "): " << vis[i][j] << " ";
		}
		puts("");
	}
	puts("");
}

// x = cols, y = rows
void robot_motion(int rows, int cols, int x, int y) {

	steps++;
	vis[y][x] = steps;

	//updating coordinates (system is |-->)
	//                                V
	if(adj[y][x] == N) y--;
  else if(adj[y][x] == S) y++;
	else if(adj[y][x] == E) x++;
	else if(adj[y][x] == W) x--;

	//after updating coordinates
	if(x < 0 || y < 0 || x >= cols || y >= rows){
    return;
	}
	else if(vis[y][x] > 0) {
		hasCycle = true;
		steps_before_loop = vis[y][x] - 1;
		steps_of_loop = steps - steps_before_loop;
		return;
	}
	else robot_motion(rows, cols, x, y);

}


int main(){
	while(true){
		int rows, cols, s;
		scanf("%d %d %d", &rows, &cols, &s); // s = source

		if(rows == 0 && cols == 0 && s == 0) break;

		reset(rows, cols);

    for(int i = 0; i<rows; i++){
			string str;
			cin >> str;
			int length = str.length();

			for(int j = 0; j<length; j++){

				if(str[j] == 'N') adj[i][j] = N;
				else if(str[j] == 'S') adj [i][j] = S;
				else if(str[j] == 'E') adj [i][j] = E;
				else adj [i][j] = W;
			}
		}

		robot_motion(rows, cols, s-1, 0);
		if(hasCycle){
			printf("%d step(s) before a loop of %d step(s)\n", steps_before_loop, steps_of_loop);
		}
		else{
			printf("%d step(s) to exit\n", steps);
		}
  }
}
