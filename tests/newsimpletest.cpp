/* 
 * File:   newsimpletest.cpp
 * Author: Aesys_2018
 *
 * Created on 3-mag-2019, 11.17.23
 */

#include <stdlib.h>
#include <iostream>
#include "Engine.h"


using namespace std;

/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "newsimpletest test 1" << std::endl;
}

void test2() {
    std::cout << "newsimpletest test 2" << std::endl;
    std::cout << "%TEST_FAILED% time=0 testname=test2 (newsimpletest) message=error message sample" << std::endl;
}

int myMain(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (newsimpletest)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (newsimpletest)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;
	//std::unique_ptr<engineMachineState> prtEms ( IdleState);
	engineMachineState* prtEms = new IdleState();



	std::cout << "state machine sample" << endl;
	 
	std::vector<Speed> eventData;

	eventData.push_back( *new Speed()   );
	eventData.push_back( *new Speed(20) );
	eventData.push_back( *new Speed(30) );
	eventData.push_back( *new Speed(40) );
	eventData.push_back( *new Speed(0)  );
	eventData.push_back( *new Speed(0)  );
	eventData.push_back(*new Speed(0));


	for (auto speedEvent : eventData)
	{
		prtEms = prtEms->operator()(speedEvent);
	
	}

    return (EXIT_SUCCESS);
}

