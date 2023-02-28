
#include "../Cubos.hpp"
#include <list>
#include <unordered_set>
#include <iostream>

void bfs_for_cross(Cube& cube)
{
    std::list<Cube> queue;
    std::unordered_set<string>  visited;
    int i = 0;
    queue.push_back(cube);
    while (!queue.empty())
    {
        Cube current = queue.front();
        queue.pop_front();
        string str = current.to_string_forcross();
        if (visited.find(str) != visited.end())
            continue;
        visited.insert(str);
        for (char face : Cube::face_names)
        {
            for (int i = 0; i < 3; ++i)
            {
                Cube next = current;
                next.rotate(face, i);
                if (next.is_cross())
                {
                    cout << "Found cross!" << endl;
                    return;
                }
                queue.push_back(next);
            }
        }
        if (visited.size() % 100 == 0)
            cout << "Visited size: " << visited.size() << endl;
    }
}

int main()
{
    Cube::init_members();
    Cube   rk;

    // print_ascii_rubik(rk);
    rk.rotate('u', 2);
    rk.rotate('f', 2);
    rk.rotate('b', 3);
    rk.rotate('d', 2);
    rk.rotate('l', 3);
    rk.rotate('r', 2);
    rk.rotate('l', 1);
    rk.rotate('r', 2);
    rk.rotate('u', 1);
    rk.rotate('f', 3);
    rk.rotate('l', 2);
    rk.rotate('d', 3);
    rk.rotate('r', 1);
    rk.rotate('u', 2);
    print_ascii_rubik(rk);
    bfs_for_cross(rk);


}