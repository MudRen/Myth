//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/road1.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "��");
  set ("long", @LONG

�������������Ϣ�ĵط�������������˹�������Ů��������
�������䶼���������㡣

LONG);
  set("exits", ([
        "north": __DIR__"house",
          ]));
  set("objects",([
        __DIR__"npc/girl1":1,
        __DIR__"npc/girl2":1,
        __DIR__"npc/girl3":1,
        ]));
  set("no_fight",1);
  setup();
}

void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","kill");
        add_action("do_none","steal");
        add_action("do_none","ji");
        add_action("do_none","exert");
}

int do_none()
{
        object ob = this_object();

        tell_object(ob,HIR"���������Ƥ��ҡ��ҡͷ��\n"NOR);
        return 1;
}
        
