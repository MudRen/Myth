//��ɽ��.c BY cigar 2002.01
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIC"��ɽ��"NOR, ({"liang shanbo", "liang", "shanbo","master"}));
       set("long",
"�����ǻ���֮��ж����챻����������������û����ɵģ���������Ĺ����ףӢ̨��\n");
       set("title", HIR"��"+HIY"��"NOR);
       set("gender", "����");
       set("age", 20);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "����");
       set("per", 30);
        set("int", 30);
       set("max_kee", 500);
       set("max_gin", 500);
       set("max_sen", 500);
       set("force", 500);
       set("max_force", 500);
       set("force_factor", 20);
       set("max_mana", 300);
       set("mana", 300);
       set("mana_factor", 20);
       set("combat_exp", 200000);
  set("daoxing", 100000);


        set("eff_dx", 70000);
        set("nkgain", 260);

       set_skill("literate", 100);
       set_skill("unarmed", 80);
       set_skill("dodge", 80);
       set_skill("force", 80);
       set_skill("parry", 80);
       set_skill("hammer", 80);
       set_skill("spells", 80);
        set_skill("wuji", 80);
        set_skill("suiyu-zhang", 80);
        set_skill("lianxin-force", 80);
        set_skill("fengri-hammer", 60);
        set_skill("ningxin-step", 60);
        map_skill("spells", "wuji");
        map_skill("unarmed", "suiyu-zhang");
        map_skill("force", "lianxin-force");
        map_skill("hammer", "fengri-hammer");
        map_skill("parry", "fengri-hammer");
        map_skill("dodge", "ningxin-step");

           create_family("������", 4, "�Ĺ�С��");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/obj/weapon/hammer/falun")->wield();
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="����")){
           command("shake");
           command("say ��ֻ����ͽ����λ" +
RANK_D->query_respect(ob) + "����ȥ���Ҽ����ðɡ�\n");
           return;
        }

        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ���������������ȷ�����\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xian");
}
