//created by vikee
//2000-12-9 23:35

inherit __DIR__"yaoguai.c";


void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

        me->set("title","��ɽ��ħ");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
        me->set_skill("sword",j); 
        
        me->set_skill("yujianshu", j+random(15));
	me->set_skill("mindsword", j+random(15));        
        me->set_skill("spells",j+random(15));
        me->set_skill("sevensteps",j+random(15));
        me->set_skill("taoism", j+random(15));
        me->set_skill("unarmed", j+random(15));        
        me->set_skill("hunyuan-zhang", j+random(15));
        me->set_skill("zixia-shengong", j+random(15)); 

        me->map_skill("force", "zixia-shengong");
        me->map_skill("sword", "mindsword");        
        me->map_skill("parry", "mindsword");
        me->map_skill("spells", "taoism");
        me->map_skill("dodge", "sevensteps");
        me->map_skill("unarmed", "hunyuan-zhang");

	set("chat_chance_combat", cast_chance(level));
        set("chat_msg_combat", ({
        (: perform_action,"sword", "fenguang" :),
        (: cast_spell, "jianshen" :),
        }) );        
        weapon=new("/d/obj/weapon/sword/qingfeng");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}
