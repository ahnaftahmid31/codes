#include<bits/stdc++.h>
using namespace std;

#define N 1003

struct lang {
  int no_states;
  char language;
  lang(int _no_states, char _language) {
    no_states = _no_states;
    language = _language;
  }
  bool operator < (const lang &p) const {
    if(no_states == p.no_states) {
      return language > p.language;
    }
    return no_states < p.no_states;
  }
};


char adj[N][N]; // adj matrix
bool vis[N][N]; // is visited or not
int langs[29];  // langs[i] have i-th language's state number, i = 1 => a, 2 => b ....
int rows, cols;
priority_queue <lang> pq; // priority queue for sorting out the languages
//direction array assuming graph is |-->
//                                  V
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// it does exactly what it's named
void reset() {
  for(int i = 0; i<27; i++) {
    langs[i] = 0;
  }
  for(int r = 0; r < rows; r++) {
    for(int c = 0; c < cols; c++) {
      vis[r][c] = false;
    }
  }
}

void dfs(int r, int c, char ch) {
  if(r >= 0 && c >= 0 && r < rows && c < cols) {
    if(!vis[r][c] && adj[r][c] == ch) {
      vis[r][c] = true;
      for(int i = 0; i < 4; i++) {
        dfs(r + dy[i], c + dx[i], ch);
      }
    }
  }
}

// does the main work, more like dfs initializer
void rank_em() {
  for(int r = 0; r < rows; r++) {
    for(int c = 0; c < cols; c++) {
      if(!vis[r][c]) {
        char ch = adj[r][c];
        dfs(r, c, ch);
        int alpha_no = ch - 'a' + 1;
        langs[alpha_no]++;
      }
    }
  }
  // ranking the languages
  for(int i = 1; i <= 26; i++) {
    if(langs[i] > 0) {
      char ch = i + 'a' -1; // character represntation of i-th language
      pq.push(lang(langs[i], ch)); // langs[i] = how many states i-th language speak
    }
  }
}

void print_output(int case_no) {
  cout << "World #" << case_no << endl;
  while(!pq.empty()) {
    lang lg = pq.top();
    pq.pop();
    cout << lg.language << ": " << lg.no_states << endl;
  }
}

int main() {
  int cases;
  scanf("%d", &cases);
  for(int case_no = 1; case_no <= cases; case_no++) {
    scanf("%d %d", &rows, &cols);
    reset();

    for(int r = 0; r<rows; r++) {
      string str;
      cin >> str;

      for(int c = 0; c < cols; c++) {
        adj[r][c] = str[c];
      }
    }
    rank_em();
    print_output(case_no);
  }
  return 0;
}
