#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "����");
  set ("long", @LONG

           ��  ��  ɱ  ¾         ��  ʱ  ��  ��

LONG);
  set("exits", (["up" : __DIR__"pkdao",]));
  set("outdoors", 0);
  set("sleep_room",1);
  set("if_bed",1);
  setup();
  replace_program(ROOM);
}
void greeting(object who) {
if( who->query("combat_exp") < 500000)
{
message_vision(HIR"���ϴ���һ��ŭ������$N��ѧ����50���ˣ����ȥ�ѣ���\n"NOR,who);
who->move("/d/city/kezhan");
}
}
