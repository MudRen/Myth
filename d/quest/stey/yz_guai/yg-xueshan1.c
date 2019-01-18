
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
        
       
        create_family("��ѩɽ", 2, "����");
        me->set_skill("unarmed",  guai_value+random(i));
        me->set_skill("dodge",  guai_value+random(i));
        me->set_skill("parry",  guai_value+random(i));
        me->set_skill("force",  guai_value+random(i));
        me->set_skill("spells",  guai_value+random(i));
 
        me->set_skill("blade",  guai_value+random(i));
        me->set_skill("bingpo-blade",  guai_value+random(i));
        me->set_skill("xiaoyaoyou", guai_value+random(i));
        me->set_skill("dengxian-dafa", guai_value+random(i));
        me->set_skill("ningxie-force",  guai_value+random(i));
        me->set_skill("cuixin-zhang",  guai_value+random(i));

        me->map_skill("force", "ningxie-force");
        me->map_skill("blade", "bingpo-blade");
        me->map_skill("parry", "bingpo-blade");
        me->map_skill("spells", "dengxian-dafa");
        me->map_skill("dodge", "xiaoyaoyou");
        me->map_skill("unarmed", "cuixin-zhang");

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
           (: perform_action,"blade", "yaowu" :),
           (: perform_action,"blade", "xuan" :),
           (: cast_spell, "tuntian" :),
           (: cast_spell, "juanbi" :),

            }) );    
        weapon=new("/d/obj/weapon/blade/iceblade");
        weapon->move(me);
        command("wield all");
        carry_object("/d/obj/armor/jinjia.c")->wear();
}

