
// Room: /d/wiz/wizroom.c
// by mudring

#include <ansi.h>

inherit ROOM;

void create ()
{
    set ("short", "���������");
    set ("long", @LONG
����ǲ���ү�ĵ��̣�������ƽʱΪ�����ʣ����в��尡�������ڱ�
��Ѻ����ү�Ľ����ң�����������һ�����񶴣�zuan�������ÿ�����
����һ���˵��Դ��أ���֪��Ҫ��ô�����ܳ�ȥӴ��
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

           message_vision("$N����һ���������������Ǵ󷨣����������˹�ȥ...\n", ob);
		   
        if (tval > 1500)
        {
             return notify_fail("����̫С�ˣ��������������ȥ�������ӵ�һЩ���������ɣ�ǧ��ɢ��������...\n");
        }
  else
    {
    	
        ob->receive_damage("sen", ob->query("max_sen")*10/100,"�����");
      if (random(20) < 5)
        {
           return notify_fail("�Ͳ�һ���ͳ�ȥ�ˣ�����һ�ο϶��У���\n");    
        }
        else
        {        	
                ob->move("/d/city/kezhan");
        	message_vision("$N������������Ϲ�����ȣ����Ƹ�����һ���������ĵĻ�������һ�㣡������\n", ob);
        }
    }
                
    return 1;
}

