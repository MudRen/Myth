
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
        
        create_family("�ݿ�ɽ�޵׶�", 3, "����"); 
        me->set_skill("unarmed", guai_value+random(i));
        me->set_skill("dodge", guai_value+random(i));
        me->set_skill("parry", guai_value+random(i));
        me->set_skill("force", guai_value+random(i));
        me->set_skill("spells", guai_value+random(i));
 
        me->set_skill("blade", guai_value+random(i));
        me->set_skill("kugu-blade", guai_value+random(i));
        me->set_skill("sword",guai_value+random(i));
        me->set_skill("qixiu-jian",guai_value+random(i));
        me->set_skill("lingfu-steps", guai_value+random(i));
        me->set_skill("yaofa", guai_value+random(i));
        me->set_skill("huntian-qigong", guai_value+random(i));
        me->set_skill("yinfeng-zhua", guai_value+random(i));

        me->map_skill("force", "huntian-qigong");
        me->map_skill("blade", "kugu-blade");
        me->map_skill("sword","qixiu-jian");
        me->map_skill("parry", "kugu-blade");
        me->map_skill("spells", "yaofa");
        me->map_skill("dodge", "kugu-blade");
        me->map_skill("unarmed", "yinfeng-zhua");

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        (: perform_action,"blade", "diyu" :),
        (: cast_spell, "tudun" :),
        (: perform_action,"blade", "pozhan" :),
        (: perform_action,"blade", "sword" :),
        (: exert_function, "zhangqi" :),
 //       (: perform_action,"unarmed", "duo" :),
        (: perform_action,"unarmed", "duzun" :),
        }) );

        weapon=new("/d/obj/weapon/blade/jindao");
        weapon->move(me);
       
        command("wield all");
        carry_object("/d/obj/armor/jinjia.c")->wear();
}

