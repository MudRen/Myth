//Cracked by Roath
inherit NPC;

void create()
{

        set_name("������", ({ "dongfang cong", "dongfang", "cong"}) );
        set("gender", "����" );
        set("age", 22);
        set("long", "�������ǹ����Ĵ���ӣ�����һЩͽ�����ա�\n");
        set("combat_exp", 20000);
	set("title", "��ݽ�ͷ");
	set_skill("stick", 50);
	set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
	set_skill("force", 40);
        setup();
        add_money("silver", 1+random(20));
        carry_object("/d/obj/cloth/choupao")->wear();
}

int recognize_apprentice()
{
	if(!this_player()->query("newbie/learn") )
	return notify_fail("������Ц�����̲����㣬��ȥ�ʵ���\n");

	return 1;
}
