 //modifyed by stey steywen@21cn.com
inherit NPC;
#include <ansi.h>
string *list=({"yg-qiankun","yg-jianmang","yg-jianzhang","yg-zxzx",
                "yg-ba","yg-jldl",
        });
void create()
{

        set_name("姜子牙", ({ "jiang ziya", "jiang", "ziya" }) );
        set("gender", "男性" );
        set("long", "姜子牙乃是封神榜天神，左手手持一个通天镜。\n");
        set("age",40);
        set("title", "传说中的神仙");
        set("str", 40);
        set("int", 30);
        set("con", 30);
        set("spi", 30);
        set("per", 30);
        set("class", "xian");
        set("attitude", "heroism");
        set("combat_exp", 1500000);
        set("daoxing", 2000000);
        set("max_kee", 20000);
        set("max_sen", 20000);
        set("force",5000);
        set("max_force",3000);
        set("force_factor", 150);
        set("mana", 5000);
        set("max_mana", 3000);
        set("mana_factor", 150);

        set("eff_dx", 600000);
        set("nkgain", 600);

        set_skill("unarmed",170);
        set_skill("dodge",400);
        set_skill("parry",170);
        set_skill("sword", 180);
        set_skill("force", 170);
        set_skill("spells", 170);
        set_skill("changquan", 170);
        set_skill("liangyi-sword", 180);
        set_skill("baguazhou", 170);
        set_skill("moshenbu", 170);
        set_skill("lengquan-force", 170);
        map_skill("unarmed", "changquan");
        map_skill("force", "lengquan-force");
        map_skill("spells", "baguazhou");
        map_skill("sword", "liangyi-sword");
        map_skill("parry", "liangyi-sword");
        map_skill("dodge", "moshenbu");

        set("chat_chance",1);
        set("chat_msg", ({
                    name()+"说道：哎。。近期下界妖怪淫乱，哪位大仙可愿去搭救花仙？\n",
                    }));

        seteuid(getuid());



        setup();
        carry_object("/d/obj/armor/jinjia")->wear();
        carry_object("/d/sky/obj/zhanyaojian")->wield();
}
void init ()
{
  add_action("do_task", "baohu");
  add_action("do_task", "dajiu");
  add_action("do_cancel", "cancel");
  add_action("do_cancel2", "cancel2");
  add_action("do_couple","killguai");
}

int do_couple()
{
        object me = this_player();
        object guai,xie,couple;
        int level,i;
        int tt;
        string where,msg;
          if( !me->query("married") )
        {
tell_object(me,"小孩子一边玩去！\n");
     return 1;
       }
    if( !me->query("married") && me->query("combat_exp")< 1000000 )
        {
tell_object(me,"你的武学修为不够，练好了再来！\n");
     return 1;
         }
     if(!objectp(couple=present(me->query("couple/id"),environment(me))))
        {
                tell_object(me,"你的那口子没来，闹别扭了？找到再说！\n");
                return 1;
        }
        
        if( (tt=(int)me->query("job_couple/job_start")) &&
             me->query("job_couple/done")=="done") {
 // job done
            if(tt<=time() &&
                    time()<tt+200) {
                message_vision("$N拿起通天镜一看，怪已除尽,你还是等等再来。\n",
                        this_object(), me);
                return 1;
            }

        }

 //       me->command("say 最近可有妖怪为害花仙？");


        if( me->query("job_couple/fail") )
             { if(tt<=time() &&
                    time()<tt+600) {

                message_vision(CYN"\n姜子牙说道：你任务失败了，等等再来把。\n"NOR,me);
                return 1;
            }

            me->delete("job_couple/fail");
             }


        if( me->query("job_couple/get") )
             {message_vision(CYN"\n姜子牙说道：你已经有任务了，快快起程。\n"NOR,me);
              return 1;
             }



        //确定任务等级
        level = random(10);
        if (level<5) level=1;
        else if (level<8) level=2;
        else level=3;

        me->set("job_couple/get",1);
        me->set("job_couple/level",level);
        me->delete("job_couple/done");
        me->set("job_couple/resen",1);
        me->set("job_couple/rekee",1);
        couple->set("job_couple/get",1);
        couple->set("job_couple/level",level);
        couple->delete("job_couple/done");
        couple->set("job_couple/resen",1);
        couple->set("job_couple/rekee",1);
        guai = new("/d/wizz/stey/couple/"+list[random(sizeof(list))]);
        guai->set("job_couple/npcstart",time());
        where=guai->invocation(me,couple,level);
        message_vision(CYN"\n姜子牙说道：现在有"+where+"附近活动，你去灭了它吧。\n"NOR,me);


this_object()->command("job "+me->name()+"接到一个杀"+guai->name()+"的任务。");
        me->set("job_couple/guai",guai);
        me->delete("job_couple/job_start");
        couple->delete("job_couple/job_start");
        me->set("job_couple/where",where);
        couple->set("job_couple/where",where);
        me->set("job_couple/job_start",time());
        couple->set("job_couple/job_start",time());
        couple->set("job_couple/guai",guai);
        me->set_temp("job_couple/ob",guai);
         couple->set_temp("job_couple/ob",guai);
    

        msg = me->name()+"接到一个夫妻的杀"+guai->name()+"的任务。";
        MONITOR_D->report_system_msg (msg);
        return 1;
}

int do_task()
{
        object me = this_player();
        object guai,xie;
        int level,i;
        int tt;
        string where,msg;
    if( me->query("combat_exp")< 1800000)
        {
tell_object(me,"你的武学修为不够，练好了再来！\n");
     return 1;
       }
        if( (tt=(int)me->query("baohu/job_start")) &&
             me->query("baohu/done")=="done") {
 // job done
            if(tt<=time() &&
                    time()<tt+200) {
                message_vision("$N拿起通天镜一看，花仙已搭救,你还是等等再来。\n",
                        this_object(), me);
                return 1;
            }

        }

        me->command("say 最近可有妖怪为害花仙？");


        if( me->query("baohu/fail") )
             { if(tt<=time() &&
                    time()<tt+600) {

                message_vision(CYN"\n姜子牙说道：你任务失败了，等等再来把。\n"NOR,me);
                return 1;
            }

            me->delete("baohu/fail");
             }


        if( me->query("baohu/get") )
             {message_vision(CYN"\n姜子牙说道：花仙等着搭救呢，快快起程。\n"NOR,me);
              return 1;
             }



        //确定任务等级
        level = random(10);
        if (level<5) level=1;
        else if (level<8) level=2;
        else level=3;

        me->set("baohu/get",1);
        me->set("baohu/level",level);
        me->delete("baohu/done");
        guai = new(__DIR__"baohunpc");
        guai->set("baohu/npcstart",time());
        where=guai->invocation(me, level);
        message_vision(CYN"\n姜子牙说道：现在有"+where+"附近被妖怪掳去，
已经快不行了，你去搭救她吧。\n"NOR,me);


this_object()->command("job "+me->name()+"接到一个搭救"+guai->name()+"的任务。");
        me->set("baohu/guai",guai);
        me->delete("baohu/job_start");
        me->delete("baohu/kk");
        me->set("baohu/where",where);
        me->set("baohu/start_time",time());
        me->set("baohu/job_start",time());

        me->set("baohu/id",guai->query("id"));

        me->set("baohu/name",guai->query("name"));
        me->set_temp("baohu/ob",guai);
        me->delete_temp("baohu/get");
        xie=new(__DIR__"shoes.c");
        xie->move(me);

        message_vision("$N变出一双水晶鞋。\n $N给$n一双水晶鞋。\n",this_object(),this_player());

        msg = me->name()+"接到一个搭救"+guai->name()+"的任务。";
        MONITOR_D->report_system_msg (msg);
        return 1;
}

int do_cancel()
{
        object me = this_player();
        object guai;
        int tt;
          if (!me->query("baohu/get"))
             {tell_object(me,"你没有任务在身。\n"); return 1;}
        if ( (tt=(int)me->query("baohu/job_start"))){
        if(tt<=time() &&
                    time()<tt+600) {
                message_vision("$N说道：时辰未到，不可放弃，呵呢陀佛。\n",
                        this_object(), me);
                return 1;
            }
        else{

        me->delete_temp("baohu");

        me->command("say 这个任务弟子恐怕无能为力搭救。");
        message_vision(CYN"\n姜子牙说道：好吧，那我另派神仙搭救吧。\n"NOR,me);
        me->delete("baohu/fail",1);
        me->delete("baohu/get");
        me->delete("baohu/job_start");

        guai=me->query_temp("baohu/ob");
        me->delete("baohu");

        if (living(guai))
        {
        destruct(guai);

        }
        me->delete("baohu/name");
        me->delete_temp("baohu");
        return 1;
        }
        }
}

int do_cancel2()
{
        object me = this_player();
        object guai,couple;
        int tt;
        
             if(!objectp(couple=present(me->query("couple/id"),environment(me))))
        {
                tell_object(me,"你的搭档不在，找到再说！\n");
                return 1;
        }
          if (!me->query("job_couple/get"))
             {tell_object(me,"你没有任务在身。\n"); return 1;}
        if ( (tt=(int)me->query("job_couple/job_start"))){
        if(tt<=time() &&
                    time()<tt+600) {
                message_vision("$N说道：时辰未到，不可放弃，呵呢陀佛。\n",
                        this_object(), me);
                return 1;
            }
        else{

        me->delete_temp("job_couple");

        me->command("say 这个任务弟子恐怕无能为力搭救。");
        message_vision(CYN"\n姜子牙说道：好吧，那我另派神仙搭救吧。\n"NOR,me);
        me->delete("job_couple/fail",1);
        me->delete("job_couple/get");
        me->delete("job_couple/job_start");
        couple->delete("job_couple/fail",1);
        couple->delete("job_couple/get");
        couple->delete("job_couple/job_start");

        guai=me->query_temp("job_couple/ob");
        

        if (living(guai))
        {
        destruct(guai);

        }
       
        return 1;
        }
        }
}
