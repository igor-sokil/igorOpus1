********SUITE('MapIntegers2Booleans')********

{ForeachItem_in_ICollection1

    {Foreach_in_TransformedCollection1

        {ForeachItem_in_ICollection1

            {Foreach_in_ArrayCollection1
            {for (uint32_t i = 0; i < COUNT; ++i)1

                {OnValue_in_FunctorVisitor1

                    {process_in_TransformedCollection1

                        {greaterThanTwo1
                        }greaterThanTwo_

                        {OnValue_in_FunctorVisitor1

                            {fillVector1
                            item= 0
                            }fillVector_
                        }OnValue_in_FunctorVisitor_
                    }process_in_TransformedCollection1
                }OnValue_in_FunctorVisitor_
            }for (uint32_t i = 0; i < COUNT; ++i)_
            {for (uint32_t i = 0; i < COUNT; ++i)1

                {OnValue_in_FunctorVisitor1

                    {process_in_TransformedCollection1

                        {greaterThanTwo1
                        }greaterThanTwo_

                        {OnValue_in_FunctorVisitor1

                            {fillVector1
                            item= 0
                            }fillVector_
                        }OnValue_in_FunctorVisitor_
                    }process_in_TransformedCollection1
                }OnValue_in_FunctorVisitor_
            }for (uint32_t i = 0; i < COUNT; ++i)_
            {for (uint32_t i = 0; i < COUNT; ++i)1

                {OnValue_in_FunctorVisitor1

                    {process_in_TransformedCollection1

                        {greaterThanTwo1
                        }greaterThanTwo_

                        {OnValue_in_FunctorVisitor1

                            {fillVector1
                            item= 1
                            }fillVector_
                        }OnValue_in_FunctorVisitor_
                    }process_in_TransformedCollection1
                }OnValue_in_FunctorVisitor_
            }for (uint32_t i = 0; i < COUNT; ++i)_
            {for (uint32_t i = 0; i < COUNT; ++i)1

                {OnValue_in_FunctorVisitor1

                    {process_in_TransformedCollection1

                        {greaterThanTwo1
                        }greaterThanTwo_

                        {OnValue_in_FunctorVisitor1

                            {fillVector1
                            item= 1
                            }fillVector_
                        }OnValue_in_FunctorVisitor_
                    }process_in_TransformedCollection1
                }OnValue_in_FunctorVisitor_
            }for (uint32_t i = 0; i < COUNT; ++i)_
            }Foreach_in_ArrayCollection_
        }ForeachItem_in_ICollection_
    }Foreach_in_TransformedCollection_
}ForeachItem_in_ICollection_
REQUIRE(items.size() == 4)
items.size() == 4   4
REQUIRE_FALSE(items[0])
items[0]   false
REQUIRE_FALSE(items[1])
items[1]   false
REQUIRE(items[2])
items[2]   true
REQUIRE(items[3])
items[3]   true
