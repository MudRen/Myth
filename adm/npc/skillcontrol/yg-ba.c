//stey
inherit NPC;
#include <command.h>

void create() { seteuid(getuid());}




void set_skills(int level,object me)
{

         int i = 50;
         object weapon;

        me->set_skill("changquan", level+random(16));
        me->set_skill("yanxing-steps", level+random(16));
        me->set_skill("spear", level+random(16));
        me->set_skill("bawang-qiang", level+random(16));
        me->set_skill("lengquan-force", level+random(16));
        me->set_skill("literate", 180);
        me->set_skill("baguazhou", level+20+random(16));
        me->map_skill("spells", "baguazhou");
        me->map_skill("force", "lengquan-force");
        me->map_skill("unarmed", "changquan");
        me->map_skill("spear", "bawang-qiang");
        me->map_skill("parry", "bawang-qiang");
        me->map_skill("dodge", "yanxing-steps");
        me->set("force_factor", query_skill("force") );
        me->set("mana_factor", query_skill("spells",1));
        me->set("chat_msg_combat", ({

        (: perform_action,"spear", "ba" :),

        }) );
       me->carry_object("/d/obj/armor/jinjia.c")->wear();
       me->carry_object("d/obj/stey/shenspear.c")->wield();
}



 
