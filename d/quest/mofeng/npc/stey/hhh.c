 
 
inherit NPC;
#include <command.h> 
 
void create() { seteuid(getuid());}  
 
 
 
 
void set_skills(int level,object me) 
{ 
         int levele; 
         int i = 50; 
         object weapon;                 
                                        
                                        
       
         
        
         
        me->create_family("���޵ظ�", 2, "����");  
         
        me->set_skill("unarmed", levele+random(i)); 
        me->set_skill("dodge", levele+random(i)); 
        me->set_skill("parry", levele+random(i)); 
        me->set_skill("force", levele+random(i)); 
        me->set_skill("spells", levele+random(i)); 
  
        me->set_skill("whip", levele+random(i)); 
        me->set_skill("hellfire-whip", levele+random(i)); 
        me->set_skill("stick",levele+random(i)); 
        me->set_skill("kusang-bang",levele+random(i)); 
        me->set_skill("ghost-steps", levele+random(i)); 
        me->set_skill("jinghun-zhang", levele+random(i)); 
        me->set_skill("tonsillit", levele+random(i)); 
        me->set_skill("gouhunshu", levele+random(i)); 
 
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
