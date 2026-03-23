********SUITE('2a_AddsUntilFull')********

List_for_CellAnalogRecord_in_List_for_CellAnalogRecordOver2_1
**uint32_t maxSize= 3

    List_for_CellAnalogRecord_in_List_for_CellAnalogRecordOver1_1

    Array__for__Node_for_CellAnalogRecord_in_Array__for__Node_for_CellAnalogRecordOver1_1
*    *Node_for_CellAnalogRecord buffer[SIZE_for_CellAnalogRecord]=6406192

    Array__for__Node_for_CellAnalogRecord_in_Array__for__Node_for_CellAnalogRecordOver2_1
*    *Node_for_CellAnalogRecord buffer[SIZE_for_CellAnalogRecord]=6406192
REQUIRE(list.Add(1))
ptmp= 6406192
REQUIRE(list.Add(2))
ptmp= 6406352
REQUIRE(list.Add(3))
ptmp= 6406512
REQUIRE(list.IsFullAndCapacityNotZero())
btmp= 1
REQUIRE_FALSE(list.Add(4))
ptmp= 0

    Iterate_in_List_for_CellAnalogRecord1
*    *pList_for_CellAnalogRecord->head= 6406192

        From__in__Iterator_in_List_for_CellAnalogRecord_static1
*        *Node_for_CellAnalogRecord* start= 6406192

        Iterator_in_List_for_CellAnalogRecord__in__Iterator_in_List_for_CellAnalogRecord1
*        *Node_for_CellAnalogRecord* start= 6406192
REQUIRE(iter.HasNext())
btmp= 1
REQUIRE(i == iter.Next()->value)
iter.Next()->value= 5
REQUIRE(iter.HasNext())
btmp= 1
REQUIRE(i == iter.Next()->value)
iter.Next()->value= 6
REQUIRE(iter.HasNext())
btmp= 1
REQUIRE(i == iter.Next()->value)
iter.Next()->value= 7
REQUIRE(iter.HasNext())
btmp= 0
REQUIRE(iter.HasNext())
btmp= 0
