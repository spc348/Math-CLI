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
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int main() {

	// Seed the random number generator
	srand(time(NULL));
	// create vector of students to allow for multiple users
	std::vector<Student> students;
	// student index
	int currentStudent { 0 };
	// first student
	Student student;
	students.push_back(student);

	// Problem instance
	ProblemSet problemSet;
	std::vector<PSC::Problem> problems;

	// Presume new settings are desired
	int sentinel { 3 };
	while (sentinel) {

		cout << "################################################" << endl;
		cout << "Welcome to the Computer Aided Math Instruction" << endl;
		cout << "\n";

		switch (sentinel) {

		case 2: { // create a new user
			Student newStudent;
			students.push_back(newStudent);
			currentStudent++;
		} // case 2
			/* no break */
		case 3: { // ask user for new settings
			// difficulty setting
			cout << "Which level of difficulty would you prefer?" << endl;
			cout << "Enter 0 for easy, 1 for medium, and 2 for hard: " << endl;
			int diff;
			cin >> diff;
			problemSet.setDifficulty(PSC::ProblemSetDifficulty(diff));
			// arithmetic operation settings
			cout << "Which arithmetic operation would you prefer?" << endl;
			cout << "Enter 0 for addition, 1 for subtraction," << endl;
			cout << "2 for multiplication, 3 for division: " << endl;
			cout << "4 for a random operator ( if you dare ): " << endl;
			int arith;
			cin >> arith;
			problemSet.setArithmetic(PSC::ProblemSetArithmetic(arith));
			break;
		} // case 3
		} // end switch

		// always generate a new problem set
		problems = problemSet.getQuestions();
		// output id number for student
		cout << "Welcome, student id ["
				<< students[currentStudent].getStudentID() << "] " << endl;

		// variables needed to iterate over questions
		std::vector<PSC::Problem>::iterator i;
		double studentAnswer;
		// iterator over ten questions
		for (i = problems.begin(); i < problems.end(); i++) {
			cout << "What is " << i->operatorOne << " " << i->operation << " "
					<< i->operatorTwo << "? ";
			// accept answer
			cin >> studentAnswer;
			// compare student answer to correct answer
			bool correct = std::abs(studentAnswer) - std::abs(i->answer) < std::numeric_limits<double>::epsilon();
			// store correctness
			students[currentStudent].setAnsweredCorrectly(correct);
			// display reinforcement
			if (correct) {
				cout << problemSet.getPositiveResponse() << endl;
			} else {
				cout << problemSet.getNegativeResponse() << " ";
				cout << i->operatorOne << " " << i->operation << i->operatorTwo
						<< " = " << i->answer << endl;
			}
		}
		// display final message to student
		if (students[currentStudent].getRecentStudentAverage() < 0.75) {
			cout << "Please ask your teacher for extra help." << endl;
		} else {
			cout << "Fantastic, you are ready for the next level" << endl;
		}
		cout << "################################################" << endl;
		cout << "Thanks for playing" << endl;
		cout << "\n";
		cout << "################################################" << endl;
		cout
				<< "Enter 0 to quit, 1 to try again, 2 for a new player, 3 to change settings"
				<< endl;
		cin >> sentinel;

	}
	cout << "Program Complete" << endl;
}

