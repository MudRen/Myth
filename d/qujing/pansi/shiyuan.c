// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "ʯԺ");
  set ("long", @LONG

ͥԺ�������ʢï��Ժ����ɽʯ�ݾͣ��м���һ��˪���ɣ�
����������������������������ң���Χ֥����ɢ��ǧ������
����һ���ȣ��ϱ���һʯ����

LONG);

  set("exits", ([
        "north"   : __DIR__"shitou",
        "south"   : __DIR__"shidong",
        "west"    : __DIR__"chulang",
      ]));
  set("objects", ([
        __DIR__"npc/girl4"    : 1,
        __DIR__"npc/girl5"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

