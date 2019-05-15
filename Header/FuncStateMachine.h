#pragma once


#include <string>
#include "EventData.h"
#include "Functor.h"

template <class State, class EventData>
class StateMachine : public Functor<  State,   EventData>
{
public:
	
	 
	virtual ~StateMachine() {};

	virtual State operator() (EventData& p) = 0;
	
	 
};




