#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob, where;
        int i, skill, damage, force;

        where=environment(me);
        if( where->query("no_fight") )
                return notify_fail("���ʱ���ڴ���\n");
       if (!present("yu xiao", me))
                return notify_fail("�봵�ࡸ�̺�������û��������ô�У�\n");
        if( !me->is_fighting() )
                return notify_fail("û�˴���ѽ����ʲôѽ��\n");
        if (!PFM_D->valid_family(me, "��ԯ��Ĺ"))
                return notify_fail("�⡺�̺�������������ԯ��Ĺ�ľ��ܣ�����ε�֪�ģ���\n");
        if( (int)me->query("force") < 200 )
                return notify_fail("�������������\n");
        if( (int)me->query("kee") < 100)
                return notify_fail("������������ˡ�\n");
        if (me->query_skill("xiao",1)<100)
                return notify_fail("��ᴵ��ô��Ϲ����\n");
        if (me->query_skill("jiuyin-force",1)<200)
                return notify_fail("û��ôǿ���ڹ���С���߻���ħ��\n");
        skill = me->query_skill("force");
        force = me->query("max_force");
        me->add("force", -150);
        me->receive_damage("kee", 50);

        me->start_busy(5);
        message_vision(HIG "$N����һ̽,���ж��һֻ����,ֻ��$N��̤�Ź����Եķ�λ����Ĵ���������\n\n"NOR,me); 
        message_vision(HIC "��֪�����а����ϳ������������߶����Բ�����ħ���壬��������������\n"NOR,me);
        message_vision(HIW "               ���������Ծ����澭Ϊ�����Ĺ�Ĺ��ѧ\n\n"NOR,me); 
        message_vision(HIW+BLINK"                        ���̺���������\n\n"NOR,me);
 ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if(!me->visible(ob[i])) continue;
                if( skill/2 + random(skill/2) < (int)ob[i]->query("cps") * 2 ) continue;

                damage = skill + force/5 - ((int)ob[i]->query("max_force") / 5);
                if( damage > 0 ) {
                        ob[i]->receive_damage("sen", damage,me,"pfm");
                        if( (int)ob[i]->query("force") < skill * 2 )
                                ob[i]->receive_wound("sen", damage/2,me,"pfm");
  message_vision(HIR "$n������������������һ��,ֻ��������һ��¶�,���岻���������������裡\n\n"NOR,me,ob[i]); 
                        tell_object(ob[i], "�������ǰһ�������ð���Դ�ʹ������Ҫ�ѿ�һ����\n");
                }
                COMBAT_D->report_sen_status(ob[i]);             
                if( userp(ob[i]) ) ob[i]->fight_ob(me);
                else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);

        }

        return 1;
}

