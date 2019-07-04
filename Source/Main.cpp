#include <iostream>
#include <memory>
#include <thread> 

#include <chrono>
#include "Engine.h"


using namespace std;

 

void sendEvent( std::vector<Speed>& eventQueue, unsigned int sleepTime, unsigned int speed)
{
 
    std::chrono::milliseconds dura( sleepTime *1000 );
    std::this_thread::sleep_for( dura );

    eventQueue.push_back( *new Speed(speed) );
    std::this_thread::sleep_for( dura );

    eventQueue.push_back( *new Speed(speed) );
    std::this_thread::sleep_for( dura );

    eventQueue.push_back( *new Speed(speed) );
    std::this_thread::sleep_for( dura );

    eventQueue.push_back( *new Speed(speed) );
    std::this_thread::sleep_for( dura );

    eventQueue.push_back( *new Speed(speed) );
    std::this_thread::sleep_for( dura );
    std::cout <<__PRETTY_FUNCTION__<<"\tend Thread Function" << std::endl;
}
 

void moveEngine(std::vector<Speed>& eventQueue, std::shared_ptr<engineMachineState>& prtEms )
{
    auto start = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double >  elapsed;
    
    while ( true )
        {
            auto now = std::chrono::high_resolution_clock::now();
            elapsed = now-start;            
            if (eventQueue.size() > 0 )
            {
                auto speedEvent = eventQueue.back();
                eventQueue.pop_back() ;
                    std::cout<< "\t\t -------------------" <<std::endl 
                    << "arrived speedEvent  " << speedEvent.getEventData() 
                    << "\telapsed  " << elapsed.count() <<std::endl;
                std::unique_ptr<engineMachineState> ptAppoggio ( prtEms->operator()(speedEvent) );
                prtEms =std::move( ptAppoggio );                 	
            }
            std::chrono::milliseconds dura( 100 );
            std::this_thread::sleep_for( dura );       
            
        }

}


int main(int argc, char** argv)
{
    cout << "state machine example" << endl;

    std::shared_ptr<engineMachineState> prtEms ( new IdleState() );
    std::vector<Speed> eventData;    
    eventData.push_back( *new Speed(10) );//accendiamo il motore

    int time_1=3, time_2=4;
    int speed1=90, speed2=0;
    //engineMachineState* prtEms= (new IdleState());
    std::thread t1(sendEvent, std::ref(eventData),  time_1,speed1);
    std::thread t2(sendEvent, std::ref(eventData),  time_2, speed2);
    std::thread t3(moveEngine, std::ref(eventData), std::ref(prtEms) );
	
    t1.join();
    t2.join(); 
    
        
   }
