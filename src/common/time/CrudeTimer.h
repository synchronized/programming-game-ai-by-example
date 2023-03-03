#ifndef CRUDETIMER_H
#define CRUDETIMER_H
//------------------------------------------------------------------------
//
//  Name:   CrudeTimer.h
//
//  Desc:   timer to measure time in seconds
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------

//this library must be included

#include <chrono>

#define Clock CrudeTimer::Instance()

class CrudeTimer
{
  private:


    //set to the time (in seconds) when class is instantiated
    std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double, std::milli>> m_dStartTime;

    //set the start time
    CrudeTimer(){m_dStartTime = std::chrono::steady_clock::now();}

    //copy ctor and assignment should be private
    CrudeTimer(const CrudeTimer&);
    CrudeTimer& operator=(const CrudeTimer&);

  public:

    static CrudeTimer* Instance();

    //returns how much time has elapsed since the timer was started
    double GetCurrentTime(){
      auto dura = std::chrono::steady_clock::now() - m_dStartTime;
      return dura.count();
    }
};



#endif
