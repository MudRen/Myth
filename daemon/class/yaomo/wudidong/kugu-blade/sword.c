
#include <ansi.h>

inherit SSERVER;

string get_name(string str)
{
        str="���⽣Ӱ";
        return str;
}

string get_help(string str)                
{
        str="ָ����������������\n"
        +"�������ݹǵ���180�������޽���180�����������1000";
        return str;
}

int perform(object me, object target)
{
        
        object *inv, obj, obj1;
        int i, j, mypot, tapot;
        string str;

        object weapon1, weapon2;
       
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С����⽣Ӱ����\n");

        if(!me->is_fighting())
                return notify_fail("�����⽣Ӱ��ֻ����ս����ʹ�ã�\n");

        if (!PFM_D->valid_family(me, "�ݿ�ɽ�޵׶�"))
                return notify_fail("������͵���ľ�����\n"); 
                
        if((int)me->query("max_force") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 600 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        i=(int)me->query_skill("kugu-blade",1);
        j=(int)me->query_skill("qixiu-jian",1);
        
        if( i < 180)
                return notify_fail("��Ŀݹǵ������������죬ʹ����һ�л������ѣ�\n");
                
        if( j < 180)
                return notify_fail("������޽������������죬ʹ����һ�л������ѣ�\n");

        if( time()-(int)me->query_temp("wddsword_end") < 4 )
                return notify_fail("�����⽣Ӱ���ö��˾Ͳ����ˡ�\n");

        if (me->query_temp("xieji_busy")) 
                return notify_fail("[���⽣Ӱ]��[Ѫ��]��������ʹ��!\n");
                
        weapon1=me->query_temp("weapon");
        weapon2=present("sword", me);
        if(!objectp(weapon2)) 
                return notify_fail("���һ�ѵ���ô�á����⽣Ӱ����\n");

                
        message_vision(MAG"\n$N��$n���һ����˫Ŀ����һ�֣�����"+weapon2->query("name")+MAG"������"+weapon1->query("name")+MAG"��
��������ʹ����"HIW"���ݹǵ��������⽣Ӱ��"NOR""MAG"�������ա�������һ�С�
��ʱ����������ع�ɭɭ���������������$N�ޱȷ����ĵ��⽣Ӱ֮�С�\n\n"NOR,me,target);
                
        mypot=(int)me->query_skill("kugu-blade");
        mypot=mypot*mypot*mypot + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot+(int)target->query_skill("dodge")/10;
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");

       
        if( random( mypot+tapot ) > tapot/4 || !living(target) ) 
        {               
                message_vision(MAG"\nֻ��$n��ʱ�������Ʈҡ֮�䣬$Nǿ��ĵ�����$n����������������ʮ���Ǳ���\n\n"NOR,me, target);  
                COMBAT_D->do_attack_damage(me, target);
                target->receive_wound("kee", random(me->query_skill("blade")*3/2), me, "pfm");
                COMBAT_D->report_status(target);
                
                if (target->query("eff_kee")< -100 || !living(target))  
                {
                        str=target->name()+"��"+me->name()+"�ġ����⽣Ӱ��ɱ����ʬ�嶼�޴�Ѱ�١�";
                        CHANNEL_D->do_channel(me, "rumor",str);
                        me->delete_temp("last_channel_msg");}
                else 
                {
                        if ( random(10)>1 )
                        {
                                message_vision(MAG"\n\n$N����$nҡҡ��׹�����赶����ʤ׷�����İ�$n�������ء�\n"NOR,me,target);
                                COMBAT_D->do_attack_damage(me, target);
                                target->receive_wound("kee", random(me->query_skill("qixiu-jian")*3/2), me, "pfm");
                                COMBAT_D->report_status(target);
                                if(!target->is_busy())
                                        target->start_busy(2+random(2));
 
                        }
          
                }
        }        
     
        else  
        {
                message_vision(HIY"$N��$n�������ڣ��������ѻ�ʯ����æ�󳷣��㿪��$n�Ĺ�����\n"NOR, target, me);
         
        }
               
        me->add("force", -150);
        me->receive_damage("sen", 50);
        me->set_temp("wddsword_end",time());
        return 1;
}

