

#include <ansi.h>
inherit NPC;

void create()
{
        string weapon;

        set_name("妖兵", ({ "yao bing", "bing" }));
        set("gender", "男性" );//性别与上面对应
        set("family/family_name","大雪山");
        set("long",
"一个妖魔所幻化的丑陋怪物。\n");
        set("attitude", "aggressive");
        set("shen_type", 1);
        set("vendetta/authority",1);
        set("nickname",HIC"妖气冲天"NOR);
        set("force_factor",100+random(90));
        set("mana_factor",100+random(90));
        set("max_kee",6000+random(2000));
        set("max_sen",6000+random(2000));
        set("max_force",10000+random(1500));
        set("force",20000+random(1500));
        set("mana",20000+random(1500));
        set("max_mana",10000+random(1500));
        set("per", 21);
        set("age", 22);
        set("int", 40);
        set("daoxing", 1000000+random(450000));
        set("combat_exp", 1000000+random(450000));
        set("bellicosity", 300);
        set("chat_chance_combat", 160);
        set("chat_msg_combat", ({
                (: perform_action, "blade", "yaowu" :),
                (: perform_action, "blade", "bing" :),
                (: perform_action, "sword", "feijian" :),
                (: perform_action, "sword", "zheng" :),
                (: perform_action, "sword", "chaofeng" :),
                (: cast_spell, "bingfeng" :),
                (: cast_spell, "juanbi" :),
                (: cast_spell, "tuntian" :),
        }) );
        set("chat_chance", 5);
        set("chat_msg", ({
                "妖兵喝道：杀啊！！冲啊！！\n",
                "妖兵笑道：这次一定要占领天宫！！\n",
                (: random_move :),
        }) );

        set_skill("force", 100+random(100));
        set_skill("unarmed", 100+random(100));
        set_skill("blade", 100+random(100));
        set_skill("parry", 100+random(100));
        set_skill("dodge", 120+random(100));
        set_skill("spells", 100+random(100));
        set_skill("sword", 100+random(100));
        set_skill("throwing", 100+random(100));
        set_skill("bingpo-blade", 100+random(100));
        set_skill("bainiao-jian", 100+random(100));
        set_skill("ningxie-force", 100+random(100));
        set_skill("dengxian-dafa", 100+random(100));
        set_skill("xiaoyaoyou", 120+random(100));
        
        map_skill("blade", "bingpo-blade");
        map_skill("parry", "bingpo-blade");
        map_skill("force", "ningxie-force");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("spells", "dengxian-dafa");
        map_skill("sword", "bainiao-jian");
        map_skill("throwing", "bainiao-jian");
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 20);
        set_temp("apply/damage", 20);
if (random(20)>15)
{
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);
}

        setup();
        weapon = random(2)?"/d/obj/weapon/blade/iceblade":"/d/obj/weapon/sword/qinghong";
        carry_object(weapon)->wield();
        carry_object("d/obj/armor/yinjia")->wear();
        add_money("silver", 50);
}
void init( )
{
        call_out("hunting",180);
}

void hunting()
{
        object ob=this_object();
        write(HIW"只听天空之中传来三声令响！妖兵撤回了魔界！\n"NOR);
        destruct(ob);
}

void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
        if (me)
        {
                message_vision(WHT"$N大叫一声,我命休矣！倒地而亡。\n"NOR,ob,me);
                if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
                corpse->move(environment(this_object()));
                if((int)me->query("combat_exp") < 600000)   {
                    message("vision", me->name() + "由于成功的保卫了天宫,增加了300经验,二百天道行和100潜能。\n", me);
                    me->add("combat_exp",300);
                    me->add("daoxing",800);
                    me->add("potential",100);
                    destruct(ob);
        }
        message("vision", me->name() + HIG"成功的保卫了天宫。\n"NOR, me);
        me->add("weiwang",1);
        
}
        destruct(ob);
        return;
}

