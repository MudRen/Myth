// create by snowcat.c 4/8/1997
// room: /d/westway/jiuquan.c

inherit ROOM;
#include <ansi.h>


void create ()
{
  set ("short","��Ȫ����");
  set ("long", @LONG

��Ȫ�����ǳ�;�����Ъ�ŵ���һ����Ҫ�ص㡣����Ƚ����֣�
�����Բ��ƶ�����������������ҹ�Ɑ���ɴ˶�����������һ
�������������һ��ʯջ���������������ص�Сɽ��

LONG);

  set("exits", ([
        "east"      : __DIR__"madao",
        "west"      : __DIR__"shizhan",
        "northup"   : __DIR__"yunti",
      ]));
//  set("outdoors", __DIR__);

       set("tsj_exst","west");
  setup();
}



