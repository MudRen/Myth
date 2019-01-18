// lgshou.c �����

#include <ansi.h>
inherit NPC;

int do_kill(string);

void create()
{
	set_name("�����", ({ "luogu shou", "shou" }));
	set("long", "�����ǻ����������ֵĴ����֡�\n"
		"����ǰ����һ����ģ�˫�ָ���һ����鳣��𾢵��ô��š�\n");
	set("gender", "����");
	set("age", 30);
	set("attitude", "peaceful");
	set("str", 50);
	set("int", 10);
	set("max_kee", 500);
	set("combat_exp", 10000);
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	setup();
}

void init()
{
	add_action("do_kill", "kill");
	add_action("do_kill", "fight");
}

int do_kill(string arg)
{
	if ((arg=="shou" || arg=="luogu shou")
		&& environment()!=find_object("/d/moon/yltw")) {
		message_vision(HIR 
"��ͻȻ��������һ���޴�������������$N��ͼ�ƻ��������˺��£��������ݣ�ȥ���ɣ���\n"
"����δ�䣬���ߡ���¡¡��һ��������һ������ֱ����������$N��ͷ����$N��ʱ�����˻ҽ���\n" NOR, this_player());
		this_player()->die();
		return 1; }
	return 0;
}
