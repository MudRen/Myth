#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

#include <magic_power.h>

string get_name(){return "�س���";}//��������
string get_help()                  //����˵��,�Ժ�ֱ��help,�����޸�
{
        return "����������԰���ص���ջ,��Ҫһ����ħ���㣱";
}

int do_cast(object me,object target)
{
        string helltype;
        if(me->is_fight())
        {
                tell_object(me,"����ս���У���æ���أ�\n");
                return 1;
        }
        if(me->query("magic_pointed")<10)
        {
                tell_object(me,"���ħ����̫���ˣ������ò����������!\n");
                return 1;
        }
        helltype=me->query("hell_type");
        if(!helltype) helltype="Ұ����";
        if(!userp(me)) return 1;
        me->add("magic_pointed",-magic_power[helltype]/10);
        me->move("/d/city/kezhan");
        return 1;
}

