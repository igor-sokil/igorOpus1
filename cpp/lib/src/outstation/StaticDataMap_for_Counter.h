/*
 * Copyright 2013-2022 Step Function I/O, LLC
 *
 * Licensed to Green Energy Corp (www.greenenergycorp.com) and Step Function I/O
 * LLC (https://stepfunc.io) under one or more contributor license agreements.
 * See the NOTICE file distributed with this work for additional information
 * regarding copyright ownership. Green Energy Corp and Step Function I/O LLC license
 * this file to you under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef OPENDNP3_STATICDATAMAP_Counter_H
#define OPENDNP3_STATICDATAMAP_Counter_H

////#include "app/MeasurementTypeSpecs.h"
////#include "app/Range.h"
////#include "outstation/IEventReceiver.h"
////#include "outstation/StaticDataCell.h"

////#include "opendnp3/gen/EventMode.h"
////#include "opendnp3/util/Uncopyable.h"

////#include <iterator>
////#include <map>

#include "StaticDataMap.h"
#include "MeasurementTypeSpecs.h"
#include "Range.h"
#include "IEventReceiver.h"
#include "StaticDataCell.h"

#include "EventMode.h"
//#include "opendnp3/util/Uncopyable.h"

//#include <iterator>
#include <map>

////namespace opendnp3
////{

////bool convert_to_event_class(PointClass pc, EventClass& ec);

////template<class Spec>
////typename Spec::static_variation_t check_for_promotion(const typename Spec::meas_t& value,
////                                                      typename Spec::static_variation_t variation)
////{
////    return variation;
////}

////template<> StaticCounterVariation check_for_promotion<CounterSpec>(const Counter& value, StaticCounterVariation variation);


  using map_t_StaticDataMap_for_CounterSpec = std::map<uint16_t, StaticDataCell_for_Counter>;
  using map_iter_t_StaticDataMap_for_CounterSpec = typename map_t_StaticDataMap_for_CounterSpec::iterator;

////template<class Spec> class StaticDataMap : private Uncopyable
//typedef struct
class StaticDataMap_for_CounterSpec
{

public:
////    StaticDataMap() = default;
////    StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config);

  class iterator
  {
    map_iter_t_StaticDataMap_for_CounterSpec iter;
    map_iter_t_StaticDataMap_for_CounterSpec end;
    Range& range;

  public:
    explicit iterator(map_iter_t_StaticDataMap_for_CounterSpec begin,
                      map_iter_t_StaticDataMap_for_CounterSpec end, Range& range) : iter(begin), end(end), range(range) {}

////        using value_type = std::pair<uint16_t, SelectedValue<Spec>>;
    using value_type = std::pair<uint16_t, SelectedValue_for_CounterSpec>;
    using difference_type = typename map_iter_t_StaticDataMap_for_CounterSpec::difference_type;
    using pointer = typename map_iter_t_StaticDataMap_for_CounterSpec::pointer;
////        using reference = std::pair<uint16_t, SelectedValue<Spec>&>;
    using reference = std::pair<uint16_t, SelectedValue_for_CounterSpec&>;
    using iterator_category = std::input_iterator_tag;

    boolean operator==(const iterator& rhs)
    {
      return this->iter == rhs.iter;
    }
    boolean operator!=(const iterator& rhs)
    {
      return this->iter != rhs.iter;
    }

    void operator++()
    {
      // unselect the point
      this->iter->second.selection_in_StaticDataCell.selected = false;

      while (true)
      {
        iter++;

        if (iter == this->end)
        {
////                    this->range = Range::Invalid();
          this->range = Invalid_in_Range_static();
          return;
        }

        // shorten the range
        this->range.start = iter->first;

        if (iter->second.selection_in_StaticDataCell.selected)
        {
          return;
        }
      }
    }

    reference operator*()
    {
      return reference(iter->first, iter->second.selection_in_StaticDataCell);
    }
  };

////    bool add(const typename Spec::meas_t& value, uint16_t index, typename Spec::config_t config);
////
////    bool update(const typename Spec::meas_t& value, uint16_t index, EventMode mode, IEventReceiver& receiver);

////    bool modify(uint16_t start, uint16_t stop, uint8_t flags, IEventReceiver& receiver);
////
////    void clear_selection();

////    bool has_any_selection() const
////    {
////        return this->selected.IsValid();
////    }
////
////    Range get_selected_range() const
////    {
////        return this->selected;
////    }

////    size_t select_all()
////    {
////        return this->select_all([](auto var) { return var; }); // use the default
////    }
////
////    size_t select_all(typename Spec::static_variation_t variation)
////    {
////        return this->select_all([variation](auto var) { return variation; }); // override default
////    }

////    size_t select(Range range)
////    {
////        return this->select(range, [](auto var) { return var; }); // use the default
////    }
////
////    bool select(uint16_t index, typename Spec::static_variation_t variation)
////    {
////        return this->select(Range::From(index, index), variation);
////    }

////    bool select(uint16_t index)
////    {
////        return this->select(Range::From(index, index)) == 1;
////    }
////
////    size_t select(Range range, typename Spec::static_variation_t variation)
////    {
////        return this->select(range, [variation](auto var) { return variation; }); // override default
////    }

////    Range assign_class(PointClass clazz);
////
////    Range assign_class(PointClass clazz, const Range& range);

  iterator begin();

  iterator end();

////private:
  map_t_StaticDataMap_for_CounterSpec map;
  Range selected;

////    Range get_full_range() const;
////
////    bool update(const map_iter_t& iter,
////                const typename Spec::meas_t& new_value,
////                EventMode mode,
////                IEventReceiver& receiver);

  // generic implementation of select_all that accepts a function
  // that can use or override the default variation
// ����� ���������� select_all, ����������� �������
  // ������� ����� ������������ ��� �������������� ������� �� ���������
////    template<class F> size_t select_all(F get_variation);

  // generic implementation of select that accepts a function
  // that can use or override the default variation
// ����� ���������� select, ����������� �������
  // ������� ����� ������������ ��� �������������� ������� �� ���������
////    template<class F> size_t select(Range range, F get_variation);
};

void StaticDataMap_for_CounterSpec_in_StaticDataMap_for_CounterSpecOver1(StaticDataMap_for_CounterSpec *pStaticDataMap);
void StaticDataMap_for_CounterSpec_in_StaticDataMap_for_CounterSpecOver2(StaticDataMap_for_CounterSpec *pStaticDataMap, std::map<uint16_t, CounterConfig>& config);
Range get_selected_range_in_StaticDataMap_for_CounterSpec(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec);

////template<> StaticCounterVariation check_for_promotion<CounterSpec>(const Counter& value, StaticCounterVariation variation);
StaticCounterVariation_uint8_t check_for_promotion_for_CounterSpec_static(Counter* value, StaticCounterVariation_uint8_t variation);

void clear_selection_in_StaticDataMap_for_CounterSpec(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec);

uint16_t select_all_in_StaticDataMap_for_CounterSpecOver1(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec);
uint16_t select_all_in_StaticDataMap_for_CounterSpecOver2(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, StaticCounterVariation_uint8_t variation);

boolean has_any_selection_in_StaticDataMap_for_CounterSpec(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec);

template<class F> uint16_t select_all_for_CounterSpec_staticOver3(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, F get_variation);

////template<class Spec> template<class F> size_t StaticDataMap<Spec>::select_all(F get_variation)
template<class F> uint16_t select_all_in_StaticDataMap_for_CounterSpecOver3(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, F get_variation)
{
//qDebug()<<"";
//qDebug()<<"select_all_in_StaticDataMap_for_CounterSpecOver3_1";

  if (pStaticDataMap_for_CounterSpec->map.empty())
  {
    return 0;
  }
  else
  {
//Range From_in_Range_static(uint16_t start, uint16_t stop);
////        this->selected = Range::From(map.begin()->first, map.rbegin()->first);
    pStaticDataMap_for_CounterSpec->selected = From_in_Range_static(pStaticDataMap_for_CounterSpec->map.begin()->first,
        pStaticDataMap_for_CounterSpec->map.rbegin()->first);

    for (auto& iter : pStaticDataMap_for_CounterSpec->map)
    {
//qDebug()<<"iter___";
// StaticCounterVariation_uint8_t check_for_promotion_for_CounterSpec(Counter* value, StaticCounterVariation_uint8_t variation);
//void SelectedValue_for_CounterSpec_in_SelectedValue_for_CounterSpecOver2(SelectedValue_for_CounterSpec *pSelectedValue_for_CounterSpec,
//                                          boolean selected, Counter* value, StaticCounterVariation_uint8_t variation);
////            iter.second.selection = SelectedValue<Spec>{
////                true, iter.second.value,
////                check_for_promotion<Spec>(iter.second.value, get_variation(iter.second.config.svariation))};
      SelectedValue_for_CounterSpec sSelectedValue_for_CounterSpec;
      SelectedValue_for_CounterSpec_in_SelectedValue_for_CounterSpecOver2(&sSelectedValue_for_CounterSpec,
          true, &iter.second.value_in_StaticDataCell,
          check_for_promotion_for_CounterSpec_static(&iter.second.value_in_StaticDataCell, get_variation(iter.second.config_in_StaticDataCell.
                                             dDeadbandConfig_for_CounterInfo.eEventConfig.svariation)));

      iter.second.selection_in_StaticDataCell = sSelectedValue_for_CounterSpec;
    }//for

//qDebug()<<"map.size= "<<pStaticDataMap_for_CounterSpec->map.size();
    return pStaticDataMap_for_CounterSpec->map.size();
  }
}

uint16_t select_in_StaticDataMap_for_CounterSpecOver1(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, Range range);
boolean select_in_StaticDataMap_for_CounterSpecOver2(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, uint16_t index, StaticCounterVariation_uint8_t variation);
boolean select_in_StaticDataMap_for_CounterSpecOver3(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, uint16_t index);
uint16_t select_in_StaticDataMap_for_CounterSpecOver4(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, Range range, StaticCounterVariation_uint8_t variation);

template<class F> uint16_t select_in_StaticDataMap_for_CounterSpecOver5(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, Range range, F get_variation);
////template<class Spec> template<class F> size_t StaticDataMap<Spec>::select(Range range, F get_variation)
template<class F> uint16_t select_in_StaticDataMap_for_CounterSpecOver5(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, Range range, F get_variation)
{
//boolean IsValid_in_Range(Range *pRange);
////    if (!range.IsValid())
  if (!IsValid_in_Range(&range))
  {
    return 0;
  }

  const auto start = pStaticDataMap_for_CounterSpec->map.lower_bound(range.start);

  if (start == pStaticDataMap_for_CounterSpec->map.end())
  {
    return 0;
  }

//boolean Contains_in_Range(Range *pRange, uint16_t index);
////    if (!range.Contains(start->first))
  if (!Contains_in_Range(&range, start->first))
  {
    return 0;
  }

  uint16_t stop = 0;
  uint16_t count = 0;

  for (auto iter = start; iter != pStaticDataMap_for_CounterSpec->map.end(); ++iter)
  {
////        if (!range.Contains(iter->first))
    if (!Contains_in_Range(&range, iter->first))
    {
      break;
    }

    stop = iter->first;
//StaticBinaryVariation_uint8_t check_for_promotion_for_BinarySpec_static(Analog* value, StaticBinaryVariation_uint8_t variation);
////        iter->second.selection = SelectedValue<Spec>{
////            true, iter->second.value,
////            check_for_promotion<Spec>(iter->second.value, get_variation(iter->second.config.svariation))};
    Counter cCounter = iter->second.value_in_StaticDataCell;
    SelectedValue_for_CounterSpec sSelectedValue_for_CounterSpec = {
      true, cCounter, check_for_promotion_for_CounterSpec_static(&cCounter, get_variation(iter->second.config_in_StaticDataCell.dDeadbandConfig_for_CounterInfo.eEventConfig.svariation))
    };
    iter->second.selection_in_StaticDataCell = sSelectedValue_for_CounterSpec;
    ++count;
  }

//Range Union_in_Range(Range *pRange, Range* other);
//Range From_in_Range_static(uint16_t start, uint16_t stop);
////    this->selected = this->selected.Union(Range::From(start->first, stop));
  Range rRange = From_in_Range_static(start->first, stop);
  pStaticDataMap_for_CounterSpec->selected = Union_in_Range(&(pStaticDataMap_for_CounterSpec->selected), &rRange);

  return count;
}

////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
////{
////    for (const auto& item : config)
////    {
////        this->map[item.first] = StaticDataCell<Spec>{item.second};
////    }
////}

boolean add_in_StaticDataMap_for_CounterSpec(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, Counter *value, uint16_t index, CounterConfig *config);
////template<class Spec>
////bool StaticDataMap<Spec>::add(const typename Spec::meas_t& value, uint16_t index, typename Spec::config_t config)
////{
////    if (this->map.find(index) != this->map.end())
////    {
////        return false;
////    }
////
////    this->map[index] = StaticDataCell<Spec>{value, config};

////    return true;
////}
////
boolean update_in_StaticDataMap_for_CounterSpecOver1(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec,
    Counter* value,
    uint16_t index,
    EventMode_uint8_t mode,
    IEventReceiver* receiver);
////
////template<class Spec>
////bool StaticDataMap<Spec>::update(const typename Spec::meas_t& value,
////                                 uint16_t index,
////                                 EventMode mode,
////                                 IEventReceiver& receiver)
////{
////    return update(this->map.find(index), value, mode, receiver);
////}
////
////template<class Spec> void StaticDataMap<Spec>::clear_selection()
////{
////    // the act of iterating clears the selection
////    for (auto iter = this->begin(); iter != this->end(); ++iter)
////    {
////    }
////}

Range get_full_range_in_StaticDataMap_for_CounterSpec(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec);
////template<class Spec> Range StaticDataMap<Spec>::get_full_range() const
////{
////    return this->map.empty() ? Range::Invalid() : Range::From(this->map.begin()->first, this->map.rbegin()->first);
////}

boolean update_in_StaticDataMap_for_CounterSpecOver2(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec,
    map_iter_t_StaticDataMap_for_CounterSpec & iter,
    Counter* new_value,
    EventMode_uint8_t mode,
    IEventReceiver* receiver);

////template<class Spec>
////bool StaticDataMap<Spec>::update(const map_iter_t& iter,
////                                 const typename Spec::meas_t& new_value,
////                                 EventMode mode,
////                                 IEventReceiver& receiver)
////{
////    if (iter == this->map.end())
////    {
////        return false;
////    }
////
////    if (mode != EventMode::EventOnly)
////    {
////        iter->second.value = new_value;
////    }

////    if (mode == EventMode::Force || mode == EventMode::EventOnly || Spec::IsEvent(iter->second.event.lastEvent, new_value, iter->second.config))
////    {
////        iter->second.event.lastEvent = new_value;
////        if (mode != EventMode::Suppress)
////        {
////            EventClass ec;
////            if (convert_to_event_class(iter->second.config.clazz, ec))
////            {
////                receiver.Update(Event<Spec>(new_value, iter->first, ec, iter->second.config.evariation));
////            }
////        }
////    }

////    return true;
////}

boolean modify_in_StaticDataMap_for_CounterSpec(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec,
    uint16_t start, uint16_t stop, uint8_t flags,
    IEventReceiver* receiver);
////template<class Spec>
////bool StaticDataMap<Spec>::modify(uint16_t start, uint16_t stop, uint8_t flags, IEventReceiver& receiver)
////{
////    if (stop < start)
////    {
////        return false;
////    }
////
////    for (auto iter = this->map.lower_bound(start); iter != this->map.end(); ++iter)
////    {
////        if (iter->first > stop)
////        {
////            return false;
////        }
////
////        auto new_value = iter->second.value;
////        new_value.flags = Flags(flags);
////        this->update(iter, new_value, EventMode::Detect, receiver);
////    }
////
////    return true;
////}
////
////template<class Spec> template<class F> size_t StaticDataMap<Spec>::select_all(F get_variation)
////{
////    if (map.empty())
////    {
////        return 0;
////    }
////    else
////    {
////        this->selected = Range::From(map.begin()->first, map.rbegin()->first);
////
////        for (auto& iter : this->map)
////        {
////            iter.second.selection = SelectedValue<Spec>{
////                true, iter.second.value,
////                check_for_promotion<Spec>(iter.second.value, get_variation(iter.second.config.svariation))};
////        }
////
////        return this->map.size();
////    }
////}
////
////template<class Spec> template<class F> size_t StaticDataMap<Spec>::select(Range range, F get_variation)
////{
////    if (!range.IsValid())
////    {
////        return 0;
////    }
////
////    const auto start = this->map.lower_bound(range.start);
////
////    if (start == this->map.end())
////    {
////        return 0;
////    }

////    if (!range.Contains(start->first))
////    {
////        return 0;
////    }
////
////    uint16_t stop = 0;
////    size_t count = 0;
////
////    for (auto iter = start; iter != this->map.end(); ++iter)
////    {
////        if (!range.Contains(iter->first))
////        {
////            break;
////        }
////
////        stop = iter->first;
////        iter->second.selection = SelectedValue<Spec>{
////            true, iter->second.value,
////            check_for_promotion<Spec>(iter->second.value, get_variation(iter->second.config.svariation))};
////        ++count;
////    }

////    this->selected = this->selected.Union(Range::From(start->first, stop));
////
////    return count;
////}

Range assign_class_in_StaticDataMap_for_CounterSpecOver1(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, PointClass_uint8_t clazz);
////template<class Spec> Range StaticDataMap<Spec>::assign_class(PointClass clazz)
////{
////    for (auto& elem : this->map)
////    {
////        elem.second.config.clazz = clazz;
////    }

////    return this->get_full_range();
////}

Range assign_class_in_StaticDataMap_for_CounterSpecOver2(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, PointClass_uint8_t clazz, Range* range);
////template<class Spec> Range StaticDataMap<Spec>::assign_class(PointClass clazz, const Range& range)
////{
////    for (auto iter = this->map.lower_bound(range.start); iter != this->map.end() && range.Contains(iter->first); iter++)
////    {
////        iter->second.config.clazz = clazz;
////    }

////    return range.Intersection(this->get_full_range());
////}
////
////template<class Spec> typename StaticDataMap<Spec>::iterator StaticDataMap<Spec>::begin()
////{
////    if (!this->selected.IsValid())
////    {
////        return iterator(this->map.end(), this->map.end(), this->selected);
////    }

////    const auto begin = this->map.lower_bound(this->selected.start);
////
////    return iterator(begin, this->map.end(), this->selected);
////}
////
////template<class Spec> typename StaticDataMap<Spec>::iterator StaticDataMap<Spec>::end()
////{
////    return iterator(this->map.end(), this->map.end(), this->selected);
////}

////} // namespace opendnp3

#endif
