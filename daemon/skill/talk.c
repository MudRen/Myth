    //talk
    //add by dewbaby@sk

inherit SKILL; 
#include <ansi.h> 
mapping *action = ({ 
     ([      "action": 
    "$N�ſ�Ѫ����죬һʽ��Ѫ�����ˡ�"NOR"��ߴ���������$n", 
                       "force":                150, 
                       "damage_type":          "����", 
            "weapon" :              "˫��", 
              "parry_msg":    "ֻ��$N��Ŀ����,��֮����", 
      ]), 
      ([      "action": 
    "$N�ſ�Ѫ����죬һʽ����Ѫ��ͷ����ߴ���������$n", 
                      "force":                100, 
                      "damage_type":          "����", 
            "weapon" :              "˫��", 
              "parry_msg":    "ֻ��$N��Ŀ����,��֮����", 
    ]), 
      ([      "action": 
    "$N�������Ĳ�����һʽ��˥���塹������ž�����$n", 
                      "force":                120, 
                      "damage_type":          "����", 
            "weapon" :              "����", 
                         "parry_msg":    "ֻ��$N��Ŀ����,��֮����", 
      ]), 
      ([      "action": 
      "$N��Ƥ�鶯��һʽ�����ޱߡ�������ž�����$n", 
                      "force":                100, 
                      "damage_type":          "����", 
            "weapon" :              "����", 
          "parry_msg":    "ֻ��$N��Ŀ����,��֮����", 
      ]), 
      ([  "action": 
      "ֻ��$N����ͦ�أ�һʽ���������ء��������������$n", 
                      "force":                150, 
                      "damage_type":          "˥��", 
            "weapon" :              "����", 
              "parry_msg":    "ֻ��$N��Ŀ����,��֮����", 
      ]), 
      ([  "action": 
      "ֻ��$N����Ǭ����һʽ����٩�޵С��������������$n", 
                      "force":                180, 
                      "damage_type":          "����", 
            "weapon" :              "����", 
          "parry_msg":    "ֻ��$N��Ŀ����,��֮����", 
      ]), 
    }); 


int valid_enable(string usage) 
{ 
    return usage=="unarmed"; 
}

mapping query_action(object me, object weapon) 
{
    return action[random(sizeof(action))]; 
}


string perform_action_file(string func) 
{
    return CLASS_D("quest") + "/talk/" + func; 
}
