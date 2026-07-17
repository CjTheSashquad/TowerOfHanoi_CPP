#include <iostream>
using namespace std;

void towerOfHanoi(int n, string fromRod, string toRod, string auxRod, int& nMove) {
    if (n == 1) {
        cout << "Move disk 1 from " << fromRod << " to " << toRod << endl;
        nMove++;
        return;
    }

    towerOfHanoi(n - 1, fromRod, auxRod, toRod, nMove);

    cout << "Move disk " << n << " from " << fromRod << " to " << toRod << endl;
    nMove++;

    towerOfHanoi(n - 1, auxRod, toRod, fromRod, nMove);
}

int main() {
    int n = 0;                   
    int moves = 0;

    cout << "Enter number of disk : ";
    cin >> n;

    cout << "\n\n---------------------------------------------------";
    cout << "\nTower of Hanoi with " << n << " disks:\n\n";
    towerOfHanoi(n, "Source Rod", "End Rod", "Support Rod", moves);

    cout << "\nNumber of moves required = " << moves << endl;
    return 0;
}