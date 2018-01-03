#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
	static int i_prof;
	static int i_student;
	int age, cur_id;
	string name;
	virtual void putdata() {
		cout << "hello" << endl;
	};
	virtual void getdata() {}
};

int Person::i_prof = 1;
int Person::i_student = 1;

int sum(int marks[6]) {
	int total = 0;
	for (int i = 0; i < 6; i++) total += marks[i];
	return total;
}

class Professor: public Person {
public:
	int publications;
	void getdata();
	void putdata();
};

void Professor::getdata() {
	string n;
	int a, p;

	cin >> n;
	cin >> a;
	cin >> p;

	name = n;
	age = a;
	publications = p;
	cur_id = Person::i_prof;
	Person::i_prof++;
}

void Professor::putdata() {
	cout << name << " " << age << " " << publications << " " << cur_id << endl;
}

class Student: public Person {
public:
	int marks[6];

	void getdata();
	void putdata();
};

void Student::getdata() {
	string n;
	int a;

	cin >> n;
	cin >> a;

	for (int i=0; i < 6; i++) {
		cin >> marks[i];
	}
	
	name = n;
	age = a;
	cur_id = Person::i_student;
	Person::i_student++;
}

void Student::putdata() {
	cout << name << " " << age << " " << sum(marks) << " " << cur_id << endl;
}

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
