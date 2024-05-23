#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class ReadClass {
private:
    string filename;
    vector<string> classNames;

    void readFile() {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }
        string line;
        while (getline(file, line)) {
            parseClass(line);
        }
        file.close();
    }

    void parseClass(const string& line) {
        size_t pos = line.find("class ");
        if (pos != string::npos) {
            size_t start = pos + 6; // 6 is the length of "class "
            size_t end = line.find("{", start);
            if (end != string::npos) {
                string className = line.substr(start, end - start);
                className.erase(className.find_last_not_of(" \t\n\r\f\v") + 1); // Trim trailing whitespace
                classNames.push_back(className);
            }
        }
    }

public:
    ReadClass(const string& file) : filename(file) {
        readFile();
    }

    void showClass() const {
        cout << classNames.size() << " classes in main.cpp" <<  endl;
        for (const string& className : classNames) {
            cout << "class " << className << endl;
        }
    }
};

int main() {
    string filename = "main.cpp";
    ReadClass rfile(filename);
    rfile.showClass();

    return 0;
}
