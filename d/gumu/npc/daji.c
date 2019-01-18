//妲己
//轩辕古墓
 
//daji.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_mieyao();
string ask_cancel(); 
void create()
{
       set_name("妲己", ({"da ji", "daji", "ji"}));
       set("long", "女娲座下 九天玄女 妖狐妲己\n");
       set("title", HIB"古墓幽魂" NOR);
       set("color", HIW);
       set("gender", "女性");
       set("age", 20);
       set("class","yaomo");
       set("attitude", "friendly");
       set("cor", 30);
       set("per", 40);
       set("max_kee", 4500);
       set("max_gin", 800);
       set("max_sen", 4500);
       set("force", 4000);
       set("max_force", 2000);
       set("force_factor", 125);
       set("max_mana", 2000);
       set("mana", 4000);
       set("mana_factor", 100);
       set("combat_exp", 2000000);
       set_skill("literate", 220);
       set_skill("unarmed", 220);
       set_skill("dodge", 220);
       set_skill("force", 220);
       set_skill("parry", 220);
       set_skill("sword", 220);
       set_skill("spells", 220);
   set_skill("youming-spells", 220);
   set_skill("jiuyin-zhua", 180);
   set_skill("jiuyin-force", 220);
   set_skill("qinghu-jian", 200);
   set_skill("kongming-steps", 150);
   map_skill("spells", "youming-spells");
   map_skill("unarmed", "jiuyin-zhua");
   map_skill("force", "jiuyin-force");
   map_skill("sword", "qinghu-jian");
   map_skill("parry", "qinghu-jian");
   map_skill("dodge", "kongming-steps");
   set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "mei" :),
                (: cast_spell, "huo" :)
        }) );
   set("inquiry", ([
                           "灭天": (: ask_mieyao :),
]));
create_family("轩辕古墓", 1, "红");
setup();

        carry_object("/d/obj/cloth/tianyi.c")->wear();
        carry_object("/d/obj/weapon/sword/qinghong.c")->wield();
        carry_object("/d/ourhome/obj/shoes")->wear();
}
void init()
{
add_action("do_kneel","kneel");
}

void attempt_apprentice(object ob)
{


   if ( (string)ob->query("family/family_name")=="轩辕古墓") {
   if (((int)ob->query("combat_exp") < 100000 )) {
   command("say " + RANK_D->query_respect(ob) +
"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
   return;
   }
        command("nod "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，有朝一日让轩辕古墓称霸三界！\n");
       command("recruit " + ob->query("id") );
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"还是先去找我妹妹学些基础功夫吧。\n");
        return;
}
int accept_fight(object me)
{
   return 0;
}

// lost add
string ask_cancel() 
{
object me=this_player(); 
if((int)me->query("secmieyao")) 
{
me->add("daoxing",-2000); 
me->delete_temp("m_mieyao"); 
me->delete("secmieyao"); 
me->delete("secmieyao_mudage");  
me->set("m_mieyao",1); 
me->add("m_fangqi",1);
return ("没用的东西！"); 
}
else
{
return ("我好象没叫你做个什么呀？！"); 
}
}
string ask_mieyao()
{
    object who=this_player();

    if((string)who->query("family/family_name")=="轩辕古墓") {
      command("smile "+who->query("id"));
      return "/d/obj/mieyao"->query_yao(who);
    }
    return ("非我门人,何故来此?\n");
}
int do_kneel()
{
    object who = this_player();
    if((string)who->query("family/family_name")!="轩辕古墓")
     return notify_fail(this_object()->query("name")+"说：你又不是仙家弟子，拜我干什么？\n");
   if("/d/obj/mieyao"->delete_mieyao(who)){
        command("say 既然如此，就算了吧，不过你没有完成任务，得受些惩罚！\n");
        who->add("faith",-5);
        message_vision("$N的忠诚度下降了！\n",who);
     }
}
string ask_hebi()
{
    object who=this_player();
    if((string)who->query("family/family_name")!="轩辕古墓")
        return ("你不是本派弟子，怎么知道紫青合璧?");
    if(who->query("qinghu-jian")<300)
        return ("你的青狐剑法还不够，还需多加努力才行。");
    if(who->query("zizhi-blade")<300)
        return ("你的紫雉刀法还不够，还需多加努力才行。");
    who->set_temp("gumu_hebi",1);
        return ("你可以perform hebi,也可以尝试perform ziqing hebi。");
}

