//hellupdate.c
#include <skill.h>

inherit F_CLEAN_UP;
mapping hskill=([
                    "sword":"����", "blade":"����",
                    "hammer":"�󴸷�","staff":"ħ����",
                    "whip":"����","axe":"����",
                    "fork":"����","spear":"ǹ��",
                    "mace":"ﵷ�","stick":"����",
                    "unarmed":"ȭ����","dodge":"������",
 ]);
void create() { seteuid(getuid()); }
     


int main(object me, string skill)
{
        
        
        int  my_skill, cost,upper,amount;

        if(!skill) return notify_fail
                    ("ָ���ʽ��hellupdate <����>\n");

       if(sscanf(skill, "check %s", skill)==1 ) 
           {
                 if(undefinedp(hskill[skill]))
                      return notify_fail ("û��������ܣ�\n");
              my_skill =me->query("hell_skill/"+skill);
              cost=(my_skill*my_skill+20)*5;
              return notify_fail  ("�������һ��"+hskill[skill]+"����������Ҫ"+cost+"�㼼�������㣡\n");
           
           }
        if(undefinedp(hskill[skill])) 
            return notify_fail ("û��������ܣ�\n");
       
        if( me->is_fighting() )
                return notify_fail("����ĥǹ������������\n");

        if(me->is_busy())
            return notify_fail("����æ���ء�\n");

        amount=me->query("hell_pot");
        
           if(amount<=0)
                return notify_fail("��ļ����������Ѿ�ʹ�����ˣ�û�а취�������ˡ�\n");
        my_skill =me->query("hell_skill/"+skill);
        cost=(my_skill*my_skill+20)*5;
        if(my_skill>100) cost =cost*3;
        if(amount<cost)
                return notify_fail  ("��ļ��������㲻��������"+hskill[skill]+"����������Ҫ"+cost+"�㼼�������㣡\n");
        upper=(my_skill * my_skill  +10)*50;
        if(me->query("hell_exp")<upper)
                     return notify_fail
                     ("��ĵ������鲻��������"+hskill[skill]+"����������Ҫ"+upper+"�㾭�飡\n");

        me->add("hell_skill/"+skill,1);
        me->add("hell_pot",- cost);
        me->start_busy(5);
         return notify_fail("���"+hskill[skill]+"����һ����\n");
}

int help(object me)
{
        write(@HELP
ָ���ʽ : hellupdate <����>         �鿴��ʽ�� hellupdate check <����>
 
���ָ��������������������һЩ�������ܵ�ָ���Ҫһ���ĵ������������㡣

�������֪�������˽�������Щʲô���ܣ������� hellscore ָ��ֱ�Ӳ鿴�������
һ������dodge��

�������ָ�� : hellscore
HELP
        );
        return 1;
}


