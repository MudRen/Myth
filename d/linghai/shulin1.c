//by dewbaby//shulin1

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
         "southwest" : __DIR__"minghu5",
         "east" : __DIR__"yuexia",
          "north":__DIR__"shulin3",
     ]));    
 
     setup();
}


