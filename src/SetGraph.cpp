#include "SetGraph.hpp"


SetGraph::SetGraph(int vertex_num): graph(vertex_num)
{
}


SetGraph::SetGraph(const IGraph &graph): graph(graph.VerticesCount()){
    for(int i = 0; i < this->graph.size(); i++){
        std::vector<int> next_vertices = graph.GetNextVertices(i);
        for(int j = 0; j < next_vertices.size(); j++){
            AddEdge(i, next_vertices[j]);
        }
    }
}


SetGraph::~SetGraph()
{    
}


void SetGraph::AddEdge(int from, int to){
    graph[from].insert(to);
}


std::vector<int> SetGraph::GetNextVertices(int vertex) const{
    std::vector<int> next_vertices;
    
    for(auto i = graph[vertex].begin(); i != graph[vertex].end(); ++i){
        next_vertices.push_back(*i);
    }
    
    return next_vertices;
}


std::vector<int> SetGraph::GetPrevVertices(int vertex) const{
    std::vector<int> prev_vertices;
   
    for(int i = 0; i < graph.size(); i++){
        if(graph[i].count(vertex) == 1){
            prev_vertices.push_back(i);
        }
    }
    
    return prev_vertices;
}
