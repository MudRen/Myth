// 九重天神 "五重天神 乌亚子" by Calvin

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string kick_back();

void create()
{
  set_name(MAG"乌亚子"NOR, ({ "wu yazi", "wu", "wuyazi","yazi","tianshen","wu" }));

  set("gender", "男性");
  set("age", 100);

  set("str", 20);
  set("per", 130);
  set("cor", 30);
  set("cps", 75);
  set("kar", 100);
  set("int", 40);
  set("con", 40);
  set("spi", 40);

  set("long","
乌亚子前生是先天界的一只蛄鸱,后来修生转世为今生界天神。

");
  set("title",MAG"笑傲九天"NOR);
  set("combat_exp", 5000000);
  set("daoxing", 5000000);

  set_skill("literate", 350);
  set_skill("unarmed", 350);
  set_skill("force", 350);
  set_skill("lengquan-force", 350);
  set_skill("axe", 350);
  set_skill("dodge", 350);
  set_skill("parry", 350);
  set_skill("sanban-axe", 350);
  set_skill("bawang-qiang", 350);
  set_skill("spells", 350);
  set_skill("baguazhou", 350);
  set_skill("jinglei-mace", 350);
  set_skill("mace", 350);
 set_skill("spear", 350);
  set_skill("yanxing-steps", 350);

  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("axe", "sanban-axe");
  map_skill("parry", "sanban-axe");
  map_skill("dodge", "yanxing-steps");
  map_skill("spear", "bawang-qiang");

  set("max_sen", 5000);
  set("max_kee", 5000);
  set("force", 2500); 
  set("max_force", 2500);
  set("force_factor", 140);
  set("max_mana", 3000);
  set("mana", 3000);
  set("mana_factor", 150);

  set("inquiry", ([
        "name"    : "小神九重天神其一'笑傲九天 乌亚子'。",
        "here"    : "这里便是五重天界,也就是千紫天。",
        "回去"    : (: kick_back :),
]) );

  create_family("将军府", 1, "蓝");

  setup();
  carry_object("/d/9ct/zb/axe")->wield();
  carry_object("/d/9ct/zb/kui")->wear();
}

void attempt_apprentice(object me)
{
  int effstr=(int)(me->query("str")+me->query_skill("unarmed",1)/10-2);
  string myrespect=RANK_D->query_respect(me);

  if (wizardp(me) && me->query("env/override"))
  {
        command("recruit "+me->query("id"));
        return;
  }
    if (effstr<20)
  {
      command("say "+myrespect+"的臂力低了些，恐怕难以学斧。");
      return;
 }
  command("nod");
  command("say 看来"+myrespect+"该是与我相会之时了,那我就收下吧!\n");
  command("recruit " + me->query("id") );
  return;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "fighter");
    ob->set("title",HIC"将军府深宫密使"NOR);
}

