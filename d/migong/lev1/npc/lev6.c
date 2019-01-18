// migong lev1

#include <ansi.h>

inherit NPC;

string *names = ({
    "������",
    "��Ѫ����",
    "������",
    "������",
});

void create()
{
        string str;
        set_name(names[random(sizeof(names))], ({"bian fu","fu", "bianfu"}));
        set("race", "Ұ��");
        set("long",
"����һֻ�����������ڶ�����\n");
        set("age", 40+random(51));
        set("combat_exp", 500000+random(500001));
        set("daoxing", 500000+random(500001));
        set("limbs", ({ "ͷ��", "����", "ǰצ", "β��", "��Ƥ", "��צ"}) );
        set("verbs", ({ "bite", "claw"}) );
        set("attitude", "aggressive");
        set("per", 10);
        set_skill("parry", 200);
        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("blade", 200);
        set("max_sen",2000);
        set("max_kee",2000);
        set("force",2000);
        set("max_force",1500);
        set("max_mana",1500);
        set("mana",2000);
        set("mana_factor",80);
        set("force_factor",80);
        add_temp("apply/damage", 50);
        setup();
}


void init( )

{
        object ob;      
        remove_call_out("hunting");
        if( interactive(ob = this_player())  ) {
        call_out("hunting",1);
        }
        if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",1);
}

void hunting()
{
        int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
        message_vision(WHT"$Nһ���ҽ�,��Ȼ���أ���Ϊһ��������ɢ�ˡ�\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
                corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 300000)   {
                message("vision", me->name() + "�ɹ������Թ�����������40����,��ʮ�����,20Ǳ�ܡ�\n", me);
                me->add("combat_exp",40);
                me->add("daoxing",80);
                me->add("potential",20);
                destruct(ob);
        }

   
        destruct(ob);
        return;
}

