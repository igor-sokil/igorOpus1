/*
 * Copyright (c) 2018, Automatak LLC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 * following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 * disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote
 * products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef EXE4CPP_MOCKEXECUTOR_H
#define EXE4CPP_MOCKEXECUTOR_H

////#include "exe4cpp/IExecutor.h"

////#include <algorithm>
////#include <cstddef>
////#include <limits>
////#include <memory>
#include "IExecutorExe4cpp.h"
#include <queue>

#include <functional>   // ��� std::function

////namespace exe4cpp
////{

//typedef std::function<void()> action_t;
//typedef std::deque<action_t> post_queue_t;
typedef std::deque<void*> post_queue_t2;
//typedef void (*pAction)(void);
////    class MockTimer final : public ITimer
typedef struct
{
  ITimer iITimer;
////        friend class MockExecutor;
////
////    public:
////        MockTimer(MockExecutor* source, const steady_time_t& time, const action_t& action) :
////                time{time},
////                source{source},
////                action{action}
////        {}
////
////        // implement ITimer
////        void cancel() override
////        {
////            source->cancel(this);
////        }
////
////        steady_time_t expires_at() override
////        {
////            return this->time;
////        }
////
////    private:
  uint32_t timeMockTimer;
////        MockExecutor* source;
  void* source;
  //action_t action;
  void* action;
} MockTimer;

typedef std::vector<MockTimer> timer_vector_t;

void MockTimer_in_MockTimer(MockTimer *pMockTimer, void* source, uint32_t timeMockTimer, void (*pAction)(void));
void cancel_in_MockTimer(ITimer *pITimer);//MockTimer *pMockTimer);
void cancel_in_MockTimer_override(void *pITimer);
uint32_t expires_at_in_MockTimer(MockTimer *pMockTimer);
uint32_t expires_at_in_MockTimer_override(void *pITimer);

/**
* Mock implementation of IExecutor for testing
*/
////class MockExecutor final : public IExecutor
typedef struct
{
  IExecutorExe4cpp iIExecutorExe4cpp;
////private:
////    class MockTimer final : public ITimer
////    {
////        friend class MockExecutor;
////
////    public:
////        MockTimer(MockExecutor* source, const steady_time_t& time, const action_t& action) :
////                time{time},
////                source{source},
////                action{action}
////        {}
////
////        // implement ITimer
////        void cancel() override
////        {
////            source->cancel(this);
////        }
////
////        steady_time_t expires_at() override
////        {
////            return this->time;
////        }
////
////    private:
////        steady_time_t time;
////        MockExecutor* source;
////        action_t action;
////    };
////
////public:
////    MockExecutor() = default;
////
////    // ------ Implement IExecutor ------
////
////    virtual Timer start(const duration_t& delay, const action_t& action) override
////    {
////        return start(current_time + delay, action);
////    }
////
////    virtual Timer start(const steady_time_t& time, const action_t& action) override
////    {
////        const auto timer = std::make_shared<MockTimer>(this, time, action);
////        this->timers.push_back(timer);
////        return Timer{timer};
////    }

////    virtual void post(const action_t& action) override
////    {
////        this->post_queue.push_back(action);
////    }
////
////    virtual steady_time_t get_time() override
////    {
////        return current_time;
////    }
////
  /**	@return true if an action was run. */
////    bool run_one()
////    {
////        this->check_for_expired_timers();
////
////        if (this->post_queue.size() > 0)
////        {
////            auto runnable = post_queue.front();
////            this->post_queue.pop_front();
////            runnable();
////            return true;
////        }
////        else
////        {
////            return false;
////        }
////    }

  /** Calls RunOne() up to some maximum number of times continuing while
      there are still events to dispatch

      @return the number of events dispatched
  */
////    size_t run_many(size_t maximum = std::numeric_limits<size_t>::max())
////    {
////        size_t num = 0;
////        while (num < maximum && this->run_one()) ++num;
////        return num;
////    }

  /** @return The number of active, pending timers and post operations */
////    size_t num_active() const
////    {
////        return this->post_queue.size();
////    }
////
////    size_t num_pending_timers() const
////    {
////        return this->timers.size();
////    }
////
////    steady_time_t next_timer_expiration_abs() const
////    {
////        auto lt = [](const std::shared_ptr<MockTimer>& lhs, const std::shared_ptr<MockTimer>& rhs)
////        {
////            return lhs->expires_at() < rhs->expires_at();
////        };
////        auto min = std::min_element(this->timers.begin(), this->timers.end(), lt);
////        if (min == this->timers.end())
////        {
////            return steady_time_t();
////        }
////        else
////        {
////            return (*min)->expires_at();
////        }
////    }

////    duration_t next_timer_expiration_rel() const
////    {
////        auto lt = [](const std::shared_ptr<MockTimer>& lhs, const std::shared_ptr<MockTimer>& rhs)
////        {
////            return lhs->expires_at() < rhs->expires_at();
////        };
////        auto min = std::min_element(this->timers.begin(), this->timers.end(), lt);
////        if (min == this->timers.end())
////        {
////            return duration_t::max();
////        }
////        else
////        {
////            return (*min)->expires_at() - this->current_time;
////        }
////    }

////    size_t advance_time(duration_t duration)
////    {
////        this->add_time(duration);
////        return this->check_for_expired_timers();
////    }

  // doesn't check timers_
////    void add_time(duration_t duration)
////    {
////        this->current_time += duration;
////    }
////
////    bool advance_to_next_timer()
////    {
////        if (this->timers.empty())
////        {
////            return false;
////        }
////        else
////        {
////            const  auto timestamp = next_timer_expiration_abs();
////
////            if (timestamp > this->current_time)
////            {
////                this->current_time = timestamp;
////                return true;
////            }
////            else
////            {
////                return false;
////            }
////        }
////    }

////    size_t num_timer_cancel() const
////    {
////        return this->num_timer_cancel_;
////    }
////
////private:
////    size_t check_for_expired_timers()
////    {
////        size_t count = 0;
////        while (find_expired_timer())
////        {
////            ++count;
////        }
////        return count;
////    }

////    bool find_expired_timer()
////    {
////        auto expired = [this](const std::shared_ptr<MockTimer>& timer)
////        {
////            return timer->expires_at() <= this->current_time;
////        };

////        auto iter = std::find_if(this->timers.begin(), this->timers.end(), expired);
////
////        if (iter == this->timers.end())
////        {
////            return false;
////        }
////        else
////        {
  // keep the timer alive until it's callback is completed.
////            auto action = [timer = (*iter), action = (*iter)->action]() -> void { action(); };
////            this->post_queue.push_back(action);
////            this->timers.erase(iter);
////            return true;
////        }
////    }

////    void cancel(ITimer* timer)
////    {
////        const auto result = std::find_if(this->timers.begin(), this->timers.end(), [timer](const std::shared_ptr<MockTimer>& item)
////        {
////            return item.get() == timer;
////        });
////
////        if (result != this->timers.end())
////        {
////            ++num_timer_cancel_;
////            this->timers.erase(result);
////        }
////    }
////
////    typedef std::deque<action_t> post_queue_t;
////    typedef std::vector<std::shared_ptr<MockTimer>> timer_vector_t;

////    steady_time_t current_time;
  uint64_t current_time;
////    size_t num_timer_cancel_ = 0;
  uint16_t num_timer_cancel_;// = 0;

  post_queue_t2 post_queue;
  timer_vector_t timers;
} MockExecutor;

void MockExecutor_in_MockExecutor(MockExecutor *pMockExecutor);
boolean run_one_in_MockExecutor(MockExecutor *pMockExecutor);
uint16_t run_many_in_MockExecutor(MockExecutor *pMockExecutor, uint16_t maximum=100);////size_t maximum = std::numeric_limits<size_t>::max());
uint64_t get_time_in_MockExecutor(MockExecutor *pMockExecutor);

//     TimerExe4cpp (*pStart_in_IExecutorExe4cpp)(void *, uint32_t duration, void (*pAction)(void));////const action_t& action) = 0;
TimerExe4cpp Start_in_MockExecutor(MockExecutor *pMockExecutor, uint32_t duration, void (*pAction)(void));
TimerExe4cpp Start_in_MockExecutor_override(void *pIExecutorExe4cpp, uint32_t duration, void (*pAction)(void));

void post_in_MockExecutor(MockExecutor *pMockExecutor, void (*pAction)(void));
void post_in_MockExecutor_override(void *pIExecutorExe4cpp, void (*pAction)(void));

TimerExe4cpp Start_in_MockExecutorOver2(MockExecutor *pMockExecutor, uint32_t duration, void (*pAction)(void));

void cancel_in_MockExecutor(/*MockExecutor *pMockExecutor,*/ ITimer* timer);

uint16_t advance_time_in_MockExecutor(MockExecutor *pMockExecutor, uint32_t duration);
void add_time_in_MockExecutor(MockExecutor *pMockExecutor, uint32_t duration);

uint16_t num_pending_timers_in_MockExecutor(MockExecutor *pMockExecutor);


////     steady_time_t get_time() override


////}

#endif
