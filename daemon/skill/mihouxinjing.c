//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells", 1) < 10
        ||      (int)me->query_skill("spells", 1) <=
(int)me->query_skill("mihouxinjing", 1) )
                return
notify_fail("��ķ�����Ϊ����������޷�ѧϰ�ֺ��ľ���\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("houyao") + "/mihouxinjing/" + spell;
}


