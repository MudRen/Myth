// mind_beast.c

inherit NPC;

void create()
{
	set_name("������", ({ "mind beast", "beast" }) );
	set("race", "Ұ��");
	set("age", 3);
	set("long", "����һֻ���޵��˵������˼�����Ĺ����ޣ����ס�˵Ļ��ǡ�\n");
	
	set("str", 48);
	set("cor", 52);
	set("cps", 22);

	set("max_kee", 600);
	set("max_gin", 600);
	set("max_sen", 900);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	if( this_player() ) {
		set("combat_exp", this_player()->query_skill("spells", 1) * 2000);
		set("bellicosity", this_player()->query("bellicosity") );
	}
	
	set_temp("apply/attack", 60);
	set_temp("apply/armor", 40);

	setup();
}

void die()
{
	string owner;
	object owner_ob;

	owner = query("owner");

	if( objectp(owner_ob = find_player(owner)) ) {
		if( (object)query_temp("last_damage_from") != owner_ob ) {
			tell_object(owner_ob, "��Ĺ����ޱ���ɱ���ˣ�\n�����һ��������ת....\n");
			owner_ob->unconcious();
		} else {
			tell_object(owner_ob, "��ɱ������Ĺ����ޣ����Ҵ�������һЩ�����ĵ���\n");
			owner_ob->improve_skill("spells", random(owner_ob->query("spi"))+1);
		}
	}
	::die();
}
