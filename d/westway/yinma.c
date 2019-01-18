// create by snowcat.c 4/8/1997
// room: /d/westway/yinma.c

inherit ROOM;
#include <ansi.h>


void create ()
{
  set ("short","������");
  set ("long", @LONG

�߽�������������һ���Ӱ���������������ԼԼ��������һ��
����С�м��ĺ�«�������ȵ״�����������ˮ���������߳�
�����ھ���ȥ��Ȫ�����ߵ�������ͨ��ƽ������������ش���
�㣬�������죬���ַ·��������������е�ʲô������

LONG);

  set("exits", ([
        "east"      : __DIR__"pingyang",
        "northwest" : __DIR__"madao",
      ]));
  set("resource/water", 1);
  set("outdoors", __DIR__);

  set("objects",([
        __DIR__"npc/madao" : 1,
       ]));
//  set("tsj_exst","northwest");

  setup();
}

int valid_leave (object me, string dir)
{
  object madao;
  madao = present("ma dao",environment(me)); 
  if (madao &&
      living(madao) &&
      (string)me->query("family/family_name")!="��ׯ��" &&
      (me->query_temp("has_paid") <= 0) &&
      (me->query("obstacle/number") < 2) &&
      dir == "northwest")
  {
    if (random(3) == 0)
      message_vision ("$N��ݺݵ�����һ�Ѿ�ס$n�����Ķ��ܣ���Ǯ��\n",madao,me);
    return notify_fail("��������ţ�����Ǯ��Ҫɱ������\n");
  }
  if (me->query_temp("has_paid") > 0)
    me->set_temp("has_paid",me->query_temp("has_paid")-1);
  return 1;
}



