// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

��ɽ���룬���ƴ�Ρ��ֻ�����ϰ���ƮƮ����ǰ��Ӱ��������
���ɰ�ǧǧ����ͷ���񼸸ɡ��Ĵ���ʯ���ף�ʹ���ĸв�����
�������Ծٲ���

LONG);

  set("exits", ([
        "northwest"    : __DIR__"xuanya4",
        "southdown"    : __DIR__"jiankou1",
      ]));
  set("objects", ([
        __DIR__"npc/xiaoyao" : 1,
        __DIR__"npc/laoshu" : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

