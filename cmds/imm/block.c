// block.c
// modified by mon 7/25/97

#include "/doc/help.h"
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string option, target;

        if (! SECURITY_D->valid_grant(me, "(immortal)"))
                return 0;

       if (me != this_player()) return 0;

	if( !arg) return notify_fail("��Ҫ�ص������˭��Ƶ����\n");

        if( sscanf(arg, "%s %s", option, target)!=2 ) target = arg;
	if ( option != "-s" && option != "-u" ) target = arg;

	obj = find_player(target);
        if(!obj) return notify_fail("û������ˣ�����\n");

	if(option=="-s") {  // say, tell, reply, emote and whisper
	  if( wizardp(obj)) return notify_fail("�б�Ҫ��\n");
	  obj->set("channel/tell_block",time()+86400);
	  tell_object(obj, "��Ľ�̸Ƶ������ʱ�ر��ˣ�\n");
	  write( "���" + obj->query("name") + "�Ľ�̸Ƶ�����ر��ˣ�\n");
	  
        } else if(option=="-u") { // open channel
          obj->delete("channel/tell_block");
          obj->delete("channel/chat_block");
          obj->delete("chblk_chat");
          obj->clear_condition("maren");
	  tell_object(obj, "���Ƶ�������ˣ�\n");
	  write( "���" + obj->query("name") + "��Ƶ�������ˣ�\n");

	} else {  // chat and rumor
	  // block chat and rumor for 24 hours. (24*3600 sec).
	  if( wizardp(obj)) return notify_fail("�б�Ҫ��\n");
          obj->set("channel/chat_block",time()+86400);
	  tell_object(obj, "��Ĺ���Ƶ������ʱ�ر��ˣ�\n");
	  write( "���" + obj->query("name") + "�Ĺ���Ƶ�����ر��ˣ�\n");	
        }

	return 1;

}

int help(object me)
{
   write(@HELP
ָ���ʽ�� block <ĳ��>     ��ʱ�ص�ĳ�˵�chat��rumorƵ����
           block -s <ĳ��>  ��ʱ�ص�ĳ�˵�say��reply��emote��tell��whisper��
           block -u <ĳ��>  �ָ�ĳ�˵�����ͨ����

HELP
   );
   return 1;
}
