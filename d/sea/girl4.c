// hill.c

inherit ROOM;

void create()
{
  set ("short", "�Ʒ�");
  set ("long", @LONG

�����������ǰ���һ�����С���˵�ǵ���������̫���Ͼ����Ӯ��
�ġ�����������(lianwu)�е���ƮƮ�ģ�����ϰ�Ṧȴ����Ī���
�ô���
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"girl2",
]));
set("objects", ([
                __DIR__"npc/beisao": 1,
               "/d/obj/armor/tenjia": 1,
]) );

        set("no_clean_up", 0);
//      
        set("water", 1);
//  
        setup();
}

void init()
{
	add_action("do_dodge", "lianwu");
}

int do_dodge()
{
	object me=this_player();

	if( (string)me->query("family/family_name")!="��������" ){
		if( (string)me->query_temp("family/family_name")!="��������"){
		message_vision("$N���������˼���������һ�����ȣ�����һ����ˮ��\n", me);
  if (me->query("water")<me->max_water_capacity())         me->set("water", (int)me->max_water_capacity());
		return 1;
		}
	}

	if( (int)me->query_skill("dodge")  >= 50)
		return notify_fail("����Ṧ�Ѿ��ܸ��ˣ�����Ҳ�ﲻ�˶����ˡ�\n");

        if( (int)me->query_skill("dodge",1)  >= 150)
                return
notify_fail("����Ṧ�Ѿ��ܸ��ˣ�����Ҳ�ﲻ�˶����ˡ�\n");


	if( (int)me->query("kee") < 30 )
		return notify_fail("�����ں��ۣ�ЪЪ�ɣ�\n");
	if( (int)me->query("sen") < 50 )
		return notify_fail("��ľ��񲻼ã�ЪЪ�ɣ�\n");

	message_vision("$N�ڰ��ư�����������������������ƮƮ�ġ�\n", me);
	tell_object(me, "��ġ������Ṧ�������ˡ�\n");
	me->improve_skill("dodge", (int)me->query_int()/5);
	me->receive_damage("kee", 20+random(5));
	
	return 1;
}
