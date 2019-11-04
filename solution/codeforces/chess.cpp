#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
int abslt(int a) {
  if (a < 0) a = -a;
  return a;
}

int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

int level[64 + 3][64 + 3];

int king(int r1, int c1, int r2, int c2) {
  queue<pii> q;
  q.push({r1, c1});
  for (int i = 1; i<=8; i++) {
    for (int j = 1; j<=8; j++) {
      level[i][j] = -1;
    }
  }
  level[r1][c1] = 0;

  while (!q.empty()) {
    pii top = q.front();
    q.pop();
    int uy = top.first;   // row corresponds to y-axis
    int ux = top.second;  // column corresponds to x-axis

    for (int i = 0; i < 8; i++) {
      int vx = ux + dx[i];
      int vy = uy + dy[i];

      if (vx >= 1 && vy >= 1 && vx <= 8 && vy <= 8) {
        // column -> x, row -> y and our array is in level[row][col] format
        if (level[vy][vx] == -1) {
          level[vy][vx] = level[uy][ux] + 1;
          if (vy == r2 && vx == c2) {
            return level[r2][c2];
          }
          q.push(pii(vy, vx));
        }
      }
    }
  }
  return 0;
}

int bishop(int r1, int c1, int r2, int c2) {
  if (abslt(r1 - c1) % 2 == 0) {
    if (abslt(r2 - c2) % 2 == 0) {
      if (abslt(r1 - r2) == abslt(c1 - c2)) {
        return 1;
      } else return 2;
    } else return 0;
  } else {
    if (abslt(r2 - c2) % 2 != 0) {
      if (abslt(r1 - r2) == abslt(c1 - c2)) {
        return 1;
      } else return 2;
    } else return 0;
  }
}

int rook(int r1, int c1, int r2, int c2) {
  if (r1 == r2 || c1 == c2) {
    return 1;
  } else {
    return 2;
  }
}

int main() {
  int c1, c2, r1, r2;
  scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
  printf("%d %d %d\n", 
        rook(r1, c1, r2, c2),
        bishop(r1, c1, r2, c2),
        king(r1, c1, r2, c2)
  );
}