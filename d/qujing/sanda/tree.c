//Cracked by Roath

//  ����֮�� ������
//  by happ@YSZZ 2000.4.14

inherit ROOM;
#include <ansi.h>


void create ()
{
  set ("short", "����");
  set ("long", @LONG

����һ�ô�������������˺ܶ�Ĵ����ӣ���Ŀ�ˮ���������ϵ�
����ȥ����������һ�㡣

LONG);

  set("exits", ([
        "down"     : __DIR__"shanding",
      ]));
  setup();
}

void init()
{
        add_action("do_pick","pick");
}

int do_pick(string arg)
{
        object ob = this_player();
        object tao = new(__DIR__"obj/tao");
        
        if( !arg || arg != "tao zi")
          {
          tell_object(ob,"��Ҫժʲô��\n");
          return 1;
          }
        if( present("tao",ob) )
           {
           tell_object(ob,RED"����ô��ô̰�ġ�\n"NOR);
           return 1;
           }
        tao->move(ob);
        message_vision("$N������ժ��һ���ִ��ֺ�����ӡ�\n",ob);
        return 1;
}        
