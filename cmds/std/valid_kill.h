//modified by vikee for XLQY
//2001-2-9 20:07
//Update By Aeddy

void set_my_killer_list(object killer, object victim);

int valid_kill(object killer, object victim, int no_list)
{    
    if (userp(killer) && !query_heart_beat(killer))
    {
        return notify_fail("������û�������������µ�½!!\n");
    }

/*
    if (victim->query("ziyouchoose") == "nopk" && userp(victim))
        return notify_fail(HIR"�Է�ѡ����NOPK�������㲻��KILL��\n"NOR);
        
    if (killer->query("ziyouchoose") == "nopk" && userp(victim))
        return notify_fail(HIR"��ѡ����NOPK����������ɱ�ˣ�\n"NOR);
*/

//��Щcast������Ҫ�ſ��ģ�����cast zhang,cast lianhua,cast yinshen�ȵ�
//���Խ�����һ���ɿ��ƵĹ̶��ص��ִ����������������֡�������������˵̫������
//����������kz u u ����ص������"������"����֪���з�by seng@2005-1-25
if (userp(victim)  && environment(victim)->query("short")!="���������������")
// if (userp(victim)  && environment(victim)->query("short")!="������")
    {
                    return notify_fail("�ͺ����������꣡:P\n");
    }

         if(environment(killer)->query("hellfireroom") && (killer->query_temp("position/xx")!=victim->query_temp("position/xx") ||  killer->query_temp("position/yy")!=victim->query_temp("position/yy")) )
              return notify_fail("�㲻��"+victim->name()+"��λ��ǰ,��ô��\n");
     if(userp(victim) && userp(killer)) {
         if ((int)killer->query_condition("no_pk_time")>480) 
            return notify_fail(
                    "�����ɱ��̫�࣬��ʱ��Ȼ�����������أ��²�ȥ�֡�\n");
         if ((killer->query("combat_exp")+killer->query("daoxing"))
                 <5000) 
             return notify_fail(
                     "���Լ�����û���ã�����Ҫɱ�ˣ�\n");
         if(!no_list) 
             set_my_killer_list(killer, victim);
     }
           
     return 1;
}

void set_my_killer_list(object killer, object victim)
{
     string *list, *listk;
     string kill;

         listk=killer->query_temp("my_killer_list");
         if(listk && arrayp(listk)) {
             if(member_array(victim->query("id"),listk)!=-1) {
                 // the victim issued kill on the killer first.
                 // so not mark the killer. mon 10/24/98
                 return;
             }
         }

         // this list contains all the players initiaite killing
         // to the victim.  -mon 8/4/98
         list=victim->query_temp("my_killer_list");
         kill=killer->query("id");
         if(!list) list=({kill});
         else if(member_array(kill, list)==-1)
             list+=({kill});
         if(sizeof(list)>100)
             list=list[1..<1]; // remove the first element.
         victim->set_temp("my_killer_list", list);
}

int set_to_killer(object killer,object target)
{
        string enemy;   
        killer->delete_temp("is_killer");//����ϴμ�¼��
        killer->set_temp("is_killer/flag",1);//�����¼�¼
        enemy = target->query("id");//��¼�������֡�
        killer->set_temp("is_killer/enemy_id",enemy);
}


