#include "Miner.h"
#include "misc/ConsoleUtils.h"


//-----------------------------------------------------------------------------
void Miner::Update()
{
  SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);

  m_iThirst += 1;

  m_pStateMachine->Update();
}

//-----------------------------------------------------------------------------
void Miner::AddToGoldCarried(const int val) {
    m_iGoldCarried = std::max(0, m_iGoldCarried + val);
}

//-----------------------------------------------------------------------------
void Miner::AddToWealth(const int val) {
    m_iMoneyInBank = std::max(0, m_iMoneyInBank + val);
}

//-----------------------------------------------------------------------------
bool Miner::Thirsty()const {return (m_iThirst >= ThirstLevel);}


//-----------------------------------------------------------------------------
bool Miner::Fatigued()const {return (m_iFatigue > TirednessThreshold);}
