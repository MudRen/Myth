// Room: /d/qujing/wudidong/temple-qiandian.c
// created 6-20-97 pickle
inherit ROOM;

void create ()
{
  set ("short", "С��ǰ��");
  set ("long", @LONG

С����ɽ���죬Զ����Ϊ���ţ�����ȴ���ֲ�Ȼ���������ı�͸�磬
����©ˮ���������Ա��ϵ��������ȱ�첲���ȡ��ۼ����߽�����Ҳ
û�и�֪��ɮ����ӭ���ϱ߻��м��Ҳ�ǲ��Ʋ�����ֻ�ж���һ
�䷿�ӻ����Ĺ�ȥ��
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "east" : "һ�Ƚ��յ�ľ�ţ���������(knock)������û���ˡ�
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"temple-houdian",
  "north" : __DIR__"road1",
]));
  set("light_up", 1);

  setup();
}

void init()
{
  add_action("do_knock", "knock");
}

int do_knock()
{
  object me=this_player();
  string myrespect=(string)RANK_D->query_respect(me);

  if (me->query("obstacle/wudidong") != "done")
  {
      message_vision("ֻ���ź���һ�󾪽У��㡢�㡢����ʲô���֣�ɱ��������������\n", me);
      return 1;
  }
  message_vision("ֻ����֨����һ�������ű�������һ���졣\n", me);
  message_vision("һ������̽��ͷ���Ĵ����˿���������$N�����ŵ�����¶��һ˿Ц�ݡ�\n", me);
  message_vision("���е���ԭ����"+myrespect+"���ɰ��Ҹ��Ż��ˡ�\n", me);
  message_vision("���д��ţ���$N���˽�ȥ���ּ�æ���Ź����ˡ�\n",me);
  me->move(__DIR__"bedroom");
  return 1;
}






