//stey
inherit NPC;  
#include <command.h> 

void create() { seteuid(getuid());}  
 
 
 
 
void set_skills(int level,object me) 
{ 
         
         int i = 50; 
         object weapon;      
         
        me->set_skill("wuxing-quan", level+random(16));
        me->set_skill("baguazhen", level+random(16));
        me->set_skill("sword", level+random(16));
        me->set_skill("sanqing-jian", level+random(16));
        me->set_skill("zhenyuan-force", level+random(16));
        me->set_skill("literate", 180);
        me->set_skill("taiyi", level+20+random(16));
        me->map_skill("spells", "taiyi");
        me->map_skill("force", "zhenyuan-force");
        me->map_skill("unarmed", "wuxing-quan");
        me->map_skill("parry", "sanqing-jian");
        me->map_skill("sword", "sanqing-jian");
        me->map_skill("dodge", "baguazhen");
        me->set("chat_chance_combat", 80);
        me->set("chat_msg_combat", ({
                (: perform_action, "sword","jianzhang" :)
               }) );

        me->carry_object("/d/obj/armor/jinjia.c")->wear();
        me->carry_object("/d/obj/stey/sttt.c")->wield();
}
