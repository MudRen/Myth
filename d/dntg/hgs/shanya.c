//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "ɽ��");
set("long", @LONG
    
���������Ļ���ɽһ·������ֻ�е������һ��һľ������
��Ŀһ�¡��ɴˣ���ɽ��·ͨ��һ���ٲ��������ǻ���ɽ��
�����ǵĽо����������Ǵ�����ȥ����ʱ������׳�ĺŽ�����
LONG );


set("exits", ([
"east"   : __DIR__"pubu",
"west"   : __DIR__"jiaojunchang",
"southdown"   : __DIR__"tongfeng",
]));


set("objects", ([
__DIR__"npc/ba" : 1,
__DIR__"npc/maque" : 1,
]));



set("outdoors", 1);
setup();
}
