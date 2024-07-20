#include <queue>
#include <vector>

#include "Octree.h"
#include "OctreeNode.h"


void Octree::Init(){
    mOctree = std::queue<OctreeNode*>();

    std::vector<double> center_world = {0., 0., 0.};
    std::vector<std::vector<double>> vertex_world = {{ 500., 500., 500.},
                                                     { 500.,-500., 500.},
                                                     {-500.,-500., 500.},
                                                     {-500., 500., 500.},
                                                     {-500., 500.,-500.},
                                                     {-500.,-500.,-500.},
                                                     { 500.,-500.,-500.},
                                                     { 500., 500.,-500.}};
    double width = 1000.;
    int depth = 0;
  
    OctreeNode* world = MakeOctreeNode(center_world, vertex_world, width, depth);
    AppendOctreeNode(world);
}

void Octree::AppendOctreeNode(OctreeNode* node){
    mOctree.push(node);
}

void Octree::RemoveParentNode(){
    mOctree.pop();
}

void Octree::GenerateChild(OctreeNode* parentsNode){
    std::vector<double> center_parents = parentsNode->GetCenter();
    std::vector<std::vector<double>> vertex_parents = parentsNode->GetVertex();
    double width_child = 0.5 * parentsNode->GetWidth();
    double depth_child = parentsNode->GetDepth() + 1;

    for(int idx_chlid = 0; idx_chlid < 8; idx_chlid++){
        std::vector<double> center_child;
        std::vector<std::vector<double>> vertex_child;
        // double center_x = 

        // center_child.push_back(center_x);
        // center_child.push_back(center_y);
        // center_child.push_back(center_z);

        // for(int idx_vertex = 0; idx_vertex < 8; idx_vertex++){
        //     std::vector<double> vertex_point;
        //     double x = center_parents[0];
        //     double y = center_parents[1];
        //     double z = center_parents[2];
        //     if( idx_vertex = 0 ){ x += 0.5 * width_child; y += 0.5 * width_child; z += 0.5 * width_child; }
        //     if( idx_vertex = 1 ){ x += 0.5 * width_child; y -= 0.5 * width_child; z += 0.5 * width_child; }
        //     if( idx_vertex = 2 ){ x -= 0.5 * width_child; y -= 0.5 * width_child; z += 0.5 * width_child; }
        //     if( idx_vertex = 3 ){ x -= 0.5 * width_child; y += 0.5 * width_child; z += 0.5 * width_child; }
        //     if( idx_vertex = 4 ){ x -= 0.5 * width_child; y += 0.5 * width_child; z -= 0.5 * width_child; }
        //     if( idx_vertex = 5 ){ x -= 0.5 * width_child; y -= 0.5 * width_child; z -= 0.5 * width_child; }
        //     if( idx_vertex = 6 ){ x += 0.5 * width_child; y -= 0.5 * width_child; z -= 0.5 * width_child; }
        //     if( idx_vertex = 7 ){ x += 0.5 * width_child; y += 0.5 * width_child; z -= 0.5 * width_child; }
        //     vertex_point.push_back(x);
        //     vertex_point.push_back(y);
        //     vertex_point.push_back(z);

        //     vertex_world.push_back(vertex_point);
        // } code in friday
        

        OctreeNode* child_node = MakeOctreeNode(center_child, vertex_child, width_child, depth_child);
        AppendOctreeNode(child_node);
    }
    RemoveParentNode();
}

OctreeNode* Octree::MakeOctreeNode(std::vector<double> center, std::vector<std::vector<double>> &vertex, double width, int depth){
    OctreeNode* node;
    node->SetCenter(center);
    node->SetVertex(vertex);
    node->SetDepth(depth);
    node->SetDepth(width);

    return node;
}


