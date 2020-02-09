#include "Student.h"

//initialize total account values
int Student::accountIdGlobal{0};

Student::Student() :
		totalAverage{0},
		lastSessionAverage{0},
		id{0},
		lastTenAnswers(10, false ),
		correctAnswers{0},
		incorrectAnswers{0}
{
		this->id = Student::accountIdGlobal++;
		this->lastTenAnswers.clear();
}

int Student::getStudentID(){
	return this->id;
}

float Student::getTotalStudentAverage(){
	return this->totalAverage;
}

float Student::getRecentStudentAverage(){
	setStudentAverage();
	resetStudentLastAnswers();
	return this->lastSessionAverage;
}

void Student::setAnsweredCorrectly(bool correct){
	this->lastTenAnswers.push_back(correct);
	if(correct){
		this->correctAnswers++;
	} else {
		this->incorrectAnswers++;
	}
	this->totalAverage = this->correctAnswers / static_cast<double>(this->correctAnswers+this->incorrectAnswers);
}

void Student::setStudentAverage(){
	int sessionCorrect{0};
	int sessionIncorrect{0};
	std::vector<bool>::iterator i;
	for(i = this->lastTenAnswers.begin(); i < this->lastTenAnswers.end(); i++){
		if(*i){
			sessionCorrect += 1;
		} else {
			sessionIncorrect += 1;
		}
	}
	this->lastSessionAverage = sessionCorrect / static_cast<float>(sessionCorrect+sessionIncorrect);
}

void Student::resetStudentLastAnswers(){
	this->lastTenAnswers.clear();
}
