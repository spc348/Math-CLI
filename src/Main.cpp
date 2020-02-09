/*
 * Main.cpp
 *
 *  Created on: Feb 7, 2020
 *      Author: cahn
 */

#include <iostream>
#include "Student.h"
#include "ProblemSet.h"
#include "ProblemSetCommon.h"
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int main() {

	srand(time(NULL));

	std::vector<Student> students;
	int currentStudent { 0 };
	// first student
	Student student;
	students.push_back(student);
	ProblemSet problemSet;
	std::vector<PSC::Problem> problems;

	int sentinel { 3 };
	while (sentinel) {

		switch (sentinel) {
		case 2: {
			Student newStudent;
			students.push_back(newStudent);
			currentStudent++;
		}
			/* no break */
		case 3: {
			cout << "Settings" << endl;
			cout << "Which level of difficulty would you prefer?" << endl;
			cout << "Enter 0 for easy, 1 for medium, and 2 for hard: " << endl;
			int diff;
			cin >> diff;
			problemSet.setDifficulty(PSC::ProblemSetDifficulty(diff));
			cout << "Which arithmetic operation would you prefer?" << endl;
			cout << "Enter 0 for addition, 1 for subtraction," << endl;
			cout << "2 for multiplication, 3 for division: " << endl;
			cout << "4 for a random operator ( if you dare ): " << endl;
			int arith;
			cin >> arith;
			problemSet.setArithmetic(PSC::ProblemSetArithmetic(arith));
			break;
			default:
			break;
		}
		} // end switch

		// always generate a new problem set
		problems = problemSet.getQuestions();

		cout << "student id " << students[currentStudent].getStudentID()
				<< endl;

		for (int i = 0; i < 10; i++) {
			cout << problems[i].operatorOne << " " << problems[i].operatorTwo
					<< " " << problems[i].answer << endl;
			students[currentStudent].setAnsweredCorrectly(i % 2 == 0);
		}

		cout << "total" << students[currentStudent].getTotalStudentAverage()
				<< endl;
		cout << "recent " << students[currentStudent].getRecentStudentAverage()
				<< endl;

		cout
				<< "Enter 0 to quit, 1 to try again, 2 for a new player, 3 to change settings"
				<< endl;
		cin >> sentinel;

	}
	cout << "Program Complete" << endl;
}

