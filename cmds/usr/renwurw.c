// job.c
// creatied by passion@skxy
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
      object ob;
    mapping my;
    string line;
              if(!arg) ob = me;  
              else if (wizardp(me)) { ob = present(arg, environment(me));  
                   if (!ob) ob = find_player(arg);  
                   if (!ob) ob = find_living(arg);  
              if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");  
              }   
                      else return notify_fail("����Ȩ�쿴���˵�״̬��\n");  
     my = ob->query_entire_dbase();
/*
    if (!wizardp(ob) || arg == "") me = ob;
    else
    {
        if( arg ){
            me = present(arg, environment(ob));
            if (!me) me =  find_player(arg);
            if (!me) return notify_fail("��Ҫ�쿴˭��״̬��\n");
        }
        else {
*/
            me = ob;
              line = sprintf(" ��������:\n"); 
            line += sprintf(" �㵽ĿǰΪֹ�ܹ������%s����������", 
              HIR+my["m_win"]+NOR,);
              line += sprintf("������%s����������,", 
              HIR+my["m_fangqi"]+NOR,);
             line += sprintf("ʧ����%s��.\n", 
              HIR+my["m_shibai"]+NOR,);
            write(line); 
            return 1;
        }
int help(object me)
{
    write(@HELP
ָ���ʽ : job
���ָ�������ʾ����������ɹ�������
HELP
    );
    return 1;
}




