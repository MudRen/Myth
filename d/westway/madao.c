// create by snowcat.c 4/8/1997
// room: /d/westway/madao.c

inherit ROOM;
#include <ansi.h>


void create ()
{
  set ("short","���");
  set ("long", @LONG

һ������ר�õĳ�����·�����˴Ҵ�ææ�ظ�·�����߿쵽��
Ȫ�ˡ����Ϸ�����һƬ�ֵأ�·���ֵص����ȥ���Ǳ��Ǿ�
����Σ�յ���������

LONG);

  set("exits", ([
        "southeast" : __DIR__"yinma",
        "west"      : __DIR__"jiuquan",
      ]));
  set("outdoors", __DIR__);
       set("tsj_exst","west");

  setup();
}





