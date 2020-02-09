/*
 * ProblemSet.h
 *
 *  Created on: Feb 7, 2020
 *      Author: cahn
 */

#ifndef SRC_PROBLEMSET_H_
#define SRC_PROBLEMSET_H_

#include <string>
#include <vector>
#include "ProblemSetCommon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class ProblemSet {
public:
	ProblemSet();
	virtual ~ProblemSet(){};

	// get/set problem difficulty
	void setDifficulty(PSC::ProblemSetDifficulty);
	PSC::ProblemSetDifficulty getDifficulty();

	// get/set problem difficulty
	void setArithmetic(PSC::ProblemSetArithmetic);
	PSC::ProblemSetArithmetic getArithmetic();

	// return new problem set
	std::vector<PSC::Problem>& getQuestions();

	// get reinforcement statements
	const std::string& getPositiveResponse();
	const std::string& getNegativeResponse();

private:
	// create the problem set, using difficulty and arithmetic type
	void generateProblemSet();
	// class member setting for difficulty
	PSC::ProblemSetDifficulty difficulty;
	// class member setting for arithmetic type
	PSC::ProblemSetArithmetic arithmetic;
	// storage of strings
	std::vector<std::string> positiveResponses;
	std::vector<std::string> negativeResponses;
	// collection of problems
	std::vector<PSC::Problem> questions;
};

#endif /* SRC_PROBLEMSET_H_ */
