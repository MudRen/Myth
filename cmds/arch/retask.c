
#include <ansi.h>

int main(object me)
{
        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;

          if( !wizardp(me) )
                return notify_fail("��Ҳ���ʹ�ô����������·ֲ�ʹ����:(\n");

/*
          message("system",HIR "\n\n���·ֲ�����ʹ��������"NOR,users()); 
          TASK_D->init_dynamic_quest(1);
          message("system",HIG "������ʹ�����·ֲ����\n\n"NOR,users()); 
*/
          CRON_D->create();
          DISASTER_D->disaster(0);
          return 1;
}
                
 int help(object me)
{
  write(@HELP

retask �������������²����У���ɺ�û��ɣ���ʹ�����������

HELP
    );
return 1;
}


