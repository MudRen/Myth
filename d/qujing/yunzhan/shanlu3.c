//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/shanlu3.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

�������У�ʱ������������֮��Ұ�׷����ļ��֮�����ɾ��ĺ���
��Ұ�Ǵ�����ǰ������ȥ�����������ľ���������Ľ�����һ�Թ�
ľ(bush)�ڷ�Ĵ������𸡲�����
LONG);

  set("exits", ([
        "westdown"   :"/d/qujing/huangfeng/road1",
        "eastdown"  : __DIR__"shanlu2",
      ]));
  set("outdoors","yz");
  setup();
}

void init()
{
        add_action("do_kan","kan");
}

int do_kan(string arg)
{
        object ob = this_player();
        object wield;

        if(!wield=ob->query_temp("weapon"))
                return notify_fail("������û��������\n");

        if( ! arg || arg != "bush" )
                return notify_fail("��Ҫ��ʲô��\n");

        if(((string)wield->query("skill_type")!="sword"
             && ((string)wield->query("skill_type")!="blade")))
                return notify_fail("��Ӧ���Ұѽ������ǵ�ʲô�ġ�\n");

        message_vision(HIR"$N���Ź�ľ���Ϳ���һ�����Ź�ľ�ĵ��£���Ȼ������һ�����ڡ�\n"NOR,ob);
                set("exits/down", __DIR__"in1");
                remove_call_out("close");
                call_out("close", 5, this_object());
                return 1;
}
void close(object room)
{
        message("vision","��һ��������һЩ��ľ���˹������պö�ס�˶��ڡ�\n", room);
        room->delete("exits/down");
}
