// created by angell 1/1/2001
// room: /d/qujing/huangfeng/tulu3.c

inherit ROOM;

void create ()
{
  set ("short", "�����·");
  set ("long", @LONG

���ӽ���Ⱥɽ֮�䣬һ��Ϫ���ƴ������·��������������
�����߹�������Щ��ʵ�Ĵ���֮�ˡ�����һ����ɽ�εض���
ֱ��������ɽ����Ȫ���٣�������������ɽ���ǻƷ����ˡ�

LONG);

  set("exits", ([
        "east" : __DIR__"tulu2",
        "south" : __DIR__"tulu4",
	 "northup" : __DIR__"huangfeng",
       ]));
  set("objects", ([
                __DIR__"npc/people": 1 ]) );

  set("outdoors", __DIR__);

  setup();
}