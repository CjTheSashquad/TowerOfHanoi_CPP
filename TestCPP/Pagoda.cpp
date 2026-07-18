#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Rod {
    string name;
    vector<string> disks;
};

void printRods(const Rod& r1, const Rod& r2, const Rod& r3) {
    auto printRod = [](const Rod&r) {
        cout << r.name << "[";
        for (size_t i = 0; i < r.disks.size(); i++) {
            cout << r.disks[i];
            if (i != r.disks.size() - 1) cout << ",";
        }
        cout << "]";
        };
	cout << "Current Stacks: ";
    printRod(r1);
    cout << " | ";
    printRod(r2);
    cout << " | ";
    printRod(r3);
    cout << endl << "\n";
};

void towerOfHanoi(int n, Rod& from, Rod& to, Rod& aux, Rod& source, Rod& support, Rod& end, int& nMove) {

    if (n == 1) {
        string disk = from.disks.back();
        from.disks.pop_back();
        to.disks.push_back(disk);
        nMove++;
        cout << "Move " << nMove << ": " << disk << " from " << from.name << " to " << to.name << "\n";        
        printRods(source, support, end);
        return;
    }

    towerOfHanoi(n - 1, from, aux, to, source, support, end, nMove);

    string disk = from.disks.back();
    from.disks.pop_back();
    to.disks.push_back(disk);
    nMove++;
    cout << "Move " << nMove << ": " << disk << " from " << from.name << " to " << to.name << "\n";
    printRods(source, support, end);

    towerOfHanoi(n - 1, aux, to, from, source, support, end, nMove);
}

int main() {
    int n = 0, moves = 0, max = 15;
    bool input = false;

    Rod source{ "Source", {} };
    Rod support{ "Support", {} };
    Rod end{ "End", {} };

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

    for (int i = n; i > 0; i--) source.disks.push_back("disk " + to_string(i));

    printRods(source, support, end);

    cout << "---------------------------------------------------";
    cout << "\nTower of Hanoi with " << n << " disks:\n\n";

    towerOfHanoi(n, source, end, support, source, support, end, moves);

    cout << "\nNumber of moves required = " << moves << endl;
    return 0;
}