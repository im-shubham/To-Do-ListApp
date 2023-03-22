#include <iostream>
#include <string>

using namespace std;

struct ToDo {
    string task;
    ToDo* next;
};

class ToDoList {
private:
    ToDo* head;
public:
    ToDoList() {
        head = nullptr;
    }
    void addTask(string newTask) {
        ToDo* newToDo = new ToDo;
        newToDo->task = newTask;
        newToDo->next = head;
        head = newToDo;
    }
    void removeTask(string taskToRemove) {
        ToDo* current = head;
        ToDo* previous = nullptr;
        while (current != nullptr) {
            if (current->task == taskToRemove) {
                if (previous == nullptr) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
                cout << taskToRemove << " has been removed from the list." << endl;
                return;
            }
            previous = current;
            current = current->next;
        }
        cout << taskToRemove << " was not found in the list." << endl;
    }
    void displayTasks() {
        if (head == nullptr) {
            cout << "The to-do list is empty." << endl;
        } else {
            ToDo* current = head;
            cout << "To-Do List:" << endl;
            while (current != nullptr) {
                cout << "- " << current->task << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    ToDoList toDoList;
    string input;
    while (true) {
        cout << "Enter a command (add/remove/display/quit): ";
        getline(cin, input);
        if (input == "add") {
            cout << "Enter a task to add: ";
            getline(cin, input);
            toDoList.addTask(input);
        } else if (input == "remove") {
            cout << "Enter a task to remove: ";
            getline(cin, input);
            toDoList.removeTask(input);
        } else if (input == "display") {
            toDoList.displayTasks();
        } else if (input == "quit") {
            break;
        } else {
            cout << "Invalid command." << endl;
        }
    }
    return 0;
}
