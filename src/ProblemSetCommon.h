/*
 * ProblemSetCommon.h
 *
 *  Created on: Feb 7, 2020
 *      Author: cahn
 */

#ifndef SRC_PROBLEMSETCOMMON_H_
#define SRC_PROBLEMSETCOMMON_H_

namespace PSC{

// struct of difficulties
enum ProblemSetDifficulty{
	EASY,
	MEDIUM,
	HARD
};

// struct of operations
enum ProblemSetArithmetic{
	ADDITION,
	SUBTRACTION,
	MULTIPLY,
	DIVISION,
	RANDOM
};

// struct to contain problem data
struct Problem{
	int operatorOne;
	int operatorTwo;
	double answer;
	char operation;
};

}
#endif /* SRC_PROBLEMSETCOMMON_H_ */
