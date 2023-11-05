#include<bits/stdc++.h>
using namespace std;


int n = 50;
const int INF = numeric_limits<int>::max();

//int count = 0;
vector <vector <int>> graph(n);
vector <int> degree(n);


// struct monte_carlo_tree_node{
//     int t;
//     int ni;
//     int leaf;
// };



void create_graph(){
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[0].push_back(4);
    graph[0].push_back(6);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[2].push_back(0);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[2].push_back(14);
    graph[3].push_back(2);
    graph[3].push_back(1);
    graph[3].push_back(5);
    graph[3].push_back(8);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[4].push_back(5);
    graph[4].push_back(6);
    graph[5].push_back(4);
    graph[5].push_back(3);
    graph[5].push_back(7);
    graph[5].push_back(9);
    graph[6].push_back(0);
    graph[6].push_back(4);
    graph[6].push_back(7);
    graph[6].push_back(8);
    graph[7].push_back(6);
    graph[7].push_back(5);
    graph[7].push_back(9);
    graph[7].push_back(10);
    graph[8].push_back(3);
    graph[8].push_back(6);
    graph[8].push_back(10);
    graph[8].push_back(13);
    graph[9].push_back(5);
    graph[9].push_back(7);
    graph[9].push_back(11);
    graph[9].push_back(12);
    graph[10].push_back(8);
    graph[10].push_back(7);
    graph[10].push_back(11);
    graph[10].push_back(16);
    graph[11].push_back(9);
    graph[11].push_back(10);
    graph[11].push_back(12);
    graph[11].push_back(14);
    graph[12].push_back(9);
    graph[12].push_back(11);
    graph[12].push_back(13);
    graph[12].push_back(17);
    graph[13].push_back(12);
    graph[13].push_back(8);
    graph[13].push_back(15);
    graph[13].push_back(16);
    graph[14].push_back(2);
    graph[14].push_back(11);
    graph[14].push_back(15);
    graph[14].push_back(20);
    graph[15].push_back(13);
    graph[15].push_back(14);
    graph[15].push_back(18);
    graph[15].push_back(19);
    graph[16].push_back(13);
    graph[16].push_back(10);
    graph[16].push_back(17);
    graph[16].push_back(18);
    graph[17].push_back(16);
    graph[17].push_back(12);
    graph[17].push_back(19);
    graph[17].push_back(24);
    graph[18].push_back(15);
    graph[18].push_back(16);
    graph[18].push_back(21);
    graph[18].push_back(22);
    graph[19].push_back(17);
    graph[19].push_back(15);
    graph[19].push_back(20);
    graph[19].push_back(21);
    graph[20].push_back(14);
    graph[20].push_back(19);
    graph[20].push_back(22);
    graph[20].push_back(23);
    graph[21].push_back(18);
    graph[21].push_back(19);
    graph[21].push_back(23);
    graph[21].push_back(25);
    graph[22].push_back(18);
    graph[22].push_back(20);
    graph[22].push_back(26);
    graph[22].push_back(27);
    graph[23].push_back(21);
    graph[23].push_back(20);
    graph[23].push_back(24);
    graph[23].push_back(27);
    graph[24].push_back(17);
    graph[24].push_back(23);
    graph[24].push_back(25);
    graph[24].push_back(26);
    graph[25].push_back(24);
    graph[25].push_back(21);
    graph[25].push_back(28);
    graph[25].push_back(29);
    graph[26].push_back(24);
    graph[26].push_back(22);
    graph[26].push_back(30);
    graph[26].push_back(32);
    graph[27].push_back(22);
    graph[27].push_back(23);
    graph[27].push_back(28);
    graph[27].push_back(29);
    graph[28].push_back(25);
    graph[28].push_back(27);
    graph[28].push_back(31);
    graph[28].push_back(33);
    graph[29].push_back(27);
    graph[29].push_back(25);
    graph[29].push_back(30);
    graph[29].push_back(34);
    graph[30].push_back(26);
    graph[30].push_back(29);
    graph[30].push_back(31);
    graph[30].push_back(32);
    graph[31].push_back(28);
    graph[31].push_back(30);
    graph[31].push_back(33);
    graph[31].push_back(36);
    graph[32].push_back(26);
    graph[32].push_back(30);
    graph[32].push_back(39);
    graph[32].push_back(42);
    graph[33].push_back(28);
    graph[33].push_back(31);
    graph[33].push_back(34);
    graph[33].push_back(35);
    graph[34].push_back(29);
    graph[34].push_back(33);
    graph[34].push_back(35);
    graph[34].push_back(38);
    graph[35].push_back(33);
    graph[35].push_back(34);
    graph[35].push_back(36);
    graph[35].push_back(37);
    graph[36].push_back(31);
    graph[36].push_back(35);
    graph[36].push_back(37);
    graph[36].push_back(40);
    graph[37].push_back(36);
    graph[37].push_back(35);
    graph[37].push_back(38);
    graph[37].push_back(42);
    graph[38].push_back(34);
    graph[38].push_back(37);
    graph[38].push_back(39);
    graph[38].push_back(40);
    graph[39].push_back(38);
    graph[39].push_back(32);
    graph[39].push_back(41);
    graph[39].push_back(43);
    graph[40].push_back(36);
    graph[40].push_back(38);
    graph[40].push_back(41);
    graph[40].push_back(45);
    graph[41].push_back(40);
    graph[41].push_back(39);
    graph[41].push_back(44);
    graph[41].push_back(47);
    graph[42].push_back(37);
    graph[42].push_back(32);
    graph[42].push_back(43);
    graph[42].push_back(46);
    graph[43].push_back(39);
    graph[43].push_back(42);
    graph[43].push_back(44);
    graph[43].push_back(45);
    graph[44].push_back(41);
    graph[44].push_back(43);
    graph[44].push_back(49);
    graph[45].push_back(40);
    graph[45].push_back(43);
    graph[45].push_back(46);
    graph[45].push_back(47);
    graph[46].push_back(42);
    graph[46].push_back(45);
    graph[46].push_back(48);
    graph[46].push_back(49);
    graph[47].push_back(41);
    graph[47].push_back(45);
    graph[47].push_back(48);
    graph[48].push_back(46);
    graph[48].push_back(47);
    graph[49].push_back(44);
    graph[49].push_back(46);
}



void print_graph(){
    for(int i = 0 ;i < n; i++){
        cout << "FOR VERTEX "<< i << " : ";
        int s = graph[i].size();
        for(int j = 0; j < s; j++)
            cout <<graph[i][j] << " ";
        cout << endl;
    }
}

vector<int> fourthstep;

vector<int> bfs4(int start, int c) {
    c++;
    for (int neighbor : graph[start]) {
        if (c == 4) {
            auto it = find(fourthstep.begin(), fourthstep.end(), neighbor);
            if(it == fourthstep.end())
               fourthstep.push_back(neighbor);
            }
        else 
            bfs4(neighbor, c);
        }
}


// int rollout(int start, int end, int c) {
//     auto it = find(graph[start].begin(), graph[start].end(), end);
//     if(it != fourthstep.end())
//         return c;
//     else
//         for (int neighbor : graph[start]) {
//             rollout(neighbor,end, c);
//         }
// }



int findDistance(int start, int end) {
    vector<bool> visited(graph.size(), false);
    vector<int> distance(graph.size(), -1); // Initialize all distances to -1
    queue<int> q;

    q.push(start);
    visited[start] = true;
    distance[start] = 0;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

        if (currentNode == end) {
            return distance[currentNode];
        }

        for (int neighbor : graph[currentNode]) {
            if (!visited[neighbor]) {   
                 q.push(neighbor);
                visited[neighbor] = true;
                distance[neighbor] = distance[currentNode] + 1;
            }
        }
    }
    return -1;
}

void mcts(){
    for(int i  = 0; i < n; i++){
          // bfs(i);

    }
}


struct mcnode{
    int visits;
    int s;

}node[100];


int main(){
    create_graph();
    print_graph();
   

    //vector<int> fourthStepVertices = bfs(startVertex,0);
    bfs4(44, 0);
    for (int vertex : fourthstep) {
        cout << vertex << " ";
    }
    fourthstep.clear();
    cout << endl;
    bfs4(22, 0);
    for (int vertex : fourthstep) {
        cout << vertex << " ";
    }
    cout << endl;
    int start = 0;
    int end = 40;
    int distance = findDistance(start, end);

    if (distance != -1) {
        cout << distance << endl;
    } else {
        cout << "Nodes are not connected." << endl;
    }

    return 0;
}