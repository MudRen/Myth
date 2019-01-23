inherit NPC;
#include <ansi.h>
#include "greeting.h"
string ask_bad(object me);
int done_bad();
int do_job();
int ask_done();

void create()
{
        set_name(HIC"薛仁贵"NOR, ({ "xue rengui", "xue", "rengui" }) );
        set("gender", "男性");
        set("age", 35);
        set("long","薛仁贵是长安城九门提督，负责皇宫内外安全。\n");
        set("combat_exp", 200000000);
        set("daoxing", 200000000);
        set("title", HIR"九门提督"NOR);
        set("nickname", HIY"勇冠三军"NOR);
        set("attitude", "friendly");
        set("per", 25);
        set("str", 35);
        set("max_kee", 20000);
        set("max_sen", 20000);
        set("max_mana", 20000);
        set("mana", 40000);
        set("force", 40000);
        set("max_force", 20000);
        set("force_factor", 500);
        set_skill("spear", 500);
        set_skill("unarmed", 500);
        set_skill("changquan", 500);
        set_skill("parry", 500);
        set_skill("dodge", 500);
        set_skill("bawang-qiang", 500);
        set_skill("yanxing-steps", 500);
        map_skill("spear", "bawang-qiang");
        map_skill("parry", "bawang-qiang");
        map_skill("dodge", "yanxing-steps");
        map_skill("unarmed", "changquan");
        set("inquiry", ([
                "逃犯" : (: ask_bad :),
                "cancel" : (: done_bad :),
                "fangqi" : (: done_bad :),
                "守城" : (: do_job :),
                "job"  : (: do_job :),
                "完成" : (: ask_done :),
                "done" : (: ask_done :),
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
        command("say 我为殿前将军，岂能与你村野匹夫较艺！");
        return 0;
}


string ask_bad(object me)
{
    me=this_player();
    if ( me->query("office_number") > 300 )
        return ("不敢有劳大驾。");
    if ( me->query("combat_exp") < 100000 )
        return ("我怎么能放心你去呢？");
    if ( me->query("bad") == 0 )
        return "/d/obj/bad"->query_yao(me);
}

int accept_object(object who, object ob)
{
        int i,t,j;
      string bname = who->name()+"的"+who->query("bad/name") + "的头颅";

     if ( (string)ob->query("name") != bname )
        return notify_fail("薛仁贵怒道：你竟敢糊弄我！\n");

     if (!ob->query("killer") ||ob->query("killer") != who->query("id"))
       return notify_fail("薛仁贵大怒：不是你杀的也敢拿来,小心我扁你！\n");
                j =who->query("combat_exp");

t=who->query("sell_gem/ask_jobgift_time");
                i=who->query("sell_gem/number");
                if(t && (t+3600)>time()){
                        if(i>=10000 && i<30000){
                                who->add("office_number", 1);
                                if (j< 1500 )
                                        who->add("combat_exp", who->query("combat_exp")/1500 );
                                else
                                        who->add("combat_exp", 1501*4/3);
                                who->add("potential", (50 + random(100))*4/3 );
                        }
                        else if(i>=30000 && i<60000){
                                who->add("office_number", 1);
                                if (j< 1500 )
                                        who->add("combat_exp", who->query("combat_exp")*3/4000 );
                                else
                                        who->add("combat_exp", 1501*3/2);
                                who->add("potential", (50 + random(100))*3/2 );
                        }
                        else if(i>=60000 && i<150000){
                                who->add("office_number", 1);
                                if (j< 1500 )
                                        who->add("combat_exp", who->query("combat_exp")/1000 );
                                else
                                        who->add("combat_exp", 1501*2);
                                who->add("potential", (50 + random(100))*2 );
                        }
                }
                else{
      who->add("office_number", 1);
      if (j< 1500 ) {
      who->add("combat_exp", who->query("combat_exp")/2000 );
        }
      else {
      who->add("combat_exp", 1501);
 }
      who->add("potential", 50 + random(100) );
        }
      command("smile");
      command("touch " + who->query("id"));
      tell_object(who,"薛仁贵点点头：不错，应该奖励。\n");
//    message("channel:chat",HIY+"【大唐天朝】薛仁贵(Xue rengui)："+who->query("name")+"杀死了"+who->query("bad/name")+"，功加一等。\n"+NOR,users());
      who->delete("bad");
      return 1;
}

int done_bad()
{
        object who = this_player();
        if ( who->query("bad") == 0 )
        {
                tell_object(who,"你现在没有逃犯要杀啊。\n");
                return 1;
        }
        command("qi");
        command("kick" + who->query("id"));
        tell_object(who,"薛仁贵的样子看起来气冲冲的：你这人，真没用。\n");
        who->delete("bad");
        return 1;
}


int do_job()
{
        object me;
        me = this_player();

    if ( me->query("office_number") > 1000 )
{
                 tell_object(me,"不敢有劳大驾。你的官职都这么高了还来守城？\n");
return 1;
}
    if( me->query("job/sxy-done")>0)
    {
                tell_object(me,"你必须先把上次的任务报告了以后才能再要任务。\n");
                return 1;
    }
    else
    if( me->query("job/sxy")>0)
    {
                tell_object(me,"你已在这儿要过任务了，快去守城。\n");
                return 1;
    }
    else
    if( me->query("combat_exp")<500000)
    {
                tell_object(me,"你为朝廷效力之心可表，可是守城不是儿戏，不要丢了性命。\n");
                return 1;
    }

    message_vision(CYN"薛仁贵对$N说道：你这就去吧，为朝廷效力，才是升官捷径者。\n"NOR,me);
        me->set("job/sxy", 1);
        me->apply_condition("sxy-job", 8);
        return 1;
}

int ask_done()
{

        object me/*,ob*/;
        int gong,exp,pot/*,money*/,i,t;
        me = this_player();
        gong = me->query("job/gong");

t=me->query("sell_gem/ask_jobgift_time");
                i=me->query("sell_gem/number");

                if(t && (t+3600)>time()){
                                exp = gong * 250 *4/3;
                                pot = gong * 100 *4/3;
                        }
                        else if(i>=30000 && i<60000){
                                exp = gong * 250 *3/2;
                                pot = gong * 100 *3/2;
                        }
                        else if(i>=60000 && i<150000){
                                exp = gong * 250 *2;
                                pot = gong * 100 *2;
                        }
                else{
        exp = gong * 250 /2;
        pot = gong * 100 /2;
        }

    if( me->query("job/sxy-done")< 1)
    {
                tell_object(me,"你的任务还没完成呢。\n");
                return 1;
    }

    message_vision(CYN"薛人贵对$N说道：做得不错！为国出力就应如此。\n"NOR,me);
    message_vision(CYN"薛仁贵对$N说道：你总共立了" + gong + "件功。\n"NOR,me);
    message_vision(CYN"薛仁贵对$N说道：该奖励你" + exp + "点经验，" + pot + "点潜能，"+gong + "点官值。\n"NOR,me);
    me->add("combat_exp",exp);
    me->add("potential",pot);
    me->add("office_number",gong); //Cigar 在2002.05.14更改去掉silver奖励，并且平衡了pot&exp与逃犯的之间差！
    me->delete("job/gong");
    me->delete("job/sxy");
    me->delete("job/sxy-done");
    return 1;
}
