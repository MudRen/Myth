//十本刀之夜伽·驹形由美
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("驹形由美", ({"xizikawa youmai","youmei"}));
        set("nickname", HIB"夜伽"NOR  );
        set("title", HIW"十本刀"NOR );
        set("gender", "女性" );
        set("age", 21);
        set("per", 40);
        set("str", 20);
            set ("long", @LONG
出身为花魁得她，因为对新政府将艺妓当做家畜看待
的态度感到绝望，于是走到了志志雄真实的身边，剑
心与志志雄进行最后的决斗时，她一直努力的希望去
帮助自己所爱的男人，即使失去生命也毫不惋惜。
LONG);

        set("combat_exp", 5000000);
        set("daoxing", 900000000);
        set_skill("unarmed", 300);
        set_skill("dodge", 300);
        set_skill("force", 300);
        set_skill("spells",300);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("force", 6000);
        set("max_force", 3000);
        set("mana", 6000);
        set("max_mana", 3000);  
        set("force_factor", 10);
        set("mana_factor", 10);
        set("inquiry", ([
           "name" : "我就是十本刀之夜伽·驹形由美\n",
     "here" : "我也不知道这是那里。\n",
     "志志雄" : "我所爱的男人，他才是真正的英雄！\n",
     "十本刀" : "你是不可能战胜十本刀的！\n", 
         ]) );


            setup();
}

