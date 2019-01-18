//Cracked by Roath
inherit ROOM;
#include <room.h>
#include <ansi.h>

void create ()
{
  set ("short", "����ʤ��");
  set ("long", @LONG

ɽ�絭īƮ�죬ˮ����֬�޲��������ԯ������ȥ���������
���Ҳ�����ǰ�ж��Ľ𹬣���ǧ��ϼ�⣬����������䣬����
��ʤ����

LONG);

  set("alternative_die", 1);
  set("broadcast", 1);
  setup();
}


int alternative_die(object who)
{

	message_vision("$N���ˣ��ֻ��ˡ�\n", who);

	who->remove_all_killer();
	all_inventory(this_object())->remove_killer(who);

	who->clear_condition();

	who->set("eff_kee", who->query("max_kee"));
	who->set("eff_sen", who->query("max_sen"));
	who->set("kee", who->query("max_kee"));
	who->set("sen", who->query("max_sen"));

	who->set("force", who->query("max_force"));
	who->set("mana", who->query("max_mana"));


	return 1;
}
void broadcast_room (object room, string str)
{
  string prefix = HIB"��ʤ����"NOR;
  string s1 = str, s2 = "", s3;
  int i;

  reset_eval_cost();

  // remove extra trailing NOR. mon 7/13/99
  s1=replace_string(s1,"\n"NOR,"\n");

  while (strsrch(s1,"\n\n") != -1)
    s1 = replace_string(s1,"\n\n","\n");

  while (sizeof(s1)>1 && s1[sizeof(s1)-1]=='\n')
  {
    s1 = s1[0..(sizeof(s1)-2)];
    s2 = "\n";
  }
  if (sizeof(s1) <= 1)
    return;

  s1 = replace_string(s1,"\n","\n"+prefix);
  if (room)
  {
   tell_room (room, prefix+s1+ NOR+"\n");     
  }
}

void broadcast(string msg) {
  object room=load_object("/u/bula/workroom");
  if (room) broadcast_room(room,msg);
}

