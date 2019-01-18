 
inherit NPC;
int give_horse();
void create()
{
	set_name("��ة", ({"jian cheng"})); 
        set("gender", "����" );
	set("long", "������ة��\n");
        set("age",40);
        set("str", 30);
	set("title", "�����");
        set("int", 20);
	set("con", 30);
	set("spi", 20);
        set("per", 15);
	set("class", "xian");
	set("attitude", "friendly");
        set("combat_exp", 8500);
	set("max_kee", 1000);
	set("max_sen", 1000);
        set("inquiry", ([
                "horse": (: give_horse :),
		"����":(: give_horse :),
        ]) );

        setup();
        carry_object("/d/obj/cloth/xianpao")->wear();
}
 
int give_horse()
{
	object me, who, horse;
	me=this_object();
	who=this_player();
	if( member_array("zengzhang tianwang", who->parse_command_id_list())==-1
		&& member_array("huguo tianwang", who->parse_command_id_list())==-1) {
		message_vision("$N���ɻ�Ŀ���$n˵���Ҳ���ʶ�㣡\n", me,who);
		return 1;
	}
	if( me->query("no_horse")){
		message_vision("$N��ͷ�����Ķ�$n˵��������С��ʵ���ǳ鲻��һƥ����\n", me, who);
		return 1;
	}
	message_vision("$N��ͷ������˵����˵����˵��\n", me);
	seteuid(getuid());
	horse=new("/d/sky/npc/horse");
	horse->move(environment(me));
	tell_room(environment(me), "�Աߵĵ䲾����Ȧ��ǣ��ƥ��������\n");
	me->set("no_horse", 1);
	call_out("reg", 3600);
	return 1;
}
int reg()
{
	delete("no_horse");
	return 1;
}
