inherit NPC;
#include <ansi.h>
#include "greeting.h"
string ask_girl(object me);
int done_girl();

void create()
{
        set_name("无天血魔", ({ "blood king", "xuemo", "king" }) );
        set("gender", "男性");
        set("age", 99);
        set("long","他就是扰乱三界，与神佛为敌的无天血魔。\n");
        set("combat_exp", 90000000);
        set("title", HIR"无法无天"NOR);
        set("nickname", HIY"灭绝三界"NOR);
        set("attitude", "friendly");
        set("per", 40);
        set("str", 40);
        set("max_kee", 50000);
        set("max_gin", 50000);
        set("max_mana", 60000);
        set("mana", 60000);
        set("force", 60000);
        set("max_force", 60000);
        set("force_factor", 500);
        set_skill("spear", 380);
        set_skill("unarmed", 380);
        set_skill("moyun-shou", 380);
        set_skill("parry", 380);
        set_skill("dodge", 380);
        set_skill("huoyun-qiang", 380);
        set_skill("moshenbu", 380);
        set_skill("spells", 380);
        set_skill("pingtian-dafa", 380);
        map_skill("spear", "huoyun-qiang");
        map_skill("parry", "huoyun-qiang");
        map_skill("dodge", "moshenbu");
        map_skill("unarmed", "moyun-shou");
        map_skill("spells", "pingtian-dafa");
        set("inquiry", ([
                "任务" : (: ask_girl :),
                "cancel" : (: done_girl :),
                "fangqi" : (: done_girl :),
                ]));
        setup();

        carry_object("/d/obj/weapon/spear/tiespear")->wield();
        carry_object("/d/obj/armor/tongjia")->wear();
}

void init ()
{
        greeting2(this_player());
}

int accept_fight(object me)
{
        command("say 就凭你！哼，我怕喘气大点把你吹飞了！");
        return 0;
}


string ask_girl(object me)
{
    me=this_player();
    if ( me->query("bellicosity") < 1300 )
        return ("哼哼，你以为你是名门正派么？");
    if ( me->query("combat_exp") < 300000 )
        return ("你太弱了，会死的很惨的！");
    if ( me->query("girl") == 0 )
        return "/d/obj/girl"->query_yao(me);
}

int accept_object(object who, object ob)
{
      int i;
 string bname = who->query("girl/name");
     
     if ( (string)ob->query("name") != bname )
        return notify_fail("无天血魔怒道：你竟敢糊弄我！\n");
        
     if (!ob->query("killer") ||ob->query("killer") != who->query("id"))
       return notify_fail("无天血魔大怒：不是你杀的也敢拿来,小心我扁你！\n");
                i =who->query("combat_exp");
      who->add("bellicosity", 10);
      if (i< 1500 ) {
      who->add("combat_exp", who->query("combat_exp")/2000 );
        }
      else { 
      who->add("daoxing", 5000);
 }
      who->add("potential", 50 + random(100) );
      command("smile");
      command("touch " + who->query("id"));
      tell_object(who,"无天血魔点点头：不错，应该奖励。\n");
      message("channel:rumor",HIY+"【惨绝人寰】某人：听说"+who->query("name")+"将"+who->query("girl/name")+"献给无天血魔，"+who->query("girl/name")+"惨遭血魔蹂躏！\n"+NOR,users());
      who->delete("girl");
      return 1;
}

int done_girl()
{
        object who = this_player();
        if ( who->query("girl") == 0 )
        {
                tell_object(who,"你现在没有任务啊。\n");
                return 1;
        }
        command("qi");
        command("hummar" + who->query("id"));
        tell_object(who,"无天血魔的样子看起来气冲冲的：你这人，真没用。\n");
        who->delete("girl");
        return 1;
}

