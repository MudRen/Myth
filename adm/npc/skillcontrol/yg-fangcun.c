 
//stey
inherit NPC;  
#include <command.h> 

void create() { seteuid(getuid());}  
 
 
 
 
void set_skills(int level,object me) 
{ 
         
         int i = 50; 
         object weapon;      
         
       
        me->create_family("����ɽ���Ƕ�", 3, "����");  
         
        me->set_skill("unarmed", level+random(i)); 
        me->set_skill("dodge", level+random(i)); 
        me->set_skill("parry", level+random(i)); 
        me->set_skill("force", level+random(i)); 
        me->set_skill("spells", level+random(i)); 
  
        me->set_skill("stick", level+random(i)); 
        me->set_skill("qianjun-bang", level+random(i)); 
        me->set_skill("jindouyun", level+random(i)); 
        me->set_skill("wuxiangforce", level+random(i)); 
        me->set_skill("puti-zhi", level+random(i)); 
        me->set_skill("dao", level+random(i)); 
 
        me->map_skill("force", "wuxiangforce"); 
        me->map_skill("stick","qianjun-bang"); 
        me->map_skill("parry", "qianjun-bang"); 
        me->map_skill("spells", "dao"); 
        me->map_skill("dodge", "jindouyun"); 
        me->map_skill("unarmed", "puti-zhi"); 
 
        me->set("chat_chance_combat", 20); 
        me->set("chat_msg_combat", ({ 
        (: exert_function, "jldl" :), 
        (: perform_action,"stick", "pili" :), 
        (: perform_action,"stick","qiankun" :), 
        (: cast_spell, "thunder" :), 
        (: cast_spell, "light" :), 
        (: cast_spell, "dingshen" :), 
        (: perform_action,"unarmed", "jingmo" :), 
        }) ); 
 
        weapon=new("/d/obj/weapon/stick/xiangmo"); 
        weapon->move(me); 
        me->command("wield all"); 
        me->carry_object("/d/obj/armor/jinjia.c")->wear(); 
} 
 
 
