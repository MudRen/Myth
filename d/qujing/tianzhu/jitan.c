
inherit ROOM;

void create ()
{
  set ("short", "��̨");
  set ("long", @LONG

����ʼ����������ƣ�̨�Ϲ�����һ�����ϵ�����Ȼ��
���ؾ����صؽ����������������������˵����񹩷�����
��,��������յİ�����ҵ��
LONG);

  set("no_quit",1);
  set("no_flee",1);
  set("alternative_die",1);
  set("exits",([
    "south" : __DIR__"jiedao18",
  ]));
  setup();
}

#include "/d/obj/misc/jitan.h"
