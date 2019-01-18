// ������� "������� ������" by Calvin

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

int do_drop(object, object);

void create()
{
  set_name(HIY"������"NOR, ({ "a ruotuo", "a", "ruotuo","tuo","aruotuo","art","tianshen" }));
  set("title", HIY"�������"NOR);
  create_family("�ݿ�ɽ�޵׶�", 1, "��ʦ");
  set("class", "xian");
  set("long", "һλ����翪������ķ�ʦ,���򹦼�׿�ѱ�תΪ��������\n");
  set("gender", "����");
  set("age", 100);
  set("attitude", "heroism");
  set("rank_info/respect", "���");
  set("rank_info/rude", "���ҷ�");
  set("per", 40);
  set("str", 30);
  set("cor", 40);
  set("con", 40);
  set("int", 40);
  set("spi", 40);
  set("cps", 40);
  set("kar", 40);
  set("max_kee", 10000);
  set("max_gin", 1800);
  set("max_sen", 10000);
  set("force", 8000);
  set("max_force", 5000);
  set("force_factor", 200);
  set("max_mana", 3500);
  set("mana", 5000);
  set("mana_factor", 120);

  set("combat_exp", 6000000);
  set("daoxing", 6000000);

  set_skill("spells", 350);
  set_skill("dao", 350);
  set_skill("yaofa", 350);
  set_skill("unarmed", 350);
  set_skill("kugu-blade", 350);
  set_skill("literate", 350);
  set_skill("spear", 370);
  set_skill("yinfeng-zhua", 350);
  set_skill("dodge", 350);
  set_skill("lingfu-steps", 350);
  set_skill("parry", 350);
  set_skill("force", 350);
  set_skill("huntian-qigong", 350);
  set_skill("blade", 350);
  set_skill("sword", 350);
  set_skill("qixiu-jian", 350);
  map_skill("spells", "dao");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("parry", "huoyun-qiang");
  map_skill("sword", "qixiu-jian");
  map_skill("blade", "kugu-blade");
  map_skill("dodge", "lingfu-steps");
  map_skill("force", "huntian-qigong");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "blade","pozhan" :),
        }) );
  setup();
  carry_object("/d/obj/cloth/taijicloth")->wear();
  carry_object("/d/npc/obj/blade")->wield();
  carry_object("/d/obj/armor/jinjia")->wear();
        add_money("gold", 10);
}

void attempt_apprentice(object ob)
{
  if ((string)ob->query("family/family_name")=="�ݿ�ɽ�޵׶�") {
    if(ob->query("combat_exp") > 2000000 && ob->query("daoxing") > 2000000) {
                command("say ���ղ�����!������Ŭ��!");
                command("say "+RANK_D->query_respect(ob)+"��ȻӲҪ����,���Ҿ�������ɡ�");
                command("recruit "+ob->query("id"));
        }
   return;
   }
    ob->set("class", "yaomo");
           ob->set("title",HIY"�޵׶�������ʹ"NOR);
        }

