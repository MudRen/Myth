#include <ansi.h>

inherit SSERVER;
void doblow(object);
int random_go(object victim,string* dirs);

int cast(object me, object target)
{
        string msg,start;
        int busy_time, ap, dp ,msgnum ,damage;


        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse() )
                return notify_fail("��Ҫ��˭ʩչ���������\n");

        if ( !me->is_fighting() )
                return notify_fail("�������ֻ����ս����ʹ�ã�\n");

        if (!PFM_D->valid_family(me, "��ׯ��"))
                return notify_fail("�����ׯ�۵��ӣ�����ʹ�����з�����\n");  


        if((int)me->query_skill("spells") < 60)
                return notify_fail("�㻹ûѧ�����жݷ�������\n");

        if((int)me->query_skill("baguazhen",1) < 30)
                return notify_fail("������а��Ի������˽⣬����ʹ�û���Σ�ա�����\n"); 


        if ( target == me ) {

                if((int)me->query("mana") < 100 )
                        return notify_fail("��ķ���������\n");
                if((int)me->query("sen") < 100 )
                        return notify_fail("��ľ���û�а취��Ч���У�\n");
                me->add("mana", -100);
                me->receive_damage("sen", 10);

                if( random(me->query_skill("spells")) < 20 ) {
                        
                        write("��ʧ���ˡ�\n");
                        return 1;
                }
        msgnum = random(5);
        switch ( msgnum ) {
        case 0:
            msg = WHT "$N�����૵��������ģ���Ȼ���һ����������\n"  +
            "ֻ��$N����һ����������Ӱ���ٵ���ʧ�ˣ�\n\n"NOR ;
            break ;
        case 1:
            msg = HIY "$N�����૵��������ģ���Ȼ���һ����������\n"  +
            "ֻ��$N����һ����⣬ವ�һ�������ˣ�\n\n"NOR ;
            break ;
        case 2:
            msg = HIR "$N�����૵��������ģ���Ȼ���һ����������\n"  +
            "ֻ��$N����һ�Ż��棬Ȼ����ʧ����Ӱ���٣�\n\n"NOR ;
            break ;
        case 3:
            msg = HIG "$N�����૵��������ģ���Ȼ���һ����������\n"  +
            "ֻ��$N����һ�ο�ľ�������Ѳ�֪ȥ��\n\n"NOR ;
            break ;
        case 4:
            msg = BLU "$N�����૵��������ģ���Ȼ���һ����������\n"  +
            "ֻ��$N����һ�Ŵ�����֪Ʈ������ȥ�ˣ�\n\n"NOR ;
            break ;
        }

        message_vision(msg, me);


        switch ( msgnum ) {
        case 0:
            start="/d/death/gate";
            message("vision", WHT+me->name()+"����Ӱ��һ�ź�����������Ρ�\n"NOR,
              environment(me), me);
            tell_object(me, WHT"�����ӰͻȻ������һ�ź����С�\n"NOR);
            break ;
        case 1:
            start="/d/city/kezhan";
            message("vision", HIY+me->name()+"ͻȻ��һ����������˳�����\n"NOR,
              environment(me), me);
            tell_object(me, HIY"�����ӰͻȻ������һ������С�\n"NOR);
            break ;
        case 2:
            start="/d/qujing/wuzhuang/chengyun";
            message("vision", HIR+"ͻȻ���һ��,"+me->name()+"����ð�˳�����\n"NOR,
              environment(me), me);
            tell_object(me, HIR"�����ӰͻȻ������һ�Ż����С�\n"NOR);
            break ;
        case 3:
            start="/d/penglai/penglai";
            message("vision", HIG+"ֻ��һ�ο�ľ�ѿ�,"+me->name()+"�������˳�����\n"NOR,
              environment(me), me);
            tell_object(me, HIG"�����ӰͻȻ������һ�ο�ľ�С�\n"NOR);
            break ;
        case 4:
            start="/d/xueshan/binggu";
            message("vision", BLU+"һ��Ũ��Ʈ���������"+me->name()+"�����Ρ�\n"NOR,
              environment(me), me);
            tell_object(me, BLU"�����ӰͻȻ������һ��Ũ���С�\n"NOR);
            break ;
        }
        me->move(start);

        return 2+random(3);

        }

        if((int)me->query_skill("taiyi",1) < 60)
                return notify_fail("��̫���ɷ��������������޷�ʹ�����з�����ս��������\n");

        if((int)me->query_skill("baguazhen",1) < 60)
                return notify_fail("������а��Ե��˽⻹��͸������������������ˣ�\n"); 

        if((int)me->query("mana") < 200 )
                return notify_fail("��ķ���������\n");
    
        if((int)me->query("sen") < 200 )
                return notify_fail("��ľ���û�а취��Ч���У�\n");

        me->add("mana", -200);
        me->receive_damage("sen", 20);

        if( random(me->query_skill("spells")) < 40 ) {
                write("��ʧ���ˡ�\n");
                return 1;
        }

        if  (target->is_busy() ) 
        { 
                msgnum = random(4);}
                else  msgnum = random(5) ;
                switch ( msgnum ) {
                case 4:    
                        msg = WHT "$N�����૵��������ģ���Ȼ���һ����������\n"  +
                        "ֻ��һ�ź�������$n���ϣ�\n\n"NOR ;
                        ap = me->query_skill("spells");
                        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
                        ap += (int)me->query("combat_exp");
                        dp = target->query_skill("spells");
                        dp = dp * dp * dp ;
                        dp += (int)target->query("combat_exp");
                        break ;
                case 1:
                        msg = HIY "$N�����૵��������ģ���Ȼ���һ����������\n"  +
                        "ֻ��һ���������$n��\n\n"NOR ;
                        ap = me->query_skill("spells");
                        ap = ( ap * ap * ap / 800 ) * (int)me->query("kee");
                        ap += (int)me->query("combat_exp");
                        dp = target->query_skill("spells");
                        dp = dp * dp * dp ;
                        dp += (int)target->query("combat_exp");
                        break;
                case 2:
                        msg = HIR "$N�����૵��������ģ���Ȼ���һ����������\n"  +
                        "ֻ��һ�Ż���ֱ��$n��\n\n"NOR ;
                        ap = me->query_skill("spells");
                        ap = ( ap * ap * ap / 1600 ) * (int)me->query("sen");
                        ap += (int)me->query("combat_exp"); 
                        dp = target->query_skill("spells");
                        dp = dp * dp * dp ;
                        dp += (int)target->query("combat_exp");

                        break;
                case 3:
                        msg = HIG "$N�����૵��������ģ���Ȼ���һ����������\n"  +
                        "ֻ����������������ľ����$n��ͷ���£�\n\n"NOR ;
                        ap = me->query_skill("spells");
                        ap = ( ap * ap * ap / 1200 ) * (int)me->query("max_force");
                        ap += (int)me->query("combat_exp"); 
                        dp = target->query_skill("spells");
                        dp = dp * dp * dp ;
                        dp += (int)target->query("combat_exp");
                        break;
                case 0:
                        msg = BLU "$N�����૵��������ģ���Ȼ���һ����������\n"  +
                        "ֻ��һ����Х��һ�ɾ�������$n������\n\n"NOR ;
                        ap = me->query_skill("spells");
                        ap = ( ap * ap * ap / 2400 ) * (int)me->query("max_mana");
                        ap += (int)me->query("combat_exp"); 
                        dp = target->query_skill("spells");
                        dp = dp * dp * dp ;
                        dp += (int)target->query("combat_exp");
                        break;
                }
                if( random(ap + dp) > dp )  {

                        switch (msgnum) {
                        case 4:

                                busy_time  += (int)me->query("mana_factor")/50;
                                if ( busy_time < 0 ) busy_time = 0 ;
                                if (busy_time > 7) busy_time =8;            
                                target->start_busy(busy_time+2);
                                msg +=  WHT "\n$n���������֣�ֻ�������ܻ����ɵ�һƬ��ʲôҲ���������\n" NOR;
                                break;
                        case 1:
                                damage = (int)me->query("max_mana") / 10
                                + random((int)me->query("eff_kee") / 3);
                                damage -= (int)target->query("max_mana") / 15
                                + random((int)target->query("eff_kee") / 4);
                                damage += (int)me->query("mana_factor")
                                - (int)target->query("mana_factor");
                                if (damage > 0) msg +=  HIY "\n������͡���һ��������$n����͸�������
                 \n�ϳ�һ��������Ѫ����ֱ�䵽��������ĵ��£�\n" NOR;
                                if (damage <= 0 ) 
                                {
                                        msg += HIY "\n����$n����Ӳ������һ�£����޴� ��\n" NOR;
                                        damage =10;
                                }
                                if (damage > 0) damage +=random((damage*(int)me->query_skill("spells"))/100);
                                if (damage > 0) target->receive_damage("kee", damage, me);
                                if (damage > 0) target->receive_wound("kee", damage/4, me);
                                break;
                        case 2:
                                damage = (int)me->query("max_mana") / 10 +
                                random((int)me->query("eff_sen") / 5);
                                damage -= (int)target->query("max_mana") / 15 +
                                random((int)target->query("eff_sen") / 8);
                                damage+=(int)me->query("mana_factor")-(int)target->query("mana_factor");
                                if( damage > 0 ) msg +=  HIR "\n$n�����һ�ƣ�ֻ�����ۻ����ң����񲻶�������ε��ڵأ�\n" NOR;
                                if ( damage <=0 ) 
                                {
                                        msg += HIR "\n$nǿ�����񣬾�Ȼû��̫���Ӱ�졣\n" NOR; 
                                        damage = 20;
                                 }
                                damage +=random((damage*(int)me->query_skill("spells"))/100);
                                target->receive_damage("sen", damage, me);
                                target->receive_wound("sen", damage/3, me);
                
                                break;
                        case 3:
                                damage = (int)me->query("max_mana") / 20 +
                                random((int)me->query("max_force") / 10);
                                damage -= (int)target->query("max_mana") / 30 +
                                random((int)target->query("eff_force") / 15);   
                                damage +=(int)me->query("force_factor")-(int)target->query("force_factor");
                                if( damage > 0 ) msg +=  HIG "\n$n����ľ�Ҹ����ţ��ƺ�����Щ���ˣ�\n" NOR;
                                if ( damage <=0 ) 
                                { 
                                        msg += HIG "\n$n���Ʋ������������ƺ�ֻ���˵���ˡ�\n" NOR; 
                                        damage =5;
                                }
                                damage +=random((damage*(int)me->query_skill("spells"))/100);
                                if (( damage > 0 ) && (damage >=(int)target->query("force"))) target->set("force", 0); 
                                if ((damage >0) && (damage < (int)target->query("force"))) target->add("force", -damage);
        
                                break;  
                        case 0:
                                damage = (int)me->query("max_mana") / 10 +
                                random((int)me->query("max_mana") / 10);
                                damage -= (int)target->query("max_mana") / 15 +
                                random((int)target->query("max_mana") / 15);
                                damage+=(int)me->query("mana_factor")-(int)target->query("mana_factor");
                                if( damage > 0 ) msg +=  BLU "\n$n�������ܵ���������������Ҳ��ʧ�˲��٣�\n" NOR;
                                if ( damage <=0 ) 
                                { 
                                        msg += BLU "\n$n�����е�յ����ģ��ƺ��������˵�Ӱ�졣\n" NOR; 
                                        damage = 10 ;
                                }
                                if( damage > 0 ) damage +=random((damage*(int)me->query_skill("spells"))/100);
                                if (( damage > 0 ) && (damage >=(int)target->query("mana"))) target-> set("mana", 0);
                                if (( damage > 0 ) && (damage < (int)target->query("mana"))) target-> add("mana", -damage);

                                break;
                        }
                } else {
                msg += "����$n����һԾ���㿪����һ����\n";
        
        }
        message_vision(msg, me, target);
        if( ( damage > 0 ) && ( msgnum == 1 ))COMBAT_D->report_status(target);
        if( ( damage > 0 ) && ( msgnum == 2 ))COMBAT_D->report_sen_status(target);

        return 3+random(3);
}

