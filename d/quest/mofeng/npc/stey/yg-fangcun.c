
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
        
        create_family("����ɽ���Ƕ�", 3, "����"); 
        
        me->set_skill("unarmed", guai_value+random(i));
        me->set_skill("dodge", guai_value+random(i));
        me->set_skill("parry", guai_value+random(i));
        me->set_skill("force", guai_value+random(i));
        me->set_skill("spells", guai_value+random(i));
 
        me->set_skill("stick", guai_value+random(i));
        me->set_skill("qianjun-bang", guai_value+random(i));
        me->set_skill("jindouyun", guai_value+random(i));
        me->set_skill("wuxiangforce", guai_value+random(i));
        me->set_skill("puti-zhi", guai_value+random(i));
        me->set_skill("dao", guai_value+random(i));

        me->map_skill("force", "wuxiangforce");
        me->map_skill("stick","qianjun-bang");
        me->map_skill("parry", "qianjun-bang");
        me->map_skill("spells", "dao");
        me->map_skill("dodge", "jindouyun");
        me->map_skill("unarmed", "puti-zhi");

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        (: exert_function, "jldl" :),
        (: perform_action,"stick", "pili" :),
        (: perform_action,"stick","qiankun" :),
        (: cast_spell, "thunder" :),
        (: cast_spell, "light" :),
        (: cast_spell, "dingshen" :),
        (: perform_action,"unarmed", "jingmo" :),
        }) );

        weapon=new("/d/obj/weapon/stick/xiangmo");
        weapon->move(me);
        command("wield all");
        carry_object("/d/obj/armor/jinjia.c")->wear();
}


