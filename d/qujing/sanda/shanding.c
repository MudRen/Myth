//Cracked by Roath

//  ����֮�� ������
//  by happ@YSZZ 2000.4.14

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

ɽ���Ͼ���Щ�����������Ϳ�������գ�����������л���ĸ質
�ţ��ƺ�������֪���������ϴ��ںܶ��Σ�գ�����һЩС�Ķ���
��������Ľű��ܹ����㲻��ͯ�Ĵ󷢣������Ա߻���һ�ô�������
�������������ȥ������

LONG);

  set("exits", ([
        "northwest"     : __DIR__"shanding2",
        "eastdown"   : __DIR__"shanpo3",
      ]));
  setup();
}

void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object ob = this_player();

         if ( ! arg || arg != "up" )
          {
         write("��Ҫ��������\n");
          return 1;
          }
        if( ob->query("kee") < 50 )
          {
         write("��һ����С�Ĵ�����ˤ��������\n");
         return 1;
          }
         message_vision(HIC"ֻ��$N��������Ƶĺ������������ȥ��\n"NOR,ob);
         ob->move(__DIR__"tree");
         ob->add("kee", -50);
         return 1;
}
