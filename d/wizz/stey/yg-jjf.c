
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
        
        create_family("������", 2, "����");
        me->set_skill("unarmed", guai_value+random(i));
        me->set_skill("dodge", guai_value+random(i));
        me->set_skill("parry", guai_value+random(i));
        me->set_skill("force", guai_value+random(i));
        me->set_skill("spells", guai_value+random(i));
 
        me->set_skill("spear", guai_value+random(i));
        me->set_skill("bawang-qiang", guai_value+random(i));
        me->set_skill("axe",guai_value+random(i));
        me->set_skill("sanban-axe",guai_value+random(i));
        me->set_skill("yanxing-steps",guai_value+random(i));
        me->set_skill("changquan", guai_value+random(i));
        me->set_skill("lengquan-force", guai_value+random(i));
        me->set_skill("baguazhou", guai_value+random(i));

        me->map_skill("force", "lengquan-force");
        me->map_skill("axe", "sanban-axe");
        me->map_skill("spear","bawang-qiang");
        me->map_skill("parry", "bawang-qiang");
        me->map_skill("spells", "baguazhou");
        me->map_skill("dodge", "yanxing-steps");
        me->map_skill("unarmed", "changquan");

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        (: exert_function, "powerup" :),
        (: perform_action,"axe", "sanban" :),
        (: perform_action,"axe", "kai" :),
        (: perform_action,"unarmed", "zhiqi" :),         
        }) );

        weapon=new("/d/obj/weapon/axe/huafu");
        weapon->move(me);
        
        command("wield all");
        carry_object("/d/obj/armor/jinjia.c")->wear();
}

