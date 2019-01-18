// һ������ "����ѩ�� ����" by Calvin

inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
        set_name(HIW"����"NOR, ({"ge xi", "gexi", "tianshen", "yi"}));
        set("title", HIW"����ѩ��"NOR);
        set("gender", "����" );
        set("age", 100);
        set("per", 30);
        set("str", 30);
        set("long", "�ഫ��λ������Ǵ����Ľ����ܡ�\n");
        set("class", "yaomo");
        set("combat_exp", 5000000);
        set("daoxing", 5000000);

        set("attitude", "peaceful");
        create_family("��ѩɽ", 1, "��ʦ");
        set("rank_info/respect", "ѩ��");

        set_skill("unarmed", 350);
        set_skill("cuixin-zhang", 350);
        set_skill("dodge", 350);
        set_skill("xiaoyaoyou", 350);
        set_skill("parry", 350);
        set_skill("sword", 350);
        set_skill("bainiao-jian", 350);
        set_skill("blade", 350);
        set_skill("bingpo-blade", 350);
        set_skill("throwing", 350);
        set_skill("force", 350);   
        set_skill("ningxie-force", 350);
        set_skill("literate", 200);
        set_skill("spells", 350);
        set_skill("dengxian-dafa", 350);
        map_skill("spells", "dengxian-dafa");
        map_skill("force", "ningxie-force");
        map_skill("unarmed", "cuixin-zhang");
        map_skill("sword", "bainiao-jian");
        map_skill("blade", "bingpo-blade");
        map_skill("dodge", "xiaoyaoyou");

        set("max_kee", 5000);
        set("max_sen", 5000);
     set("force", 5000);
        set("max_force", 2500);
        set("mana", 5000);
        set("max_mana", 2500);  
        set("force_factor", 100);
        set("mana_factor", 100);

        set_temp("apply/damage", 50);
        set_temp("spply/armor", 50);
        set_temp("apply/dodge", 50);
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
                (: cast_spell, "juanbi" :),
                (: cast_spell, "tuntian" :),
                (: perform_action, "sword", "chaofeng" :),

       }) );
            setup();
         carry_object("/d/9ct/zb/jing")->wear();
        carry_object("/d/9ct/zb/sword")->wield();
}

void attempt_apprentice(object ob)
{
        if( (string)ob->query("class")=="bonze" && (string)ob->query("gender")=="����"  )
        {
                command("kick " + ob->query("id"));
                command("say ���ߣ����ߣ���һ�������о�������\n");
                return;
        }

        if( (string)ob->query("family/family_name")=="��ѩɽ" ){
                if( (int)ob->query("family/generation") > 3   ){
                        command("say û���Ĵ󻤷����Ƽ����������ѿ��ǡ�\n");
                }
                else {
                        if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 2000000 ){
                                command("nod ");
                                command("say �ã�" + RANK_D->query_respect(ob) + "����������ǰ���ĳ���,�úøɰɣ�\n");
                                command("recruit " + ob->query("id") );
                        }
                        else {
                                command("say �㻹��ȥѩɽ���Ҵ�������������Űɡ�\n");
                        }
                }
        }
       else{
                command("hmm");
                command("say ��λ" + RANK_D->query_respect(ob) + "���ڱ��ſ�û��һ��������¡�\n");
        }

        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "yaomo");
                ob->set("title", HIW"��ѩɽ����ѩ��"NOR);
}

void init()
{       
        object ob=this_player();

        ::init();
        if ( ((string)ob->query("gender")=="����") && ((string)ob->query("class")=="bonze") && (random(3) > 1) )
        {
                remove_call_out("greeting");
call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        
        switch( random(1) ) {
                case 0:
                        command("kick " + ob->query("id"));
                        command("say ����ͺ��");
                        break;
        }
}
