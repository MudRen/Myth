//wuyue-spear ������ǹ
/*
������ǹ    dodge  0    parry  -10    damage  25
����������Ʒɻ��ĳ���ǹ�����а��۲���֮��
���������мܣ�����Ҳ����С��
*/
inherit SKILL;
#include <ansi.h>
string* skill_head =({
        "$Nʹ��һ��",
        "$N���㾫�񣬺�һ��",
        "$Nһ������ʹ����",
        "$N��̬���У�һ��",
        "$N��ǹ��һ��ͻȻһ��",
        "$Nһ�����������ǹ��������һ��",
});

string* skill_tail =({
        "������$w��$n��ͷ����ֱɨ������",
        "������$w�������޵ش���$n$l",
        "��$N����$w�������ٴ���$n��$l",
        "������$w����ػ���$n��$l",
        "��ǹǹ����$nҪ��",
        "������$w����һ������ֱ��$n$l",
});

mapping *action = ({
        ([      "action":
"$Nʹһ��"+BLINK""+HIM"��̩ɽѹ����"NOR"������$w��$n��ͷ����ֱɨ������",
                "damage":               40,
                "dodge":                -15,
                "parry":                -15,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���㾫�񣬶���$w��һ��"+BLINK""+HIC"���������ơ�"NOR"����$n",
                "damage":               40,
                "dodge":                5,
                "parry":                -10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����$w�������ٴ���$n��$l����һ��"+BLINK""+HIG"�����Ϫ�ơ�"NOR"",
                "damage":               45,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N һ�����������ǹ��������һ��"+BLINK""+HIB"���������ڡ�"NOR"��ǹǹ����$nҪ��",
                "damage":               50,
                "dodge":                10,
                "parry":                -15,
                "damage_type":  "����"
        ]),
        ([      "action":
"ֻ��$Nһ������ʹ��"+BLINK""+HIY"��̫�Ҳη�"NOR"������$w����һ������ֱ��$n$l",
                "damage":               40,
                "dodge":                0,
                "parry":                0,
                "damage_type":  "����"
        ]),
        ([      "action":
"ֻ��$N�ڿշ�������ǹ��һ��$wֻ��$n$1������һ��"+BLINK""+HIW"���������ա�"NOR"",
                "damage":               40,
                "dodge":                5,
                "parry":                -25,
                "damage_type":  "����"
        ]),
});
int valid_learn(object me)
{
        object ob;
        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취��������ǹ��\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "spear" )
                return notify_fail("���������һ��ǹ������ǹ����\n");
        return 1;
}
int valid_enable(string usage)
{
        return (usage=="spear") || (usage=="parry");
}
mapping query_action(object me, object weapon)
{
        mapping* m_actions;
        m_actions=me->query("skill_wuyue-spear");
        if(me->query("skill_wuyue-spear")==0 )
        return action[random(sizeof(action))];
        if( random(4) == 1 )
        return m_actions[random(sizeof(m_actions))];
        else 
        return action[random(sizeof(action))];

}
int practice_skill(object me)
{
        object weapon;
        if( (string)me->query_skill_mapped("force")!= "huomoforce")
                return notify_fail("������ǹ������ϻ�ħ�ķ���������\n");
        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "spear" )
                return notify_fail("���������һ����ǹ���������Ƶ�������������ǹ����\n");
        if( (int)me->query("kee") < 30 
        ||    (int)me->query("force") < 5  )
                return notify_fail("�����������������ǹ������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
//        write("�㰴����ѧ����һ��������ǹ��\n");
        return 1;
}
string perform_action_file(string func)
{
        return CLASS_D("yaomo") + "/kusong/wuyue-spear/" + func;
}
void skill_improved(object me)
{
        int m_skill=me->query_skill("wuyue-spear",1);

        if(m_skill>200&&m_skill%10==0)
        {
                tell_object(me,HIR"���������ǹ����������ˣ����������ǹ������һ���µľ��磡\n"NOR);

                if(random(me->query("kar"))<20)
                {
                        tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
                        return;
                }
                if(random(me->query("int"))<20)
                {
                        tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û��ץס��\n"NOR);
                        return;
                }
                tell_object(me,HIW"��ͻȻ�������飬��������ǹ�������һ���µ��÷���\n"NOR);
                tell_object(me,"��Ϊ����ȡһ�����֣�");
                input_to( (: call_other, __FILE__, "name_skill", me:));
        }
        return;
}

void name_skill(object me, string arg)
{
        mapping* m_actions;
        mapping m_act=([]);
        int content;
        string msg;

        m_actions=me->query("skill_wuyue-spear");
        if(!pointerp(m_actions))m_actions=({});

        content=me->query("str")+2*me->query_skill("unarmed",1)/10;
        m_act+=(["damage":content]);
        content=-me->query("spi");
        m_act+=(["dodge" :content]);
        content=-me->query("cps");
        m_act+=(["parry" :content]);
        content=me->query("con")+me->query_skill("force",1)/10;
        m_act+=(["force" :content]);
        m_act+=(["damage_type":"����"]);
        
        if(!arg||arg==" ")arg="������ǹ��ɱ��"+chinese_number(sizeof(m_actions)+1);
        m_act+=(["name":arg]);
        msg= skill_head[random(sizeof(skill_head))]+BLINK+HIW"��"+arg+"��"NOR
                  +skill_tail[random(sizeof(skill_tail))];
        m_act+=(["action":msg]);
        m_actions+=({m_act});
        me->set("skill_wuyue-spear",m_actions);
}
 

