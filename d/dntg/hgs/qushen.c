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
  "out": __DIR__"huntian",
  "enter": __DIR__"yishan",
]));


set("objects", ([
  "/d/dntg/sky/stars/fjz" : 1,
]));



  set("outdoors", 1);

setup();
}
