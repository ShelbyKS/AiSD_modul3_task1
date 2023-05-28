#include "include/ListGraph.hpp"
#include "include/MatrixGraph.hpp"
#include "include/ArcGraph.hpp"
#include "include/SetGraph.hpp"


void Print_vec(std::vector<int> ver){
    for(int i = 0; i < ver.size(); i++){
        std::cout << ver[i] << " ";
    }
    std::cout << std::endl;
}


int main(){
    ListGraph list_graph(5);

    list_graph.AddEdge(1, 3);
    list_graph.AddEdge(1, 4);
    list_graph.AddEdge(2, 1);
    list_graph.AddEdge(2, 4);
    list_graph.AddEdge(4, 3);

    int vertex = 4;

    Print_vec(list_graph.GetNextVertices(vertex));
    Print_vec(list_graph.GetPrevVertices(vertex));

    std::cout << "After copping:" << std::endl;

    MatrixGraph matrix_graph(list_graph);
    SetGraph set_graph(matrix_graph);
    ArcGraph arc_graph(set_graph);

    Print_vec(arc_graph.GetNextVertices(vertex));
    Print_vec(arc_graph.GetPrevVertices(vertex));

    return 0;
}