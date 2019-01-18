// monkey1.c

inherit NPC;

void create()
{
	set_name("С����", ({ "xiao houzi","xiaohouzi","monkey","hou" }) );
	set("race", "Ұ��");
	set("age", 6);
	set("long", "һֻ��Ƥ��С���ӡ�\n");
	
	set("str", 30);
	set("cor", 26);	
	set("combat_exp", 50);
  set("daoxing", 0);

            set_skill("dodge",20);
            set_skill("unarmed",10);
	set("limbs", ({ "ͷ��", "����", "ǰצ", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 6);
	set("chat_msg", ({
		(: call_other, this_object(), "random_move" :),
		"С���Ӷ������˸�������\n",
		"ž��һ����С��������һ��Ұ��������������ı��ӡ�\n",
		"С���Ӷ���֨֨֨�ؽ��˼�����\n",
		"С����ץ�������أ�Χ����������ȥ��\n" }) );
		
//	set_temp("apply/attack", 20);
//	set_temp("apply/defense", 50);
//	set_temp("apply/armor", 3);

	setup();
}

int accept_object(object who, object ob)
{
	if( ob->id("mihou tao")||ob->id("huasheng")||ob->id("jiudai")) {
		set_leader(who);
		who->set("pending/haha", 5);
		message("vision", name() + "���˵�ץ��������ֱ����ͷ��\n", environment());
		return 1;
	}
}
void init()
{
        add_action("do_let", "let");
}

int do_let(string arg)
{
        if( !this_player()->query("pending/haha") ) 
        return notify_fail("С���ӿ�����������������Ը���㣡\n");
	
	if(!arg )
	return notify_fail("С���Ӻ��󲻶���˵ʲô��\n");

	message_vision("$N��$n���˸����ơ�\n", this_player(), this_object());
	command("bite");
	command("bite none");
	this_player()->add("pending/haha", -1);
	return 1;
}
�