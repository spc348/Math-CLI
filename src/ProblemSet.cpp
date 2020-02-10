#include "ProblemSet.h"

ProblemSet::ProblemSet() :
		difficulty { PSC::EASY }, arithmetic { PSC::MULTIPLY }, positiveResponses(
				5), negativeResponses(5) {

	// read in reinforcement statements from a file
	reinforcementStatements.open("Reinforcement.txt");
	if (!reinforcementStatements) { // error checking
		std::cerr << "Reinforcement file not found.\n";
	}
	std::string readLine;
	positiveResponses.clear();
	negativeResponses.clear();
	// assume positive starts first
	bool positive { true };
	// read in all file
	while (getline(reinforcementStatements, readLine)) {
		// add positive statements to the positive vector
		if (readLine.compare(POSITIVE_HEADER) == 0) {
			positive = true;
			continue;
			// add negative statements to negative vector
		} else if (readLine.compare(NEGATIVE_HEADER) == 0) {
			positive = false;
			continue;
		}
		// clear out any new line characters
		readLine.erase(std::remove(readLine.begin(), readLine.end(), '\n'),
				readLine.end());

		// push to correct vector
		if (positive) {
			positiveResponses.push_back(readLine);
		} else {
			negativeResponses.push_back(readLine);
		}
	}
	// file reading finished
	reinforcementStatements.close();
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

const std::string& ProblemSet::getPositiveResponse() {
	// randomize selected response
	int index = rand() % positiveResponses.size();
	return positiveResponses[index];
}

const std::string& ProblemSet::getNegativeResponse() {
	// randomize selected response
	int index = rand() % negativeResponses.size();
	return negativeResponses[index];
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

	// push back 10 questions
	for (int i = 0; i < 10; i++) {
		struct PSC::Problem problem;
		// select random numbers
		problem.operatorOne = rand() % modulator;
		// reduce size of second operator for division to avoid very small answers
		problem.operatorTwo = rand() % modulator;

		// select random operation if selected
		PSC::ProblemSetArithmetic localArithmetic { this->arithmetic };
		if (localArithmetic == PSC::RANDOM) {
			localArithmetic =
					static_cast<PSC::ProblemSetArithmetic>(rand() % 4);
		}

		// complete operation and assign necessary variables to problem struct
		// store operation character for output
		switch (localArithmetic) {
		case PSC::ADDITION:
			problem.answer = problem.operatorOne + problem.operatorTwo;
			problem.operation = '+';
			break;
		case PSC::SUBTRACTION:
			if (this->difficulty != PSC::EASY) {
				// swap if second value greater than first
				// to avoid negative answers
				if (problem.operatorOne < problem.operatorTwo) {
					swapValues(&problem);
				}
			}
			problem.answer = problem.operatorOne - problem.operatorTwo;
			problem.operation = '-';
			break;
		case PSC::MULTIPLY:
			problem.answer = problem.operatorOne * problem.operatorTwo;
			problem.operation = 'x';
			break;
		case PSC::DIVISION:
			// ensure division does not cause divide by 0
			while (problem.operatorOne <= 0) {
				problem.operatorOne = rand() % modulator;
			}
			while (problem.operatorTwo <= 0) {
				problem.operatorTwo = rand() % modulator;
			}
			// swap if second value greater than first
			if (problem.operatorOne < problem.operatorTwo) {
				swapValues(&problem);
			}
			problem.answer = problem.operatorOne
					/ static_cast<double>(problem.operatorTwo);
			problem.operation = '/';
			break;
		default:
			break;
		}
		this->questions.push_back(problem);
	}
}

void ProblemSet::swapValues(PSC::Problem* problem) {
	int temp = problem->operatorOne;
	problem->operatorOne = problem->operatorTwo;
	problem->operatorTwo = temp;
}
