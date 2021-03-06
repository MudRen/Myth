
// Room: /d/wiz/wizroom.c
// by mudring

#include <ansi.h>

inherit ROOM;

void create ()
{
    set ("short", "财神禁闭室");
    set ("long", @LONG
这儿是财神爷的地盘，看来你平时为富不仁，多行不义啊。你现在被
关押财神爷的禁闭室，不过好像有一个财神洞（zuan），正好可以容
纳下一个人的脑袋呢，不知道要怎么样才能出去哟。
LONG);

    set("exits", ([ /* sizeof() == 2 */
    ]));

    set("no_fight", 1);
    set("no_magic", 1);
    set("no_time", 1);
    set("no_get", 1);
    set("no_pk", 1);
// 26      set("no_clean_up", 1); 

    setup();
    //call_other("/obj/board/meet_b", "???");
}

void init()
{
  add_action("say_log",({ "zuan","pa"}));
   if (!wizardp(this_player()))
    add_action("block_cmd","",1);     
}

int block_cmd()
{
       string verb = query_verb();

       if (verb=="say") return 0; //allow say
       if (verb=="chat") return 0;
       if (verb=="quit") return 0;
       if (verb=="look") return 0;
       if (verb=="zuan") return 0;
       if (verb=="pa") return 0;
       if (verb=="drop") return 0;
       if (verb=="inventory") return 0;
       if (verb=="i") return 0;
//       if (verb=="home") return 0;
       if (verb=="get") return 0;
       if (verb=="fly") return 1;
       if (verb=="move") return 1;
       return 1;
}

int say_log()
{
    object ob = this_player();

        int exp;
        object cash, gold, silver, coin;
        string log_msg;
        int tval;

        //if (wizardp(ob)) return;

        cash = present("cash_money", ob);
        gold = present("gold_money", ob);
        silver = present("silver_money", ob);
        coin = present("coin_money", ob);
        exp = ob->query("combat_exp");

        tval = 0;
        if (cash) tval = cash->query_amount() * 10;
        if (gold) tval += gold->query_amount();
//        if (tval < 100) return;
        if (silver) tval += silver->query_amount() / 100;
        if (coin) tval += coin->query_amount() / 10000;

           message_vision("$N深吸一口气，运起了缩骨大法，往财神洞钻了过去...\n", ob);
		   
        if (tval > 1500)
        {
             return notify_fail("洞口太小了，你的身子爬不过去，还是扔掉一些东西再爬吧，千金散尽还复来...\n");
        }
  else
    {
    	
        ob->receive_damage("sen", ob->query("max_sen")*10/100,"钻财神洞");
      if (random(20) < 5)
        {
           return notify_fail("就差一点点就出去了，再试一次肯定行！！\n");    
        }
        else
        {        	
                ob->move("/d/city/kezhan");
        	message_vision("$N从天而降，脸上光彩奕奕，好似刚做过一件百年来的的积德善事一般！！！！\n", ob);
        }
    }
                
    return 1;
}

