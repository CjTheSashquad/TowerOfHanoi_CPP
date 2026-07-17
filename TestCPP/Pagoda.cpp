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
    const string& fromName, const string& toName, const string& auxName,
    int& nMove) {

    if (n == 1) {
        int disk = fromRod.back();
        fromRod.pop_back();
        toRod.push_back(disk);
        nMove++;
        cout << "Move " << nMove << ": disk " << disk << " from " << fromName << " to " << toName << "\n";
        printRods(fromRod, auxRod, toRod);
        return;
    }

    towerOfHanoi(n - 1, fromRod, auxRod, toRod, fromName, auxName, toName, nMove);

    int disk = fromRod.back();
    fromRod.pop_back();
    toRod.push_back(disk);
    nMove++;
    cout << "Move " << nMove << ": disk " << disk << " from " << fromName << " to " << toName << "\n";
    printRods(fromRod, auxRod, toRod);

    towerOfHanoi(n - 1, auxRod, toRod, fromRod, auxName, toName, fromName, nMove);
}

int main() {
    int n = 0, moves = 0, max = 15;
    bool input = false;
    vector<int> fromRod, auxRod, toRod;

	while(input == false) {
		cout << "Enter number of disk : ";
		cin >> n;
		if (cin.fail() || n < 1) {
			cout << "Invalid input. Please enter a positive integer." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			input = true;
		}
	}

    if (n > max) {
        long long totalMoves = (1LL << n) - 1; 
        cout << "\nThat number is too big to display step-by-step.\n";
		cout << "Using the formula 2^n - 1, the total number of moves required for " << n << " disks is: " << totalMoves << endl;
        return 0;
    }

    for (int i = n; i > 0; i--) fromRod.push_back(i);

    printRods(fromRod, auxRod, toRod);

    cout << "---------------------------------------------------";
    cout << "\nTower of Hanoi with " << n << " disks:\n\n";

    towerOfHanoi(n, fromRod, toRod, auxRod, "Source", "End", "Support", moves);

    cout << "\nNumber of moves required = " << moves << endl;
    return 0;
}