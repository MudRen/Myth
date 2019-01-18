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
        
        create_family("�Ϻ�����ɽ", 3, "����"); 
        me->set_skill("unarmed", guai_value+random(i));
        me->set_skill("dodge", guai_value+random(i));
        me->set_skill("parry", guai_value+random(i));
        me->set_skill("force", guai_value+random(i));
        me->set_skill("spells", guai_value+random(i));
 
        me->set_skill("staff", guai_value+random(i));
        me->set_skill("lunhui-zhang", guai_value+random(i));
        me->set_skill("lotusmove", guai_value+random(i));
        me->set_skill("buddhism", guai_value+random(i));
        me->set_skill("jienan-zhi", guai_value+random(i));
        me->set_skill("lotusforce", guai_value+random(i));

        me->map_skill("force", "lotusforce");
        me->map_skill("staff", "lunhui-zhang");
        me->map_skill("parry", "lunhui-zhang");
        me->map_skill("spells", "buddhism");
        me->map_skill("dodge", "lotusmove");
        me->map_skill("unarmed", "jienan-zhi");

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        (: cast_spell, "bighammer" :),
        (: perform_action,"staff", "pudu" :),   
        (: perform_action,"staff", "chaodu" :), 
        (: perform_action,"unarmed", "storm" :),        
        }) );

        weapon=new("/d/obj/weapon/staff/budd_staff");
        weapon->move(me);
        
        command("wield all");
        carry_object("/d/obj/armor/jinjia.c")->wear();
}

