#include "IGraph.hpp"

class ListGraph: public IGraph {
public:
    ListGraph(int vertex_num);
    ListGraph(const IGraph &graph);
    ~ListGraph();
    ListGraph& operator=(const ListGraph&) = delete;

    void AddEdge(int from, int to) override;

    int VerticesCount() const override { return vec.size(); }

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int> > vec;
};