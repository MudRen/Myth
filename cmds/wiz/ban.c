//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// ban.c

void create()
{
   seteuid(getuid());
}

int main(object me, string arg)
{
   string site;

   if (!arg)
     BAN_D->print();
   else if (sscanf(arg, "+ %s", site) == 1) {
     if (site[sizeof(site)-1] == '*' ||
         site[sizeof(site)-1] == '?' ||
         site[sizeof(site)-1] == '+')
        write("���ܽ��� *, +, ? ��β�ĵ�ַ��\n");
     else
        BAN_D->add(site);
     }
   else if (sscanf(arg, "- %s", site) == 1)
     BAN_D->remove(site);
   else write("ָ���ʽ��ban [+|- site]\n");

   return 1;
   
}

int help(object me)
{
   write(@HELP
ָ���ʽ��ban [+|- site]

�����˸��ƻ�ʱ���Ծܾ������IP�����ߡ�
HELP
   );
   return 1;
}
