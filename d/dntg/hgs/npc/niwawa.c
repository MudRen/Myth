
inherit NPC;
inherit F_VENDOR;
void create()
{
       set_name("������", ({"mud baby", "baby"}));
       set("long", "һ�����߶�ߵ�С���ޣ�ȫ������������̥һ�㡣\n");
       set("gender", "����");
        set("combat_exp", 100);
	set("per", 20);
       set("age", 6);
       set("attitude", "peaceful");
	set("max_kee", 400);
	set("max_sen", 400);
       set("shen_type", 1);
       set_skill("unarmed", 5);
	set_skill("dodge", 15);

        setup();
       add_money("silver", 1);
        carry_object("/d/obj/cloth/linen")->wear();
}
int accept_fight(object me)
{	me=this_player();
	if((int)this_player()->query("combat_exp") < 15000) {
	this_object()->set("combat_exp", (int)this_player()->query("combat_exp")+300);
	}
	command("say �����ð���\n");
        return 1;
}

void die()
{
        if( environment() ) {
                message("sound", "\n\n������һ���죬���������������ˣ�\n
��ǰ����һ���������Ѳ����ˣ�����ֻ����һ����ˮ��\n", environment());
        }

        destruct(this_object());
}

