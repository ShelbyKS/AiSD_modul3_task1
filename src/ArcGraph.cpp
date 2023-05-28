#include "ArcGraph.hpp"


ArcGraph::ArcGraph(int vertex_num)
{
}


ArcGraph::ArcGraph(const IGraph &graph){
    for(int i = 0; i < graph.VerticesCount(); ++i){
        std::vector<int> next_ver = graph.GetNextVertices(i);
        for(int j = 0; j < next_ver.size(); ++j){
            AddEdge(i, next_ver[j]);
        }
    }
}


ArcGraph::~ArcGraph()
{    
}


void ArcGraph::AddEdge(int from, int to){
    std::pair<int, int> edge;
    edge = std::make_pair(from, to);
    edges.push_back(edge);
}


std::vector<int> ArcGraph::GetNextVertices(int vertex) const{
    std::vector<int> next_vertices;
    
    for(int i = 0; i < edges.size(); i++){
        if(edges[i].first == vertex){
            next_vertices.push_back(edges[i].second);
        }
    }
    return next_vertices;
}


std::vector<int> ArcGraph::GetPrevVertices(int vertex) const{
    std::vector<int> prev_vertices;
   
    for(int i = 0; i < edges.size(); i++){
        if(edges[i].second == vertex){
            prev_vertices.push_back(edges[i].first);
        }
    }
    return prev_vertices;
}


void ArcGraph::Print(){
    for(int i = 0; i < edges.size(); i++){
        std::cout << edges[i].first << " " << edges[i].second << std::endl;
    }
}
