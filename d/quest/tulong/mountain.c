inherit ROOM;
#include <ansi.h> 

void create ()
{
  set ("short", "�ٲ�");
  set ("long",HIG @LONG
��ɽ���룬���ƴ�Ρ��ֻ�����ϰ���ƮƮ����ǰ��Ӱ��������
���ɰ�ǧǧ���Ĵ���ʯ���ף����˾ٲ�ά�ѡ��ٲ������������ˮ
���ɽ��������������Ʈ����ɽ�¶����������������ƣ���֪����
��������֡�
LONG);

  set("exits", ([
        "north"    : "/d/quest/tulong/spirit9",      ]));
  setup();
}

void init ()
{
  add_action ("do_climb","climb");
}

int do_climb (string arg)
{
  object who = this_player();

  message_vision ("$N�ֽŲ��÷ܲ������������ȥ��\n",who);
  if (who->query("combat_exp") < 1000000 ||
      random(4))
  {
    message_vision ("\n��������һ����$Nʧ�ֻ���������\n",who);
    who->unconcious();    
  }
  else
    who->move("/d/quest/tulong/yashang");  return 1;
}


