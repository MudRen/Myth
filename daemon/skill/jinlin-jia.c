//Cracked by Roath
// jinlin-jia.c
inherit SKILL;
#include <ansi.h>
string *absorb_msg = ({
 "$n����һЦ�����Ų�æ��������ۼס�\n",
        "$n��Ŀ��������ȫ������Ӳ���ﵽ�۷�״̬��\n",
        "$n˫��һȦ�����б�����������ۼ�ӭ��$N��\n",
});
string query_absorb_msg()
{
 return absorb_msg[random(sizeof(absorb_msg))];
}
int valid_learn(object me)
{
  if(me->query("class")!="dragon")
    return notify_fail("�㲻�����壬ѧ���������书��\n");
  return 1;
}
