//by dewbaby@sk_sjsh
//guang.c
//����Ӱ���⡿escape from combat


#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
        if( !target ) target = offensive_target(me);

        if( (int)me->query("mana") < 50 )
                return notify_fail("��ķ��������ˣ�\n");

        if( (int)me->query("sen") < 50 )
                return notify_fail("��ľ����޷����У�\n");

              if((string)me->query("family/family_name") !="�躣��")
                return notify_fail("ֻ���躣�����˲Ż�˷���!\n");

        if( me->query("gender") =="����" )
                return notify_fail("�貨����ֻ��Ů�����У��������͵ѧ���ģ�\n");         


        message_vision(HIC"$NĬ���˼�������...\n\n"HIC"�������Բ�����ס��\n", me);

        me->add("mana", -20);
        me->receive_damage("sen", 20);

        if(me->is_fighting() ) {
        if(random((int)me->query("combat_exp")) >=(int)target->query("combat_exp")/2) {
                           message_vision(WHT"$N"WHT"���������֣��û��ɵε�¶ˮ����ʧ�ڿ�����.....\n"NOR, me);
            me->move("/u/dewbaby/wangxian/huxin");

            tell_room(environment(me),
        WHT"��̼䣬�������һƬ������ɨ�ǣ�ֻ��"+me->query("name")+"��һƬ�����������߳���\n\n"NOR, ({me, me}) );
            
            } else {
        message_vision(WHT"$N������ȥ���˰��죬ȴ���ֺ������á�\n"NOR, me, target);
            me->start_busy(1+random(1));
             }
        } else {        message_vision(WHT"$N"WHT"���������֣��û��ɵε�¶ˮ����ʧ�ڿ�����.....\n"NOR, me); 
            me->move("/u/dewbaby/wangxian/huxin");
     
            tell_room(environment(me), 
        WHT"��̼䣬�������һƬ������ɨ�ǣ�ֻ��"+me->query("name")+"��һƬ�����������߳���\n\n"NOR, ({me, me}) );        }

        return 1;
}



