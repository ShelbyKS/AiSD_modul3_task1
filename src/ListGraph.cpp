#include "ListGraph.hpp"

ListGraph::ListGraph(int vertex_num): vec(vertex_num) 
{
}


ListGraph::ListGraph(const IGraph &graph): vec(graph.VerticesCount()) {
    for(int i = 0; i < vec.size(); i++){
        std::vector<int> next_vertices = graph.GetNextVertices(i);
        for(int j = 0; j < next_vertices.size(); j++){
            AddEdge(i, next_vertices[j]);
        }
    }
}


ListGraph::~ListGraph()
{
}


void ListGraph::AddEdge(int from, int to){
    vec[from].push_back(to);
}


std::vector<int> ListGraph::GetNextVertices(int vertex) const{
    std::vector<int> next_vertices;
    for(int i = 0; i < vec[vertex].size(); ++i){
        next_vertices.push_back(vec[vertex][i]);
    }
    return next_vertices;
}


std::vector<int> ListGraph::GetPrevVertices(int vertex) const{
    std::vector<int> prev_vertices;
    for(int i = 0; i < vec.size(); ++i){
        for(int j = 0; j < vec[i].size(); ++j){
            if(vertex == vec[i][j]){
                prev_vertices.push_back(i);
                break;
            }
        }
    }
    return prev_vertices;
}