#include<bits/stdc++.h>

using namespace std;

int mrx;
vector<int>detective(3);            //detective vertices 
int n = 50;
const int INF = numeric_limits<int>::max();

vector <vector<int>> graph(n);  //graph
vector <int> degree(n);
vector <int> mrxmoves;

struct tickets{         //tickets structure
    int taxi = 12;
    int bus  = 0;
    int subway = 0;
}Detective[3];

void show_tickets(int i){
    cout << "Tickets : "<< Detective[i].taxi << endl;
}

 void turn(int i){
        Detective[i].taxi--;
        return;
}


int findDistance(int start, int end) {
    if(start == end)
        return 0 ;
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

void MrX_Decisions() {
    float disAvg = 0;
    int next = -1; // Initialize next to an invalid value
    int bestNext = -1; // Initialize bestNext to an invalid value
    float maxDisAvg = -1; // Initialize maxDisAvg to a small negative value

    for (int x : graph[mrx]) {
        // Calculate the average distance to detectives for this neighbor
        disAvg = (findDistance(x, detective[0]) + findDistance(x, detective[1]) + findDistance(x, detective[2])) / 3.0;

        // Check if this neighbor is a better choice
        if (disAvg > maxDisAvg) {
            maxDisAvg = disAvg;
            bestNext = x;
        }
    }

    // Check if a better neighbor was found
    if (bestNext != -1) {
        // Make the move to the best neighbor
        mrx = bestNext;
    }
    mrxmoves.push_back(mrx);
    return;
}



// struct monte_carlo_tree_node{
//     int t;
//     int ni;
//     int leaf;
// };



//vector<int> fourthstep;

// vector<int> bfs4(int start, int c) {
//     c++;
//     for (int neighbor : graph[start]) {
//         if (c == 4) {
//             auto it = find(fourthstep.begin(), fourthstep.end(), neighbor);
//             if(it == fourthstep.end())
//                fourthstep.push_back(neighbor);
//             }
//         else 
//             bfs4(neighbor, c);
//         }
// }


// int rollout(int start, int end, int c) {
//     auto it = find(graph[start].begin(), graph[start].end(), end);
//     if(it != fourthstep.end())
//         return c;
//     else
//         for (int neighbor : graph[start]) {
//             rollout(neighbor,end, c);
//         }
// }



void make_graph() {
    // Initialize the degrees of the first three vertices and create initial connections
    for (int i = 0; i < 3; i++) {   //make a small complete graph 
        degree[i] = 2;
        if (i != 0)
            graph[i].push_back(0); 
        if (i != 1)
            graph[i].push_back(1); 
        if (i != 2)
            graph[i].push_back(2); 
    }
    
    int r1, r2;
    // Generate connections for the remaining vertices
    for (int i = 3; i < n; i++) {
        retry:
        r1 = rand() % i; // Randomly select a vertex r1
        if (degree[r1] > 3)
            goto retry; // If degree[r1] is already 3 or more, retry selecting r1
        
        tryagain:
        r2 = rand() % i; // Randomly select a vertex r2
        if (degree[r2] > 3 || r1 == r2)
            goto tryagain; // If degree[r2] is 3 or more, or if r1 equals r2, retry selecting r2
        
        degree[i] = 2; // Set the degree of the current vertex i
        degree[r1]++; // Increase the degree of r1
        degree[r2]++; // Increase the degree of r2

        graph[i].push_back(r1);// Create connections between the vertices
        graph[i].push_back(r2);
        graph[r1].push_back(i);
        graph[r2].push_back(i);
    }
    return;
}

void print_graph(){
    for(int i = 0 ;i < n; i++){
        cout << "FOR VERTEX "<< i << " : ";
        int s = graph[i].size();
        for(int j = 0; j < s; j++)
            cout << graph[i][j] << " ";
            //cout << "graph["<< i <<"].push_back("<<graph[i][j] << ");"<<endl;
            cout << endl;
    }
}



int caught(){
    if(mrx == detective[0] || mrx == detective[1] || mrx == detective[2] )
        return 1;
    else 
        return 0;

}

void make_move(){
    int t;
    for(int i = 0 ;i < 3 ; i++){
        cout << "POSSIBLE MOVES for "<< i << " : ";
        for (int nei : graph[detective[i]])
            cout << " " << nei ;
        cout << endl;
        t = detective[i];
        show_tickets(i);
        cout << "Your Move : " ;  
        again :
        cin >> detective[i];
        if(find(graph[t].begin(), graph[t].end(), detective[i]) == graph[t].end()){
            cout << "Taxi doesn't go to "<< detective[i] << ". Try again : ";
            goto again;
        }
        turn(i);
    }
}


int main() {
    int flag = 0;
    srand(static_cast<unsigned int>(time(nullptr)));
    cout << "WELCOME TO SOCTLAND YARD GAME !!!" << endl << endl;
    cout << "You along with 2 other detectives are on a mission in a city to find Mr X."<<endl;
    cout << "He is a very dangerous person who deals with lots of drugs and murder." << endl;
    cout << "Recently, he created a great havoc in the city by destroying railroads and the Bus Routes in the city." << endl;
    cout << "Fortunately this backfired him as he left something in the middle of the city and hence he had to return for it.";
    cout << "We have finally tracked his phone but it reveals its location only after 4 stations are crossed"<< endl;
    cout << "Now all he can do is by moving across the city using taxis only. This is the best time to catch him." << endl;
    cout << "Catch him as soon as possible....." << endl;

    cout << "There are 50 stations in the city numbered from 0 to 49."<<endl << "Here is the graph of the city Make moves and catch MrX"<<endl; 
    make_graph();
    print_graph();
    for(int i = 0 ; i < 3; i++){
         detective[i] = rand()%50;
        cout << "Starting Position of " << i << " : "<< detective[i] << endl; 
    }
   
    mrx = rand()%50;
    mrxmoves.push_back(mrx);
    while(1 && Detective[0].taxi != 0){
        if(Detective[0].taxi % 4 == 0 && Detective[0].taxi != 12 ) 
            cout <<"Alert Mr. X has been loacted at : " << mrx << endl;
        make_move();
        if((caught())){
            flag = 1;
            cout << " Congratulations !! You caught Mr.X" << endl << "Thank You for saving the city" << endl;
            break;
        }
        MrX_Decisions();
    }
    if(!flag){
        cout << "Bruh Mr X escaped and now the city is doomed :( ....."<< endl;
    }
        cout << "HERE ARE the Mr. X MOVES : " << endl;
        cout << mrxmoves[0];
        for(int j = 1; j < mrxmoves.size(); j++)
            cout << "->" << mrxmoves[j];
        cout << endl;
    return 0;
}




