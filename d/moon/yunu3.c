//Cracked by Roath
// Room: /moon/yunu3.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "��Ů��");
  set ("long", @LONG

��ѩ���硣���������û��·������ǿ��סһЩͻ�����ı��飬�����ҳ�
һ��·��������һ�������ɵ�ͷ��Ŀѣ����Ͻ������۾�������һ������
��ˤ�÷�����ǡ�����������һƬ���͸�����㡣
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"yunu2",
  "southup" : __DIR__"yunu4",
]));

  setup();
}






void init()
{
    add_action ("do_jump","jump");
}

int do_jump(string arg)
{

   object who=this_player();
   if (arg != "west")
      return 0;

  message_vision ("$N�۾�һ�գ������ߵ���������ȥ��\n",who);
   who->move("/d/moon/fengxue/fxtd");
  message_vision ("$N�����ƮƮ�طɰ��ɰ������ڷɵ�һ���ط���\n",who);
   return 1;
}

