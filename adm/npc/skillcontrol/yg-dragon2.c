//stey
inherit NPC;  
#include <command.h> 

void create() { seteuid(getuid());}  
 
 
 
 
void set_skills(int level,object me) 
{ 
         
         int i = 50; 
         object weapon;      
                
        me->create_family("��������", 2, "ˮ��"); 
        me->set_skill("unarmed", level+random(i)); 
        me->set_skill("dodge", level+random(i)); 
        me->set_skill("parry", level+random(i)); 
        me->set_skill("force", level+random(i)); 
        me->set_skill("spells", level+random(i)); 
  
        me->set_skill("fork", level+random(i)); 
        me->set_skill("fengbo-cha", level+random(i)); 
        me->set_skill("hammer",level+random(i)); 
        me->set_skill("huntian-hammer",level+random(i)); 
        me->set_skill("dragonstep", level+random(i)); 
        me->set_skill("dragonfight", level+random(i)); 
        me->set_skill("dragonforce", level+random(i)); 
        me->set_skill("seashentong", level+random(i)); 
 
        me->map_skill("force", "dragonforce"); 
        me->map_skill("fork", "fengbo-cha"); 
        me->map_skill("hammer","huntian-hammer"); 
        me->map_skill("parry", "huntian-hammer"); 
        me->map_skill("spells", "seashentong"); 
        me->map_skill("dodge", "dragonstep"); 
        me->map_skill("unarmed", "dragonfight"); 
 
        me->set("chat_chance_combat", 20); 
        me->set("chat_msg_combat", ({ 
        (: perform_action,"fork", "fengbo" :), 
    (: cast_spell, "dragonfire" :), 
        (: cast_spell, "freez" :), 
        (: exert_function, "roar" :), 
        (: exert_function, "shield" :), 
        (: perform_action,"unarmed", "sheshen" :), 
        }) ); 
 

           weapon=new("/d/obj/weapon/fork/gangcha"); 
        weapon->move(me); 
        me->command("wield all"); 
        me->carry_object("/d/obj/armor/jinjia.c")->wear(); 
} 
 
