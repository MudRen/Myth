
#include <ansi.h>

int main(object me)
{
        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;

          if( !wizardp(me) )
                return notify_fail("玩家不能使用此命令来从新分布使命！:(\n");

/*
          message("system",HIR "\n\n重新分布所有使命．．．"NOR,users()); 
          TASK_D->init_dynamic_quest(1);
          message("system",HIG "．．．使命重新分布完毕\n\n"NOR,users()); 
*/
          CRON_D->create();
          DISASTER_D->disaster(0);
          return 1;
}
                
 int help(object me)
{
  write(@HELP

retask 命令是用来重新布所有（完成和没完成）的使命（ｔａｓｋｓ）

HELP
    );
return 1;
}


