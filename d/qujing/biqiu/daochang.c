// created by snowcat 11/21/1997

inherit ROOM;

string *msgs = ({
  "���ߣ���Ե���ա�",
  "�����ߣ���Կա�",
  "�������У�売��ڲ���֮�ڡ�",
  "���ĬĬ����ң�ڼ���֮�С�",
  "����ն��ٶ��Σ���������ǧ���",
  "���˼��֪�����뵱ʶ�ġ�",
  "�ľ���������գ��Ĵ����򾳽��塣",
  "������Ƿ�����࣬��ǰ�ɼ���",
  "�����������л����������",
  "�й���������Ϊ�붨֮ԭ��",
  "����ʩ������������֮����",
  "������׾����֪������Ϊ��",
  "�ƼƷǳ����ͷͷ���¡�",
  "��ʹһ�Ĳ�����������ȫ��",
  "���Ʋ�����������Ϊ����������٣�ʵ����ʡ�",
  "ֻҪ����Ե����������ɫ�Կա�",
  "���ش����Ѱ�������Ȼ���������",
});

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

�����Ϊһ�����ã���ʮ��������ľ���ӳ���������ͨ����
���ϱ����裬����һ�����������ţ���һЩ��ҵ�������һ
�𽲷��۵���������һ��ͨ���֡�

LONG);

  set("exits", ([
        "east"    : __DIR__"jie11",
      ]));
  setup();
}

void init ()
{
  add_action ("do_zuochan", "zuochan");
}

int do_zuochan ()
{
  object who = this_player();
  int size = sizeof(msgs);
  int i = who->query_temp("obstacle/biqiu_zuochan");
  int j;

  if (who->is_busy())
    return notify_fail ("����æ���أ�\n");

  message_vision ("$N��ϥ���������Ʊ�Ŀ��\n",who);
  if (i >= size)
  {
    message_vision ("\n$N��˼���꣬���������ƺ��Ѿ���\n",who); 
  }  
  else
  {
    j = i*18+10;
    who->start_busy (j,j);
    call_out ("start_zhuochan",5,who,i);
    call_out ("finish_zhuochan",j,who);
  }
  return 1;
}

void start_zhuochan (object who, int i)
{
  message_vision ("\n$N�����"+msgs[i]+"\n",who); 
  message_vision ("\nƬ�̣�$N��ʼ����������\n",who); 
  who->set_temp("obstacle/biqiu_zuochan",i+1);
}

void finish_zhuochan (object who)
{
  object where = environment(who);

  who->interrupt_me ();
  message_vision ("\n$N������ϣ�����\n",who); 
  // much slower than normal speed, just a symbolic reward
  where->add("times",1);
  if (where->query("times") < 200)
  {
    who->add("potential",random(3)+1);
    tell_object(who,"���Ǳ���������ˣ�\n");
  }
}
