// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/yujie2.c
inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

�ɰ����̳ɵ�̨�ף���������������ȥ��ÿһ��̨�׶�����ϸ��
���ɣ���Ƕ�н�˿���ߡ����߸�ͨ��һ��һ���Ϊ����������
Ϊ̫���

LONG);

  set("exits", ([
        "northdown"  : __DIR__"yujie1",
        "southup"    : __DIR__"yujie3",
        "west"       : __DIR__"gong2",
        "east"       : __DIR__"dian2",
      ]));
  set("objects", ([
        __DIR__"npc/girl" : 2,
    ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

/*
int valid_leave (object who, string dir)
{
  if (dir == "west")
  {
    message_vision ("$N��ͷ������һ̽��������������Ļ������ͽ�$N�ܳ���\n",
                    who);
    return notify_fail("");
  }
  if (dir == "east")
  {
    message_vision ("$N��ͷ������һ̽��������������Ļ������ͽ�$N�ܳ���\n",
                    who);
    return notify_fail("");
  }
  return 1;
}

*/
