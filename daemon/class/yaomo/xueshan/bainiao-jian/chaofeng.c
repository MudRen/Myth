// Update by waiwai@2001/06/13
// Update by waiwai@2002/12/05
// ���������书���ڻ�����Ӱ�죬��϶�̬����Ӧ��

#include <ansi.h>
inherit SSERVER;

string get_name(string str)
{
        str="���񳯷�";
        return str;
}

string get_help(string str)                
{
        str="ָ������������������\n"
        +"���񳯷�������ʺ������Ѿ���ǿ��";
        return str;
}

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ii, req, num_anqi, num_hit; 
        int max_hit, hitt, damage, op, opfa, remain, t;
        string anqi_type, b_unit;

        string *list, s_room;
        object other, env;
        mapping exit;
        int i;

        int wound=0;

        if( !target ) target = offensive_target(me);
        
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ����˭��\n");
        
        weapon = me->query_temp("weapon");

        req=(int)me->query_skill("sword", 1)+(int)me->query_skill("bainiao-jian", 1)+
                         (int)me->query_skill("throwing", 1); 

        if(!weapon || (string)weapon->query("skill_type") != "sword")
                return notify_fail(WHT"�����װ��������ʹ�á����񳯷\n"NOR);

        if(weapon) {
                if(weapon->query("anqi/allow") != 1) num_anqi=0;
                        else num_anqi=weapon->query("anqi/now");
        }

        if( userp(me) ) {
                if(me->query_skill_mapped("force")!="ningxie-force")
                        return notify_fail("���񳯷������ϱ�����Ѫ������ʹ�á�\n");

                if(me->query_skill_mapped("throwing")!="bainiao-jian")
                        return notify_fail("���񳯷������ϰ���ʹ�ò���ʹ�á�\n");

        if(req < 120) return notify_fail("�㽣�д����Ĺ��򻹲������\n");
        }

        if(req < 150 && weapon->query("anqi/now") ==0)
                return notify_fail("�㽣��û�а����ɴ�\n");

        if (me->query("force")<200)
                return notify_fail("���������̣������������롣\n");
/*
        if( ((t=(int)me->query_temp("chaofeng_time")) <= time() )
            && (time()<t+4) ) 
        {  
                return notify_fail(CYN"���������ʤ�����񳯷��ʹ�Ͳ����ˡ�\n"NOR);
        } else me->delete_temp("chaofeng_time");
*/
        
        if( time()-(int)me->query_temp("chaofeng_time") < 3 )            
                return notify_fail("���������ʤ�����񳯷��ʹ�Ͳ����ˡ�\n");
                
        if (!PFM_D->valid_family(me, "��ѩɽ"))
                return notify_fail("�㲻�Ǵ�ѩɽ���ӣ���ô��ʹ�ô�ѩɽ������\n");
                
        me->add("force", -100);

        if(num_anqi <=0) 
        { 
                anqi_type="����"; 
                damage=me->query("force_factor")+10; 
        }
        else if (req < 150)
        { 
                anqi_type=weapon->query("anqi/type"); 
                damage=me->query_temp("apply/damage");
        }
        else 
        { 
                anqi_type=weapon->query("anqi/type")+HIR"���Ž���"NOR;
                damage=me->query_temp("apply/damage")+me->query("force_factor")+10;
        }
         
        msg = HIW"ֻ��$N����"+weapon->query("name")+NOR HIW"�������ó����콣â������"
                 +anqi_type+HIW"���� "HIR"��"HIB"��"HIY"Ͷ"HIM"��"HIW" ��Ϯ��$n \n" NOR;


        // Added by waiwai@2002/12/05
        // �����ۺ����������书���ڻ�����Ӱ��
        env=environment(me);

        exit=env->query("exits");

        if( exit ) {
                list=keys(exit);

                for(i=0;i<sizeof(list);i++) {
                        s_room=env->query("exits/"+list[i]);
                        if(!other=find_object(s_room))  other=load_object(s_room);
                        tell_object(other,WHT"����ͻȻ���������˺ɱ�����ƺ���ѩɽ�ɵİ�����ֱ�������������\n"NOR);
                }
        }



        if (num_anqi > 10 || num_anqi == 0) max_hit=10;
        else max_hit=weapon->query("anqi/now");

        num_hit=random(max_hit/2)+(max_hit/2);

        if (!target->is_fighting(me)) opfa=40;
        else opfa=20;

        if (target->query("combat_exp")  !=0 ) 
               op= me->query("combat_exp")*opfa/target->query("combat_exp");
        else op=10;
        hitt=0; 
        for (ii=1;ii<=num_hit;ii++)  
        {
                if (op > random(60)) hitt++;
        }

        if (weapon->query("anqi/type")=="��ȸ��") b_unit="֧";
        else b_unit="��";
        if (weapon->query("anqi/now") != 0) remain=weapon->query("anqi/now")-num_hit;
        else remain=0;
        weapon->set("anqi/now",remain);
        if (weapon->query("anqi/now") == 0) 
        {
                weapon->delete("anqi/type");  
                weapon->set("long",weapon->query("orilong"));
        }
        else weapon->set("long",weapon->query("orilong")+"�����Ѿ�װ��"
           +chinese_number(weapon->query("anqi/now"))+b_unit+weapon->query("anqi/type")+"\n"); 

        if (hitt==0) {
                msg += HIY"$n"HIY"��æ����һת�����������������������컨����һ����\n"NOR;
                message_vision(msg, me, target);
                me->start_busy(random(2));
        } else {
                // By waiwai@2001/05/05 changed.
                damage=damage*hitt+random(req);
                target->receive_damage("kee",damage,me,"pfm");
                if(damage>target->query_temp("apply/armor")) 
                {
                        target->receive_wound("kee",damage-target->query_temp("apply/armor"),me,"pfm");
//                        target->receive_wound("kee",damage,me,"pfm");
                        wound=1;
                }

        if (weapon->query("anqi/type")=="������") 
                target->apply_condition("ice_poison", 3);

        msg += HIR "\n$n"HIR"�������������� "HIW+chinese_number(hitt)+HIR " ������"+anqi_type+"��\n\n"NOR;
                message_vision(msg, me, target);
                me->set_temp("chaofeng_time",time());
//                me->start_busy(1);
                COMBAT_D->report_status(target,wound);
                if(!target->is_busy()) target->start_busy(2+random(3));
        }

        msg = HIG"$n"HIG"����$N"HIG"����������ð����ҷŰ�����������ô��ʰ�㣡\n" NOR;     
        message_vision(msg, me, target);
        me->kill_ob(target);

        return 1;
}


