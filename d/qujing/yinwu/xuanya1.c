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
        "east"    : __DIR__"xuanya2",
        "southwest"    : __DIR__"xuanya6",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

