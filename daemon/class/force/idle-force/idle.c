//Cracked by Roath
#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill,howlong, damage, force,time;
               mapping action; 
        if (me->query_skill("idle-force",1)<80)
         return notify_fail("��ķ����󷨻�������\n");
        message_vision(HIC "\n$Nʹ��������,�ճյĳ�$n��ȥ��\n"NOR,me);
        message_vision(HIC "\n$nһ�¾����ˣ���������.\n"NOR,me);
        command("rumor "+"��˵$n��$N�÷�����Ϯ���ɹ���");
        howlong=1000-me->query_skill("idle-skill")*2;
        me->set_temp("pfm_idle",1);
        me->set("actions",action);
        me->reset_action();
        return 1;
}


int remove_ansi(object me,int strength)
{       
        me->delete_temp("pfm_idle");
message_vision(HIW"$N�ֿ���ʩչ�������ˣ�\n"NOR,me);  return 1;       

}

