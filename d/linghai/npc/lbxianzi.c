
//lbxianzi.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
       set_name(HIC"�貨����"NOR,({"lingbo xianzi","lingbo", "xianzi","master"}));
       set("long", "�����Ǿ����躣�񹬵Ĵ�ʼ�ˡ�
��Ϊ������ӣ����µ�������ڵ��ӡ��躣�񹬵�
����Ҳ�ڽ�������\n");
       set("title", HIB"ӯӯ΢�����»�"NOR);
       set("gender", "Ů��");
       set("age", 30);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/self", "ʥ��");
       set("cor", 30);
       set("per", 40);
       set("max_kee", 4500);
       set("max_gin", 800);
       set("max_sen", 4500);
       set("force", 5000);
       set("max_force", 3000);
       set("force_factor", 125);
       set("max_mana", 2500);
       set("mana", 5000);
       set("mana_factor", 250);
       set("combat_exp", 3000000);
           set("daoxing", 4000000);
       set_skill("literate", 300);
       set_skill("unarmed", 350);
       set_skill("dodge", 350);
       set_skill("force", 400);
       set_skill("parry", 350);
       set_skill("sword", 400);
       set_skill("spells", 350);
       set_skill("blade", 350);
   set_skill("linghai-force", 400);
   set_skill("lingbo-steps", 350);
   set_skill("huanyue-jianfa", 400);
   set_skill("kongwujian", 350);
   set_skill("fenxin-blade", 350);
   set_skill("fenxin-spells", 350);
   map_skill("spells", "fenxin-spells");
   map_skill("force", "linghai-force");
   map_skill("sword", "huanyue-jianfa");
   map_skill("parry", "huanyue-jianfa");
   map_skill("dodge", "lingbo-steps");
   set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "fengyue" :),
                 (: perform_action, "lianyue" :),
                 (: exert_function, "xuehai" :)
        }) );

create_family("�躣��", 1, "��");
setup();

        carry_object("/d/obj/cloth/tianyi.c")->wear();
        carry_object("/d/linghai/obj/lingbojian")->wield();
        carry_object("/d/ourhome/obj/shoes")->wear();
}

void attempt_apprentice(object ob)
{

   if ( (string)ob->query("family/family_name")=="�躣��") {
   if( (((int)ob->query("combat_exp") < 1000000 ))|| 
        ((int)ob->query_skill("huanyue-jianfa",1) < 200) || 
        ((int)ob->query_skill("linghai-force",1) < 200) || 
        ((int)ob->query("per") < 20) ){
   command("shake" +ob->query("id"));
   command("say " + RANK_D->query_respect(ob) +
"����Ϊ����������ʹ�������ˣ�Ҳ���ѳɲġ�\n");
   return;
   }
        command("nod "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"��ϧʱ�⣬���躣���������£�\n");
       command("recruit " + ob->query("id") );
           ob->set("title", HIC"�躣ʥ��"NOR);
           ob->set("class", "xian");
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"������ȥѧЩ��������ɡ�\n");
        return;
}
int accept_fight(object me)
{
   command("say ��!��ʥ�����ɺ����ȭ�����֣�\n");
   return 0;
}






