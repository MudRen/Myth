/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
//Last modified by waiwai@2001/04/19

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "ͷ�ؽ��ᣬ���ŷ��ȣ������������ˡ�\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "�����ͷ�ؽ��ᣬ���ŷ��ȣ������������ˡ�\n" NOR );
      message("vision", me->name() + "ֻ��������֮��һ���ڣ�ͷ�ؽ��ᣬ̧����ͷ�������ŷ��ȣ������������ˡ�\n",
            environment(me), me);
   }
   me->receive_wound("kee", 2);
   me->receive_damage("kee", 2);
   me->apply_condition("ill_zhongshu", duration - 1);

	// Update By waiwai@2001/06/15 ��ĳЩNpc�����ö�
	if( duration < 1 || me->query("no_poison")>0 ) return 0;
   return CND_CONTINUE;
}
