// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
	HIB "���޳�˵����ι�������ģ����ʲ�����֣�\n\n" NOR,
	HIB "���޳���������۹ⶢ���㣬����Ҫ�������һ���Ƶġ�\n\n" NOR,
	HIB "���޳����ߡ���һ�����������ͳ�һ�����ʲ�Ķ�����������\n\n" NOR,
	HIB "���޳����ϲ��ӣ�˵�����ף�����δ����������ܣ�\n\n" NOR,
	HIB "���޳�ɦ��ɦͷ��̾�������˰��ˣ����߰ɡ�\n\n"
		"һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n" NOR,
});

void create()
{
	set_name("���޳�", ({ "black gargoyle", "gargoyle" }) );
	set("long",
		"���޳�������������ͷ�����㣬��ڵ����Ͽ������κ�ϲŭ���֡�\n");
	set("attitude", "peaceful");
	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :),
		"���޳�����һ����������������������������ע��������ʱ�򣬵�����һ�ۡ�\n",
		"���޳��ѳ�������ͷ��������������������Լ��ֺ��ֳ�����ָ��\n"
	}) );
	set("age", 217);
	set("combat_exp", 20000);
  set("daoxing", 50000);

	set("max_gin", 900);
	set("max_kee", 900);
	set("max_sen", 200);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_temp("apply/armor", 60);
	set_temp("apply/damage", 20);
	setup();
}

void init()
{
	::init();
	if( !previous_object()
	||	!userp(previous_object()) )
		return;
	call_out( "death_stage", 5, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
	if( !ob || !present(ob) ) return;

	if( !ob->is_ghost() ) {
		command("say ι��������������ʲ�᣿");
		kill_ob(ob);
		ob->fight_ob(this_object());
		return;
	}

	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 5, ob, stage );
		return;
	} else
		ob->reincarnate();

	ob->move(REVIVE_ROOM);
	message("vision",
		"���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"
		"�ܾ��ˣ�ֻ����һֱû������\n", environment(ob), ob);
}


�