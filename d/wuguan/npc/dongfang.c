//Cracked by Roath
inherit NPC;
string teach_me(object me);
void create()
{

        set_name("��������", ({ "dongfang boyu", "dongfang", "boyu"}) );
        set("gender", "����" );
	set("per", 23);
        set("age", 42);
        set("long", "���������Ƕ�����ݵĹ��������Ϻ������¹���
���������Ī����������ͽ��Ϊ�١�\n");
        set("combat_exp", 80000);
	set("title", "��ݹ���");
	set("max_kee", 500);
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 10);
	set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("unarmed", 70);
	set_skill("force", 70);
set("inquiry", ([
"name": "�Ϸ򶫷�����������ĵ��ҡ�\n",
"here": "����ǰ�����������������ˣ���ѧ�յ��˺ܶ��ء�\n",
"ѧ��": (: teach_me :),
]) );

        setup();
        add_money("silver", 1+random(20));
        carry_object("/d/obj/cloth/choupao")->wear();
}

string teach_me(object me)
{
	if((int)this_player()->query("combat_exp") < 10000 ) {
	message_vision("���������$N����һЦ��˵��������һ�������Ҿ�֪����Ҫѧ�ա�\n", this_player());
	this_player()->set("newbie/learn", 1);
	return "�Ժ�͸��Ҷ���Ů��ѧ�ɡ�\n";
	}
	command("look " + this_player()->query("id"));
	return "��̫���ˣ����������ʦȥ�ɣ�\n";
}
