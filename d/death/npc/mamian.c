//puti.c
inherit NPC;

void create()
{
       set_name("�����", ({"mamian gui", "gui", "mamian"}));
       set("gender", "����");
       set("age", 30);
	set("long", "һ�������������һҰ��ģ����\n");
       set("attitude", "heroism");
       set("shen_type", 1);
       set("per", 10);
	set("str", 20);
       set("combat_exp", 90000+random(10000));
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("hammer", 80);
	set_skill("parry", 80);
	set("force", 300);
	set("max_force", 300);
	set("force_factor", 15);
	set("max_kee",800);
	set("max_sen",800);
	set("mana", 300);
	set("mana_factor", 15);
	set("max_mana", 300);

set("inquiry", ([
"name": "���Ӿ���ɱ��������������ָͷ�������\n",
"here": "��������ܵظ����ߣ����Ű�Ƥ�����㣡\n",
]) );

setup();

        carry_object("/d/obj/armor/shoupi")->wear();
//        carry_object("/d/lingtai/obj/shoe")->wear();
        carry_object("/d/obj/weapon/hammer/tongchui")->wield();
}

