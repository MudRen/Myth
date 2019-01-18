//Creat by waiwai@2000/07/20

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��ؤ", ({ "qi-gai" }) );
	set("long", "����һ����ͨ����ؤ�������ƺ���������\n");
	set("attitude", "friendly");

	set("str", 40+random(60));
	set("cor", 30);
	set("cps", 25);

	set("combat_exp", 5000000+random(9000000));

	set("chat_chance", 30);
	set("chat_msg_combat", ({
		"��ؤ�ȵ�����������Ұ����ò��ͷ��ˣ�\n",
		(: command("crazy") :),
	}) );
	set_skill("unarmed", 500+random(1000));
	set_skill("dodge", 500+ random(1000));
	set_skill("parry", 500+ random(1000));

	setup();

	carry_object("/d/tianpeng/hu/obj/jncloth")->wear();
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
		HIW + name() + "�ݺ�����������һ�ڵ����´�û��ô���ˣ�\n\n"
		+ name() + "�޺޵ض��˶�ţ�һ�������ˡ�\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}
