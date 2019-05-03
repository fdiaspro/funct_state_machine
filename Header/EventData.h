#pragma once
#
#include <memory>


template <typename payload>
class EventData
{
public:
	
	virtual payload& getEventData() = 0; 
	virtual ~EventData() {};
 
};

