//���NPC
//plum.c   by junhyun@SK

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("������", ({"buwawa's"}));
        set("title", HIG"��ҹ"HIW"����"NOR);
        set("gender", "Ů��" );
        set("age", 20);
        set("per", 40);
        set("str", 330);
set("long","����ΪǮ������������,�������԰�����(��ǣ��gold)
\n");

       set("shen_type", 1);
       set("combat_exp", 185472870);
       set("daoxing", 180483650);
       set("max_kee",4000);
       set("max_gin", 306);
       set("max_sen", 3500);
       set("force", 12000);
      set("max_force", 6000);
       set("force_factor", 500);
       set("max_mana", 6000);
       set("mana", 12000);
       set("mana_factor", 500);

       set_skill("dodge", 400);
       set_skill("baguazhen", 400);
       set_skill("force", 400);
       set_skill("zhenyuan-force", 400);
       set_skill("spells", 400);
       set_skill("taiyi", 400);
       set_skill("sword", 400);
       set_skill("sanqing-jian", 400);
       set_skill("unarmed", 400);
       set_skill("wuxing-quan", 400);
       set_skill("literate", 400);
       set_skill("parry", 400);



        map_skill("dodge", "baguanzhen");
        map_skill("force", "zhenyuan-force");
        map_skill("parry", "sanqing-jian");
        map_skill("spells", "taiyi");
        map_skill("unarmed", "wuxing-quan");
        map_skill("sword", "sanqing-jian");

       set("chat_msg_combat", ({
              (: perform_action, "sword", "jianzhang" :),
              (: perform_action, "sword", "jianmang" :),
                }) );
        set_temp("apply/armor",50);
        set_temp("apply/damage",25);
        setup();
        carry_object("d/wizz/junhyun/usr/obj/wawaguo")->wear();
        carry_object("d/wizz/junhyun/usr/obj/wawaguo1")->wear();
        carry_object("d/wizz/junhyun/usr/obj/wawasword")->wield();
}

