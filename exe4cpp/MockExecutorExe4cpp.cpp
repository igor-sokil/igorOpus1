//#include <QtWidgets>
#include <QApplication>
#include "header.h"
#include "MockExecutorExe4cpp.h"

void MockExecutor_in_MockExecutor(MockExecutor *pMockExecutor)
{
  ISteadyTimeSourceExe4cpp_in_ISteadyTimeSourceExe4cpp(&(pMockExecutor->iIExecutorExe4cpp.iISteadyTimeSourceExe4cpp));

  pMockExecutor->current_time = 333;
  pMockExecutor->num_timer_cancel_ = 0;

  pMockExecutor->iIExecutorExe4cpp.pPost_in_IExecutorExe4cpp = post_in_MockExecutor_override;
  pMockExecutor->iIExecutorExe4cpp.pStart_in_IExecutorExe4cpp = Start_in_MockExecutor_override;

  setParentPointer_in_IExecutorExe4cpp(&(pMockExecutor->iIExecutorExe4cpp), pMockExecutor);
  setParentPointer_in_ISteadyTimeSourceExe4cpp(&(pMockExecutor->iIExecutorExe4cpp.iISteadyTimeSourceExe4cpp), pMockExecutor);
}

/**	@return true if an action was run. */
boolean run_one_in_MockExecutor(MockExecutor *pMockExecutor)
{
////        this->check_for_expired_timers();

  if (pMockExecutor->post_queue.size() > 0)
  {
////            auto runnable = post_queue.front();
    void* runnable = pMockExecutor->post_queue.front();
    pMockExecutor->post_queue.pop_front();
////            runnable();
////---    runnable();
//    VOIDVOID_FUNCTION(runnable)();
    return true;
  }
  else
  {
    return false;
  }
}

void post_in_MockExecutor_override(void *pIExecutorExe4cpp, void (*pAction)(void))
{
  MockExecutor* parent = (MockExecutor*) getParentPointer_in_IExecutorExe4cpp((IExecutorExe4cpp*) pIExecutorExe4cpp);
  post_in_MockExecutor(parent, pAction);
}

void post_in_MockExecutor(MockExecutor *pMockExecutor, void (*pAction)(void))
{
  pMockExecutor->post_queue.push_back((void*)pAction);
}

uint16_t run_many_in_MockExecutor(MockExecutor *pMockExecutor, uint16_t maximum)////size_t maximum = std::numeric_limits<size_t>::max())
{
  uint16_t num = 0;
  while (num < maximum && run_one_in_MockExecutor(pMockExecutor)) ++num;////this->run_one()) ++num;
  return num;
}

uint64_t Get_time_in_ISteadyTimeSourceExe4cpp_override(void* pIExecutorExe4cpp)
{
  MockExecutor* parent = (MockExecutor*) getParentPointer_in_ISteadyTimeSourceExe4cpp(&(((IExecutorExe4cpp*) pIExecutorExe4cpp)->iISteadyTimeSourceExe4cpp));
  return get_time_in_MockExecutor(parent);
}

uint64_t get_time_in_MockExecutor(MockExecutor *pMockExecutor)
{
  return pMockExecutor->current_time;
}

TimerExe4cpp Start_in_MockExecutor_override(void *pIExecutorExe4cpp, uint32_t duration, void (*pAction)(void))
{
  MockExecutor* parent = (MockExecutor*) getParentPointer_in_IExecutorExe4cpp((IExecutorExe4cpp*) pIExecutorExe4cpp);
  return Start_in_MockExecutor(parent, duration, pAction);
}

TimerExe4cpp Start_in_MockExecutor(MockExecutor *pMockExecutor, uint32_t delay, void (*pAction)(void))
{
////        return start(current_time + delay, action);
  return Start_in_MockExecutorOver2(pMockExecutor, pMockExecutor->current_time+delay, pAction);
}

////    virtual Timer start(const duration_t& delay, const action_t& action) override
////    {
////        return start(current_time + delay, action);
////    }

////    virtual Timer start(const steady_time_t& time, const action_t& action) override
TimerExe4cpp Start_in_MockExecutorOver2(MockExecutor *pMockExecutor, uint32_t duration, void (*pAction)(void))
{
//    void MockTimer_in_MockTimer(MockTimer *pMockTimer, void* source, uint32_t timeMockTimer, void (*pAction)(void));
////        const auto timer = std::make_shared<MockTimer>(this, time, action);
  MockTimer timer;
  MockTimer_in_MockTimer(&timer, pMockExecutor, duration, pAction);

  pMockExecutor->timers.push_back(timer);
//   void TimerExe4cpp_in_TimerExe4cpp(TimerExe4cpp *pTimerExe4cpp, ITimer* tim)
////        return Timer{timer};
  TimerExe4cpp tTimerExe4cpp;
  TimerExe4cpp_in_TimerExe4cpp(&tTimerExe4cpp, &(timer.iITimer));
  return tTimerExe4cpp;
}

void cancel_in_MockExecutor(MockExecutor *pMockExecutor, ITimer* timer)
{
////        const auto result = std::find_if(pMockExecutor->timers.begin(), pMockExecutor->timers.end(), [timer](const std::shared_ptr<MockTimer>& item)
////        {
////            return item.get() == timer;
////        });
////
////        if (result != this->timers.end())
////        {
  ++(pMockExecutor->num_timer_cancel_);
////            pMockExecutor->timers.erase(result);
////        }
}

//--------------------------------MockTimer--------------------------------------------
void MockTimer_in_MockTimer(MockTimer *pMockTimer, void* source, uint32_t timeMockTimer, void (*pAction)(void))
{
  pMockTimer->timeMockTimer = timeMockTimer;
  pMockTimer->source = source;
  pMockTimer->action = (void*)pAction;

  pMockTimer->iITimer.pcancel_in_ITimer     = cancel_in_MockTimer_override;
  pMockTimer->iITimer.pexpires_at_in_ITimer = expires_at_in_MockTimer_override;

  setParentPointer_in_ITimer(&(pMockTimer->iITimer), pMockTimer);
}

void cancel_in_MockTimer(MockTimer *pMockTimer)
{
////            source->cancel(this);
  cancel_in_MockExecutor((MockExecutor*)pMockTimer->source, &(pMockTimer->iITimer));
}
void cancel_in_MockTimer_override(void *pITimer)
{
//qDebug()<<"cancel_in_MockTimer_override1";
  MockTimer* parent = (MockTimer*) getParentPointer_in_ITimer((ITimer*) pITimer);
  cancel_in_MockTimer(parent);
}

uint32_t expires_at_in_MockTimer(MockTimer *pMockTimer)
{
  return pMockTimer->timeMockTimer;
}

uint32_t expires_at_in_MockTimer_override(void *pITimer)
{
  MockTimer* parent = (MockTimer*) getParentPointer_in_ITimer((ITimer*) pITimer);
  return expires_at_in_MockTimer(parent);
}

uint16_t advance_time_in_MockExecutor(MockExecutor *pMockExecutor, uint32_t duration)
{
////        this->add_time(duration);
        add_time_in_MockExecutor(pMockExecutor, duration);
        return 0;////this->check_for_expired_timers();
}

  // doesn't check timers_
////    void add_time(duration_t duration)
void add_time_in_MockExecutor(MockExecutor *pMockExecutor, uint32_t duration)
{
////        this->current_time += duration;
  pMockExecutor->current_time += duration;
}
