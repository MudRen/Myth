
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "�ɷ��");
  set ("long", @LONG

����ɽ�߶������ܣ�Ψɽ����������ƣ���ͬ�������ǻ�����
�ò�ɢ�����˾��졣���཭��С�򣬽�é���ݶ��������ʣ���
Ȼ�������ŵ���Ȥ��
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/erlang" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"cuiping",
]));

  setup();
}

void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object ob = this_player();

        if( ! arg || arg != "down" )
                return notify_fail("��Ҫ��������\n");
        
        if(present("erlang zhenjun") )
                return notify_fail("�������ҡҡͷ���ο�ҪѰ�̼��ء�\n");

        message_vision("ֻ��$N����һԾ���������������¡�",ob);
        ob->move(__DIR__"fengdi");
        ob->unconcious();
        return 1;
}
