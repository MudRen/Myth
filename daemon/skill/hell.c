//���һ�ޡ�hellfire-whip.c
//write by yesi
/*
�һ��    dodge  -10    parry  -10    damage  20
�һ���Ʋ��ƹ��У�һ���������乥����Χ�������⣬
�Ҵ˱�����ת�գ���ȥ���٣�Ҫ�мֵܵ�Ҳ��Ϊ���ס�
�ص���ɱ�˲���

Attention: �һ��ǰ�����������ֻ��г��ģ�����13��14�����ǿ�ɥ��
�;������У����� Perform �ģ������ƽ���������õ���
*/
inherit SKILL;
#include <ansi.h>
int ratio;
string* skill_head =({
        "$N����һ����һ��",
        "��Ц����$Nһ��������ʹ��",
        "$Nʹ��",
        "$N�����﷢���������У�һʽ",
        "$N���ض���������һ��",
        "$N����һ����һ��",
});

string* skill_tail =({
        "������$w���ñ�ֱ������һ����Х�ʹ�$n$l",
        "������$w��ž������һȦ��һȦ�ؾ���$n",
        "������$w���˸�Ȧ������$n��",
        "������$w�糤��һ�㣬����$nת����ͣ",
        "��$w����$n��$l",
        "������$w��Ϧ���Ĵ��̣���������",
});


mapping *action = ({
        ([      "name":                 "������",
                "action":
"$N����ϲɫ������$wһӭ��ƮȻ�䡸"+BLINK""+HIY"������"+NOR"������ҵ��ʹ��",
                "dodge":                0,
                "parry":                -5,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�˼����",
                "action":
"$N������ݣ�������࣬��������࣬��"+BLINK""+HIG"�˼����"+NOR"��ʹ����Ȼ�����$nΪ֮��Ȼ����",
                "dodge":                -10,
                "parry":                -5,
                "damage":               45,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��������",
                "action":
"$Nɱ������һ��$w������������ȥ����"+BLINK""+HIM"��������"+NOR"�����������ӵ����쾡��",
                "dodge":                -10,
                "parry":                -5,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����޵�",
                "action":
"$Nŭ����ڣ�$w��������޵�����$n��������нС�"+BLINK""+HIR"�����޵�"+NOR"��",
                "dodge":                -10,
                "parry":                -5,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����ָ�",
                "action":
"$N����֮ɫ�������Σ�����֮���᳹��$w��$n�����"+BLINK""+HIB"�����ָ�"+NOR"������",
                "dodge":                -10,
                "parry":                -5,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "name":                 "����Ͷ̥",
                "action":
"$N�������Σ�˳��һ����$wȴ��ֱ�������$n��ȥ����һ�С�"+BLINK""+YEL"����Ͷ̥"+NOR"��",
                "dodge":                -10,
                "parry":                -5,
                "damage":               40,
                "damage_type":  "����"
        ]),               
        ([      "name":                 "�����һ�",
                "action":
"$N����һ����һ��"+BLINK""+HIW"���زص�î��"NOR"$w���ñ�ֱ������һ����Х�ʹ�$n$l",
                "dodge":                0,
                "parry":                -5,
                "damage":               35,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����һ�",
                "action":               
"$N���һ��������$w�����������ڰ�գ�����"+BLINK""+HIR"����ճ�����"NOR"�����š�\n$nֻ����ȫ�����$w����֮��",
                "dodge":                -20,
                "parry":                -20,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����һ�",
                "action":
"$N����һ����һ��"+BLINK""+MAG"���������ޡ�"NOR"$w���ض��ɣ��ټ�����ϣ��·�����˵����е��һ𣬼�ͷ���Ե�����$n",
                "dodge":                -5,
                "parry":                -15,
                "damage":               45,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����һ�",
                "action":
"Ҳ��֪$N��ζ���һ����һ��"+BLINK""+RED"���������жɹ�꡹"NOR"�������������һ����$nֻ��$w�ѻ�����$l",
                "dodge":                -15,
                "parry":                -5,
                "damage":               35,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����һ�",
                "action":
"$N������ǰ����������$w��ž������һȦ��һȦ�ؾ���$n,��һ��"+BLINK""+HIC"����ڤ������������"NOR"",
                "dodge":                -5,
                "parry":                0,
                "damage":               35,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����һ�",
                "action":
"��Ц����$Nһ������������$w���ʣ�������Բ�����ɳ��ʯ�������ݺᣡ\n$n��֪��β���������������������",
                "dodge":                -15,
                "parry":                -20,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "name":                 "С¥ҹ��",
                "action":
"$N�����﷢���������У��߾�$w������һ�еس���$n��������$n����������\n����$wȴ������Ϣ�ش���$n��$l����������"+BLINK""+HIB"��С¥ҹ�ޡ�"NOR"",
                "dodge":                -15,
                "parry":                -15,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ع�",
                "action":               "$N������Σ�����ƮƮ�����ĳʱ��̣�һ��"+BLINK""+HIB"����ع���"NOR"����$n$l",
                "dodge":                -10,
                "parry":                -10,
                "damage":                50,
                "damage_type":  "����"
        ]),

});
string *liudao=({
                HIY"\n$N���г��������������ɵ����������˭����? "NOR,
                HIG"\n$N���г������˽�������˵�����������˭���ˣ�"NOR,
                HIM"\n$N���г�����ڤ�������ծ���������̷�˭������"NOR,
                HIR"\n$N���г��������޵���ɱ¾������ս����˭���磿"NOR,
                HIB"\n$N���г�������������޳�����±�ȸ���˭�Ե���"NOR,
                YEL"\n$N���г����������������������ţ��˭˵�ã�"NOR
                });
                




int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 150 )
                return notify_fail("�������������û�а취���һ�ޡ�\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "whip" )
                return notify_fail("���������һ�����Ӳ������һ�ޡ�\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="whip" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        int i,j;
        mapping* m_actions;
        string strs;
        m_actions=me->query("skill_hellfire-whip");

        if( !me->query_temp("ldlh") ) 
        {
                if(me->query("skill_hellfire-whip")==0) 
                        return action[6+random(6)];
                if(random(2))
                        return action[6+random(6)];
                return m_actions[random(sizeof(m_actions))];
        }
        else 
                j=me->query_temp("lunhui")%6;
        message_vision(liudao[j],me);
        me->add_temp("lunhui",1);
        return action[j];
}
                

int practice_skill(object me)
{
        if( (int)me->query("kee") < 25
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ�һ�ޡ�\n");
        me->receive_damage("kee", 25);
        me->add("force", -5);
//        write("�㰴����ѧ����һ���һ�ޡ�\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}


string perform_action_file(string func)
{
        return CLASS_D("ghost") + "/hellfire-whip/" + func;
}

mixed hit_ob(object me, object victim)
{
        int damage;
        if (me->query_temp("ldlh"))
        {
                switch (me->query_temp("lunhui")%6)
                {
                        case 1: {victim->receive_wound("kee",me->query_skill("spells")/2+random(me->query_skill("spells")/2));
                                                             ratio=(int)victim->query("kee") * 100 /(1+(int)victim->query("max_kee"));
                                 break;
                                }
                        case 2: {victim->receive_wound("sen",me->query_skill("spells")/2+random(me->query_skill("spells")/2));
                                 ratio=(int)victim->query("sen") * 100 /(1+(int)victim->query("max_sen"));
                                 break;
                                } 
                        case 3: {victim->add("mana",-random(me->query_skill("spells")));
                                 if (victim->query("mana")<0) victim->set("mana",0);
                                 break;
                                 }
                        case 4: {victim->add("force",-random(me->query_skill("force")));
                                 if (victim->query("force")<0) victim->set("force",0);
                                 break;
                                }
                        case 5: {victim->receive_wound("sen",random(me->query_skill("spells")));
                                 ratio=(int)victim->query("sen") * 100 /(1+(int)victim->query("max_sen"));
                                 break;
                                } 
                        case 0: {victim->receive_wound("kee",random(me->query_skill("spells")));
                                 ratio=(int)victim->query("kee") * 100 /(1+(int)victim->query("max_kee"));
                                 break;
                                }
/*
                        case 5: {victim->add("food",-random(me->query_skill("whip")));
                                 if (victim->query("food")<0) victim->set("food",0);
                                 break;
                                }
                        case 0: {victim->add("water",-random(me->query_skill("whip")));
                                if (victim->query("water")<0) victim->set("water",0);
                                }
*/

                }          
        }
}

mixed fail_hit(object me, object victim)
{    
        if (me->query_temp("ldlh"))
        {
                switch (me->query_temp("lunhui")%6)
                {
                        case 1: return HIC"$n��Ϊ������ʥ�����������ս����񣬵�ָ�����������ȥ��\n"NOR;
                        case 2: return HIC"$nӲ���ĳ����������Ե����ǷǷǣ��첽�뿪�˽����\n"NOR;
                        case 3: return HIC"$n�ԲҺ�����м�ڹˣ���֮߮��ʤ����ͥ�Ų���\n"NOR;
                        case 4: return HIC"$n�Ը������������࣬�ܿ��ɱ��һ��Ѫ·�뿪�ˡ�\n"NOR;
                        case 5: return HIC"$n����һ��Ⱥ�����ԶԶ�Ķ��˿�ȥ��\n"NOR;
                        case 0: return HIC"$n������һƥ������������ҹ����뿪������硣\n"NOR;
                        //default: return 1;
                }
        }   
}      

mixed hit_ob_msg(object me,object victim)
{   
        string strs;
        if (me->query_temp("ldlh"))
        {
                //me->add_temp("lunhui",1);
                switch (me->query_temp("lunhui")%6)
                {
                        case 1: return HIY"�����ۼ���أ�ϼ�ٺ����Ŀ�����������̱ǣ�˿���������ڶ���$n�������ж���֪����\n"NOR;
                        case 2: {strs="( $n" + COMBAT_D->sen_status_msg(ratio)+ " )\n";
                                 strs=HIG"$n�����������������ů��������ϣ�������Ȼ��\n"NOR+strs;
                                 return strs;
                                }
                        case 3: return HIM"$n������˺���ѷεĽк�����Χ���ŵû���ֱð�亹��\n"NOR;
                        case 4: return HIR"$n�����ķ�����������׷ɱ��ʧ����������ƣ���ߡ�\n"NOR;
                        case 5: return HIB"$n������������Ӹо��Լ��ĺ���Ҳ���ճ�ֻ��һ��ϸ�첻�ܽ�ʳ��\n"NOR;
                        case 0: return YEL"$n��̾�����������֪�Ϳ�������֪�����͵������г̡�\n"NOR;
               }
       }
}        
void skill_improved(object me)
{
        int m_skill=me->query_skill("hellfire-whip",1);

        if(m_skill>200&&m_skill%10==0)
        {
                tell_object(me,HIW"����һ�޵���������ˣ�����һ�޽�����һ���µľ��磡\n"NOR);
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
                tell_object(me,HIW"��ͻȻ�������飬���һ���������һ���µ��÷���\n"NOR);
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

        m_actions=me->query("skill_hellfire-whip");
        if(!pointerp(m_actions))m_actions=({});

        content=me->query("str")+2*me->query_skill("unarmed",1)/10;//Ӧ��Ϊstr
        m_act+=(["damage":content]);
        content=-me->query("spi");
        m_act+=(["dodge" :content]);
        content=-me->query("cps");
        m_act+=(["parry" :content]);
        content=me->query("con")+me->query_skill("force",1)/10;
        m_act+=(["force" :content]);
        m_act+=(["damage_type":"����"]);

        if(!arg||arg==" ")arg="�һ���ؼ�"+chinese_number(sizeof(m_actions)+1);
        m_act+=(["name":arg]);
        msg= skill_head[random(sizeof(skill_head))]+"��"+arg+"��"
                  +skill_tail[random(sizeof(skill_tail))];
        m_act+=(["action":msg]);
        m_actions+=({m_act});
        me->set("skill_hellfire-whip",m_actions);
}

