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
#ifndef OPENDNP3_STATICDATAMAP_Analog_H
#define OPENDNP3_STATICDATAMAP_Analog_H

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

using map_t_StaticDataMap_for_AnalogSpec = std::map<uint16_t, StaticDataCell_for_Analog>;
using map_iter_t_StaticDataMap_for_AnalogSpec = typename map_t_StaticDataMap_for_AnalogSpec::iterator;

////template<class Spec> class StaticDataMap : private Uncopyable
//typedef struct
class StaticDataMap_for_AnalogSpec
{

public:
////    StaticDataMap() = default;
////    StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config);

  class iterator
  {
    map_iter_t_StaticDataMap_for_AnalogSpec iter;
    map_iter_t_StaticDataMap_for_AnalogSpec end;
    Range& range;

  public:
    explicit iterator(map_iter_t_StaticDataMap_for_AnalogSpec begin,
                      map_iter_t_StaticDataMap_for_AnalogSpec end, Range& range) : iter(begin), end(end), range(range) {}

////        using value_type = std::pair<uint16_t, SelectedValue<Spec>>;
    using value_type = std::pair<uint16_t, SelectedValue_for_AnalogSpec>;
    using difference_type = typename map_iter_t_StaticDataMap_for_AnalogSpec::difference_type;
    using pointer = typename map_iter_t_StaticDataMap_for_AnalogSpec::pointer;
////        using reference = std::pair<uint16_t, SelectedValue<Spec>&>;
    using reference = std::pair<uint16_t, SelectedValue_for_AnalogSpec&>;
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
  map_t_StaticDataMap_for_AnalogSpec map;
  Range selected;

////    Range get_full_range() const;
////
////    bool update(const map_iter_t& iter,
////                const typename Spec::meas_t& new_value,
////                EventMode mode,
////                IEventReceiver& receiver);

  // generic implementation of select_all that accepts a function
  // that can use or override the default variation
// общая реализация select_all, принимающая функцию
  // который может использовать или переопределить вариант по умолчанию
////    template<class F> size_t select_all(F get_variation);

  // generic implementation of select that accepts a function
  // that can use or override the default variation
// общая реализация select, принимающая функцию
  // который может использовать или переопределить вариант по умолчанию
////    template<class F> size_t select(Range range, F get_variation);
};

void StaticDataMap_for_AnalogSpec_in_StaticDataMap_for_AnalogSpecOver1(StaticDataMap_for_AnalogSpec *pStaticDataMap);
void StaticDataMap_for_AnalogSpec_in_StaticDataMap_for_AnalogSpecOver2(StaticDataMap_for_AnalogSpec *pStaticDataMap, std::map<uint16_t, AnalogConfig>& config);
Range get_selected_range_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec);

////template<> StaticAnalogVariation check_for_promotion<AnalogSpec>(const Analog& value, StaticAnalogVariation variation);
StaticAnalogVariation_uint8_t check_for_promotion_for_AnalogSpec_static(Analog* value, StaticAnalogVariation_uint8_t variation);

void clear_selection_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec);

uint16_t select_all_in_StaticDataMap_for_AnalogSpecOver1(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec);
uint16_t select_all_in_StaticDataMap_for_AnalogSpecOver2(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, StaticAnalogVariation_uint8_t variation);

boolean has_any_selection_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec);

template<class F> uint16_t select_all_for_AnalogSpec_staticOver3(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, F get_variation);

////template<class Spec> template<class F> size_t StaticDataMap<Spec>::select_all(F get_variation)
template<class F> uint16_t select_all_in_StaticDataMap_for_AnalogSpecOver3(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, F get_variation)
{
  if (pStaticDataMap_for_AnalogSpec->map.empty())
  {
    return 0;
  }
  else
  {
//Range From_in_Range_static(uint16_t start, uint16_t stop);
////        this->selected = Range::From(map.begin()->first, map.rbegin()->first);
    pStaticDataMap_for_AnalogSpec->selected = From_in_Range_static(pStaticDataMap_for_AnalogSpec->map.begin()->first,
        pStaticDataMap_for_AnalogSpec->map.rbegin()->first);

    for (auto& iter : pStaticDataMap_for_AnalogSpec->map)
    {
//qDebug()<<"iter___";
// StaticAnalogVariation_uint8_t check_for_promotion_for_AnalogSpec(Analog* value, StaticAnalogVariation_uint8_t variation);
//void SelectedValue_for_AnalogSpec_in_SelectedValue_for_AnalogSpecOver2(SelectedValue_for_AnalogSpec *pSelectedValue_for_AnalogSpec,
//                                          boolean selected, Analog* value, StaticAnalogVariation_uint8_t variation);
////            iter.second.selection = SelectedValue<Spec>{
////                true, iter.second.value,
////                check_for_promotion<Spec>(iter.second.value, get_variation(iter.second.config.svariation))};
      SelectedValue_for_AnalogSpec sSelectedValue_for_AnalogSpec;
      SelectedValue_for_AnalogSpec_in_SelectedValue_for_AnalogSpecOver2(&sSelectedValue_for_AnalogSpec,
          true, &iter.second.value_in_StaticDataCell,
          check_for_promotion_for_AnalogSpec_static(&iter.second.value_in_StaticDataCell, get_variation(iter.second.config_in_StaticDataCell.
              dDeadbandConfig_for_AnalogInfo.eEventConfig.svariation)));

      iter.second.selection_in_StaticDataCell = sSelectedValue_for_AnalogSpec;
    }//for

//qDebug()<<"map.size= "<<pStaticDataMap_for_AnalogSpec->map.size();
    return pStaticDataMap_for_AnalogSpec->map.size();
  }
}

uint16_t select_in_StaticDataMap_for_AnalogSpecOver1(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, Range range);
boolean select_in_StaticDataMap_for_AnalogSpecOver2(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, uint16_t index, StaticAnalogVariation_uint8_t variation);
boolean select_in_StaticDataMap_for_AnalogSpecOver3(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, uint16_t index);
uint16_t select_in_StaticDataMap_for_AnalogSpecOver4(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, Range range, StaticAnalogVariation_uint8_t variation);

template<class F> uint16_t select_in_StaticDataMap_for_AnalogSpecOver5(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, Range range, F get_variation);
////template<class Spec> template<class F> size_t StaticDataMap<Spec>::select(Range range, F get_variation)
template<class F> uint16_t select_in_StaticDataMap_for_AnalogSpecOver5(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, Range range, F get_variation)
{
//boolean IsValid_in_Range(Range *pRange);
////    if (!range.IsValid())
  if (!IsValid_in_Range(&range))
  {
    return 0;
  }

  const auto start = pStaticDataMap_for_AnalogSpec->map.lower_bound(range.start);

  if (start == pStaticDataMap_for_AnalogSpec->map.end())
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

  for (auto iter = start; iter != pStaticDataMap_for_AnalogSpec->map.end(); ++iter)
  {
////        if (!range.Contains(iter->first))
    if (!Contains_in_Range(&range, iter->first))
    {
      break;
    }

    stop = iter->first;
//StaticAnalogVariation_uint8_t check_for_promotion_for_AnalogSpec_static(Analog* value, StaticAnalogVariation_uint8_t variation);
////        iter->second.selection = SelectedValue<Spec>{
////            true, iter->second.value,
////            check_for_promotion<Spec>(iter->second.value, get_variation(iter->second.config.svariation))};
    Analog aAnalog = iter->second.value_in_StaticDataCell;
    SelectedValue_for_AnalogSpec sSelectedValue_for_AnalogSpec = {
      true, aAnalog, check_for_promotion_for_AnalogSpec_static(&aAnalog, get_variation(iter->second.config_in_StaticDataCell.dDeadbandConfig_for_AnalogInfo.eEventConfig.svariation))
    };
    iter->second.selection_in_StaticDataCell = sSelectedValue_for_AnalogSpec;
    ++count;
  }

//Range Union_in_Range(Range *pRange, Range* other);
//Range From_in_Range_static(uint16_t start, uint16_t stop);
////    this->selected = this->selected.Union(Range::From(start->first, stop));
  Range rRange = From_in_Range_static(start->first, stop);
  pStaticDataMap_for_AnalogSpec->selected = Union_in_Range(&(pStaticDataMap_for_AnalogSpec->selected), &rRange);

  return count;
}

////template<class Spec> template<class F> size_t StaticDataMap<Spec>::select_all(F get_variation)

////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
////{
////    for (const auto& item : config)
////    {
////        this->map[item.first] = StaticDataCell<Spec>{item.second};
////    }
////}

boolean add_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, Analog *value, uint16_t index, AnalogConfig *config);
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
////template<>
////bool StaticDataMap<TimeAndIntervalSpec>::update(const TimeAndInterval& value,
////                                                uint16_t index,
////                                                EventMode mode,
////                                                IEventReceiver& receiver);
////
////template<class Spec>
////bool StaticDataMap<Spec>::update(const typename Spec::meas_t& value,
////                                 uint16_t index,
////                                 EventMode mode,
////                                 IEventReceiver& receiver)
boolean update_in_StaticDataMap_for_AnalogSpecOver1(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec,
    Analog* value,
    uint16_t index,
    EventMode_uint8_t mode,
    IEventReceiver* receiver);

////template<class Spec> void StaticDataMap<Spec>::clear_selection()
////{
////    // the act of iterating clears the selection
////    for (auto iter = this->begin(); iter != this->end(); ++iter)
////    {
////    }
////}

Range get_full_range_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec);
////template<class Spec> Range StaticDataMap<Spec>::get_full_range() const
////{
////    return this->map.empty() ? Range::Invalid() : Range::From(this->map.begin()->first, this->map.rbegin()->first);
////}

////template<class Spec>
////bool StaticDataMap<Spec>::update(const map_iter_t& iter,
////                                 const typename Spec::meas_t& new_value,
////                                 EventMode mode,
////                                 IEventReceiver& receiver)
boolean update_in_StaticDataMap_for_AnalogSpecOver2(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec,
    map_iter_t_StaticDataMap_for_AnalogSpec & iter,
    Analog* new_value,
    EventMode_uint8_t mode,
    IEventReceiver* receiver);


boolean modify_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec,
    uint16_t start, uint16_t stop, uint8_t flags,
    IEventReceiver* receiver);
////template<class Spec>
////bool StaticDataMap<Spec>::modify(uint16_t start, uint16_t stop, uint8_t flags, IEventReceiver& receiver)

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

Range assign_class_in_StaticDataMap_for_AnalogSpecOver1(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, PointClass_uint8_t clazz);
////template<class Spec> Range StaticDataMap<Spec>::assign_class(PointClass clazz)
////{
////    for (auto& elem : this->map)
////    {
////        elem.second.config.clazz = clazz;
////    }

////    return this->get_full_range();
////}

Range assign_class_in_StaticDataMap_for_AnalogSpecOver2(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, PointClass_uint8_t clazz, Range* range);
////template<class Spec> Range StaticDataMap<Spec>::assign_class(PointClass clazz, const Range& range)
////{
////    for (auto iter = this->map.lower_bound(range.start); iter != this->map.end() && range.Contains(iter->first); iter++)
////    {
////        iter->second.config.clazz = clazz;
////    }

////    return range.Intersection(this->get_full_range());
////}

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
