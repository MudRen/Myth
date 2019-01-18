// double.c
// by junhyun@SK
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, string arg)
{
        object weapon, weapon1, target;
        int skill, skill1;
// string msg;

    if(!arg) return notify_fail("�����˭һ��˫����赣�\n");

    if(!objectp(target = present(arg, environment(me))))
             return notify_fail("����û������ˡ�\n");

    if (me->query("gender") == "����")
            return notify_fail("�㲻�ò��˺ϱڡ�\n");

    if (target->query("gender") == "����")
    return notify_fail("�Է����ܺ���ϱڡ�\n");

    if (me->query("gender") == target->query("gender"))
    return notify_fail("�ϱ���Ҫ������ͨ���Է��޷����������⣬�޷��ϱڡ�\n");

    if( !target->is_fighting() || !target->is_character() || !me->is_fighting() )
                return notify_fail("˫�����ֻ����ս����ʹ�á�\n");

    if(!living(target))
                return notify_fail(target->name()+"�Ѿ��޷�ս���ˡ�\n"); 

    if(target==me) return notify_fail("����Լ���赣�\n"); 
    if(me->is_fighting(target))
                return notify_fail("�����ں�"+target->name()+"����ء�\n");            

    weapon = me->query_temp("weapon");  
    weapon1 = target->query_temp("weapon");  

    if(!weapon || weapon->query("skill_type") != "sword"
      || me->query_skill_mapped("sword") != "qinghu-jian"
      || me->query_skill_mapped("parry") != "qinghu-jian")
        return notify_fail("�������޷�ʹ�á�˫����赡���\n");

    if(!weapon1 || weapon1->query("skill_type") != "sword"
      || target->query_skill_mapped("sword") != "qinghu-jian"
      || target->query_skill_mapped("parry") != "qinghu-jian")
        return notify_fail(target->name()+"�����޷�ʹ�á�˫����赡���\n");


    skill = me->query_skill("qinghu-jian", 1);
    skill1 = target->query_skill("qinghu-jian", 1);
    
    if(skill < 120 )
        return notify_fail("�����������ȼ�����������ʹ�á�˫����赡���\n");
    
    if( skill1 < 120 )
        return notify_fail( target->name()+"����������������죬�޷��������ʹ�á�˫����赡���\n");

    if((int)me->query_skill("jiuyin-force", 1) < 120 )
        return notify_fail("��ľ����澭�ȼ�����������ʹ�á�˫����赡���\n");       

    if((int)target->query_skill("jiuyin-force", 1) < 120 )
        return notify_fail(target->name()+"�ľ����澭�������죬�޷��������ʹ�á�˫����赡���\n");       
    
    if (me->query_skill_mapped("force") != "jiuyin-force")
                return notify_fail("����ʹ�õ��ڹ����ԡ�\n");

    if((int)me->query("force") < 500 )
        return notify_fail("����������̫��������ʹ�á�˫����赡���\n");

    if((int)target->query("force") < 500 )
        return notify_fail( target->name()+"��������̫��������ʹ�á�˫����赡���\n");

    if((int)me->query("max_force") < 1000 )
        return notify_fail("����������̫��������ʹ�á�˫����赡���\n");

    if((int)target->query("max_force") < 1000 )
        return notify_fail("����������̫��������ʹ�á�˫����赡���\n");

    if(me->query_temp("gumu_double")) 
        return notify_fail("���Ѿ���ʹ�á�˫����赡��ˡ�\n");

    if(target->query_temp("gumu_double")) 
        return notify_fail(target->name()+"�Ѿ���ʹ�á�˫����赡��ˡ�\n");
    
    if(me->query_temp("gmdouble_target")){
          if(me->query_temp("gmdouble_target")==target)
                return notify_fail("���Ѿ����ú�"+target->name()+"˫����赵�׼���ˡ�\n");
          else               
               tell_object(me->query_temp("gmdouble_target"), YEL+me->name()+"�������������˫������ˡ�\n"NOR); 
               me->delete_temp("gmdouble_target");
               
          }
    if(target->query_temp("gmdouble_target") ==me){
        message_vision(HIW"
$N��Ȼ����һ����һʽ���չȴ�������Խ�ϰ�գ������ᶶ��"+weapon->name()+"�ڿ��л���һ�����£�\n"NOR,me,target);
        message_vision(HIW"
$n���������һ�С���Ѩ���硹��ƮȻ��$N���£�����"+weapon->name()+"�������ϼ���$N��"+weapon1->name()+"�ϣ�

��ʱ�佣�����࣬���������ĸ�Ϊ�����ˣ�\n"NOR,me,target);
    
        me->set_temp("gmdouble_target", target);
        me->set_temp("gumu_double", 1); 
        target->set_temp("gumu_double", 1); 
        me->add("force", -300);
        target->add("force", -300);
        me->add("sen", -50);
        target->add("sen", -50);
        call_out("check_fight", 1, me, skill, (skill+skill1)/2);
        call_out("check_fight", 1, target, skill1, (skill+skill1)/2);
                return 1;
        return 1;
        }
    message_vision(YEL"$N������"+weapon->name()+"һ�ᣬ��ʾ$n��$Pһ������˫����赡�\n"NOR,me,target);
    tell_object(target, YEL"�����Ը���"+me->name()+"����˫���ϱڣ���Ҳ��"+me->name()+"��һ�� ( perform double player<name> ) �����\n"NOR);     
    me->set_temp("gmdouble_target", target);
    return 1;
}
void remove_effect(object me, int skill)
{
                if(me->query_temp("gumu_double")){
                me->delete_temp("gumu_double");
                me->delete_temp("gmdouble_target");
                message_vision(HIR"$N˫�������ᣬ����Ҳ�ָ������ˡ�\n"NOR, me);
        }
}
void check_fight(object me, int skill, int count)
{
        object weapon;
        object target;

        if (!me) return;
        if (count < 1 || !me->is_fighting()) {
                remove_effect(me, skill);
                return;
        }
        target = me->query_temp("gmdouble_target");
        if (!target || !target->is_fighting()) {
                remove_effect(me, skill);
                return;
        }
        if (target->query_temp("gmdouble_target") != me) {
                remove_effect(me, skill);
                return;
        }
        weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "sword") {
                remove_effect(me, skill);
                return;
        }
        if (me->query_skill_mapped("sword") != "qinghu-jian"
                || me->query_skill_mapped("parry") != "qinghu-jian") {
                remove_effect(me, skill);
                return;
        }
        if(environment(me) != environment(target)) {
                remove_effect(me, skill);
                return;
        }
    call_out("check_fight", 1, me, skill, count-1);
}
 

