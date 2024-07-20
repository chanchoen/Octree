#include <queue>
#include <vector>

#include "OctreeNode.h"


void OctreeNode::SetCenter(std::vector<double> center){ mCenter = center; }
void OctreeNode::SetVertex(std::vector<std::vector<double>> &vertex){ mVertex = vertex; }
void OctreeNode::SetWidth(double width){ mWidth = width; }
void OctreeNode::SetDepth(int depth){ mDepth = depth; }

std::vector<double> OctreeNode::GetCenter(){ return mCenter; }
std::vector<std::vector<double>> OctreeNode::GetVertex(){ return mVertex; }
double OctreeNode::GetWidth(){ return mWidth; }
double OctreeNode::GetDepth(){ return mDepth; }
