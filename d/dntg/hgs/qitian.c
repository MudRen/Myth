//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "�����ʥ��");
set("long", @LONG

      �ǹ����

   ǧ          ��
   ��          ��
   ��          ��
   ��          ��
   ��          Ⱥ
   ��          Ӣ
   ��          ��

LONG );


set("exits", ([
  "southdown": __DIR__"shanlu2",
  "enter": __DIR__"pingtian",
]));


set("objects", ([
  "/d/dntg/sky/stars/xqing" : 1,
]));



  set("outdoors", 1);

setup();
}
