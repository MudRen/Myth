//Cracked by Roath
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "��ʯ̨");
  set ("long", @LONG

�������Ϸ�������������Ǻ�ȥ������������Ұ��������Χ��ɫ
�������������ʯ�²�֪���ж�ߣ��������в������ߣ�������
�����ƣ�Ҳ��֪�ж���ˡ�
LONG);
  set("exits", ([ /* sizeof() == 3 */
//  "south" : __DIR__"road1",
]));
	set("outdoors", 1);
  setup();
}


void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	object me=this_player();
	
	if( !arg || (arg!="����" && arg!="����" && arg!="cliff") )
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy())
		return notify_fail("�����ں�æ����ʲôѽ��\n");
	
	message_vision("$N���˴��֣�����ʯͷ�ķ�϶��������ȥ������\n", me);
	me->start_busy(3);

	if( (int)me->query("kee") < 500 || (int)me->query("sen") < 500) {
		call_out("faila", 3, me);
		return 1;
	}

	if( (int)me->query_skill("dodge",1)+(int)me->query_skill("unarmed",1) <=200 ){
		call_out("faila", 3, me);
		return 1;
	}

	if( random((int)me->query_kar()) <= 5){
		call_out("faila", 3, me);
		return 1;
	}
 
	call_out("success", 3, me);
	return 1;
}
int success(object me)
{
	message_vision("$NԽ��Խ�ߣ��������������С�����\n", me);
	me->move("/d/penglai/yashang");
	me->receive_damage("kee", 400);
	me->receive_damage("sen", 400);
	message_vision("$N����������������\n", me);
	return 1;
}
int faila(object me)
{
	tell_object(me, "������һ�����ȣ������ϵ�������������\n");
	tell_room(environment(me), me->name()+"�����ƵĴ����ϵ���������\n", ({me, me}));
	me->unconcious();
	
	return 1;
}
