inherit __DIR__"fei.c";


void set_skills()
{
        object me=this_object();
        object weapon;
        int j;
        j= 200+random(150);  
        create_family("��ԯ��Ĺ", 3, "����");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
        me->set_skill("blade",j); 
                me->set_skill("sword",j); 
        
        me->set_skill("qinghu-jian", j+random(15));
        me->set_skill("zizhi-blade", j+random(15));        
        me->set_skill("spells",j+random(15));
        me->set_skill("kongming-steps",j+random(15));
        me->set_skill("youming-spells", j+random(15));
        me->set_skill("unarmed", j+random(15));        
        me->set_skill("jiuyin-zhua", j+random(15));
        me->set_skill("jiuyin-force", j+random(15)); 

        me->map_skill("force", "jiuyin-force");
        me->map_skill("sword", "qinghu-jian");  
                me->map_skill("blade", "zizhi-blade");
        me->map_skill("parry", "qinghu-blade");
        me->map_skill("spells", "youming-spells");
        me->map_skill("dodge", "kongming-steps");
        me->map_skill("unarmed", "jiuyin-zhua");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: perform_action,"sword", "hebi" :),
        (: cast_spell, "feng" :),
        (: cast_spell, "mei" :),
        }) );        
        weapon=new("/d/obj/weapon/sword/xuanyuan-sword.c");
        weapon->move(me);
        
        command("wield all");
}
