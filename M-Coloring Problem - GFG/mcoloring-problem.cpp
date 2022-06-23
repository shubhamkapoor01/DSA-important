// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool solve(bool graph[101][101], int idx, int n, int m, vector<int>& color) {
    if (idx == n) {
        return true;
    }
    
    for (int i = 1; i <= m; i ++) {
        bool doable = true;
        for (int j = 0; j < n; j ++) {
            if (idx != j && graph[idx][j] && color[j] == i) {
                doable = false;
                break;
            }
        }
        if (doable) {
            color[idx] = i;
            if (solve(graph, idx + 1, n, m, color)) {
                return true;
            }
            color[idx] = 0;
        }
    }
    
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> color(n, 0);
    return solve(graph, 0, n, m, color);
}


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends