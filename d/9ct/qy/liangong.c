// ������ ���� ������ by Calvin

#include <ansi.h>
inherit ROOM;
inherit "/d/9ct/qy/climbtree.c";

void create ()
{
        set("short", HIC"���ء�������"NOR);
  set ("long", @LONG

          ��������������������������������������
          ��������������������������������������
          ��������˾�ǧɽ��  ˮ���˶ʯ��������
          ��������������������������������������
          ��������������������������������������

LONG);

  set("exits", ([
           "up" : __DIR__"tree7",
      ]));

  set("objects", ([
          "/d/9ct/npc/longfei" : 1,
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
          message_vision("$N�����һ�ھ���������,һ�����ʧ���޾����㻨֮���ˡ�\n", me);
                   me->move("/d/9ct/qy/ba.c");
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
        return notify_fail("������ס��˵��:�������һЩ�����벻Ҫǰȥ��\n");
        }   
        return ::valid_leave(me, dir);
}
