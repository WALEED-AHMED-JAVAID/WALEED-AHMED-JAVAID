#include <iostream>
#include <string>

using namespace std;

class Mentor;

class Skill {
    int skillid;
    string skillname;
    string description;

public:
    Skill(int id, string n, string des) { 
        skillid = id;
        skillname = n;
        description = des;
    }

    void showskilldetails() {
        cout << "SKILL: " << skillname << " - " << description << endl; 
    }

    void updateskilldescription(string newdes) {
        description = newdes;
    }
};

class Sport {
    int sportid;
    string name;
    string description;
    string requiredskills[10]; 
    int skillcount = 0;

public:
    Sport(int id, string n, string desc) { 
        sportid = id;
        name = n;
        description = desc; 
    }

    void addskill(string skill) {
        if (skillcount < 10) {
            requiredskills[skillcount++] = skill;
        } else {
            cout << "Skill list full" << endl;
        }
    }

    void removeskill(string skill) {
        for (int i = 0; i < skillcount; i++) { 
            if (requiredskills[i] == skill) {
                for (int j = i; j < skillcount - 1; j++) {
                    requiredskills[j] = requiredskills[j + 1];
                }
                skillcount--;
                return;
            }
        }
        cout << "Skill not found in list " << name << endl;
    }
};

class Student {
public:
    int studentid;
    string name;
    int age;
    string sportsinterest[3]; 
    Mentor* mentorassigned;

    Student(int id, string n, int a) {
        studentid = id;
        name = n;
        age = a;
        mentorassigned = nullptr;
    }

    void registerformentorship(Mentor* m);
    void viewmentordetails();
    void updatesportsinterest(string s, int index) {
        if (index >= 0 && index < 3) {
            sportsinterest[index] = s;
            cout << "Sports interest updated" << endl;
        } else {
            cout << "Choose between 0 and 2" << endl;
        }
    }
};

class Mentor {
public:
    int mentorid;
    string name;
    string sportexpertise[3];
    int maxlearners;
    Student* assignedlearners[3]; 
    int learnercount;

    Mentor(int id, string n, int max) {
        mentorid = id;
        name = n;
        maxlearners = max;
        learnercount = 0;
    }

    void assignlearner(Student* s) {
        if (learnercount < maxlearners) { 
            assignedlearners[learnercount++] = s;
            s->mentorassigned = this;
            cout << s->name << " assigned to mentor " << name << endl;
        } else {
            cout << "Mentor at full capacity" << endl;
        }
    }

    void removelearner(Student* s) {
        for (int i = 0; i < learnercount; i++) {
            if (assignedlearners[i] == s) {
                for (int j = i; j < learnercount - 1; j++) {
                    assignedlearners[j] = assignedlearners[j + 1];
                }
                learnercount--;
                s->mentorassigned = nullptr;
                cout << s->name << " removed from mentorship of " << name << endl;
                return;
            }
        }
        cout << s->name << " not assigned to mentor " << name << endl;
    }

    void viewlearners() {
        for (int i = 0; i < learnercount; i++) {
            cout << "- " << assignedlearners[i]->name << endl;
        }
    }

    void provideguidance() {
        cout << name << " is providing guidance to students" << endl;
    }
};


void Student::registerformentorship(Mentor* m) { // Fixed function name
    if (m->learnercount < m->maxlearners) {
        m->assignlearner(this);
    } else {
        cout << "Mentor is full" << endl;
    }
}

void Student::viewmentordetails() { 
    if (mentorassigned) {
        cout << "Mentor - " << mentorassigned->name << " assigned" << endl;
    } else {
        cout << "No mentor assigned" << endl;
    }
}

int main() {
    
	 Mentor ali(1, "Ali", 3);
    Student saad(101, "Saad", 20);
    Student ahmed(102, "Ahmed", 21);
    Student bilal(103, "Bilal", 22);

    Sport tennis(1, "Tennis", "A racket sport");
    Skill forehand(1, "Forehand", "Basic tennis shot");

   

    saad.registerformentorship(&ali);
    ahmed.registerformentorship(&ali);
    bilal.registerformentorship(&ali);

    saad.viewmentordetails();
    ali.viewlearners();

    ali.provideguidance();

    ali.removelearner(&ahmed);
    ali.viewlearners();
	return 0; 
}
