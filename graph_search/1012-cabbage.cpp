#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

bool farm[51][51] = {false,};
bool visited[51][51] = {false,};
int width, height, N;

void input_problem(){
    cin >> width >> height >> N;
    for (int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        farm[x][y] = true;
    }
}

void DFS(int x, int y){
    visited[x][y] = true;
    
    if (farm[x+1][y] && !visited[x+1][y])
        DFS(x+1, y);
    if (farm[x-1][y] && !visited[x-1][y])
        DFS(x-1, y);
    if (farm[x][y+1] && !visited[x][y+1])
        DFS(x, y+1);
    if (farm[x][y-1] && !visited[x][y-1])
        DFS(x, y-1);

}

int main(){
    int T; cin >> T;

    for (int i = 0; i < T; i++){
        input_problem();

        int count = 0;
        for (int x = 0; x < width; x++){
            for (int y = 0; y < height; y++){
                if (farm[x][y] == 1 && !visited[x][y]){
                    count++;
                    DFS(x, y);
                }
            }
        }

        cout << count << '\n';

        memset(visited, false, sizeof(visited));
        memset(farm, false, sizeof(farm));
    }

    return 0;
}