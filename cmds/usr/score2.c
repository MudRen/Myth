// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit F_CLEAN_UP;
#include <obstacle.h>
int telling (object me, object who);
int telling2 (object who);
string name;
int killtime(object me);
int main(object me, string arg)
{
        object ob;
        if( !arg ) {
                ob = me;
                name = ob->short(1);
        } else if (wizardp (me)) {
                ob = find_player(arg);
                if(!ob) ob = find_living(arg);
                if(!ob) ob = LOGIN_D->find_body(arg);
                if(!ob || !me->visible(ob)) return notify_fail("û������ˡ�\n");
                name = ob->short(1);
        } else
           return 0;
        telling(me, ob);
        return 1;
}
int help()
{
        write(@TEXT
ָ���ʽ��score2 <ĳ��>

��ʾĳ���������ϡ� 
        ���磺�鿴��ħ����

��ذ�����help wudang ��
TEXT
        );
        return 1;
}

int telling (object me, object who)
{
  write (name+"\n");
  write ("�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n");
if(who->query("HellZhenPass")){
        write ("�Ѿ��¹�ʮ�˲�����ˡ�\n");
        write ("������������������������������������������������������������������������\n");
}
   telling2(who);
if(who->query("death")){
        write ("�ϴ�������ʧ"+COMBAT_D->chinese_daoxing(who->query("death/dx_loss"))+"���С�\n");
        write ("�ϴ�������ʧ"+who->query("death/combat_exp_loss")+"��ѧ��\n");
        write ("�ϴ�������ʧ"+who->query("death/pot_loss")+"Ǳ�ܡ�\n");
        write ("�ϴ�������ʧ"+who->query("death/skill_loss")+"�����ܡ�\n");
        write ("������������������������������������������������������������������������\n");
}
if(who->query("child")){
        write ("��"+who->query("child")+"�����ӡ�\n");
        write ("������������������������������������������������������������������������\n");
}
  write ("һ������"+who->query("liwu/eat")+"�����\n");
  write ("һ������"+who->query("rsg_eaten")+"���˲ι���\n");
  write ("����ֳ���"+who->query("eat_biou")+"����ź��\n");
  write ("����ֳ���"+who->query("eat_jiaoli")+"�����档\n");
  write ("����ֳ���"+who->query("eat_huozao")+"�����档\n");
  write ("������������������������������������������������������������������������\n");
   write ("һ�������"+who->query("dajiunpc")+"�α�������\n");
   write ("һ�������"+who->query("baohuhuaxian")+"�����ɡ�\n");
  write ("һ��������"+who->query("killme/number")+"������\n");
  write ("����ۼƽ�����"+who->query("killme_number")+"������\n");
        if(who->query_temp("ask_njiang")=="do"){
                write ("��׼��������������񣬵���û������ͬ�⡣\n");
        }else{
        if(who->query_temp("killme_applied")=="do"){
                write ("�����Ѿ���������Ӧ�ý�����ħȥ�ˡ�\n");
                killtime(who);
        }else{
        if(who->query_temp("killme_applied")=="done"){
                write (" ��ɱ�����֣������Ž����ء�\n");
        }else{
        if(who->query_temp("ask_jiang")=="do"){
                write ("�մ����������񽫵���Ϣ������û�õ��𸴡�\n");
        }else{
        if(who->query_temp("ask_jiang")=="ok"){
                write ("�Ѿ������������񽫵���Ϣ�ˣ���׼��ȥ�ҡ�\n");
        }else{
                write ("����û�����ħ����\n");
        }
        }
        }
        }
        }
  write ("�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n");
}

int telling2 (object who)
{
  int size = sizeof(obstacles);
  string *names = keys(obstacles);
  string *strs = allocate (size);
  int nb = 0;
  int i;

  for (i = 0; i < size; i++)
  {
    strs[i] = "none";
  }

  for (i = 0; i < size; i++)
  {
    if (who->query("obstacle/"+names[i])!="done")
    {
      strs[nb] = obstacles[names[i]];
      nb++;
    }
  }

  if (nb == 0)
  {
        write ("��ʣ"+(3-who->query("obstacle/rebirth"))+"��������ë��\n");
        write ("������������������������������������������������������������������������\n");
  }
}
int killtime(object me)
{
        int sec,min,age,time1,time2;
        string out_str;
        object old=find_living(me->query("id")+" yao");
        time2=time();
        time1 = (int)me->query_temp("killme/time1");
        age = 1800 - (time2 - time1);
        if(age>0){
        sec = age % 60;age /= 60;
        min = age % 60;age /= 60;
        out_str = (min? chinese_number(min)+"����":"")
        + (sec? chinese_number(sec)+"��":"");
                if(old){
                        write("������" + out_str + "֮�ڳ�������\n");
                }else{
                        write("�Ѿ��Ҳ�����Ҫ������ħ�ˣ���������������ȥ�ɡ�\n");
                }
        }else{
                write("�����Ѿ���ʱ�ˣ���������������ȥ�ɡ�\n");
        }
        return 1;
}

