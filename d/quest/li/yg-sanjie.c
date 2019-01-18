//modified by vikee
//2000-12-9 23:34



inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

        set("title","����ɽ");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);

        me->set_skill("zhaoyangbu",j+random(15));
        me->set_skill("sword",j+random(15));
        me->set_skill("huxiaojian",j+random(15));
        me->set_skill("unarmed",j+random(15));
        me->set_skill("huxiaoquan",j+random(15));
        me->set_skill("liushenjue",j+random(15));
        me->set_skill("tianyaofa",j+random(15));
        me->set_skill("huntianforce",j+random(15));
        me->set_skill("tianmogong",j+random(15));
        me->set_skill("blade",j+random(15));
        me->set_skill("zileidao",j+random(15));
        me->set_skill("zhaoyangbu",j+random(15));
            
        me->map_skill("force", "huntianforce");
        me->map_skill("sword", "huxiaojian");
        me->map_skill("blade","zileidao");
        me->map_skill("parry", "zileidao");
        me->map_skill("spells", "tianyaofa");
        me->map_skill("dodge", "zhaoyangbu");
        me->map_skill("unarmed", "huxiaoquan");

        set("chat_chance_combat", cast_chance(level));
        set("chat_msg_combat", ({
        (: perform_action,"blade", "tulong" :),	
        (: perform_action,"sword", "pili" :),
        (: cast_spell, "zhui" :),
        (: cast_spell, "sishi" :),        
        }) );

        if (random(2))
           weapon=new("/d/obj/weapon/blade/jindao");
        else
           weapon=new("/d/obj/weapon/sword/qingfeng");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}
