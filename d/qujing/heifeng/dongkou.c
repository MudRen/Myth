//  Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/road3.c
//  modified by vikee for xlqy
// 2000-11-25 14:22

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����ǰ�����������ˣ�����ʯ�Ž��գ���һ���ķ羰�������˵�
�ܣ���ס�ڴ�Ҳ���Գ��������ˡ�
LONG);

  set("exits", ([
        "north"  : __DIR__"road4",
      ]));
  set("outdoors","hf");
  setup();
}

void init()
{
        add_action("do_break","break");
}
int do_break(string arg)
{
        object ob = this_player();

        if( ! arg || arg != "door" )
                return notify_fail("��Ҫ�ҿ�ʲô��\n");

        if( ob->query("force") < 500 )
                return notify_fail("�������������\n");

        if( !ob->query_temp("fired") )
        {         
         write("��һ�þ���������˸����ͷ��\n");
         ob->unconcious();
         return 1;
        }

        message_vision("\nֻ��$N˫�ַ�������һ����������\n",ob);
        message_vision("�ͼ�ʯ�ű�$N�������顣\n",ob);
        set("exits/enter",__DIR__"in1");
        ob->set("force",0);
        return 1;
}
