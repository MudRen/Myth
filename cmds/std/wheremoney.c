#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
         
        string str;

        if(me->is_busy()) return notify_fail("����æ���أ�\n");
       
        if (stringp("/adm/daemons/ran_moneyd"->show_msg()))
           {
           str="/adm/daemons/ran_moneyd"->show_msg();
           write(CYN"\n�콵�����б�������ˣ��ƺ��ڣ�\n"NOR+str);
           me->start_busy(2);
           }
           else 
           {write(HIR"\nŶ�ޣ����ϵĲƱ�ȫ�����ˡ���\n\n"NOR);
            }
            
        return 1;
                 
}

