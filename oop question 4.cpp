#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int id;
    bool feePaid;
    string stop;
public:
    Student(string n, int i, string s) : name(n), id(i), stop(s), feePaid(false) {}
    void payFee() { feePaid = true; }
    bool isFeePaid() { return feePaid; }
    string getStop() { return stop; }
    int getId() { return id; }
};

class BusStop {
private:
    string stopName;
    int studentCount;
    Student* students[10];
public:
    BusStop(string name) : stopName(name), studentCount(0) {}
    void addStudent(Student* student) {
        if (studentCount < 10) students[studentCount++] = student;
    }
    string getName() { return stopName; }
};

class Route {
private:
    string routeName;
    int stopCount;
    BusStop* stops[5];
public:
    Route(string name) : routeName(name), stopCount(0) {}
    void addStop(BusStop* stop) {
        if (stopCount < 5) stops[stopCount++] = stop;
    }
    string getName() { return routeName; }
};

class TransportationSystem {
private:
    Student* students[20];
    int studentCount;
    Route* routes[3];
    int routeCount;
public:
    TransportationSystem() : studentCount(0), routeCount(0) {}
    void registerStudent(string name, int id, string stop) {
        if (studentCount < 20) students[studentCount++] = new Student(name, id, stop);
    }
    void addRoute(Route* route) {
        if (routeCount < 3) routes[routeCount++] = route;
    }
    void markAttendance(int id) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i]->getId() == id) {
                if (students[i]->isFeePaid()) {
                    cout << "Attendance marked for student ID: " << id << "\n";
                } else {
                    cout << "Fee not paid for student ID: " << id << "\n";
                }
                return;
            }
        }
        cout << "Student not found\n";
    }
};

int main() {
    TransportationSystem ts;
    ts.registerStudent("Ali", 101, "Stop A");
    ts.registerStudent("Ahmed", 102, "Stop B");
    ts.markAttendance(101);
    return 0;
}
