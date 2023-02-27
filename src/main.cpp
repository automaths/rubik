
#include "../Cubos.hpp"
#include <list>
#include <unordered_set>
#include <iostream>

void bfs_for_cross(Cube& cube)
{
    std::list<Cube> queue;
    std::unordered_set<string>  visited;

    queue.push_back(cube);
    while (!queue.empty())
    {
        Cube current = queue.front();
        queue.pop_front();
        if (current.is_cross())
        {
            cout << "Found cross!" << endl;
            return;
        }
        if (visited.find(current.to_string_forcross()) != visited.end())
            continue;
        visited.insert(current.to_string_forcross());
        for (char face : Cube::face_names)
        {
            for (int i = 0; i < 3; ++i)
            {
                Cube next = current;
                next.rotate(face, i);
                queue.push_back(next);
            }
        }
        // if (queue.size() % 100 == 0)
        //     cout << "Queue size: " << queue.size() << endl;
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
    rk.rotate('d', 3);
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