inherit NPC;
#include <ansi.h>

int summons();
void create()
{
        set_name("日光精灵", ({ "spirit" }) );
        set("age", 20);
        set("gender", "男性"); 
        set("long", 
"日光精灵，在日光中诞生的精灵，看上去象一团光影。\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("int", 20);
        set("per", 20);
        set("con", 20); 
        set("dex", 40); 
        set("kee", 200); 
        set("sen", 20300); 
        set("max_kee", 20200);
        set("max_sen", 22000);
        set("max_force", 22000);
        set("force", 20020);
        set("force_factor", 300);

        set_skill("dodge", 800); 
        set_skill("blade", 800); 
        set_skill("parry", 800); 
        set_skill("force", 800); 
        set_skill("spirit-dodge", 800); 
        set_skill("spirit-blade", 800); 
        map_skill("dodge", "spirit-dodge");
        map_skill("blade", "spirit-blade");
        map_skill("parry", "spirit-blade"); 

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({ 
        (: summons :)
        }) );
        setup();
         carry_object("/d/obj/weapon/blade/jindao")->wield(); 
}

int summons()
{
        object ob;
        object me = this_object ();
        message_vision(HIY"$N双手结印，喃喃地念了几句咒语。\n"NOR, me);
        ob = new("/d/quest/tulong/npc/spirit");
        ob->move(environment(me));
        ob->invocation(me); 
                return 1;
} 

