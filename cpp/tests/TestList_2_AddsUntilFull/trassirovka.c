********SUITE('2AddsUntilFull')********

List_for_int_in_List_for_intOver2_1
**uint32_t maxSize= 3

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
REQUIRE(list.Add(1))
ptmp= 0x61fa00

    {Insert_in_List_for_int1
    }Insert_in_List_for_int2_
REQUIRE(list.Add(2))
ptmp= 0x61fa0c

    {Insert_in_List_for_int1
    }Insert_in_List_for_int2_
REQUIRE(list.Add(3))
ptmp= 0x61fa18
REQUIRE(list.IsFullAndCapacityNotZero())
btmp= 1

    {Insert_in_List_for_int1
    }Insert_in_List_for_int1_
REQUIRE_FALSE(list.Add(4))
ptmp= 0
