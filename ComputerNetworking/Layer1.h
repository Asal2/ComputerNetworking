#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream getFile("getRequest.txt");
    if (!getFile.is_open()) {
        cout << "Unable to open file." << endl;
        return 1;
    }

    const int NUM_LINES = 8;
    string lines[NUM_LINES];
    string second_words[NUM_LINES];
    int i = 0;
    string line;
    while (getline(getFile, line)) {
        if (i == 0) {
            lines[i] = line.substr(0, line.find("HTTP") + 8);
        }
        else {
            size_t position = line.find(':');
            if (position != std::string::npos) {
                lines[i] = line.substr(position + 2, line.length() - position - 6);
                second_words[i] = line.substr(0, position);
            }
        }
        i++;
    }
    getFile.close();

    // print the second_words array
    for (int i = 1; i < NUM_LINES; i++) {
        cout << second_words[i] << endl;
    }

    // print a blank line for separation
    cout << endl;

    // print the lines array
    cout << lines[0] << endl;
    for (int i = 1; i < NUM_LINES; i++) {
        cout << lines[i] << endl;
    }

    return 0;
}
