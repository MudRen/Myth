//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "ͨ���ʥ��");
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
  "out": __DIR__"fuhai",
  "northup": __DIR__"shanya",
]));


set("objects", ([
  "/d/dntg/sky/stars/ivan" : 1,
]));



  set("outdoors", 1);

setup();
}
