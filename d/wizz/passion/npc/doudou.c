inherit NPC;

int give_dan();

#define UPPLAYER   "/cmds/wiz/update"

#include <ansi.h>

void create()

{

set_name("三界迎宾", ({ "doudou" }) );

        set("gender", "女性" );

      set("color", HIR); 

         set("age", 9);

        set("age", 20);
set("max_mana",100000);
set("max_sen",100000);
set("max_kee",100000);
set("max_gin",100000);
set("max_force",100000);
set("force",100000);
set("kee",100000);
set("sen",100000);
set("mana",100000);
set("gin",100000);
/*
set("max_mana",100000)
set("max_sen",100000)
set("max_kee",100000)
set("max_gin",100000)
set("max_force",100000)
set("force",100000)
set("kee",100000)
set("sen",100000)
set("mana",100000)
set("gin",100000)
*/

           set("title", HIY "痴"+ HIR "情" + HIM "大" + HIC"唐" NOR);

        set("long",

HIC "欢迎大唐的朋友来这里发展！"
"希望大家能把这里当成一个新的起点努力奋斗！从创辉煌\n" NOR);

set("combat_exp", 5000000000000);

        set("attitude", "friendly");

        set("per",50);

        set_skill("unarmed",200);

            set_skill("dodge",200);

        set("inquiry", ([

                "大唐" : (: give_dan :),

            ]));

        setup();

}

int give_dan()

{

object dan;

object who;

who = this_player();

if (!userp(who))

{

command("heng");

command("say 什么小猫小狗也来要礼物啊？！");

command("qi");

return 1;

}

         if ((string)this_player()->query("passionset")=="1")

{

          message_vision("$N对着$n哼了一声。\n",this_object(),this_player());

       command("say 你是谁呀，好象登记过了呀！");

  return 1;

}

if ( who->query("mud_age") < 6100 ) 
{
who->set("title","大唐");
message_vision(HIY"$N浑身散发耀眼的金光!\n$N手一指，金光笼罩在$n身上。\n"NOR,this_object(),this_player());
message_vision(HIW"欢迎$n来到三界蛇口站,祝$n在本站完的高兴。\n"NOR,this_object(),this_player());
who->set("passionset","1");
UPPLAYER->update_player(who);
 return 1;
}




/*
message_vision(HIY"$N浑身散发耀眼的金光!\n$N手一指，金光笼罩在$n身上。\n"NOR,this_object(),this_player());

message_vision(HIW"欢迎$n来到三界蛇口站,祝$n在本站完的高兴。\n"NOR,this_object(),this_player());

who->set("passionset","1");

UPPLAYER->update_player(who);

*/
message_vision(HIW"你不是新人了，继续努力吧。\n"NOR,this_object(),this_player());
 return 1;

}




