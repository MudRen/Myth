#include <ansi.h>

string get_name(string str)
{
        str="ײ�־�";
        return str;
}

string get_help(string str)                
{
        str="ָ�����������������\n"
        +"ţħ���ľ��У���ţ��ײ�Է���";
        return str;
}

inherit SSERVER;
mapping default_dirs = ([
        "north":        "��",
        "south":        "��",
        "east":         "��",
        "west":         "��",
        "northup":      "����",
        "southup":      "�ϱ�",
        "eastup":       "����",
        "westup":       "����",
        "northdown":    "����",
        "southdown":    "�ϱ�",
        "eastdown":     "����",
        "westdown":     "����",
        "northeast":    "����",
        "northwest":    "����",
        "southeast":    "����",
        "southwest":    "����",
        "up":           "��",
        "down":         "��",
        "out":          "��",
        "enter":        "��",
]);


int cast(object me, object target)
{
        string msg;
        int damage, ap, dp, success, n, i;
        object env, obj;
        string *dirs, target_dir, dest;
        mapping exit;
        
        seteuid(getuid());

        if( !target ) target = offensive_target(me);

        if( !target
        ||   !target->is_character()
        ||   target->is_corpse()
        ||   target==me)
                return notify_fail("��Ҫ������ȥײ˭��\n");

        if((int)me->query_skill("pingtian-dafa", 1) < 30 )
                return notify_fail("���ƽ��󷨻�򲻹�������ʩչ�ĳ���\n");

        if((int)me->query("mana") < 25+(int)me->query("mana_factor") )
                return notify_fail("��ķ�������������û��ʲô�ã�\n");

        if((int)me->query("force") < 100 )
                return notify_fail("�������������\n");

        if((int)me->query("sen") < 10 )
                return notify_fail("���������ǲ��壬����Լ�ײ���ˣ�\n");

        me->add("mana", -25-(int)me->query("mana_factor"));
        me->add("force", -30);
        me->receive_damage("sen", 10);

        success=0;
        
        msg = HIC "\n\n$N��Ȼ�˺�������һ��ͷ�����ؾ���$nײȥ��\n" NOR;

        ap = me->query_skill("spells");
        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
        ap += (int)me->query("daoxing");
        dp = target->query("daoxing");
        if( random(ap + dp) > dp ) 
        {
                damage = (int)me->query("max_mana") / 10 + random((int)me->query("eff_sen") / 5);
                damage -= (int)target->query("max_mana") / 10 + random((int)me->query("eff_sen") / 5);
                damage +=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
                damage += random( (int)me->query("force_factor") );
                //here we can see if 2 players are at same status, the attacker has higher chance.
                if( damage > 0 ) 
                {
                        //finally damage also depends on enabled spells level.
                        damage +=random((damage*(int)me->query_skill("spells"))/100);
                        
                        msg += HIC "���$n������������ײ��" NOR;

                        env=environment(me);
                        exit=env->query("exits");

                        if( mapp(exit)) {
                                dirs=keys(exit);
                                n=sizeof(exit);
                                i=random(n);
                                dest=exit[dirs[i]];
                                if(!undefinedp(default_dirs[dirs[i]]))
                                        target_dir=default_dirs[dirs[i]];
                                else
                                        target_dir=dirs[i]; 

                                if( obj=load_object(dest)) {
                                        success=1;
                                        msg+= HIC "��" +target_dir+ NOR;
                                }

                        }


                        msg += HIC "���˳�ȥ��\n\n" NOR;

                        if( success == 1){
                                if( target->move(obj) ) {

tell_room(environment(target),  HIR"\nֻ��"+target->name()+"�������ݰ�ķ��˹�����\n" NOR, ({target,
target}));
                                }
                        }
                        target->receive_damage("kee", damage, me, "cast");
                }
                else 
                {
                        //here, cast failed and the target's mana_factor will be added to the previous 
                        //damage to hurt yourself:(...note, damage<0.
                        msg += HIC "�����$n�Է���һ�ƣ�$Nûײ��ȥ���Լ������������ˣ�\n" NOR;
                        damage -= (int)target->query("mana_factor");
                        damage -= random((-damage*(int)target->query_skill("spells"))/100);
                        me->receive_damage("kee", -damage/2, target, "cast");
                }
        } 
        else
                msg += "���Ǳ�$n�㿪�ˡ�\n";

        message_vision(msg, me, target);

        if( damage > 0 ) COMBAT_D->report_status(target);
        else if( damage < 0 ) COMBAT_D->report_status(me);
        //damage=0 corresponding to "���Ǳ�$n�㿪�ˡ�\n"--no report.

        if( !target->is_fighting(me)) 
        {
                if( living(target) ) 
                {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }

        return 3;
}

