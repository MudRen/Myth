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
         "east" : __DIR__"minghu5",
          "west" : __DIR__"shulin4",
          "north":__DIR__"shulin5",
     ]));    
 
     setup();
}


