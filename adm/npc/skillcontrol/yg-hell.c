 

inherit NPC;  
#include <command.h> 

void create() { seteuid(getuid());}  
 
 
 
 
void set_skills(int level,object me) 
{ 
       
         int i = 50; 
         object weapon;                 
                                        
                                        
       
         
        
         
        me->create_family("���޵ظ�", 2, "����");  
         
        me->set_skill("unarmed", level+random(i)); 
        me->set_skill("dodge", level+random(i)); 
        me->set_skill("parry", level+random(i)); 
        me->set_skill("force", level+random(i)); 
        me->set_skill("spells", level+random(i)); 
  
        me->set_skill("whip", level+random(i)); 
        me->set_skill("hellfire-whip", level+random(i)); 
        me->set_skill("stick",level+random(i)); 
        me->set_skill("kusang-bang",level+random(i)); 
        me->set_skill("ghost-steps", level+random(i)); 
        me->set_skill("jinghun-zhang", level+random(i)); 
        me->set_skill("tonsillit", level+random(i)); 
        me->set_skill("gouhunshu", level+random(i)); 
 
        me->map_skill("force", "tonsillit"); 
         me->map_skill("whip", "hellfire-whip"); 
        me->map_skill("stick","kusang-bang"); 
        me->map_skill("parry", "kusang-bang"); 
        me->map_skill("spells", "gouhunshu"); 
        me->map_skill("dodge", "ghost-steps"); 
        me->map_skill("unarmed", "jinghun-zhang"); 
 
        me->set("chat_chance_combat", 20); 
        me->set("chat_msg_combat", ({ 
        (: perform_action,"whip", "three" :), 
        (: cast_spell, "gouhun" :), 
        (: perform_action,"unarmed", "zhua" :), 
        }) ); 
 
        weapon=new("/d/obj/weapon/whip/tielian"); 
        weapon->move(me); 
        me->carry_object("/d/obj/armor/jinjia.c")->wear(); 
       
        me->command("wield all");
}
