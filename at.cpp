#include<bits/stdc++.h>

using namespace std;

int n = 50;


vector <vector<int>> graph(n);
vector <int> degree(n);




void make_graph( ){
    
    for(int i = 0; i < 3; i++){
        degree[i] = 2;
        if(i != 0)
            graph[i].push_back(0);
        if(i != 1)
            graph[i].push_back(1);
        if(i != 2)
            graph[i].push_back(2);
    }
    int r1, r2;
    for(int i = 3; i < n; i++){
        retry:
        r1 = rand()%i;
        if(degree[r1] > 3)
            goto retry;
        tryagain :
        r2 = rand()%i;
        if(degree[r2] > 3 ||  r1 == r2)
            goto tryagain;
        degree[i] = 2;
        degree[r1]++;
        degree[r2]++;

        graph[i].push_back(r1);
        graph[i].push_back(r2);
        graph[r1].push_back(i);
        graph[r2].push_back(i);
    }
    return;
}

void print_graph(){
    for(int i = 0 ;i < n; i++){
        //cout << "FOR VERTEX "<< i << " : ";
        int s = graph[i].size();
        for(int j = 0; j < s; j++)
            //cout << graph[i][j] << " ";
            cout << "graph["<< i <<"].push_back("<<graph[i][j] << ");"<<endl;
            //cout << endl;
    }
}

int main() {
    make_graph();
    print_graph();
    cout << degree[0];
    return 0;
}
