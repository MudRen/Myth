
#include <ansi.h>
inherit NPC;

string *name =({
       "��ħ��",
       "��ħ��",
       "��ħ��",
});

void create()
{        
        string weapon;
        set_name(name[random(sizeof(name))], ({ "mo wang", "mowang" }));
        set("gender", "����" );//�Ա��������Ӧ
        set("long",
"����ħ��ͳ������������ħ����������ǿ�������ѵС�\n");
        set("family/family_name","���ƶ�");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
        set("title",HIC"ħ������"NOR);
        set("nickname",HIR"�����ħ֮"NOR);
        set("force_factor",300+random(200));
        set("mana_factor",350+random(180));
        set("max_kee",15000+random(3000));
        set("max_sen",12000+random(3000));
        set("max_force",30000+random(5000));
        set("max_mana",30000+random(5000));
        set("force",60000+random(3000));
        set("mana",4500+random(5900));
        set("per", 30);
        set("int", 60);
        set("age", 206);
        set("combat_exp", 40000000+random(20000000));
        set("daoxing", 40000000+random(20000000));
        set("chat_chance_combat", 160);
        set("chat_msg_combat", ({
                (: perform_action, "spear", "buhui" :),
                (: perform_action, "spear", "qianghun" :),
                (: perform_action, "spear", "fengchan" :),
                (: perform_action, "stick", "tmzx" :),
                (: perform_action, "stick", "qzld" :),
                (: perform_action, "stick", "shenli" :), 
                (: perform_action, "unarmed", "zhangxinlei" :), 
                (: cast_spell, "yan" :),
                (: cast_spell, "niushi" :),
                (: cast_spell, "zhuang" :),                
        }) );
        set("chat_chance", 5);
        set("chat_msg", ({
                "ħ�����ȵ���ɱ������\n",
                "ħ����Ц������ζ�Ҫ������϶���������\n",
                (: random_move :),
        }) );

        set_skill("unarmed", 350+random(150));
        set_skill("spear", 350+random(150));
        set_skill("parry", 350+random(150));
        set_skill("dodge", 350+random(150));
        set_skill("stick", 350+random(150));
        set_skill("moyun-shou", 350+random(150));
        set_skill("wuyue-spear", 350+random(150));
        set_skill("moshenbu", 350+random(150));
        set_skill("dali-bang", 350+random(150));
        set_skill("literate", 350+random(150));
        set_skill("force", 350+random(150));
        set_skill("spells", 350+random(150));
        set_skill("huomoforce", 350+random(150));
        set_skill("pingtian-dafa", 350+random(150));

        map_skill("spear", "wuyue-spear");
        map_skill("parry", "wuyue-spear");
        map_skill("unarmed", "moyun-shou");
        map_skill("dodge", "moshenbu");
        map_skill("force", "huomoforce");
        map_skill("spells", "pingtian-dafa");
        map_skill("stick", "dali-bang");
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
        weapon = random(2)?"/d/npc/obj/stick":"/d/obj/weapon/spear/huaji2";
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
        write(HIW"ֻ�����ϴ����������죡ħ������ħ���������칬��\n"NOR);
        destruct(ob);
}

void die()
{
        object ob, obn, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
        if (me)
        {    
             message_vision(WHT"$N���һ��,ħ�����꣡˵��㵹�ض�����\n"NOR,ob,me);
             if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
             corpse->move(environment(this_object()));
             message("vision", me->name() + "��ħ�����Ϸ����˴����Ļƽ�\n", me);
             obn=new("/d/obj/money/gold");
             obn->set_amount(5+random(10));
             obn->move(me);

             if((int)me->query("combat_exp") < 25000000)   
             {
                 message("vision", me->name() + HIG"���ڳɹ��ı������칬,������3000����,������к�1000Ǳ�ܡ�\n"NOR, me);
                 me->add("combat_exp",3000);
                 me->add("daoxing",4000);
                 me->add("potential",1000);
                 destruct(ob);
             }
             message("vision", me->name() + HIG"�ɹ��ı������칬��\n"NOR, me);
             me->add("weiwang",1);
        
        }
        destruct(ob);
        return;
}

