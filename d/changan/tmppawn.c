// Room: /d/changan/tmppawn.c

#include <room.h>

inherit HOCKSHOP;

void create()
{
	set("short", "��ϲ������ʱ���´�");
	set("long", @LONG

��ϲ�����ڳ����������ĵ����ˡ��򳤰������ݱգ�������
��ˮ�ӱ���ʱ���˸����´����ſ���һ������(paizi)�����
������������ŷ�������ܰ����ƹ�ļ��������������Ƶ�
�Ͻ��ѹ�̨�ϵļ�С�������յ���̨���¡�
LONG
	);
	set("item_desc", ([
		"paizi": @TEXT
�����̲����ۺ�ͯ�����ۣ���ӭ�ݹˣ����Ա��ܡ�
�͹ٿ������������(value)���䵱(pawn)������(sell)��
���(retrieve stamp)������(buy)(��list�鿴)
���ֻ��ͭǮ���������ƽ���Ʊһ��ͨ�á�
TEXT
	]) );
	set("exits", ([
		"south" : __DIR__"eside2",
	]));

	setup();
}
