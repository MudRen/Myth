//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/road1.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���и߿أ������ϣ���һ����ɽ�����ĺ����������м����һ��
��ͭ��¯�����߽������ϣ�����һ�����ֽ�Ĵ��������飺
[32m
        ˿Ʈ����ƽ����ѩ����÷СԺ����

[m
LONG);
  set("exits", ([
        "west"  : __DIR__"kitchen",
         "east" : __DIR__"born",
         "south": __DIR__"inroom",
         "out": __DIR__"road4",
          ]));
  set("objects", ([
        __DIR__"npc/oldwoman":1,
        ]));
/*
// ����ط������ó�no_fight
// ���˭Ҫ�Ļ�ȥ��������wiz_room post
// ��Ҳ��֪���ĳ�no_fight��û��Ӱ�졡
// ��������ģ�����������pk
// ��ʱ��û������������ʲô�õ�
// ������������:)
// mudring Dec/08/2002
set("no_fight",1);
*/
// �����кð취������.
// mudring Dec/10/2002
set("no_pk",1);
  setup();
}

void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","kill");
        add_action("do_none","steal");
        add_action("do_none","ji");
}

int do_none()
{
        object ob = this_object();

        tell_object(ob,HIC"���������Ŀ����㡣\n"NOR);
        return 1;
}
