#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

const string LOG_FILENAME = "log.txt";
const size_t MAX_SIZE = 1048576; // 1 MB in bytes

int getNextLogIndex() {
    int index = 1;
    while (fs::exists("log" + to_string(index) + ".txt")) {
        index++;
    }
    return index;
}

void rotateLog() {
    int nextIndex = getNextLogIndex();
    string newName = "log" + to_string(nextIndex) + ".txt";
    fs::rename(LOG_FILENAME, newName);
    cout << "[INFO] Log rotated: " << LOG_FILENAME << " -> " << newName << endl;
}

void logMessage(const string& message) {
    if (fs::exists(LOG_FILENAME)) {
        auto fileSize = fs::file_size(LOG_FILENAME);
        if (fileSize >= MAX_SIZE) {
            rotateLog();
        }
    }

    ofstream logFile(LOG_FILENAME, ios::app);
    if (!logFile) {
        cerr << "[ERROR] Failed to open log file." << endl;
        return;
    }

    logFile << message << endl;
    logFile.close();
}

int main() {
    string input;
    cout << "Logging system started. Type 'exit' to quit.\n";

    while (true) {
        cout << "\nEnter log message: ";
        getline(cin, input);
        if (input == "exit") break;
        logMessage(input);
    }

    cout << "Logger exited.\n";
    return 0;
}
