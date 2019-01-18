// created by angell 1/1/2001
// room: /d/qujing/huangfeng/yuan.c

#include <room.h>
inherit ROOM;

void create ()
{
	set ("short", "��԰");
	set ("long", @LONG

�Ʒ綴�ĺ�԰��ʯ��أ��Ĳ����죬���۵Ĺ�ľ���١�԰���ĵ�
�յ�������һ������(zhuzi)���������ɡ�

LONG);

      set("item_desc", ([ /* sizeof() == 1 */
  		"zhuzi" : "����ͨ����ڣ�ϸ���ŷ��������Ͽ��š�������������С�֡�
����ͥ�У���һ�˱���ľ��֦Ҷ��ס��͸��֦Ҷ�ķ�϶����
�����ƺ���ʲô�������������⡣
",
]));
       set("exits", 
	([ //sizeof() == 1
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));

	set("outdoors", __DIR__);

	setup();
}

void init()
{
  add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	object wugang;
  object me=this_player();
 
  if( (!arg) || !((arg == "zhuzi") || (arg == "������")))
    return notify_fail("��ʲô��\n");
  if( me->query("kee") < (int)(me->query("max_kee")/3)){
    me->receive_damage("kee",(int)me->query("max_kee")*20/100);
    return notify_fail("���������꣬ͻȻһ��ʧ�֣�����������\n");
}
  if ((int)me->query_skill("dodge", 1)<50)
        {
	  message_vision("$N������������ȥ�������Ϲ������û������֮�����������ֻ���������\n", me);
        }
      else
        {
	  message_vision("$N�������ֽŲ��ã�˳������������ȥ��\n", me);
          me->move(__DIR__"zhuzitop.c");
        }
  me->receive_damage("kee", (int)me->query("max_kee")*10/100);
  return 1;
}
