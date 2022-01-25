
#include <gtest/gtest.h>
#include <PathFinding/TileBasedMaps.h>

using std::vector;
using std::string;

TEST(PathFinding, Shortest_disance_between_2_points)
{
        vector<string> map;
        map.push_back("XXXXXXXXXX");
        map.push_back("X___XX_X_X");
        map.push_back("X_X__X___X");
        map.push_back("XSXX___X_X");
        map.push_back("X_X__X___X");
        map.push_back("X___XX_X_X");
        map.push_back("X_X__X_X_X");
        map.push_back("X_XX___X_X");
        map.push_back("X__O_X___X");
        map.push_back("XXXXXXXXXX");
        TileBasedMaps::ShortestPath path('X', '_');
        int distance = path.getDistance(map, 'S', 'O');
        GTEST_ASSERT_EQ(distance, 7);
}


int main(int ac, char* av[])
{
        testing::InitGoogleTest(&ac, av);
        return RUN_ALL_TESTS();
} 
