//by dewbaby//shulin2

#include <ansi.h>
inherit ROOM;

void create()
{
     set("short", GRN"������"NOR);
     set("long", @LONG
��������һƬï�ܵ������֣���֦Ʈ�ڣ���Ҷӯӯ���㱻��Ƭ����
�Ի�ס�ˣ��������Ա����ʱ֮·��
LONG);

     set("outdoors","������");

     set("exits", ([
         "west" : __DIR__"shulin6",
          "north" : __DIR__"shulin7",
          "south":__DIR__"shulin2",
     ]));    
 
     setup();
}


