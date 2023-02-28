
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
                queue.push_back(current);
                Cube &next = queue.back();
                next.rotate(face, i);
                if (next.is_cross())
                {
                    cout << "Found cross!" << endl;
                    cube = next;
                    return;
                }
            }
        }
        if (visited.size() % 1000 == 0)
            cout << "Visited size: " << visited.size() << endl;
    }
}

int main()
{
    Cube::init_members();
    Cube   rk;

    rk.rotate('b', 1);
    rk.rotate('r', 1);
    rk.rotate('u', 1);
    print_ascii_rubik(rk);
    Cube rk2 = rk.y();
    print_ascii_rubik(rk2);

    // rk.shuffle();
    // bfs_for_cross(rk);
    
    // print_ascii_rubik(rk);
}