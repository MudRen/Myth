//���NPC
//plum.c   by junhyun@SK

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("����", ({"ffff's"}));
        set("title", HIC"������ʦ"NOR);
        set("gender", "����" );
        set("age", 20);
        set("per", 40);
        set("str", 330);
set("long","
�����߿�վ����ҳ������ͬʱҲ���߿�վ��������ң���
����һ��������ʵҲ�����ġ���
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
       set_skill("yanxing-steps", 550);
       set_skill("force", 550);
       set_skill("lengquan-force", 550);
       set_skill("spells", 550);
       set_skill("baguazhou", 550);
       set_skill("spear", 550);
       set_skill("bawang-qiang", 550);
       set_skill("axe", 550);
       set_skill("sanban-axe", 550);
       set_skill("unarmed", 550);
       set_skill("changquan", 550);
       set_skill("literate", 550);
       set_skill("parry", 550);
       set_skill("mace", 550);
       set_skill("jinglei-mace", 550);



        map_skill("dodge", "yanxing-steps");
        map_skill("force", "lengquan-force");
        map_skill("parry", "jinglei-mace");
        map_skill("spells", "baguazhou");
        map_skill("axe", "sanban-axe");
        map_skill("unarmed", "chanquan");
        map_skill("spear", "bawang-qiang");
       set("chat_chance_combat", 80);
       set("chat_msg_combat", ({
              (: perform_action, "mace", "lei" :),
//              (: perform_action, "spear", "po" :),
//              (: perform_action, "spear", "hebi" :),
                }) );
        set_temp("apply/armor",50);
        set_temp("apply/damage",25);
        setup();
        carry_object("/d/obj/weapon/mace/silverjian.c")->wield();
}

