// hell_guard.c

#include <ansi.h>

inherit NPC;

void create()
{
	object ob1, ob2;
	
	string *order = ({"��", "��", "��", "î", "��", "��", "��", "δ", "��", "��", "��", "��"});

	set_name( (order[random(12)]) + "������", ({ "hell guard", "guard" }) );
	set("long", "����һλ����������ػ���ר�ŵ��λ���֮��\n");
	set("attitude", "heroism");

	set("max_gin", 1000);
	set("max_kee", 1000);
	set("max_sen", 1000);

	set("max_force", 100);
	set("force", 100);
	set("max_mana", 100);
	set("mana", 100);

	set("str", 40);
	set("per", 10);

	set("combat_exp", 100000);
	set("daoxing", 100000);

	set("chat_chance", 15);
	set("chat_msg_combat", ({
		name() + "�ȵ������ϣ����Ҹ���˾����ɡ�\n"
	}) );

	set_skill("fork", 90);
	set_skill("parry", 70);
	set_skill("dodge", 50);

	setup();

	ob1=carry_object(__DIR__"obj/steel_armor");
	ob1->wear();
	ob1->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n");
	ob2=carry_object(__DIR__"obj/steel_fork");
	ob2->wield();
	ob2->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n");
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",
		HIB + name() + "˵����ĩ������ٻ��������Ѿ���ɻ������񣬾ʹ˸�ǣ�\n"
		+ name() + "�����η����İ������⣬������²����ˡ�\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

void invocation(object who)
{
	int i;
	object *enemy;

	message("vision",
		HIB "һ������ӵص����������г���һ����ִ�ֲ桢��Ŀ�����Ĺ��䡣\n"
		+ name() + "˵����ĩ������ٻ�������������\n" NOR,
		environment(), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	set_leader(who);
}
