// created by angell 1/1/2001
// room: /d/qujing/huangfeng/dong6.c


inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���ڹ��߻谵�����������ȳ��˱ǡ���������������ߴ�
����ȥ����ע�⵽����ǽ����һ��С������֪���ܲ�����
��ȥ��

LONG);

  set("exits", ([
        "north" : __DIR__"dong5",
      ]));
       
  setup();
}

void init ()
{
  add_action ("do_zuan","zuan");
}

int do_zuan (string arg)
{
  object who = this_player();

  if ((! arg)||(arg != "dong" && arg != "С��" && arg != "��"))
    return 0;

  tell_object (who,"���������������С�������˹�ȥ\n");
  who->move(__DIR__"anshi");
  return 1;
}