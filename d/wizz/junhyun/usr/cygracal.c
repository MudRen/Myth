// ���NPC
//by junhyun@SK

#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����"NOR, ({"cygracal's"}));
        set("title", HIW"��˿��"HIY"�ֻ�����"NOR);
        set("nickname", HIG"��˿����"NOR);
        set("gender", "Ů��" );
      set("taskguai",1);
        set("age", 20);
        set("per", 40);
        set("str", 30);
        set("family/family_name", "��˿��");
        set("class", "xian");
    set("long","
�߿�վ������ң��������а�ǰ��ʮ���ڵ�ٮٮ�ߡ�\n");

        set("attitude", "friendly");

  set("combat_exp", 100000000);
  set("daoxing", 100000000);

  set_skill("literate", 300);
  set_skill("unarmed", 300);
  set_skill("lanhua-shou", 300);
  set_skill("force", 300);
  set_skill("jiuyin-xinjing", 300);
  set_skill("sword", 300);
  set_skill("chixin-jian", 300);
  set_skill("whip", 300);
  set_skill("yinsuo-jinling", 300);
  set_skill("parry", 300);
  set_skill("dodge", 300);
  set_skill("yueying-wubu", 300);
  set_skill("spells", 300);
  set_skill("pansi-dafa", 300);

  map_skill("force", "jiuyin-xinjing");
  map_skill("spells", "pansi-dafa");
  map_skill("sword", "chixin-jian");
  map_skill("parry", "chixin-jian");
  map_skill("dodge", "yueying-wubu");
  map_skill("whip", "yinsuo-jingling");

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
               (: perform_action, "sword", "hongyan" :), 
        }) );
  set_temp("apply/armor", 50);
  set_temp("apply/dodge", 50);

  setup();
  carry_object("/d/obj/weapon/sword/qingfeng.c")->wield();
}

