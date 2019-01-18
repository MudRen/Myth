// jinguzhou.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg, name;
        int damage, ap, dp, howlong=0;
        object ob;

        if( !target ) target = offensive_target(me);

        if( !(ob = present("jingu zhou", me))) 
                return notify_fail("������û�н����䡢���������䣬�޷�ʩ�����\n");
        name="��"+ob->query("name")+"��";

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭��"+name+"��\n");
                
        if (!PFM_D->valid_family(me, "�Ϻ�����ɽ")) 
                return notify_fail("���Ƿ��ŵ��Ӳ����á����䡹��\n");

        if((int)me->query_skill("spells") < 100)
                return notify_fail("�㻹ûѧ����"+name+"��\n");

        if((int)me->query("mana") < 25+(int)me->query("mana_factor") )
                return notify_fail("��ķ���������\n");

        if((int)me->query("sen") < 10 )
                return notify_fail("���޷����о�������ʩ�õ��Լ�ͷ�ϣ�\n");

        me->add("mana", -25-(int)me->query("mana_factor"));
        me->receive_damage("sen", 10);

        if( random(me->query("max_mana")) < 50 ) {
                write("��ʧ���ˣ�\n");
                return 1;
        }

        msg = HIC
"$NĬĬ�ؽ���"+name+"���˼��顣\n" NOR;
 
        ap = me->query_skill("spells");
        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
        ap += (int)me->query("daoxing");
        dp = target->query("daoxing");
        if( random(ap + dp) > dp ) {
                damage = (int)me->query("max_mana") / 10 +
random((int)me->query("eff_sen") / 5);
                damage -= (int)target->query("max_mana") / 10 +
random((int)target->query("eff_sen") / 5);         
                damage+=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
//here we can see if 2 players are at same status, the attacker has higher chance.
                if( damage > 0 ) {
                msg += HIC "�Ѹ�$nʹ�������ѣ������������࣬�������飬���ɵ�ץ�����Լ���ͷ��\n" NOR;
//finally damage also depends on enabled spells level.
                damage +=random((damage*(int)me->query_skill("spells"))/80);
                if (name != "�������䡱") damage /= 2;
                target->receive_damage("sen", damage,me,"cast");
                target->receive_wound("sen", damage/3,me,"cast");
                target->receive_damage("kee", damage,me,"cast");
                target->receive_wound("kee", damage/4,me,"cast");
                target->set_temp("no_move", 1);
                me->improve_skill("buddhism", 1, 1);
                howlong = 15 + random((me->query_skill("spells") -100));
                if(howlong>60) howlong=60;
                if (name != "�������䡱") howlong /= 2;
//a typical level is 100+100 ->enabled 150, so will "ding" about 1 minute in the best case.

                }
                else msg += "����ʲôҲû������\n";
        } 
        else
                msg += "����ʲôҲû������\n";

        message_vision(msg, me, target);

        if( damage > 0 ) {
                destruct(ob);
                COMBAT_D->report_status(target);
                call_out("free", howlong, target);
        }

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else
                        target->kill_ob(me);
                }
                me->fight_ob(target);
        }

        me->start_busy(1+random(2));
        return 3+random(5);
}

void free(object target)
{
        if(target) target->delete_temp("no_move");      
        return;
}

