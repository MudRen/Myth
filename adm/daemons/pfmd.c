#include <ansi.h>

// tell wizard the damage
// mudring Nov/27/2002
varargs void test_msg(object ob, object tob, string message)
{
    if (wizardp(ob) && ob->query("env/combat") == "verbose")
        tell_object(ob, WHT"�����Ծ��顿" + message + "\n"NOR);
    if (wizardp(tob) && tob->query("env/combat") == "verbose")
        tell_object(tob, WHT"�����Ծ��顿" + message + "\n"NOR);
}

int valid_family(object me, string family)
{
    string *m_fam;

    if (!userp(me)) return 1;
    if (me->query("family/family_name") == family)
        return 1;

    if (metep(me))
         {
        m_fam=me->query("opinion/family_allow");
      if(!m_fam && sizeof(m_fam)==0 ) {tell_object(me,"���ת����ԭ����û��¼!\n"); return 0;}
      if(member_array(family,m_fam) == -1) return 0; 
        return 1;
                 }
    return 0;
}

//the following functions are for performs...weiqi
//copy and modified from spelld.c
int attacking_perform_success(object attacker, object target, int skill_level, int success_adj)
{
    int ap, dp, success;

    ap = ( skill_level * skill_level * skill_level / 10 ); //this is from skill.
    //at high exp, the skill level can not follow, so need adjustment here.
    ap = ap*(1+attacker->query("combat_exp")/500000);
    ap = ap+attacker->query("combat_exp");
    dp = target->query("combat_exp");

    success = 0;

    if ( success_adj < 20 ) success_adj = 20;
    else if( success_adj > 500 ) success_adj = 500;

    ap = ap*success_adj/100;

    if( random(100)>dp*100/(ap+dp) ) success = 1;

    return success;
}

int attacking_perform_damage(object attacker, object target, int damage_adj)
{
    int a_neili, d_neili, damage;

    if( damage_adj < 50 ) damage_adj = 50;
    else if( damage_adj > 200 ) damage_adj = 200;

    //will use current neili...but do not allow it exceeds 2 time of the max.
    a_neili = attacker->query("force");
    if( a_neili > 2*attacker->query("max_force") ) a_neili = 2*attacker->query("max_force");
    d_neili = target->query("force");
    if( d_neili > 2*target->query("max_force") ) d_neili = 2*target->query("max_force");

    //neili and qi. weaker than cast here...
    damage = (a_neili - d_neili)/30 +
        random(attacker->query("eff_kee") / 30)-random(target->query("eff_kee") / 30);
    //mana_factor, here the attacker has some advantage.
    //the damage_adj higher, the better for attacker.
    damage += (3*damage_adj/200) //weaker than cast here...
        *( attacker->query("force_factor") - random(target->query("force_factor")) );

    //for backfire, we need let it be serious...
    if( damage < 0 ) damage = damage - target->query("force_factor");
    //here increase the damage, since previously it's included in random()

    damage = damage*damage_adj/100; //last damage scaled again.

    //finally, we need let the force level useful...
    //the setting is, at enabled level 200, the damage will double.
    if( damage > 0 )
    {
        damage += (damage*(int)attacker->query_skill("force"))/200;
    }
    else if ( damage < 0 )
    {
            damage += (damage*(int)target->query_skill("force"))/200;
    }

    return damage;
}

// /daemon/class/ghost/hellfire-whip/biluo.c
// /daemon/class/fighter/sanban-axe/kai.c
// /daemon/class/bonze/jienan-zhi/storm.c
void attacking_perform(
    object attacker,
    object target,
    int skill_level,//the level of skill used to attack.
    int success_adj,
    int damage_adj, //default value is 100 for this 2 parameters.
    string damage_type, //must be "shen"/"sen", "qi"/"kee" or "both"(default)
    string msg_init,
    string msg_success,
    string msg_fail,
    string msg_backfire_init,
    string msg_backfire_success)
{
    int damage;

    //first, show the initial message...
    message_vision( msg_init, attacker, target );

    //calculate if the casting can happen...
    if( attacking_perform_success(attacker, target, skill_level, success_adj) == 0 )
    {
        message_vision( msg_fail, attacker, target );
        //let the target kill attacker.
        attacker->kill_ob(target);
        return;
    }

    damage = attacking_perform_damage(attacker, target, damage_adj);

    if( damage > 0 ) //attacker hit target
        SPELL_D->apply_damage(attacker, target, damage, damage_type, msg_success);

    else if( damage < 0 ) //backfire
    {
        message_vision(msg_backfire_init, attacker, target);
        SPELL_D->apply_damage(target, attacker, -damage, damage_type, msg_backfire_success);
    }

    else //damge=0
        message_vision(HIB "������ñ�$N��������ס��˭Ҳû�гԿ���\n" NOR, target);

    //let the target kill attacker.
    attacker->kill_ob(target);

    return;
}

// /daemon/class/yaomo/xueshan/bingpo-blade/ningxue.c
// /daemon/class/sanjie/tianyaofa/xinqing.c
// /daemon/class/sanjie/huxiaojian/leihua.c
// /daemon/class/puti/qianjun-bang/fantian.bak
// /daemon/class/bonze/jienan-zhi/lingxi.c
//�����˺������൱��ֱ�Ӵ��е��ˣ�����һ�����ܵ��˺�
int do_attack_damage(object me, object victim, object weapon)
{
    mapping my, your, action, victim_action;
    string  result;
    string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
    mixed foo;
    int damage, damage_bonus, defense_factor;

    my = me->query_entire_dbase();
    your = victim->query_entire_dbase();
    action = me->query("actions");
    damage = me->query_temp("apply/damage");
    damage = (damage + random(damage)) / 2;

    if( action["damage"] )
        damage += action["damage"] * damage / 100;

    damage_bonus = me->query_str();

    // Let force skill take effect.
    if( my["force_factor"] && (my["force"] > my["force_factor"]) )
    {
        if( force_skill = me->query_skill_mapped("force") )
        {
            foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["force_factor"]);
            if( stringp(foo) ) result += foo;
            else if( intp(foo) ) damage_bonus += foo;
        }
    }

    if( action["force"] )
        damage_bonus += action["force"] * damage_bonus / 100;

    if( martial_skill = me->query_skill_mapped(attack_skill) )
    {
        foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
        if( stringp(foo) ) result += foo;
        else if(intp(foo) ) damage_bonus += foo;
    }

    // Let weapon or monster have their special damage.
    if( weapon )
    {
        foo = weapon->hit_ob(me, victim, damage_bonus);
        if( stringp(foo) ) result += foo;
        else if(intp(foo) ) damage_bonus += foo;
    } else {
        foo = me->hit_ob(me, victim, damage_bonus);
        if( stringp(foo) ) result += foo;
        else if(intp(foo) ) damage_bonus += foo * 3 / 4;
    }

    if( damage_bonus > 0 )
        damage += (damage_bonus + random(damage_bonus))/2;
    if( damage < 0 ) damage = 0;

    // Let combat exp take effect
    defense_factor = your["combat_exp"];

    while( random(defense_factor) > my["combat_exp"] )
    {
        damage -= damage / 3;
    }

    damage = victim->receive_damage("kee", damage, me );
    if( (me->is_killing(victim) || weapon)
        && random(damage) > (int)victim->query_temp("apply/armor") )
    {
        // We are sure that damage is greater than victim's armor here.
        victim->receive_wound("kee",
        damage - (int)victim->query_temp("apply/armor"), me);
        //wounded = 1;
    }

    return damage;
}

int do_control(int damage,object who,string d_type,object victim)
{
     int ccp,app;
     if(!userp(who) && !userp(victim)) return damage;
     if(userp(who) && userp(victim)) 
     {
            if (d_type=="pfm")
			{
				app=(victim->query("combat_exp"))/(who->query("combat_exp"));
			}
            if (d_type=="cast")
			{
				app=(victim->query("daoxing"))/(who->query("daoxing"));
			}
			
            if (app >2) damage=damage/app;

	     return damage *2/5;
     }
      if(userp(who))
      { 
        if (d_type=="pfm") damage =damage *2/3;
        if (d_type=="cast") 
           { 
            ccp=(who->query("daoxing")+10000)/(victim->query("daoxing")+10000);
            if (ccp >=3) ccp=3;
            if (ccp <=1) ccp=1;
            damage=damage*ccp *5/4;
            }
         return damage;
       }
       //Ŀǰ�򵥴���
}  

