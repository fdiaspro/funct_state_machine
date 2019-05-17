#pragma once
#include <ostream>
#include <memory>
#include <vector>
#include "FuncStateMachine.h"

typedef enum {
	IDLE =0,
	START,
	STOP,
	CHANGE_SPEED,
	MAX_ENUM_EMS
} engine_machine_state;

std::ostream& operator<<(std::ostream& os, engine_machine_state& p);

class Speed : public EventData<unsigned int>
{
protected:
	unsigned int speed;
	

public:
	Speed() : speed(0) { };
	Speed(unsigned int _s): speed(_s) { };
	virtual ~Speed() ;
	virtual unsigned int& getEventData() { return   speed; };

};


class engineMachineState : public StateMachine<engineMachineState*, Speed>
{
	engine_machine_state ems{ IDLE };
	unsigned int         speed{ 0 };
protected:
        void printInfo() ;
public:
    engineMachineState(){};
    ~engineMachineState(){};
	engineMachineState(engine_machine_state _ems, unsigned int _speed) : ems(_ems), speed(_speed){};
	engine_machine_state& getEms() { return ems; };
	unsigned int         getSpeed() { return speed; };
	void setEms(engine_machine_state _ems) { ems = _ems; };
	void setSpeed(unsigned int _speed) { speed = _speed; };
	virtual engineMachineState* operator()(Speed &p)=0;
        friend std::ostream& operator<<(std::ostream& os, engine_machine_state& p);
};


class IdleState : public engineMachineState
{
public:

	IdleState(): engineMachineState(IDLE, 0) {printInfo() ;};
	engineMachineState* operator()(Speed &p) ;
        virtual ~IdleState(){};
 
};


class StartState : public engineMachineState
{
public:

	StartState(unsigned int speed) : engineMachineState(START, speed) {printInfo() ;};

	engineMachineState* operator()(Speed &p) ;
        virtual ~StartState(){};
};


class StopState : public engineMachineState
{
public:

	StopState() : engineMachineState(STOP, 0) {printInfo() ;};

	engineMachineState* operator()(Speed &p) ;
                virtual ~StopState(){};


};

class ChangeSpeedState : public engineMachineState
{
public:

	ChangeSpeedState(unsigned int speed) : engineMachineState(CHANGE_SPEED, speed) 
        {printInfo() ;};

	engineMachineState* operator()(Speed &p) ;
        virtual  ~ChangeSpeedState(){};

};






 
