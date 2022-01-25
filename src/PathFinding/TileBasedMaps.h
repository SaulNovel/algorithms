#ifndef TILE_BASED_MAPS
#define TILE_BASED_MAPS

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>

using std::string;
using std::vector;
using std::pair;
using std::queue;

namespace TileBasedMaps
{

class ShortestPath
{
private:
    using Node = pair<int, int>;

    const vector<Node> directions_ = 
    {
        { 0, -1}, // up
        { 0,  1}, // down
        { 1,  0}, // right
        {-1,  0}  // left
    };

    // constrains
    const char wall_;
    const char open_;

    /**
     * BFS on map to find target symbol
     * @param map
     * @param seen tracks traversed nodes
     * @param start
     * @param targetSymbol
     * 
     * Returns shortest distance or INF if targetSymbol not found
    */ 
    int findPath(const vector<string>& map, vector<vector<bool>>& seen, const Node& start, const char targetSymbol) {
        const int size1 = static_cast<int>(map.size());
        const int size2 = static_cast<int>(map[0].size());
        
        queue<Node> queue;
        queue.push(start);
        int distance = 0;

        int inputCount = static_cast<int>(queue.size());
        while(!queue.empty()) {

            while(inputCount > 0) {

                Node current = queue.front();
                queue.pop();
                inputCount--;

                int x = current.first;
                int y = current.second;
                seen[x][y] = true;

                if (map[x][y] == targetSymbol) {
                    return distance;
                }

                for (auto& dir : directions_) {
                    int x1 = x + dir.first;
                    int y1 = y + dir.second;

                    if (x1 >= 0 && x1 < size1 && 
                        y1 >= 0 && y1 < size2 &&
                        !seen[x1][y1] &&
                        map[x1][y1] != wall_) {
                        queue.push({x1, y1});
                    }
                }
            }
            
            distance++;
            inputCount = static_cast<int>(queue.size());
        }

        return std::numeric_limits<int>::max();
    }

public:

    ShortestPath(const char wall, const char open)
        : wall_(wall), open_(open)
    {
    }

    int getDistance(const vector<string>& map, char startSymbol, char targetSymbol) {
        if (map.empty()) { return 0; } 
        
        const int size1 = static_cast<int>(map.size());
        const int size2 = static_cast<int>(map[0].size());

        // find start/end idx
        Node start = {-1, -1};

        for (int i=0; i<size1; i++) {
            for (int j=0; j<size2; j++) {
                if (map[i][j] == startSymbol) {
                    start = {i, j};
                    break;
                }
            }
        }

        vector<vector<bool>> seen(size1, vector<bool>(size2, false));
        return findPath(map, seen, start, targetSymbol);
    }

};

}

#endif

