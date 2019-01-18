// ��ǿperform����
// add by bird
//perform.c
#include <ansi.h>
#include <skill.h>
#include "/cmds/std/valid_kill.h";

inherit F_CLEAN_UP;

//bird 04/3/31 add performs checking
int show_perform(string arg)
{
         mixed *files;
         string dir=SKILL_D(arg)->perform_action_file(""); //���skill��·��
         string pfms="";
         int i;

         if(!dir) return notify_fail("ʲô");
         files=get_dir(dir+"*.c",-1);
         for(i=0;i<sizeof(files);i++)
                   pfms+="�� "+files[i][0][0..<3]+" ��\n";
         write("��Ŀǰ����ʹ�õ���ʽ�У�\n");
         write(pfms);
         return 1;
}

int main(object me, string arg)
{
         object weapon, target;
         string martial, skill, perf;
         int show;

         seteuid(getuid());

         if( me->is_busy() )
                     return notify_fail("( ����һ��������û����ɣ�����ʩ���⹦��)\n");
         if( !arg ) show=1;
         if ( !wizardp(me) && environment(me)->query("no_fight"))
                     return notify_fail("���ﲻ��ʩ���⹦��\n");

         if( arg&&sscanf(arg, "%s on %s", perf, arg)==2 ) {
                  target = present(arg, environment(me));
                  if( !target ) target = present(arg, me);
                  if( !target ) return notify_fail("����û�� " + arg + "��\n");

                  if(!valid_kill(me,target,0)) return 0;
                  set_to_killer(me,target);
                  if( userp(me) && userp(target) &&
                  target->query_temp("netdead") )
                  return notify_fail("�Է����ڶ����У����ܶ���ʩ���⹦��\n");
                  arg=perf+" "+arg;
 } else if(arg&&sscanf(arg, "%s %s", perf, arg)==2 ) {
    arg=perf;
}
         if( weapon = me->query_temp("weapon") )
             martial = weapon->query("skill_type");
       else
             martial = "unarmed";

         if( stringp(skill = me->query_skill_mapped(martial)) ) {
             notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");
             
             if(show) {show_perform(skill);return 1;}
             if( SKILL_D(skill)->perform_action(me, arg) ) {
                 if( random(120) < (int)me->query_skill(skill) )
                    me->improve_skill(skill, 1, 1);
                 return 1;
             } else if( SKILL_D(martial)->perform_action(me, arg) ) {
                 if( random(120) < (int)me->query_skill(martial, 1) )
                    me->improve_skill(martial, 1, 1);
                 return 1;
             } 
             return 0;
       }   
             martial = "literate";
             if( stringp(skill = me->query_skill_mapped(martial)) ) {
                notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");
             if(show) {show_perform(skill);return 1;}
             if( SKILL_D(skill)->perform_action(me, arg) ) {
                   if( random(120) < (int)me->query_skill(skill) )
                         me->improve_skill(skill, 1, 1);
                   return 1;
             } else if( SKILL_D(martial)->perform_action(me, arg) ) {
                   if( random(120) < (int)me->query_skill(martial, 1) )
                        me->improve_skill(martial, 1, 1);
                   return 1;
             }
             return 0;

             }
             if(show) notify_fail("������û�п���ʹ�õ���ʽ��\n");
             else notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ��⹦��\n");
             return 0;
}
int help (object me)
{
       write(@HELP
ָ���ʽ��perfrom [<�书����>.]<��ʽ����> [<ʩ�ö���>]
�������ѧ���⹦(ȭ�š�����������....)��һЩ����Ĺ�����ʽ����ʽ������
�����ָ����ʹ�ã���������� enable ָ��ָ����ʹ�õ��书����ָ���书��
��ʱ�����ֵ��⹦��ָ���ȭ�Ź���ʹ������ʱ���Ǳ��е��书��

���仰˵��ֻҪ�� enable �е��书��������ʽ�ģ������������ָ��ʹ�á�
HELP
        );
       return 1;
}
