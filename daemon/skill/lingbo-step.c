//���貨΢����
// lingbo-step.c

#include <ansi.h>
inherit SKILL; 

string type() { return "dodge"; }
string *dodge_msg = ({
     "$nһ��"BLINK" + "HIW"������ʤѩ̤�貨��"NOR"��$Nֻ��һ��Ӱ�ӻι���ȴ������$n����Ӱ��\n",
     "$nһ��"BLINK" + "CYN"���������������衹"NOR"������΢΢ǰ�㣬��Ц���ѱܿ���$N��һ�С�\n",
     "ֻ��$n���¿첽��ͣ��һ��"BLINK" + "HIR"����ǧ�쳾��˿�ϡ�"NOR"��$N�۾�һ����վ��ԭ�ز�֪������Ǻá�\n",
     "$n����$nһ��"BLINK" + "HIM"���������϶����á�"NOR"�����䷭�ɣ����$N��һ�С�\n",
     "$nϢ���������������һ��"BLINK" + "HIB"����ҹ���˺δ�ȥ��"NOR"������ƮȻ����\n",
     "$n΢΢һЦ��һ��"BLINK" + "HIY"����������׹��񷡹"NOR"�������Ӱ���������磬˲����վ����$N���\n",
     "$nһ��"BLINK" + "MAG"���̴�������Ӱ����"NOR"�����һ����ͷ��������$N���\n",});

int valid_enable(string usage) { return (usage=="dodge"); }

int valid_learn(object me)
{
        if( (int)me->query("spi") < 20 )
             return notify_fail("������Բ�����\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("sen") < 20 )
                return notify_fail(WHT"��ľ���̫���ˣ����������貨΢������\n"NOR);
        me->add("sen", -15); 
        me->add("qi",-5);        return 1;
}



