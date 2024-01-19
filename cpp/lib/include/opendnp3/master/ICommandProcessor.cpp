#include <QApplication>

#include "header.h"
#include "ICommandProcessor.h"

void SelectOperate_in_ICommandProcessor(ICommandProcessor* pICommandProcessor, CommandSet* commands,
                                  CommandResultCallbackT* callback,
                                  TaskConfig* config)
{
  (pICommandProcessor->pSelectOperate_in_ICommandProcessor)(pICommandProcessor, commands, callback, config);
}

void DirectOperate_in_ICommandProcessor(ICommandProcessor* pICommandProcessor, CommandSet* commands,
                                  CommandResultCallbackT* callback,
                                  TaskConfig* config)
{
  (pICommandProcessor->pDirectOperate_in_ICommandProcessor)(pICommandProcessor, commands, callback, config);
}

void* getParentPointer_in_ICommandProcessor(ICommandProcessor* pICommandProcessor)
{
  return pICommandProcessor->pParentPointer_in_ICommandProcessor;
}
void  setParentPointer_in_ICommandProcessor(ICommandProcessor* pICommandProcessor, void* pParentPointer)
{
  pICommandProcessor->pParentPointer_in_ICommandProcessor = pParentPointer;
}

