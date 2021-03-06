// jiuyou.c
// created by kuku@sjsh  2002/11

#include <ansi.h>
inherit NPC;
int time_period(int timep, object me);
string sysmsg;
object owner() {return query("owner");}
int give_quest();
int do_cancel();

void create()
{
        set_name(HIB "九幽异人" NOR, ({ "jiuyou", "jiu you", "yiren" }) );
        set("gender", "男性");
        set("age", 99);
        set("long",
            "九幽异人年过六甲，鹤发童颜。他乃一隐居江湖之奇人，他虽已退
隐江湖多年，但是黑白两道上的人一提起他的名字无不惧怕三分。\n");
        set("attitude", "peaceful");
        set("str", 26000);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("per", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
            "九幽异人拿起旱烟抽了几口．．．．\n",
        }) );
        set("force", 40000);
        set("max_force", 80000);
        set("force_factor", 1000);
        set("combat_exp", 100000000);
        set_skill("unarmed", 120);
        set_skill("force", 100);
        set_temp("apply/attack",300);
        set_temp("apply/damage",30000);
        set("title", HIC"闲云野鹤"NOR);
        set("inquiry", ([ 
                "quest" : (: give_quest :),
                "cancel" : (: do_cancel :),
        ]) );
        setup();
        carry_object("/d/obj/cloth/linen")->wear();
        carry_object("/d/obj/cloth/buxie")->wear();
}

int accept_fight(object me)
{
        command("say 生命可贵！不要自寻死路！");
        return 0;
}

int accept_object(object who, object ob)
{
        int  exp, pot, score,i;
        string nm,id;
        nm=who->query("task/name");
        id=who->query("task/id");
        if(ob->query("name")!=nm||ob->query("id")!=id)
        {
            tell_object(who,"九幽异人说道：这不是我想要的。\n");
            return 0;
        }
        if( ob->is_character())
        {
            tell_object(who,"九幽异人说道：这不是我想要的。\n");
            return 0;
        }
        if ((int) who->query("task_time") < time() )
        {
            tell_object(who,"九幽异人说道：真可惜！你没有在指定的时间内完成！\n");
            return 1;
        }
        else
        {
            tell_object(who,"九幽异人说道：恭喜你！你又完成了一项任务！\n");
            score = (int) who->query_temp("quest_number");
        exp =1000+random(3000)+400*score;
        pot = exp / 8 ;
        if (random(2)==1){ 
            who->add("combat_exp",exp);
            who->add("potential",pot);
            who->add("balance",20000);
            tell_object(who,HIW"你得到了"+exp+"点武学"+pot+"点潜能的奖励！你的存款增加了二两黄金。\n" NOR);
            message("channel:rumor",HIM"【"+HIW"谣言传说"+HIM"】"+who->name()+"帮"+this_object()->query("name")+"找到了『"+ob->query("name")+"』，得到了"+exp+"点武学和"+pot+"点潜能。\n"NOR,users());}
           else {
            who->add("daoxing",exp);
            who->add("potential",pot);
            who->add("balance",20000);
            tell_object(who,HIW"你得到了"+COMBAT_D->chinese_daoxing(exp)+"道行和"+pot+"点潜能的奖励！你的存款增加了二两黄金。\n" NOR);
message("channel:rumor",HIM"【"+HIW"谣言传说"+HIM"】"+who->name()+"帮"+this_object()->query("name")+"找到了『"+ob->query("name")+"』，得到了"+COMBAT_D->chinese_daoxing(exp)+"道行和"+pot+"点潜能。\n"NOR,users());
         }
       if (score == 10){
       who->delete_temp("quest_number");
        i = 300000+random(500000);
        who->add("balance",i);
        tell_object(who,HIG"你真行，你得到了"+chinese_number(i/10000)+"两黄金的附加奖励！\n"NOR);  } 
        who->set_temp("task/done",1);
        who->delete("task/name");
        who->delete("task/id");
        who->delete("quest_ask");
        who->delete("task_give");
       return 1; }
        return 1;
}

int give_quest()
{
        object me,person,newob;
        int j, t, timep;
        string where;
        mixed* file,local;
        me = this_player();
        if((int)me->query("combat_exp") >= 50000000)
        {
            write("九幽异人已经不会给你任何任务了！\n");
            return 1;
        }
        if(!userp(me)){
                write("想浑水摸鱼？没门！！\n");
                return 1;
        }
        if((int) me->is_ghost())
        {
            write("鬼魂不可要任务．\n");
            return 1;
        }
        if(me->query("task/name")&&me->query("task/id"))
        {
          if( ((int) me->query("task_time")) >  time() ) 
          {
            command("say 我让你找的东西呢？\n");
            return 1; 
          }
          else
               me->set("kee", me->query("kee")/2+1);
               me->delete_temp("quest_number");
    
        if(!me->query_temp("task/done") || !me->query_temp("task/cancel")){
            command("say 你的上一个任务还没完成呢。\n");
            return 1; }
        }
        person = new(__DIR__"questnpc");
        where=person->invocation(me);
        person->set("owner",me);
        file = get_dir("/d/quest/newtask/questobj"+"/*.c",-1);
        if( !sizeof(file) )  return 0;
        j = random(sizeof(file));
        if( file[j][1] > 0 ) { 
            newob=load_object("/d/quest/newtask/questobj"+"/"+file[j][0]);
            }
        timep = 600;   // each quest give 10 mins.
        timep = random(timep/2)+timep/2;
        time_period(timep, me);
        tell_object(me,where+"等你，向他要回『"+newob->query("name")+"』。\n" NOR);
        sysmsg +="找回『"+newob->query("name")+"』。";
        me->set("task_time", (int) time()+(int) timep);
        me->set("task/name", newob->query("name"));
        me->set("task/id", newob->query("id"));
        me->set_temp("task/ob",person);
        me->delete_temp("task/done");
        me->delete_temp("task/cancel");
        if((int)me->query_temp("quest_number") < 20)
        me->add_temp("quest_number",1);
        CHANNEL_D->do_channel(this_object(), "job", sprintf("%s(%s)：%s",
        me->query("name"),me->query("id"),sysmsg));
        return 1;
}

int do_cancel()
{
             object me = this_player();
             object person;
        if (!me->query("task/name")||!me->query("task/id"))
                  {tell_object(me,"你没有任务在身。\n"); return 1;}
            me->delete_temp("quest_number");
            me->delete("task/name");
            me->delete("task/id");
            me->delete("quest_ask");
        me->delete("task_give");
        me->set_temp("task/cancel",1);
        me->command("say 这个任务弟子恐怕无能为力。\n");
        command("say 好吧，那你先休息休息吧。\n");
            person=me->query_temp("task/ob");
             if (living(person))
             {
             destruct(person);
            }
             return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;
        if(d) time = chinese_number(d) + "天";
        else time = "";
        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
        tell_object(me,HIW + sprintf("%s",this_object()->name()) +"说道：请在" + time + "内，");
        sysmsg = "在" + time + "内";
        return 1;
}

void die()
{
        if (environment())
        message("sound", "九幽异人「唉」的一声叹了口气！\n", environment());

        set("eff_kee", 10000);
        set("eff_gin", 10000);
        set("eff_sen", 10000);
        set("kee", 10000);
        set("gin", 10000);
        set("sen", 10000);
        set("force", 10000);
        set("mana", 10000);
}

void unconcious()
{
        die ();
}
