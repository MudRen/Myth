// Room: /d/moon/fengxue/lake.c

inherit ROOM;

#include <ansi.h>
void create()
{
        set("short", "����");
        set("long", @LONG

    �ƹ�һ��ɽ�ţ���һƬ�����Ա��������棬��������ĺ���Ҫ�����öࡣ��˵��
������������Ǳˮ��ȥ�������ں����ҵ������䱦��

LONG);
  set("no_clean_up", 0);
  set("outdoors","fengxue");
  set("exits",([
    "east" : __DIR__"lake",
]));

        setup();
}
void init()
{
  add_action("do_dive","dive");
  add_action("do_move","push");
}

int do_dive()
{
  object me,paper;
  me = this_player();

  if (( !(paper=present("bishui zhou", me))
                ||(string)paper->query("unit")!="��"))
     return notify_fail("��һ����������ˮ�����\n"+
                  "\n��û�����ͱ���ð�����ֻ�øϽ����ϰ�����\n");

  message_vision(HIY "$Nһ����������ˮ�У�Ȼ�󲻼��ˣ�\n" NOR, me);
  me->move(__DIR__"shijie2");
  message_vision("�л��㱵أ�$N����ˮ�ף�ȴ��������ط���Ȼû��ˮ��\n",me);
  return 1;
}

int do_move(string arg)
{
   object me = this_player();

   if ((string)arg!="shuzhi")
      return notify_fail("ʲô��\n");

  if (me->query("str") + me->query("force_factor")<40)
   {
      message_vision("$Nʹ����������֦��ȴ��һ�㶼�Ʋ�����\n",me);
          return 1;
   }
   else   {
      message_vision("$N����ز������Ե���֦��ȴ����һ��С·��\n",me);
      me->move(__DIR__"xiaolu");
      message_vision("$N�����������˹�����\n",me);
   }
   return 1;
}
