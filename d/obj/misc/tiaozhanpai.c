//Cracked by Roath

#include <ansi.h>

inherit ITEM;

void create() {

  set_name("��ս����", ({"tiaozhan jinpai","jinpai","pai"}));
  set_weight(200);
  set("value",100000);
  set("unit", "��");
  set("long", "һ����ƣ�������š������һ������ڶ����˸��֡�\n"+
      "�����ƾ������������������ս(challenge)��\n");
  set("value", 1000);
  setup();
}

void init() {
  add_action("do_challenge","challenge");
}

int do_challenge(string arg) {
  object me=this_player();
  object who,old;


  if (!userp(me)) return 0;
  if ((!arg) || (!who=find_player(arg))) 
    return notify_fail("��Ҫ��˭��ս��\n");
  if (who==me) return notify_fail("��ս���ң���־����\n");
  old=me->query_temp("leitai/challenge");
  if (who==old)   return notify_fail("���Ѿ���������ս�ˡ�\n");
  if (old) {
     write("����ƴ򲻹�"+old->query("name")+"���������������ˡ�\n");
     old->delete_temp("leitai/being_challenged");
     tell_object(old,me->query("name")+"���㲻������Ϊ�㲻��ȥ��������������ˡ�\n");
  }
  message_vision("$N����"+who->query("name")+RANK_D->query_respect(who)+"�ֽ��д��书������\n",me);
  tell_object(who,me->query("name")+"�����㣺"+RANK_D->query_rude(who)+
   "����û�е��Ӻ��Ҵ���һ��(defend)����������̨���㣡\n");


  me->set_temp("leitai/challenge",who);
  who->set_temp("leitai/being_challenged",me);
//  destruct(this_object());
  return 1;
}

