// modified by vikee

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("������", ({ "lin yueru", "lin", "yueru" }));
        set("title","��ɽ����ʥ�õ���");
        set("long", 
"������Ů��ǧ�𣬱������׶����ġ�\n");
        set("gender", "Ů��");
        set("age", 16);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("per", 30);
        set("kee", 2200);
        set("max_kee", 2200);
        set("sen", 1600);
        set("max_sen", 1600);
        set("force", 3000);
        set("max_force", 3000);
        set("mana", 3000);
        set("max_mana", 3000);
        set("force_factor", 60);
        set("mana_factor", 60);

        set("combat_exp", 1800000);
        set("daoxing", 2500000);

        set_skill("force", 150);
        set_skill("dodge", 160);
        set_skill("parry", 140);
        set_skill("whip", 180);
        set_skill("unarmed",120);
set_skill("fumozhang",120);
set_skill("sevensteps",160);
set_skill("zixia-shengong",140);
set_skill("yirubian",200);
        set_skill("literate", 80);
        set_skill("taoism",120);
        map_skill("spells", "taoism");
map_skill("force", "zixia-shengong");
map_skill("unarmed", "fumozhang");
map_skill("dodge", "sevensteps");
map_skill("parry", "snowwhip");
map_skill("whip", "snowwhip");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
(: perform_action, "whip","snake" :),
                (: exert_function, "powerup" :),
        }) );
        setup();
        create_family("��ɽ����", 5, "δ���ŵ���");
       carry_object("/obj/cloth")->wear();
carry_object("/d/obj/weapon/whip/snakewhip")->wield();
}
void attempt_apprentice(object me)
{
me =this_player();
/* if ( !((string)me->query("gender")=="Ů��"))
		{
        command("shake");
        command("say ��ֻ��Ůͽ����λ" +
 RANK_D->query_respect(me) + "��������߾Ͱɡ�\n");
           return ;
} */
if (me->query("nyj/shushan") != "done")
{
command("say �����ڻ��ڵ�����������ӡ���");
return;
}
command("pat "+me->query("id"));
command("say ��Ȼ" + RANK_D->query_respect(me) +"������ɽ������ֻ������Ϊͽ��\n");
command("recruit " + me->query("id") );
        return ;
}



