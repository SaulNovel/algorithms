#ifndef FIND_NODE
#define FIND_NODE

// TODO: add it from CMake
#include <FindNode/BinarySearchTree.h>

#include <unordered_map>
#include <unordered_set>
#include <queue>

namespace FindNode
{

/** 
 * Finds distance (number of vertex) from source to target
 * 
*/
template<class T>
class Distance
{

private:
    using Tree = BinarySearchTree::BinarySearchTree<T>;
    using Reverse = std::unordered_map<typename Tree::Node*, typename Tree::Node*>;
    using Seen = std::unordered_set<typename Tree::Node*>;
    using Queue = std::queue<typename Tree::Node*>;

    void DFS(typename Tree::Node* prev, typename Tree::Node* current, Reverse& prevNodes) {
        if (current == nullptr) {
            return;
        }

        prevNodes[current] = prev;

        DFS(current, current->left, prevNodes);
        DFS(current, current->right, prevNodes);
    }


public:
    const int getDistance(typename Tree::Node* root, typename Tree::Node* source, typename Tree::Node* target) {

        Reverse prevNodes;
        Seen seen;

        DFS(root, root->right, prevNodes);
        DFS(root, root->left, prevNodes);

        // BFS over source till target is found
        Queue queue;
        queue.push(source);
        int size = static_cast<int>(queue.size());
        int distance = 0;
        while(!queue.empty()) {
            while(size-- > 0) {
                auto current = queue.front();
                queue.pop();
                seen.insert(current);

                if (current->value == target->value) {
                    return distance;
                }

                auto left = current->left;
                if (left != nullptr && !seen.count(left)) {
                    queue.push(left);
                }

                auto right = current->right;
                if (right != nullptr && !seen.count(right)) {
                    queue.push(right);
                }

                auto prev = prevNodes[current];
                if (prev != nullptr && !seen.count(prev)) {
                    queue.push(prev);
                }

            }

            size = static_cast<int>(queue.size());
            distance++;
        }
        return std::numeric_limits<int>::max();
    }

};

}

#endif