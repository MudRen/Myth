// dipi.c

inherit NPC;

void create()
{
        set_name("СƦ��", ({"xiao pizi", "pizi", "punk"}) );
        set("gender", "����" );
        set("age", 15+random(10));
        set("long", "����һ�����������ֺ��е�СƦ�ӡ�\n");

	set("combat_exp", 1500+random(300));
	set("str", 15);
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("attitude","heroism");
        setup();
	carry_object("/d/obj/cloth/linen")->wear();
}

