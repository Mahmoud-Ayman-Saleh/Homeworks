#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstring>
using namespace std;


void tower_of_hanoi(int n, char from, char aux, char to)
{
    if (n == 0) return;
    tower_of_hanoi(n-1, from, to, aux);
    cout << "Move disk " << n << " from rod " << from << " to rod " << to << endl;
    tower_of_hanoi(n-1, aux, from, to);
}