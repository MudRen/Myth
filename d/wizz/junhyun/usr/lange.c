// ���NPC
//by junhyun@SK

#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����"NOR, ({"lange's"}));
        set("title", HIR"��ׯ�۳��Ƹ���"NOR);
        set("gender", "����" );
      set("taskguai",1);
        set("age", 20);
        set("per", 40);
        set("str", 30);
        set("family/family_name", "��ׯ��");
        set("class", "xian");
    set("long","
���������������ѣ�ȴ��ϴ�÷��ס������������
ϵ�Ÿ�������������������Ĳ��Űѽ���ü��Ũ��
�Ǻ�ֱ�������ź�Ũ�ĺ��ӡ��˳��ò�����Ӣ��������
���������ĸ�����������Ҹ���\n");

        set("attitude", "friendly");

  set("combat_exp", 68000000);
  set("daoxing", 60000000);

  set_skill("literate", 300);
  set_skill("unarmed", 300);
  set_skill("wuxing-quan", 300);
  set_skill("force", 300);
  set_skill("zhenyuan-force", 300);
  set_skill("sword", 300);
  set_skill("sanqing-jian", 300);
  set_skill("blade", 300);
  set_skill("yange-blade", 300);
  set_skill("parry", 300);
  set_skill("dodge", 300);
  set_skill("baguazhen", 300);
  set_skill("spells", 300);
  set_skill("taiyi", 300);

  map_skill("force", "zhenyuan-force");
  map_skill("spells", "taiyi");
  map_skill("sword", "sanqing-jian");
  map_skill("parry", "sanqing-jian");
  map_skill("dodge", "baguazhen");
  map_skill("blade", "yange-blade");

  set("max_sen", 10000);
  set("max_kee", 10000);
  set("force", 16400); 
  set("max_force", 8200);
  set("force_factor", 500);
  set("max_mana", 6500);
  set("mana", 13000);
  set("mana_factor", 500);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
               (: perform_action, "sword", "jianzhang" :), 
        }) );
  set_temp("apply/armor", 50);
  set_temp("apply/dodge", 50);

  setup();
  carry_object("/d/obj/weapon/sword/qingfeng.c")->wield();
}

