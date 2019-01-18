
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
        
        create_family("���ƶ�", 2, "����"); 
        me->set_skill("unarmed", guai_value+random(i));
        me->set_skill("dodge", guai_value+random(i));
        me->set_skill("parry", guai_value+random(i));
        me->set_skill("force", guai_value+random(i));
        me->set_skill("spells", guai_value+random(i));
 
        me->set_skill("spear", guai_value+random(i));
        me->set_skill("huoyun-qiang", guai_value+random(i));
        me->set_skill("moyun-shou",guai_value+random(i));
        me->set_skill("moshenbu",guai_value+random(i));
        me->set_skill("huomoforce", guai_value+random(i));
        me->set_skill("pingtian-dafa", guai_value+random(i));
        me->set_skill("dali-bang", guai_value+random(i));
        me->set_skill("stick", guai_value+random(i));

        me->map_skill("force", "huomoforce");
        me->map_skill("spear", "huoyun-qiang");
        me->map_skill("stick","dali-bang");
        me->map_skill("parry", "dali-bang");
        me->map_skill("spells", "pingtian-dafa");
        me->map_skill("dodge", "moshenbu");
        me->map_skill("unarmed", "moyun-shou");

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
 //       (: cast_spell, "sanmei" :),
 //       (: perform_action,"spear", "huohun" :),
        (: perform_action,"spear", "lihuo" :),
        (: perform_action,"unarmed", "zhangxinlei" :),
        }) );

        weapon=new("/d/obj/weapon/spear/jinqiang");
        weapon->move(me);
        command("wield all");
        carry_object("/d/obj/armor/jinjia.c")->wear();
}

