//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/shandao.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���ﾲ���ĵģ��м����һ�����棬����������

LONG);

  set("exits", ([
        "south": __DIR__"dadian",
      ]));
  setup();

}
void init()
{
  add_action("do_xiuxi", "xiuxi");
}
int do_xiuxi(string arg)
{
  object me=this_player();
if( me->query("obstacle/yj") !="done")
   return notify_fail("ʲô��\n");
if( me->query_temp("jiasha_given"))
{
message_vision(HIR"�������׼����Ϣ��\n"NOR,me);
message_vision(HIR"ͻȻ��Ȼһ�����\n"NOR,me);
message_vision(HIR"����������ȥ������ʲô�¡�\n"NOR,me);
me->set_temp("fired",1);
}
return 1;
} 
