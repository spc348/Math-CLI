#include "ProblemSet.h"

ProblemSet::ProblemSet() :
		difficulty { PSC::EASY }, arithmetic { PSC::MULTIPLY }, positiveResponses(
				5, " "), negativeResponses(5, " ") {
}

void ProblemSet::setDifficulty(PSC::ProblemSetDifficulty selectedDifficulty) {
	this->difficulty = selectedDifficulty;
}

PSC::ProblemSetDifficulty ProblemSet::getDifficulty() {
	return this->difficulty;
}

void ProblemSet::setArithmetic(PSC::ProblemSetArithmetic selectedArithmetic) {
	this->arithmetic = selectedArithmetic;
}

PSC::ProblemSetArithmetic ProblemSet::getArithmetic() {
	return this->arithmetic;
}

std::vector<PSC::Problem>& ProblemSet::getQuestions() {
	generateProblemSet();
	return this->questions;
}

void ProblemSet::generateProblemSet() {
	this->questions.clear();
	int modulator;
	switch (this->difficulty) {
	case PSC::EASY:
		modulator = 10;
		break;
	case PSC::MEDIUM:
		modulator = 100;
		break;
	case PSC::HARD:
		modulator = 1000;
		break;
	default:
		break;
	}

	for (int i = 0; i < 10; i++) {
		struct PSC::Problem problem;
		problem.operatorOne = rand() % modulator;
		problem.operatorTwo = rand() % modulator;

		PSC::ProblemSetArithmetic localArithmetic { this->arithmetic };
		if (localArithmetic == PSC::RANDOM) {
			localArithmetic =
					static_cast<PSC::ProblemSetArithmetic>(rand() % 4);
		}

		switch (localArithmetic) {
		case PSC::ADDITION:
			problem.answer = problem.operatorOne + problem.operatorTwo;
			problem.operation = PSC::ADDITION;
			break;
		case PSC::SUBTRACTION:
			problem.answer = problem.operatorOne - problem.operatorTwo;
			problem.operation = PSC::SUBTRACTION;
			break;
		case PSC::MULTIPLY:
			problem.answer = problem.operatorOne * problem.operatorTwo;
			problem.operation = PSC::MULTIPLY;
			break;
		case PSC::DIVISION:
			while(problem.operatorTwo <= 0){
				problem.operatorTwo = rand() % modulator;
			}
			if(problem.operatorOne < problem.operatorTwo){
				int temp = problem.operatorOne;
				problem.operatorOne = problem.operatorTwo;
				problem.operatorTwo = temp;
			}
			problem.answer = problem.operatorOne / static_cast<double>(problem.operatorTwo);
			break;
		default:
			std::cout << "accidentally miscounted" << std::endl;
			break;
		}
		this->questions.push_back(problem);
	}
}
