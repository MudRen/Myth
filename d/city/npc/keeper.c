inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("��ף", ({ "miao zhu", "zhu","keeper" }) );
        set("gender", "����" );
        set("age", 74);
        set("long",

"������˿�������ʮ�����ˣ��꼶�Ǵ��ˣ�������ȴ�ܺá�\n");
        set("combat_exp", 1);
        set("attitude", "friendly");
        setup();
	carry_object("/d/obj/cloth/linen")->wear();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || !present(ob, environment(this_object())) ) return;
        say( "��ף˵������λ" + RANK_D->query_respect(ob)
                + "��������Ǯ�������£���Щ��Ե�ɡ�\n");
}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("��ף������Ʒ�ľ��ס�\n");
        else if( val > 100 ) {
		who->add("donation", val);
                if( (who->query("bellicosity") > 0)
                &&      (random(val/10) > (int)who->query("kar")) )
                        who->add("bellicosity", -
(random((int)who->query("kar")) + val/100) );
                if(who->query("bellicosity")<0)
                   who->set("bellicosity",0);
        }
        say( "��ף˵������л��λ" + RANK_D->query_respect(who)
                + "������һ���ᱣ����ġ�\n");

        return 1;
}

