// keeper.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("���ޱ�", ({ "a luoben", "monk", "luoben" }) );
        set("gender", "����" );
        set("age", 54);
	set("str", 25);
	set("per", 25);
	set("title", "��˹ɮ��");
	set("long",
	"����һλ��������ľ���ɮ�ˣ�ӥ����Ŀ���뷢�԰ס�\n"
	"����������ѧ�ʣ������������Ŀ��˼��\n");
        set("combat_exp", 100000);
  set("daoxing", 200000);

        set("attitude", "peaceful");

	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("unarmed", 80);
        set_skill("literate", 80);

	set("max_kee", 800);
        set("max_gin", 300);
	set("max_sen", 400);
	set("max_force", 300);
	set("force", 300);
	set("force_factor", 10);
	set("max_mana", 200);
	set("mana", 200);
	set("mana_factor", 10);

	set("inquiry", ([
		"here": "���ƾ�����\n",
		"name": "���ޱ�\n",
	]) );

        setup();

        carry_object("/d/obj/cloth/sengpao")->wear();
        carry_object("/d/obj/cloth/sengxie")->wear();

}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || !present(ob, environment(this_object())) ) return;
        say( "���ޱ�˵������λ" + RANK_D->query_respect(ob)
		+ "��������������츸���ɡ�\n");
}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("���ޱ�������Ʒ�ľ��ס�\n");
	else if( val > 100 )
	{
                if( (who->query("bellicosity") > 0)
                &&      (random(val/10) > (int)who->query("kar")) )
                        who->add("bellicosity", - (random((int)who->query("kar")) + val/1000) );
                if(who->query("bellicosity")<0)
		   who->set("bellicosity",0);
        }
        say( "���ޱ�˵������л��λ" + RANK_D->query_respect(who)
                + "���츸һ���ᱣ����ġ�\n");

        return 1;
}

�
