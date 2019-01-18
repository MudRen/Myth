
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
        
        create_family("��˿��", 3, "����");
        me->set_skill("unarmed", guai_value+random(i));
        me->set_skill("dodge", guai_value+random(i));
        me->set_skill("parry", guai_value+random(i));
        me->set_skill("force", guai_value+random(i));
        me->set_skill("spells", guai_value+random(i));
        me->set_skill("whip",guai_value+random(i)); 
                me->set_skill("sword",guai_value+random(i)); 
        
        me->set_skill("yinsuo-jinling", guai_value+random(i));
        me->set_skill("qingxia-jian", guai_value+random(i));        
        me->set_skill("spells",guai_value+random(i));
        me->set_skill("yueying-wubu",guai_value+random(i));
        me->set_skill("pansi-dafa", guai_value+random(i));
        me->set_skill("unarmed", guai_value+random(i));        
        me->set_skill("lanhua-shou", guai_value+random(i));
        me->set_skill("jiuyin-xinjing", guai_value+random(i)); 

        me->map_skill("force", "jiuyin-xinjing");
        me->map_skill("whip", "yinsuo-jinling");  
                me->map_skill("sword", "qingxia-jian");
        me->map_skill("parry", "qingxia-jian");
        me->map_skill("spells", "pansi-dafa");
        me->map_skill("dodge", "yueying-wubu");
        me->map_skill("unarmed", "lahua-shou");

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        (: perform_action,"whip", "wangling" :),
        (: perform_action,"whip", "tian" :),
        (: cast_spell, "wuzhishan" :),
        (: perform_action,"unarmed", "juehu" :),        
        }) );        
        weapon=new("/d/pansi/obj/yinsuo");
        weapon->move(me);
        
        command("wield all");
        carry_object("/d/obj/armor/jinjia.c")->wear();
}

