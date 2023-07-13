#include <iostream>
#include <cstring>
using namespace std;

#define INF 9999999
#define V 6

int G[V][V] = { { 0, 4, 4, 0, 0, 0 },
    			{ 4, 0, 2, 0, 0, 0 },
    			{ 4, 2, 0, 3, 2, 4 },
                { 0, 0, 3, 0, 0, 3 },
    			{ 0, 0, 2, 0, 0, 3 },
    			{ 0, 0, 4, 3, 3, 0 } };

int main() {
    clock_t start, end;
    int no_edge = 0, selected[V];
    memset(selected, false, sizeof(selected));  // Set selected false initially
    selected[0] = true;
    int x, y;  // Rows and columns
    cout << "Edge" << " : " << "Weight" << endl;
    start = clock();
    while (no_edge < V - 1) {
        int min = INF;
        x = 0;
        y = 0;
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                          min = G[i][j];
                          x = i;
                          y = j;
                        }
                    }
                }
            }
        }
        cout << x << " - " << y << " :  " << G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
    }
    end = clock();
    cout << "Time taken: " << (double)(end-start)/CLOCKS_PER_SEC << endl;
    return 0;
}
