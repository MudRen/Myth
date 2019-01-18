// demongorgon.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name( HIW "�����" NOR, ({ "sun wukong" }) );
	set("long",
		"һ��������ߣ����ݸɸɣ������ë�������\n");
//		"����ɱ����ѹ���㼸����������������������ƺ���һ�������ڸ�\n"
//		"���㣺�� �� �� ������\n");

	set("age", 30);
	set("pursuer", 1);

	set("max_gin", 5000);
	set("max_kee", 5000);
	set("max_sen", 5000);

	set("max_atman", 9999);
	set("atman", 9999);
	set("max_force", 5000);
	set("force", 5000);
	set("max_mana", 5000);
	set("mana", 5000);

	set("str", 100);
	set("cor", 100);
	set("cps", 100);
	set("spi", 100);
	set("int", 100);
	set("con", 100);
	set("kar", 100);
	set("per", 100);

	set("combat_exp", 5000000);
	set("daoxing", 5000000);

	set_skill("stick", 500);
	set_skill("unarmed", 500);
	set_skill("parry", 500);
	set_skill("dodge", 500);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);

	setup();

	carry_object("/d/obj/weapon/stick/jingubang")->wield();
}

void start_shutdown()
{
	if( geteuid(previous_object()) != ROOT_UID ) return;

	message("system",
		HIR "\n���������˹ֽ��˼�������\n\n"
		HIW	"�����" HIR "�ȵ�������϶����������ˣ�\n\n"
			"\t\t�����밳����װ�ϰ��ʱ���������ɹ���\n\n"
//			"\t\t������ʮ������ڰ��ҵ�ͷ­������ ��\n\n"
			"\t\t�����������ϣ�������������𵶱���\n\n" NOR,
		users() );
	call_out("countdown", 60, 10);
}

private void countdown(int min)
{
	min--;
	if( min ) {
		message("system",
			HIW "\n�����" HIR "����������������ȵ���\n\n"
				"\t\t���ǻ���" + chinese_number(min) + "���ӵ�ʱ�䣡\n\n"
				"\t\t��ʱĪ�ְ����﷭�����飬�����¶ˣ�\n\n" NOR,
			users() );
		call_out("countdown", 60, min);
	} else {
		message("system",
			HIW "\n�����" HIR "����������������ȵ���\n\n"
				"\t\t�ɺޣ��������ǿɺޣ�����\n\n"
				"\t\t���찡�� ��ذ���  ���󰡡�  ��������\n\n" NOR,
			users() );
		call_out("do_shutdown", 3);
	}
}

private void do_shutdown()
{
    object *user, link_ob;
    int i;

	message("system",
		HIW "\n\n�����" HIR "�����ȵ���װ�죡����\n\n"
			"\t\t���е�һ�ж���˲������ڰ�������\n\n"
			"\t\tȻ�������ǰ��һƬ�ڰ���������ֹ���ĺڰ�������\n\n" NOR,
		users() );
	
	user = users();
	for(i=0; i<sizeof(user); i++) {
	   if( !environment(user[i]) ) continue;
	   user[i]->save();
	   link_ob = user[i]->query_temp("link_ob");
	   if( objectp(link_ob) ) link_ob->save();
	}

	shutdown(0);
}

void die()
{
	object ob;

	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);

	if( !ob ) return;

	message("system",
		HIR "\n\n������һ�����ŷߺޡ����֡���Ұ�ް���������쳹������ա�\n\n"
		HIW "�����" HIR "˻�Ƶغ��ţ��ɶ��" + ob->name(1) + "����һ���ᱨ��ġ�����\n\n"
			"Ȼ��һ����ɫ�����Х�ų����ƶˣ�����ָֻ���������\n\n" NOR,
		users() );
	destruct(this_object());
}
