//created by mind 2001/2


#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{       
        string str;
        int damage,wound;
        object weapon=me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ�������� �ǳ�������\n");

        if(!me->is_fighting())
                return notify_fail("�������� �ǳ�����ֻ����ս����ʹ�ã�\n");
        
   if (!PFM_D->valid_family(me, "����ɽ"))
                return notify_fail("�������͵���ľ��С������� �ǳ�������\n");
        
        if( (int)me->query("bellicosity") > 1000 )
        return notify_fail("���ɱ��̫�أ������Ϻ�Х�ʽ�Ҫ�塣\n");      
                
        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");
              if( time()-(int)me->query_temp("dunno_end") < 4 )   
              return notify_fail(CYN"�������� �ǳ��������������̫��,�޷�����ʹ�ã�\n"NOR);   

        if((int)me->query("force") < 300 )
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("zhaoyangbu", 1) < 100)
                return notify_fail("��ĳ���������Ϊ��������ʹ����һ�л������ѣ�\n");
        if((int)me->query_skill("huxiaojian", 1) < 100)
                return notify_fail("��ĺ�Х�ʽ�������Ϊ��������ʹ����һ�л������ѣ�\n");

   message_vision(HIC"$N��Х�ʽ�������Ҫּ�������� �ǳ�����������������������ʽ�ۼ���ѭ��$n��ȥ��\n"NOR,me,target, "");
            target->start_busy(1);
        me->set("dunnoname", 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("dunnoname", 9);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("dunnoname", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("dunnoname", 11);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("dunnoname", 12);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("dunnoname", 13);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->delete("dunnoname");
//        me->start_busy(2);
     message_vision(HIC"$N���������ʹ�����У�������չ.\n"NOR,me,target, "");
        if (target->query("eff_kee")<0 || !living(target))  
        {
//        str=target->name()+"��"+me->name()+"�õľ��С������� �ǳ�����ɱ���ˡ�\n��˵"+target->name()+"��������֪������ʲô��ʽ֮�£�";
//        message("channel:rumor",HIM"����Ѩ���硿ĳ�ˣ�"+str+"\n"NOR,users());
        }
        
        me->add("kee", -50);
        me->add("force", -150);
       me->add("sen",-50);
            me->set_temp("dunno_end",time());   

        return 1;
}

