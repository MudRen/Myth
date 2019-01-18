#include <ansi.h>

inherit NPC;

void create()
{
        string str;
        set_name("��ţ", ({"kui niu", "niu"}));
        set("race", "Ұ��");
        set("long",
"��˵���Ϲ�ʱ����һ�ֹ��ޣ��׺��ޱȣ���ֻ��һ���ȣ���Ծ�н���\n");
        set("age", 40+random(51));
        set("combat_exp", 2500000+random(800001));
        set("daoxing", 2500000+random(800001));
        set("limbs", ({ "ͷ��", "����", "ǰצ", "β��", "��Ƥ", "��צ"}) );
        set("verbs", ({ "bite", "claw"}) );
        set("attitude", "aggressive");
        set("per", 10);
        set_skill("parry", 300);
        set_skill("unarmed", 400);
        set_skill("dodge", 300);
        set_skill("force", 300);
        set_skill("hammer", 300); 
        set_skill("spells", 300);
        set_skill("dragonstep", 300);
        set_skill("dragonforce", 300);
        set_skill("seashentong", 300);
        map_skill("dodge", "dragonstep");
        map_skill("force", "dragonforce");
        map_skill("spells", "seashentong");
        set("max_sen",12500);
        set("max_kee",12500);
        set("force",7500);
        set("max_force",3500);
        set("max_mana",3500);
        set("mana",7500);
        set("mana_factor",150);
        set("force_factor",150);
        add_temp("apply/damage", 150);
        add_temp("apply/attack", 150);
        add_temp("apply/defense", 200); 
        add_temp("apply/armor", 300);  
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
        
        message_vision(WHT"$Nһ���ҽ�,��Ȼ���أ��鴤�˼��¾Ͳ����ˡ�\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
                corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 12000000)   {
                message("vision", me->name() + "�ɹ������Թ�����������50����,��ʮ�����,20Ǳ�ܡ�\n", me);
                me->add("combat_exp",50);
                me->add("daoxing",120);
                me->add("potential",20);
                destruct(ob);
        }

   
        destruct(ob);
        return;
}




