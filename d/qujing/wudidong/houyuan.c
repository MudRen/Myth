// Room: /d/qujing/wudidong/houyuan
// created 6-18-97 pickle
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "��Ժ");
  set ("long", @LONG

��Ժ����Ҷ��أ�Ҳû���˴�ɨ����������һ��ʯ�������泤������
̦�Ӳݣ��Ա�һ����������ˮ��ͰҲ��֪��ȥ�ˣ������ܾ�û���ù�
�ˡ�
LONG);

  set("light_up", 1);
  set("outdoors", "/d/qujing/wudidong");
  set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"bedroom",
]));

  setup();
}
void init()
{
  add_action("do_dive", "dive");
}

int do_dive(string arg)
{
  object me, tar;
  me=this_player();
  if ( !arg || ((arg !="well") ))
    return notify_fail("��Ҫ���Ķ�����\n");
  
  if (!tar=present("bishui zhou", me))
    return notify_fail(HIY "���������¾�ȥ������ˮ��Ƿ�ѣ�Ǻ������ˮ�󣬲��ò����ž������˻�����\n" NOR);
  else message_vision(HIW "$Nһ�������¾�ȥ��\n" NOR, me);
  me->move(__DIR__"well");
  return 1;
}
