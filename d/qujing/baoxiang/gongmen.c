// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/gongmen.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���ų�˫�¹��Σ���ɽ����������ʯ���ɣ��������ϸ��Ľ�˿
���߻��λ��ơ������濴ȥ�����������������أ��������֣���
�󼫶ȷǷ���

LONG);

  set("exits", ([
        "southwest"  : __DIR__"xi4",
        "north"      : __DIR__"bei4",
        "west"      : __DIR__"jitan",
        "east"       : __DIR__"zhendong",
        "south"      : __DIR__"longfeng",
      ]));

  set("objects", ([
         __DIR__"npc/bing" : 2,
       ]));

  set("outdoors","/d/qujing/baoxiang");

  setup();
}

int valid_leave (object who, string dir)
{
  if ((! interactive(who)) &&
      dir == "south" &&
      who->query("id")!="huangjia bing" &&
      who->query("id")!="baihua xiu")
    return 0;
  return 1;
}
