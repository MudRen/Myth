// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/bei1.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

������ı����ţ����η������������������ѱ�����������
������ȥ���Լ���ɽ�ͣ����ϼ�Ŀ��ȥ��ԶԶ�ܿ����������
�������š�

LONG);

  set("exits", ([
        "northwest"  : __DIR__"yedu",
        "south"      : __DIR__"bei2",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 2,
        __DIR__"npc/bing" : 2,
        __DIR__"npc/shanyao" : 1,
  ]));
  set("outdoors","/d/qujing/baoxiang");
  setup();
}

int valid_leave (object who, string dir)
{
  if ((! interactive(who)) &&
      dir == "northwest" &&
      who->query("id")!="huangjia bing")
    return 0;
  return 1;
}

