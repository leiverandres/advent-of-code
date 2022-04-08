#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

/*
Traverse the queue and hold two sums used for comparing the sliding windows.
N0 -> prev_sum
N1 -> prev_sum & lastest_sum
N2 -> prev_sum & lastest_sum
N3 ->            lastest_sum
*/
bool decreased(const queue<int>& q) {
    queue<int> q_copy = q;
    int last_window_sum = 0;
    int prev_window_sum = 0;
    int sum_watcher = 0;
    while (!q_copy.empty()) {
        if (sum_watcher <= 2) {
            prev_window_sum += q_copy.front();
        }
        if (sum_watcher >= 1) {
            last_window_sum += q_copy.front();
        }
        q_copy.pop();
        sum_watcher++;
    }
    if (last_window_sum > prev_window_sum) { // decreasing
        return true;
    }
    return false;
}

int main () {
    ifstream input_file("input.txt");
    string line;
    if (input_file.is_open()) {
        queue<int> measurements_queue;
        int counter = 0;
        while (getline(input_file, line)) {
            int new_value = stoi(line);
            measurements_queue.push(new_value);
            if (measurements_queue.size() == 4) {
                if (decreased(measurements_queue)) {
                    counter++;
                }
                measurements_queue.pop();
            }
        }
        cout << "counter: " << counter << endl;
    }
    return 0;
}