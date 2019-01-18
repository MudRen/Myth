inherit NPC;

void create()
{
        set_name("��ɽ", ({ "yin kaishan", "yin", "kaishan" }));
        set("title", "���ܹ�");
        set("gender", "����");
        set("age", 70);
        set("str", 20);
        set("dex", 20);
        set("long", "�����ǵ������ܹ���ɽ������Ͷ��֮�䣬��ŭ������\n");
        set("combat_exp", 80000);
  set("daoxing", 90000);

        set("attitude", "friendly");
	set("force_factor", 10);
        set_skill("unarmed", 80);
        set_skill("dodge",80);
        set_skill("parry", 80);
	set("max_kee", 700);
	set("max_sen", 700);
        set("force", 500); 
        set("max_force", 500);

        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        add_money("silver", 20);

}

int accept_object(object who,object ob)
{
	int val;
	val = ob->value();
	if( !val )
                return notify_fail("��ɽЦ�������ǲ����յģ����û�ȥ�ɣ�\n");
	if (val < 5000) {
	write("��ɽЦ�������Ӽ�ÿ�²�������ʮ��������\n");
	return 0;
	}
        who->set("guozi/paid", 1);
        call_out("destroy", 1, ob);
        return 1;
}

void destroy(object ob)
{
        destruct(ob);
        return;
}

�