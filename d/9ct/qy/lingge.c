// ������� ��ڤ�� by Calvin

#include <ansi.h>
inherit ROOM;
inherit "/d/9ct/qy/climbtree.c";

void create ()
{
set("short", "��ڤ��");
  set ("long", @LONG

          ����������������������������������
          ����������������������������������
          ����Խ����ǧ����  �ص������������
          ����������������������������������
          ����������������������������������

LONG);

  set("exits", ([
           "west" : __DIR__"huoge",
           "east" : __DIR__"tuge",
           "down" : __DIR__"wangxianya",
      ]));

  set("objects", ([
      "/d/9ct/npc/yimu" : 1,
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
                   me->move("/d/9ct/qy/sky.c");
        }
    }
  me->receive_damage("kee", (int)me->query("max_kee")*10/100);
  return 1;
}
