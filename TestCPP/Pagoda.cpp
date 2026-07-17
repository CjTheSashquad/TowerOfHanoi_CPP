#include <iostream>
#include <vector>
using namespace std;

void printRods(const vector<int>& fromRod, const vector<int>& auxRod, const vector<int>& toRod) {
    auto printRod = [](const string& name, const vector<int>& rod) {
        cout << name << "[";
        for (size_t i = 0; i < rod.size(); i++) {
            cout << rod[i];
            if (i != rod.size() - 1) cout << ",";
        }
        cout << "]";
        };
	cout << "Current Stacks: ";
    printRod("Source", fromRod);
    cout << " | ";
    printRod("Support", auxRod);
    cout << " | ";
    printRod("End", toRod);
    cout << endl << "\n";
};

void towerOfHanoi(int n,
    vector<int>& fromRod, vector<int>& toRod, vector<int>& auxRod,
    vector<int>& source, vector<int>& support, vector<int>& end,
    const string& fromName, const string& toName, const string& auxName,
    int& nMove) {

    if (n == 1) {
        int disk = fromRod.back();
        fromRod.pop_back();
        toRod.push_back(disk);
        nMove++;
        cout << "Move " << nMove << ": disk " << disk << " from " << fromName << " to " << toName << "\n";
        printRods(source, support, end);
        return;
    }

    towerOfHanoi(n - 1, fromRod, auxRod, toRod, source, support, end, fromName, auxName, toName, nMove);

    int disk = fromRod.back();
    fromRod.pop_back();
    toRod.push_back(disk);
    nMove++;
    cout << "Move " << nMove << ": disk " << disk << " from " << fromName << " to " << toName << "\n";
    printRods(source, support, end);

    towerOfHanoi(n - 1, auxRod, toRod, fromRod, source, support, end, auxName, toName, fromName, nMove);
}

int main() {
    int n = 0;                   
    int moves = 0;
    vector<int> fromRod, auxRod, toRod;

    cout << "Enter number of disk : ";
    cin >> n;

    for (int i = n; i > 0; i--) fromRod.push_back(i);

    printRods(fromRod, auxRod, toRod);

    cout << "---------------------------------------------------";
    cout << "\nTower of Hanoi with " << n << " disks:\n\n";

    towerOfHanoi(n, fromRod, toRod, auxRod, fromRod, auxRod, toRod, "Source", "End", "Support", moves);

    cout << "\nNumber of moves required = " << moves << endl;
    return 0;
}