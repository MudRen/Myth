// created by angell 1/1/2001
// room: /d/qujing/huangfeng/tulu4.c

inherit ROOM;

void create ()
{
  set ("short", "�����·");
  set ("long", @LONG

���ӽ���Ⱥɽ֮�䣬һ��Ϫ���ƴ������·��������������
�����߹�������Щ��ʵ�Ĵ���֮�ˡ������Ǵ��е������ꡣ
�������˵��������һЩ��������

LONG);

  set("exits", ([
        "west"      : __DIR__"wuqidian",
        "north"   : __DIR__"tulu3",
        "south" :__DIR__"minju2",
      ]));
  set("objects", ([
                __DIR__"npc/people": 1 ]) );

  set("outdoors", __DIR__);

  setup();
}
