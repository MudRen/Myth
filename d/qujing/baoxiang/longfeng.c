// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/longfeng.c

inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

�������������������ƻ�����������ûʣ����ý�˿��
�����ƶ��ɡ�������������仨����������Ƕ��������ơ�����
�Ǳ�����������ĵط���

LONG);

  set("exits", ([
        "north"      : __DIR__"gongmen",
        "southup"    : __DIR__"yujie1",
      ]));
  set("objects", ([
         __DIR__"npc/dashi" : 1,
         __DIR__"npc/bing" : 2,
      ]));

  setup();
}

int valid_leave (object who, string dir)
{
  object dashi = present("da shi",environment(who));

  if (interactive(who) &&
      dir == "southup" &&
      dashi &&
      living(dashi) &&
      ! who->query("obstacle/baoxiang"))
    return notify_fail("���Ŵ�ʹ����ҡ��ҡ�֡�\n");;
  return 1;
}

