// ���NPC
//by junhyun@SK

#include <ansi.h>
inherit NPC;
void create()
{
        set_name("��"NOR, ({"hjeff's"}));
        set("title", HIC"����һƷ������"NOR);
        set("nickname", HIW"ǹ���Ӱ"NOR);
        set("gender", "����" );
      set("taskguai",1);
        set("age", 20);
        set("per", 40);
        set("str", 30);
        set("family/family_name", "������");
        set("class", "xian");
    set("long","
�߿�վ������ң��������а�ǰ��ʮ���ڵ�ٮٮ�ߡ�\n");

        set("attitude", "friendly");

  set("combat_exp", 100000000);
  set("daoxing", 100000000);

  set_skill("literate", 300);
  set_skill("unarmed", 300);
  set_skill("changquan", 300);
  set_skill("force", 300);
  set_skill("lengquan-force", 300);
  set_skill("mace", 300);
  set_skill("jinglei-mace", 300);
  set_skill("spear", 300);
  set_skill("bawang-qiang", 300);
  set_skill("parry", 300);
  set_skill("dodge", 300);
  set_skill("yanxing-steps", 300);
  set_skill("spells", 300);
  set_skill("baguazhou", 300);

  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("mace", "jinglei-mace");
  map_skill("parry", "jinglei-mace");
  map_skill("dodge", "yanxing-steps");
  map_skill("spear", "bawang-qiang");

  set("max_sen", 7000);
  set("max_kee", 7000);
  set("force", 16000); 
  set("max_force", 8000);
  set("force_factor", 100);
  set("max_mana", 8000);
  set("mana", 16000);
  set("mana_factor", 100);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
               (: perform_action, "mace", "lei" :), 
        }) );
  set_temp("apply/armor", 50);
  set_temp("apply/dodge", 50);

  setup();
  carry_object("/d/obj/weapon/mace/silverjian.c")->wield();
}

