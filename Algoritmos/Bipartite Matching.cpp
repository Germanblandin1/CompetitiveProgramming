// This code performs maximum bipartite matching.
//
// Running time: O(|E| |V|) -- often much faster in practice
//
//   INPUT: w[i][j] = edge between row node i and column node j
//   OUTPUT: mr[i] = assignment for row node i, -1 if unassigned
//           mc[j] = assignment for column node j, -1 if unassigned
//           function returns number of matches made

#include<bits/stdc++.h>
using namespace std;
#define llenar(arr,val) memset(arr,val,sizeof(arr))

int N,M; //   N:tam lado izquier, M: tam lado derecho
bool w[MAXN][MAXN];
int mr[MAXN];
int mc[MAXN];
bool seen[MAXN];

bool FindMatch(int i) {
  for (int j = 0; j < M; j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j])) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching() {
	for(int i=0;i<N;i++) mr[i]=-1;
	for(int i=0;i<M;i++) mc[i]=-1;
	int ct = 0;
	for (int i = 0; i < w.size(); i++) {
		llenar(seen,false);
		if (FindMatch(i)) ct++;
	}
	return ct;
}