#include <iostream>
#include <memory>
#include "Engine.h"


using namespace std;


int main(int argc, char** argv)
{
	//std::unique_ptr<engineMachineState> prtEms ( IdleState);
	engineMachineState* prtEms = new IdleState();



	cout << "state machine sample" << endl;
	 
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



}