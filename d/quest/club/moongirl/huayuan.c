// ������ ����԰ by Calvin

#include <ansi.h>
inherit ROOM;
inherit "/d/9ct/qy/climbtree.c";

void create ()
{
  set ("short", "����԰"NOR);
  set ("long", @LONG

������Կ���˵��һ���˼��ɾ����������仨��ݣ�ɢ����
���˵ķҷ����ܶ����δ����С���ڻ���ĸ質����Զ��һ
��СϪ�������������ֹ����Ͻ����˷�˶�Ĺ�ʵ����������
��������������


LONG);

  set("exits", ([
             "south": __DIR__"moon5",
      ]));

         set("objects", 
        ([ //sizeof() == 1
        "d/moon/obj/xuelian" : 2,
        "/d/obj/flower/flower" : 2, 
"d/wizz/junhyun/obj/bei" : 1, 

        ]));

  setup();
}

int do_climb(string arg)
{
        object tianshen; 
  object me=this_player();

  if( (!arg) || !((arg == "sky") || (arg == "������")))
    return notify_fail("��ʲô��\n");
  if (me->is_busy()) return notify_fail("��������æ���ء�");
  if( me->query("kee") < (int)(me->query("max_kee")/3)){
    me->receive_damage("kee",(int)me->query("max_kee")*20/100);
    return notify_fail("�����ӷ��飬һͷ������������ѽ��\n");
}
  else
    {
      if ((int)me->query_skill("dodge", 1)<60 && (int)me->query_skill("moondance", 1) < 200)
        {
          message_vision("$NС������������ʵ���һ�㣬����ͷ���ۻ����͸Ͻ�����������\n", me);
          me->improve_skill("dodge", 60-me->query("str"));
          tell_object(me, "�������һЩ�����Ṧ��������š�\n");
        }
      else
        {
          message_vision("$N�����һԾ���Ʋ������εĽ���,һ�����ʧ���ƺ�֮�С�\n", me);
                   me->move(__DIR__"tian");
        }
    }
  me->receive_damage("kee", (int)me->query("max_kee")*10/100);
  return 1;
}

int valid_leave(object me, string dir)
{
        object a;
   if (dir == "up" ) {
                if(objectp(a=present("tianshen", environment(me))) &&
living(a) )
        return notify_fail("������ס��˵��:���������һЩ�����벻Ҫǰȥ��\n");
        }   
        return ::valid_leave(me, dir);
}

