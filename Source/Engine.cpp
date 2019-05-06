#include "Engine.h"

 
Speed::~Speed() 
{
	//EventData<unsigned int>::~EventData();
}




engineMachineState* IdleState::operator()(Speed &p)
{
	engineMachineState* ptr;

	std::cout << __PRETTY_FUNCTION__ << std::endl;

	if (p.getEventData() == 0)
	{
		return new IdleState();
	}
	else
	{
		ptr = new StartState(p.getEventData());
	}

	
	return ptr;
}


void engineMachineState::printInfo() {
	std::cout << "state " << ems << std::endl;
	std::cout << "speed " << speed << std::endl;
}

engineMachineState* StartState::operator()(Speed &p)
{
	engineMachineState*  ptr;
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	if (p.getEventData() == 0)
	{
		ptr=new StopState();;
	}
	else
	{		
		ptr = new ChangeSpeedState(p.getEventData());
	}


	return ptr;
}


engineMachineState* StopState::operator()(Speed &p)
{
	engineMachineState*  ptr;
	std::cout << __PRETTY_FUNCTION__ << std::endl;
 
	if (p.getEventData() > 0)
	{
		ptr = new StartState(p.getEventData());;
	}
	else
	{
		ptr = new IdleState();
	}


	return ptr;
}

engineMachineState* ChangeSpeedState::operator()(Speed &p)
{
	engineMachineState*  ptr;

	std::cout << __PRETTY_FUNCTION__ << std::endl;

	if (p.getEventData() > 0)
	{
		ptr = new ChangeSpeedState(p.getEventData());;
	}
	else
	{
		ptr = new StopState();
	}


	return ptr;
}

std::ostream& operator<<(std::ostream& os, engine_machine_state& p) {

	switch (p)
	{
	case	IDLE :
		os << "IDLE";
		break;
	case	START:
		os << "START";
		break;
	case	STOP:
		os << "STOP";
			break;
	case	CHANGE_SPEED:
		os << "CHANGE_SPEED";
		break;
	default:
		os << "UNKNOWN STATE";

	}

	return os;
}