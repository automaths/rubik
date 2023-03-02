#include <queue>
#include <unordered_set>
#include <iostream>
#include "../Cubos.hpp"

using namespace std;

vector<string> astar_for_cross(Cube& cube)
{
    priority_queue<SearchCube> queue;
    unordered_set<string>  visited;

    queue.push(SearchCube(cube, vector<string>()));
    while (!queue.empty())
    {
        SearchCube current = queue.top();
        queue.pop();
        string str = current.cube.to_string_forcross();
        if (visited.find(str) != visited.end())
            continue;
        visited.insert(str);
        for (char face : Cube::face_names)
        {
            for (int i = 1; i < 4; ++i)
            {
                Cube next = current.cube;
                next.rotate(face, i);
                vector<string> moves = current.moves;
                moves.push_back(string(1, face+'A'-'a') + (i==2?"'":i==2?"2":""));
                if (next.is_cross())
                {
                    cout << "Found cross!" << endl;
                    for (string move : moves)
                        Cube::res_moves += move + " ";
                    cube = next;
                    return moves;
                }
                queue.push(SearchCube(next, moves));
            }
        }
        if (visited.size() % 1000 == 0)
            cout << "Visited size: " << visited.size() << endl;
    }
    return vector<string>(1, "fail???");
}


bool Cube::is_cross()
{
    if (edges["DF"].orientation != 0
     || edges["DF"].name != "DF"
     || edges["DR"].orientation != 0
     || edges["DR"].name != "DR"
     || edges["DB"].orientation != 0
     || edges["DB"].name != "DB"
     || edges["DL"].orientation != 0
     || edges["DL"].name != "DL")
        return false;
    return true;
}

string Cube::to_string_forcross()
{
    string s = "";
    for (auto edge : edges)
    {
        if (edge.second.name[0] == 'D')
            s += edge.second.name + to_string(edge.second.orientation);
        else
            s += "*";
    }
    return s;
}
