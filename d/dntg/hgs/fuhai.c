//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "������ʥ��");
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
  "out": __DIR__"yishan",
  "enter": __DIR__"tongfeng",
]));


set("objects", ([
  "/d/dntg/sky/stars/xuexing" : 1,
]));



  set("outdoors", 1);

setup();
}
