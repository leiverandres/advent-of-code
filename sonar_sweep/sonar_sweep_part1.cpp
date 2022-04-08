#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string line;
    ifstream input_file("input.txt");
    if (input_file.is_open()) {
        int prev_measurement = -1;
        // counts measurements that are larger than the previous measurement
        int counter = 0;
        while (getline(input_file, line)) {
            int new_measurement = stoi(line);
            if (new_measurement > prev_measurement and prev_measurement != -1) {
                counter++;
            }
            prev_measurement = new_measurement;
        }
        cout << "counter: " << counter << endl;
        input_file.close();
    }
    return 0;
}