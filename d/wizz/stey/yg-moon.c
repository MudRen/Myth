
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
        
        create_family("�¹�", 3, "����");
        set("gender", "Ů��");
        me->set_skill("unarmed", guai_value+random(i));
        me->set_skill("dodge", guai_value+random(i));
        me->set_skill("parry", guai_value+random(i));
        me->set_skill("force", guai_value+random(i));
        me->set_skill("spells", guai_value+random(i));
 
        me->set_skill("whip", guai_value+random(i));
        me->set_skill("jueqingbian", guai_value+random(i));
        me->set_skill("sword",guai_value+random(i));
        me->set_skill("snowsword",guai_value+random(i));
        me->set_skill("moondance", guai_value+random(i));
        me->set_skill("moonshentong", guai_value+random(i));
        me->set_skill("baihua-zhang", guai_value+random(i));
        me->set_skill("moonforce", guai_value+random(i));

        me->map_skill("force", "moonforce");
        me->map_skill("sword", "snowsword");
        me->map_skill("whip","jueqingbian");
        me->map_skill("parry", "jueqingbian");
        me->map_skill("spells", "moonshentong");
        me->map_skill("dodge", "moondance");
        me->map_skill("unarmed", "baihua-zhang");

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        (: cast_spell, "arrow" :),
//       (: cast_spell, "shiyue" :),
        (: perform_action,"sword", "tian" :),  
        (: perform_action,"sword", "hanyue" :),  
        (: perform_action,"unarmed", "flower" :),        
       
        }) );

          weapon=new("/d/moon/obj/snow_sword");
        weapon->move(me);
        
        command("wield all");
        carry_object("/d/obj/armor/jinjia.c")->wear();
}

