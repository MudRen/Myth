#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

#include <magic_power.h>

string get_name(){return "�ƶ���";}//��������
string get_help()                  //����˵���Ժ�ֱ��help,�����޸�
{
        return "����������������ڷ���������ƶ���λ,��Ҫһ���ķ�����";
}

int do_cast(object me,object target)
{
        string helltype;
        
        if(me->is_fight())
        {
                tell_object(me,"����ս���У�æ���أ�\n");
                return 1;
        }
        
        if(me->query("mana")<300)
        {
                tell_object(me,"��ķ���̫���ˣ������ò����������!\n");
                return 1;
        }
        
        helltype=me->query("hell_type");
        if(!helltype) helltype="Ұ����";
        if(!userp(me)) return 1;
        me->add("mana",-2* magic_power[helltype]);
        me->set_temp("position/yy",18+random(5));
        me->set_temp("position/xx",18+random(5));
        me->command("fangwei");
        return 1;
}

