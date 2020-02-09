/*
 * Student.h
 *
 *  Created on: Feb 7, 2020
 *      Author: cahn
 */

#ifndef SRC_STUDENT_H_
#define SRC_STUDENT_H_

#include <vector>
#include <random>

class Student{
public:
	Student();
	virtual ~Student(){}

	//get student id
	int getStudentID();

	// get student average
	float getTotalStudentAverage();

	// get student average
	float getRecentStudentAverage();

	//set answer correct
	void setAnsweredCorrectly(bool);

	static int accountIdGlobal;

private:
	// calculate average from previous responses
	void setStudentAverage();
	// clear last batch
	void resetStudentLastAnswers();
	// student average
	float totalAverage;
	// average in last session
	float lastSessionAverage;
	// student id
	int id;
	// last ten correct
	std::vector<bool> lastTenAnswers;
	// assist in calculating average
	int correctAnswers;
	int incorrectAnswers;

};

#endif /* SRC_STUDENT_H_ */
