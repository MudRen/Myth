// ������ ����԰ by Calvin

#include <ansi.h>
inherit ROOM;
inherit "/d/9ct/qy/climbtree.c";

void create ()
{
  set ("short", NOR"����԰"NOR);
  set ("long", @LONG

����������������������������������������������������������������������������
������   �����ǻʹ��ĺ�Ժ - "����԰",�����ļ�����,���������۵ľ���    ������
������   ��԰�м���ǿ�"ǧ����(qianzi teng)",����������,һ�ۿ�����    ������
������   ��.��˵����������������,����û��һ��ͷ�����,��������Ҳ��    ������
������   �˺ö���,������Ҳ������������ȥ,��˵����õ�������ϵ�һ   ������
������   �����ﲢ�����ʵ۵Ļ����Եõ��ʹ�,�����ʹ��(climb)���� ...   ������
����������������������������������������������������������������������������

LONG);

  set("exits", ([
             "north": "/d/calvin/lanling/entrance",
      ]));

  set("objects", ([
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
                   me->move("/d/9ct/qy/yi.c");
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
