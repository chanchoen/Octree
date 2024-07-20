#ifndef OCTREENODE_H_
#define OCTREENODE_H_

#include <queue>
#include <vector>


class OctreeNode
{
public:
    void SetCenter(std::vector<double> center);
    void SetVertex(std::vector<std::vector<double>> &vertex);
    void SetWidth(double width);
    void SetDepth(int depth);

    std::vector<double> GetCenter();
    std::vector<std::vector<double>> GetVertex();
    double GetWidth();
    double GetDepth();
    

private:
    std::vector<double> mCenter;
    std::vector<std::vector<double>> mVertex;
    double mWidth;
    int mDepth;
};

#endif