//Cracked by Roath

inherit SKILL;
string type() { return "dodge"; }
string *dodge_msg = ({
        "$nһʽ���������᡹�������������������ݷ����У���$Nͷ����Ծ������\n",
        "$nһʽ��������ϼ������һ����磬�滺��������$N���������ơ�\n",
         "$nһʽ����س���������ӯ��һԾ��һת�ۼ���Ƶ���$N�����\n",
         "$nһʽ��ȴ����ɡ���һת��䣬���Ʈ����һ��Զ\n",
         "$nһʽ�����ճ�������ȫ���ֱ���εض����ڰ����һת�����䵽����Զ�ĵط���\n",
         "$nһʽ�������ա���������һֻ�����������ˮ�ػ������ࡣ\n",
         "$nһʽ���������ǡ���˫�ŵ�أ�ȫ��Ϊһ����Ӱ����������$N���˼�ת��\n",

});

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}


int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        return 1;
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
                return notify_fail("�������̫���ˣ����������ǲ���\n");
        me->receive_damage("kee", 30);
        return 1;
}