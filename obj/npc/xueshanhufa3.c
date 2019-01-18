//xueshanhufa3.c
//created by vikee
//2000.10

#include <ansi.h>
inherit NPC;
#include <soldier_skill.h>
void create()
{
	set_name("���",({ "feng huang", "hufa" }) );
	set("long", "һֻ�õ�����ķ�ˣ���˵�Ǵ����������µĵ����ɽ���\n");
	set("attitude", "friendly");
	set("max_gin", 1500);
	set("max_kee", 1500);
	set("max_sen", 1500);
	set("max_force", 1500);
	set("force_factor", 30);
	set("max_mana", 1500);
	set("mana", 1500);
	set("mana_factor", 30);
	set("str", 30);
	set("cor", 30);
	set("cps", 25);
	set("combat_exp", 1000000);
	set("daoxing", 1000000);
	set_skill("dodge", 160);
	set_skill("parry", 160);
	set_skill("unarmed", 160);
	setup();
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
		HIG + "������ĵش��˸���Ƿ�����ĵس����ܿ��˿������ĵط����ˡ�\n\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}
void invocation(object who)
{
	int i;
	object *enemy;
	message("vision",
		HIG "ͻȻ�����ܰ���������һֻ��˰�Ȼվ���������ǰ��\n\n" NOR,environment(), this_object() );
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
  give_skill(who,"dengxian-dafa","sword");
}
