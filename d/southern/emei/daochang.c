//Cracked by Roath
// ajax

inherit ROOM;

void create()
{
set("short", "������������");
set("long", @LONG
    
������������ʱ��һ�죬��λ�����ѹ�����ʿ����ɽ�ϲ�ҩ��
ͻȻ��һͷ�Ž���ߣ�������󣬴ӿ��зɳ۶����������
�����壬ȴ�������˼������ѹ�����֪����������������ȫ
����ǣ��ѹ���ɽ��լΪ���������ͣ��������ɽ�ͳ�
�����͵�����
LONG );


set("exits", ([
  "east"   : __DIR__"shanlu5",
  "westup"   : __DIR__"jinding",
  "south"   : __DIR__"wanniansi",
  "north"   : __DIR__"guangxiangsi",
 
]));


set("objects", ([
     __DIR__"npc/puxian" : 1,
]));



set("outdoors", 1);

setup();
}
