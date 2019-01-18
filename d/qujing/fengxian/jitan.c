// created by snowcat 12/2/1997

inherit ROOM;

string *msgs = ({
  "$Nȡ����һ���㽫���ȼ���������㡣",
  "$Nȡ���ڶ����㽫���ȼ���������㡣",
  "$Nȡ���������㽫���ȼ���������㡣",
  "$Nȡ�����ĸ��㽫���ȼ���������㡣",
  "$Nȡ��������㽫���ȼ���������㡣",
  "$Nȡ���������㽫���ȼ���������㡣",
  "$Nȡ�����߸��㽫���ȼ���������㡣",
  "$Nȡ���ڰ˸��㽫���ȼ���������㡣",
  "$Nȡ���ھŸ��㽫���ȼ���������㡣",
});

string *strs = ({
  "���ٳ���һ�ݡ�",
  "���ٳ�������һ�ݡ�",
  "��Ⱥ�����˵�������һ��������Ҳ��",
  "��ߴ�����Լ��������",
  "���������������",
  "�����������������Ӳ��ϡ�",
  "��������������ң����������",
  "���ٺȵ��������׹��л����������������Ƕϣ�",
  "���ٴ󾪵��������׹��л������������Ѷϣ�",
});

void create ()
{
  set ("short", "��̳");
  set ("long", @LONG

һ�����ľ������̳��������������ש�������������š�̨̳
�ɺ�ש���ɣ�������������̳�ס�̨�Ϲ�����ͭ�㶦���̻�
�ϣ�����������
    
LONG);

  set("no_fight",1);
  set("no_magic",1);
  set("exits", ([
        "east"    : __DIR__"jiedao8",
      ]));
  set("objects", ([
        __DIR__"npc/jiguan" : 1,
        __DIR__"npc/people2" : 4,
      ]));
  setup();
}

void init ()
{
  add_action ("do_nianxiang", "nianxiang");
}

int do_nianxiang ()
{
  object who = this_player();
  int size = sizeof(msgs);
  int i = who->query_temp("obstacle/fengxian_nianxiang");
  int j;

  if (who->is_busy())
    return notify_fail ("����æ���أ�\n");

  if (interactive (who) &&
      who->query("combat_exp") < 10000)
    return notify_fail ("��ĵ������ǲ����ɣ�\n");

  if (interactive(who))
    message_vision ("$N������ס�\n",who);

  if (! interactive(who))
    message_vision ("$Nȡ��һ���㽫���ȼ���������㡣\n",who);
  else if (i >= size)
  {
    message_vision ("\n���ٸϽ���$N����\n",who); 
  }  
  else
  {
    j = i*18+10;
    who->start_busy (j,j);
    call_out ("start_nianxiang",5,who,i);
    call_out ("finish_nianxiang",j,who,i);
  }
  return 1;
}

void start_nianxiang (object who, int i)
{
  message_vision ("\n"+msgs[i]+"\n",who); 
}

void finish_nianxiang (object who, int i)
{
  who->interrupt_me ();
  message_vision ("\n$N��ϣ���һ���ݡ�\n",who); 
  message_vision ("\n"+strs[i]+"\n",who); 
  who->set_temp("obstacle/fengxian_nianxiang",i+1);
}
