
#include <ansi.h>
inherit SSERVER;

#include "/daemon/skill/eff_msg.h";

string get_name(string str)
{
        str="������";
        return str;
}

string get_help(string str)                
{
        str="ָ�������������\n"
        +"������ǧ������100������������100���������ڹ�100���������Ṧ120���������1200"
        +"��perform����ǧ�������ļ��𻮷�Ϊ�����׶Σ�100��һ����120��������150������";        
        return str;
}

int def;

int perform(object me, object target)
{       
        object weapon1;
        string msg;
        int damage, p, time;
        
        if( !target ) target = offensive_target(me);
        
        if( !target 
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target) )
                return notify_fail("�������衹ֻ����ս����ʹ�á�\n");
                
        if (!PFM_D->valid_family(me, "����ɽ���Ƕ�"))
                return notify_fail("[������]��б�����Ƕ�����֮�ܣ�\n");
                
        if( !(weapon1 = me->query_temp("weapon"))
        ||      (string)weapon1->query("skill_type") != "stick" )
                return notify_fail("����Ϊ����˭��û��Ҳ�������裡\n"); 
                
        if( (int)me->query_skill("stick", 1) < 100 ||
           (int)me->query_skill("qianjun-bang", 1) < 100 )
                return notify_fail("��Ĺ�����������죬����ʹ�á������衹��\n");
                
        if((int)me->query_skill("dodge", 1) <120)
                return notify_fail("�������ڵ��Ṧ��Ϊ��Ρ������衹��\n");
                
        if((int)me->query_skill("force", 1) <100)
                return notify_fail("�������ڵ��ڹ���Ϊ��ʹ�����������衹��\n");
                
        if( (int)me->query("max_force") < 1200 )
                return notify_fail("�������ڵ��ڹ���Ϊ��ʹ�����������衹��\n");
                
        if( (int)me->query("force") < 600 )
                return notify_fail("�������������\n");
                
        msg = HIY "\n$Nʹ������ɽ�����������衹������Ȼ�ӿ죡\n" NOR;
        if (random(me->query("combat_exp")) > random(target->query("combat_exp")/3))
        {
                me->start_busy(2);
                target->start_busy(1);
                msg += YEL "\n$N��Ȼ��һ�������հ����裬��$n�����������"NOR;
                if ((int)me->query_skill("force", 1)> random((int)me->query_skill("force", 1)/4))
                {
                        msg += HIC "\n����$n���һ����������������,���$nֻ��ס��ʼ���У����޷���ά�����ȵ����衣\n" NOR;
                        damage = (int)me->query_skill("qianjun-bang", 1);
                        damage = damage + random(damage);
                        def=(int)target->query_temp("apply/armor_vs_force");
                        damage -=damage*def/3000;
                        target->receive_damage("kee", damage, me, "pfm");
                        target->receive_wound("kee", damage, me, "pfm");
                        me->add("force", -(damage/10));
                        p = (int)target->query("kee")*100/(int)target->query("max_kee");
                        msg += damage_msg(damage, "����");
                        msg += "( $n"+eff_status_msg(p)+" )\n";
                        message_vision(msg, me, target);
                        target->set_temp("last_damage_from", me);
                        if(me->query_skill("stick", 1) > 119)
                        {
                                remove_call_out("perform2");
                                call_out("perform2", 0, me, target);    
                        }
                } 
                else 
                {
                        msg += HIC "\n��ʱ�ƺ����ֲ��أ����䲨��״�Ĺ�Ӱ���˻�ǰ�ˣ�һ�˸߹�һ�ˣ����಻����\n"NOR;
                        message_vision(msg, me, target);
                        for (p=1;p<3+random(3);p++)
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                        if(random(me->query_skill("qianjun-bang", 1))> 119)
                        {
                                remove_call_out("perform2");
                                call_out("perform2", 0, me, target);    
                        }
                }
        } 
        else 
        {       
                me->start_busy(2);
                me->add("force", -100);                
                msg += HIG"����$p����һ�����㿪�˶��ֵĹ�����\n"NOR;
                if(me->query_skill("qianjun-bang",1)>119)
                {
                        remove_call_out("perform2");
                        call_out("perform2", 0, me, target);    
                }
                message_vision(msg, me, target);
        }
        return 1;
}



int perform2(object me, object target)
{
        int damage, p,skill;
        object weapon1;
        string msg,weapon,force_skill,force_skill_name;
        if(!target||!living(target)) return notify_fail("�����Ѿ�������ս���ˡ�\n");
        weapon = me->query_temp("weapon");  
        if( !(weapon1 = me->query_temp("weapon"))
        ||      (string)weapon1->query("skill_type") != "stick" )
                return notify_fail("����Ϊ����˭��û��Ҳ�������裡\n");
/*              
        force_skill = target->query_skill_mapped("force");
        if( !force_skill ) force_skill_name = "�����ڹ�";
        else                if( force_skill=="huntian-qigong" ) force_skill_name = "��������";
        else                if( force_skill=="lengquan-force" ) force_skill_name = "��Ȫ��";
        else                if( force_skill=="lotusforce" ) force_skill_name = "�����ķ�";
        else                if( force_skill=="moonforce" ) force_skill_name = "�¹��ķ�";
        else                if( force_skill=="ningxie-force" ) force_skill_name = "��Ѫ��";
        else                if( force_skill=="wuxiangforce" ) force_skill_name = "С���๦";
        else                if( force_skill=="dragonforce" ) force_skill_name = "�����ķ�";
        else                if( force_skill=="tonsillit" ) force_skill_name = "������";
        else                if( force_skill=="xuanhu-xinfa" ) force_skill_name = "�����ķ�";
        else                if( force_skill=="jiuyin-xinjing" ) force_skill_name = "�����ľ�";
        else                if( force_skill=="zhenyuan-force" ) force_skill_name = "��Ԫ��";
        else                if( force_skill=="shushan-force" ) force_skill_name = "��ɽ�ķ�";
        else                if( force_skill=="butian-force" ) force_skill_name = "�����ķ�";
        else                if( force_skill=="xuanzong-force" ) force_skill_name = "�����ķ�";
        else                if( force_skill=="huomo-force" ) force_skill_name = "��ħ�ķ�";
        else                force_skill_name = "�����ڹ�";
*/
        if( !target 
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target) )
                return notify_fail("�������衹����û������ѽ��\n");
        if( (int)me->query("force", 1) < 300 )
                return notify_fail("���Ҫ�ٳ��ڶ�����ȴ�����Լ������������ˣ�\n");     
        if (random(5)>2)
                msg = HIC"\n����$N���ϱ���,ͻȻһ������,���һ��,ļ���������,$n��ǰһ��!!\n"NOR;
        else
                msg = HIG"\n����$N���ϱ���,ͻȻ��Хһ��,�չ���ɨ,���Ƹ���,$n�����Ż����ֽ�!!\n"NOR;
        message_vision(msg, me, target); 
        if (random(me->query("combat_exp")) > target->query("combat_exp")/4)
        {
                //msg = CYN "$n����֮�£�"NOR+HIR+force_skill_name+NOR+CYN"��ʱ�����ٳ���$n�����޴��мܣ�\n" NOR;
                msg = CYN "$n����֮�£���ʱ�����ٳ���$n�����޴��мܣ�\n" NOR;
                me->start_busy(2);
                target->start_busy(2);
                damage = (int)me->query_skill("qianjun-bang", 1);
                damage = damage+(int)me->query_skill("force", 1);
                damage = damage + random(damage);
                def=(int)target->query_temp("apply/armor_vs_force");
                damage -=damage*def/3000;
                target->receive_damage("kee", damage, me, "pfm");
                target->receive_wound("kee", damage/2, me, "pfm");
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                target->set_temp("last_damage_from", me);
                if(me->query_skill("qianjun-bang", 1) > 149)
                {
                        remove_call_out("perform3");
                        call_out("perform3", 0, me, target);    
                }
        } 
        else 
        {       
                me->start_busy(2);
//                me->add("force", -200);                
                msg = WHT"����$p�ϵ�֮��,�������У�����$N�������ˡ�\n"NOR;
                if(me->query_skill("qianjun-bang", 1) > 149
                && me->query_skill("stick", 1) > 149)
                {
                        remove_call_out("perform3");
                        call_out("perform3", 0, me, target);    
                }
        }
        message_vision(msg, me, target);
        return 1;
}


int perform3(object me, object target)
{
        int damage, p,skill;
        object weapon1;
        string msg,weapon,force_skill,force_skill_name,*limbs;
        if(!target||!living(target)) return notify_fail("�����Ѿ�������ս���ˡ�\n");
        weapon = me->query_temp("weapon");  
        if( !(weapon1 = me->query_temp("weapon"))
             ||      (string)weapon1->query("skill_type") != "stick" )
                return notify_fail("����Ϊ����˭��û��Ҳ�������裡\n"); 
        if(!living(target)) 
                return notify_fail("�����Ѿ�������ս���ˡ�\n");
        if( !target 
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target) )
                return notify_fail("����������û������ѽ��\n");
/*                
        force_skill = target->query_skill_mapped("force");
        if( !force_skill ) force_skill_name = "�����ڹ�";
        else                if( force_skill=="huntian-qigong" ) force_skill_name = "��������";
        else                if( force_skill=="lengquan-force" ) force_skill_name = "��Ȫ��";
        else                if( force_skill=="lotusforce" ) force_skill_name = "�����ķ�";
        else                if( force_skill=="xuanhu-xinfa" ) force_skill_name = "�����ķ�";
        else                if( force_skill=="moonforce" ) force_skill_name = "�¹��ķ�";
        else                if( force_skill=="ningxie-force" ) force_skill_name = "��Ѫ��";
        else                if( force_skill=="jiuyin-xinjing" ) force_skill_name = "�����ľ�";
        else                if( force_skill=="wuxiangforce" ) force_skill_name = "С���๦";
        else                if( force_skill=="dragonforce" ) force_skill_name = "�����ķ�";
        else                if( force_skill=="tonsillit" ) force_skill_name = "������";
        else                if( force_skill=="shushan-force" ) force_skill_name = "��ɽ�ķ�";
        else                if( force_skill=="butian-force" ) force_skill_name = "�����ķ�";
        else                if( force_skill=="xuanzong-force" ) force_skill_name = "�����ķ�";
        else                if( force_skill=="zhenyuan-force" ) force_skill_name = "��Ԫ��";
        else                if( force_skill=="huomo-force" ) force_skill_name = "��ħ�ķ�";
        else                force_skill_name = "�����ڹ�";
*/
        if( (int)me->query("force", 1) < 800 )
                return notify_fail("���Ҫ�ٳ����Ļ���ȴ�����Լ������������ˣ�\n");     
        if (random(5)>2)
        {
                msg = HIC"\n$Nһ��������������Ȼ���ַɳ����������㰿������ƿ�����$n����磡\n"NOR;
                msg += HIC "$n���һ��������$N���������ϣ�˫�����õ��ģ���������֮��!\n" NOR;
        }
        else 
                msg = HIG"\n$N��Хһ����һʽ����غ��衹���ڿշ���ȫ��ų���������Ӱ��������ʣ�\n"NOR;
        message_vision(msg, me, target); 
        if (random(me->query("combat_exp")) > random(target->query("combat_exp")/8))
        {
                //msg = CYN "$n�������Ѿ�����������"NOR+HIR+force_skill_name+NOR+CYN",$N�������һ��\n" NOR;
                msg = CYN "$n�������Ѿ��������м�,$N�������һ��\n" NOR;
                me->start_busy(2);
                target->start_busy(1);
                damage = (int)me->query_skill("unarmed", 1);
                damage = damage+(int)me->query_skill("force", 1);
                //damage = damage*(1+random(3))/2+random(damage);
                def=(int)target->query_temp("apply/armor_vs_force");
                damage -=damage*def/3000;
                target->receive_damage("kee", damage, me, "pfm");
                target->receive_wound("kee", damage/2, me, "pfm");
                me->add("force", -100);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                limbs = target->query("limbs");
                msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
                msg = replace_string(msg, "$w", weapon->name());    
                message_vision(msg, me, target);
                target->set_temp("last_damage_from", me);
                me->start_busy(2);
        } 
        else 
        {       
                me->start_busy(1+random(2));
//                me->add("force", -200);                
                msg = HIC"����$pһ������,������$N�����Ľ�����\n"NOR;
                message_vision(msg, me, target);
        }
//                me->add("force",-500);                
        return 1;
}


