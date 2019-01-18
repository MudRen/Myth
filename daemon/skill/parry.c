// parry.c

inherit SKILL;

string *parry_msg = ({
	"ֻ�������ϡ�һ������$p���ˡ�\n",
	"�����������һ����$p�����ˡ�\n",
	"���Ǳ�$n�����б��мܿ���\n",
	"����$n����һ�࣬�����б��и񿪡�\n",
});

string *unarmed_parry_msg = ({
	"���Ǳ�$p���ˡ�\n",
	"�����$p�����ˡ�\n",
});

string query_parry_msg(object weapon)
{
	if( weapon )
		return parry_msg[random(sizeof(parry_msg))];
	else
		return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
