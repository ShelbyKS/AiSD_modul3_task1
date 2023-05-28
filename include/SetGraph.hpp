#include "IGraph.hpp"
#include <set>

class SetGraph: public IGraph{
public:
    SetGraph(int vertex_num);
    SetGraph(const IGraph &graph);
    ~SetGraph();

    void AddEdge(int from, int to) override;

    int VerticesCount() const override { return graph.size(); }

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::set<int> > graph;
};