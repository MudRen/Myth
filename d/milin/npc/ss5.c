// �������� ���� by Calvin

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name(HIC"����"NOR, ({"si shen", "shen", "guard"}));
        set("gender", "����" );
        set("age", 45);
        set("taskguai",1);
        set("per", 30);
        set("str", 30);
    set("long","һλ����Ī�������\n");

        set("attitude", "aggressive");

  set("combat_exp", 10000000);
  set("daoxing", 100000000);

  set_skill("literate", 300);
  set_skill("unarmed", 300);
  set_skill("force", 300);
  set_skill("lengquan-force", 300);
        set_skill("dengxian-dafa", 300);
     set_skill("gouhunshu", 300);
//   set_skill("meihua", 300);
  set_skill("whip", 300);
  set_skill("bawang-qiang", 300);
  set_skill("axe", 300);
  set_skill("dodge", 300);
  set_skill("parry", 300);
  set_skill("sanban-axe", 300);
  set_skill("bawang-qiang", 300);
  set_skill("spells", 300);
  set_skill("baguazhou", 300);
  set_skill("spear", 300);
  set_skill("yanxing-steps", 300);
  map_skill("force", "lengquan-force");
  map_skill("spells", "gouhunshu");
//        map_skill("spells", "dengxian-dafa");
  map_skill("axe", "sanban-axe");
  map_skill("parry", "sanban-axe");
  map_skill("dodge", "yanxing-steps");
  map_skill("spear", "bawang-qiang");
  map_skill("whip", "bawang-qiang");

  set("max_sen", 10000);
  set("max_kee", 10000);
  set("force", 6000); 
  set("max_force", 6000);
  set("force_factor", 500);
  set("max_mana", 10000);
  set("mana", 10000);
  set("mana_factor", 500);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "spear.lei" :),
                (: perform_action, "axe.sanban" :),
                (: perform_action, "axe.kai" :),
                (: exert_function, "jingxin" :),
                (: cast_spell, "gouhun" :),
                (: cast_spell, "inferno" :),
//                (: cast_spell, "tuntian" :),
//                (: cast_spell, "jieti" :),
        }) );
  set_temp("apply/armor", 50);
  set_temp("apply/dodge", 50);

  setup();
        carry_object("/d/milin/obj/bsd");
  carry_object("/d/obj/weapon/spear/jinqiang")->wield();
}
