// Update by waiwai@2003/04/25

#include <condition.h>
#include <ansi.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	// Update By waiwai@2001/06/15 ��ĳЩNpc�����ö�
	if( duration < 1 || me->query("no_poison")>0 ) return 0;

   if (file_name(environment(me))!="/d/city/misc/lichunyuan2") {
   tell_object(me,HIY"����Ժ�깫����������ߣ�����������ȥ�����ȥ�ӿͣ�\n"NOR);
      message_vision(CYN"����Ժ�깫ͻȻ���֣����ɷ�˵������$N���ߡ�\n"NOR,me);
      me->move("/d/city/misc/lichunyuan2");
   }

   me->apply_condition("prostitute", duration - 1);
	if((int)me->query_condition("prostitute")==0) {
   tell_object(me,HIW"��ӿ����������ˡ�����\n"NOR);

        me->set("title",me->query("family/family_name")+"��"+
                chinese_number(me->query("family/generation"))+
                "������");
        me->delete("hooker");
        me->delete("nickname");
	me->clean_condition("prostitute");
	me->set("startroom","/d/city/kezhan");
	}

   return CND_CONTINUE;
}
