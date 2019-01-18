#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "������ʮ����");
  set ("long", @LONG

����к���ͻأ��գ�������ɫ��������������������ƣ��г�
�޻𣬲�����ǰ����������ڸ�ɳ档����������ϣ����̾�����
�����⣬����ǰ������ǣ�ɡ�
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/baben" : 1,
  __DIR__"npc/benba" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"tower12",
]));

  setup();
}
void init()
{
  add_action("do_shao", "shao");
}
int do_shao(string arg)
{
	object me=this_player();
	
	if(!arg && arg != "di" && arg!="floor")
		return notify_fail("��Ҫɨʲô��\n");

	if(!present("broom", me))
		return notify_fail("ûɨ�صļһ���ô�У�\n");

	if(query("clean"))
		return notify_fail("���¹��ɾ��ˣ�����ɨ�ˣ�\n");

	if((int)me->query("kee") <20)
		return notify_fail("��̫���ˣ�ЪЪ�ɣ�\n");

	message_vision("$N�����Ŵ�ɨ��ɨ�������\n", me);
	message_vision("$NĨ��һ�Ѻ��������Ц��Ц��\n", me);
	me->receive_damage("kee", 15);
	me->add_temp("clean_floor", 1);
	
	if((int)me->query_temp("clean_floor") > 13){
		me->delete_temp("clean_floor");
	}
	set("clean", 1);
	call_out("regenerate", 800);
	set("long", @LONG

����к���ͻأ��գ�������ɫ����������ת�紩�ߣ��ſ��Ƴ�
������ƿӰ������£������������Ϸ硣���������ܹ���������
����������ʯ�������͸�����������Զ������ǧ���⣬�ߵ�
���ھ����С�
LONG);

	return 1;
}
int regenerate()
{
  set ("long", @LONG
                
����к���ͻأ��գ�������ɫ��������������������ƣ��г�
�޻𣬲�����ǰ����������ڸ�ɳ档����������ϣ����̾�����
�����⣬����ǰ������ǣ�ɡ�
LONG);  

        set("clean", 0);
        return 1;
}

