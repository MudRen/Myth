// created by snowcat 12/2/1997

inherit ROOM;

string *msgs = ({
  "$N�ϵط��ڵ��ϣ�������һ��ͷ��",
  "$N�ϵط��ڵ��ϣ������ض���ͷ��",
  "$N�ϵط��ڵ��ϣ�����������ͷ��",
  "$N�ϵط��ڵ��ϣ��������Ŀ�ͷ��",
  "$N�ϵط��ڵ��ϣ����������ͷ��",
  "$N�ϵط��ڵ��ϣ�����������ͷ��",
  "$N�ϵط��ڵ��ϣ��������߿�ͷ��",
  "$N�ϵط��ڵ��ϣ������ذ˿�ͷ��",
  "$N�ϵط��ڵ��ϣ������ؾſ�ͷ��",
});

string *strs = ({
  "��ף���ޱ��飬�����ƺ�û��ʲô������",
  "��ף���ϸ�����ƺ�������ʲô��",
  "������Լ����˵������ˡ�",
  "���Ͽ�ʼ���������",
  "���ϵķ�������졣",
  "���ϵķ�εô��ˡ�",
  "���ϵĿ�������",
  "��ף��ϲ�������Ϸ��񴫻����������ɽ����һ�룡",
  "��ף��ϲ�������Ϸ��񴫻����������ɽȫ�����ˣ�",
});

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����ڳ�ǽ���£���ש����ľ�ܡ�������ǽ���Ϲ�������
��������ȸ������衣����ǽ��һ�����ľɲ�ľ����������
������¯����ð��˿˿���̡�
    
LONG);

  set("no_fight",1);
  set("no_magic",1);
  set("exits", ([
        "north"    : __DIR__"jiedao14",
      ]));
  set("objects", ([
        __DIR__"npc/miaozhu" : 1,
        __DIR__"npc/people2" : 4,
      ]));
  setup();
}

void init ()
{
  add_action ("do_ketou", "ketou");
}

int do_ketou ()
{
  object who = this_player();
  int size = sizeof(msgs);
  int i = who->query_temp("obstacle/fengxian_ketou");
  int j;

  if (who->is_busy())
    return notify_fail ("����æ���أ�\n");

  if (interactive (who) &&
      who->query("combat_exp") < 10000)
    return notify_fail ("��ĵ������ǲ����ɣ�\n");

  if (interactive(who))
    message_vision ("$N˫ϥ��£�������¹�\n",who);

  if (! interactive(who))
    message_vision ("$N�ϵط��ڵ��ϣ������ؿ�ͷ��\n",who);
  else if (i >= size)
  {
    message_vision ("\n��ףЦ�Ž�$N����\n",who); 
  }  
  else
  {
    j = i*18+10;
    who->start_busy (j,j);
    call_out ("start_ketou",5,who,i);
    call_out ("finish_ketou",j,who,i);
  }
  return 1;
}

void start_ketou (object who, int i)
{
  message_vision ("\n"+msgs[i]+"\n",who); 
}

void finish_ketou (object who, int i)
{
  who->interrupt_me ();
  message_vision ("\n$N��������\n",who); 
  message_vision ("\n"+strs[i]+"\n",who); 
  who->set_temp("obstacle/fengxian_ketou",i+1);
}
