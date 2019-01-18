

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��", ({ "gui jiang", "jiang" }));
        set("gender", "����" );//�Ա��������Ӧ
        set("long",
"һ��������ʮ�˵����Ķ����ħ������ΪСС���졣\n");
        set("family/family_name","���޵ظ�");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
        set("title",HIW"ħ��С��"NOR);
        set("nickname",HIB"�����˼�"NOR);
        set("force_factor",100+random(180));
        set("mana_factor",100+random(180));
        set("max_kee",9000+random(3000));
        set("max_sen",1000+random(990));
        set("max_force",20000+random(5000));
        set("max_mana",20000+random(5000));
        set("force",25000+random(3000));
        set("mana",2500+random(5900));
        set("per", 1);
        set("int", 60);
        set("age", 56);
        set("combat_exp", 5000000+random(2000000));
        set("daoxing", 5000000+random(2000000));
        set("chat_chance_combat", 160);
        set("chat_msg_combat", ({
                (: perform_action, "whip", "biluo" :),
                (: perform_action, "whip", "yanluo" :),
                (: perform_action, "whip", "three" :),
                (: cast_spell, "gouhun" :),
                (: cast_spell, "zhuang" :),
                (: cast_spell, "hunfei" :),
                (: cast_spell, "inferno" :),
        }) );
        set("chat_chance", 5);
        set("chat_msg", ({
                "�����ȵ���ɱ������\n",
                "����Ц�������һ��Ҫ�����칬���ɣ�\n",
                (: random_move :),
        }) );

        set_skill("unarmed", 150+random(150));
        set_skill("whip", 150+random(150));
        set_skill("parry", 150+random(150));
        set_skill("dodge", 150+random(150));
        set_skill("jinghun-zhang", 150+random(150));
        set_skill("hellfire-whip", 150+random(150));
        set_skill("ghost-steps", 150+random(150));
        set_skill("zhuihun-sword", 150+random(150));
        set_skill("kusang-bang", 150+random(150));
        set_skill("force", 150+random(150));
        set_skill("spells", 150+random(150));
        set_skill("gouhunshu", 150+random(150));
        set_skill("tonsillit", 150+random(150));

        map_skill("whip", "hellfire-whip");
        map_skill("parry", "hellfire-whip");
        map_skill("unarmed", "jinghun-zhang");
        map_skill("dodge", "ghost-steps");
        map_skill("force", "tonsillit");
        map_skill("spells", "gouhunshu");
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);

if (random(20)>15)
{
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
}

        setup();

        carry_object("d/obj/armor/yinjia")->wear();
        carry_object("d/obj/weapon/whip/fuchen")->wield();
        add_money("silver", 50);
}
void init( )
{
        call_out("hunting",180);
}

void hunting()
{
        object ob=this_object();
        write(HIW"ֻ�����ϴ����������죡ħ����������칬��\n"NOR);
        destruct(ob);
}

void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
        if (me)
        {    
             message_vision(WHT"$N���һ��,�������ӣ����ض�����\n"NOR,ob,me);
             if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
             corpse->move(environment(this_object()));
             if((int)me->query("combat_exp") < 2000000)   
             {
                 message("vision", me->name() + HIG"���ڳɹ��ı������칬,������400����,һ����к�200Ǳ�ܡ�\n"NOR, me);
                 me->add("combat_exp",400);
                 me->add("daoxing",1000);
                 me->add("potential",200);
                 destruct(ob);
             }
             message("vision", me->name() + HIG"�ɹ��ı������칬��\n"NOR, me);
             me->add("weiwang",1);
        
        }
        destruct(ob);
        return;
}

