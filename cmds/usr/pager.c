//Cracked by Roath

inherit F_CLEAN_UP;
int help(object me);
void create() {seteuid(getuid());}
int main(object me)
{
  if(!me->query("msg_on")) 
  {
     me->set("msg_on",1);
     write("������,ok!\n");
  }
  else 
  { 
     me->delete("msg_on");
     write("�ر�����,ok!\n");
  }
  return 1;
 }
 int help(object me)
{
    write(@HELP
ָ���ʽ��pager
���ָ���������򿪻��߹ر�Ԥ�����úõ����ԡ�
���ָ�� : set reply_msg
HELP
    );
    return 1;
}

  