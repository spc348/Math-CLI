/*
 * ProblemSetCommon.h
 *
 *  Created on: Feb 7, 2020
 *      Author: cahn
 */

#ifndef SRC_PROBLEMSETCOMMON_H_
#define SRC_PROBLEMSETCOMMON_H_

namespace PSC{

enum ProblemSetDifficulty{
	EASY,
	MEDIUM,
	HARD
};

enum ProblemSetArithmetic{
	ADDITION,
	SUBTRACTION,
	MULTIPLY,
	DIVISION,
	RANDOM
};

struct Problem{
	int operatorOne;
	int operatorTwo;
	double answer;
	ProblemSetArithmetic operation;
};



}
#endif /* SRC_PROBLEMSETCOMMON_H_ */
