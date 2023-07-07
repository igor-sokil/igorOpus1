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
#ifndef OPENDNP3_ICOLLECTION_H
#define OPENDNP3_ICOLLECTION_H

#include "Indexed.h"
#include "Group50.h"
////#include <cstddef>

////namespace opendnp3
////{

//--------------------------------ICollection_for_uint16--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor_for_uint16)(void*, uint16_t* value);// = 0;
} IVisitor_for_uint16;

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
////template<class T> class ICollection
typedef struct
{
  uint16_t *pValue_in_ICollection_for_uint16;
////public:
  /**
   * The number of elements in the collection
   */
  uint16_t (*pCount_in_ICollection_for_uint16)(void*);// const = 0;

  /**
   * Visit all the elements of a collection
   */
  void (*pForeach_in_ICollection_for_uint16)(/*ICollection_for_uint16*/void*, IVisitor_for_uint16* visitor);// const = 0;

  /**
      visit all of the elements of a collection
  */
//    template<class Fun> void ForeachItem(const Fun& fun) const
//    {
//        FunctorVisitor<T, Fun> visitor(fun);
//        this->Foreach(visitor);
//    }

  /**
      Retrieve the only value from the collection.
  */
////    boolean ReadOnlyValue_in_ICollection_for_uint16(uint16_t* value) const
////    {
////        if (this->Count() == 1)
////        {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
////            return true;
////        }
////        else
////        {
////            return false;
////        }
////    }
} ICollection_for_uint16;

boolean ReadOnlyValue_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, uint16_t* value);
void ForeachItem_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, void (*fun)(ICollection_for_uint16 *pICollection_for_uint16, uint16_t* item));

/**
 * A visitor implemented as an abstract functor
 *
 */
////template<class T, class Fun> class FunctorVisitor : public IVisitor<T>
////{

////public:
////    FunctorVisitor(const Fun& fun_) : fun(fun_) {}

////    virtual void OnValue(const T& value) override final
////    {
////        fun(value);
////    }

////private:
////    Fun fun;
////};
typedef struct
{
////public:
  IVisitor_for_uint16 iIVisitor_for_uint16;
////private:
  void (*Fun)(ICollection_for_uint16 *pICollection_for_uint16, uint16_t* item);
  ICollection_for_uint16 *pICollection_for_uint16;
}  FunctorVisitor_for_uint16;
void FunctorVisitor_for_uint16_in_FunctorVisitor_for_uint16(FunctorVisitor_for_uint16 *pFunctorVisitor_for_uint16,
    ICollection_for_uint16 *pICollection_for_uint16,
    void (*fun)(ICollection_for_uint16 *pICollection_for_uint16, uint16_t* item));
void OnValue_in_FunctorVisitor_for_uint16(void *pFunctorVisitor_for_uint16, uint16_t *value);


//--------------------------------ICollection_for_uint16--------------------------------
//--------------------------------ICollection_Indexed_for_IINValue--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor__for__Indexed_for_IINValue)(void*, Indexed_for_IINValue* value);// = 0;
} IVisitor__for__Indexed_for_IINValue;

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
////template<class T> class ICollection
typedef struct
{
  Indexed_for_IINValue *pValue_in_ICollection_Indexed_for_IINValue;
////public:
  /**
   * The number of elements in the collection
   */
  uint16_t (*pCount_in_ICollection_Indexed_for_IINValue)(void*);// const = 0;

  /**
   * Visit all the elements of a collection
   */
  void (*pForeach_in_ICollection_Indexed_for_IINValue)(/*ICollection_Indexed_for_IINValue*/void*, IVisitor__for__Indexed_for_IINValue* visitor);// const = 0;

  /**
      visit all of the elements of a collection
  */
//    template<class Fun> void ForeachItem(const Fun& fun) const
//    {
//        FunctorVisitor<T, Fun> visitor(fun);
//        this->Foreach(visitor);
//    }

  /**
      Retrieve the only value from the collection.
  */
////    boolean ReadOnlyValue_in_ICollection_Indexed_for_IINValue(uint16_t* value) const
////    {
////        if (this->Count() == 1)
////        {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
////            return true;
////        }
////        else
////        {
////            return false;
////        }
////    }
} ICollection_Indexed_for_IINValue;

boolean ReadOnlyValue_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue, Indexed_for_IINValue* value);
void ForeachItem_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue, void (*fun)(ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue, Indexed_for_IINValue* item));

/**
 * A visitor implemented as an abstract functor
 *
 */
////template<class T, class Fun> class FunctorVisitor : public IVisitor<T>
////{

////public:
////    FunctorVisitor(const Fun& fun_) : fun(fun_) {}

////    virtual void OnValue(const T& value) override final
////    {
////        fun(value);
////    }

////private:
////    Fun fun;
////};
typedef struct
{
////public:
  IVisitor__for__Indexed_for_IINValue iIVisitor__for__Indexed_for_IINValue;
////private:
  void (*Fun)(ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue, Indexed_for_IINValue* item);
  ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue;
}  FunctorVisitor__for__Indexed_for_IINValue;
void FunctorVisitor__for__Indexed_for_IINValue_in_FunctorVisitor__for__Indexed_for_IINValue(FunctorVisitor__for__Indexed_for_IINValue *pFunctorVisitor__for__Indexed_for_IINValue,
    ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue,
    void (*fun)(ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue, Indexed_for_IINValue* item));
void OnValue_in_FunctorVisitor__for__Indexed_for_IINValue(void *pFunctorVisitor__for__Indexed_for_IINValue, Indexed_for_IINValue *value);


//--------------------------------ICollection_Indexed_for_IINValue--------------------------------
//--------------------------------ICollection_Indexed_for_AnalogOutputInt16--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor__for__Indexed_for_AnalogOutputInt16)(void*, Indexed_for_AnalogOutputInt16* value);// = 0;
} IVisitor__for__Indexed_for_AnalogOutputInt16;

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
////template<class T> class ICollection
typedef struct
{
  Indexed_for_AnalogOutputInt16 *pValue_in_ICollection_Indexed_for_AnalogOutputInt16;
////public:
  /**
   * The number of elements in the collection
   */
  uint16_t (*pCount_in_ICollection_Indexed_for_AnalogOutputInt16)(void*);// const = 0;

  /**
   * Visit all the elements of a collection
   */
  void (*pForeach_in_ICollection_Indexed_for_AnalogOutputInt16)(/*ICollection_Indexed_for_AnalogOutputInt16*/void*, IVisitor__for__Indexed_for_AnalogOutputInt16* visitor);// const = 0;

  /**
      visit all of the elements of a collection
  */
//    template<class Fun> void ForeachItem(const Fun& fun) const
//    {
//        FunctorVisitor<T, Fun> visitor(fun);
//        this->Foreach(visitor);
//    }

  /**
      Retrieve the only value from the collection.
  */
////    boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputInt16(uint16_t* value) const
////    {
////        if (this->Count() == 1)
////        {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
////            return true;
////        }
////        else
////        {
////            return false;
////        }
////    }
} ICollection_Indexed_for_AnalogOutputInt16;

boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputInt16(ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16, Indexed_for_AnalogOutputInt16* value);
void ForeachItem_in_ICollection_Indexed_for_AnalogOutputInt16(ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16, void (*fun)(ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16, Indexed_for_AnalogOutputInt16* item));

/**
 * A visitor implemented as an abstract functor
 *
 */
////template<class T, class Fun> class FunctorVisitor : public IVisitor<T>
////{

////public:
////    FunctorVisitor(const Fun& fun_) : fun(fun_) {}

////    virtual void OnValue(const T& value) override final
////    {
////        fun(value);
////    }

////private:
////    Fun fun;
////};
typedef struct
{
////public:
  IVisitor__for__Indexed_for_AnalogOutputInt16 iIVisitor__for__Indexed_for_AnalogOutputInt16;
////private:
  void (*Fun)(ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16, Indexed_for_AnalogOutputInt16* item);
  ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16;
}  FunctorVisitor__for__Indexed_for_AnalogOutputInt16;
void FunctorVisitor__for__Indexed_for_AnalogOutputInt16_in_FunctorVisitor__for__Indexed_for_AnalogOutputInt16(FunctorVisitor__for__Indexed_for_AnalogOutputInt16 *pFunctorVisitor__for__Indexed_for_AnalogOutputInt16,
    ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16,
    void (*fun)(ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16, Indexed_for_AnalogOutputInt16* item));
void OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputInt16(void *pFunctorVisitor__for__Indexed_for_AnalogOutputInt16, Indexed_for_AnalogOutputInt16 *value);


//--------------------------------ICollection_Indexed_for_AnalogOutputInt16--------------------------------
//--------------------------------ICollection_Indexed_for_AnalogOutputInt32--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor__for__Indexed_for_AnalogOutputInt32)(void*, Indexed_for_AnalogOutputInt32* value);// = 0;
} IVisitor__for__Indexed_for_AnalogOutputInt32;

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
////template<class T> class ICollection
typedef struct
{
  Indexed_for_AnalogOutputInt32 *pValue_in_ICollection_Indexed_for_AnalogOutputInt32;
////public:
  /**
   * The number of elements in the collection
   */
  uint16_t (*pCount_in_ICollection_Indexed_for_AnalogOutputInt32)(void*);// const = 0;

  /**
   * Visit all the elements of a collection
   */
  void (*pForeach_in_ICollection_Indexed_for_AnalogOutputInt32)(/*ICollection_Indexed_for_AnalogOutputInt32*/void*, IVisitor__for__Indexed_for_AnalogOutputInt32* visitor);// const = 0;

  /**
      visit all of the elements of a collection
  */
//    template<class Fun> void ForeachItem(const Fun& fun) const
//    {
//        FunctorVisitor<T, Fun> visitor(fun);
//        this->Foreach(visitor);
//    }

  /**
      Retrieve the only value from the collection.
  */
////    boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputInt32(uint16_t* value) const
////    {
////        if (this->Count() == 1)
////        {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
////            return true;
////        }
////        else
////        {
////            return false;
////        }
////    }
} ICollection_Indexed_for_AnalogOutputInt32;

boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputInt32(ICollection_Indexed_for_AnalogOutputInt32 *pICollection_Indexed_for_AnalogOutputInt32, Indexed_for_AnalogOutputInt32* value);
void ForeachItem_in_ICollection_Indexed_for_AnalogOutputInt32(ICollection_Indexed_for_AnalogOutputInt32 *pICollection_Indexed_for_AnalogOutputInt32, void (*fun)(ICollection_Indexed_for_AnalogOutputInt32 *pICollection_Indexed_for_AnalogOutputInt32, Indexed_for_AnalogOutputInt32* item));

/**
 * A visitor implemented as an abstract functor
 *
 */
////template<class T, class Fun> class FunctorVisitor : public IVisitor<T>
////{

////public:
////    FunctorVisitor(const Fun& fun_) : fun(fun_) {}

////    virtual void OnValue(const T& value) override final
////    {
////        fun(value);
////    }

////private:
////    Fun fun;
////};
typedef struct
{
////public:
  IVisitor__for__Indexed_for_AnalogOutputInt32 iIVisitor__for__Indexed_for_AnalogOutputInt32;
////private:
  void (*Fun)(ICollection_Indexed_for_AnalogOutputInt32 *pICollection_Indexed_for_AnalogOutputInt32, Indexed_for_AnalogOutputInt32* item);
  ICollection_Indexed_for_AnalogOutputInt32 *pICollection_Indexed_for_AnalogOutputInt32;
}  FunctorVisitor__for__Indexed_for_AnalogOutputInt32;
void FunctorVisitor__for__Indexed_for_AnalogOutputInt32_in_FunctorVisitor__for__Indexed_for_AnalogOutputInt32(FunctorVisitor__for__Indexed_for_AnalogOutputInt32 *pFunctorVisitor__for__Indexed_for_AnalogOutputInt32,
    ICollection_Indexed_for_AnalogOutputInt32 *pICollection_Indexed_for_AnalogOutputInt32,
    void (*fun)(ICollection_Indexed_for_AnalogOutputInt32 *pICollection_Indexed_for_AnalogOutputInt32, Indexed_for_AnalogOutputInt32* item));
void OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputInt32(void *pFunctorVisitor__for__Indexed_for_AnalogOutputInt32, Indexed_for_AnalogOutputInt32 *value);


//--------------------------------ICollection_Indexed_for_AnalogOutputInt32--------------------------------
//--------------------------------ICollection_Indexed_for_AnalogOutputFloat32--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor__for__Indexed_for_AnalogOutputFloat32)(void*, Indexed_for_AnalogOutputFloat32* value);// = 0;
} IVisitor__for__Indexed_for_AnalogOutputFloat32;

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
////template<class T> class ICollection
typedef struct
{
  Indexed_for_AnalogOutputFloat32 *pValue_in_ICollection_Indexed_for_AnalogOutputFloat32;
////public:
  /**
   * The number of elements in the collection
   */
  uint16_t (*pCount_in_ICollection_Indexed_for_AnalogOutputFloat32)(void*);// const = 0;

  /**
   * Visit all the elements of a collection
   */
  void (*pForeach_in_ICollection_Indexed_for_AnalogOutputFloat32)(/*ICollection_Indexed_for_AnalogOutputFloat32*/void*, IVisitor__for__Indexed_for_AnalogOutputFloat32* visitor);// const = 0;

  /**
      visit all of the elements of a collection
  */
//    template<class Fun> void ForeachItem(const Fun& fun) const
//    {
//        FunctorVisitor<T, Fun> visitor(fun);
//        this->Foreach(visitor);
//    }

  /**
      Retrieve the only value from the collection.
  */
////    boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputFloat32(uint16_t* value) const
////    {
////        if (this->Count() == 1)
////        {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
////            return true;
////        }
////        else
////        {
////            return false;
////        }
////    }
} ICollection_Indexed_for_AnalogOutputFloat32;

boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputFloat32(ICollection_Indexed_for_AnalogOutputFloat32 *pICollection_Indexed_for_AnalogOutputFloat32, Indexed_for_AnalogOutputFloat32* value);
void ForeachItem_in_ICollection_Indexed_for_AnalogOutputFloat32(ICollection_Indexed_for_AnalogOutputFloat32 *pICollection_Indexed_for_AnalogOutputFloat32, void (*fun)(ICollection_Indexed_for_AnalogOutputFloat32 *pICollection_Indexed_for_AnalogOutputFloat32, Indexed_for_AnalogOutputFloat32* item));

/**
 * A visitor implemented as an abstract functor
 *
 */
////template<class T, class Fun> class FunctorVisitor : public IVisitor<T>
////{

////public:
////    FunctorVisitor(const Fun& fun_) : fun(fun_) {}

////    virtual void OnValue(const T& value) override final
////    {
////        fun(value);
////    }

////private:
////    Fun fun;
////};
typedef struct
{
////public:
  IVisitor__for__Indexed_for_AnalogOutputFloat32 iIVisitor__for__Indexed_for_AnalogOutputFloat32;
////private:
  void (*Fun)(ICollection_Indexed_for_AnalogOutputFloat32 *pICollection_Indexed_for_AnalogOutputFloat32, Indexed_for_AnalogOutputFloat32* item);
  ICollection_Indexed_for_AnalogOutputFloat32 *pICollection_Indexed_for_AnalogOutputFloat32;
}  FunctorVisitor__for__Indexed_for_AnalogOutputFloat32;
void FunctorVisitor__for__Indexed_for_AnalogOutputFloat32_in_FunctorVisitor__for__Indexed_for_AnalogOutputFloat32(FunctorVisitor__for__Indexed_for_AnalogOutputFloat32 *pFunctorVisitor__for__Indexed_for_AnalogOutputFloat32,
    ICollection_Indexed_for_AnalogOutputFloat32 *pICollection_Indexed_for_AnalogOutputFloat32,
    void (*fun)(ICollection_Indexed_for_AnalogOutputFloat32 *pICollection_Indexed_for_AnalogOutputFloat32, Indexed_for_AnalogOutputFloat32* item));
void OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputFloat32(void *pFunctorVisitor__for__Indexed_for_AnalogOutputFloat32, Indexed_for_AnalogOutputFloat32 *value);


//--------------------------------ICollection_Indexed_for_AnalogOutputFloat32--------------------------------
//--------------------------------ICollection_Indexed_for_AnalogOutputDouble64--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor__for__Indexed_for_AnalogOutputDouble64)(void*, Indexed_for_AnalogOutputDouble64* value);// = 0;
} IVisitor__for__Indexed_for_AnalogOutputDouble64;

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
////template<class T> class ICollection
typedef struct
{
  Indexed_for_AnalogOutputDouble64 *pValue_in_ICollection_Indexed_for_AnalogOutputDouble64;
////public:
  /**
   * The number of elements in the collection
   */
  uint16_t (*pCount_in_ICollection_Indexed_for_AnalogOutputDouble64)(void*);// const = 0;

  /**
   * Visit all the elements of a collection
   */
  void (*pForeach_in_ICollection_Indexed_for_AnalogOutputDouble64)(/*ICollection_Indexed_for_AnalogOutputDouble64*/void*, IVisitor__for__Indexed_for_AnalogOutputDouble64* visitor);// const = 0;

  /**
      visit all of the elements of a collection
  */
//    template<class Fun> void ForeachItem(const Fun& fun) const
//    {
//        FunctorVisitor<T, Fun> visitor(fun);
//        this->Foreach(visitor);
//    }

  /**
      Retrieve the only value from the collection.
  */
////    boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputDouble64(uint16_t* value) const
////    {
////        if (this->Count() == 1)
////        {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
////            return true;
////        }
////        else
////        {
////            return false;
////        }
////    }
} ICollection_Indexed_for_AnalogOutputDouble64;

boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64, Indexed_for_AnalogOutputDouble64* value);
void ForeachItem_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64, void (*fun)(ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64, Indexed_for_AnalogOutputDouble64* item));

/**
 * A visitor implemented as an abstract functor
 *
 */
////template<class T, class Fun> class FunctorVisitor : public IVisitor<T>
////{

////public:
////    FunctorVisitor(const Fun& fun_) : fun(fun_) {}

////    virtual void OnValue(const T& value) override final
////    {
////        fun(value);
////    }

////private:
////    Fun fun;
////};
typedef struct
{
////public:
  IVisitor__for__Indexed_for_AnalogOutputDouble64 iIVisitor__for__Indexed_for_AnalogOutputDouble64;
////private:
  void (*Fun)(ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64, Indexed_for_AnalogOutputDouble64* item);
  ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64;
}  FunctorVisitor__for__Indexed_for_AnalogOutputDouble64;
void FunctorVisitor__for__Indexed_for_AnalogOutputDouble64_in_FunctorVisitor__for__Indexed_for_AnalogOutputDouble64(FunctorVisitor__for__Indexed_for_AnalogOutputDouble64 *pFunctorVisitor__for__Indexed_for_AnalogOutputDouble64,
    ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64,
    void (*fun)(ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64, Indexed_for_AnalogOutputDouble64* item));
void OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputDouble64(void *pFunctorVisitor__for__Indexed_for_AnalogOutputDouble64, Indexed_for_AnalogOutputDouble64 *value);


//--------------------------------ICollection_Indexed_for_AnalogOutputDouble64--------------------------------
//--------------------------------ICollection_Indexed_for_ControlRelayOutputBlock--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor__for__Indexed_for_ControlRelayOutputBlock)(void*, Indexed_for_ControlRelayOutputBlock* value);// = 0;
} IVisitor__for__Indexed_for_ControlRelayOutputBlock;

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
////template<class T> class ICollection
typedef struct
{
  Indexed_for_ControlRelayOutputBlock *pValue_in_ICollection_Indexed_for_ControlRelayOutputBlock;
////public:
  /**
   * The number of elements in the collection
   */
  uint16_t (*pCount_in_ICollection_Indexed_for_ControlRelayOutputBlock)(void*);// const = 0;

  /**
   * Visit all the elements of a collection
   */
  void (*pForeach_in_ICollection_Indexed_for_ControlRelayOutputBlock)(/*ICollection_Indexed_for_ControlRelayOutputBlock*/void*, IVisitor__for__Indexed_for_ControlRelayOutputBlock* visitor);// const = 0;

  /**
      visit all of the elements of a collection
  */
//    template<class Fun> void ForeachItem(const Fun& fun) const
//    {
//        FunctorVisitor<T, Fun> visitor(fun);
//        this->Foreach(visitor);
//    }

  /**
      Retrieve the only value from the collection.
  */
////    boolean ReadOnlyValue_in_ICollection_Indexed_for_ControlRelayOutputBlock(uint16_t* value) const
////    {
////        if (this->Count() == 1)
////        {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
////            return true;
////        }
////        else
////        {
////            return false;
////        }
////    }
} ICollection_Indexed_for_ControlRelayOutputBlock;

boolean ReadOnlyValue_in_ICollection_Indexed_for_ControlRelayOutputBlock(ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock, Indexed_for_ControlRelayOutputBlock* value);
void ForeachItem_in_ICollection_Indexed_for_ControlRelayOutputBlock(ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock, void (*fun)(ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock, Indexed_for_ControlRelayOutputBlock* item));

/**
 * A visitor implemented as an abstract functor
 *
 */
////template<class T, class Fun> class FunctorVisitor : public IVisitor<T>
////{

////public:
////    FunctorVisitor(const Fun& fun_) : fun(fun_) {}

////    virtual void OnValue(const T& value) override final
////    {
////        fun(value);
////    }

////private:
////    Fun fun;
////};
typedef struct
{
////public:
  IVisitor__for__Indexed_for_ControlRelayOutputBlock iIVisitor__for__Indexed_for_ControlRelayOutputBlock;
////private:
  void (*Fun)(ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock, Indexed_for_ControlRelayOutputBlock* item);
  ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock;
}  FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock;
void FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock_in_FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock(FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock *pFunctorVisitor__for__Indexed_for_ControlRelayOutputBlock,
    ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock,
    void (*fun)(ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock, Indexed_for_ControlRelayOutputBlock* item));
void OnValue_in_FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock(void *pFunctorVisitor__for__Indexed_for_ControlRelayOutputBlock, Indexed_for_ControlRelayOutputBlock *value);


//--------------------------------ICollection_Indexed_for_ControlRelayOutputBlock--------------------------------
//--------------------------------ICollection_for_Group50Var1--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor_for_Group50Var1)(void*, Group50Var1* value);// = 0;
} IVisitor_for_Group50Var1;

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
////template<class T> class ICollection
typedef struct
{
  Group50Var1 *pValue_in_ICollection_for_Group50Var1;
////public:
  /**
   * The number of elements in the collection
   */
  uint16_t (*pCount_in_ICollection_for_Group50Var1)(void*);// const = 0;

  /**
   * Visit all the elements of a collection
   */
  void (*pForeach_in_ICollection_for_Group50Var1)(/*ICollection_for_Group50Var1*/void*, IVisitor_for_Group50Var1* visitor);// const = 0;

  /**
      visit all of the elements of a collection
  */
//    template<class Fun> void ForeachItem(const Fun& fun) const
//    {
//        FunctorVisitor<T, Fun> visitor(fun);
//        this->Foreach(visitor);
//    }

  /**
      Retrieve the only value from the collection.
  */
////    boolean ReadOnlyValue_in_ICollection_for_Group50Var1(uint16_t* value) const
////    {
////        if (this->Count() == 1)
////        {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
////            return true;
////        }
////        else
////        {
////            return false;
////        }
////    }
} ICollection_for_Group50Var1;

boolean ReadOnlyValue_in_ICollection_for_Group50Var1(ICollection_for_Group50Var1 *pICollection_for_Group50Var1, Group50Var1* value);
void ForeachItem_in_ICollection_for_Group50Var1(ICollection_for_Group50Var1 *pICollection_for_Group50Var1, void (*fun)(ICollection_for_Group50Var1 *pICollection_for_Group50Var1, Group50Var1* item));

/**
 * A visitor implemented as an abstract functor
 *
 */
////template<class T, class Fun> class FunctorVisitor : public IVisitor<T>
////{

////public:
////    FunctorVisitor(const Fun& fun_) : fun(fun_) {}

////    virtual void OnValue(const T& value) override final
////    {
////        fun(value);
////    }

////private:
////    Fun fun;
////};
typedef struct
{
////public:
  IVisitor_for_Group50Var1 iIVisitor_for_Group50Var1;
////private:
  void (*Fun)(ICollection_for_Group50Var1 *pICollection_for_Group50Var1, Group50Var1* item);
  ICollection_for_Group50Var1 *pICollection_for_Group50Var1;
}  FunctorVisitor_for_Group50Var1;
void FunctorVisitor_for_Group50Var1_in_FunctorVisitor_for_Group50Var1(FunctorVisitor_for_Group50Var1 *pFunctorVisitor_for_Group50Var1,
    ICollection_for_Group50Var1 *pICollection_for_Group50Var1,
    void (*fun)(ICollection_for_Group50Var1 *pICollection_for_Group50Var1, Group50Var1* item));
void OnValue_in_FunctorVisitor_for_Group50Var1(void *pFunctorVisitor_for_Group50Var1, Group50Var1 *value);


//--------------------------------ICollection_for_Group50Var1--------------------------------
////} // namespace opendnp3

#endif
