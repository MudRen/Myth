//puti.c
inherit NPC;

void create()
{
       set_name("ţͷ��", ({"niutou gui", "gui", "niutou"}));
       set("gender", "����");
       set("age", 30);
	set("long", "һ��ţͷ��������һҰţģ����\n");
       set("attitude", "heroism");
       set("shen_type", 1);
       set("per", 10);
	set("str",20);
       set("combat_exp", 90000+random(10000));
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("whip", 80);
	set_skill("parry", 80);
	set("force", 300);
	set("max_force", 300);
	set("force_factor", 15);
	set("mana", 300);
	set("max_mana", 300);
	set("mana_factor", 15);
	set("max_kee", 800);
	set("max_sen", 800);
set("inquiry", ([
"name": "���Ӿ���ɱ�����������к����׵�ţͷ��\n",
"here": "��������ܵظ����ߣ����Ű�Ƥ�����㣡\n",
]) );


setup();

        carry_object("/d/obj/armor/shoupi")->wear();
        carry_object("/d/obj/weapon/whip/tielian")->wield();
}

