#include <ansi.h>;

inherit SKILL;

string *dodge_msg = ({
  HIW"$nһ��"HIC"�������貨��"HIW"�������趯����ס����ȥ������ƮƮ�������⣬�����$N��һ�С�\n"NOR,

  HIR"$n��ȻһЦ�����˾�����$N��Ϊ���ˣ����²���һ�٣�$n�ѽ���"HIM"��һЦ�����"HIR"֮�ƣ��ܿ���$N���������ơ�\n"NOR,

  HIG"$nʹ��"HIR"��������ơ�"HIG"��������Σ��Ų�������������$N�����\n"NOR,

  HIC"$n�����أ��ۿ�$Nɱ�п���Ϯ������ϥһ�䣬�����߳�������һ��"HIR"�����ҹ����"HIC"�������ѽ���ƽ�ƣ�����һ�ԡ�\n"NOR,

  HIY"$nһʽ"HIG"������׹¥��"HIG"���������ػ��У�����˷�����˼����$N�Ĺ�����Ȼ�˿ա�\n"NOR,

});

int valid_enable(string usage) { return (usage=="dodge"); }

int valid_learn(object me)
{
        if( (string)me->query("gender") != "Ů��" )
                return notify_fail("��Ů��ֻ��Ů�Բ�������\n");
        if( (int)me->query("spi") < 10 )
                return notify_fail("������Բ�����û�а취��Ů���衣\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("sen") < 30 )
                return notify_fail("��ľ���̫���ˣ���������Ů���衣\n");
        me->receive_damage("sen", 30);
        return 1;
}


