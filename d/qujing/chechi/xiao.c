// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/xiao.c

inherit ROOM;

void create ()
{
  set ("short", "С�ฮ");
  set ("long", @LONG

С�ฮ�ſڷ���һ��̴ľ�����ܣ����Ͽ���һ����������������
ǽ�����������Σ����湩��ʱ��ˮ����������һ�Ű׵ײ�Ⱦ���
�����磬�����ݸ�����

LONG);

  set("exits", ([
        "east"         : __DIR__"jieshi1",
      ]));

  set("objects", ([
        __DIR__"npc/xiaoguan"  : 1,
      ]));

  setup();
}

