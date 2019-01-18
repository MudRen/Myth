// jingang.c

#include <ansi.h>

inherit NPC;

void create()
{
	object ob1, ob2;
	
	string *order = ({"�÷�", "ʤ��", "����", "��ס"});

	set_name((order[random(4)]) + "���", ({ "jingang"}) );
	set("long", "����һλ������ɽ���ػ���ר�ŵ��λ���֮��\n");
	set("attitude", "friendly");

	set("max_gin", 500);
	set("max_kee", 1000);
	set("max_sen", 500);

        set("max_mana", 1000);
	set("mana", 500);

	set("str", 40);
	set("cor", 30);
	set("cps", 25);

        set("combat_exp", 500000);
        set_skill("staff", 200);
	set_skill("parry", 100);
        set_skill("dodge", 200);

	setup();

	ob1=carry_object("/d/city/obj/jiasha");
	ob1->wear();
	ob1->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n");
	ob2=carry_object("/d/obj/weapon/staff/budd_staff");
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
		RED + name() + "˵����ĩ������ٻ��������Ѿ���ɻ������񣬾ʹ˸�ǣ�\n\n"
		+ name() + "����һ����⣬���������ʧ�����ˡ�\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

void invocation(object who)
{
	int i;
	object *enemy;

	message("vision",
		RED "ֻ��ž����һ����һ�ź�ⱬ�����ֳ�һ���������ִ���ȵĽ�ա�\n\n"
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
