#include "MatrixGraph.hpp"


MatrixGraph::MatrixGraph(int vertex_num): matrix(vertex_num, std::vector<int>(vertex_num))
{
}


MatrixGraph::MatrixGraph(const IGraph &graph): matrix(graph.VerticesCount(), std::vector<int>(graph.VerticesCount())) {
    for(int i = 0; i < matrix.size(); i++){
        std::vector<int> next_vertices = graph.GetNextVertices(i);
        for(int j = 0; j < next_vertices.size(); j++){
            AddEdge(i, next_vertices[j]);
        }
    }
}


MatrixGraph::~MatrixGraph()
{
}


void MatrixGraph::AddEdge(int from, int to){
    matrix[from][to] = 1;
}


std::vector<int> MatrixGraph::GetNextVertices(int vertex) const{
    std::vector<int> next_vertices;
    
    for(int i = 0; i < matrix.size(); i++){
        if(matrix[vertex][i] == 1){
            next_vertices.push_back(i);
        }
    }
    return next_vertices;
}


std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const{
    std::vector<int> prev_vertices;
   
    for(int i = 0; i < matrix.size(); i++){
        if(matrix[i][vertex] == 1){
            prev_vertices.push_back(i);
        }
    }
    return prev_vertices;
}


void MatrixGraph::PrintMatrix(){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix.size(); j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}