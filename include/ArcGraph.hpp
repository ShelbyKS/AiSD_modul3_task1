#include "IGraph.hpp"

class ArcGraph: public IGraph{
public:
    ArcGraph(int vertex_num);
    ArcGraph(const IGraph &graph);
    ~ArcGraph();

    void AddEdge(int from, int to) override;

    int VerticesCount() const override { return edges.size(); }

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
    
    void Print();
private:
    std::vector<std::pair<int, int> > edges;
};