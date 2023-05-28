#include "IGraph.hpp"

class MatrixGraph: public IGraph{
public:
    MatrixGraph(int vertex_num);
    MatrixGraph(const IGraph &graph);
    ~MatrixGraph();

    void AddEdge(int from, int to) override;

    int VerticesCount() const override { return matrix.size(); }

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

    void PrintMatrix();

private:
    std::vector<std::vector<int> > matrix;
};