// heaven_soldier.c

#include <ansi.h>

inherit NPC;

#include <soldier_skill.h>
void create()
{
    	object ob1, ob2;
	
	string *order = ({"��", "��", "��", "��", "��", "��", "��", "��", "��", "��"});

	set_name("��" + (order[random(10)]) + "���", ({ "heaven soldier", "soldier" }) );
	set("long", "����һλ���������ػ���ר�ŵ��λ���֮��\n");
	set("attitude", "friendly");

	set("max_gin", 1000);
	set("max_kee", 1000);
	set("max_sen", 1000);
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 5);
	set("max_mana", 200);
	set("mana", 200);
	set("mana_factor", 5);
	set("str", 30);
	set("cor", 30);
	set("cps", 25);

	set("combat_exp", 100000);
	set("daoxing", 100000);
/*
	set("chat_chance", 15);
	set("chat_msg_combat", ({
		name() + "�ȵ������ϣ����Ҷԣ�\n"
	}) );
*/
	set_skill("sword", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);

	setup();

	ob1=carry_object("/d/obj/armor/tianjia");
	ob1->wear();
	ob1->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n");
	ob2=carry_object(__DIR__"obj/golden_sword");
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
		HIY + name() + "˵����ĩ������ٻ��������Ѿ���ɻ������񣬾ʹ˸�ǣ�\n\n"
		+ name() + "����һ����⣬���������ʧ�����ˡ�\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

void invocation(object who)
{
	int i;
	object *enemy;

	message("vision",
		HIY "һ��������������������߳�һ������ɫս�۵Ľ��١�\n\n"
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
  give_skill(who,"moonshentong","sword");
}
