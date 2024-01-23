#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed = false;
};

vector<Task> tasks;
string username;

void addTask();
void viewTasks();
void markTaskCompleted();
void removeTask();

int main() {
    cout << "Please enter your name: ";
    getline(cin, username);

    int choice;

    do {
        cout << "\nDear " << username << ", choose an option:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}

void addTask() {
    string description;
    cout << "Enter task description: ";
    getline(cin, description);
    Task newTask = {description, false};
    tasks.push_back(newTask);
    cout << "Task added successfully with sequence number " << tasks.size() << "!" << endl;
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks to display." << endl;
    } else {
        cout << "\nTask List:" << endl;
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].completed) {
                cout << " (Completed)";
            }
            cout << endl;
        }
    }
}

void markTaskCompleted() {
    int taskIndex;
    viewTasks();
    cout << "Enter task number to mark as completed: ";
    cin >> taskIndex;
    if (taskIndex > 0 && taskIndex <= tasks.size()) {
        tasks[taskIndex - 1].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

void removeTask() {
    int taskIndex;
    viewTasks();
    cout << "Enter task number to remove: ";
    cin >> taskIndex;
    if (taskIndex > 0 && taskIndex <= tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex - 1);
        cout << "Task removed successfully." << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}
