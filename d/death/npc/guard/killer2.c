// hell_guard.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("ۺ����ʹ", ({"hell guard", "guard"}));
	set("long", "����һλ����������ػ���ר�ŵ��λ���֮��\n");
	set("attitude", "friendly");
	set("class", "youling");
	set("max_gin", 600);
	set("max_kee", 600);
	set("max_sen", 600);
	set("age", 50);

	set("max_force", 400);
	set("force", 400);
	set("force_factor", 20);
	set("max_mana", 400);
	set("mana", 400);
	set("mana_factor", 20);

	set("str", 30);
	set("cor", 30);
	set("cps", 30);

	
	set("combat_exp", 100000);
        set_temp("apply/damage", 15);
        set_temp("apply/armor", 15);

	set("chat_chance", 15);
	set("chat_msg_combat", ({
		name() + "�ȵ������ϣ����Ҹ���˾����ɡ�\n"
	}) );

	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("unarmed", 70);
	set_skill("force", 70);
	set_skill("tonsillit", 70);
	set_skill("ghost-steps", 70);
	set_skill("jinghun-zhang", 70);

	map_skill("dodge", "ghost-steps");
        map_skill("unarmed", "jinghun-zhang");
        map_skill("force", "tonsillit");

	setup();

	carry_object("/d/obj/armor/shoupi")->wear();
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

