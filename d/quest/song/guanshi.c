// guanshi.c 
// modified by koker@sjsh2002

#include <ansi.h>
inherit NPC;

string* dart_area=({"/d/dntg/hgs/schoolhall","/d/moon/yltw"});
string* dart_short=({"傲来国武馆","月宫附近的杏林外"});
string* dart_id=({"dongfang boyu","jiaofu tou"});
string* dart_name=({"馆主东方博玉","轿夫头"});
 
string do_job();
string do_give();
string do_cancel();

void create()
{
        set_name("武馆管事", ({"guan shi", "oldman"}));
        set("title", "酒老三");
        set("gender", "男性");
        set("age", 70);
        set("long", "老英雄萧振远的武馆管事。
由于酒量远近闻名，又排行老三所以人送外号酒老三。＂。\n");

        set("combat_exp", 70000);
        set_skill("fonxansword", 70);
        set_skill("sword", 70);
        set_skill("unarmed", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
        set_skill("moondance", 70);
        map_skill("dodge", "moondance");
        map_skill("sword", "fonxansword");
        map_skill("parry", "fonxansword");
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 30);
        set("inquiry", ([
                "运货" : (: do_job :),
                "货"   : (: do_job :),
                "工作" : (: do_job :),
                "job"  : (: do_job :),
                "领赏" : (: do_give :),
                "over" : (: do_give :),
                 "放弃" : (: do_cancel :),
                 "cancel" : (: do_cancel :),
        ]) );
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 15);
        setup();
//        carry_object("/clone/weapon/changjian")->wield();
//        carry_object("/clone/misc/cloth")->wear();
}

string chinese_time(int t)
{
        int d, h, m, s;
        string time;
        s = t % 60;     t /= 60;
        m = t % 60;     t /= 60;
        h = t % 24;     t /= 24;
        d = t;
        if(d) time = chinese_number(d) + "天";
        else time = "";
        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
        return time;
}

string do_job()
{   int n;
    object ob,cart;
    ob=this_player(); 
    n=random(sizeof(dart_area));   

    if ( ob->query_temp("in_dart"))
       return "你不是才要了任务吗？\n";

    if ( (int)ob->query_condition("dart_limit" ) > 0 )
       return "你好象没完成任务吧。\n";

    if ( ob->is_busy() || ob->query_temp("pending/exercising"))
                return "你现在正忙着呢。\n";

    if ( (int)ob->query("combat_exp") < 100000 )
       return "运我的货是件危险工作，我看"+RANK_D->query_respect(ob)+"似乎没有这能力！\n";

    if ( (int)ob->query_skill("force") < 60 )
       return "运货是件危险工作，我看"+RANK_D->query_respect(ob)+"的基本内力不足！\n";

    ob->set_temp("in_dart",1);
    ob->set_temp("dart_area",dart_area[n]);
    ob->set_temp("dart_id",dart_id[n]);
    ob->set_temp("dart_name",dart_name[n]);
    ob->apply_condition("dart_limit", 60);

    cart=new(__DIR__"cart");
    cart->set("master",ob->query("name"));
    cart->set("masterid",ob->query("id"));
    cart->move("/d/city/bingqipu");
    command("nod");
    message_vision(CYN "几个伙计将货车推了出来挂上了马匹。\n" NOR,ob); 
    return "你把这批武器的货送到"+dart_short[n]+"的"+dart_name[n]+"手中。\n";
    
}

string do_give()
{
string msg;
  object ob;

  ob=this_player();

  if ( !ob->query_temp("in_dart"))
    return "我没让你运货啊？\n";

  if ( !ob->query_temp("over_dart") )
    return "货车没有送到地头，莫非是你吞了！？\n";

  ob->delete_temp("in_dart");
  ob->delete_temp("over_dart");
  ob->delete_temp("dart_name");
  ob->delete_temp("dart_id");
  ob->delete_temp("dart_area");
  
if (ob->query("weiwang") < 200)
{
    ob->add("combat_exp",random(500)+50);
//    ob->add("potential",random(200)+50);
    ob->add("balance",random(1000)+500);   
    ob->add("daoxing",random(10000)+500);   
    ob->add("weiwang",5);
      msg = ob->name()+"完成了一次运货任务得到了奖励"; 
      MONITOR_D->report_system_msg (msg); 
    return RANK_D->query_respect(ob)+"果然是把好手，好样的。\n但是你的"CYN"门派威望"NOR"太少，我不能给你全额的佣金了，你先拿这点用吧！\n"NOR;  
}
else {
    ob->add("combat_exp",random(20000)+5000);
    ob->add("potential",random(20000)+5000);
    ob->add("balance",random(30000)+3000); 
    ob->add("daoxing",random(100000)+30000); 
    ob->add("weiwang",-200);                   
}
  msg = ob->name()+"在兵器铺得到了萧萧的全额奖励";
  MONITOR_D->report_system_msg (msg);
  command("pat "+ob->query("id"));
  return RANK_D->query_respect(ob)+"真的十分感谢你能帮助我运货到那边，太麻烦您了。\n这是您的"YEL"全额佣金"NOR"，希望您下次再来帮我送货，我们很需要你这样的人才！\n"NOR;
}

// passion add
string do_cancel()
{
object ob;
ob=this_player();
  if ( !ob->query_temp("in_dart"))
   return "搞什么搞，你有没有领过任务？\n";
ob->delete_temp("in_dart");
ob->delete_temp("dart_area");
ob->delete_temp("dart_id");
ob->delete_temp("dart_name");
ob->clear_condition("dart_limit");
command("sigh");
message_vision(CYN "算了算了，再给你一次机会吧。\n" NOR,ob); 
return "下次好好做，别在丢东西了。\n";
}
