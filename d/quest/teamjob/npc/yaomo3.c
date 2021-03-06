
#include <ansi.h>
inherit NPC;

string *name =({
       "混世魔",
       "吸血狂魔",
       "剑魔",
       "风魔",
       "飞羽奇魔",
       "灵幻神魔",
       "梦魔",
       "心魔",
});

void create()
{        
        string weapon;
        set_name(name[random(sizeof(name))], ({ "mo shuai", "shuai" }));
        set("gender", "男性" );//性别与上面对应
        set("long",
"他是魔界中数位魔帅之一。\n");
        set("family/family_name","三界山");
        set("class","sanjie");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
        set("title",HIR"魔帅"NOR);
        set("nickname",HIY"群魔乱舞"NOR);
        set("force_factor",150+random(180));
        set("mana_factor",150+random(180));
        set("max_kee",9000+random(3000));
        set("max_sen",8000+random(3000));
        set("max_force",20000+random(5000));
        set("max_mana",20000+random(5000));
        set("force",25000+random(3000));
        set("mana",2500+random(5900));
        set("per", 10);
        set("int", 60);
        set("age", 106);
        set("combat_exp", 10000000+random(5000000));
        set("daoxing", 10000000+random(5000000));
        set("chat_chance_combat", 160);
        set("chat_msg_combat", ({
                (: perform_action, "blade", "leihuo" :),
                (: perform_action, "blade", "tulong" :),
                (: perform_action, "blade", "rimu" :),
                (: perform_action, "sword", "sixiao" :),
                (: perform_action, "sword", "chan" :),
                (: perform_action, "sword", "leihua" :), 
                (: perform_action, "unarmed", "liushen" :),
                (: exert_function, "daozhuan" :), 
                (: cast_spell, "zhui" :),
                (: cast_spell, "wanying" :),                
        }) );
        set("chat_chance", 5);
        set("chat_msg", ({
                "魔帅长喝道：杀啊！！\n",
                "魔帅长笑道：不占领天宫誓不罢休！\n",
                (: random_move :),
        }) );

        set_skill("unarmed", 250+random(150));
        set_skill("blade", 250+random(150));
        set_skill("parry", 250+random(150));
        set_skill("dodge", 250+random(150));
        set_skill("sword", 250+random(150));
        set_skill("liushenjue", 250+random(150));
        set_skill("zileidao", 250+random(150));
        set_skill("zhaoyangbu", 250+random(150));
        set_skill("huxiaojian", 250+random(150));
        set_skill("huxiaoquan", 250+random(150));
        set_skill("force", 250+random(150));
        set_skill("spells", 250+random(150));
        set_skill("huntianforce", 250+random(150));
        set_skill("tianmogong", 250+random(150));

        map_skill("blade", "zileidao");
        map_skill("parry", "zileidao");
        map_skill("unarmed", "liushenjue");
        map_skill("dodge", "zhaoyangbu");
        map_skill("force", "huntianforce");
        map_skill("spells", "tianmogong");
        map_skill("sword", "huxiaojian");
        add_temp("apply/attack", 100);
        add_temp("apply/defense", 100);
        add_temp("apply/armor", 200);
        add_temp("apply/damage", 100);

if (random(20)>15)
{
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
}

        setup();
        weapon = random(2)?"/d/sanjie/obj/leidao":"/d/obj/weapon/sword/qinghong";
        carry_object("d/obj/armor/jinjia")->wear();
        carry_object(weapon)->wield();
        add_money("silver", 50);
}
void init( )
{
        call_out("hunting",180);
}

void hunting()
{
        object ob=this_object();
        write(HIW"只听天上传来三声令响！魔界魔帅撤出了天宫！\n"NOR);
        destruct(ob);
}

void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
        if (me)
        {    
             message_vision(WHT"$N大叫一声,我虽死了，但魔界绝不会就此罢休！\n"NOR,ob,me);
             if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
             corpse->move(environment(this_object()));
             if((int)me->query("combat_exp") < 5500000)   
             {
                 message("vision", me->name() + HIG"由于成功的保卫了天宫,增加了1500经验,两年道行和500潜能。\n"NOR, me);
                 me->add("combat_exp",1500);
                 me->add("daoxing",2000);
                 me->add("potential",500);
                 destruct(ob);
             }
             message("vision", me->name() + HIG"成功的保卫了天宫。\n"NOR, me);
             me->add("weiwang",1);
        
        }
        destruct(ob);
        return;
}

