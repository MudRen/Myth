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
        
               
        create_family("��������", 2, "ˮ��");
        set("lg",1);
        me->set_skill("unarmed", guai_value+random(i));
        me->set_skill("dodge", guai_value+random(i));
        me->set_skill("parry", guai_value+random(i));
        me->set_skill("force", guai_value+random(i));
        me->set_skill("spells", guai_value+random(i));
 
        me->set_skill("fork", guai_value+random(i));
        me->set_skill("fengbo-cha", guai_value+random(i));
        me->set_skill("hammer",guai_value+random(i));
        me->set_skill("huntian-hammer",guai_value+random(i));
        me->set_skill("dragonstep", guai_value+random(i));
        me->set_skill("dragonfight", guai_value+random(100));
        me->set_skill("dragonforce", guai_value+random(i));
        me->set_skill("seashentong", guai_value+random(i));

        me->map_skill("force", "dragonforce");
        me->map_skill("fork", "fengbo-cha");
        me->map_skill("hammer","huntian-hammer");
        me->map_skill("parry", "huntian-hammer");
        me->map_skill("spells", "seashentong");
        me->map_skill("dodge", "dragonstep");
        me->map_skill("unarmed", "dragonfight");

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: perform_action,"unarmed", "sheshen" :),
        (: cast_spell, "dragonfire" :),
        (: cast_spell, "freez" :),
        (: cast_spell, "shuidun" :),
        (: exert_function, "roar" :),
        (: exert_function, "shield" :),

        }) );
        carry_object("/d/obj/armor/jinjia.c")->wear();

}

