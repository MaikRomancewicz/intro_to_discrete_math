#include <iostream>
#include <vector>
#include "graph.h"
#include <queue>

using namespace std;

void printNeighbors(Graph g, int id){
    Graph::Node n = g.get_node(id);
        vector<Graph::Neighbor> adjacent = n.adjacent_nodes();
        cout << "Nodes adjacent to " << id << ":" << endl;
        for(Graph::Neighbor n : adjacent){
            cout << n.id() << endl;
        }
}

Graph bfs(const Graph & graph, Graph::NodeId start_node){
    std::vector<bool> visited(graph.num_nodes(), false);
    std::vector<int> dist(graph.num_nodes(), -1);
    Graph bfs_tree(graph.num_nodes(), graph.dirtype);
    queue<Graph::NodeId> queue1;
    
    queue1.push(start_node);
    visited[start_node] = true;
    dist[start_node] = 0;
    
    while(not queue1.empty()){
        auto current_node = queue1.front();
        queue1.pop();
        cout << "Node " << current_node << " has distance" << dist[current_node];
        
        for (auto neighbor: graph.get_node(current_node).adjacent_nodes()) {
            if(not visited[neighbor.id()]){
                queue1.push(neighbor.id());
                visited[neighbor.id()] = true;
                dist[neighbor.id()] = true;
                bfs_tree.add_edge(current_node, neighbor.id());
            }
        }
    }
    return bfs_tree;
}

int main(int argc,char** argv){
   if (argc > 1) {
        Graph g(argv[1], Graph::directed);
        printNeighbors(g, 26);
    }
}
