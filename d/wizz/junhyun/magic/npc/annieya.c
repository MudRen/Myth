//魔导圣战NPC - 创世神之智慧安妮雅(未完成)
//by junhyun@SK
#include <ansi.h>
inherit NPC;
int give_gift();

void create()
{
        set_name(HIW"安妮雅"NOR, ({"annieya"}));
        set("title", HIC"创世贤者"NOR );
        set("nickname", HIW"智慧女神"NOR );
        set("gender", "女性" );
        set("age", 21);
        set("per", 40);
        set("str", 30);
            set ("long", @LONG
创世众神之一，拥有光明的力量。
LONG);

        set("combat_exp", 290000);
        set("daoxing", 40000000000);
        set_skill("unarmed", 370);
        set_skill("dodge", 340);
        set("max_kee", 10000);
        set("max_sen", 10000);
        set("force", 6000);
        set("max_force", 3000);
        set("mana", 6000);
        set("max_mana", 3000);  
        set("force_factor", 1000);
        set("mana_factor", 1000);
        set("inquiry", ([
           "name" : "我就是秩序女神安妮雅。\n",
     "here" : "这里是光明圣殿，光明勇士的梦想之地。\n",
         ]) );


            setup();
}


