// kid.c
inherit NPC;
void create()
{
        set_name("С����", ({ "kid", "wawa"}));
        if(random(10)<7)
	set("gender", "����" );
        else
	set("gender", "Ů��" );
        set("age", 3+random(5));
        set("long", "һ���ɰ���С���ޡ����ﶼȥ�ɻ��ˣ��Լ���Ϫ��׽�㡣\n");
        set("combat_exp", 10);
        set("attitude", "friendly");
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin", 15+random(35));
}