// dtask.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{       object ob;
        
        seteuid(getuid(me));
        if(!arg) ob = me;
        else if (wizardp(me)) { ob = present(arg, environment(me));
             if (!ob) ob = find_player(arg);
             if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
        } 
                else return notify_fail("ֻ����ʦ�ſ��Բ쿴���˵�״̬��\n");
        
        printf("���� �� �Ѷ�һ �� �Ѷȶ� �� �Ѷ��� �� ���Ǳ�� �� �����ѧ �� ��õ��� \n");
        printf("ɱ�� ��%8|d��%8|d��%8|d��%10|d��%10|d��%d \n",
              ob->query("rulaitask_log/kill1"),  ob->query("rulaitask_log/kill2"),     
              ob->query("rulaitask_log/kill3"),  ob->query("rulaitask_log/kill_potential"),
              ob->query("rulaitask_log/kill_combat"),
              ob->query("rulaitask_log/kill_daoxing"));
        printf("���� ��%8|d��%8|d��%8|d��%10|d��%10|d��%d \n",
              ob->query("rulaitask_log/arrest1"),  ob->query("rulaitask_log/arrest2"),     
              ob->query("rulaitask_log/arrest3"),  ob->query("rulaitask_log/arrest_potential"),
              ob->query("rulaitask_log/arrest_combat"),
              ob->query("rulaitask_log/arrest_daoxing"));
        printf("Ȱ�� ��%8|d��%8|d��%8|d��%10|d��%10|d��%d \n",
              ob->query("rulaitask_log/persuade1"),  ob->query("rulaitask_log/persuade2"),     
              ob->query("rulaitask_log/persuade3"),  ob->query("rulaitask_log/persuade_potential"),
              ob->query("rulaitask_log/persuade_combat"),
              ob->query("rulaitask_log/persuade_daoxing"));
        printf("���� ��%8|d��%8|d��%8|d��%10|d��%10|d��%d \n",
              ob->query("rulaitask_log/fight1"),  ob->query("rulaitask_log/fight2"),     
              ob->query("rulaitask_log/fight3"),  ob->query("rulaitask_log/fight_potential"),
              ob->query("rulaitask_log/fight_combat"),
              ob->query("rulaitask_log/fight_daoxing"));
        printf("ѳְ������ %d\n",ob->query("rulaitask_log/die"));
        
        
        
        return 1;
}

int help(object me)
{
     write(@HELP
ָ���ʽ: dtask

���ָ������֪���������������ͳ�������

HELP
    );
    return 1;
}

