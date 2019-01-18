
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
        
        create_family("��ɽ����", 3, "����"); 
        me->set_skill("unarmed", guai_value+random(i));
        me->set_skill("dodge", guai_value+random(i));
        me->set_skill("parry", guai_value+random(i));
        me->set_skill("force", guai_value+random(i));
        me->set_skill("spells", guai_value+random(i));
        me->set_skill("sword",guai_value+random(i)); 
        
        me->set_skill("yujianshu", guai_value+random(i));
        me->set_skill("mindsword", guai_value+random(i));        
        me->set_skill("spells",guai_value+random(i));
        me->set_skill("sevensteps",guai_value+random(i));
        me->set_skill("taoism", guai_value+random(i));
        me->set_skill("unarmed", guai_value+random(i));        
        me->set_skill("hunyuan-zhang", guai_value+random(i));
        me->set_skill("zixia-shengong", guai_value+random(i)); 

        me->map_skill("force", "zixia-shengong");
        me->map_skill("sword", "mindsword");        
        me->map_skill("parry", "mindsword");
        me->map_skill("spells", "taoism");
        me->map_skill("dodge", "sevensteps");
        me->map_skill("unarmed", "hunyuan-zhang");

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        (: perform_action,"sword", "jianqi" :),
        (: perform_action,"sword", "taohua" :),
        (: cast_spell, "jianshen" :),
        (: cast_spell, "shou" :),
        (: perform_action,"unarmed", "sword" :),
        }) );        
        weapon=new("/d/obj/weapon/sword/qingfeng");
        weapon->move(me);
     
        command("wield all");
        carry_object("/d/obj/armor/jinjia.c")->wear();
}

