inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","ɱ��ҩ��" );
  set ("long", @LONG

            ��  ��  ��  ��         ��  ҩ  ��  ��

LONG);
  set("exits", (["down" : __DIR__"pkdao",]));
  set("objects", ([__DIR__"npc/boss" : 1,]));
  set("no_fight", 1);
  set("no_magic", 1);
  set("outdoors", 0);
  setup();
}
void greeting(object who) {
if( who->query("combat_exp") < 500000)
{
message_vision(HIR"���ϴ���һ��ŭ������$N��ѧ����50���ˣ����ȥ�ѣ���\n"NOR,who);
who->move("/d/city/kezhan");
}
}
