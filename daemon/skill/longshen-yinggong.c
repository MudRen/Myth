
//Cracked by Roath
//longshen-yinggong.c
inherit FORCE;
int valid_enable(string usage) { return usage=="jinlin-jia"; }
int valid_learn(object me) { return 1; }
int practice_skill(object me)
{
        return
notify_fail("��������ֻ����ѧ�ġ�\n");
}

int effective_level() { return 20;}
string *absorb_msg = ({
        "$n˫��һ���������񹦾����Ƶ����ȶ�����\n",
        "$nʩչ���������񹦣�$N���屻��ķ��顣\n",
        "$nʹ���������񹦣�����Ӳ���ʯ��\n",
        "$nʩչ���������񹦣��Կ�$N��һ��֮����\n",
});
string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}
int bounce_ratio()
{
 return 5;
}
int learn_bonus()
{
 return -10;
}
int practice_bonus()
{
 return -5;
}
int black_white_ness()
{
 return 20;
}
string perform_action_file(string action)
{
        return CLASS_D("dragon") + "/longshen-yingong/" + action;
}

