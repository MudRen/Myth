//sanban, �޵����師
//created 6-10-97 pickle
 
#include <ansi.h>
 
inherit SSERVER;

int perform(object me, object target)
{
        string msg,targetrude;
        int success,hurt,diff,damage;
        int myexp=(int)me->query("combat_exp")/5000;
        int mylev=(int)me->query_skill("axe");
        int mystr=(int)me->query("str")+(int)(me->query_skill("unarmed")/10-2);
        int mykar=(int)me->query_kar();
        int targetlev, targetstr,targetkar,targetexp,targeteffkee;
        string *hitone = ({
        "$n��ͼ����ܿ�����Ϊʱ���������ڼ��ϣ�����һ����ɼ��ǵ��˿ڣ�\n",
        "$n�߾����б�����ͼ�ܿ���������ס$N�����ƣ�������³�һ����Ѫ��\n",
        "$n�Թ�Ϊ�أ���ȥ�Ʋ�����������Ƶ�$N�ظ��Ի�����������$n������һ���˿ڡ�\n",
        });
        string *missone = ({
        "$n����һ�����󸫴���һ�󾢷�����ն�£���û�˵�$n�ֺ���\n",
        "$n�߾����б��з���һ�ܣ�ֻ����������һ�����죬$N�޸��ѱ�������\n",
        "$n���˴����ƣ�������$N�������Ƶ�$N���ò��ظ��Ա�����һ�ơ����ϡ��ʹ���ա�\n",
        });
        string *hittwo = ({
        "$n�ƺ�û�о���Σ�գ�˳��һ����������������֮����Ϊʱ���������Ѷ���һ�����糤���˿ڣ�\n",
        "$nû���$N�������֮�죬��æ��ͷ���ܣ����޷��㿪�������л���Ƥ��������\n",
        "$n������Ȼ�������������ط������ϱ����һƬƤ����Ȼ�˵ò��ᣡ\n",
        });
        string *misstwo = ({
        "$n�Դ�΢΢һ�࣬�ܹ���$N�Ĺ��ơ�\n",
        "$n�ƺ������ϵ���һ�У�˳���ڸ�����һ�ƣ����˿�ȥ��\n",
        "�ۿ�����Ҫ��$n�Դ������Դ���ͻȻ��$nʹ�������ţ����ֵ����˸��ա�\n",
        });
        string *hitthree = ({
        "$n�ƺ��ѱ����������������������˵�������ɢɢ��һ�ᣬ���󸫺����ڼ�ͷ��\n",
        "$n��׼���ƣ������б�����ȥ�������������ģ�����ͷ��û��ڳ�Ѫ����Ȼ���˲��ᣡ\n",
        "$n�ۼ�������������ͼ��ͷ�ܹ��������ϴ�������������$n���ϸ���һ��ƬƤ�⣡\n",
        });
        string *missthree = ({
        "$n�ƺ�������֪����·����δ������������ƮƮ�رܿ��ˡ�\n",
        "$n�ۼ��㲻�����У���æ�ڵ���һ������Ȼ�ܵ��Ǳ�����˿��û�����ˡ�\n",
        "$n��������Σ�գ��й�ֱ������$N��ȥ����Ȼ�����л����ˡ�\n",
        });
        string *hit=({
        RED"$N����Ҳ���㳢�����޵����師��������\n"NOR,
        RED"���޵����師һ���ǳɣ�$n�����˸����ֲ�����������Ϊ���£�\n"NOR,
        RED"$N��Ц������ƾ����㱾�£�Ҳ�����Ҷ���\n"NOR,
        });
        string *miss;
  
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�޵����師�������źÿ��ģ�ֻ�ܶ�ս������ʩ�á�\n");
        targetrude=RANK_D->query_self_rude(target);
        targetexp=(int)target->query("combat_exp")/5000;
        targetlev=(int)target->query_skill("parry");
        targetstr=(int)target->query("str")+(int)(target->query_skill("unarmed")/10-2);
        targetkar=(int)target->query_kar();
        miss=({
        BLU"$n������Ц����"+targetrude+"��˵���޵����師�ж�������������һ����Ҳ��������\n"NOR,
        BLU"$n��Цһ������$N��м��˵��������㱾�£�"+targetrude+"��û�������\n"NOR,
        BLU"$n�����Ц��������ʲô���£������ó����ɣ�\n"NOR,
        });
        if((string)me->query_skill_mapped("force")!="lengquan-force")
                return notify_fail("�޵����師��������Ȫ��Ϊ���ӡ�\n");
        if(me->query_skill("lengquan-force",1) < 100)
                return notify_fail("����ڹ����Ӳ��㣬�޷��˸���磬ʩչ�����޵����師��\n");
        if(me->query_skill("sanban-axe",1)<100)
                return notify_fail("�����������������Ϥ���޷�һ���ǳɵ�ʹ����\n");
        if(me->query("max_force") < 1000 || me->query("force")<500)
                return notify_fail("����������㣬��������Ӷ�һ���󸫡�\n");
        msg = CYN "$Nһ�����ȣ����ϣ��������Ͷ��䣡����һ���ǳɣ�\n\nֻ��һ����Ӱ��������ֱ��$n���ţ�\n" NOR;
        if( random(mylev+targetlev+mystr*3+targetstr*3) > (targetlev+targetstr*3))
        {
                msg += hitone[random(sizeof(hitone))];
                success+=1;
                if(random(mykar+targetkar)>targetkar) hurt+=1;
                damage=15+random(mykar/3);
        }
        else msg+=missone[random(sizeof(missone))];
        msg+=CYN"\n$N���Ѿ�������˳���Ը�β���ּ⵶����$n���ţ�\n"NOR;
        if( random(myexp+targetexp+mylev+targetlev) > (targetexp+targetlev))
        {
                msg += hittwo[random(sizeof(hittwo))];
                success+=1;
                if(random(mykar+targetkar)>targetkar) hurt+=1;
                damage+=15+random(mykar/3);
        }
        else msg+=misstwo[random(sizeof(misstwo))];
        msg+=CYN"\n$NѸ�����׵ط�ת��ͷ������$n�Դ�������ȥ��\n"NOR;
        if(random(myexp+targetexp+mykar*10+targetkar*10)>(targetexp+targetkar))
        {
                msg+=hitthree[random(sizeof(hitthree))];
                success+=1;
                if(random(mykar+targetkar)>targetkar) hurt+=1;
                damage+=15+random(mykar/3);
        }
        else msg+=missthree[random(sizeof(missthree))];
        diff=3-success;
        if (diff<0) diff = 0;
        if (success) hurt=damage*hurt/success;
        else hurt=0;
        me->add("force", -(150*success+70*diff));
        targeteffkee=(int)target->query("eff_kee");
        target->receive_wound("kee", targeteffkee*hurt/100);
        target->receive_damage("kee", target->query("kee")*(damage-hurt)/100);
        if(success)
        {
                me->start_busy(1+random(4-(mykar+5)/10));
                msg+=hit[random(sizeof(hit))];
        }       
        else
        {
                me->start_busy(random(4-(mykar+5)/10));
                msg+=miss[random(sizeof(miss))];
        }
        message_vision(msg, me, target);
        if(success && me->query_temp("jjftop") && living(target))
        {
                target->receive_damage("kee", target->query("kee")*(damage-hurt)/40);
                msg=HIG"$N�е��������࣬���а師˳�ƻذ⣬һ������$n��\n$n��ʱ������Ѫ��ģ���������ڵ��ϣ�\n";
                message_vision(msg, me, target);
        }
        return 1;
}

