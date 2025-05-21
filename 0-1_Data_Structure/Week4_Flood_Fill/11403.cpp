#include <iostream>
using namespace std;
bool graph[101][101]; // city[start][end]

void Floyd_Warshall(int &n) {
    for(int k = 1; k <= n; k++) // ¤»¤»
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= n; j++) 
                if(!graph[i][j]) 
                    if(graph[i][k] && graph[k][j])
                        graph[i][j] = 1;
}

int main() {
    int n;
    cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
			int t;
			cin >> t;
			if(t)
				graph[i][j] = 1;
		}

    Floyd_Warshall(n);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            cout << graph[i][j] << ' ';
        cout << '\n';
    }
}