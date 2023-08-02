#include "header.h"
#include "LinkStatistics.h"

 void Parser_in_LinkStatistics__in__Parser_in_LinkStatistics(Parser_in_LinkStatistics *pParser_in_LinkStatistics)
{
        /// Number of frames discarded due to header CRC errors
/// ���������� ������, ����������� ��-�� ������ CRC � ���������
        pParser_in_LinkStatistics->numHeaderCrcError = 0;

        /// Number of frames discarded due to body CRC errors
/// ���������� ������, ����������� ��-�� ������ CRC ����
        pParser_in_LinkStatistics->numBodyCrcError = 0;

        /// Number of frames received
/// ���������� ���������� ������
        pParser_in_LinkStatistics->numLinkFrameRx = 0;

        /// number of bad LEN fields received (malformed frame)
/// ���������� ���������� �������� ����� LEN (��������������� ����)
        pParser_in_LinkStatistics->numBadLength = 0;

        /// number of bad function codes (malformed frame)
/// ���������� ������������ ����� ������� (��������������� �����)
        pParser_in_LinkStatistics->numBadFunctionCode = 0;

        /// number of FCV / function code mismatches (malformed frame)
/// ���������� �������������� ���� FCV/������� (�������� ����)
        pParser_in_LinkStatistics->numBadFCV = 0;

        /// number of frames w/ unexpected FCB bit set (malformed frame)
/// ���������� ������ � ����������� ������������� ����� FCB (��������������� ����)
        pParser_in_LinkStatistics->numBadFCB = 0;
}

void Channel_in_LinkStatistics__in__Channel_in_LinkStatistics(Channel_in_LinkStatistics *pChannel_in_LinkStatistics)
{
        /// The number of times the channel has successfully opened
/// ������� ��� ����� ������� ����������
        pChannel_in_LinkStatistics->numOpen = 0;

        /// The number of times the channel has failed to open
/// ������� ��� ����� �� ��������
        pChannel_in_LinkStatistics->numOpenFail = 0;

        /// The number of times the channel has closed either due to user intervention or an error
/// ������� ��� ����� ���������� ���� ��-�� ������������� ������������, ���� ��-�� ������
        pChannel_in_LinkStatistics->numClose = 0;

        /// The number of bytes received
/// ���������� ���������� ������
        pChannel_in_LinkStatistics->numBytesRx = 0;

        /// The number of bytes transmitted
/// ���������� ���������� ������
        pChannel_in_LinkStatistics->numBytesTx = 0;

        /// Number of frames transmitted
/// ���������� ���������� ������
        pChannel_in_LinkStatistics->numLinkFrameTx = 0;
}

void LinkStatistics_in_LinkStatisticsOver1(LinkStatistics *pLinkStatistics)
{
  Parser_in_LinkStatistics__in__Parser_in_LinkStatistics(&(pLinkStatistics->parser));
 Channel_in_LinkStatistics__in__Channel_in_LinkStatistics(&(pLinkStatistics->channel));
}

void LinkStatistics_in_LinkStatisticsOver2(LinkStatistics *pLinkStatistics,
                                           Channel_in_LinkStatistics* channel, 
                                           Parser_in_LinkStatistics* parser)
{
  pLinkStatistics->channel = *channel;
  pLinkStatistics->parser = *parser;
}
