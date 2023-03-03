#include "time/PrecisionTimer.h"


//---------------------- default constructor ------------------------------
//
//-------------------------------------------------------------------------
PrecisionTimer::PrecisionTimer(): m_NormalFPS(0.0),
                                  m_SlowFPS(1.0),
                                  m_TimeElapsed(0.0),
                                  m_FrameTime(0),
                                  m_LastTime(),
                                  m_LastTimeInTimeElapsed(),
                                  m_bStarted(false),
                                  m_StartTime(),
                                  m_LastTimeElapsed(0.0),
                                  m_bSmoothUpdates(false)
{
    //how many ticks per sec do we get
}

//---------------------- constructor -------------------------------------
//
//  use to specify FPS
//
//-------------------------------------------------------------------------
PrecisionTimer::PrecisionTimer(double fps): m_NormalFPS(fps),
                                            m_SlowFPS(1.0),
                                            m_TimeElapsed(0.0),
                                            m_FrameTime(0),
                                            m_LastTime(),
                                            m_LastTimeInTimeElapsed(),
                                            m_bStarted(false),
                                            m_StartTime(),
                                            m_LastTimeElapsed(0.0),
                                            m_bSmoothUpdates(false)
{
    //calculate ticks per frame
    Duration second(1.0);
    m_FrameTime = second/m_NormalFPS;
}




//------------------------Start()-----------------------------------------
//
//  call this immediately prior to game loop. Starts the timer (obviously!)
//
//--------------------------------------------------------------------------
void PrecisionTimer::Start()
{
    m_bStarted = true;

    m_TimeElapsed = Duration(0.0);

    // get the time
    m_LastTime = std::chrono::steady_clock::now();

    //keep a record of when the timer was started
    m_StartTime = m_LastTimeInTimeElapsed = m_LastTime;

    //update time to render next frame
    m_NextTime = m_LastTime + m_FrameTime;

    return;
}
