//edit by xuanzi
inherit ROOM;
#include <ansi.h>

void create()
{
  set("short",HIG"��԰"NOR);
  set("long",@LONG

������һ�������Ļ�԰���������������Ư���Ļ������涷�ޣ���ɫ
���أ��ƺ����Ƿ������С�

LONG);

 set("outdoors",__DIR__);
 set("exits",([
   "south":__DIR__"wytdamen",
   ]));

  setup();
}
void init()
{
  add_action("do_fl","zhong");
}

int do_fl(string arg)
{
  object me = this_player();
if (!arg||(string)arg!="flower") return notify_fail("ʲô��\n");
if ((int)me->query("kee")<100)
return notify_fail("��̫���ˣ���������Ϣһ�°ɣ�\n");
if (me->is_busy())
return notify_fail("����æ���أ�\n");
  
  message_vision("$N����һ��С��ͷ����ϸ����һ���ӣ���һ�����ѽ�ȥ��\n",me);
me->add("kee",-50);
me->start_busy(8);
  remove_call_out("finish");
  call_out("finish",5,me);
  return 1;
}

void finish(object me)
{
  object flower;
if (random(2)) message_vision("\n�㽽ˮ�����������û�п���\n",me);
else {
flower = new("/d/obj/flower/rose999");
 message_vision("\nһ��紵���������ˣ�"+flower->name()+"�ڷ���ҡҷ����Ư������\n",me);
  flower->move(me);
}
}

