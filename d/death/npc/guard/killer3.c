// hell_guard.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("���޳�", ({"white gargoyle", "gargoyle"}));
	set("long", "����һλ����������ػ���ר�ŵ��λ���֮��\n");
	set("attitude", "friendly");
	set("class", "youling");
	set("title", "�л�ʹ��");
	set("max_gin", 1000);
	set("max_kee", 1000);
	set("max_sen", 1000);
	set("age", 50);

	set("max_force", 500);
	set("force", 500);
	set("force_factor", 40);
	set("max_mana", 500);
	set("mana", 500);
	set("mana_factor", 40);

	set("str", 30);
	set("cor", 30);
	set("cps", 30);

	
	set("combat_exp", 250000);

	set("chat_chance", 15);
	set("chat_msg_combat", ({
		name() + "�ȵ������ϣ����Ҹ���˾����ɡ�\n"
	}) );

	set_skill("stick", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("tonsillit", 80);
	set_skill("kusang-bang", 80);
	set_skill("ghost-steps", 80);
	set_skill("jinghun-zhang", 80);

	map_skill("stick", "kusang-bang");
        map_skill("parry", "kusang-bang");
        map_skill("dodge", "ghost-steps");
        map_skill("unarmed", "jinghun-zhang");
        map_skill("force", "tonsillit");

	setup();

	carry_object("/d/obj/cloth/bai")->wear();
	carry_object("/d/obj/weapon/stick/wuchangbang")->wield();
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
	message("vision", "\n" +
		HIB + name() + "˵����˭�������������ԣ��ǲ������ֿ����\n\n"
		+ name() + "�����η����İ������⣬������²����ˡ�\n\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}
void die()
{

        if( environment() ) {
        command("heng");
        message("sound", "\n���޳������³�һ�ɺ��̣�����ɢ���˾������ˡ�����\n\n", environment());
        }

        destruct(this_object());
}

