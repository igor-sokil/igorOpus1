********SUITE('8CanIterateOverValues')********

List_for_int_in_List_for_intOver2_1
**uint32_t maxSize= 10

    List_for_int_in_List_for_intOver1_1

    Array__for__Node_for_int_in_Array__for__Node_for_intOver1_1
*    *Node_for_int buffer[SIZE_for_int]=6420992

    Array__for__Node_for_int_in_Array__for__Node_for_intOver2_1
*    *Node_for_int buffer[SIZE_for_int]=6420992

    {Initialize_in_List_for_int1
*    *Initialize_in_List_for_int2
*    *pList_for_int->free= 6420992
    }Initialize_in_List_for_int_

    {Insert_in_List_for_int1
    }Insert_in_List_for_int2_
ptmp= 0x61fa00

    {Insert_in_List_for_int1
    }Insert_in_List_for_int2_
ptmp= 0x61fa0c

    {Insert_in_List_for_int1
    }Insert_in_List_for_int2_
ptmp= 0x61fa18

    Iterate_in_List_for_int1
*    *pList_for_int->head= 6420992

        From__in__Iterator_in_List_for_int_static1
*        *Node_for_int* start= 6420992

        Iterator_in_List_for_int__in__Iterator_in_List_for_int1
*        *Node_for_int* start= 6420992
REQUIRE(iter.HasNext())
btmp= 1
REQUIRE(i == iter.Next()->value)
iter.Next()->value= 1
REQUIRE(iter.HasNext())
btmp= 1
REQUIRE(i == iter.Next()->value)
iter.Next()->value= 2
REQUIRE(iter.HasNext())
btmp= 1
REQUIRE(i == iter.Next()->value)
iter.Next()->value= 3
