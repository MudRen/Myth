// ��ԯ��Ĺ ��Ĺ������
//by junhyun@SK

#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC"��������"NOR, ({"hubao yaohu", "fox", "hu"}));
        set("title", HIW"��ԯ��Ĺ"NOR);
        set("gender", "Ů��" );
      set("taskguai",1);
        set("age", 20);
        set("per", 40);
        set("str", 30);
        set("family/family_name", "��ԯ��Ĺ");
        set("class", "yaomo");
    set("long","��������ԯ��Ĺ���ڶ౦�������\n");

        set("attitude", "aggressive");

  set("combat_exp", 10000000);
  set("daoxing", 100000000);

  set_skill("literate", 300);
  set_skill("unarmed", 300);
  set_skill("jiuyin-zhua", 300);
  set_skill("force", 300);
  set_skill("jiuyin-force", 300);
  set_skill("sword", 300);
  set_skill("qinghu-jian", 300);
  set_skill("blade", 300);
  set_skill("zizhi-blade", 300);
  set_skill("parry", 300);
  set_skill("dodge", 300);
  set_skill("kongming-steps", 300);
  set_skill("spells", 300);
  set_skill("youming-spells", 300);

  map_skill("force", "jiuyin-force");
  map_skill("spells", "youming-spells");
  map_skill("sword", "qinghu-jian");
  map_skill("parry", "qinghu-jian");
  map_skill("dodge", "kongming-steps");
  map_skill("blade", "zizhi-blade");

  set("max_sen", 10000);
  set("max_kee", 10000);
  set("force", 6000); 
  set("max_force", 6000);
  set("force_factor", 500);
  set("max_mana", 10000);
  set("mana", 10000);
  set("mana_factor", 500);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
               (: perform_action, "sword", "hebi" :), 
        }) );
  set_temp("apply/armor", 50);
  set_temp("apply/dodge", 50);

  setup();
        carry_object("/obj/money/gold");
          carry_object("/d/obj/weapon/sword/xy_sword.c")->wield(); 
}

