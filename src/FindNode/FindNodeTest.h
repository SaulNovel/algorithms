#include <FindNode/FindNode.h>
#include <iostream>


namespace FindNodeTest
{

void test() {

    using Tree = BinarySearchTree::BinarySearchTree<int>;
    Tree tree;

    tree.insert(9);
    tree.insert(4);
    tree.insert(6);
    tree.insert(20);
    tree.insert(170);
    tree.insert(15);
    tree.insert(1);
    tree.insert(29);
    tree.insert(200);
    tree.print();


    auto root = tree.getRoot();
    auto source = tree.getNode(29);
    auto target = tree.getNode(200);

    FindNode::Distance<int> distance;
    int ans = distance.getDistance(root, source, target);
    std::cout << ans << std::endl;

}

}