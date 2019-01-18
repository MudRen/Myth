// combatd.c
// optimize by mudring Nov/22/2002
// ����NK BUG...mudring......
// Modify by Mudring@SanJie

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_DBASE;

#include "s_killmsg.h"
#include <combat_msg.h>

int victim_lose(object killer, object victim, string killerid);
varargs void victim_penalty(object victim, int raw);
int nk_gain(object killer, object victim);

//this mapping indicates whether this family class is
//xian or yao.
mapping family=([ //
    "����ɽ���Ƕ�"  :   1,
    "�Ϻ�����ɽ"    :   1,
    "������"        :   1,
    "��ׯ��"        :   1,
    "�¹�"         :   1,
    "��ɽ����"      :   1,
    "��������"      :   1,
    "���޵ظ�"      :  -1,
    "��˿��"        :  -1,
    "��ѩɽ"        :  -1,
    "��ԯ��Ĺ"      :  -1,
    "�ݿ�ɽ�޵׶�"  :  -1,
    "����ɽ"        :  -1,
    "���ƶ�"        :  -1,
]);

void create()
{
    seteuid(getuid());
    set("channel_id", "ս������");
}

// �еط����������
// û�п��Խ��������ɾ������
string chinese_daoxing(int gain)
{
    return CHINESE_D->chinese_daoxing(gain);
}

int check_family(string fam)
{
    if (fam && !undefinedp(family[fam]))
        return family[fam];
    else
        return 0;
}

varargs void report_status(object ob, int effective)
{
#if 1
    if (effective)
        message_combatd("( $N" + eff_status_msg((int)ob->query("eff_kee") *
                100 /(1+(int)ob->query("max_kee")) ) + " )\n", ob, 0, "");
    else
        message_combatd( "( $N" + status_msg((int)ob->query("kee") *
                100/(1+(int)ob->query("max_kee")) ) + " )\n", ob, 0, "");
#else
    if (effective)
        message_vision("( $N" + eff_status_msg((int)ob->query("eff_kee") *
                100 /(1+(int)ob->query("max_kee")) ) + " )\n", ob);
    else
        message_vision( "( $N" + status_msg((int)ob->query("kee") * 100/(1+(int)ob->query("max_kee")) ) + " )\n", ob);
#endif
}

varargs void report_sen_status(object ob, int effective)
{
    message_combatd( "( $N" + sen_status_msg((int)ob->query("sen") *
            100 /(1+(int)ob->query("max_sen")))+ " )\n", ob, 0, "");
}

varargs string report_status_msg(object ob, int effective)
{
    if (effective)
        return eff_status_msg(ob->query("eff_kee") * 100 / (1 + ob->query("max_kee")));
    else
        return status_msg(ob->query("kee") * 100 / (1 + ob->query("max_kee")));
}

// This function calculates the combined skill/combat_exp power of
// a certain skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
    int level, power;
    int exp;

    if (!living(ob)) return 0;

    level = ob->query_skill(skill);
    exp   = valid_data(ob->query("combat_exp"));

    switch (usage)
    {
        case SKILL_USAGE_ATTACK:
            // level = ob->eff_skill_level(level, SKILL_USAGE_ATTACK);
            level += ob->query_temp("apply/attack");
            break;
        case SKILL_USAGE_DEFENSE:
            // level = ob->eff_skill_level(level, SKILL_USAGE_DEFENSE);
            level += ob->query_temp("apply/defense");
            if (ob->is_fighting())
                level += level * ob->query_temp("fight/" + skill) / 100;
            break;
    }

    if (level < 1)
        power = exp / 2;
    else
        power = (to_int(sqrt(level))*level*level + exp) / 30;

    if (usage == SKILL_USAGE_ATTACK)
        return power * ob->query_str();

    return power * (skill == "dodge"?ob->query_cps():ob->query_con());
}

mixed force_hit(object me, object victim, int damage_bonus, int factor, int em)
{
    int damage, my_force, v_force;

    my_force = (int)me->query("force");
    if( my_force > (int)me->query("max_force") ) my_force = (int)me->query("max_force");
    v_force = (int)victim->query("force");
    if( v_force > (int)victim->query("max_force") ) v_force = (int)victim->query("max_force");

    damage = my_force/25 + factor + factor * factor/400 - v_force/30;

    damage /= 2;

    if (damage < 0)
    {
        if (!me->query_temp("weapon")
            && !me->query_temp("hit_ob_hit")
            && !me->query("env/invisibility")
            && !me->query_temp("fanzhen")
            && random(victim->query_skill("force")) > me->query_skill("force")/2
            && living(victim))
        {
            damage = - damage;
            me->receive_damage( "kee", damage, victim, "pfm");
            me->receive_wound( "kee", damage/3, victim);
            if( damage < 50 ) return "$N�ܵ�$n�����������ƺ�һ����\n";
            if( damage < 100 ) return "$N��$n���������𣬡��١���һ������������\n";
            if( damage < 220 ) return "$N��$n������һ���ؿ������ܵ�һ���ش�����������������\n";
            return "$N��$n������һ����ǰһ�ڣ��������ɳ�������\n";
        }
        if( damage_bonus + damage < 0 ) return - damage_bonus;
        return damage;
    }

    damage += em/2+random(em/2);

    if (wizardp(me) && me->query("combat_test"))
        tell_object(me, GRN"damage = "+damage+" \n"NOR);

    damage -= victim->query_temp("apply/armor_vs_force");
    if (damage < 0) damage = 0;
    if (damage_bonus + damage < 0) return - damage_bonus;
    if (random(me->query_skill("force")) > damage )
        return damage;
    return damage/2;

}

// ��������ǵ����������ʽ��.
// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//
// mudring Nov/23/2002
varargs int do_attack(object me, object victim, object weapon, int attack_type)
{
    mapping my, your, action, victim_action;
    string limb, *limbs, result, damage_info;
    string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
    mixed foo;
    int ap, dp, pp, afp, vfp;  //afp: attacker->force power, vfp: victim->force power
    int damage, damage_bonus, force_adj;
    int wounded = 0;
    int mod_val, em;
    object vweapon;

    if (!me || !victim || environment(me) != environment(victim))
        return 0;
    if (!living(me) || me->is_busy() && !victim->is_busy())
        return 0;

    my = me->query_entire_dbase();
    your = victim->query_entire_dbase();
    vweapon = victim->query_temp("weapon");

    //
    // (0) Choose skills.
    //
    if (objectp(weapon))
    {
        if (weapon->query("weapon_scar"))
            WEAPON_D->do_s_attack(me,victim,weapon);
        if (weapon->query("use_apply_skill"))
            attack_skill = weapon->query("apply/skill_type");
        else
            attack_skill = weapon->query("skill_type");
    }
    else  attack_skill = "unarmed";

    //
    // (1) Find out what action the offenser will take.
    //
    me->reset_action();
    action = me->query("actions");
    if (!mapp(action))
    {
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s(%s): bad action = %O",
                         me->name(1), me->query("id"),
                         me->query("actions", 1)));
        action = me->query("default_actions");
        if (!mapp(action)) return 0;
        weapon = 0;
        attack_skill = "unarmed";
    }

    if (action["name"])
        me->set_temp("action_name", action["name"]);

    result = "\n" + action["action"] + "��\n";

    if (!arrayp(limbs = victim->query("limbs")))
        limbs = ({ "����", "����", "����" });
    limb = limbs[random(sizeof(limbs))];

    
    //(2) ���������ڹ��ķ�������
    // Wuyou added
    if ( victim->query_temp("jldl") && living(victim) )                             
    { 
        afp = skill_power(me, "force", SKILL_USAGE_ATTACK);
        if( afp < 1) afp = 1;
        vfp = skill_power(victim, "force", SKILL_USAGE_DEFENSE);
        if( victim->is_busy() ) vfp /= 3;
        if( vfp < 1 ) vfp = 1;
        mod_val = 0;
        mod_val -= random(6)*5+5;
        if (!victim->query_temp("weapon")) mod_val += 10;
        if( vfp > 1000000 )     
            mod_val = vfp / 100 * (100 + mod_val);
        else   
            mod_val = (100 + mod_val) * vfp / 100;
        if( mod_val < 1 ) mod_val = 1;
        force_adj=random(afp + vfp);
    }
    else 
    {
        force_adj=1;
        mod_val=1;
    }

    //
    // (2) Prepare AP, DP for checking if hit.
    //
    // Wuyou added            
    if ( force_adj < mod_val )
    {
        foo = "/daemon/class/puti/wuxiangforce/jldl"->jldl_result(victim, me, mod_val, force_adj,action);
        result += foo;
        damage = RESULT_FORCE;
    }
   
    ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
    if( ap < 1) ap = 1;

    if (victim->query_temp("must_be_hit"))
        dp = 1;
    else
    {
        // Check DP.
        if (userp(me) && intp(action["dodge"]))
            me->set_temp("fight/dodge", action["dodge"]);
        if (userp(me) && intp(action["parry"]))
            me->set_temp("fight/parry", action["parry"]);

        dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);

        if (!weapon && vweapon) dp /= 2;

        if (victim->is_busy()) dp /= 3;
        if (dp < 1) dp = 1;
    }

     // mon 8/3/98
    if (living(victim))  dodge_skill = victim->query_skill_mapped("dodge");
    else   dodge_skill = 0;

    mod_val = 0;
    if (dodge_skill)
    {
        victim_action = SKILL_D(dodge_skill)->query_action();
        if (victim_action && victim_action["dodge_power"])
            mod_val = victim_action["dodge_power"];
    }

    if (action["dodge"])  mod_val += action["dodge"];
    if (dp > 1000000)
        mod_val = dp / 100 * (100 + mod_val);
    else
        mod_val = (100 + mod_val) * dp / 100;

    if (mod_val < 1) mod_val = 1;

    // (3) Fight!
    //     Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
    //     AP and DP are greater than zero, so we always have chance to hit
    //     or be hit.
    //
    damage = 0;
    wounded = 0;
    damage_info = "";
    if (random(ap + dp) < mod_val && living(victim))
    {
#if INSTALL_COMBAT_TEST
        if (wizardp(me) && me->query("env/combat_test"))
            tell_object(me, HIY "�����Ծ��顿������ AP��" + ap +
                        "��DP��" + dp + "��MOD��" + mod_val + "��\n" NOR);
        if (wizardp(victim) && victim->query("env/combat_test"))
            tell_object(victim, HIC "�����Ծ��顿���Է� AP��" + ap +
                        "��DP��" + dp + "��MOD��" + mod_val + "��\n" NOR);
#endif
        // Does the victim dodge this hit?
        if (!dodge_skill) dodge_skill = "dodge";

        if (victim_action && victim_action["dodge_action"])
            result += victim_action["dodge_action"];
        else
            result += SKILL_D(dodge_skill)->query_dodge_msg(limb);

        if (dp < ap && your["combat_exp"] < my["combat_exp"]*2
            && (!userp(victim) || !userp(me))
            && random(sizeof(victim->query_enemy())) < 4
            && random(your["sen"]*100/your["max_sen"] + your["int"]*your["cps"]) > 150)
        {
            your["combat_exp"]++;
            victim->improve_skill("dodge", random(2));
        }

        damage = RESULT_DODGE;
    }
    else
    {
        //
        //  (4) Check if the victim can parry this attack.
        //
        if (victim->query_temp("must_be_hit"))
            pp = 1;
        else
        {
            // Check PP.
            if (vweapon)
            {
                pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
                if (!weapon && !victim->is_busy()) pp *= 2;
                parry_skill = victim->query_skill_mapped("parry");
            }
            else
            {
                pp = skill_power(victim, "unarmed", SKILL_USAGE_DEFENSE);

                if (weapon)
                {
                    if (victim->is_busy()) pp = pp/3 + random(pp/2);
                    if ((int)victim->query_temp("fight/parry") > 40 )
                        pp /= 4;
                    else pp = 0;
                }
                parry_skill = victim->query_skill_mapped("unarmed");
            }
        }

        if( victim->is_busy() ) pp /= 3;
        if (!living(victim)) pp /= 20;
        if (pp < 1) pp = 1;

        mod_val = 0;
        if( action["parry"] )       mod_val = action["parry"];
        if (pp > 1000000)
            mod_val = pp / 100 * (100 + mod_val);
        else
            mod_val = (100 + mod_val) * pp / 100;
        if(mod_val < 1)  mod_val = 1;

        if (random(ap + pp)< mod_val && living(victim))
        {
#if INSTALL_COMBAT_TEST
            if (wizardp(me) && me->query("env/combat_test"))
                tell_object(me, HIY "�����Ծ��顿������ AP��" + ap +
                            "��PP��" + pp + "��MOD��" + mod_val + "��\n" NOR);
            if (wizardp(victim) && victim->query("env/combat_test"))
                tell_object(victim, HIC "�����Ծ��顿���Է� AP��" + ap +
                            "��PP��" + pp + "��MOD��" + mod_val + "��\n" NOR);
#endif        	
            if (!parry_skill) parry_skill = "parry";

            result += SKILL_D("parry")->query_parry_msg(vweapon);

            if (pp < ap && your["combat_exp"] < my["combat_exp"] * 2
                && (!userp(victim) || !userp(me))
                && random(sizeof(victim->query_enemy())) < 4
                && random(your["sen"]*100/your["max_sen"] + your["int"]*your["cps"]) > 150 )
            {
                your["combat_exp"] += 1;
                victim->improve_skill("parry", random(2));
            }

            if (weapon) WEAPON_D->weapon_cut(me, victim, weapon, vweapon, damage);

            damage = RESULT_PARRY;
        }
        else
        {
            //
            //  (5) We hit the victim and the victim failed to parry
            //
            // ����damage����
            // mudring Nov/28/2002
            damage = me->query_temp("apply/damage");
            if (weapon && weapon->query("weight") > 500
                && weapon->query("flag") != 4)
                damage += weapon->query("weight")/500;

            if (damage > 1000) damage = 1000;
            damage = (damage + random(damage)) / 2;
            if (action["damage"])
                damage += action["damage"] * damage / 100;
            damage += me->query_skill(attack_skill) * damage / 1000;
            damage_bonus = me->query_str();
/*
            // different skill, different effect. snowman
            switch (attack_skill)
            {
"sword":"��",
"stick":"��",
"hammer":"��",
"staff":"��",
"whip":"��",
"axe":"��",
"blade":"��",
"fork":"��",
"spear":"ǹ",
"mace":"�", 
   1k archery.c        1k axe.c            1k blade.c          1k bow.c       
   1k dagger.c         1k fork.c           1k hammer.c         1k mace.c      
   1k rake.c           1k spear.c          1k staff.c         1k whip.c        
   1k stick.c          1k sword.c          1k throwing.c       1k unarmed.c   


                case "hand":
                case "dagger":
                case "brush":
                case "sword":   em = -damage_bonus/3; break;
                case "whip":
                case "cuff":
                case "blade":   em = -damage_bonus/5; break;
                case "staff":
                case "club":
                case "spear":
                case "claw":    em = damage_bonus/5; break;
                case "throwing":
                case "axe":
                case "hammer":
                case "unarmed":
                case "finger":  em = damage_bonus/3; break;
                default:        em = 0;
            }
*/
            em = 0;
            damage_bonus += em;

            // Let force skill take effect.
            if (my["force_factor"] && (my["force"] > my["force_factor"]))
            {
                my["force"] -= my["force_factor"];
                if (!living(victim))
                    damage_bonus += my["force_factor"];

                else if( force_skill = me->query_skill_mapped("force") )
                {
                    foo = force_hit(me, victim, damage_bonus, my["force_factor"], -em);
                    if (stringp(foo))
                        damage_info += foo;
                    else if (intp(foo))
                    {
                        if (!living(victim) && foo < 0) foo = 0;
                        if (weapon) foo /= 3;
                        damage_bonus += foo;
                    }
                }
#if INSTALL_COMBAT_TEST
                if (wizardp(me) && me->query("env/combat_test"))
                    tell_object(me, HIY "�����Ծ��顿������ AP��" + ap +
                                "��DP��" + dp + "��PP��" + pp + "��MOD��" + mod_val + 
                                "���˺�Ч����" + damage +
                                "�������˺�Ч����" + damage_bonus + "��\n" NOR);
                if (wizardp(victim) && victim->query("env/combat_test"))
                    tell_object(victim, HIC "�����Ծ��顿���Է� AP��" + ap +
                                "��DP��" + dp + "��PP��" + pp + "��MOD��" + mod_val + 
                                "���˺�Ч����" + damage +
                                "�������˺�Ч����" + damage_bonus + "��\n" NOR);
#endif
            }


// �˺�ֵ��Ҫ����
//                damage_bonus += action["force"] * damage_bonus / 100;
            // �����������˺���Ӱ�죬�������ý��ͣ��������ñȱ�����.
            // mudring Nov/24/2002
            // 100,200
            if (action["force"])
            {
                if (weapon)
                    damage_bonus += action["force"] * damage_bonus / 200;
                else
                    damage_bonus += action["force"] * damage_bonus / 100;
            }

            // ����skills���˺���Ӱ�죬
            // ��������ֻ������ڹ��йأ�����������ڹ��͹��������й�ϵ
            // mudring Nov/24/2002
            // 500,750
           if (weapon)
              damage_bonus += me->query_skill("force") * damage_bonus / 100;
           else
              damage_bonus += (me->query_skill(attack_skill) +
                  me->query_skill("force")) * damage_bonus / 100;
// �����
            if( martial_skill = me->query_skill_mapped(attack_skill) )
            {
                foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
                if (stringp(foo))
                    damage_info += foo;
                else if (intp(foo))
                    damage_bonus += foo;
            }

            // add force skill hit_ob
            if (force_skill)
            {
                foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus);
                if (stringp(foo))
                    damage_info += foo;
                else if( intp(foo) )  damage_bonus += foo;
            }

            // Let weapon or monster have their special damage.
            if (weapon)
            {
                // check weapon_cut in WEAPON_D
                WEAPON_D->weapon_cut(me, victim, weapon, vweapon, damage_bonus);

                foo = weapon->hit_ob(me, victim, damage_bonus);
                if (stringp(foo))
                     damage_info += foo;
                 else if(intp(foo) ) damage_bonus += foo;
            } else
            {
                foo = me->hit_ob(me, victim, damage_bonus);
                if (stringp(foo))
                    damage_info += foo;
                else if(intp(foo) ) damage_bonus += foo * 3 / 4;
            }

            if (!victim)
                return 0;

            if (damage_bonus > 0)
                damage += (damage_bonus + random(damage_bonus))/2;
            if (damage_bonus < 0)
                damage += (damage_bonus - random(-damage_bonus))/2;
            if (damage < 0) damage = 0;

            if (living(victim))
            {
                int defense_factor = dp + pp;

                while( defense_factor > ap / 3)
                {
                    damage -= damage / 4;
                    defense_factor /= 2;
                }
            }
            //
            //  (6) Inflict the damage.

            // �޸Ĵ˾�mudring Nov/24/2002
            // damage = victim->receive_damage("kee", damage, me );

            if (attack_type == TYPE_BUSY) damage /= 2;
            if (attack_type == TYPE_QUICK) damage = damage/2 + random(damage/2);
            if (attack_type == TYPE_SUPER) damage *= 2;
            if (!living(victim)) damage *= 2;

            damage = damage * 20 / (victim->query_con() / 4 + 15);

            if (living(victim)
                && !victim->is_busy()
                && !me->query_temp("hit_ob_hit")
                && !victim->query_temp("no_hit_ob_hit")
                && damage > 0)
            {
                em = 0;
                if (martial_skill = victim->query_skill_mapped("dodge"))
                {
                    foo = SKILL_D(martial_skill)->ob_hit(me, victim, damage);
                    if( stringp(foo) )
                        damage_info += foo;
                    else if (foo) damage += foo;
                    else em = 1;
                }

                if ((martial_skill = victim->query_skill_mapped("parry")) && em == 1)
                {
                    foo = SKILL_D(martial_skill)->ob_hit(me, victim, damage);
                    if( stringp(foo) )
                        damage_info += foo;
                    else if (foo) damage += foo;
                    else em = 2;
                }

                if ((martial_skill = victim->query_skill_mapped("force")) && em == 2)
                {
                    foo = SKILL_D(martial_skill)->ob_hit(me, victim, damage);
                    if( stringp(foo) )
                        damage_info += foo;
                    else if(intp(foo) ) damage += foo;
                }
            }

            if (foo = victim->query_temp("armor/cloth") )
            {
                foo = foo->ob_hit(me, victim, damage);
                if( stringp(foo) )
                    damage_info += foo;
                else if(intp(foo) ) damage += foo;
            }

            if (damage < 0) damage = 0;
            if (damage > 0)
                damage = victim->receive_damage("kee", damage, me, "pfm");

#if INSTALL_COMBAT_TEST
            if (wizardp(me) && me->query("env/combat_test"))
                tell_object(me, HIY "�����Ծ��顿�����" +
                            victim->query("name") + "���" +
                            damage + "���˺���\n" NOR);
            if (wizardp(victim) && victim->query("env/combat_test"))
                tell_object(victim, HIG "�����Ծ��顿�����ܵ�" +
                            me->query("name") + damage + "���˺���\n" NOR);
#endif

            if (damage > victim->query_temp("apply/armor")
                && ((me->is_killing(your["id"]) && ((!weapon && !random(4)) || (weapon && !random(2))))
                || ((!weapon && !random(8))|| (weapon && !random(4)))))
/*
            if( (me->is_killing(victim) || weapon)
                && random(damage) > (int)victim->query_temp("apply/armor") )
*/
            {
                // We are sure that damage is greater than victim's armor here.
                victim->receive_wound("kee", damage - (int)victim->query_temp("apply/armor"), me);
                wounded = 1;
            }
// ���������ʲô������
// wuyou��mudring������Ѫ...
// ����ǵظ���Pfm ldlh ������õĶ���������ldlh�Ͳ��������ˡ�
            if (me->query_temp("ldlh"))
                result += "\n" + action["action"] + "��\n";
// ...
// ...
            result += damage_msg(damage, action["damage_type"]);
//            damage_info += "( $n" + status_msg(victim->query("kee") * 100 / victim->query("max_kee")) + ")\n";
            damage_info += "( $n" + report_status_msg(victim, wounded) + ")\n";
        }
    }

    result = replace_string(result, "$l", limb);
    if (objectp(weapon) )
        result = replace_string(result, "$w", weapon->name());
    else if( stringp(action["weapon"]) )
        result = replace_string(result, "$w", action["weapon"]);
    else if (attack_skill == "unarmed")
        result = replace_string(result, "$w", "ȭͷ" );
    if (objectp(victim->query_temp("weapon")))
        result = replace_string( result, "$W",
            victim->query_temp("weapon")->name() );

    message_combatd(result, me, victim, damage_info);

    if ( damage > 0)
    {
//        report_status(victim, wounded);
        /*
        if( martial_skill = me->query_skill_mapped(attack_skill) )
        {
            hit_ob_msg = SKILL_D(martial_skill)->hit_ob_msg(me, victim);
            if (stringp(hit_ob_msg)) message_vision(hit_ob_msg,me,victim);
        }
        */
        // Wuyou added
        if ( (string)me->query("env/brief_message")
          && (string)victim->query("env/brief_message")  && me->query_temp("ldlh") ) 
            message_vision(result, me, victim );
        
        if ( me->query_temp("zxzx") == 1 )
        {
            "/daemon/class/yaomo/wudidong/qixiu-jian/zxzx"->zxzx_effect(me,victim);
        }

        if (victim->is_busy()) victim->interrupt_me(me);
        if ((!me->is_killing(your["id"])) && (!victim->is_killing(my["id"])))
        {
            // fight until one side's kee is < 50%
            if( victim->query("kee") < victim->query("max_kee") * 50 / 100)
            {
                me->remove_enemy(victim);
                victim->remove_enemy(me);
                message_vision(winner_msg[random(sizeof(winner_msg))], me, victim);
            }
        }
    }

    if (functionp(action["post_action"]))
        evaluate( action["post_action"], me, victim, weapon, damage);

    if (damage > 0
        && attack_type != TYPE_QUICK
        && me->query_temp("perf_quick")
        && me->is_fighting(victim) )   //��������
    {
        if( me->query_temp("weapon")
            &&  me->query_temp("perf_quick/"+me->query_temp("weapon")->query("skill_type")) )
        {
            if( me->query_temp("perf_quick/msg") )
                message_combatd(CYN + me->query_temp("perf_quick/msg") +NOR, me, victim, "");
            else
                message_combatd(CYN + "$N���Ʋ����ˣ���$nչ������������"+NOR, me, victim, "");
            do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
            return 1;
        }
    }

    // See if the victim can make a riposte.
    if (attack_type==TYPE_REGULAR
        && damage < 1
        && victim->query_temp("guarding") )
    {
        victim->set_temp("guarding", 0);
        if( random(my["cps"]) < 5 )
        {
            message_combatd("$Nһ�����У�¶����������\n", me, 0, "");
            do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
        } else
        {
            message_combatd("$N��$n����ʧ�󣬳û�����������\n", victim, me, "");
            do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
        }
    }
} // do_attack

// �����������˴�����.
//
//      fight()
//
//      This is called in the attack() defined in F_ATTACK, which handles fighting
//      in the heart_beat() of all livings. Be sure to optimize it carefully.
//
void fight(object me, object victim)
{
    object ob;

    if( !living(me) ) return;
    if( me->query_temp("netdead") )  return;
    if( victim->query_temp("netdead") )
    {
        if( member_array( me, victim->query_netdead_enemy() ) == -1 )
            return;     // can't start fight if the victim is already netdead
    }

    if (!me->visible(victim)
        && (random(100 + (int)me->query_skill("perception")) < 100) )
        return;
    if(me->query("attacking"))      //���ǿ�ʼ��
    {
        ob=find_player(victim->query("owner"));
        CITY_D->city_attack(me,victim,ob);
    }

    // If victim is busy or unconcious, always take the chance to make an attack.
    // added: if victim is in "no_move", similar to "is_busy".
    if( victim->is_busy() || (victim->query_temp("no_move")) || !living(victim) )
    {
        me->set_temp("guarding", 0);
        if( !victim->is_fighting(me) ) victim->fight_ob(me);
        if( !environment(me)->query("hellfireroom"))
            do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
        else
            CITY_D->hell_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
        // Else, see if we are brave enough to make an aggressive action.
    } else
    if( random( (int)victim->query("cps") * 3 ) < ((int)me->query("cor") +
        (int)me->query("bellicosity") / 50))
    {
        me->set_temp("guarding", 0);
        if( !victim->is_fighting(me) ) victim->fight_ob(me);
        if( !environment(me)->query("hellfireroom"))
            do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
        else
            CITY_D->hell_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);

    // Else, we just start guarding.
    } else if (!me->query_temp("guarding"))
    {
        me->set_temp("guarding", 1);
        message_combatd( guard_msg[random(sizeof(guard_msg))], me, victim, "");
        return;
    } else

    return;
}

// �Զ�����.
//      auto_fight()
//
//      This function is to start an automatically fight. Currently this is
//      used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
    // Don't let NPC autofight NPC.
    if( !userp(me) && !userp(obj) ) return;

    // Because most of the cases that we cannot start a fight cannot be checked
    // before we really call the kill_ob(), so we just make sure we have no
    // aggressive callout wating here.
    if (me->query_temp("looking_for_trouble")) return;
        me->set_temp("looking_for_trouble", 1);

    // This call_out gives victim a chance to slip trough the fierce guys.
    call_out( "start_" + type, 0, me, obj);
}

// ���漸��������������������Թ��.
void start_berserk(object me, object obj)
{
    int bellicosity;

    if( !me ) return;// Are we still exist( not becoming a corpse )?
    me->set_temp("looking_for_trouble", 0);
    if( !obj ) return;

    if( wizardp(obj) ) return;

    if (me->is_fighting(obj)                       // Are we busy fighting?
        || !living(me)                             // Are we capable for a fight?
        || environment(me)!=environment(obj)       // Are we still in the same room?
        || environment(me)->query("no_fight"))     // Are we in a peace room?
        return;

    bellicosity = (int)me->query("bellicosity");
    message_vision("$N��һ������������ɨ�����ڳ���ÿһ���ˡ�\n", me);

    if ((int)me->query("force") > (random(bellicosity) + bellicosity)/2 ) return;

    if (bellicosity > (int)me->query("score")
        && !wizardp(obj))
    {
        message_vision("$N����$n�ȵ���" + RANK_D->query_self_rude(me)
            + "����ʵ�ںܲ�˳�ۣ�ȥ���ɡ�\n", me, obj);
        me->kill_ob(obj);
    } else {
        message_vision("$N����$n�ȵ���ι��" + RANK_D->query_rude(obj)
            + "��" + RANK_D->query_self_rude(me) + "�������˴�ܣ����������ְɣ�\n",
            me, obj);
        me->fight_ob(obj);
    }
}

void start_hatred(object me, object obj)
{
    if( !me || !obj ) return;                   // Are we still exist( not becoming a corpse )?

    me->set_temp("looking_for_trouble", 0);

    if (me->is_fighting(obj)                    // Are we busy fighting?
        || !living(me)                          // Are we capable for a fight?
        || environment(me)!=environment(obj)    // Are we still in the same room?
        || environment(me)->query("no_fight"))  // Are we in a peace room?
        return;

    // We found our hatred! Charge!
    message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
    me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
    if( !me || !obj ) return;                    // Are we still exist( not becoming a corpse )?

    me->set_temp("looking_for_trouble", 0);

    if (me->is_fighting(obj)                     // Are we busy fighting?
        || !living(me)                           // Are we capable for a fight?
        || environment(me)!=environment(obj)     // Are we still in the same room?
        || environment(me)->query("no_fight"))   // Are we in a peace room?
        return;

    // We found our vendetta opponent! Charge!
    me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
    if( !me || !obj ) return;                       // Are we still exist( not becoming a corpse )?

    me->set_temp("looking_for_trouble", 0);

    if (me->is_fighting(obj)                        // Are we busy fighting?
        || !living(me)                                                     // Are we capable for a fight?
        || environment(me)!=environment(obj)        // Are we still in the same room?
        || environment(me)->query("no_fight"))      // Are we in a peace room?
        return;

    if (!living(obj)
        && obj->query_temp("faint_by")
        && obj->query_temp("faint_by") != me->query("id"))
        return;

    // We got a nice victim! Kill him/her/it!!!
    me->kill_ob(obj);
}

// ������,����...
// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event, string msg)
{
    switch(event)
    {
    case "dead":
        message_vision("\n$N���ˡ�\n\n", ob);
        break;
    case "unconcious":
        message_vision("\n$N����һ�����ȣ����ڵ���һ��Ҳ�����ˡ�\n\n", ob);
        break;
    case "revive":
        message_vision("\n$N���������۾��������˹�����\n\n", ob);
        break;
    case "death_rumor":
        CHANNEL_D->do_channel(this_object(),"rumor",msg);
        break;
    }
}

// .......
void winner_reward(object killer, object victim)
{
    killer->defeated_enemy(victim);
}

// ����������.
// rewritten for sanjie lib
// mudring Dec/21/2002
void killer_reward(object killer, object victim)
{
    int bls, gain, lose;
    object weapon;
    string k_id, k_name, v_name, v_id;
    string str, killmsg, rkmsg, pk_msg;
    string where, vmark;

    // Call the mudlib killer apply.
    killer->killed_enemy(victim);

    k_id = killer->query("id");
    v_id = victim->query("id");
    k_name = filter_color(killer->query("name"));
    v_name = filter_color(victim->query("name"));

    if (userp(victim)) // victim is user.
    {
        int no_pk;
        int add_no_pk;

        killer->add("PKS", 1);
        victim->add("DIE",1);

        // do party action
        PARTY_D->party_kill(killer, victim);

        victim->remove_all_enemy();
        victim->remove_all_killer();
        killer->remove_enemy(victim);
        killer->remove_killer(victim);

        no_pk = killer->query_condition("no_pk_time");
        add_no_pk = no_pk * 3 / 2;
        if (add_no_pk < 240) add_no_pk = 240;
        no_pk  += add_no_pk;

        killmsg = killer->query_temp("kill_msg");
        if(killmsg)
        {
            if (!undefinedp(s_killmsg[killmsg]))
                rkmsg = s_killmsg[killmsg];
            if(killmsg == "special_msg")
            {
                rkmsg = killer->query_temp("special_msg");
                killer->delete_temp("special_msg");
            }
        }
        str = "";
        weapon = killer->query_temp("kill_weapon");
        where = MISC_D->find_place(environment(killer));

        if (weapon && rkmsg)
        {
            str += "��" + weapon->name() + rkmsg + "���ˡ�";
        }
        else if (weapon && !rkmsg)
        {
            str += "��" + weapon->name() + "��ȥ����������";
        }
        else if (rkmsg && !weapon)
        {
            str += "��һ�С�" + rkmsg + "����ȥ����������";
        }
        else
        {
            str += "ɱ���ˡ�";
        }

        // for die reason
        str = filter_color("��" + k_name + str);
        victim->set("die_reason", str);
        str = filter_color(v_name + "��" + where + str);

        killer->delete_temp("kill_weapon");
        killer->delete_temp("kill_msg");

        bls = 10;

        if (userp(killer))
        {
            lose = victim_lose(killer, victim, k_id);
            gain = lose * 8 / 10;
            if (gain < 0) gain = 0;

            if (lose)
            {
                if (strlen(chinese_daoxing(gain)) > 1)
                    str += k_name + "�õ�" + chinese_daoxing(gain) + "���У�";
                killer->add("kill/pkgain", gain);
                killer->add("daoxing", gain);
            }

            if (pkerp(victim))
            {
                log_file("PK_LOG", sprintf("%s(%s) ���� %s(%s) at %s %s\n",
                         k_name, k_id, v_name, v_id, where, log_time()));
            } else
            if (killer->query_temp("kill_other/" + v_id))
            {
                log_file("PK_LOG", sprintf("%s(%s) ׷ɱ %s(%s) at %s %s\n",
                         k_name, k_id, v_name, v_id, where, log_time()));
            } else
            if (victim->query_temp("kill_other/" + k_id))
            {
                log_file("PK_LOG", sprintf("%s(%s) ���� %s(%s) at %s %s\n",
                         k_name, k_id, v_name, v_id, where, log_time()));
            } else
            {
                log_file("PK_LOG", sprintf("%s(%s) ��ɱ %s(%s) at %s %s\n",
                         k_name, k_id, v_name, v_id, where, log_time()));
            }

			// ��������������
            victim_penalty(victim, 1);

//            killer->delete_temp("kill_other/" + v_id);
            killer->delete_temp("other_kill/" + v_id);
            victim->delete_temp("kill_other/");
            victim->delete_temp("other_kill/");
        }
        else
        {
            victim_penalty(victim);
            log_file("NK_LOG", sprintf("%s(%s) kill %s(%s) at %s %s\n",
                     k_name, k_id, v_name, v_id, where, log_time()));
        }

        victim->delete_temp("faint_by");
        victim->delete_temp("last_damage_from");
        announce(victim, "death_rumor", str);
    }
    else
    {
        if (userp(killer))
        {
            int reward;
            reward = nk_gain(killer, victim);

            if (reward > 0)
            {
                string msg;
                killer->add("kill/nkgain", reward);
                killer->add("daoxing", reward);
                str = chinese_daoxing(reward);
                tell_object(killer, "\n��õ���" + str + "���С�\n");
                msg = sprintf("%s(%d)ɱ����%s(%d)���õ�%d����С�",
                              k_id, (killer->query("daoxing") +
                              killer->query("combat_exp")) / 2,
                              v_id, (victim->query("daoxing") +
                              victim->query("combat_exp")) / 2, reward);
                log_file("npc_kill", msg + log_time() + "\n");
                CHANNEL_D->do_channel(this_object(), "qst", msg);
            }
        }
        killer->add("MKS", 1);
        bls = 1;
    }

    if (!userp(killer)
        && ((killer->query("daoxing") + killer->query("combat_exp"))/10 >
           (victim->query("daoxing") + victim->query("combat_exp"))))
        bls=0;

    killer->add("bellicosity", bls * (userp(killer)? 1: 10));

    if (stringp(vmark = victim->query("vendetta_mark")) )
        killer->add("vendetta/" + vmark, 1);
    if(killer->query("job/sxy") >= 1 && victim->query("sxy") >= 1)
	{
	   tell_object(killer,"��ɱ����һ����»ɽ�ұ�����Ĺ�������ˣ�\n");
	   killer->add("job/gong",1);   
        }

    if (userp(killer)) killer->save();
    if (userp(victim)) victim->save();
} // killer_reward

// ���������Ե���.
// modify for pk and pker
// mudring Dec/20/2002
varargs void victim_penalty(object victim, int raw)
{
    int exp_loss;
    int dx_loss;
    int no_pk;
    int pot;
// �� nopk ����..mudring...
raw = 0;
// end...


//        exp_loss = (int)victim->query("combat_exp") / 50;
//        dx_loss = (int)victim->query("daoxing") / 50;
        exp_loss = (int)victim->query("combat_exp") / 100;
        dx_loss = (int)victim->query("daoxing") / 100;

        if (random(100) > (int)victim->query("kar"))
        {
        	victim->set("death/skill_loss", 1);        	
//        	victim->set("death/skill_loss", 2);        	
//        	victim->skill_death_penalty();
        	victim->skill_death_penalty();
        } else
        {     	
//            victim->set("death/skill_loss", 1);
//            victim->skill_death_penalty();
		}

    victim->add("score", -victim->query("score") / 10);
    victim->add("weiwang", -victim->query("weiwang") / 10);
//1171      victim->add("potential", -victim->query("potential") / 2);
    pot = 0;
    if ((int)victim->query("potential") > (int)victim->query("learned_points"))
        pot = victim->query("learned_points") - victim->query("potential");
    pot /= 4;

    victim->set("bellicosity", 0);

    victim->set("death/mud_age", victim->query("mud_age"));
    victim->set("death/combat_exp_loss", exp_loss);
    victim->set("death/dx_loss", dx_loss);
    victim->set("death/pot_loss", -pot);

    victim->add("combat_exp", -exp_loss);
    victim->add("daoxing", -dx_loss);
    victim->add("potential", pot);
    victim->delete("vendetta");

    log_file("death",
             victim->query("id") +
             " lost " + exp_loss + " exp points and "
             + dx_loss + " dx points.\n");

    if (victim->query("thief"))
        victim->set("thief", (int)victim->query("thief") / 2);

        if (victim->query("job/sxy"))
        {
            victim->delete("job");
        }
    no_pk = victim->query_condition("no_pk_time");

    victim->clear_condition();
    if (no_pk > 180)
        victim->apply_condition("no_pk_time", no_pk - 180);

    victim->save();
}

int nk_gain(object killer, object victim)
{
    string fam, fam1;
    int cla, eff_dx, eff1, eff2, dx, reward, nkgain;

    if (victim->query("no_nk_reward")) return 0;

    if (victim->query_temp("faint_by") &&
        victim->query_temp("faint_by") !=
        killer->query("id")) return 0;

    fam = killer->query("family/family_name");

    if (fam && !undefinedp(family[fam]))
    {
        cla    = family[fam];
        eff_dx = victim->query("eff_dx");
        nkgain = victim->query("nkgain");
        fam1   = victim->query("family/family_name");

        if (fam1 && fam == fam1)
            return 0;

        if (eff_dx != 0 && cla * eff_dx > 0)
            return 0;

        if (!eff_dx)
        {
            int dxn=0;

            eff_dx = (victim->query("daoxing") + victim->query("combat_exp")) / 2;
            if (eff_dx > 20000)     dxn = eff_dx / 3;
            else if (eff_dx > 5000) dxn = eff_dx / 2;
            else                    dxn = eff_dx;
            eff_dx = dxn;
        }

        if (!nkgain)
        {
            int effdx = eff_dx;

            if (effdx < 0) effdx = -effdx;

            if (effdx > 667000)      nkgain = 600;
            else if (effdx > 333000) nkgain = 500;
            else if (effdx > 100000) nkgain = 400;
            else if (effdx > 33000)  nkgain = 300;
            else if (effdx > 17000)  nkgain = 200;
            else if (effdx > 5000)   nkgain = 150;
            else if (effdx > 2000)   nkgain = 100;
            else if (effdx > 500)    nkgain = 50;
            else                     nkgain = 25;

            nkgain = nkgain + 20;
        }

        if (eff_dx < 0) eff_dx = -eff_dx;
        eff1 = eff_dx / 8;
        eff2 = eff_dx / 4;
        dx = (killer->query("daoxing") + killer->query("combat_exp")) / 2;
        if (dx > eff_dx)    reward = 0;
        else if (dx > eff2) reward = nkgain;
        else if (dx > eff1) reward = 10 * (dx - eff1) / (eff2 - eff1) * nkgain / 10;
        else                reward = 0;

        if (cla == 0 || (cla != 0 && !fam1))
            reward = reward * 2 / 3;

        return reward;
    }

    return 0;
}

// opitimize speed
// mudring Dec/20/2002
int victim_lose(object killer, object victim, string killerid)
{
    int lose, exp_k, exp_v;

    if ((wizardp(victim) && !wizardp(killer)) ||
        (!wizardp(victim) && wizardp(killer)))
        return 0;

    // nopk by mudring
//1202      if (victim->query("nopk") || killer->query("nopk"))
    // ����pk,���ܱ�ɱ���ǲ���nopk,�����Եõ����н���.
/*
    if (killer->query("nopk"))
        return 0;
*/
    if (victim->query_temp("faint_by") &&
        victim->query_temp("faint_by") != killer)
        return 0;

    exp_k = killer->query("daoxing");
    exp_v = victim->query("daoxing");

    if (exp_k > exp_v)
    {
        lose = 10 * exp_v / (exp_k + 1) * (4000 + exp_v) / 500;
        if (exp_k > exp_v * 4) lose = 0;
    } else
    {
        lose = (4000 + exp_v) / 50;
    }

    if (lose < 0) lose = 0;

    if (lose > exp_v / 40)
        lose = exp_v / 40;

    return lose;
}
