// ������� "���" by cigar
 
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name(WHT"���"NOR, ({"piao miao","piao","miao","tianshen","piaomiao"}));
        set("title", CYN"�����ֻص�"NOR);
  set("long", "����������翲��������������г�������!\n");
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
  set("class", "sanjie");
  set("family/family_name", "����ɽ");
  set("max_gin", 2500);
  set("max_sen", 10000);
  set("force", 20000);
  set("max_force", 5000);
  set("force_factor", 250);
  set("max_mana", 5000);
  set("mana", 20000);
  set("mana_factor", 100);

  set("combat_exp", 2000000);
  set("daoxing", 2000000);

   set_skill("unarmed", 350);
  set_skill("blade", 400);
  set_skill("zileidao", 350);
  set_skill("dodge", 350);
   set_skill("parry", 350);
   set_skill("literate", 350);
   set_skill("spells", 350);
  set_skill("force", 350);
  set_skill("huntianforce", 400);
  set_skill("zhaoyangbu", 350);
     set_skill("tianmogong", 400);
     set_skill("sword", 350);
   set_skill("stick", 350);

  map_skill("force", "huntianforce");
  map_skill("dodge", "zhaoyangbu");
  map_skill("spells", "tianmogong");
  map_skill("parry", "zileidao");
  map_skill("blade", "zileidao");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "zileidao", "tulong" :),
                (: exert_function, "jinshen" :),
                (: exert_function, "recover" :),
                (: cast_spell, "feixian" :),
                (: cast_spell, "zhui" :),
        }) );
  set("nk_gain", 600);
   
  set_temp("apply/armor", 50);
  set_temp("apply/dodge", 50);
 
  create_family("����ɽ", 1, "���");
  setup();
  
  carry_object("/d/9ct/zb/blade")->wield();
carry_object("/d/npc/obj/armor")->wear();
carry_object("/d/9ct/zb/pao")->wear();
}

void attempt_apprentice(object ob, object me)
{
  if ( (string)ob->query("family/family_name")=="����ɽ") {
    if (((int)ob->query("combat_exp") < 2000000 )) {
      command("say " + RANK_D->query_rude(ob) + "������ˮƽ��������,����Ҳ�ѳɴ���,�����ٻ�ȥ����һ����!");
      return;
    }
    command("grin");
    command("say �ܺã�" + RANK_D->query_respect(ob) +
       "���Ŭ�������ձض��гɡ�\n");
    command("recruit " + ob->query("id") );
                ob->set("title", HIB"�����ֻ�ʥ��"NOR);
    return;
  }
 command("shake");
  command("say " + RANK_D->query_respect(ob) +
     "������ȥѧЩ��������ɣ�\n");
  return;
}

