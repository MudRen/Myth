// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short", "���¹�");
  set ("long", @LONG

        ��ϵ��ѩ��

  ѩ                   ��
  ԭ                   ��
  ç                   ��
  ç                   ��
  ѩ                   ��
  ��                   ��
  ��                   ��
  ��                   ��
  ��                   ��
  ѩ                   ��
  ԭ                   ��
  ӳ                   ��
  ��                   ��
  ��                   ��


LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west"     : __DIR__"qinglongdian",
  "east"     : __DIR__"kangjingong",
  "northeast" : __DIR__"jishuigong",
  "southeast"  : __DIR__"weihuogong",

]));


  set("objects", 
      ([
       __DIR__"stars/yixue" : 1,
      ]));


  setup();
}
 
