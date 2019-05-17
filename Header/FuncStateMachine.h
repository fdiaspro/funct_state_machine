#pragma once


#include <string>
#include "EventData.h"
#include "Functor.h"

template <class State, class EventData>
class StateMachine : FunctorImpl<State,   EventData>
{
public:
    
	 
	virtual ~StateMachine() {};

	virtual State operator() (EventData& p) = 0;
	
	 
};




