
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����Ͽ");
  set ("long", @LONG

Ͽ�аٳ��೤������ʯ��(wall)���ʡ�����̦�۰߲�������������
�ܣ���Ե���£���ʯ������ɲ�����ֵ�ͼ��������������
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "wall" : "ͼ���ƺ��Ǽ������ڱ��䡣\n",
]));


  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"feifeng",
  "southdown" : __DIR__"jixian",
]));

  setup();
}

void init()
{
        add_action("do_study", "read");
}

int do_study(string arg)
{	
	object me=this_player();
	int sen_cost, kee_cost, force_cost, gain;

	if( !arg || (arg != "wall"))
		return notify_fail("��Ҫѧʲô��\n");
	if( me->is_busy() )
		return notify_fail("��æ�ĺܣ����й���ȥ��ʯ�ڣ�\n");
	if( me->is_fighting() )
		return notify_fail("��ѧ�������������ˣ�\n");
	if( (int)me->query_skill("literate", 1) < 100)
		return notify_fail("�㿴�˰���Ҳ���������滭����ʲô��\n");
	if( (int)me->query_skill("unarmed", 1) < 100)
		return notify_fail("�㿴�˰�����󿴳��˵��ŵ���ȴһʱ�����ˡ�\n");
	if( (int)me->query_skill("unarmed", 1) >= 140)
		return notify_fail("�㶨�����˻ᣬ���Ѿ�ȫ�������ˡ�\n");
	if( (int)me->query("max_force") < 1000)
		return notify_fail("��������㣬�����ˡ�\n");

	sen_cost = 80 - (int)me->query_int();
	if( (int)me->query("sen") < sen_cost )
		return notify_fail("������ͷ�����ͣ�����Ϣ��Ϣ�ˡ�\n");

	kee_cost = 80 - (int)me->query_con();
	if( (int)me->query("kee") < kee_cost )
		return notify_fail("�����ڻ�������������Ϣ��Ϣ�ˡ�\n");

	force_cost = 20;
	if( (int)me->query("force") < force_cost )
		return notify_fail("���������᲻�����ˣ�����Ϣ��Ϣ�ˡ�\n");

	me->receive_damage("sen", sen_cost);
	me->receive_damage("kee", kee_cost);
	me->add("force", - force_cost);

	gain = (int)me->query("int")/2 + (int)me->query("con")/2 + 1 + random(10);

	me->improve_skill("unarmed", gain);

	write("������ʯ���ϵ�ͼ���Ȼ����ԡ��˻���֮�����������˽⡣\n");

	tell_room( environment(me), me->name() + "˫�ֻ�����ȥ����֪�ڱȻ�ʲô��\n", ({me}));

	return 1;
}
