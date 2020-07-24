#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<int> arrows)
{
    int roomCnt = 0;
    map<pair<int, int>, bool> vertex_visited;
    map<pair<pair<int, int>, pair<int, int>>, bool> edge_visited;

    // 0 1 2 3 4 5 6 7
    int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

    int x = 0;
    int y = 0;
    vertex_visited[{x, y}] = true;
    for (int i = 0; i < arrows.size(); i++)
    {
        // X�ڷ� �����Ǵ� ������ Ư���ϱ� ���� ���̸� 2��� �ø�
        for (int j = 0; j < 2; j++)
        {
            int xpos = x + dx[arrows[i]];
            int ypos = y + dy[arrows[i]];

            if (vertex_visited[{xpos, ypos}] == true)
            {
                if (edge_visited[{ {x, y}, { xpos, ypos }}] == false || edge_visited[{ {xpos, ypos}, { x, y }}] == false)
                {
                    roomCnt++;
                }
            }

            // vertex üũ
            vertex_visited[{xpos, ypos}] = true;

            // edge üũ
            edge_visited[{ {x, y}, { xpos, ypos }}] = true;
            edge_visited[{ {xpos, ypos}, { x, y }}] = true;

            x = xpos;
            y = ypos;
        }
    }
    return roomCnt;
}
