// created by snowcat 12/2/1997

inherit ROOM;

string *msgs = ({
  "$NĬĬ�ص�ͷ�����������дǵ�һհ�ݡ�",
  "$NĬĬ�ص�ͷ�����������дǵض�հ�ݡ�",
  "$NĬĬ�ص�ͷ�����������дǵ���հ�ݡ�",
  "$NĬĬ�ص�ͷ�����������дǵ���հ�ݡ�",
  "$NĬĬ�ص�ͷ�����������дǵ���հ�ݡ�",
  "$NĬĬ�ص�ͷ�����������дǵ���հ�ݡ�",
  "$NĬĬ�ص�ͷ�����������дǵ���հ�ݡ�",
  "$NĬĬ�ص�ͷ�����������дǵذ�հ�ݡ�",
  "$NĬĬ�ص�ͷ�����������дǵؾ�հ�ݡ�",
});

string *strs = ({
  "��ʦ�������ӣ���Ĭ���ԡ�",
  "��ʦ���⿴��һ�ۣ���Ȼ���ԡ�",
  "��ʦ������ת���⣬���ǿ�����ʲô��",
  "��������һ�����硣",
  "��������������һ�¡�",
  "��������ƵƵ���������ϡ�",
  "���ϵ�����������������컮�ơ�",
  "��ʦ���������ϵ������л����������ɽ�����˰�ߣ�",
  "��ʦ�󾪵������ϵ����Ӵ������������ɽ�����������ˣ�",
});

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�������½���ʩ������֮����������ͨ�������ϱ���һ����ţ�
�������̷�̨������Ϊƴ��ľͷ�������̿��ز���̺��������
һͭ�ӣ�ÿ��ʱ�����������졣
    
LONG);

  set("no_fight",1);
  set("no_magic",1);
  set("exits", ([
        "south"    : __DIR__"jiedao1",
      ]));
  set("objects", ([
        __DIR__"npc/fashi" : 1,
        __DIR__"npc/people2" : 4,
      ]));
  setup();
}

void init ()
{
  add_action ("do_zhanbai", "zhanbai");
}

int do_zhanbai ()
{
  object who = this_player();
  int size = sizeof(msgs);
  int i = who->query_temp("obstacle/fengxian_zhanbai");
  int j;

  if (who->is_busy())
    return notify_fail ("����æ���أ�\n");

  if (interactive (who) &&
      who->query("combat_exp") < 10000)
    return notify_fail ("��ĵ������ǲ����ɣ�\n");

  if (interactive(who))
    message_vision ("$N���ƶԺϣ�˫��΢�ա�\n",who);

  if (! interactive(who))
    message_vision ("$NĬĬ�ص�ͷ�����������дǵ�հ�ݡ�\n",who);
  else if (i >= size)
  {
    message_vision ("\n��ʦ��æ��$N����\n",who); 
  }  
  else
  {
    j = i*18+10;
    who->start_busy (j,j);
    call_out ("start_zhanbai",5,who,i);
    call_out ("finish_zhanbai",j,who,i);
  }
  return 1;
}

void start_zhanbai (object who, int i)
{
  message_vision ("\n"+msgs[i]+"\n",who); 
}

void finish_zhanbai (object who, int i)
{
  who->interrupt_me ();
  message_vision ("\n$N����һ������̧��ͷ����\n",who); 
  message_vision ("\n"+strs[i]+"\n",who); 
  who->set_temp("obstacle/fengxian_zhanbai",i+1);
}
