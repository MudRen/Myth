//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "����ɽ");
set("long", @LONG
    
��ɽ��ʮ��֮����������֮�������Կ����Ƕ����������к�
���ɡ������ɽ���дʸ�Ϊ֤����Ի��

���������������󣬳�ӿ��ɽ����Ѩ��
����������������������ѩ������Ԩ��

LONG );


set("exits", ([
  "northup"   : __DIR__"up1",
  "west"   : __DIR__"aolai",
]));


//set("objects", ([
//]));



set("outdoors", 1);

setup();
}
