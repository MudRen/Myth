inherit ROOM;

#include <ansi.h>
void create()
{
      set("short", "��");
      set("long", @LONG
������һ��������̦����ʯ��С·���ұ�����ˮ���ӣ�С����
�£������������ӳ��ɽ�����������������ף��������ʡ�
����һƬ�ݵأ�ԶԶ���ƺ����Ѿ��ŵ��˻��㡣
LONG );
      set("outdoors", "nightstar");
      set("no_fight", "1");
      set("no_steal", "1");
      set("exits", ([
            "south"   : __DIR__"bamboo",
            "northup": __DIR__"ground",
            "north"   : __DIR__"bamboo1",
      ]));
}

int valid_leave(object me, string dir)
{
      int c_exp,c_skill;
      me = this_player();
      if (dir == "north")
      {
          if ((int)me->query("kee") < 50)
              return notify_fail("���ŵ㣬С�����塣\n");
          c_exp=me->query("combat_exp");
          c_skill=me->query_skill("dodge",1);
          if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<301))
              me->improve_skill("dodge", (int)me->query_skill("dodge", 1)*10);
          me->receive_damage("kee",30);

          tell_object(me,"�������������е������������Ṧ��Ϊ��������\n");
      }
      return 1;
}

