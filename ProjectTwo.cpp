#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Stores all information for one course.
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

// Binary search tree node used to store courses in alphanumeric order.
struct Node {
    Course course;
    Node* left;
    Node* right;

    explicit Node(const Course& aCourse)
        : course(aCourse), left(nullptr), right(nullptr) {
    }
};

// Removes leading and trailing whitespace from a string.
string trim(const string& text) {
    size_t first = text.find_first_not_of(" \t\r\n");
    if (first == string::npos) {
        return "";
    }

    size_t last = text.find_last_not_of(" \t\r\n");
    return text.substr(first, last - first + 1);
}

// Converts text to uppercase so course searches are case-insensitive.
string toUpper(string text) {
    transform(text.begin(), text.end(), text.begin(),
        [](unsigned char ch) { return static_cast<char>(toupper(ch)); });
    return text;
}

// Inserts a course into the binary search tree according to course number.
Node* insertCourse(Node* node, const Course& course) {
    if (node == nullptr) {
        return new Node(course);
    }

    if (course.courseNumber < node->course.courseNumber) {
        node->left = insertCourse(node->left, course);
    }
    else if (course.courseNumber > node->course.courseNumber) {
        node->right = insertCourse(node->right, course);
    }
    else {
        // Replace a duplicate course number with the latest file entry.
        node->course = course;
    }

    return node;
}

// Searches the binary search tree for a specific course number.
Node* searchCourse(Node* node, const string& courseNumber) {
    if (node == nullptr || node->course.courseNumber == courseNumber) {
        return node;
    }

    if (courseNumber < node->course.courseNumber) {
        return searchCourse(node->left, courseNumber);
    }

    return searchCourse(node->right, courseNumber);
}

// Prints courses in alphanumeric order using an in-order traversal.
void printCourseList(Node* node) {
    if (node == nullptr) {
        return;
    }

    printCourseList(node->left);
    cout << node->course.courseNumber << ", " << node->course.courseTitle << endl;
    printCourseList(node->right);
}

// Deletes all dynamically allocated tree nodes.
void clearTree(Node*& node) {
    if (node == nullptr) {
        return;
    }

    clearTree(node->left);
    clearTree(node->right);
    delete node;
    node = nullptr;
}

// Loads course information from a comma-separated file into the BST.
bool loadCourses(const string& fileName, Node*& root) {
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cout << "Error: Unable to open file '" << fileName << "'." << endl;
        return false;
    }

    // Clear previously loaded data so selecting Option 1 reloads cleanly.
    clearTree(root);

    string line;
    int lineNumber = 0;
    int courseCount = 0;

    while (getline(inputFile, line)) {
        ++lineNumber;

        if (trim(line).empty()) {
            continue;
        }

        vector<string> fields;
        string field;
        stringstream lineStream(line);

        while (getline(lineStream, field, ',')) {
            fields.push_back(trim(field));
        }

        if (fields.size() < 2 || fields[0].empty() || fields[1].empty()) {
            cout << "Error: Invalid course data on line " << lineNumber << "." << endl;
            clearTree(root);
            return false;
        }

        Course course;
        course.courseNumber = toUpper(fields[0]);
        course.courseTitle = fields[1];

        // Any non-empty fields after the title are prerequisite course numbers.
        for (size_t i = 2; i < fields.size(); ++i) {
            if (!fields[i].empty()) {
                course.prerequisites.push_back(toUpper(fields[i]));
            }
        }

        root = insertCourse(root, course);
        ++courseCount;
    }

    inputFile.close();

    if (courseCount == 0) {
        cout << "Error: The file did not contain any course records." << endl;
        return false;
    }

    cout << "Course data loaded successfully. " << courseCount
        << " courses were loaded." << endl;
    return true;
}

// Prints one course and its prerequisite numbers and titles.
void printCourseInformation(Node* root, const string& requestedCourse) {
    string courseNumber = toUpper(trim(requestedCourse));
    Node* found = searchCourse(root, courseNumber);

    if (found == nullptr) {
        cout << "Error: Course " << courseNumber << " was not found." << endl;
        return;
    }

    cout << found->course.courseNumber << ", " << found->course.courseTitle << endl;
    cout << "Prerequisites: ";

    if (found->course.prerequisites.empty()) {
        cout << "None" << endl;
        return;
    }

    for (size_t i = 0; i < found->course.prerequisites.size(); ++i) {
        const string& prereqNumber = found->course.prerequisites[i];
        Node* prerequisite = searchCourse(root, prereqNumber);

        cout << prereqNumber;
        if (prerequisite != nullptr) {
            cout << ", " << prerequisite->course.courseTitle;
        }
        else {
            cout << ", Title unavailable";
        }

        if (i + 1 < found->course.prerequisites.size()) {
            cout << "; ";
        }
    }

    cout << endl;
}

// Displays the required advising program menu.
void displayMenu() {
    cout << "\nWelcome to the course planner." << endl;
    cout << "1. Load Data Structure." << endl;
    cout << "2. Print Course List." << endl;
    cout << "3. Print Course." << endl;
    cout << "9. Exit" << endl;
    cout << "What would you like to do? ";
}

int main() {
    Node* root = nullptr;
    bool dataLoaded = false;
    string input;

    while (true) {
        displayMenu();
        getline(cin, input);
        input = trim(input);

        int choice;
        try {
            size_t processed = 0;
            choice = stoi(input, &processed);
            if (processed != input.length()) {
                throw invalid_argument("extra characters");
            }
        }
        catch (...) {
            cout << "Error: Please enter 1, 2, 3, or 9." << endl;
            continue;
        }

        if (choice == 1) {
            string fileName;
            cout << "Enter the course data file name: ";
            getline(cin, fileName);
            fileName = trim(fileName);

            dataLoaded = loadCourses(fileName, root);
        }
        else if (choice == 2) {
            if (!dataLoaded) {
                cout << "Error: Please load the course data first using Option 1." << endl;
            }
            else {
                cout << "\nHere is a sample schedule:" << endl;
                printCourseList(root);
            }
        }
        else if (choice == 3) {
            if (!dataLoaded) {
                cout << "Error: Please load the course data first using Option 1." << endl;
            }
            else {
                string courseNumber;
                cout << "What course do you want to know about? ";
                getline(cin, courseNumber);
                printCourseInformation(root, courseNumber);
            }
        }
        else if (choice == 9) {
            cout << "Thank you for using the course planner!" << endl;
            break;
        }
        else {
            cout << "Error: " << choice << " is not a valid option." << endl;
        }
    }

    clearTree(root);
    return 0;
}