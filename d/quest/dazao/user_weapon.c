// user_weapon.c ��������
// Created by Zen(SnowMan.ZD)
// Modified by kuku@sjsh 2003.2 ������Ʊ�������Ч��������

inherit EQUIP;

void create()
{
        set_name("��ͨ����", ({ "user weapon" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N�ó�$n�������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
                set("wield_maxneili", 100000);
                set("wield_neili", 10);
                set("wield_str", 10);
                set("imbued", 1);
        }
        set("flag", 4);
        set("verbs", ({ "slash", "hack", "slice", "thrust" }) );
        set("weapon_prop/damage", 1);
        set("skill_type", "sword");
        setup();
}
int weapon_setup(mapping mp)
{
        string *vb;
        int i;
        
        if( !clonep(this_object()) )
                return 0;
        if( !mapp(mp) ) return 0;
        
        vb = keys(mp);
        
        for( i = 0; i < sizeof(vb); i++ )
                set(vb[i], mp[vb[i]]);
        
        set_name(mp["name"], mp["id"]);
        set_weight(mp["weight"]);
        set("inset_hole",4);
        set("actions", (: call_other, WEAPON_D, "query_action" :) );
        
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int diff;
        string poison_name1,poison_name2;
        object weapon,ob;
        
        if( damage_bonus < 0 ) return 0;
        poison_name1 = me->query("user_weapon/poisoned");
        poison_name2 = victim->query("user_weapon/poisoned");
        
        if( poison_name1 && !poison_name2){
                victim->apply_condition( poison_name1, (1000 + random(1000))/2 ); 
                message_vision("$N����һ������⣬�ж��ˣ�\n", victim);
        }  
        else if( !poison_name1 && poison_name2){
                me->apply_condition( poison_name2, (1000 + random(1000))/2 );
                message_vision("$N����һ������⣬�ж��ˣ�\n", me);
        }     
        else if( poison_name1 && poison_name2){
                if(random(me->query_skill("spells")) > victim->query_skill("spells")*2/3){
                        victim->apply_condition( poison_name1, (1000 + random(1000))/2 );
                        message_vision("$N����һ������⣬�ж��ˣ�\n", victim);
                }
                else {
                        me->apply_condition( poison_name2, (1000 + random(1000))/2 );
                        message_vision("$N����һ������⣬�ж��ˣ�\n", me);
                }
        }
        else 
                message_vision("$N����һ����Ϯ������㱻$n���С�\n", victim,me);
}

int move(mixed dest, int silently)
{               
        return ::move(dest, silently);
}

int weapon_fix()
{       
        delete("weapon_mp/broken");
        delete("broken");       
}
