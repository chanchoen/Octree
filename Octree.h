#ifndef OCTREE_H_
#define OCTREE_H_

#include <queue>
#include <vector>

#include "OctreeNode.h"

class Octree
{
public:
    void Init();
    void AppendOctreeNode(OctreeNode* node);
    void RemoveParentNode();
    void GenerateChild(OctreeNode* parentsNode); //if number of point > threshold, only exec

    OctreeNode* MakeOctreeNode(std::vector<double> center, std::vector<std::vector<double>> &vertex, double width, int depth);

private:
    std::queue<OctreeNode*> mOctree;
    int mCounts;

};

#endif