// Room: /d/death/walk.c
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", HIR"���Ź�"NOR);
  set ("long", @LONG

��Լ�����ֳ�һ����ɫ��¥����¥����һ�����ң�������š���ڤ
�硱�������֡���¥�³��Ž��գ��������ʲôҲ���������·��
һ����ľ��ֱֱ��ָ�򱱷�����Χֻ��������ɫ�Ļ����������
����˸�š�
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"new-out5",
  "west" : __DIR__"new-out7",
  "south": __DIR__"gate",
]));
  set("hell", 1);

  setup();
}

void init()
{
        object me=this_player();
		remove_call_out("greeting");
                call_out("greeting", 60, me);
	add_action("do_pass", "north");


}
void greeting(object ob)
{
        if( !ob || environment(ob) != this_object() ) return;
	ob->set_temp("time_enough", 1);
	return;
}
int do_pass()
{
	object me=this_player();
	
	if( me->is_ghost() && !me->query_temp("time_enough") )
		return notify_fail("��¥����Լ��������������̫ʢ��������ǣ�\n");

	if( me->is_ghost() ) {
		me->reincarnate();
		me->set("gin", (int)me->query("max_gin"));
		me->delete_temp("time_enough");
	}

	tell_object(me, "��ֱֱ���򱱶��ų�����ȥ����Ȼ���ֺ�ɫ�ĳ���ֻ�ǵ�����������\n");
	tell_room(environment(me), me->name()+"ֱֱ���򱱶��ų�����ȥ����Ȼ�ӽ��յ����д��˹�ȥ��\n",
({me, me}));
	me->move("/d/death/new-zhaopo");
	tell_room(environment(me), me->name()+"���˹�����\n", ({me, me}));
	return 1;
}
