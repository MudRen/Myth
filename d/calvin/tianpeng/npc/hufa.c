// heaven_soldier.c

#include <ansi.h>

inherit NPC;

#include <soldier_skill.h>
void create()
{
    	object ob1, ob2;
	
        string *order = ({"青毛", "紫毛", "红毛", "白毛", "黄毛", "棕毛", "黑毛", "绿毛", "蓝毛"});

        set_name("神猪" + (order[random(10)]) + "护法", ({ "shenzhu hufa", "hufa" }) );
        set("long", "这是一位来自天蓬府的神兵，专门担任护法之责。\n");
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
		name() + "喝道：孽障！竟敢对？\n"
	}) );
*/
        set_skill("sword", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);

	setup();

	ob1=carry_object("/d/obj/armor/tianjia");
	ob1->wear();
	ob1->set("no_sell", "掌柜的瞟了一眼道：这东西一看就是劣等品，不要！不要！\n");
        ob2=carry_object("/d/obj/weapon/rake/gangpa");
	ob2->wield();
	ob2->set("no_sell", "掌柜的瞟了一眼道：这东西一看就是劣等品，不要！不要！\n");
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
		HIY + name() + "说道：末将奉法主召唤，现在已经完成护法任务，就此告辞！\n\n"
                + name() + "卷起一道狂风,刹那间不知去向了。\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

void invocation(object who)
{
	int i;
	object *enemy;

	message("vision",
                HIY "一阵狂风卷来，风中走出一个身穿金色战袍的猪样神兵。\n\n"
		+ name() + "说道：末将奉法主召唤，特来护法！\n" NOR,
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
  give_skill(who,"tianhedafa","rake");
}