// time.c

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
        
        if(ob->query("rulaitask/accomplish")) 
              { write("��ո������һ���Ѷ�"+chinese_number(ob->query("rulaitask/level"))+"��"+ob->query("rulaitask/kind")+"������\n");
                return 1;
              }
                      
        else if(ob->query("rulaitask/fail")) 
              { write("������ʧ���ˡ�\n");
                return 1;
              }
              
        else if(!ob->query("rulaitask/get")) 
              { write("��û����������\n");
                return 1;
              }      
              
        else if(!ob->query("rulaitask/guai")) 
              { write("�������Ѿ���������������֡�\n");
                return 1;
              }
        
                                  
        write("�����ڵ�������" + ob->query("rulaitask/kind")+"��,"+ob->query("rulaitask/where")+"��\n");
        write("�Ѷȣ�" + chinese_number(ob->query("rulaitask/level"))+"\n");
        if (wizardp(me)) 
              printf("���֣�%O\n",ob->query("rulaitask/guai"));
        return 1;
}

int help(object me)
{
     write(@HELP
ָ���ʽ: ctask

���ָ������֪�������ڵ���������

HELP
    );
    return 1;
}
