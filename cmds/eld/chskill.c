// chskill.c
// Modified by Cody May.2001


#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
        BLU "��ѧէ��" NOR,BLU "�����ž�" NOR,HIB "��ͨƤë" NOR,HIB "��֪һ��" NOR,
        YEL "��������" NOR,YEL "������" NOR,HIY "����С��" NOR,HIY "����Ѿ�" NOR,
        HIM "�������" NOR,HIM "��Ȼ����" NOR,HIR "�������" NOR,HIR "�������" NOR,
        MAG "����似" NOR,MAG "�����뻯" NOR,CYN "��Ȼ��ͨ" NOR,CYN "�Ƿ��켫" NOR,
        HIC "������˫" NOR,HIC "һ����ʦ" NOR,HIC "������" NOR,HIW "��ɲ�" NOR
});

string *knowledge_level_desc = ({
        BLU "��ѧէ��" NOR,HIB "�����ž�" NOR,HIB "��֪һ��" NOR,YEL "������" NOR,
	YEL "����С��" NOR,CYN "�������" NOR,CYN "��Ȼ����" NOR,CYN "��Ȼ��ͨ" NOR,
	HIC "������˫" NOR,HIC "������" NOR,HIW "��ɲ�" NOR
});


mapping valid_type = ([
"unarmed":      "�˻���֮��","spells":      "����",
"claw":         "צ��","cuff":         "ȭ��",
"finger":       "ָ��","strike":       "�ƹ�",
"hand":         "�ֹ�","leg":          "�ȹ�",
"sword":        "��������","blade":        "��������",	
"dagger":       "�̱���","brush":        "�ʷ�",		
"spear":        "����ǹ��","hook":         "����",		
"stick":        "��������","staff":        "�����ȷ�",		
"club" :        "����","throwing":     "����ʹ��",		
"whip":         "��������","axe":          "��������",
"hammer":       "��������","force":        "�ڹ��ķ�",	
"dodge":        "�����Ṧ","parry":        "����ж��֮��",	
]);

string skill_level(string, int);
string skill_enables(object sk);

int sort_skill(string file)
{
	int i;
	if ( !sscanf(file, "%*s.c") )  return 0;
	i = strlen(file);
	while(i--){
		if( file[i] == '.' ) continue;
		if( file[i] < 'a' || file[i] > 'z' )
			return 0;
	}

	return 1;
}

int main(object me, string arg)
{
        mapping lrn;
        string exert, str, *file;
        object sk;
        int i, j = 0;

        seteuid(getuid());

        if(!arg) return notify_fail("ָ���ʽ : chskill [�书����]\n");
	
	sscanf("%s", arg);
		
	if(!me->query_skill(arg, 1)) 
		return notify_fail("��Ҫ���ʲô���ܣ�\n");
	
	if(file_size(SKILL_D(arg)+".c") < 1)
		return notify_fail("������Ҫ��Լ����ļ��Ѿ���ʧ����֪ͨ��ʦ��\n");
	

	lrn = me->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        
	str = sprintf("\n��%-24s��������������������������������������������������\n", HIW"��"+to_chinese(arg)+"���ܱ�"NOR);
	
	str = replace_string(str, "  ", "��");
	str += sprintf("��"HIY"�ȼ�"NOR"��  %s %3d/%6d\t      "HIY"���"NOR"��  %-15s%9s  \n",skill_level(SKILL_D(arg)->type(), 
			me->query_skill(arg, 1)), me->query_skill(arg, 1), 
			(int)lrn[arg], SKILL_D(arg)->type(), "��");	
	
	if(member_array(arg, keys(valid_type))!=-1) 
//          (SKILL_D(arg)->type() != "magic" 
		return notify_fail(str+"����������������������������������������������������������������������\n");
		
	str += "��\t\t\t\t\t\t\t\t    ��\n";
	sk = load_object(SKILL_D(arg));
	
	exert = skill_enables(sk);
	if(exert != ""){
		str += exert;
		i++;
	}
	
	if( stringp(exert = SKILL_D(arg)->exert_function_file("")) ){
		file = get_dir(exert);
		if( sizeof(file) > 0){
			file  = filter_array(file, (: sort_skill :) );
			j = sizeof(file);
		}
	}
	
	if(j && j > 0){
		if( i )
			str = str + "����������������������������������������������������������������������\n";
		str += "��"HIG"�ڹ�����(exert + )"NOR"��\t\t\t\t\t\t    ";
		for(i=0; i < j; i++){
			if (i % 4 == 0) str += "��\n��\t";
			str += sprintf("%-14s ",YEL+replace_string(file[i], ".c", "")+NOR);
			if ( i > j-2 ){
				switch(i%4){
					case 0: str +="\t\t\t\t\t            "; break;
					case 1: str +="\t\t\t            "; break;
					case 2: str +="\t\t    "; break;
					default: break;
				}
                        }
		}
		str += "��\n";
		j = 0;
	}
	
	if( stringp(exert = SKILL_D(arg)->perform_action_file(""))){
		file = get_dir(exert);
		if( sizeof(file) > 0){
			file  = filter_array(file, (: sort_skill :) );
			j = sizeof(file);
		}
	}
	
	if(j && j > 0){
		if( i )
			str = str + "����������������������������������������������������������������������\n";
		str += "��"HIG"�⹦����(perform + )"NOR"��\t\t\t\t\t    ";
		for(i=0; i < j; i++){
			if (i % 4 == 0) str += "��\n��\t";
			str += sprintf("%-14s ",WHT+replace_string(file[i], ".c", "")+NOR);
			if ( i > j-2 ){
				switch(i%4){
					case 0: str +="\t\t\t\t            "; break;
					case 1: str +="\t\t            "; break;
					case 2: str +="\t    "; break;
					default: break;
				}
                        }
		}
		str += "��\n";
		j = 0;
	}

	if( stringp(exert = SKILL_D(arg)->cast_spell_file("")) ){
		file = get_dir(exert);
		if( sizeof(file) > 0){
			file  = filter_array(file, (: sort_skill :) );
			j = sizeof(file);
		}
	}
	
	if(j && j > 0){
		if( i )
			str = str + "����������������������������������������������������������������������\n";
		str += "��"HIG"��������(cast + )"NOR"��\t\t\t\t\t\t    ";
		for(i=0; i < j; i++){
			if (i % 4 == 0) str += "��\n��\t";
			str += sprintf("%-14s ",HIC+replace_string(file[i], ".c", "")+NOR);
			if ( i > j-2 ){
				switch(i%4){
					case 0: str +="\t\t\t\t\t            "; break;
					case 1: str +="\t\t\t            "; break;
					case 2: str +="\t\t    "; break;
					default: break;
				}
                        }
		}
		str += "��\n";
	}


	str += "����������������������������������������������������������������������\n";
        write(str);
        return 1;
}



string skill_enables(object sk)
{
	int i, j;
	string str, *skills;
	skills = keys(valid_type);
	
	for(i=0; i < sizeof(skills); i++) {
		if (sk->valid_enable(skills[i])) continue;
		skills[i] = 0;
	}
	
	skills -= ({ 0 });
	j = sizeof(skills);
	if( !j || j < 1)
		return "";
	str = "��"HIM"���⼼��"NOR"��\t\t\t\t\t\t\t    ";
		
	for(i=0; i < j; i++) {
		if (i % 4 == 0) str += "��\n��\t";
		str += sprintf("%-14s ", HIC+valid_type[skills[i]]+"("+skills[i]+")"NOR);
		if ( i > j-2 ){
			switch(i%4){
				case 0: str +="\t\t\t\t            "; break;
				case 1: str +="\t\t            "; break;
				case 2: str +="\t    "; break;
				default: break;
			}
                }
	}
	str += "��\n";
	return str;
}

string skill_level(string type, int level)
{
        int grade;
        
        switch(type) {
                case "knowledge":
                	grade = level / 15;
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                	grade = level / 15;
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}

int help(object me)
{
	write("\nָ���ʽ : chskill [�书����]\n");
	write(@HELP
���ָ����������ѯ����ܵĹ��ܺ����ݡ�

���⼼�ܱ�ʾ���� enable �ļ��ܡ�

�ڹ�������ʾ������(exert)���ڹ���

�⹦������ʾ��ʹ��(perform)���⹦��

����������ʾ������(cast)��������


	
HELP);

    return 1;
}
