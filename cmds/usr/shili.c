
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me)
{
         string faname=me->query("family/family_name");   

          if( ! faname )
           return notify_fail("���������ɶ�û�к����������ԣ�\n");
        write("���������"+HIC+faname+NOR+"���������£�\n");
write("������������������������������������������������������������������\n");   
     "/adm/daemons/shili"->query_all_shili(faname);
write("������������������������������������������������������������������\n"); 

        return 1;
           
}

 
int help(object me)
{
        write(@HELP
ָ���ʽ : shili
���ָ����������ڵ�������ȡ��·�ĸ����ϵķ�Χ����.
HELP
    );
    return 1;
}                     
