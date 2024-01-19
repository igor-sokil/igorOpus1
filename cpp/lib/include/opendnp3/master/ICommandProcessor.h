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
#ifndef OPENDNP3_ICOMMANDPROCESSOR_H
#define OPENDNP3_ICOMMANDPROCESSOR_H

#include "CommandResultCallbackT.h"
#include "CommandSet.h"
#include "TaskConfig.h"

////namespace opendnp3
////{

/**
 * Interface used to dispatch SELECT / OPERATE / DIRECT OPERATE from application code to a master
* Интерфейс, используемый для отправки SELECT / OPERATE / DIRECT OPERATE из кода приложения на мастер-сервер.
 */
////class ICommandProcessor
typedef struct
{
////public:
    /**
     * Select and operate a set of commands
     *
     * @param commands Set of command headers
     * @param callback callback that will be invoked upon completion or failure
     * @param config optional configuration that controls normal callbacks and allows the user to be specified for SA
* Выберите и управляйте набором команд
      *
      * команды @param Набор заголовков команд
      * Обратный вызов @param, который будет вызван после завершения или сбоя.
      * Дополнительная конфигурация @param config, которая управляет обычными обратными вызовами и позволяет указать пользователя для SA.
     */
    void (*pSelectOperate_in_ICommandProcessor)(void *, CommandSet* commands,
                                  CommandResultCallbackT* callback,
                                  TaskConfig* config);// = TaskConfig::Default());// = 0;

    /**
     * Direct operate a set of commands
     *
     * @param commands Set of command headers
     * @param callback callback that will be invoked upon completion or failure
     * @param config optional configuration that controls normal callbacks and allows the user to be specified for SA
* Прямое управление набором команд
      *
      * команды @param Набор заголовков команд
      * Обратный вызов @param, который будет вызван после завершения или сбоя.
      * Дополнительная конфигурация @param config, которая управляет обычными обратными вызовами и позволяет указать пользователя для SA.
     */
    void (*pDirectOperate_in_ICommandProcessor)(void *, CommandSet* commands,
                                CommandResultCallbackT* callback,
                                TaskConfig* config);// = TaskConfig::Default())   = 0;

    /**
     * Select/operate a single command
     *
     * @param command Command to operate
     * @param index of the command
     * @param callback callback that will be invoked upon completion or failure
     * @param config optional configuration that controls normal callbacks and allows the user to be specified for SA
* Выберите/выполняйте одну команду
      *
      * @param команда Команда для работы
      * @param индекс команды
      * Обратный вызов @param, который будет вызван после завершения или сбоя.
      * Дополнительная конфигурация @param config, которая управляет обычными обратными вызовами и позволяет указать пользователя для SA.
     */
////    template<class T>
////    void SelectAndOperate(const T& command,
////                          uint16_t index,
////                          const CommandResultCallbackT& callback,
////                          const TaskConfig& config = TaskConfig::Default());

    /**
     * Direct operate a single command
     *
     * @param command Command to operate
     * @param index of the command
     * @param callback callback that will be invoked upon completion or failure
     * @param config optional configuration that controls normal callbacks and allows the user to be specified for SA
* Прямое управление одной командой
      *
      * @param команда Команда для работы
      * @param индекс команды
      * Обратный вызов @param, который будет вызван после завершения или сбоя.
      * Дополнительная конфигурация @param config, которая управляет обычными обратными вызовами и позволяет указать пользователя для SA.
     */
////    template<class T>
////    void DirectOperate(const T& command,
////                       uint16_t index,
////                       const CommandResultCallbackT& callback,
////                       const TaskConfig& config = TaskConfig::Default());

  void* pParentPointer_in_ICommandProcessor;
} ICommandProcessor;

void SelectOperate_in_ICommandProcessor(ICommandProcessor* pICommandProcessor, CommandSet* commands,
                                  CommandResultCallbackT* callback,
                                  TaskConfig* config);

void DirectOperate_in_ICommandProcessor(ICommandProcessor* pICommandProcessor, CommandSet* commands,
                                  CommandResultCallbackT* callback,
                                  TaskConfig* config);

void* getParentPointer_in_ICommandProcessor(ICommandProcessor*);
void  setParentPointer_in_ICommandProcessor(ICommandProcessor*, void*);

////template<class T>
////void ICommandProcessor::SelectAndOperate(const T& command,
////                                         uint16_t index,
////                                         const CommandResultCallbackT& callback,
////                                         const TaskConfig& config)
////{
////    CommandSet commands({WithIndex(command, index)});
////    this->SelectAndOperate(std::move(commands), callback, config);
////}
////
////template<class T>
////void ICommandProcessor::DirectOperate(const T& command,
////                                      uint16_t index,
////                                      const CommandResultCallbackT& callback,
////                                      const TaskConfig& config)
////{
////    CommandSet commands({WithIndex(command, index)});
////    this->DirectOperate(std::move(commands), callback, config);
////}
////
////} // namespace opendnp3

#endif
