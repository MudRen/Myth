// ���� by Calvin

#include <ansi.h>
inherit NPC;

int test_player (object me);

void create()
{
       set_name("����", ({"bu ma","bu","ma"}));
       set("long",
"һλƯ��������С����,�����Ӻ��ǵ�Ƥ��\n");
       set("title", HIG"��������"NOR);
       set("gender", "Ů��");
       set("color", HIW);
       set("age", 16);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "СMM");
       set("per", 40);
       set("int", 30);
       set("max_kee", 10000);
       set("max_gin", 10000);
       set("max_sen", 10000);
       set("force", 6000);
       set("max_force", 6000);
       set("force_factor", 1000);
       set("max_mana", 6000);
       set("mana", 6000);
       set("mana_factor", 1000);
       set("combat_exp", 100000000);
       set("daoxing", 100000000);

        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 1000);
       set_skill("unarmed", 1000);
       set_skill("dodge", 1000);
       set_skill("force", 1000);
       set_skill("parry", 1000);
       set_skill("sword", 1000);
       set_skill("spells", 1000);
       set_skill("moonshentong", 1000);
       set_skill("baihua-zhang", 1000);
       set_skill("moonforce", 1000);
       set_skill("snowsword", 1000);
       set_skill("moondance", 1000);

        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("sword", "snowsword");
        map_skill("parry", "snowsword");
        map_skill("dodge", "moondance");

  set("inquiry", ([
        "��":   (: test_player :),
        "����":   (: test_player :),
        "������":   (: test_player :),
        "zhu":   (: test_player :),
        "longzhu":   (: test_player :),
        "long zhu":   (: test_player :),
        "qi longzhu":   (: test_player :),
        "fen longzhu":   (: test_player :),
      ]));

  set("chat_msg", ({ (: random_move :) }));

setup();

        carry_object("/d/quest/longzhu/armor/lingyue")->wear();
//        carry_object("/d/longzhu/weapon/lingyue")->wield();
}

int test_player (object me)
{
  object who = this_player();

  if (who->query("combat_exp")<1000000)
  {
    me->command_function("shake");
    me->command_function("say ��Ĺ�����ô��Ҫ��������Ҳû�еġ�");
    return 1;
  }  

  me->command_function("ok");
  me->command_function("say �����Ǹ�����,���ҪŬ��ȥ�ҵ��������鰡,ף��ɹ���");
  call_out ("give_zhu",1,me,who);
  return 1;
}

void give_zhu (object me, object who)
{
  object zhu = new ("/d/quest/longzhu/obj/3");

  zhu->move(me);
  me->command_function ("give "+who->query("id")+" zhu");
}

