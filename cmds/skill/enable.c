// enable.c

#include <ansi.h>

inherit F_CLEAN_UP;

mapping valid_types = ([
	"unarmed":	"ȭ��",
	"sword":	"����",
	"blade":	"����",
	"stick":	"����",
	"staff":		"�ȷ�",
	"throwing":	"����",
	"force":	"�ڹ�",
	"parry":	"�м�",
	"dodge":	"�Ṧ",
//	"magic":	"ħ��",
	"spells":	"����",
//	"move":		"�ж�",
//	"array":	"��",
	"whip" :	"�޷�",
	"spear":	"ǹ��",
	"axe":          "����",
	"mace":         "ﵷ�",
	"fork":		"�淨",
	"rake":		"�ٷ�",
	"archery":	"����",
	"hammer":	"����",
	"literate":     "����ʶ��",
]);

int main(object me, string arg)
{
	mapping map;
	string *types, *skill, ski, map_to;
	int i, modify;
	string check;

	seteuid(getuid());
	if (arg) 
		sscanf(arg, "-%s %s", check, arg); 
	if (check=="check" && wizardp(me) && arg) {
		me = find_player(arg);
		if (!me) me = LOGIN_D->find_body(arg);
		if (!me) return notify_fail("û������ˡ�\n");
		}

	if( !arg || check=="check" ) {
		map = me->query_skill_map();
		if( !mapp(map) || sizeof(map)==0 )
			return notify_fail("������û��ʹ���κ����⼼�ܡ�\n");

		skill = keys(valid_types);
		write("��������Ŀǰʹ���е����⼼�ܡ�\n");
		for (i=0; i<sizeof(skill); i++) {
			if( undefinedp(valid_types[skill[i]]) ) {
				map_delete(map, skill[i]);
				continue;
			}
			if( !me->query_skill(skill[i]) ) continue;
			modify = me->query_temp("apply/" + skill[i]);
			printf("  %-20s�� %-20s  ��Ч�ȼ���%s%4d\n" NOR, 
				valid_types[skill[i]] + " (" + skill[i] + ")",
				undefinedp(map[skill[i]]) ? 
				"��" : to_chinese(map[skill[i]]),
				(modify==0 ? "" : (modify>0 ? HIC : HIR)),
				me->query_skill(skill[i]));
		}
		return 1;
	}

	if( arg=="?" ) {
		write("�����ǿ���ʹ�����⼼�ܵ����ࣺ\n");
		skill = sort_array(keys(valid_types), (: strcmp :) );
		for(i=0; i<sizeof(skill); i++) {
			printf("  %s (%s)\n", valid_types[skill[i]], skill[i] );
		}
		return 1;
	}

	if( sscanf(arg, "%s %s", ski, map_to)!=2 )
		return notify_fail("ָ���ʽ��enable [<��������> <��������>|none]\n");

	if( undefinedp(valid_types[ski]) )
		return notify_fail("û������������࣬�� enable ? ���Բ鿴����Щ���ࡣ\n");

	if( map_to=="none" ) {
		me->map_skill(ski);
		me->delete_temp("perf_quick");
		me->reset_action();
		write("Ok.\n");
	} else if( map_to==ski ) {
		write("��" + to_chinese(ski) + "��������" + valid_types[ski] + "�Ļ���������Ҫ enable��\n");
		return 1;
	} else {

	  if( !me->query_skill(map_to, 1) )
		return notify_fail("�㲻�����ּ��ܡ�\n");

	  if( !SKILL_D(map_to)->valid_enable(ski) )
		return notify_fail("������ܲ��ܵ���������;��\n");

	  me->map_skill(ski, map_to);
	  me->delete_temp("perf_quick");
	  me->reset_action();
	  write("Ok.\n");
	}
	
	if( ski=="magic" ) {
		write("�������һ��ħ����������������������\n");
		me->set("atman", 0);
		me->receive_damage("gin", 0);
	} else if( ski=="force" ) {
	        int f1, f2;
		if( map_to!="none")
		  write("�������һ���ڹ���������������������\n");
		me->set("force", 0);
		me->set("force_factor", 0);
		//need this to fix low special high factor. 
		me->receive_damage("kee", 0);
		
		// mon 12/10/98
		f1=me->query_max_force();
		f2=me->query("maximum_force");
		if(f1>f2) f1=f2;
		me->set("max_force",f1);
		
	} else if( ski=="spells" ) {
	        int f1, f2;
		if( map_to!="none")
		  write("�������һ�ַ�����������������������\n");
		me->set("mana", 0);
		me->set("mana_factor", 0);
		//same as the fix for force.
		me->receive_damage("sen", 0);

		// mon 12/10/98
		f1=me->query_max_mana();
		f2=me->query("maximum_mana");
		if(f1>f2) f1=f2;
		me->set("max_mana",f1);
	}

	return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : enable|jifa [<��������> <��������> | none]
           enable ?

���ָ������ָ����Ҫ�õļ��ܣ���ָ����������ͼ������ơ�������Ӳ�
�������ʾ���������༰��Ŀǰ��ʹ�õļ������� �������һ�� ? ���г�
������ʹ�����⼼�ܵļ������ࡣ
 
HELP
        );
        return 1;
}
