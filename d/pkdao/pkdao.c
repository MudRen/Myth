#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short",HIR "ɱ����԰" NOR);
  set ("long",@LONG

           ɱ  ��  ��  ��         ��  ��  ��  ��

LONG);
  set("exits",([
  "north" : __DIR__"room1",
  "west" : __DIR__"room2",
  "east" : __DIR__"room3",
  "south" : __DIR__"room4",
  "northwest" : __DIR__"room5",
  "northeast" : __DIR__"room6",
  "southwest" : __DIR__"room7",
  "southeast" : __DIR__"room8",
  "northup" : __DIR__"room9",
  "southup" : __DIR__"room10",
  "westup" : __DIR__"room11",
  "eastup" : __DIR__"room12",
  "northdown" : __DIR__"room13",
  "southdown" : __DIR__"room14",
  "westdown" : __DIR__"room15",
  "eastdown" : __DIR__"room16",
  "up" : __DIR__"room17",
  "down" : __DIR__"room18",
  ]));
  set("no_pkdao", 1);
  set("outdoors", 1);
  setup();
  "/obj/board/pkboard"->foo();
}

void init()
{
       call_out("greeting", 1, this_player());
       add_action("do_cast", "cast");
       add_action("do_fight", "fight");
       add_action("do_kill", "kill");
       add_action("do_perform", "perform");
}
int do_cast(string arg)
{
       object who = this_player();
       object me = this_object();
       message_vision(HIR"���ϴ���һ��ŭ��������������$N���÷�����Ҫ�򶷾͵�ս����̨��ȥ����\n"NOR,who);
       return 1;
}
int do_fight(string arg)
{
       object who = this_player();
       object me = this_object();
       message_vision(HIR"���ϴ���һ��ŭ���������ﲻ�Ǵ򶷵ĵط���$N��ս����̨��ȥ�ٴ򣡡�\n"NOR,who);
       return 1;
}
int do_kill(string arg)
{
       object who = this_player();
       object me = this_object();
       message_vision(HIR"���ϴ���һ��ŭ��������û������̨����ɱ�ˣ�$NС���ңӣͣ��ӣ��㣡��\n"NOR,who);
       return 1;
}
int do_perform(string arg)
{
       object who = this_player();
       object me = this_object();
       message_vision(HIR"���ϴ���һ��ŭ������$N�ɲ������������þ���Ŷ����\n"NOR,who);
       return 1;
}
void greeting(object who) {
if( who->query("combat_exp") < 5000000)
{
message_vision(HIR"���ϴ���һ��ŭ������$N��ѧ����50���ˣ����ȥ�ѣ���\n"NOR,who);
who->move("/d/city/kezhan");
}
}
