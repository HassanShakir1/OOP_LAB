#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

struct Task {
    int id;
    string description;
    string status; // "Pending" or "Done"
};

void addTask() {
    ofstream file("tasks.txt", ios::app);
    if (!file) {
        cout << "Failed to open file." << endl;
        return;
    }

    Task task;
    cout << "Enter Task ID: ";
    cin >> task.id;
    cin.ignore();
    cout << "Enter Task Description (no spaces, use _): ";
    getline(cin, task.description);
    task.status = "Pending";

    file << task.id << " " << task.description << " " << task.status << endl;
    file.close();

    cout << "Task added successfully!\n";
}

void viewTasks() {
    ifstream file("tasks.txt");
    if (!file) {
        cout << "No tasks found.\n";
        return;
    }

    Task task;
    cout << "\n--- To-Do List ---\n";
    while (file >> task.id >> task.description >> task.status) {
        cout << "ID: " << task.id
             << " | Description: " << task.description
             << " | Status: " << task.status << endl;
    }
    file.close();
}

void markTaskDone() {
    ifstream file("tasks.txt");
    if (!file) {
        cout << "No tasks found.\n";
        return;
    }

    vector<Task> tasks;
    Task task;
    while (file >> task.id >> task.description >> task.status) {
        tasks.push_back(task);
    }
    file.close();

    int markId;
    cout << "Enter Task ID to mark as done: ";
    cin >> markId;

    bool found = false;
    for (auto &t : tasks) {
        if (t.id == markId) {
            t.status = "Done";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Task ID not found.\n";
        return;
    }

    ofstream out("tasks.txt");
    for (const auto &t : tasks) {
        out << t.id << " " << t.description << " " << t.status << endl;
    }
    out.close();

    cout << "Task marked as done!\n";
}

int main() {
    while (true) {
        int choice;
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Done\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskDone();
                break;
            case 4:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
