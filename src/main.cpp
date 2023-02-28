
#include "../Cubos.hpp"
#include <queue>
#include <unordered_set>
#include <iostream>

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
            for (int i = 0; i < 3; ++i)
            {
                Cube next = current.cube;
                next.rotate(face, i);
                vector<string> moves = current.moves;
                moves.push_back(string(1, face) + to_string(i));
                if (next.is_cross())
                {
                    cout << "Found cross!" << endl;
                    for (string move : moves)
                        cout << move << " ";
                    cout << endl;
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

int main()
{
    Cube::init_members();
    Cube   rk;
    // print_ascii_rubik(rk);
    rk.rotate('r', 1);
    cout << rk.corners["URF"].orientation << endl;
    cout << rk.to_string_2FL() << endl;
    print_ascii_rubik(rk);
    exit(0);

    astar_for_cross(rk);
    // rk.find_2FL();
    print_ascii_rubik(rk);
    Cube rk2 = rk.y();
    print_ascii_rubik(rk2);
    
}