// ������� "��ԯ�ȵ� ����" by Calvin
 
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name(HIB"����"NOR, ({"yi mu","yi","mu","tianshen","yimu"}));
        set("title", HIB"�������"NOR);
  set("long", "�Ǻ�����,�������³���֮���̳��������������²�!\n");
  set("gender", "����");
  set("class", "youling");
  set("age", 100);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("per", 30);
  set("str", 30);
  set("int", 30+random(5));
  set("nkgain",790);
  set("max_kee", 10000);
  set("class", "youling");

  set("family/family/name", "���޵ظ�");
  set("max_gin", 2500);
  set("max_sen", 10000);
  set("force", 8000);
  set("max_force", 4000);
  set("force_factor", 200);
  set("max_mana", 3500);
  set("mana", 4000);
  set("mana_factor", 200);

  set("combat_exp", 5000000);
  set("daoxing", 5000000);

   set_skill("unarmed", 350);
  set_skill("whip", 350);
  set_skill("hellfire-whip", 350);
  set_skill("dodge", 350);
   set_skill("parry", 350);
   set_skill("literate", 350);
   set_skill("spells", 350);
  set_skill("force", 350);
  set_skill("tonsillit", 350);
  set_skill("ghost-steps", 350);
     set_skill("gouhunshu", 350);
   set_skill("jinghun-zhang", 350);
set_skill("kusang-bang", 350);
   set_skill("zhuihun-sword", 350);
   set_skill("sword", 350);
   set_skill("stick", 350);

  map_skill("force", "tonsillit");
  map_skill("unarmed", "jinghun-zhang");
  map_skill("dodge", "ghost-steps");
  map_skill("spells", "gouhunshu");
  map_skill("parry", "hellfire-whip");
  map_skill("whip", "hellfire-whip");
   map_skill("sword", "zhuihun-sword");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "whip","three" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: cast_spell, "gouhun" :),
        }) );
  set("nk_gain", 600);
   
  set_temp("apply/armor", 50);
  set_temp("apply/dodge", 50);
 
  create_family("���޵ظ�", 1, "���");
  setup();
  
  carry_object("/d/obj/cloth/baipao")->wear();
  carry_object("/d/9ct/zb/necklace")->wear();
  carry_object("/d/obj/weapon/whip/longsuo")->wield();
}

void attempt_apprentice(object ob, object me)
{
  if ( (string)ob->query("family/family_name")=="���޵ظ�") {
    if (((int)ob->query("combat_exp") < 2000000 )) {
      command("say " + RANK_D->query_rude(ob) + "������ˮƽ��������,����Ҳ�ѳɴ���,�����ٻ�ȥ����һ����!");
      return;
    }
    command("grin");
    command("say �ܺã�" + RANK_D->query_respect(ob) +
       "���Ŭ�������ձض��гɡ�\n");
    command("recruit " + ob->query("id") );
                ob->set("title", HIB"���޸���ڤʥʹ"NOR);
    return;
  }
 command("shake");
  command("say " + RANK_D->query_respect(ob) +
     "������ȥѧЩ��������ɣ�\n");
  return;
}

