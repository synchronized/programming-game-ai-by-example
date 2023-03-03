#ifndef PRECISION_TIMER_H
#define PRECISION_TIMER_H
//-----------------------------------------------------------------------
//
//  Name: PrecisionTimer.h
//
//  Author: Mat Buckland 2002
//
//  Desc: c++ std::chrono timer
//
//        nb. this only uses the high performance timer. There is no
//        support for ancient computers. I know, I know, I should add
//        support, but hey, I have shares in AMD and Intel... Go upgrade ;o)
//
//-----------------------------------------------------------------------
#include <cassert>
#include <chrono>


class PrecisionTimer
{

  private:
    //microsecond time_point
    using Duration = std::chrono::duration<double>;
    using TimePoint = std::chrono::time_point<std::chrono::steady_clock, Duration>;

    TimePoint m_CurrentTime, m_LastTime, m_LastTimeInTimeElapsed,
        m_NextTime, m_StartTime;
    Duration m_FrameTime;

    Duration m_TimeElapsed, m_LastTimeElapsed;

    double    m_NormalFPS;
    double    m_SlowFPS;

    bool      m_bStarted;

    //if true a call to TimeElapsed() will return 0 if the current
    //time elapsed is much smaller than the previous. Used to counter
    //the problems associated with the user using menus/resizing/moving
    //a window etc
    bool      m_bSmoothUpdates;


  public:

    //ctors
    PrecisionTimer();
    PrecisionTimer(double fps);


    //whatdayaknow, this starts the timer
    void    Start();

    //determines if enough time has passed to move onto next frame
    inline bool    ReadyForNextFrame();

    //only use this after a call to the above.
    //double  GetTimeElapsed(){return m_TimeElapsed;}

    inline double  TimeElapsed();

    double  CurrentTime() {
        m_CurrentTime = std::chrono::steady_clock::now();
        Duration dura = (m_CurrentTime - m_StartTime);
        return dura.count();
    }

    bool    Started()const{return m_bStarted;}

    void    SmoothUpdatesOn(){m_bSmoothUpdates = true;}
    void    SmoothUpdatesOff(){m_bSmoothUpdates = false;}

};


//-------------------------ReadyForNextFrame()-------------------------------
//
//  returns true if it is time to move on to the next frame step. To be used if
//  FPS is set.
//
//----------------------------------------------------------------------------
inline bool PrecisionTimer::ReadyForNextFrame() {
    assert(m_NormalFPS && "PrecisionTimer::ReadyForNextFrame<No FPS set in timer>");

    m_CurrentTime = std::chrono::steady_clock::now();

    if (m_CurrentTime > m_NextTime) {
        m_TimeElapsed = (m_CurrentTime - m_LastTime);
        m_LastTime    = m_CurrentTime;

        //update time to render next frame
        m_NextTime = m_CurrentTime + m_FrameTime;

        return true;
    }

    return false;
}

//--------------------------- TimeElapsed --------------------------------
//
//  returns time elapsed since last call to this function.
//-------------------------------------------------------------------------
inline double PrecisionTimer::TimeElapsed() {
    m_LastTimeElapsed = m_TimeElapsed;

    m_CurrentTime = std::chrono::steady_clock::now();

    m_TimeElapsed = (m_CurrentTime - m_LastTimeInTimeElapsed);

    m_LastTimeInTimeElapsed    = m_CurrentTime;

    const double Smoothness = 5.0;

    if (m_bSmoothUpdates) {
        if (m_TimeElapsed < (m_LastTimeElapsed * Smoothness)) {
            return m_TimeElapsed.count();
        } else {
            return 0.0;
        }
    } else {
        return m_TimeElapsed.count();
    }

}



#endif
