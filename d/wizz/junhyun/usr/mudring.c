//���NPC
//plum.c   by junhyun@SK

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("����", ({"mudring's"}));
        set("title", HIC"�ܹ���ʦ"NOR);
        set("gender", "����" );
        set("age", 20);
        set("per", 40);
        set("str", 330);
set("long","
������ˣ���д�ĳ������������һ���߿�վ�ˣ�
\n");

       set("shen_type", 1);
       set("combat_exp", 50000000);
       set("daoxing", 2000000000);
       set("max_kee",90000);
       set("max_gin",90000);
       set("max_sen",90000);
       set("force", 180000);
      set("max_force", 90000);
       set("force_factor", 150);
       set("max_mana", 90000);
       set("mana", 180000);
       set("mana_factor", 150);

       set_skill("dodge", 550);
       set_skill("baguazhen", 550);
       set_skill("force", 550);
       set_skill("zhenyuan-force", 550);
       set_skill("spells", 550);
       set_skill("taiyi", 550);
       set_skill("sword", 550);
       set_skill("sanqing-jian", 550);
       set_skill("blade", 550);
       set_skill("yange-blade", 550);
       set_skill("unarmed", 550);
       set_skill("wuxing-quan", 550);
       set_skill("literate", 550);
       set_skill("parry", 550);
//       set_skill("blade", 550);
//       set_skill("xuanhu-blade", 550);



        map_skill("dodge", "baguazhen");
        map_skill("force", "zhenyuan-force");
        map_skill("parry", "sanqing-jian");
        map_skill("spells", "taiyi");
        map_skill("blade", "yange-blade");
        map_skill("unarmed", "wuxing-quan");
//        map_skill("blade", "xuanhu-blade");
       set("chat_chance_combat", 80);
       set("chat_msg_combat", ({
              (: perform_action, "sword", "jianzhang" :),
              (: perform_action, "sword", "jianmang" :),
//              (: perform_action, "sword", "" :),
                }) );
        set_temp("apply/armor",50);
        set_temp("apply/damage",25);
        setup();

        carry_object("/d/obj/weapon/sword/qingfeng.c")->wield();
}

