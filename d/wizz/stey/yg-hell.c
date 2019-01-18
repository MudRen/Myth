
// tomcat

inherit __DIR__"guai.c";



void set_skills(int max_value, int level)
{
         int guai_value;
         int i = 50;
         object weapon;
         object me = this_object();
         
        ::set_skills(max_value, level);
        
        if (level==1) guai_value = max_value+max_value/8;
        else if (level==2) guai_value = max_value+max_value/6;
        else guai_value = max_value+max_value/4;
        
        create_family("���޵ظ�", 2, "����"); 
        
        me->set_skill("unarmed", guai_value+random(i));
        me->set_skill("dodge", guai_value+random(i));
        me->set_skill("parry", guai_value+random(i));
        me->set_skill("force", guai_value+random(i));
        me->set_skill("spells", guai_value+random(i));
 
        me->set_skill("whip", guai_value+random(i));
        me->set_skill("hellfire-whip", guai_value+random(i));
        me->set_skill("stick",guai_value+random(i));
        me->set_skill("kusang-bang",guai_value+random(i));
        me->set_skill("ghost-steps", guai_value+random(i));
        me->set_skill("jinghun-zhang", guai_value+random(i));
        me->set_skill("tonsillit", guai_value+random(i));
        me->set_skill("gouhunshu", guai_value+random(i));

        me->map_skill("force", "tonsillit");
         me->map_skill("whip", "hellfire-whip");
        me->map_skill("stick","kusang-bang");
        me->map_skill("parry", "kusang-bang");
        me->map_skill("spells", "gouhunshu");
        me->map_skill("dodge", "ghost-steps");
        me->map_skill("unarmed", "jinghun-zhang");

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        (: perform_action,"whip", "three" :),
        (: cast_spell, "gouhun" :),
        (: perform_action,"unarmed", "zhua" :),
        }) );

        weapon=new("/d/obj/weapon/whip/tielian");
        weapon->move(me);
        carry_object("/d/obj/armor/jinjia.c")->wear();
      
        command("wield all");
}

