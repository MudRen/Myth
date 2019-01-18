// mind_bug.c

inherit NPC;

void create()
{
	set_name("�����", ({ "mind bug", "bug" }) );
	set("race", "Ұ��");
	set("age", 3);
	set("long", "����һֻ���޵��˵������˼�����Ĺ���������ס�˵Ļ��ǡ�\n");
	
	set("str", 24);
	set("cor", 26);

	set("max_kee", 140);
	set("max_gin", 250);
	set("max_sen", 600);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );
	
	if( this_player() ) {
		set("combat_exp", (int)this_player()->query_skill("spells", 1) * 500);
		set("bellicosity", this_player()->query("bellicosity"));
	}

	set_temp("apply/attack", 30);
	set_temp("apply/armor", 10);

	setup();
}

void die()
{
	string owner;
	object owner_ob;

	owner = query("owner");

	if( objectp(owner_ob = find_player(owner)) ) {
		if( (object)query_temp("last_damage_from") != owner_ob ) {
			tell_object(owner_ob, "��Ĺ��������ɱ���ˣ�\n�����һ��������ת....\n");
			owner_ob->unconcious();
		} else {
			tell_object(owner_ob, "��ɱ������Ĺ���������Ҵ�������һЩ�����ĵ���\n");
			owner_ob->improve_skill("spells", random((int)owner_ob->query("spi")/2)+1);
		}
	}
	::die();
}
