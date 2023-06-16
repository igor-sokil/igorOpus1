
INCLUDEPATH  += ..\..\..\qtsrc
INCLUDEPATH  += ..\..\..\cpp\lib\include\opendnp3\app
INCLUDEPATH  += ..\..\..\cpp\lib\include\opendnp3\gen
INCLUDEPATH  += ..\..\..\cpp\lib\include\opendnp3\master
INCLUDEPATH  += ..\..\..\cpp\lib\include\opendnp3\outstation
INCLUDEPATH  += ..\..\..\cpp\lib\include\opendnp3\util
INCLUDEPATH  += ..\..\..\cpp\lib\include\opendnp3\link
INCLUDEPATH  += ..\..\..\cpp\lib\src\app
INCLUDEPATH  += ..\..\..\cpp\lib\src\app\parsing
INCLUDEPATH  += ..\..\..\cpp\lib\src\link
INCLUDEPATH  += ..\..\..\cpp\lib\src\outstation
INCLUDEPATH  += ..\..\..\cpp\lib\src\outstation\event
INCLUDEPATH  += ..\..\..\cpp\lib\include\opendnp3\link

INCLUDEPATH  += ..\..\..\cpp\lib\src\gen
INCLUDEPATH  += ..\..\..\cpp\lib\src\gen\objects

INCLUDEPATH  += ..\..\..\ser4cpp\container
INCLUDEPATH  += ..\..\..\ser4cpp\util
INCLUDEPATH  += ..\..\..\ser4cpp\serialization

INCLUDEPATH  += ..\..\..\cpp\tests\unit\utils

HEADERS       = ..\..\..\qtsrc\loghandler.h \
		..\..\..\qtsrc\key_filter.h \
                ..\..\..\qtsrc\MainWindow.h \
                ..\..\..\qtsrc\header.h \
                \
                 ..\..\..\ser4cpp\util\Comparisons.h \
                 ..\..\..\ser4cpp\container\HasLength.h \
                 ..\..\..\ser4cpp\container\RSeq.h \
                \
                ..\..\..\cpp\lib\include\opendnp3\app\BaseMeasurementTypes.h \
                ..\..\..\cpp\lib\include\opendnp3\app\MeasurementInfo.h \
                ..\..\..\cpp\lib\include\opendnp3\app\DNPTime.h \
                ..\..\..\cpp\lib\include\opendnp3\app\Flags.h \
                ..\..\..\cpp\lib\include\opendnp3\app\EventTriggers.h \
                ..\..\..\cpp\lib\include\opendnp3\app\AnalogOutput.h \
                ..\..\..\cpp\lib\include\opendnp3\app\IINField.h \
                ..\..\..\cpp\lib\include\opendnp3\app\ClassField.h \
                ..\..\..\cpp\lib\include\opendnp3\app\ControlRelayOutputBlock.h \
                ..\..\..\cpp\lib\include\opendnp3\app\BinaryCommandEvent.h \
                \
                ..\..\..\cpp\lib\include\opendnp3\gen\CommandStatus.h \
                \
                ..\..\..\cpp\lib\include\opendnp3\master\ResponseInfo.h \
                \
                ..\..\..\cpp\lib\include\opendnp3\outstation\MeasurementConfig.h \
                \
                ..\..\..\cpp\lib\src\app\Functions.h \
                ..\..\..\cpp\lib\src\app\AppControlField.h \
                ..\..\..\cpp\lib\src\app\APDUHeader.h \
                ..\..\..\cpp\lib\src\app\Serializer.h 

SOURCES       =  ..\..\..\ser4cpp\util\Comparisons.cpp \
                 ..\..\..\ser4cpp\container\HasLength.cpp \
                 ..\..\..\ser4cpp\container\RSeq.cpp \
                 ..\..\..\ser4cpp\container\WSeq.cpp \
                 ..\..\..\ser4cpp\container\Settable.cpp \
                 ..\..\..\ser4cpp\container\BufferSer4.cpp \
                 ..\..\..\ser4cpp\container\StaticBuffer.cpp \
                 ..\..\..\ser4cpp\container\Array__for__Node_for_EventRecord.cpp \
                 ..\..\..\ser4cpp\container\ArrayView__for__Node_for_EventRecord.cpp \
                 ..\..\..\ser4cpp\container\Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec.cpp \
                 ..\..\..\ser4cpp\container\ArrayView__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec.cpp \
                 ..\..\..\ser4cpp\container\Array__for__Node_TypedEventRecord_for_AnalogSpec.cpp \
                 ..\..\..\ser4cpp\container\ArrayView__for__Node_TypedEventRecord_for_AnalogSpec.cpp \
                 ..\..\..\ser4cpp\container\Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec.cpp \
                 ..\..\..\ser4cpp\container\ArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec.cpp \
                 ..\..\..\ser4cpp\container\Array__for__Node_TypedEventRecord_for_BinarySpec.cpp \
                 ..\..\..\ser4cpp\container\ArrayView__for__Node_TypedEventRecord_for_BinarySpec.cpp \
                 ..\..\..\ser4cpp\container\Array__for__Node_TypedEventRecord_for_CounterSpec.cpp \
                 ..\..\..\ser4cpp\container\ArrayView__for__Node_TypedEventRecord_for_CounterSpec.cpp \
                 ..\..\..\ser4cpp\container\Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpec.cpp \
                 ..\..\..\ser4cpp\container\ArrayView__for__Node_TypedEventRecord_for_DoubleBitBinarySpec.cpp \
                 ..\..\..\ser4cpp\container\Array__for__Node_TypedEventRecord_for_FrozenCounterSpec.cpp \
                 ..\..\..\ser4cpp\container\ArrayView__for__Node_TypedEventRecord_for_FrozenCounterSpec.cpp \
                 ..\..\..\ser4cpp\container\Array__for__Node_TypedEventRecord_for_OctetStringSpec.cpp \
                 ..\..\..\ser4cpp\container\ArrayView__for__Node_TypedEventRecord_for_OctetStringSpec.cpp \
                 ..\..\..\ser4cpp\serialization\SerializationTemplates.cpp \
                \
                ..\..\..\cpp\lib\include\opendnp3\util\Buffer.cpp \
                \
                ..\..\..\cpp\lib\include\opendnp3\master\CommandPointResult.cpp \
                ..\..\..\cpp\lib\include\opendnp3\master\HeaderInfo.cpp \
                \
                ..\..\..\cpp\lib\include\opendnp3\app\BaseMeasurementTypes.cpp \
                ..\..\..\cpp\lib\include\opendnp3\app\DNPTime.cpp \
                ..\..\..\cpp\lib\include\opendnp3\app\Flags.cpp \
                ..\..\..\cpp\lib\include\opendnp3\app\GroupVariationID.cpp \
                ..\..\..\cpp\lib\include\opendnp3\app\OctetString.cpp \
                ..\..\..\cpp\lib\include\opendnp3\app\Indexed.cpp \
                \
                ..\..\..\cpp\lib\src\link\Addresses.cpp \
                ..\..\..\cpp\lib\src\link\CRC.cpp \
                \
                ..\..\..\cpp\lib\src\app\parsing\APDUHeaderParser.cpp \
                ..\..\..\cpp\lib\src\app\parsing\ParseResult.cpp \
                \
                ..\..\..\cpp\lib\src\app\AnalogCommandEvent.cpp \
                ..\..\..\cpp\lib\src\app\AnalogOutput.cpp \
                ..\..\..\cpp\lib\src\app\APDUHeader.cpp \
                ..\..\..\cpp\lib\src\app\AppControlField.cpp \
                ..\..\..\cpp\lib\src\app\APDURequest.cpp \
                ..\..\..\cpp\lib\src\app\APDUWrapper.cpp \
                ..\..\..\cpp\lib\src\app\APDUResponse.cpp \
                ..\..\..\cpp\lib\src\app\BinaryCommandEvent.cpp \
                ..\..\..\cpp\lib\src\app\BitfieldRangeWriteIterator_for_uint8.cpp \
                ..\..\..\cpp\lib\src\app\CountWriteIterator_for_UInt8_Binary.cpp \
                ..\..\..\cpp\lib\src\app\CountWriteIterator_for_UInt16_Analog.cpp \
                ..\..\..\cpp\lib\src\app\CountWriteIterator_for_UInt8_Analog.cpp \
                ..\..\..\cpp\lib\src\app\ClassField.cpp \
                ..\..\..\cpp\lib\src\app\ControlRelayOutputBlock.cpp \
                ..\..\..\cpp\lib\src\app\DNP3Serializer.cpp \
                ..\..\..\cpp\lib\src\app\IINField.cpp \
                ..\..\..\cpp\lib\src\app\EventTriggers.cpp \
                ..\..\..\cpp\lib\src\app\Functions.cpp \
                ..\..\..\cpp\lib\src\app\HeaderWriter.cpp \
                ..\..\..\cpp\lib\src\app\GroupVariationRecord.cpp \
                ..\..\..\cpp\lib\src\app\MeasurementInfo.cpp \
                ..\..\..\cpp\lib\src\app\MeasurementTypeSpecs.cpp \
                ..\..\..\cpp\lib\src\app\MeasurementFactory.cpp \
                ..\..\..\cpp\lib\src\app\MeasurementTypes.cpp \
                ..\..\..\cpp\lib\src\app\range.cpp \
                ..\..\..\cpp\lib\src\app\OctetData.cpp \
                ..\..\..\cpp\lib\src\app\QualityFlags.cpp \
                ..\..\..\cpp\lib\src\app\PrefixedWriteIterator_for_UInt16_OctetString.cpp \
                ..\..\..\cpp\lib\src\app\PrefixedWriteIterator_for_UInt16_Binary.cpp \
                ..\..\..\cpp\lib\src\app\Serializer.cpp \
                ..\..\..\cpp\lib\src\app\RangeWriteIterator_for_UInt8_Binary.cpp \
                ..\..\..\cpp\lib\src\app\RangeWriteIterator_for_UInt8_Counter.cpp \
                ..\..\..\cpp\lib\src\app\DownSampling.cpp \
                \
                ..\..\..\cpp\lib\src\outstation\Event.cpp \
                ..\..\..\cpp\lib\src\outstation\EventBufferConfig.cpp \
                \
                ..\..\..\cpp\lib\src\outstation\event\ClazzCount.cpp \
                ..\..\..\cpp\lib\src\outstation\event\EventCollection.cpp \
                ..\..\..\cpp\lib\src\outstation\event\EventLists.cpp \
                ..\..\..\cpp\lib\src\outstation\event\EventRecord.cpp \
                ..\..\..\cpp\lib\src\outstation\event\EventSelection.cpp \
                ..\..\..\cpp\lib\src\outstation\event\EventStorage.cpp \
                ..\..\..\cpp\lib\src\outstation\event\EventTypeImpl.cpp \
                ..\..\..\cpp\lib\src\outstation\event\EventUpdate.cpp \
                ..\..\..\cpp\lib\src\outstation\event\EventWriting.cpp \
                ..\..\..\cpp\lib\src\outstation\event\IEventType.cpp \
                ..\..\..\cpp\lib\src\outstation\event\TypedStorage.cpp \
                ..\..\..\cpp\lib\src\outstation\event\List_for_EventRecord_part1.cpp \
                ..\..\..\cpp\lib\src\outstation\event\List_for_EventRecord_part2.cpp \
                ..\..\..\cpp\lib\src\outstation\event\List_TypedEventRecord_for_AnalogOutputStatusSpec_part1.cpp \
                ..\..\..\cpp\lib\src\outstation\event\List_TypedEventRecord_for_AnalogOutputStatusSpec_part2.cpp \
                ..\..\..\cpp\lib\src\outstation\event\List_TypedEventRecord_for_AnalogSpec_part1.cpp \
                ..\..\..\cpp\lib\src\outstation\event\List_TypedEventRecord_for_AnalogSpec_part2.cpp \
                ..\..\..\cpp\lib\src\outstation\event\List_TypedEventRecord_for_BinaryOutputStatusSpec_part1.cpp \
                ..\..\..\cpp\lib\src\outstation\event\List_TypedEventRecord_for_BinaryOutputStatusSpec_part2.cpp \
                ..\..\..\cpp\lib\src\outstation\event\List_TypedEventRecord_for_BinarySpec_part1.cpp \
                ..\..\..\cpp\lib\src\outstation\event\List_TypedEventRecord_for_BinarySpec_part2.cpp \
                ..\..\..\cpp\lib\src\outstation\event\List_TypedEventRecord_for_CounterSpec_part1.cpp \
                ..\..\..\cpp\lib\src\outstation\event\List_TypedEventRecord_for_CounterSpec_part2.cpp \
                ..\..\..\cpp\lib\src\outstation\event\List_TypedEventRecord_for_DoubleBitBinarySpec_part1.cpp \
                ..\..\..\cpp\lib\src\outstation\event\List_TypedEventRecord_for_DoubleBitBinarySpec_part2.cpp \
                ..\..\..\cpp\lib\src\outstation\event\List_TypedEventRecord_for_FrozenCounterSpec_part1.cpp \
                ..\..\..\cpp\lib\src\outstation\event\List_TypedEventRecord_for_FrozenCounterSpec_part2.cpp \
                ..\..\..\cpp\lib\src\outstation\event\List_TypedEventRecord_for_OctetStringSpec_part1.cpp \
                ..\..\..\cpp\lib\src\outstation\event\List_TypedEventRecord_for_OctetStringSpec_part2.cpp \
                ..\..\..\cpp\lib\src\outstation\event\Nodes.cpp \
                ..\..\..\cpp\lib\src\outstation\event\TypedEventRecord.cpp \
                \
                ..\..\..\cpp\lib\src\gen\Attributes.cpp \
                ..\..\..\cpp\lib\src\gen\DoubleBit.cpp \
                ..\..\..\cpp\lib\src\gen\CommandStatus.cpp \
                ..\..\..\cpp\lib\src\gen\IntervalUnits.cpp \
                ..\..\..\cpp\lib\src\gen\FunctionCode.cpp \
                \
                ..\..\..\cpp\lib\src\gen\objects\Group60.cpp \
                ..\..\..\cpp\lib\src\gen\objects\Group1.cpp \
                ..\..\..\cpp\lib\src\gen\objects\Group2.cpp \
                ..\..\..\cpp\lib\src\gen\objects\Group20.cpp \
                ..\..\..\cpp\lib\src\gen\objects\Group30.cpp \
                ..\..\..\cpp\lib\src\gen\objects\Group32.cpp \
                ..\..\..\cpp\lib\src\gen\objects\Group50.cpp \
                ..\..\..\cpp\lib\src\gen\objects\Group51.cpp \
                \
                ..\..\..\cpp\tests\unit\utils\APDUHelpers.cpp 

#                ..\..\..\cpp\lib\src\gen\objects\Group32.cpp \
