//by dewbaby//shulin7

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
         "east" : __DIR__"shulin4",
           "south" : __DIR__"shulin6",
        "northup" : __DIR__"shanya",
     ]));    
 
     setup();
}


